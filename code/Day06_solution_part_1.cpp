#include <algorithm>
#include <array>
#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace{

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

} // namespace

auto day06Part1()
{
    std::stringstream inputStream{};
    inputStream << Input;

    using Value = unsigned long;
    using Time = Value;
    using Distance = Value;

    std::vector<std::pair<Time, Distance>> races;
    size_t distIndex = 0U;

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
        while (lineStream >> tokenNumber) {
            Value number{};
            if (!toUnsigned(tokenNumber, number)) {
                // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                throw std::invalid_argument(errorLine + "not a number: " + tokenNumber);
            }

            if (lineCount == 1U) {
                races.emplace_back(std::make_pair(number, 0U));
            } else {
                if (distIndex >= races.size()) {
                    throw std::invalid_argument(errorLine + "too many distances");
                }
                races[distIndex].second = number;
                ++distIndex;
            }
        }
    }
    if (distIndex < races.size()) {
        throw std::invalid_argument("Too few distances");
    }

    unsigned long res = 1U;
    for (auto i = 0U; i < races.size(); ++i) {
        auto time = races[i].first;
        auto dist = races[i].second;

        auto timeD = static_cast<double>(time);
        auto distD = static_cast<double>(dist);

        // std::cout << "timeD for race n. " << (i+1) << " = " << timeD << std::endl;
        // std::cout << "distD for race n. " << (i+1) << " = " << distD << std::endl;

        constexpr auto FourTimes = 4.0;
        double det = std::pow(timeD, 2) - distD * FourTimes;
        // std::cout << "det = " << det << std::endl;
        double rootDet = std::sqrt(det);
        // std::cout << "root = " << rootDet << std::endl;

        constexpr auto Half = 0.5;
        double minPushD = (timeD - rootDet) * Half;
        double maxPushD = (timeD + rootDet) * Half;

        Value minPush = (minPushD < 0.0) ? 0U : static_cast<Value>(std::ceil(minPushD));
        auto maxPush = static_cast<Value>(std::trunc(maxPushD));

        using std::literals::string_literals::operator""s;
        static const std::string errorOverflow
            = "Overflow in final multiply checks, "s + typeid(Value).name() + " is not enough";

        constexpr auto ValueLimitD = static_cast<double>(std::numeric_limits<Value>::max());

        minPushD = static_cast<double>(minPush);
        if ((minPushD - 1U) * (timeD - minPushD + 1U) > ValueLimitD) {
            throw std::invalid_argument(errorOverflow);
        }
        if (minPush * (time - minPush) == dist) {
            ++minPush;
        } else
            // Further check against lack of precision when computing minPushD.
            if ((minPush - 1U) * (time - minPush + 1U) > dist) {
            --minPush;
        }

        maxPushD = static_cast<double>(maxPush);
        if ((maxPushD + 1U) * (timeD - maxPushD - 1U) > ValueLimitD) {
            throw std::invalid_argument(errorOverflow);
        }
        if (maxPush * (time - maxPush) == dist) {
            --maxPush;
        } else
            // Further check against lack of precision when computing maxPushD.
            if ((maxPush + 1U) * (time - maxPush - 1U) > dist) {
            ++maxPush;
        }

        res *= (maxPush - minPush + 1);

        std::cout << "times for race n. " << (i + 1) << " from " << minPush << " to " << maxPush
                    << " ; n. total = " << (maxPush - minPush + 1) << std::endl;
    }

    std::cout << "\nResult: " << res << std::endl;

    return res;
}

int main()
{
    try {
        day06Part1();
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
times for race n. 1 from 2 to 5 ; n. total = 4
times for race n. 2 from 4 to 11 ; n. total = 8
times for race n. 3 from 11 to 19 ; n. total = 9
Result: 288

Real input:
times for race n. 1 from 12 to 35 ; n. total = 24
times for race n. 2 from 15 to 83 ; n. total = 69
times for race n. 3 from 25 to 41 ; n. total = 17
times for race n. 4 from 20 to 78 ; n. total = 59
Result: 1660968
*/
