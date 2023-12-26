#include <algorithm>
#include <array>
#include <exception>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace{

constexpr std::string_view Input =

false ?

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

bool charToModuleType(const char ch, ModuleType &mt)
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

struct Module{
    ModuleType mt;
    Destinations dests;
};

} // namespace

auto day20Part1()
{
    std::stringstream inputStream{};
    inputStream << Input;

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

    unsigned lineCount{0U};
    constexpr auto MaxLineLength = 1000;
    std::array<char, MaxLineLength + 1> cc{};
    while (inputStream.getline(cc.data(), MaxLineLength, '\n')) {
        ++lineCount;
        std::string errorLine = "Input error at the line n. "
            + std::to_string(static_cast<int>(lineCount)) + " : ";

        auto c = static_cast<size_t>(inputStream.gcount());
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
            throw std::invalid_argument(errorLine + "unexpected module name: " + moduleName);
        }

        auto [itM, ok] = modules.insert(std::make_pair(moduleName, Module{mt, Destinations{}}));
        if (!ok) {
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

    // initialize conjInStates
    {
        // std::unordered_set<Modules::iterator, decltype(hashItM)>
        // ffAlready(ffStates.size(),hashItM);

        for (auto itM = modules.begin(); itM != modules.end(); ++itM) {
            for (const auto& dest : itM->second.dests) {
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
                                throw std::invalid_argument( "flip-flop " + dest + " with
                    multiple inputs");
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

    using Count = unsigned long;

    // Start propagation of pulses
    std::list<std::pair<bool, Modules::iterator>> pulseList;

    static const auto compConfigs = [](const ModulesState& cm1, const ModulesState& cm2) {
        // assume they have the same keys.
        auto it1 = cm1.cbegin();
        auto it2 = cm2.cbegin();
        while (it1 != cm1.cend()) {
            if (it1->second != it2->second) {
                return it2->second; // true if couple (false < true)
            }
            ++it1;
            ++it2;
        }
        return false;
    };

    using Configs
        = std::map<ModulesState, unsigned, decltype(compConfigs)>; // TODO: unordered_map
    Configs ffConfigs(compConfigs); // records when a configuration was touched.
    ffConfigs[ffStates] = 0U;

    std::vector<std::pair<Count, Count>> memoryPartialPulseCount;
    memoryPartialPulseCount.emplace_back(0U, 0U);

    using CycleNumber = unsigned long;
    constexpr CycleNumber CycleNumberToDo = 1000UL;

    Count lowPulseCount = 0U;
    Count highPulseCount = 0U;
    Count pulsesToTestModules = 0U;

    unsigned cycleStart = 0U;
    unsigned cycleEnd = CycleNumberToDo;

    for (unsigned i = 0; i < CycleNumberToDo; ++i) {
        const auto currentCycleCount = i + 1U;

        // a button pressure determines a pulse toward the broadcaster.
        ++lowPulseCount;
        pulseList.emplace_back(false, itBC);
        // print pulse
        // std::cout << "1 Low pulse from button to broadcaster\n"; // TODO: printing lambda

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
                // modOutStates[itM] = pulseOut; not needed, flip-folp states are enough

                // print pulse
                // std::cout << listDest.size() << (pulseOut ? " High" : " Low") << " pulse
                // from
                // "
                //           << itM->first << " to ";

                for (const auto& dest : listDest) {
                    // print dest
                    // std::cout << dest << ", ";

                    if (pulseOut) {
                        ++highPulseCount;
                    } else {
                        ++lowPulseCount;
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

                    } else {
                        ++pulsesToTestModules;
                        // e.g., 'output' in the example
                    }
                }

                // std::cout << '\n';
            }
        }
        // std::cout << '\n';

        if (ffConfigs.count(ffStates) > 0U) {
            // NOT USED IN THE REAL INPUT!
            const auto oldCycleCount = ffConfigs.find(ffStates)->second;

            const auto delta
                = (CycleNumberToDo - currentCycleCount) % (currentCycleCount - oldCycleCount);
            const auto factor
                = (CycleNumberToDo - currentCycleCount) / (currentCycleCount - oldCycleCount);

            const auto deltaLow = lowPulseCount - memoryPartialPulseCount[oldCycleCount].first;
            const auto deltaHigh
                = highPulseCount - memoryPartialPulseCount[oldCycleCount].second;

            if (std::max(deltaLow, deltaHigh) > std::numeric_limits<Count>::max() / factor) {
                throw std::runtime_error("Need a larger type for Count");
            }
            if ((deltaLow * factor) > (std::numeric_limits<Count>::max() - lowPulseCount)) {
                throw std::runtime_error("Need a larger type for Count");
            }
            if ((deltaHigh * factor) > (std::numeric_limits<Count>::max() - highPulseCount)) {
                throw std::runtime_error("Need a larger type for Count");
            }

            lowPulseCount += (deltaLow * factor);
            highPulseCount += (deltaHigh * factor);

            lowPulseCount
                += (memoryPartialPulseCount[oldCycleCount + delta].first
                    - memoryPartialPulseCount[oldCycleCount].first);
            highPulseCount
                += (memoryPartialPulseCount[oldCycleCount + delta].second
                    - memoryPartialPulseCount[oldCycleCount].second);

            cycleStart = oldCycleCount;
            cycleEnd = currentCycleCount - 1U;
            break;
        }

        ffConfigs[ffStates] = currentCycleCount;

        memoryPartialPulseCount.emplace_back(lowPulseCount, highPulseCount);
    }

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Modules (exclude testing ones) n. " << modules.size() << std::endl;
    std::cout << "Total low pulses " << lowPulseCount << std::endl;
    std::cout << "Total high pulses " << highPulseCount << std::endl;
    std::cout << "Total pulses to testing modules " << pulsesToTestModules << std::endl;
    std::cout << "Cycle starts at " << cycleStart << std::endl;
    std::cout << "Cycle ends at " << cycleEnd << std::endl;

    auto res = lowPulseCount * highPulseCount;
    std::cout << "Result: " << res << std::endl;
    return res;
}

int main()
{
    try {
        day20Part1();
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

Example:
Lines count 5
Modules (exclude testing ones) n. 5
Total low pulses 4250
Total high pulses 2750
Total pulses to testing modules 6
Cycle starts at 0
Cycle ends at 3
Result: 11687500

Real input:
Lines count 58
Modules (exclude testing ones) n. 58
Total low pulses 19274
Total high pulses 48670
Total pulses to testing modules 6871
Cycle starts at 0
Cycle ends at 1000
Result: 938065580
*/
