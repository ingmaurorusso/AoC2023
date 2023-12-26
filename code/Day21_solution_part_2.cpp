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
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace{

constexpr std::string_view Input =
false ?

"...........\n"
".....###.#.\n"
".###.##..#.\n"
"..#.#...#..\n"
"....#.#....\n"
".##..S####.\n"
".##..#...#.\n"
".......##..\n"
".##.#.####.\n"
".##..##.##.\n"
"...........\n"

:

"...................................................................................................................................\n"
"................#.##....#......#.........#.....#.........................#......................#....#................#............\n"
"....#....#..#....#..#..##.#.............#.....#...##......................#............................##.......#........#.........\n"
".#......................................#........#.....#..............................................#...................#..#.....\n"
"...###.#.....#...................#..........................................#..##.......#..#...................#...................\n"
".....................#.#...........##.....#........#...#......................###...........................#......................\n"
"...............#..................#...........#....#...............................#.....#...............................#.........\n"
"......#..........#.##....#.......#.#....................................................................###......#....#............\n"
"...........#....#..............#....................#....................................#......#.......#..........#.........#...#.\n"
"....##.........##..#.........#...............#....................#...............#.....#.##.....#............#.....#.#............\n"
"...#..#..........#............#.....#....#...##...#....................#.............#.....#.....#...#...................#.........\n"
"....#.............#.....#...#...#...........##.................#..................#.#...........#...........##.........#...........\n"
"......#............................#..........................................................#...#......#..#...........#..........\n"
"...........................#...........#.............................................#.....#..#...........#......................#.\n"
".#..#...#..##.##............#...##..............................#....................#................#.............#....#.........\n"
"......................#...........#....................#..............................#..................#.......#.................\n"
"...........#.......#................#.....#.#.............#.#......#.................................##..#......................#..\n"
"...............#......#....................#...........#..................................#.....#..#............#.......#.#....#...\n"
"..#...........#.#.......................................#...#........#..#................#..............#..#.#.......#........#....\n"
"......................#...#..........................................................................#........#....................\n"
".............#.............##...#...........................#..#....#.....................#..#.......#...........#.................\n"
".#....................#......#.....#....#.......#.............#...##..............#........#.#....#..#..............#......#..#....\n"
"....#.......#...............##.................#.................................................#........#....#....#..............\n"
".#.............#....#..........................#................................................#.............#.##.................\n"
"..#........................#...........................................#............#........#.........#..#.................#......\n"
"......................#.............#...............#.........#........##......#.#.......................#.........#...#...........\n"
"..#...........#..............#..............#...........#......#.........#...#.....#.......................#...#.#.................\n"
"...##..#.........#...............#....................#..#..#..#.....#..............#...#..............#.#...#......#.#............\n"
".......................#.............................#....#...#............#..#...................................#..............#.\n"
".#...#.##..........#..##.#.......................#........#.....#...................................#.#...........#....#..##....#..\n"
"..............#.#....#.......#...........#.........#......#....................#......##............#..............................\n"
"..............#..........#............#..........#.....#....#.............................#.#.......#.....#.....#..........#.......\n"
"..#.....#....#..........#.....................##..#....##..#..##......#....................................#..................#....\n"
"...................#..#...............##...............#.#....#..................##.......................#........#...........#...\n"
"....#...#..................#................................#......#...#.....#...........#................................#........\n"
"....................................#...........#..#......##.......#..#.................#..#.......................................\n"
"............#....#....#............#.#.................#........................#...............#............#..............#......\n"
"................................#............#..................#.##.....#.....................#............###...........#...#.#..\n"
".............#.........#.........#.................#..................##....#..........#..#..............................#.#.......\n"
"..........................................#................#........#..........#............#...........................#....##..#.\n"
".#...#...#.....##...........................#.............#..............................#..#.................#..#....#.........##.\n"
"............#...............#.....#..#.....#.................#........#..#.......#........#...##.#...............#.......#..#...#..\n"
"..#.#.#.........#..........#............#..##....#......###........#.#......#....#..#.....#.......#........................#.......\n"
".............#....................#.#.#.............#...#.#.....#..#....#.#...#....#....#.......#.#....................#...#.......\n"
"......##..................#............#....................#...................#....#.........#.#.........................#..#....\n"
"............#.##.........#...............#...........................#..............#.#............................#...............\n"
"........#....#...............#.....#..#......#...##....#............#.....#.........##.....................#..................#....\n"
".................................##....#..#.#.......#........#.................#.#.........................#...........#.#.#.......\n"
"........................#....#............................#..#.....#.....#.#...........................................#...........\n"
".#.......#...........#....#......................#.........#......#...#...#.......#.#..........##.....#................#...........\n"
"......#...........................#......#.#.......#.......#.#........................#..................#..............#..........\n"
"........#.........#........#..#...................#...#...#...#......#.#................##.#......#.......#...............#..#..##.\n"
".......#........................#..........##.........#...##..............#.....#.....#............................................\n"
".......#................#....##.......................#..#..................#....................#.............#.............#.....\n"
"............................#...#...#........##........##..........#.......#..............#......................................#.\n"
"......#............................................#.........#......#....................#.....#.##.#.............#................\n"
"...............#...........##......#..........................#...........#..............................#.#....#.#..........#..#..\n"
"........................##..................................................#.......................#........#.....#...............\n"
"....................#..............#..............#.............#.......#..........................#.............#.................\n"
".................#..#.#.#......#.........#.....#...........#.......#..........#...........#........................................\n"
".................................................#.............................................#..........#....#..##...#.........#.\n"
"...................#....#.................#.......#...#............#....................#.............#...............#............\n"
".........#....#......#......#...#...#.......#.......#..#.............#....#.....#..............#....#...................#..........\n"
".........#..#..............................#....#.......#.......#....#.....#...#...#...#...........#.....##...............#........\n"
".....#..................#....#........#............##.#....#..............#...#.#.....#...........#.#......#....#..................\n"
".................................................................S.................................................................\n"
".......#...........#.#.........#...#........#.#......#.......##.#......##...........................#...#.....#.........#..........\n"
"..................................................#............................#..........#................###......##..#..........\n"
"........#....#.......................#.##...#......#...........#..............#......#............#................................\n"
".........................#...........................#.................#....#..#................#....................#.............\n"
"...................#..................#.........................#........##....#.................##..#..#.......##.....#...........\n"
"...............................#..#........#.#........#..............#............#..##...#.#.......#..............................\n"
"...............#.............#...#.....#.........#..##............................#..............#.#........#..#...#...............\n"
"..#.........#................#.......##...............#...............#........#......#.......#...........##...#.#..#...........#..\n"
".............#............#....##..#.#......##...##..#................................#..#.....##....#........................#....\n"
"..............#.....#...#.....#...................#.......##.#.......#..#..............................#.....#.....................\n"
"........................#......#...#......#.....#...........#.#...#...................#........#..........#..#.....................\n"
"...................#..................#.......#......................................##......#...#..#........##....................\n"
".....................#......................#.........#.#.#.............#.....#...........#...#..........#.........................\n"
".........................#.#...#..........#....##.............................#........#......#...#.........#......................\n"
".#......#.#...............#.#.#.#.............#...#...#...............##..#...........#...#..........#.#.#...#...................#.\n"
"........#.###...........#..#..........##.....#.#.........#.#..#..............#..............#..........................#.....#.....\n"
"......#........................................#......#.........#...#..............................#.....................#.....##..\n"
"....#...#.....................#....#..........#.........................#....#.#..........#..#...#..................#.......#......\n"
"...#......#..............#.....................#..........................#...........#.....#....#...#.............................\n"
"........#.......#.........#................#...........#......##......................................#...................#.##.....\n"
"..#..#..#...................#..................#.........#...#......#............#..#.#.#.........#..#.............................\n"
".........##..##...........................#.........#.....................#.......#.#...#...#.......#................#.#...........\n"
".....#.......#..............#...#..................#.................................#..#..#......#...#..............#........#....\n"
"............................#.............#.................................#..#..#...#................................#..#........\n"
"........#.#....#.............#.#............#..............##.......###............................#..........#..........#.........\n"
".......#...#....................#....#.#....#...#.#.#...##.........................#..........................................#....\n"
"..#......................................................###.........................#...............................#.##..........\n"
"......#........#...#..............#......#...............#...##.#...#.........#.........#.........#...................##...........\n"
".........#.....#..................#............#.....#........#........#..................#.#.............#........#....#..........\n"
"...##...............#...#...........#..##...........#...#.#................##.......#....#.#....#...........#........#.#...........\n"
"......#.............#...................##..#................#................#..........#...#..........#.......#...........#......\n"
".......#................................................#..............#..........#.#......#..#........#....#....#.#...#...........\n"
"....#.....#.........#...#....#.........................#..#.............##.....#.#...............................#.#.....#.........\n"
".......................................#.....##.....#...#.#......................#..#................................#...........#.\n"
"......#..........##.#..........................................#.......##..#.........##........................#................#..\n"
"..............#.......#........................#.......#.#......#...............#.#.................#.............#..#.............\n"
"....................................................#...........#.....#......#.#.#................##....#...#.#.#.........#........\n"
"........#..................#.................................##.....................#...#............##.....#.#.........#...#...#..\n"
".....#....#.#...#......#......#.........................#.#...............#..#.......................#...........#..##.........#.#.\n"
"..........#.................................#.....................#...#.#......#.....##...........#..............#.................\n"
"..##..##.....................#..................#.#......#.#.......#....#.#..........................#.#...#.........#...#.........\n"
"...................#.......#...#.....................................#...#........#....................#.............#.......#.....\n"
"............#..#..#...................................#......#..................#..........#..........##....................#......\n"
"...........##.........#...#.#.....#....#............##...#.............................................#..#.....#..........#.......\n"
"......#....#..............#.......#..................#...##...#.#.......#..........................#...#..............##...........\n"
"............#..##....#...........#..#....##...........#........................................#.....#..#..#........#..............\n"
"....................#.....#.#....#.........#.........#.......................................................#.........#....#......\n"
".........#...#...................#........................#..................#................#............#.#.....................\n"
".......................#.......#..........................#..#........................#.........#..................#....#..........\n"
"...#.#.................................#..#...................#......#.....#.......................#......#.......#.........#......\n"
"...#............#.....#...#.....#.....#.#................#....#....#.#...#................#...............#...............#....#...\n"
"...............................#.........................####.#...#...#...............................#.........................##.\n"
".....#.................#..#..##.....#...#....................##....................#.#........#................#.#...........#.....\n"
".#.............#..#.........#.###.#...........#............#....................#........................#......#....###..#........\n"
"......#.......#..#.........#......................##..............................#...................#.......#......#....#........\n"
"....#.....#.......................#.........#.....................#................#..............#....................#......#....\n"
"......#............#...#...#....#.#.................#...............#...................#..........#.............#..#.#............\n"
"......................#............................#...................................#.#.#...#.#...#........#..........#....#..#.\n"
"......#......................#..............#.......#........................#.............##.#.#..................................\n"
"..................................#............##..........................#......#......#..#...............#......................\n"
"......#.........#..##.#...##......#............#..........................#.......#........#....##...#...#.........................\n"
".#....................#.........#.........#.................................##...............##...........#............#...#.......\n"
"..#..................#.....#.......#..#.........#.....#..###..................#.......#....#.............##.#..#...................\n"
".#.....#...#.#.............#.....#.....#..#.....#.........#...........#...#......#............#..#.#.......#......#................\n"
"...................................................................................................................................\n"

;

using Coord = signed long long;

struct Point {
    Coord x;
    Coord y;
};
bool operator==(const Point& p1, const Point& p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}

bool operator<(const Point& p1, const Point& p2)
{
    if (p1.y != p2.y) {
        return (p1.y < p2.y);
    }
    return (p1.x < p2.x);
}
bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}
std::string pointToStr(Point p)
{
    using std::literals::string_literals::operator""s;
    return "("s + std::to_string(p.x) + ", " + std::to_string(p.y) + ')';
}

