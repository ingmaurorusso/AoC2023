#include <algorithm>
#include <array>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace{

constexpr bool Example = false;

constexpr std::string_view WantedLow = Example ? "output" : "rx";

constexpr std::string_view Input =

Example ?

/*
"broadcaster -> a, b, c\n"
"%a -> b\n"
"%b -> c\n"
"%c -> inv\n"
"&inv -> a\n"
*/

"broadcaster -> a\n"
"%a -> inv, con\n"
"&inv -> b\n"
"%b -> con\n"
"&con -> output\n"


:

"%bd -> lg, cm\n"
"broadcaster -> ct, hr, ft, qm\n"
"%bh -> lj\n"
"&zz -> th, hr, jk, bh, js\n"
"&js -> cl\n"
"&cl -> rx\n"
"%rn -> ml\n"
"%ks -> xk, kd\n"
"&cm -> jp, sk, ft, dt, gb\n"
"%gk -> qv, kd\n"
"%lg -> cm\n"
"%qd -> jp, cm\n"
"%jk -> fs\n"
"%vq -> qj, kd\n"
"%lj -> cx, zz\n"
"%th -> bh\n"
"%rp -> bk, cm\n"
"%xk -> nv, kd\n"
"%qv -> ks\n"
"%mj -> xg, mh\n"
"%lh -> zz, pz\n"
"&mh -> ct, qs, vs, vk, pg\n"
"%kb -> hv, kd\n"
"%pg -> lz\n"
"%qm -> kb, kd\n"
"%pc -> cm, xl\n"
"%hv -> kd, rn\n"
"%fr -> fl, mh\n"
"%mp -> zz\n"
"%xl -> cm, gb\n"
"%tp -> mh\n"
"%gb -> rp\n"
"%pz -> mf, zz\n"
"%qn -> cm, sk\n"
"%fl -> tp, mh\n"
"%zq -> th, zz\n"
"%sk -> qd\n"
"%tk -> mh, vk\n"
"%bk -> bd, cm\n"
"%ml -> gk\n"
"%jg -> fr, mh\n"
"%nv -> vq, kd\n"
"%xg -> mh, vs\n"
"%hr -> zz, zq\n"
"%vk -> jg\n"
"%qj -> kd\n"
"&qs -> cl\n"
"%cx -> jk, zz\n"
"%mf -> mp, zz\n"
"&dt -> cl\n"
"%lz -> tk, mh\n"
"%vs -> pg\n"
"%ct -> mh, mj\n"
"%jp -> pc\n"
"%ft -> qn, cm\n"
"%fs -> zz, lh\n"
"&kd -> qm, ml, ts, qv, rn\n"
"&ts -> cl\n"

;

enum class ModuleType : unsigned { FlipFlop, Conjunction, Broadcaster, Button };

template<typename E>
constexpr auto toUnderlying(const E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

std::string moduleTypeToStr(ModuleType mt)
{
    using std::literals::string_literals::operator""s;
    switch (mt) {
    case ModuleType::FlipFlop:
        return "FlipFlop";
    case ModuleType::Conjunction:
        return "Conjunction";
    case ModuleType::Broadcaster:
        return "Broadcaster";
    case ModuleType::Button:
        return "Button";
    default:
        throw std::runtime_error(
            "Inconsistent module type to print: "s + std::to_string(toUnderlying(mt)));
    }
}

bool charToModuleType(const char ch, ModuleType& mt)
{
    using std::literals::string_literals::operator""s;
    switch (ch) {
    case '%':
        mt = ModuleType::FlipFlop;
        break;
    case '&':
        mt = ModuleType::Conjunction;
        break;
    default:
        return false;
    }

    return true;
}

using Destinations = std::list<std::string>;

struct Module {
    ModuleType mt;
    Destinations dests;
};

} // namespace

