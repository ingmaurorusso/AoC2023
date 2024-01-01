#include <algorithm>
#include <array>
#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

constexpr std::string_view Input =

false ?

"Time:      7  15   30\n"
"Distance:  9  40  200\n"

:

"Time:        47     98     66     98\n"
"Distance:   400   1213   1011   1540\n"
;

bool toUnsigned(const std::string& s, unsigned long& res) {
    try {
        if (s.empty()) {
            return false;
        }
        if (!std::all_of(std::next(s.cbegin()), s.cend(), [](const char ch) {
                return std::isdigit(ch); // avoid first, with '-' in order to allow '-0'.
            })) {
            // stoul would ignore tailing non-digits.
            // Here ignore first char, that is, allowing '-' (specific check later for future use).
            return false;
        }
        res = std::stoul(s);
        // Note also that stoul would have converted into unsigned a value starting with minus
        // ('-').

        if (s.find('-') != std::string::npos) {
            // stoul converts negative values with a reinterpret cast.
            if (s.substr(0U, 2U) != "-0") {
                return false;
            }
        }

        return errno != ERANGE;
    } catch (...) {
        // std::invalid_argument, eventually std::out_of_range
        return false;
    }
}

auto day06Part2(std::string_view streamSource, bool sourceIsFilePath)
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

    using Value = unsigned long;
    using Time = Value;
    using Distance = long double;

    Time time = 0U;
    Distance dist = 0U;

    size_t timeDigits = 0U;
    size_t distDigits = 0U;

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

        std::stringstream lineStream;
        lineStream << line;

        std::string tokenTitle;

        if (!(lineStream >> tokenTitle)) {
            throw std::invalid_argument(errorLine + "no token!");
        }

        if (tokenTitle == "Time:") {
            if (lineCount != 1U) {
                throw std::invalid_argument(errorLine + "times not in expected line");
            }
        } else if (tokenTitle == "Distance:") {
            if (lineCount != 2U) {
                throw std::invalid_argument(errorLine + "distances not in expected line");
            }
        } else {
            // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
            throw std::invalid_argument(errorLine + "unexpected title: " + tokenTitle);
        }

        std::string tokenNumber;
        const auto enrichValue
            = [&tokenNumber, &errorLine](auto& v, size_t& digits) {
                    using V = std::remove_reference_t<decltype(v)>;

                    using std::literals::string_literals::operator""s;
                    static const std::string errorDigits
                        = "too many digits, "s + typeid(V).name() + " is not enough";

                    Value number{};
                    if (!toUnsigned(tokenNumber, number)) {
                        // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                        throw std::invalid_argument(errorLine + "not a number: " + tokenNumber);
                    }

                    digits += tokenNumber.length();
                    if (digits >= std::numeric_limits<V>::digits10) {
                        // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                        throw std::invalid_argument(errorLine + errorDigits);
                    }

                    constexpr auto BaseDec = 10.0;
                    auto mult = std::pow(BaseDec, tokenNumber.length());

                    if constexpr (std::is_same_v<V, double>) {
                        v *= mult;
                    } else {
                        v *= static_cast<V>(mult);
                    }
                    if constexpr (std::is_same_v<V, Value>) {
                        v += number;
                    } else {
                        v += static_cast<V>(number);
                    }
                };

        while (lineStream >> tokenNumber) {
            if (lineCount == 1U) {
                enrichValue(time, timeDigits);
            } else {
                enrichValue(dist, distDigits);
            }
        }
    }

    unsigned long res{};
    {
        std::cout << "time for race = " << time << std::endl;
        std::cout << "dist for race = " << dist << std::endl;

        auto timeD = static_cast<Distance>(time);

        constexpr auto FourTimes = 4.0L;
        auto det = std::pow(timeD, 2) - dist * FourTimes;
        // std::cout << "det = " << det << std::endl;
        if (det < 0) {
            res = 0U;
        } else {
            auto rootDet = std::sqrt(det);
            // std::cout << "root = " << rootDet << std::endl;

            constexpr auto Half = 0.5L;
            auto minPushD = (timeD - rootDet) * Half;
            auto maxPushD = (timeD + rootDet) * Half;

            constexpr auto ZeroDistance = 0.0L;
            Value minPush
                = (minPushD < ZeroDistance) ? 0U : static_cast<Value>(std::ceil(minPushD));
            auto maxPush = static_cast<Value>(std::trunc(maxPushD));

            constexpr auto DistanceLimit = std::numeric_limits<Distance>::max();

            using std::literals::string_literals::operator""s;
            static const std::string errorOverflow = "Overflow in final multiply checks, "s
                + typeid(Value).name() + " is not enough";

            minPushD = static_cast<Distance>(minPush);
            if ((minPushD - 1U) > (DistanceLimit / (timeD - minPushD + 1U))) {
                throw std::invalid_argument(errorOverflow);
            }
            if (minPushD * (time - minPush) == dist) {
                ++minPush;
            } else
                // Further check against lack of precision when computing minPushD.
                if ((minPush - 1U) * (time - minPush + 1U) > dist) {
                --minPush;
            }

            maxPushD = static_cast<Distance>(maxPush);
            if ((timeD - maxPushD - 1U) > (DistanceLimit / (maxPushD + 1U))) {
                throw std::invalid_argument(errorOverflow);
            }
            if (maxPush * (time - maxPush) == dist) {
                --maxPush;
            } else
                // Further check against lack of precision when computing maxPushD.
                if ((maxPush + 1U) * (time - maxPush - 1U) > dist) {
                ++maxPush;
            }

            res = (maxPush - minPush + 1);

            std::cout << "times for race from " << minPush << " to " << maxPush
                        << " ; n. total = " << (maxPush - minPush + 1) << std::endl;
        }
    }

    std::cout << "\nResult: " << res << "\n\n\n";

    return res;
}

int main06p2()
{
    try {
        day06Part2(Input, false);
        // day06Part2("./06_input_file.txt",true);
    } catch (std::invalid_argument& ex) {
        std::cerr << "Bad input: " << ex.what() << std::endl;
        return 1;
    } catch (std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error: " << std::endl;
        return 1;
    }

    return 0;
}


/*
OUTPUT:

Example:
time for race = 71530
dist for race = 940200
times for race from 14 to 71516 ; n. total = 71503
Result: 71503

Real input:
time for race = 4.79867e+07
dist for race = 4.00121e+14
times for race from 10743463 to 37243235 ; n. total = 26499773
Result: 26499773
*/