enum class Direction : unsigned { Right, Down, Left, Up };

constexpr auto FourDir = 4U;

template<typename E>
constexpr auto toUnderlying(const E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

std::string dirToStr(Direction d)
{
    using std::literals::string_literals::operator""s;
    switch (d) {
    case Direction::Right:
        return "Right";
    case Direction::Down:
        return "DownUp";
    case Direction::Left:
        return "Left";
    case Direction::Up:
        return "Up";
    default:
        throw std::runtime_error(
            "Inconsistent direction to print: "s + std::to_string(toUnderlying(d)));
    }
}

} // namespace

auto day21Part2() // NOLINT(readability-function-size)
{
    std::stringstream inputStream{};
    inputStream << Input;

    std::vector<std::string> lines;
    size_t rowsLength{};

    using Dir = Direction;

    using CycleCount = unsigned long;

    using PosCount = unsigned long; // for tiles

    PosCount rocksInBasicField = 0U;

    CycleCount res = 0U;

    bool startFound = false;
    Point startP{};

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

        // std::stringstream lineStream;
        // lineStream << line;

        if (line.empty()) {
            std::cout << "WARNING: empty line\n";
        } else if (lines.empty()) {
            rowsLength = line.size();
        } else if (rowsLength != line.size()) {
            throw std::invalid_argument(errorLine + "line length different from previous ones");
        }

        if (!std::all_of(line.cbegin(), line.cend(), [](const char ch) {
                return (ch == '#') || (ch == '.') || (ch == 'S');
            })) {
            throw std::invalid_argument(errorLine + "some non-digit character");
        }

        const auto posS = line.find('S');
        if (posS != std::string::npos) {
            if (startFound) {
                throw std::invalid_argument(errorLine + "repeated start");
            }
            startFound = true;
            startP = Point{static_cast<Coord>(posS), static_cast<Coord>(lineCount - 1U)};

            if (line.find('S', posS + 1U) != std::string::npos) {
                throw std::invalid_argument("two starts in the same line");
            }
        }

        rocksInBasicField += static_cast<PosCount>(
            std::count_if(line.cbegin(), line.cend(), [](const char ch) { return ch == '#'; }));

        lines.push_back(std::move(line));
    }

    if (!startFound) {
        throw std::invalid_argument("no start point 'S' found");
    }

    const auto& cLines = lines;

    const auto movePoint = [&lines = cLines](
                                Point& p,
                                Dir d,
                                Coord stepMoreThan1 = 0U,
                                bool acceptBeyond = false,
                                bool toroidal = false) {
        static const auto nRows = static_cast<Coord>(lines.size());
        static const auto nCols = static_cast<Coord>(lines[0].size());

        const Coord step = stepMoreThan1 + 1U; // include now the first.
        bool ok = true;
        switch (d) {
        case Dir::Down: {
            if ((!acceptBeyond) && ((p.y + step) >= nRows)) {
                if (toroidal) {
                    (p.y += step) -= nRows;
                } else {
                    ok = false;
                }
            } else {
                p.y += step;
            }
        } break;
        case Dir::Up: {
            if ((!acceptBeyond) && (p.y < step)) {
                if (toroidal) {
                    (p.y += nRows) -= step;
                } else {
                    ok = false;
                }
            } else {
                p.y -= step;
            }
        } break;
        case Dir::Right: {
            if ((!acceptBeyond) && ((p.x + step) >= nCols)) {
                if (toroidal) {
                    (p.x += step) -= nCols;
                } else {
                    ok = false;
                }
            } else {
                p.x += step;
            }
        } break;
        case Dir::Left: {
            if ((!acceptBeyond) && (p.x < step)) {
                if (toroidal) {
                    (p.x += nCols) -= step;
                } else {
                    ok = false;
                }
            } else {
                p.x -= step;
            }
        } break;
        }

        return ok;
    };

    static const auto rotateDir = [](Dir& dir, bool clockwise = true) {
        switch (dir) {
        case Dir::Down:
            dir = clockwise ? Dir::Left : Dir::Right;
            break;
        case Dir::Left:
            dir = clockwise ? Dir::Up : Dir::Down;
            break;
        case Dir::Up:
            dir = clockwise ? Dir::Right : Dir::Left;
            break;
        case Dir::Right:
            dir = clockwise ? Dir::Down : Dir::Up;
            break;
        }
    };

    static const auto isVertDir = [](Dir dir) {
        switch (dir) {
        case Dir::Down:
            [[fallthrough]];
        case Dir::Up:
            return true;
        default:
            return false;
        }
    };

    const auto printPoints = [&cLines, &startP](const auto& prPoints) {
        auto linesCopy = cLines;
        linesCopy[static_cast<size_t>(startP.y)][static_cast<size_t>(startP.x)] = '.';

        for (const auto& p : prPoints) {
            linesCopy[p.y][p.x] = 'O';
        }

        for (const auto& line : linesCopy) {
            std::cout << line << '\n';
        }
        std::cout << '\n';
    };

    constexpr CycleCount NumSteps = 26501365U;

    // NOLINTNEXTLINE(readability-magic-numbers)
    static const auto hashPointL = [](const Point& p) { return p.y * 1000L + p.x; };
    // without std::function, problems for the deleted copy assignment operator
    // of the custom lambda, even when use move assignment operator of PointSet.
    static std::function<Coord(const Point&)> hashPoint = hashPointL;

    using PointSet = std::unordered_set<Point, decltype(hashPoint)>;
    // unordered as the number may be big.

    using Entry = std::pair<Point, Dir>;


    static const auto compPointSetL = [](const PointSet& s1, const PointSet& s2) {
        if (s1.size() != s2.size()) {
            return s1.size() < s2.size();
        }

        auto it1 = s1.cbegin();
        auto it2 = s2.cbegin();
        while (it1 != s1.cend()) {
            if (*it1 != *it2) {
                return *it1 < *it2;
            }
            ++it1;
            ++it2;
        }

        return false; // all equivalent
    };
    static const std::function<bool(const PointSet&, const PointSet&)> compPointSet
        = compPointSetL;
    using WhenConfigs
        = std::map<PointSet, CycleCount, decltype(compPointSet)>; // map as short size expected.
    static const auto compWhenConfigsL = [](const WhenConfigs& wc1, const WhenConfigs& wc2) {
        if (wc1.size() != wc2.size()) {
            return wc1.size() < wc2.size();
        }

        auto it1 = wc1.cbegin();
        auto it2 = wc2.cbegin();
        while (it1 != wc1.cend()) {
            if (it1->first != it2->first) {
                return compPointSet(it1->first, it2->first);
            } // else
            if (it1->second != it2->second) {
                return it1->second < it2->second;
            }
            ++it1;
            ++it2;
        }

        return false; // all equivalent
    };
    static const std::function<bool(const WhenConfigs&, const WhenConfigs&)> compWhenConfigs
        = compWhenConfigsL;

    using TimesToConfig = std::vector<WhenConfigs::iterator>;
    using ExitHistory = std::map<CycleCount, std::set<Entry>>; // need ordered.

    // for each entry point, compute configs until cycle.
    // ok not unordered, the
    std::map<Entry, WhenConfigs> configsByEntry;
    std::map<Entry, TimesToConfig> timesByEntry;
    std::map<Entry, CycleCount> cycleStartByEntry;
    std::map<Entry, ExitHistory> exitByEntry;

    const auto isRock = [&cLines](const Point p) {
        return (cLines[static_cast<size_t>(p.y)][static_cast<size_t>(p.x)] == '#');
    };

    std::array<std::set<Coord>, FourDir> rocksBorder{};

    const auto computeConfigsDebug = [&cLines, &movePoint, &isRock](Point start) {
        static const auto nRows = static_cast<Coord>(cLines.size());
        static const auto nCols = static_cast<Coord>(cLines[0].size());

        PointSet points(1U, hashPoint);

        points.insert(start);

        CycleCount currentCycle = 0U;

        while (NumSteps >= ++currentCycle) {
            PointSet newPoints(points.size(), hashPoint);

            for (const auto& p : points) {
                Dir dir = Direction::Up;
                for (auto d = 0U; d < FourDir; ++d) {
                    Point p2 = p;
                    movePoint(p2, dir, 0U, true);

                    Point pCheck = p2;
                    if (pCheck.x < 0) {
                        pCheck.x += (nCols * (1 - (pCheck.x + 1) / nCols));
                    }
                    if (pCheck.x >= nCols) {
                        pCheck.x %= nCols;
                    }
                    if (pCheck.y < 0) {
                        pCheck.y += (nRows * (1 - (pCheck.y + 1) / nRows));
                    }
                    if (pCheck.y >= nRows) {
                        pCheck.y %= nRows;
                    }

                    if (!isRock(pCheck)) {
                        newPoints.insert(p2);
                    }
                    rotateDir(dir);
                }
            }

            points = std::move(newPoints);
            // printPoints(points);
        }

        return points;
    };

    const auto& cRocksBorder = rocksBorder;

    const auto computeConfigs = [&configsByEntry,
                                    &timesByEntry,
                                    &cycleStartByEntry,
                                    &exitByEntry,
                                    &cLines,
                                    &cRocksBorder,
                                    &movePoint,
                                    &isRock](Entry entry) {
        static const auto nRows = static_cast<Coord>(cLines.size());
        static const auto nCols = static_cast<Coord>(cLines[0].size());

        WhenConfigs& whenConfigs
            = configsByEntry.emplace(entry, WhenConfigs(compPointSet)).first->second;
        TimesToConfig& timesConfigs = timesByEntry[entry];
        // CycleCount& cycleStart = cycleStartByEntry[entry];
        ExitHistory& exitHistory = exitByEntry[entry];

        PointSet points(1U, hashPoint);

        points.insert(entry.first);

        CycleCount currentCycle = 0U;

        timesConfigs.push_back(whenConfigs.emplace(points, 0U).first);

        bool cycleFound = false;

        using EntryAndWhen = std::pair<Entry, CycleCount>;
        std::set<EntryAndWhen> exitAlready;
        // avoid recording the same exit-Entry multiple times if it
        // has the same 'oddness' in cycle number.

        while (!cycleFound) {
            if (NumSteps < ++currentCycle) {
                break; // useless beyond
            }

            PointSet newPoints(points.size(), hashPoint);
            for (const auto& p : points) {
                Dir dir = Direction::Up;
                for (auto d = 0U; d < FourDir; ++d) {
                    Point p2 = p;
                    if (movePoint(p2, dir)) {
                        if (!isRock(p2)) {
                            newPoints.insert(p2);
                        }
                    } else {
                        switch (dir) {
                        case Dir::Up:
                            p2.y = nRows - 1U;
                            break;
                        case Dir::Down:
                            p2.y = 0U;
                            break;
                        case Dir::Left:
                            p2.x = nCols - 1U;
                            break;
                        case Dir::Right:
                            p2.x = 0U;
                            break;
                        }

                        if (!isRock(p2)) { // in case the entry in next part would be a rock.
                            const bool odd = ((currentCycle % 2U) == 1U);
                            const auto c = isVertDir(dir) ? p2.x : p2.y;

                            bool add = true;
                            for (const auto& entryAndWhen : exitAlready) {
                                const auto& entryAlready = entryAndWhen.first;

                                if (entryAlready.second == dir) {
                                    const auto when = entryAndWhen.second;

                                    const bool oddEntry = ((when % 2U) == 1U);
                                    auto cEntry = isVertDir(dir) ? entryAlready.first.x
                                                                    : entryAlready.first.y;

                                    if (odd == oddEntry) {
                                        auto c0 = c;
                                        if (cEntry < c0) {
                                            std::swap(c0, cEntry);
                                        }
                                        if (currentCycle - when
                                            >= static_cast<PosCount>(cEntry - c0)) {
                                            // Simply: check there are no rocks [more
                                            // generally, one might check if there is a path
                                            // from one to another with length not higher
                                            // than currentCycle-when and the same
                                            // oddness...]
                                            bool noRocks = true;
                                            std::reference_wrapper<const std::set<Coord>>
                                                cRockSetRef
                                                = std::ref(cRocksBorder[toUnderlying(dir)]);

                                            const auto itRock
                                                = cRockSetRef.get().lower_bound(c0);
                                            if ((itRock != cRockSetRef.get().end())
                                                && (*itRock <= cEntry)) {
                                                // some rock in the middle. Don't eliminate, as
                                                // there is no direct path between the two
                                                // 'exits'.
                                                noRocks = false;
                                            }

                                            if (noRocks) {
                                                add = false;
                                            }
                                        }
                                    }
                                }
                                if (!add) {
                                    break;
                                }
                            }

                            if (add) {
                                exitHistory[currentCycle].insert(Entry{p2, dir});
                                exitAlready.emplace(Entry{p2, dir}, currentCycle);
                            }
                        }
                    }
                    rotateDir(dir);
                }
            }

            points = newPoints;
            // printPoints(points);

            auto [it, ok] = whenConfigs.emplace(points, currentCycle);
            if (ok) {
                timesConfigs.push_back(it); // in position with index currentCycle.
            } else {
                cycleFound = true;
                // cycleStart = it->second;
                cycleStartByEntry[entry] = it->second;
            }
        }
    };


    const auto nRows = static_cast<Coord>(cLines.size());
    const auto nCols = static_cast<Coord>(cLines[0].size());

    PosCount nonRocksInBasicField
        = static_cast<size_t>(nRows) * static_cast<size_t>(nCols) - rocksInBasicField;

    Dir dummyDirForStart{};
    Entry startEntry{startP, dummyDirForStart};

    // set rocksBorder before using computeConfigs.
    for (Coord x = 0U; x < nCols; ++x) {
        if (isRock(Point{x, 0})) {
            rocksBorder[toUnderlying(Direction::Up)].insert(x);
        }
        if (isRock(Point{x, nRows - 1})) {
            rocksBorder[toUnderlying(Direction::Down)].insert(x);
        }
    }
    for (Coord y = 0U; y < nRows; ++y) {
        if (isRock(Point{0, y})) {
            rocksBorder[toUnderlying(Direction::Left)].insert(y);
        }
        if (isRock(Point{nCols - 1, y})) {
            rocksBorder[toUnderlying(Direction::Right)].insert(y);
        }
    }

    computeConfigs(startEntry);

    /*
    delayed: only when needed
    for(Coord x = 0U; x < nCols; ++x){
        computeConfigs(Entry{Point{x,0U},Dir::Down});
        computeConfigs(Entry{Point{x,nRows-1U},Dir::Up});
    }
    for(Coord y = 0U; y < nRows; ++y){
        computeConfigs(Entry{Point{0U,y},Dir::Right});
        computeConfigs(Entry{Point{nCols-1U,y},Dir::Left});
    }
    */

    // now initialize map of fields with non-full points and set of full ones.
    using SuperPoint = Point; // a super-point represents a full rectangle-field repetition.
    using SuperPointSet = PointSet;
    using EntryAndTime = std::pair<Entry, CycleCount>;

    std::unordered_map<SuperPoint, PointSet, decltype(hashPoint)> pointsInParts(0U, hashPoint);
    std::unordered_map<SuperPoint, std::map<EntryAndTime, ExitHistory>, decltype(hashPoint)>
        workingEntriesPerPart(0U, hashPoint);

    workingEntriesPerPart[SuperPoint{0U, 0U}].emplace(
        EntryAndTime{startEntry, 0U}, exitByEntry[startEntry]);
    pointsInParts.emplace(SuperPoint{0U, 0U}, PointSet(1U, hashPoint))
        .first->second.insert(startP);

    SuperPointSet fullParts(0U, hashPoint);

    CycleCount currentCycle = 0U;
    CycleCount oldCurrentCycle = 0U;

    std::unordered_set<SuperPoint, decltype(hashPoint)> activeParts(0U, hashPoint);
    std::unordered_set<SuperPoint, decltype(hashPoint)> unstableParts(0U, hashPoint);
    using StableResume = std::map<
        WhenConfigs,
        std::tuple<TimesToConfig, std::unordered_map<CycleCount, PosCount>>,
        decltype(compWhenConfigs)>;
    std::unordered_map<SuperPoint, StableResume::iterator, decltype(hashPoint)> stableParts(
        0U, hashPoint);
    std::unordered_map<SuperPoint, CycleCount, decltype(hashPoint)> stablePartsModPer(
        0U, hashPoint);
    StableResume stableResume(compWhenConfigs);
    // Each part state moves from active to unstable to stable, unless again to active when
    // a new propagation activates again a part. 'unstable' means that it is waiting
    // just for a period.
    // stableResume contains, for each possible periodicity from stableParts (identified by a
    // WhenConfigs 'set' [0 dummy values]), the current corresponding TimesToConfig at the first
    // time that whenConfigs was found, and a map of counting for how many parts share the same
    // whenConfigs set, organized by when-splacements.
    activeParts.insert(SuperPoint{0U, 0U});

    // data structure for unstable ones.
    std::unordered_map<SuperPoint, WhenConfigs, decltype(hashPoint)> configsHistInUnstableParts(
        0U, hashPoint);
    std::unordered_map<SuperPoint, TimesToConfig, decltype(hashPoint)>
        timesConfigsHistInUnstableParts(0U, hashPoint);

    using EntriesToPropagate = std::map<SuperPoint, std::set<Entry>>;

    const auto updateForPart =
        [&pointsInParts,
            &fullParts,
            &workingEntriesPerPart,
            &timesByEntry,
            &cycleStartByEntry,
            &movePoint,
            &currentCycle,
            nonRocksInBasicField](SuperPoint partCoords, EntriesToPropagate& entriesToPropagate) {
            auto itP = pointsInParts.find(partCoords);
            if (itP == pointsInParts.end()) {
                // possible because pointsInParts is lightened when a key enters into
                // stableParts, whereas this is not done for workingEntriesPerPart as it aims to
                // stop propagations when possible. TODO: likely possible to infer a reduction
                // also in workingEntriesPerPart when a part is stable since long long time....
                // in the sense that the risk not to block a future propagation is much lower
                // than the advantage to reduce memory in workingEntriesPerPart.
                itP = pointsInParts.emplace(partCoords, PointSet(1U, hashPoint)).first;
            }

            // not true this may be const, later there is "exitHistory.erase(itH);".
            // cppcheck-suppress constVariable
            std::map<EntryAndTime, ExitHistory>& entriesAndTimeWithHistory
                = workingEntriesPerPart[partCoords];

            PointSet newPoints(itP->second.size(), hashPoint);
            for (auto& [entryAndTime, exitHistory] : entriesAndTimeWithHistory) {
                const auto& entry = entryAndTime.first;
                const auto when = entryAndTime.second;

                const auto elapsedTime = currentCycle - when;

                const TimesToConfig& times = timesByEntry[entry];
                const CycleCount cycleStart = cycleStartByEntry[entry];

                const CycleCount period = times.size() - cycleStart;

                // -> links to configsByEntry[entry]
                auto index = (elapsedTime > cycleStart)
                    ? cycleStart + ((elapsedTime - cycleStart) % period)
                    : elapsedTime;
                auto addPoints = times[index]->first; // a copy
                newPoints.merge(addPoints);

                const auto itH = exitHistory.find(elapsedTime);
                if (itH != exitHistory.end()) {
                    const std::set<Entry>& exits = itH->second;
                    for (const auto& exit : exits) {
                        SuperPoint newPart = partCoords;
                        movePoint(newPart, exit.second, 0U, true);

                        entriesToPropagate[newPart].insert(exit);
                    }

                    exitHistory.erase(itH);
                    // useless to repeat again in the future, but the element
                    // is not removed from entriesAndTimeWithHistory, in order
                    // to keep memory of something already done.
                }
            }

            if (newPoints.size() == nonRocksInBasicField) {
                // TODO: never hit in example and real input.
                // Simpy keep the information that this part is full.
                // const auto itPsave = std::next(itP);
                pointsInParts.erase(itP);
                // itP = itPsave;
                fullParts.insert(partCoords);

                workingEntriesPerPart.erase(partCoords); // as this is by then also useless.
            } else {
                itP->second = std::move(newPoints);
                // ++itP;
            }
        };

    const auto computeNumPoints
        = [&](/*PointSet& debugPoints,std::map<SuperPoint,PointSet>& stableOut*/) {
                /*
                debugPoints.clear();
                stableOut.clear();
                */

                // full ones
                PosCount numPoints = fullParts.size() * nonRocksInBasicField;

                // active ones
                // std::cout << "active parts n. " << activeParts.size() << std::endl;
                for (const auto partCoords : activeParts) {
                    // already computed
                    /*
                    auto copyPoints = pointsInParts.find(partCoords)->second;
                    for(auto p : copyPoints)
                        debugPoints.insert(Point{p.x+partCoords.x*nCols,p.y+partCoords.y*nRows});

                    numPoints += copyPoints.size();
                    */
                    numPoints += pointsInParts.find(partCoords)->second.size();
                }

                // unstable ones
                // std::cout << "unstable parts n. " << unstableParts.size() << std::endl;
                for (const auto partCoords : unstableParts) {
                    // already computed
                    /*
                    auto copyPoints = pointsInParts.find(partCoords)->second;
                    for(auto p : copyPoints)
                        debugPoints.insert(Point{p.x+partCoords.x*nCols,p.y+partCoords.y*nRows});

                    numPoints += copyPoints.size();
                    */

                    numPoints += pointsInParts.find(partCoords)->second.size();
                }

                // stable ones
                for (auto itResume = stableResume.begin(); itResume != stableResume.end();
                    ++itResume) {
                    const auto& [whenConfigs, resumeTuple] = *itResume;

                    const TimesToConfig& timesToConfig = std::get<0>(resumeTuple);
                    const std::unordered_map<CycleCount, PosCount>& whenAndHowMany
                        = std::get<1>(resumeTuple);

                    CycleCount period = timesToConfig.size();

                    for (const auto [modWhenZero, howMany] : whenAndHowMany) {
                        CycleCount modCycleCount = (modWhenZero + currentCycle) % period;

                        const PointSet& pointsStable = timesToConfig[modCycleCount]->first;
                        PosCount partial = pointsStable.size();
                        if (partial == 0U) {
                            // just the dummy element of whenConfigs, need to recompute
                            // specifically because of jumped iteration. Need to find some of the
                            // stableParts corresponding to the current element of stableResume.
                            bool found = false;
                            for (const auto& [partCoords, itResumeFromStable] : stableParts) {
                                if ((itResumeFromStable == itResume)
                                    && (stablePartsModPer[partCoords] == modWhenZero)) {
                                    EntriesToPropagate dummyEntriesToPropagate;
                                    updateForPart(partCoords, dummyEntriesToPropagate);
                                    const PointSet& pointsStable2
                                        = pointsInParts.find(partCoords)->second;
                                    partial = pointsStable2.size();
                                    found = true;

                                    /*
                                    stableOut[partCoords] = pointsStable2;

                                    // debug:
                                    for(const auto& [partCoords2,itResumeFromStable2] :
                                    stableParts){ if ((itResumeFromStable2 == itResume) &&
                                    (stablePartsModPer[partCoords2] == modWhenZero)){
                                            stableOut[partCoords2] = pointsStable2;
                                        }
                                    }
                                    */

                                    break;
                                }
                            }

                            if (!found) {
                                throw std::runtime_error("inconsistent stableParts");
                            }
                        } /* else{
                            // debug:
                            for(const auto& [partCoords,itResumeFromStable] : stableParts){
                                if ((itResumeFromStable == itResume) &&
                        (stablePartsModPer[partCoords] == modWhenZero)){ stableOut[partCoords] =
                        pointsStable;
                                }
                            }
                        }
                        */

                        partial *= howMany;

                        numPoints += partial;
                    }
                }

                return numPoints;
            };

    Coord oldMaxManDistPart = 0U;

    std::pair<CycleCount, PosCount> zeroPair{0U, 0U};
    using LastThree = std::array<std::pair<CycleCount, PosCount>, 3U>;
    LastThree lastThree{zeroPair, zeroPair, zeroPair};
    LastThree superLastThree{zeroPair, zeroPair, zeroPair};

    using DetType = signed long long;
    using Dets = std::array<DetType, 4U>;
    std::vector<Dets> savedDets;
    std::array<DetType, 3U> finalCoeffNum{0U, 0U, 0U};
    std::array<DetType, 3U> finalCoeffDenum{0U, 0U, 0U};
    bool doingFinalWaitConfirmation = false;
    bool doingFinalWaitConfirmation2 = false;
    CycleCount startDoingFinalWaitConfirmation2{};
    CycleCount rescrollInConfirmation2{};

    bool superConfirmation = false;
    CycleCount lastPeriodBetweenNewMaxMan = NumSteps;
    CycleCount lastCycleNewMaxMan = 0U;

    const auto inferNumPointsLD
        = [&finalCoeffNum, &finalCoeffDenum](CycleCount cycleIn, PosCount& posCount) {
                // infer based on the cofficients.
                auto cycle = static_cast<long double>(cycleIn);
                long double cycle2 = cycle * cycle;

                posCount = static_cast<PosCount>(
                    (cycle2 * finalCoeffNum.at(0U) / finalCoeffDenum.at(0U))
                    + (cycle * finalCoeffNum.at(1U) / finalCoeffDenum.at(1U))
                    + (static_cast<long double>(finalCoeffNum.at(2U)) / finalCoeffDenum.at(2U)));

                return true;
            };

    const auto inferNumPoints = [&finalCoeffNum, &finalCoeffDenum, &inferNumPointsLD](
                                    CycleCount cycleIn,
                                    PosCount& posCount,
                                    bool mayTryLongDouble = false) {
        // infer based on the cofficients.
        auto cycle = static_cast<DetType>(cycleIn);
        DetType cycle2 = cycle * cycle;

        auto gcd0 = std::gcd(cycle2, finalCoeffDenum.at(0U));
        if (finalCoeffNum.at(0U) != 0) {
            if (cycle2 / gcd0 > std::numeric_limits<DetType>::max() / finalCoeffNum.at(0U)) {
                std::cout << "need higher type, try long double\n";
                if (!mayTryLongDouble) {
                    throw std::runtime_error("neeed long double to try");
                } // else:
                return inferNumPointsLD(cycleIn, posCount);
            }
        }
        DetType num0 = (cycle2 / gcd0) * finalCoeffNum.at(0U);
        DetType denum0 = finalCoeffDenum.at(0U) / gcd0;

        auto gcd1 = std::gcd(cycle, finalCoeffDenum.at(1U));
        DetType num1 = (cycle / gcd1) * finalCoeffNum.at(1U);
        DetType denum1 = finalCoeffDenum.at(1U) / gcd1;

        DetType num2 = finalCoeffNum.at(2U);
        DetType denum2 = finalCoeffDenum.at(2U);

        auto lcmTot = std::lcm(denum0, denum1);
        lcmTot = std::lcm(lcmTot, denum2);

        auto numTot
            = num0 * (lcmTot / denum0) + num1 * (lcmTot / denum1) + num2 * (lcmTot / denum2);

        if (numTot > 0) {
            // Elements of finalCoeffDenum are properly set to non-zero before they are used.
            // NOLINTNEXTLINE(clang-analyzer-core.DivideZero)
            if ((numTot % lcmTot) == 0) {
                posCount = static_cast<PosCount>(numTot / lcmTot);
                return true;
            }
        }

        return false;
    };

    while (currentCycle < NumSteps) {
        ++currentCycle;
        CycleCount nextCycleCount = NumSteps;
        if (doingFinalWaitConfirmation) {
            nextCycleCount = currentCycle; // don't care local speed-up, try max speed-up
        } else {
            nextCycleCount
                = currentCycle + ((NumSteps - currentCycle) % lastPeriodBetweenNewMaxMan);
            // in order to hit the next value for which trying superConfirmation.
        }

        std::set<SuperPoint> toDeactive;

        Coord minManDistPart = NumSteps; // 1000000000UL; NOLINT(readability-magic-numbers)
        Coord maxManDistPart = 0U;

        for (const auto partCoords : activeParts) {
            maxManDistPart
                = std::max(maxManDistPart, std::abs(partCoords.x) + std::abs(partCoords.y));
            minManDistPart
                = std::min(minManDistPart, std::abs(partCoords.x) + std::abs(partCoords.y));

            bool stillActive = false;

            const auto itW = workingEntriesPerPart.find(partCoords);

            const std::map<EntryAndTime, ExitHistory>& entriesAndTimeWithHistory = itW->second;

            for (const auto& [entryAndTime, exitHistory] : entriesAndTimeWithHistory) {
                // const auto& entry = entryAndTime.first;
                const auto when = entryAndTime.second;

                if (!exitHistory.empty()) {
                    stillActive = true;
                }

                const auto elapsedTime = currentCycle - when;
                const auto itH = exitHistory.lower_bound(elapsedTime);
                if (itH != exitHistory.end()) {
                    nextCycleCount = std::min(nextCycleCount, when + itH->first);
                } // else: no new exit due to that entry.
            }

            if (!stillActive) {
                toDeactive.insert(partCoords);
            }
        }
        for (const auto partCoords : toDeactive) {
            // move to unstable
            activeParts.erase(partCoords);

            unstableParts.insert(partCoords);

            // preliminary add an empty point-set, as dummy element for when iterations are
            // jumped.
            configsHistInUnstableParts.emplace(partCoords, WhenConfigs(compPointSet))
                .first->second.emplace(PointSet(0U, hashPoint), 0U);
            timesConfigsHistInUnstableParts.emplace(partCoords, TimesToConfig());
        }

        // next time has been chosen.
        currentCycle = nextCycleCount;
        /*
        if (currentCycle == NumSteps) {
            activeParts.size();
        }
        */

        /*
        std::cout << "currentCycle " << currentCycle << "\n\n";
        std::cout << " Active n. " << activeParts.size() << "\n";
        std::cout << " Unstable n. " << unstableParts.size() << "\n";
        std::cout << " Stable n. " << stableParts.size() << "\n";
        std::cout << " minManDistPart " << minManDistPart << "\n";
        std::cout << " maxManDistPart " << maxManDistPart << "\n";
        std::cout << " deltaMan " << (maxManDistPart-minManDistPart) << "\n\n";
        */

        // move points for each part, based on working entries,
        // and find also the new propagation on boundaries.
        EntriesToPropagate newEntriesToPropagate;

        for (const auto partCoords : activeParts) {
            updateForPart(partCoords, newEntriesToPropagate);
        }
        for (const auto partCoords : unstableParts) {
            // for the ones not yet stable, don't care about propagations (ther would not be,
            // exit story is empty)
            EntriesToPropagate dummyEntriesToPropagate;
            updateForPart(partCoords, dummyEntriesToPropagate);
        }

        bool oddNow = ((currentCycle % 2U) == 1U);

        std::set<SuperPoint> additionallyComputed;

        // check effective propagations:
        for (const auto& [partCoords, entries] : newEntriesToPropagate) {
            if (fullParts.count(partCoords) > 0U) {
                continue; // the part is already full.
            } // else:

            std::map<EntryAndTime, ExitHistory>& workingEntries
                = workingEntriesPerPart[partCoords];
            PointSet& pointsInPart
                = pointsInParts.emplace(partCoords, PointSet(0U, hashPoint)).first->second;
            // remains added if the propagation fails, not a problem.
            // The constraint is that any part in activeParts has a key here.

            for (const auto& entry : entries) {
                auto itET = workingEntries.lower_bound(std::make_pair(entry, 0U));

                if ((activeParts.count(partCoords) == 0U)
                    && (additionallyComputed.count(partCoords) == 0U)) { // need to update.
                    additionallyComputed.insert(
                        partCoords); // just to avoid to recompute here multiple times.
                    EntriesToPropagate dummyEntriesToPropagate;
                    updateForPart(partCoords, dummyEntriesToPropagate);
                }

                bool add = (pointsInPart.count(entry.first) == 0U);

                for (int i = 0; (i < 2) && add; ++i) {
                    if (itET == workingEntries.end()) {
                        break;
                    } // else:
                    if (itET->first.first != entry) {
                        break; // only higher points
                    } // else:

                    bool oddE = ((itET->first.second % 2U) == 1U);
                    if (oddNow == oddE) {
                        add = false;
                    }
                    ++itET; // check even next, in case of different odd but still same point.
                }

                if (add) {
                    // effectively propagated.
                    // Check if computeConfigs was called on this entry:
                    if (exitByEntry.count(entry) == 0U) {
                        computeConfigs(entry);
                    }

                    pointsInPart.insert(entry.first);
                    activeParts.insert(partCoords);

                    unstableParts.erase(partCoords);
                    configsHistInUnstableParts.erase(partCoords);
                    timesConfigsHistInUnstableParts.erase(partCoords);

                    {
                        auto itSt = stableParts.find(partCoords);
                        if (itSt != stableParts.end()) {
                            // TODO: never hit in example and real input.
                            auto itStModPer = stablePartsModPer.find(partCoords);

                            std::get<1>(
                                itSt->second->second)[itStModPer->second]--; // don't care if it
                                                                                // remains zero.

                            stableParts.erase(itSt);
                            stablePartsModPer.erase(itStModPer);
                        }
                    }

                    ExitHistory historyToWork = exitByEntry[entry];

                    // remove from historyToWork the case of go-back (with the same oddness)
                    std::set<CycleCount> futuresToRemove;

                    for (auto& [future, futureEntries] : historyToWork) {
                        const bool oddFuture = ((future % 2U) == 1U);
                        if (!oddFuture) {
                            std::set<Entry> entriesToRemove;
                            for (const auto& futureEntry : futureEntries) {
                                const auto futureDir = futureEntry.second;

                                if ((isVertDir(futureDir) == isVertDir(entry.second))
                                    && (futureDir != entry.second)) {
                                    entriesToRemove.insert(futureEntry);
                                }
                            }

                            for (auto futureEntry : entriesToRemove) {
                                futureEntries.erase(futureEntry);
                            }
                            if (futureEntries.empty()) {
                                futuresToRemove.insert(future);
                            }
                        }
                    }

                    for (auto future : futuresToRemove) {
                        historyToWork.erase(future);
                    }

                    // even empty, it makes sense to know
                    workingEntries.insert(
                        std::make_pair(EntryAndTime{entry, currentCycle}, historyToWork));
                }
            }
        }

        SuperPointSet toStabilize(0U, hashPoint);
        for (const auto partCoords : unstableParts) {
            // check periodicity for partCoords.
            WhenConfigs& whenConfigs = configsHistInUnstableParts.find(partCoords)->second;
            TimesToConfig& timesConfigs
                = timesConfigsHistInUnstableParts.find(partCoords)->second;

            const auto itP = pointsInParts.find(partCoords);

            const auto [itWC, isNewC] = whenConfigs.emplace(itP->second, 0U);
            // here 0U is used, not currentCycle, so that the whenConfigs may match in
            // stableResume. Indeed, the eral cycle number does not matter, but the record in
            // timesConfigs that are implicitly associated to the last steps until currentCycle.
            if (isNewC) {
                if (!timesConfigs.empty()) {
                    // preliminary insert dummy elements for the jumped iterations:
                    CycleCount jumpedIter = currentCycle - oldCurrentCycle;
                    if (jumpedIter > 1U) {
                        timesConfigs.resize(
                            timesConfigs.size() + jumpedIter - 1U,
                            whenConfigs.find(PointSet(
                                0U, hashPoint))); // to the dummy element with the empty set.
                    }
                }

                timesConfigs.push_back(itWC);
            } else {
                // period found, stop, remove from unstable, but keep
                // in configsHistInUnstableParts and timesConfigsHistInUnstableParts.

                // The period may have begun not for timesConfigs[0].
                CycleCount realPeriodRefStart = 0U;
                while (realPeriodRefStart < timesConfigs.size()) {
                    if (timesConfigs[realPeriodRefStart] == itWC) {
                        break;
                    }
                    ++realPeriodRefStart;
                }

                if (realPeriodRefStart > 0U) {
                    CycleCount source = realPeriodRefStart;
                    CycleCount dest = 0U;
                    while (source < timesConfigs.size()) {
                        timesConfigs[dest++] = timesConfigs[source++];
                    }
                    timesConfigs.resize(timesConfigs.size() - realPeriodRefStart);
                }

                if (timesConfigs.empty()) {
                    // It means not found in timesConfigs and realPeriodRefStart
                    // was equal to timesConfigs.size().
                    throw std::runtime_error("incosistent timesConfigs");
                }

                // auto nDebug = itP->second.size();
                toStabilize.insert(partCoords);
            }
        }

        for (const auto partCoords : toStabilize) {
            // about configsHistInUnstableParts and timesConfigsHistInUnstableParts
            // it is better just to keep a map with key as timesConfigs
            // and a map of initial step-count when it started with count.
            auto itC = configsHistInUnstableParts.find(partCoords);
            auto itT = timesConfigsHistInUnstableParts.find(partCoords);
            WhenConfigs& whenConfigs = itC->second;
            TimesToConfig& timesConfigs = itT->second;

            CycleCount period = timesConfigs.size();
            // the relative step index is 0 but must be shifted to when currentCycle was zero.
            CycleCount backIndex = 0U;

            backIndex = period - (currentCycle % period);
            if (backIndex == period) {
                backIndex = 0U; // currentCycle multiple of period.
            }

            const auto copyFirstConfig = timesConfigs[0U]->first; // before moving stuff.
            auto timesConfigsSize = timesConfigs.size(); // save before moving.

            auto [itR, newInResume] = stableResume.emplace(
                std::move(whenConfigs),
                std::make_tuple(
                    std::move(timesConfigs), std::unordered_map<CycleCount, PosCount>()));

            // using StableResume =
            // std::map<WhenConfigs,std::pair<TimesToConfig,std::unordered_map<CycleCount,PosCount>>>;???

            if (newInResume) {
                std::get<1>(itR->second)[backIndex] = 1U; // one part only.
            } else {
                // first, the index must be shifted, based on the comparison between
                // timesConfigs and itR->second.first Exploit copyFirstConfig.
                const TimesToConfig& resumeTimesConfigs = std::get<0>(itR->second);
                if (resumeTimesConfigs.size() != timesConfigsSize) {
                    /* this is possible, due to jumped iterations, that might lead not to
                        realize soon a period and consider a longer period
                    std::runtime_error("inconsistent timesConfigs"); */
                    period = resumeTimesConfigs.size();
                    backIndex = period - (currentCycle % period);
                    if (backIndex == period) {
                        backIndex = 0U; // currentCycle multiple of period.
                    }
                }
                bool found = false;
                for (size_t i = 1U; (i < resumeTimesConfigs.size()) && !found; ++i) {
                    if (resumeTimesConfigs[i]->first == copyFirstConfig) {
                        // in the resume, there is a delay 'i', therefore it is
                        // like the new one started 'i' steps earlier compared
                        // to the sequence already present in the resume map.
                        backIndex = ((backIndex + i) % period);
                        found = true;
                    }
                }

                if ((!found) && (resumeTimesConfigs[0U]->first != copyFirstConfig)) {
                    throw std::runtime_error("inconsistent resumeTimesConfigs");
                }

                std::get<1>(itR->second)[backIndex]++; // one more for the new part.
            }
            stableParts.emplace(partCoords, itR);
            stablePartsModPer.emplace(partCoords, backIndex);

            // to reduce memory and complexity in pointsPerParts, this is lightened:
            pointsInParts.erase(partCoords);

            unstableParts.erase(partCoords);
            configsHistInUnstableParts.erase(itC);
            timesConfigsHistInUnstableParts.erase(itT);
        }

        static const auto computeDet = [](const auto& matrixArrOfArr) {
            DetType det = 0U;
            for (size_t i = 0; i < 3U; ++i) {
                // compute i-th diagonal
                DetType partial = 1U;
                for (size_t j = 0; j < 3U; ++j) {
                    partial *= matrixArrOfArr.at(j).at((j + i) % 3U);
                }
                det += partial;
            }
            for (size_t i = 0U; i < 3U; ++i) {
                // compute i-th anti-diagonal
                DetType partial = 1U;
                for (size_t j = 3U; j > 0U;) {
                    --j;
                    partial *= matrixArrOfArr.at(j).at((2U - j + i) % 3U);
                }
                det -= partial;
            }

            return det;
        };

        static const auto computeCurrentDets = [](const LastThree& lastThreeToUse, Dets& dets) {
            // check for the three coefficients:
            std::array<std::array<DetType, 3U>, 3U> matrixCoeff{};
            std::array<DetType, 3U> colRes{};

            for (size_t row = 0; row < 3U; ++row) {
                auto cycle = static_cast<DetType>(lastThreeToUse.at(row).first);
                matrixCoeff.at(row).at(0U) = cycle * cycle;
                matrixCoeff.at(row).at(1U) = cycle;
                matrixCoeff.at(row).at(2U) = 1U;
                colRes.at(row) = static_cast<DetType>(lastThreeToUse.at(row).second);
            }

            bool okDets = true;
            const auto detDown = computeDet(matrixCoeff);
            dets.at(3U) = detDown;
            if (detDown == 0) {
                okDets = false;
            } else {
                for (size_t col = 0U; col < 3U; ++col) {
                    std::array<DetType, 3U> saveMatrixCol{};
                    saveMatrixCol.at(0U) = matrixCoeff.at(0U).at(col);
                    saveMatrixCol.at(1U) = matrixCoeff.at(1U).at(col);
                    saveMatrixCol.at(2U) = matrixCoeff.at(2U).at(col);

                    matrixCoeff.at(0U).at(col) = colRes.at(0U);
                    matrixCoeff.at(1U).at(col) = colRes.at(1U);
                    matrixCoeff.at(2U).at(col) = colRes.at(2U);

                    auto detUp = computeDet(matrixCoeff);

                    dets.at(col) = detUp;

                    // restore:
                    matrixCoeff.at(0U).at(col) = saveMatrixCol.at(0U);
                    matrixCoeff.at(1U).at(col) = saveMatrixCol.at(1U);
                    matrixCoeff.at(2U).at(col) = saveMatrixCol.at(2U);
                }
            }

            return okDets;
        };

        const auto computeCoeff = [&finalCoeffNum, &finalCoeffDenum](const Dets& dets) {
            // const DetType detDown = detList.at(3U); already above
            const auto detDown = dets.at(3U);
            for (size_t row = 0U; row < 3U; ++row) {
                DetType detUp = dets.at(row);
                if (detUp == 0) {
                    finalCoeffNum.at(row) = 0;
                    finalCoeffDenum.at(row) = 1;
                } else {
                    bool neg = ((detUp > 0) != (detDown > 0));
                    if (detUp < 0) {
                        detUp = -detUp;
                    }
                    DetType detPos = detDown;
                    if (detDown < 0) {
                        detPos = -detDown;
                    }
                    auto gcd = std::gcd(detUp, detPos);
                    finalCoeffNum.at(row) = (neg ? -detUp : detUp) / gcd;
                    finalCoeffDenum.at(row) = detPos / gcd;
                }
            }
        };

        PosCount newCount = 0U;

        if (((NumSteps - currentCycle) % lastPeriodBetweenNewMaxMan) == 0U) {
            newCount = computeNumPoints(/*debugPoints,stableCheck*/);

            const auto superCycle1 = superLastThree.at(1).first;
            const auto superCycle2 = superLastThree.at(2).first;
            const auto delta01 = superCycle1 - superLastThree.at(0).first;
            const auto delta12 = superCycle2 - superCycle1;
            if ((delta01 == delta12) && ((currentCycle - superCycle2) == delta12)
                && (((NumSteps - superCycle2) % delta12) == 0)) {
                Dets dets;
                if (computeCurrentDets(superLastThree, dets)) {
                    //(_1_)
                    computeCoeff(dets); // prepare to use inferNumPoints
                    // updates finalCoeffNum and finalCoeffDenum to support
                    // the computation of inferNumPoints in (_3_).
                    PosCount inferCount{};
                    if (inferNumPoints(currentCycle, inferCount)) {
                        if (newCount == inferCount) {
                            if (inferNumPoints(NumSteps, inferCount, true)) {
                                superConfirmation = true;
                                doingFinalWaitConfirmation2 = false;
                                break;
                            }
                        }
                    }
                }
            }

            superLastThree.at(0) = superLastThree.at(1);
            superLastThree.at(1) = superLastThree.at(2);
            superLastThree.at(2) = std::make_pair(currentCycle, newCount);
        }

        if (maxManDistPart > oldMaxManDistPart) {
            lastPeriodBetweenNewMaxMan = currentCycle - lastCycleNewMaxMan;
            lastCycleNewMaxMan = currentCycle;

            // A new block entered as active, check for trends.
            // Trends are recorded until maxManDistPart will increase
            // 2 further times and only if the trends are confirmed
            // in the two sequences.
            if (newCount == 0U) { // else: already computed
                newCount = computeNumPoints(/*debugPoints,stableCheck*/);
            }

            /*
            std::cout << "currentCycle " << currentCycle << "\n\n";
            std::cout << " new maxManDistPart " << maxManDistPart << "\n";
            std::cout << " newCount " << newCount << "\n\n";
            */

            if (doingFinalWaitConfirmation2) {
                // always confirmed until this second new maxManDistPart !
                if (rescrollInConfirmation2 == savedDets.size()) {
                    Dets dets = savedDets
                        [(NumSteps - startDoingFinalWaitConfirmation2) % savedDets.size()];

                    //(_2_)
                    computeCoeff(dets); // prepare to use inferNumPoints for (_4_)
                    PosCount inferCount{};
                    if (inferNumPoints(NumSteps, inferCount, true)) {
                        break;
                    }
                } // else: need to restart: different number of iterations.

                doingFinalWaitConfirmation = false;
                doingFinalWaitConfirmation2 = false;
            }

            if (doingFinalWaitConfirmation) {
                doingFinalWaitConfirmation2 = true;
                rescrollInConfirmation2 = 0U;
                startDoingFinalWaitConfirmation2 = currentCycle;
            } else {
                doingFinalWaitConfirmation = true;
                savedDets.clear();
            }
        } else if (doingFinalWaitConfirmation) {
            if (newCount == 0U) { // else: already computed
                newCount = computeNumPoints(/*debugPoints,stableCheck*/);
            }
        }

        if (doingFinalWaitConfirmation) {
            /*
            PointSet debugPoints(0U,hashPoint);
            std::map<SuperPoint,PointSet> stableCheck;
            */

            // quadratic trend expected, as a portion of a 2D-area
            lastThree.at(0) = lastThree.at(1);
            lastThree.at(1) = lastThree.at(2);
            lastThree.at(2) = std::make_pair(currentCycle, newCount);

            if (!doingFinalWaitConfirmation2) {
                Dets dets;
                if (!computeCurrentDets(lastThree, dets)) {
                    doingFinalWaitConfirmation = false;
                } else {
                    savedDets.push_back(dets);
                }
            } else {
                // need confirmation step by step for others... until next maxManDistPart.
                bool confirmation = false;
                if (rescrollInConfirmation2 < savedDets.size()) {
                    Dets dets = savedDets[rescrollInConfirmation2];
                    ++rescrollInConfirmation2;
                    computeCoeff(dets);

                    PosCount inferCount{};
                    if (inferNumPoints(currentCycle, inferCount)) {
                        confirmation = (newCount == inferCount);
                    }
                }

                if (!confirmation) {
                    doingFinalWaitConfirmation = false;
                    doingFinalWaitConfirmation2 = false;
                }
            }
        }

        oldCurrentCycle = currentCycle;
        oldMaxManDistPart = maxManDistPart;
    }

    if (currentCycle == NumSteps) {
        res = computeNumPoints(/*debugPoints,stableCheck*/);
    } else if (superConfirmation) {
        // prepared in (_1_)
        if (!inferNumPoints(NumSteps, res, true)) { //(_3_)
            throw std::runtime_error("incosistent preparation of inference");
        }
    } else if (doingFinalWaitConfirmation2) {
        // prepared in (_2_)
        if (!inferNumPoints(NumSteps, res, true)) { //(_4_)
            throw std::runtime_error("incosistent preparation of inference");
        }
    }

    /*
    PointSet debugPoints(0U,hashPoint);
    std::map<SuperPoint,PointSet> stableCheck;
    */

    /*auto debugPoints2 = computeConfigsDebug(startP);
    auto res2 = debugPoints2.size();
    //if (res != res2)
    {
        std::cout << "stable parts n. " << stableParts.size() << std::endl;

        for(auto p : debugPoints2){
            Point orgP = p;

            SuperPoint partCoords{};
            if (p.x < 0){
                partCoords.x = ((p.x+1)/nCols)-1;
            }else{
                partCoords.x = p.x/nCols;
            }
            p.x -= (partCoords.x*nCols);

            if (p.y < 0){
                partCoords.y = ((p.y+1)/nRows)-1;
            }else{
                partCoords.y = p.y/nRows;
            }
            p.y -= (partCoords.y*nRows);

            if (stableCheck.count(partCoords)){
                if (stableCheck[partCoords].count(p) == 0)
                    std::cout << "miss point " << pointToStr(p) << " in part " <<
    pointToStr(partCoords) << std::endl; stableCheck[partCoords].erase(p); } else
            // per il momento debugPoints contiene solo questi.
            if (activeParts.count(partCoords) + unstableParts.count(partCoords) > 0U){
                if (debugPoints.count(orgP) == 0U){
                    std::cout << "miss point " << pointToStr(orgP) << std::endl;
                } else
                    debugPoints.erase(orgP);
            } else{
                std::cout << "miss point " << pointToStr(orgP) << " (no part)" << std::endl;
            }
        }

        for(auto [super,pSet] : stableCheck){
            // per il momento debugPoints contiene solo questi.
            for(auto p : pSet){
                std::cout << "too much point " << pointToStr(p) << " in part " <<
    pointToStr(super) << std::endl;
            }
        }

        std::cout << "too many active/unstable points " << debugPoints.size() << std::endl;
    }*/

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Rock count " << rocksInBasicField << std::endl;
    std::cout << "N. field rows " << nRows << std::endl;
    std::cout << "N. field cols " << nCols << std::endl;
    std::cout << "Result: " << res << std::endl;
    // std::cout << "Total tiles passed on or reached " << points.size() << std::endl;
    // std::cout << "Total tiles reachable exactly " << points.size() << std::endl;
    return res;
}

int main()
{
    try {
        day21Part2();
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
Lines count 11
Rock count 40
N. field rows 11
N. field cols 11
Result 470149643712804

real input:
Lines count 131
Rock count 1544
N. field rows 131
N. field cols 131
Result 639051580070841
*/