auto day20Part2(std::string_view streamSource, bool sourceIsFilePath)
{
    std::shared_ptr<std::istream> inputStream;

    if (sourceIsFilePath) {
        inputStream = std::static_pointer_cast<std::istream>(
            std::make_shared<std::ifstream>(std::string(streamSource)));
    } else {
        auto sstream = std::make_shared<std::stringstream>();
        (*sstream) << streamSource;
        // use std::move(sstream) in C++20 or more.
        inputStream = std::static_pointer_cast<std::istream>(sstream);
    }

    std::string wantedLow = WantedLow.data();
    // std::vector<std::string> lines;

    static const auto hashName = [](const std::string& name) {
        unsigned hashZero = 0U;

        return std::accumulate(
            name.cbegin(), name.cend(), hashZero, [](const auto hashAcc, const char ch) {
                // NOLINTNEXTLINE(readability-magic-numbers)
                return ((hashAcc + 137U) * 11U + static_cast<unsigned>(ch)) % 12345;
            });
    };

    using Modules = std::unordered_map<std::string, Module, decltype(hashName)>;
    Modules modules(0U, hashName);

    static const auto hashItM = [](const Modules::iterator& itm) {
        const auto& modName = itm->first;
        return hashName(modName);
    };
    /* not needed
    static equiItM = [](const Modules::iterator& itm1, const Modules::iterator& itm2){
        return itm1 == itm1;
    }; */

    using ModulesState = std::unordered_map<Modules::iterator, bool, decltype(hashItM)>;
    ModulesState ffStates(0U, hashItM);
    // map vs set-pos: more memory but stable memory (better performance)

    std::unordered_map<Modules::iterator, ModulesState, decltype(hashItM)> conjInStates(
        0U, hashItM);

    static const std::string broadcasterName = "broadcaster";

    /* not really needed
    constexpr std::string_view ButtonName = "___button___";
    modules[std::string(ButtonName)] = Module{ModuleType::Button,Destinations{}};
    modules[std::string(ButtonName)].dests.emplace_back(broadcasterName);
    */

    std::unordered_set<std::string, decltype(hashName)> tmpConjSet(0U, hashName);

    using ModuleSet = std::unordered_set<Modules::iterator, decltype(hashItM)>;
    using ModulesInputs = std::unordered_map<Modules::iterator, ModuleSet, decltype(hashItM)>;
    std::unordered_map<std::string, ModuleSet, decltype(hashName)> testingModulesWithInputs(
        0U, hashName);

    unsigned lineCount{0U};
    constexpr auto MaxLineLength = 1000;
    std::array<char, MaxLineLength + 1> cc{};
    while (inputStream->getline(cc.data(), MaxLineLength, '\n')) {
        ++lineCount;
        std::string errorLine = "Input error at the line n. "
            + std::to_string(static_cast<int>(lineCount)) + " : ";

        auto c = static_cast<size_t>(inputStream->gcount());
        // 'c' includes the delimiter, which is replaced by '\0'.
        if (c > MaxLineLength) {
            throw std::invalid_argument(
                errorLine + "longer than " + std::to_string(MaxLineLength));
        }

        std::string line;
        // std::cout << "length = " << c << '\n';
        if (cc.at(c - 1U) == '\0') { // 'c' is positive as line has been extracted.
            --c; // excludes '\0' that replaced the delimiter '\n'.
        }
        line = std::string_view(cc.data(), c);
        // std::cout << "line: " << line << '\n';

        if (line.empty()) {
            continue;
        }

        std::stringstream lineStream;
        lineStream << line;

        std::string moduleName;
        if (!(lineStream >> moduleName)) {
            throw std::invalid_argument(errorLine + "no module name");
        }

        ModuleType mt{};
        if (charToModuleType(moduleName[0], mt)) {
            moduleName.erase(moduleName.cbegin());
        } else if (moduleName == broadcasterName) {
            mt = ModuleType::Broadcaster;
            /*
            } else
            if (moduleName == ButtonName){
                throw std::invalid_argument( errorLine + "not allowed reserved name: " +
            moduleName);
            */
        } else {
            // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
            throw std::invalid_argument(errorLine + "unexpected module name: " + moduleName);
        }

        auto [itM, ok] = modules.insert(std::make_pair(moduleName, Module{mt, Destinations{}}));
        if (!ok) {
            // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
            throw std::invalid_argument(errorLine + "repeated module name: " + moduleName);
        }

        if (mt == ModuleType::FlipFlop) {
            ffStates[itM] = false; // initial low state
        }
        if (mt == ModuleType::Conjunction) {
            tmpConjSet.insert(moduleName);
        }

        std::string arrow;
        if (!(lineStream >> arrow)) {
            throw std::invalid_argument(errorLine + "no arrow");
        }
        if (arrow != "->") {
            throw std::invalid_argument(
                // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                errorLine + "not an arrow after module name: '" + arrow + "'");
        }

        auto& listDest = itM->second.dests;

        bool lastDes = false;
        std::string dest;
        unsigned destCount = 0U;
        while (lineStream >> dest) {
            if (lastDes) {
                throw std::invalid_argument(
                    // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                    errorLine + "destination not preceeded by comma: '" + dest);
            }
            ++destCount;
            if (dest.back() == ',') {
                // the analyzer believes length may be 0 (or empty() condition is redundant).
                // cppcheck-suppress invalidFunctionArg
                dest.resize(dest.length() - 1U);
                if (dest.empty()) {
                    throw std::invalid_argument(
                        errorLine + "destination without name (only comma): n. "
                        + std::to_string(destCount));
                }
            } else {
                lastDes = true;
            }

            if (std::any_of(
                    listDest.cbegin(), listDest.cend(), [&dest](const auto& destScroll) {
                        return destScroll == dest;
                    })) {
                // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                throw std::invalid_argument(errorLine + "repeated destination: " + dest);
            }

            listDest.emplace_back(std::move(dest));
        }

        // lines.push_back(std::move(line));
    }

    const auto itBC = modules.find(broadcasterName);
    if (itBC == modules.end()) {
        throw std::invalid_argument("No broadcaster preset");
    }

    // initialize conjInStates and modulesInputs.
    ModulesInputs modulesInputs(modules.size(), hashItM);
    {
        // ModuleSet ffAlready(ffStates.size(),hashItM);

        for (auto itM = modules.begin(); itM != modules.end(); ++itM) {
            for (const auto& dest : itM->second.dests) {
                const auto itMdest = modules.find(dest);
                if (itMdest == modules.end()) {
                    const auto [itT, _]
                        = testingModulesWithInputs.emplace(dest, ModuleSet(1U, hashItM));
                    itT->second.insert(itM);
                } else {
                    auto [itMI, _] = modulesInputs.emplace(itMdest, ModuleSet(1U, hashItM));
                    itMI->second.insert(itM);
                }

                if (tmpConjSet.count(dest) > 0U) {
                    const auto itC = modules.find(dest);
                    if (itC == modules.end()) {
                        throw std::runtime_error("conjunction module not found");
                    }

                    const auto [itStates, ok]
                        = conjInStates.insert(std::make_pair(itC, ModulesState(1U, hashItM)));
                    itStates->second[itM] = false; // initial low state-in.
                } /* it is accepted, as in the first example. The last-time pulse works.
                    else{
                        const auto itF = modules.find(dest);
                        if (itF != modules.end()){
                            if (!ffAlready.insert(itF).second){
                                throw std::invalid_argument( "flip-flop " + dest + " with multiple
                    inputs");
                            }
                        }
                    } */
            }
        }
        tmpConjSet.clear();

        /*
        if (ffAlready.size() != ffStates.size()){
            throw std::invalid_argument( "some flip-flop have no input");
            //TODO: print at least one that is in ffStates and not in ffAlready
        }
        */
    }

    // Check that there is one single conjunction module to pulse the wantedLow module
    // and that the roads from broadcaster to each of its input are separated, that is
    // no chain from a module on a road to a module of another. Then, for each input of
    // the conjunction it is possible to find the cycle to repeat output high one 'once'
    // and assure that never during the cycle there is a multiple output high (otherwise
    // more complex code has to be written).

    bool mayTrySpeedUp = true;

    Modules::iterator singleConj{};
    {
        const auto itT = testingModulesWithInputs.find(wantedLow);
        if (itT == testingModulesWithInputs.end()) {
            std::cout << "The speed-up works only for testing module!\n";
            mayTrySpeedUp = false;
        } else {
            bool alreadyOneConjunction = false;
            for (const auto& itM : itT->second) {
                if (itM->second.mt == ModuleType::Conjunction) {
                    if (alreadyOneConjunction) {
                        std::cout << "The speed-up would work only with one single conjunction "
                                        "input for the testing module!\n";
                        mayTrySpeedUp = false;
                        // TODO: generalize to more than one conjunction: consider when one
                        // single conj.input for the wantedLow emits the low pulse.
                    } else {
                        alreadyOneConjunction = true;
                        singleConj = itM;
                    }
                } else {
                    std::cout << "The speed-up would work only with only conjunction inputs "
                                    "for the testing module!\n";
                    mayTrySpeedUp = false;
                    // In order to generalize, it is needed to assure that flip-flop does not
                    // also emits a low input to wantedLow in the same iteration when the
                    // conjunction does.
                }
            }

            if (mayTrySpeedUp && !alreadyOneConjunction) {
                std::cout << "The speed-up would work only with conjunction input for the "
                                "testing module!\n";
                mayTrySpeedUp = false;
            }
        }
    }


    std::unordered_map<Modules::iterator, ModulesState, decltype(hashItM)> ffStatesPerInput(
        0U, hashItM);

    if (mayTrySpeedUp) {
        std::unordered_map<Modules::iterator, ModuleSet, decltype(hashItM)> ancestors(
            0U, hashItM);

        // first, initialize ancestors based on singleConj.
        {
            const auto itMI = modulesInputs.find(singleConj);
            if (itMI == modulesInputs.end()) {
                std::cout << "no inputs for the conjection module: " << singleConj->first
                            << " ; the speed-up cannot work\n";
                mayTrySpeedUp = false;
            } else {
                for (const auto& itIn : itMI->second) {
                    std::cout << "conjunction input " << itIn->first << std::endl;
                    ancestors.emplace(itIn, ModuleSet(1U, hashItM))
                        .first->second.insert(itIn); // input ancestor of itself.
                }
            }
        }

        // find ancestors for each input
        for (auto& [itI, ancSet] : ancestors) {

            auto lastNewAncestors = ancSet;

            while (!lastNewAncestors.empty()) {
                ModuleSet newAncestors(0U, hashItM);

                for (const auto& itA : lastNewAncestors) {
                    const auto itMI = modulesInputs.find(itA);
                    if (itMI == modulesInputs.end()) {
                        if (itA->second.mt != ModuleType::Broadcaster) {
                            // TODO: this check should be extended to the case of
                            // mayTrySpeedUp==false, that is no chain from broadcaster to some
                            // of the interesting inputs.
                            throw std::invalid_argument(
                                "no further inputs for the ancestor module: " + itA->first);
                        } // else: accepted. Note that the initial key of ancestors might be
                            // broadcaster.
                    } else {
                        for (const auto& itIn : itMI->second) {
                            if (ancSet.count(itIn) == 0U) { // else: cycle, stop.
                                // std::cout << "ancestor " << itIn->first << " from " <<
                                // itA->first << std::endl;
                                newAncestors.insert(itIn);
                            }
                        }
                    }
                }

                // lastNewAncestors = newAncestors; TODO: understand the compilation error.
                lastNewAncestors.clear();
                for (const auto& itA : newAncestors) {
                    lastNewAncestors.emplace(itA);
                }
                ancSet.merge(newAncestors); // empties newAncestors.
            }
        }

        // check no common ancestor and initialize ffStatesPerInput.
        for (auto itI1 = ancestors.cbegin(); (itI1 != ancestors.cend()) && mayTrySpeedUp;
                ++itI1) {
            const auto itFI
                = ffStatesPerInput
                        .emplace(itI1->first, ModulesState(itI1->second.size(), hashItM))
                        .first;
            for (const auto& itA : itI1->second) {
                if (itA->second.mt == ModuleType::FlipFlop) {
                    itFI->second.emplace(itA, false); // false as initial state.
                }
            }

            for (auto itI2 = std::next(itI1); itI2 != ancestors.cend(); ++itI2) {
                for (const auto& itA : itI1->second) {
                    if (itA->second.mt
                        != ModuleType::Broadcaster) { // Broadcaster obviously common.
                        if (itI2->second.count(itA)) {
                            std::cout << "The speed-up cannot work with common ancestor "
                                            "between the inputs: "
                                        << itI1->first->first << " and " + itI2->first->first
                                        << std::endl;
                            mayTrySpeedUp = false;
                        }
                    }
                }
            }
        }
    }

    // Start propagation of pulses
    std::list<std::pair<bool, Modules::iterator>> pulseList;

    static const auto compConfigs = [](const ModulesState& ms1, const ModulesState& ms2) {
        // assume they have the same keys.
        auto it1 = ms1.cbegin();
        auto it2 = ms2.cbegin();
        while (it1 != ms1.cend()) {
            if (it1->second != it2->second) {
                return it2->second; // true if couple (false < true)
            }
            ++it1;
            ++it2;
        }
        return false;
    };

    using CycleNumber = unsigned long;

    using Configs
        = std::map<ModulesState, CycleNumber, decltype(compConfigs)>; // TODO: unordered_map
    /* not needed for part n.2
    Configs ffConfigs(compConfigs); // records when a configuration was touched.
    ffConfigs[ffStates] = 0U;

    std::vector<std::pair<Count,Count>> memoryPartialPulseCount;
    memoryPartialPulseCount.emplace_back(0U,0U);
    */

    std::unordered_map<Modules::iterator, Configs, decltype(hashItM)> ffConfigsPerInputs(
        ffStatesPerInput.size(), hashItM);
    for (const auto& [itFI, states] : ffStatesPerInput) {
        Configs cfg(compConfigs);
        cfg[states] = 0U;

        ffConfigsPerInputs.emplace(itFI, cfg);
    }

    constexpr CycleNumber CycleNumberToDo = 1000000000000000000UL;

    std::
        unordered_map<Modules::iterator, std::pair<CycleNumber, CycleNumber>, decltype(hashItM)>
            cyclePerInput(ffStatesPerInput.size(), hashItM);

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Modules n. " << (modules.size() + testingModulesWithInputs.size())
                << std::endl;
    std::cout << "Part of testing modules n. " << testingModulesWithInputs.size() << std::endl;

    // TODO: remove checks leading to std::runtime_error, they were only during development.

    // std::unordered_map<Modules::iterator, ModulesState, decltype(hashItM)>
    // conjInStates(0U,hashItM);
    for (CycleNumber i = 0; i < CycleNumberToDo; ++i) {
        const CycleNumber currentCycleCount = i + 1U;

        // In each iteration, check whether interesting inputs emits high output once
        // and then singleConj emits after them.

        ModuleSet conjEmittingInputs(0U, hashItM);
        bool conjAlreadyEmitted = false;

        // a button pressure determines a pulse toward the broadcaster.
        pulseList.emplace_back(false, itBC);
        // print pulse
        // std::cout << "1 Low pulse from button to broadcaster\n"; //TODO: lambda

        while (!pulseList.empty()) {
            const auto pulseIn = std::move(pulseList.front());
            pulseList.pop_front();

            const auto itM = pulseIn.second;
            const auto& mod = itM->second;

            const auto mt = mod.mt;
            const auto& listDest = mod.dests;

            bool pulseOut{};
            bool doPulseOut = false;

            switch (mt) {
            case ModuleType::Broadcaster:
                // low pulse to all destinations
                pulseOut = false;
                doPulseOut = true;
                break;
            case ModuleType::FlipFlop:
                if (!pulseIn.first) { // low pulse in
                    const auto itF = ffStates.find(itM);

                    if (itF == ffStates.end()) {
                        throw std::runtime_error("flip flop state not found");
                    } // else:

                    // switch state.
                    itF->second = !itF->second;
                    pulseOut = itF->second;
                    doPulseOut = true;

                    const auto itFI = ffStatesPerInput.find(itM);
                    if (itFI != ffStatesPerInput.end()) {
                        itFI->second[itM] = pulseOut;
                    }
                } // else: high pulse ignored (doPulseOut already false).
                break;
            case ModuleType::Conjunction:
                // check its inputs.
                {
                    const auto itC = conjInStates.find(itM);
                    if (itC == conjInStates.end()) {
                        throw std::runtime_error("conjunction states not found for in");
                    }

                    const auto& inStates = itC->second;

                    pulseOut = !std::all_of(
                        inStates.cbegin(), inStates.cend(), [](const auto& pairItandState) {
                            return pairItandState.second;
                        });
                    // low if all high states, otherwise high.

                    doPulseOut = true;
                }
                break;
            default:
                throw std::runtime_error("unexpected module type");
            }

            if (doPulseOut) {

                if (mayTrySpeedUp) {
                    if (itM == singleConj) {
                        conjAlreadyEmitted = true;
                    } else if (ffStatesPerInput.count(itM) > 0U) {
                        // This is an interesting input.
                        if (pulseOut) {
                            std::cout << std::boolalpha << "emission " << pulseOut
                                        << " for interesting input " << itM->first
                                        << " at the cycle " << currentCycleCount << std::endl;

                            if (conjAlreadyEmitted) {
                                std::cout << "The speed-up is not designed for a new high "
                                                "input pulse to singleConj "
                                                "after he emitted already";
                                mayTrySpeedUp = false;
                            }

                            conjEmittingInputs.insert(itM); // ok even multiple. The constraint
                                                            // is on conjAlreadyEmitted.
                        }
                    }
                }

                // modOutStates[itM] = pulseOut; not managed, only ffStates matters.

                // print pulse
                // std::cout << listDest.size() << (pulseOut? " High" : " Low") << " pulse from
                // " << itM->first << " to ";

                for (const auto& dest : listDest) {
                    // print dest
                    // std::cout << dest << ", ";

                    if (!pulseOut) {
                        if (dest == wantedLow) {
                            std::cout << "low pulse to " << wantedLow << std::endl;
                            std::cout << "\nResult: " << currentCycleCount << std::endl;
                            //TODO: generalize the code! A low pulse does not mean a single low pulse,
                            //add code to check one only.
                            return currentCycleCount;
                        }
                    }

                    const auto itMdest = modules.find(dest);
                    if (itMdest != modules.end()) {
                        pulseList.emplace_back(pulseOut, itMdest);

                        switch (itMdest->second.mt) {
                        case ModuleType::FlipFlop:
                            // operations on ffStates are done directly when processing its
                            // pulse, as FF have only one input.
                            break;
                        case ModuleType::Conjunction: {
                            const auto itC = conjInStates.find(itMdest);
                            if (itC == conjInStates.end()) {
                                throw std::runtime_error(
                                    "conjunction states not found for dest");
                            }
                            // itC->second[itM] = pulseOut;
                            const auto itS = itC->second.find(itM); // itM as 'input'
                            if (itS == itC->second.end()) {
                                throw std::runtime_error("conjunction state-in not found");
                            }
                            itS->second = pulseOut;
                        } break;
                        default:
                            throw std::runtime_error("unexpected destination module type");
                        }

                    } // else: e.g., 'output' in the example
                }

                // std::cout << '\n';
            }
        }
        // std::cout << '\n';


        if (conjAlreadyEmitted) { //-> means some of the interesting inputs emitted. This
                                    // condition might be removed.
            // For sure it pulsed low, otherwise the cycle would have been already broken.

            // check for cycles on inputs.
            for (const auto& itI : conjEmittingInputs) {
                // avoid uselessly increasing memory of configPerInput if cycle has been already
                // found for this input.
                if (cyclePerInput.count(itI) == 0U) { // high pulse from the current input.
                    const auto itFI = ffStatesPerInput.find(itI);
                    const auto& ffPerInput = itFI->second;

                    auto& configPerInput = ffConfigsPerInputs.find(itI)->second;

                    if (configPerInput.count(ffPerInput) > 0U) {
                        const auto oldCycleCount = configPerInput.find(ffPerInput)->second;

                        cyclePerInput.emplace(
                            itI, std::make_pair(oldCycleCount, currentCycleCount));
                    }

                    configPerInput[ffPerInput] = currentCycleCount;
                }
            }
        }

        if (mayTrySpeedUp && (cyclePerInput.size() == ffStatesPerInput.size())) {
            // Found a cycle for all interesting inputs.

            /* special case of cycles all starting on zero.
            Count one = 1UL;

            auto res = std::accumulate(
                cyclePerInput.cbegin(),
                cyclePerInput.cend(),
                one,
                [](const auto acc, const auto& keyValue) {
                    if (keyValue.second.first > 0U) {
                        throw std::runtime_error("generalize code for gcd and lcm!");
                    }
                    const auto lcm = std::lcm(acc, keyValue.second.second);
                    if (((lcm % acc) != 0U) || ((lcm % keyValue.second.second) != 0U)) {
                        throw std::runtime_error("Need a larger type for Count");
                    }

                    return lcm;
                }); */

            // Each sequence emits the first time the high pulse after 'first' and then
            // repeats again and again after 'period = second-first'. If all 'first' would
            // be zero, the solution will be hit after lcm(period1, ..., periodN) cycles.
            // In case of some 'first' > 0, the first hit may be
            // found accumulating a resulting couple (firstTot, periodTot) adding a new
            // couple (first,period) at a time and solve each time the problem for two couples
            // only, the accumulated one and the new one. For two couples (f1,p1) and (f2,p2),
            // the first time to hit together may be found considering the points f1, f1+p1,
            // f1+p1*2,
            // ..., up to f1+p1*(p2-1), if for any of these points the accumulated delay of the
            // second compared to the first is multiple of p2 itself. Therefore, it is better to
            // us as p1 the maximum and as p2 the minimum between them, which means we cannot
            // start the accumulation through a dummy seed {0,1} because generally the
            // accumulation may have higher period. Then, the cumulated period is lcm(p1,p2).
            // So, this decays anyway to lcm(p1,...,pN) at the end of the story. Therefore,
            // again, it is better to order by decreasing periods.
            std::vector<std::pair<CycleNumber, CycleNumber>> listFirstAndPeriod;
            std::transform(
                cyclePerInput.cbegin(),
                cyclePerInput.cend(),
                std::back_inserter(listFirstAndPeriod),
                [](const auto& inAndCycle) {
                    const auto& firstAndSecondTime = inAndCycle.second;
                    return std::make_pair(
                        firstAndSecondTime.first,
                        firstAndSecondTime.second - firstAndSecondTime.first);
                });

            std::sort(
                listFirstAndPeriod.begin(),
                listFirstAndPeriod.end(),
                [](const auto& dp1, const auto& dp2) {
                    return (dp2.second < dp1.second);
                    // based on period. The higher first.
                });

            const auto resCycle = std::accumulate(
                std::next(listFirstAndPeriod.cbegin()),
                listFirstAndPeriod.cend(),
                *listFirstAndPeriod.cbegin(),
                [](const auto accCycle, const auto& scrollCycle) {
                    const auto gcdPeriods = std::gcd(accCycle.second, scrollCycle.second);

                    auto absDiffDelta = (accCycle.first >= scrollCycle.first)
                        ? (accCycle.first - scrollCycle.first)
                        : (scrollCycle.first - accCycle.first);

                    if ((absDiffDelta % gcdPeriods) > 0U) {
                        std::cout << "Diff between deltas " << absDiffDelta
                                    << " is not a multiple of gdc " << gcdPeriods << '\n';
                        throw std::invalid_argument("Will never meet together");
                    }

                    CycleNumber delay = // delay of the second over the first at the
                                        // moment the first has its first occurrence.
                        (scrollCycle.first >= accCycle.first)
                        ? absDiffDelta // <= scrollCycle.first <
                                        // scrollCycle.second
                        : (scrollCycle.second - (absDiffDelta % scrollCycle.second));
                    // Note that in second case it is possible absDiffDelta
                    // is multiple of p2, therefore the correct value of
                    // delay is zero (sync happening on first occurrence:
                    // point d1).
                    if (delay == scrollCycle.second) {
                        delay = 0U;
                    }

                    // TODO: is there a formula to understand deltaRes in
                    // O(1) instead of O(p2) ?

                    auto recoveryPerEachP1
                        = (accCycle.second - scrollCycle.second) % scrollCycle.second;
                    // zero only if p1 is multiple of p2, but in this case
                    // delay is zero soon (if not, absDiffDelta % gcdPeriods
                    // would have been positive, leading above to understand
                    // impossible sync).
                    const auto delayForEachP1 = scrollCycle.second - recoveryPerEachP1;
                    // Note also that reducing accCycle.second by scrollCycle.second
                    // before module is really useless
                    // but it is kept to improve reading.

                    CycleNumber firstRes = accCycle.first;
                    CycleNumber debug = 0U;
                    while (delay > 0U) {
                        delay += delayForEachP1;
                        if (delay >= scrollCycle.second) {
                            delay -= scrollCycle.second;
                        }

                        firstRes += accCycle.second;

                        if (scrollCycle.second == ++debug) {
                            throw std::runtime_error("buggy code");
                        }
                    }

                    auto periodRes = std::lcm(accCycle.second, scrollCycle.second);
                    if (((periodRes % accCycle.second) > 0U)
                        || ((periodRes % scrollCycle.second) > 0U) || (periodRes == 0U)) {
                        // overflow problem.
                        throw std::runtime_error(
                            "Cannot manage the lcm between " + std::to_string(accCycle.second)
                            + " and " + std::to_string(scrollCycle.second));
                    }

                    return std::make_pair(firstRes, periodRes);
                });

            auto res = resCycle.first;
            if (resCycle.first == 0U) {
                // there is no pulse in the initial condition
                res = resCycle.second;
            }

            std::cout << "Result: (speed-up result through lcm): " << res << std::endl;
            return res;
        }

        /* not needed for part n.2
        ffConfigs[ffStates] = currentCycleCount;
        memoryPartialPulseCount.emplace_back(lowPulseCount,highPulseCount); */
    }

    std::cout << "No solution within first " << CycleNumberToDo << " cycles; will stop"
                << std::endl;
    throw std::invalid_argument("Impossible");
}

int main()
{
    try {
        day20Part2(Input, false);
        // day20Part2("./20_input_file.txt",true);
    } catch (std::invalid_argument& ex) {
        std::cout << std::endl; // in order to flash
        std::cerr << "Bad input: " << ex.what() << std::endl;
        return 1;
    } catch (std::exception& ex) {
        std::cout << std::endl; // in order to flash
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    } catch (...) {
        std::cout << std::endl; // in order to flash
        std::cerr << "Unknown error: " << std::endl;
        return 1;
    }

    return 0;
}


/*
OUTPUT:

example:
conjunction input a
conjunction input b
The speed-up cannot work with common ancestor between the inputs: b and a
Lines count 5
Modules n. 6
Part of testing modules n. 1
Result: 1

real input:
conjunction input qs
conjunction input dt
conjunction input js
conjunction input ts
Lines count 58
Modules n. 59
Part of testing modules n. 1
emission true for interesting input qs at the cycle 3943
emission true for interesting input dt at the cycle 3947
emission true for interesting input ts at the cycle 4007
emission true for interesting input js at the cycle 4019
Result: (speed-up result through lcm): 250628960065793
*/
