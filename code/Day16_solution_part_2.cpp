#include <array>
#include <exception>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace{

constexpr std::string_view Input =

false ?

".|...\\....\n"
"|.-.\\.....\n"
".....|-...\n"
"........|.\n"
"..........\n"
".........\\\n"
"..../.\\\\..\n"
".-.-/..|..\n"
".|....-|.\\\n"
"..//.|....\n"

:

"\\.................-....-.-.|....................|......./.|.\\................|...........|....--..............\n"
"............-...................|.............|..-.......-/..............-....\\...............................\n"
"|.......//...........................................|...............-......../.....\\....................\\....\n"
"....|......-.-.............-......\\.....\\......../..................../.......................................\n"
"..\\..\\../................../.............-............|....-.........................|......|...............|.\n"
"-..|........................./.................\\.........\\./.............\\..|..-...-.............\\............\n"
".\\......||-..................../................-................./....|........................|.............\n"
"..............\\./...........-.........../-................-.........\\...\\........../-.......|.................\n"
"....-..........-.-.....\\......................../.......-..........-/.....................||................|.\n"
"./..........|/............................\\./............................./....../........\\...-|............\\-\n"
"........\\.............................-...../............---...........|...............|......\\\\..............\n"
"........//....|.\\......./...\\.............|..............\\............./...........-.|..-.............|.......\n"
"...................\\...........-/..-......\\...|........-.|................\\-.......|........\\.................\n"
"|.|....../|............\\./..-........\\..............................-.....................|....../............\n"
"............-....................-..............-..-................|.//.............-.............-..........\n"
"..........-.......-......|-................./........../...\\........-.......................-..\\.......\\......\n"
"................../....|............-....../................./.....................|.................-........\n"
"...\\..............--..|.....||.....\\.............\\../................................................-.-...../\n"
".........-......|....-.................-.......\\-................./..|...................|\\.....\\.....|.|-....\n"
"......................-......................-............/....................\\...../...\\..../...............\n"
"...../......-...............\\...-....|......../.........\\................................|.........../........\n"
"........../.......\\..............-...............\\........-|....-......-.............|...........|........./..\n"
"./...............\\....../....../..../...................................................|.....|.|../......./..\n"
"....|\\........\\-...../...................-.............\\.\\..................................././..........\\...\n"
"....................................-..../......................-..///......-...|.|..........................|\n"
".........-\\.....-...........|........./..........-..\\.....\\./...................-........................-....\n"
"....../.......././......--.....|.\\..-...-....\\..........................-....-...-..|.|.....|.......\\-./......\n"
"...-....................-................|.............-../........|../........-.............|\\...............\n"
"...../...........-......../................|................|.....\\.....-.............../...|....../\\.........\n"
"./...\\.....\\..-./.........................|................................-....................-.............\n"
".............\\|.../....\\\\.....\\..|...........\\.....................|......|.|.....|.....-............\\.\\......\n"
"........................|......-..........-.../......-........|...../.\\|...-................................|.\n"
".......\\...-...\\..........|.....\\...................\\.........|..........-/.........\\...................../...\n"
".-|.......|............./..|./....-.../...\\............-......../..............-.......//...-...........||.\\..\n"
"..|..\\./..-........\\..|....-..\\.........../..............................|..\\..................../..|...../-..\n"
".|.........-.\\...........................\\..../......./....||............\\..........|............-.\\|.........\n"
"....................\\..../|............................\\.../..|........./...../............||........\\....../.\n"
"....................../.....|...................|......|.................|..|.......|................|........\n"
".....................\\.........-..../.........../../..-......\\.................|.../....................../...\n"
"........\\.-................/........\\...../....../.|.\\...|/../..........................................-.....\n"
"....................................|......./...../............-................-/..|.-....................\\..\n"
"..|.........................-....................../...|.....|.............../.........../.....|\\.............\n"
".......................................|.\\.|.......................-.......|..............\\............-./....\n"
"..........//................\\..|./................-.................-..../../|................................\n"
".|......................................./............/..-.......-.|.........................\\|..|............\n"
"............................/.-..................-./..../..............|-.........-|..........................\n"
".................-...|................\\.........|\\...............................\\...........\\...//...........\n"
"........\\..|.|--.............|.......\\.................|......|\\./.........................\\.|................\n"
".-|.............|\\|.....\\|././...|..\\.............\\..\\...................\\...........\\...../..................\n"
"..../..............-..|...|.........-.........\\.....-...........-.....|...\\.-....-../.................\\.......\n"
"........\\.|........\\\\.........-...............-.......-..................................../..........|.......\n"
"...............-...................\\/...............\\..-\\...........|.-........-.\\-.....\\....\\..../......-....\n"
".../-......./..............|.......|..//......-....................../.|....\\......|..\\.........../-\\.........\n"
".-....|./....-.../....../.....-..............\\..-..\\..-............\\................|...|..........-.......|..\n"
"|......../...................\\..../....\\......./..|.................\\...............\\.........\\../.|......../.\n"
"../............/........|..|.......................................\\../\\...............\\............/.......\\.\n"
"........-.-...\\........../.......-....-............./.............-......./................\\..........-.......\n"
".../-................/......|/........-......|..........|..-..............|/..........................-.......\n"
"......./............../...................|../...../................./../..........\\../.....\\....\\............\n"
"..............-..|../-........................|...\\.../...-/..........\\.......\\......\\.................-....-.\n"
"......................................-/.\\........................../......-..\\..\\........\\...............|..\\\n"
".............-.........../-|........-........\\....-.....\\....../..\\........................\\......|.......\\...\n"
".././....................|\\.../\\.........\\.|.............../..../...|......./.\\...|.......\\.........|.........\n"
"......................./........./-./...........................|/...\\........-.../.................||........\n"
"..............|./........\\..............\\.............................|/................../............|.-..|.\n"
".........................-......../........./.....|....-..-.-..............-.-......../.......\\...\\./.........\n"
".-............../../....\\//......../...|......|......\\..................-......\\.....-....\\|.........|........\n"
"..............-.....................\\.................\\.|...-............................|......\\.............\n"
"\\\\.....|...........\\............|............................../............................................\\.\n"
".-........../|...\\..............-...............................\\...........\\.....|......\\..........\\.........\n"
".\\............\\.|....-........./....../../.....-..\\........|...............-..................|............-.|\n"
".....\\......-.........-.........|....../..-....|.....\\..../....|........-.....................................\n"
"..........\\-..-..../\\.....................\\.........-...........|..../-.......................\\....-..........\n"
"...../............./..|..................../............../../.........|...............-../...................\n"
".....|...../.....|......-.............................|...........-......................./............/......\n"
".....................||./.-.................-.........\\.\\..................-..............\\...--.........\\....\n"
".|......-......-.\\.......-......\\....\\..\\..|.........../......./.....................-..........|.............\n"
".....\\.....\\............................--..................|..-........\\....\\...\\.|.\\.-...........\\...\\......\n"
"./...........\\.......\\/......|........./..|................\\-................/....\\...................\\.\\.....\n"
"..|...............................-.........-.|/......|.....|........\\........................................\n"
".......|............-............../............-......../..-...\\|-...-..../...........-..........-..-/.......\n"
"............................-..\\.......................................-.........................\\..........-.\n"
"........................\\.........|................||...-....\\......\\.....\\.................\\...\\\\....../.....\n"
"....\\../.....-.......-.................-|...................-../.|-............|........-|......./../...\\.....\n"
"..................................................\\.......|......./..\\./......../....|....-|.-................\n"
"....../.........|.......|...|.......\\.../|...............-.......-\\..\\......././..................|..\\.|...../\n"
"............|.....\\...........-.............................../.....-.................-.../............/.../..\n"
"...../.......\\............................|.....\\....\\................/..................\\......../...........\n"
"..................-....\\.........\\|................/|......../.-................|...\\......................--.\n"
"......-..-.....................................-\\.........|.../.....................|..|.-.....\\...|....\\....-\n"
"......-......-.................-......|..................................................|....................\n"
"..\\...............|......../........-......./.............../...........-..........|/.....///\\.....-..........\n"
".........../..|.............../..........\\|.........................\\...|.....\\||....\\...|.|/.....-....../....\n"
"...../...../.....-............................................|........|............|.........................\n"
"......-../\\................../..............\\............\\.................../|...........|.............\\.....\n"
"...........-..........................-....\\..\\..|.-..............................................\\........|..\n"
"/.--..//....\\...............................-............|..././..............................................\n"
"/...............|.........../..../......................\\.....|............|...........|...................-..\n"
"..-................\\../|......../...................../...........\\..|.|\\../..................................\n"
"....|...../.....-......\\.........................-.....//...............|.........-.......|...-....--.........\n"
"....|..\\.-..../....................|..........\\............./...........\\.../.................................\n"
"............................\\...................................../.......................|...........\\.......\n"
".........../.....-.....................\\..\\.-..|............-...............\\.........................-.......\n"
"......-.......-\\.\\......\\..-.-........./...........\\..........|........................\\.....-.....\\..........\n"
"..............-....../.-............./........../..............\\-....-.../...../.-............\\......./.-.....\n"
"......|...................................................||..../...|\\.....................-.../...\\........|.\n"
"......|.//........................-...../...........-..\\...|......|..................../........../...........\n"
".....................................................|.........//...........|\\.....\\....................|.../.\n"
"............-..||...........|....../....................\\...\\................................../.......|......\n"
"..\\....\\......./-\\.\\...........-\\................|.........../................||.../.....-...........\\........\n"


;

using Coord = size_t;

struct Point {
    Coord x;
    Coord y;
};
/*
bool operator==(const Point p1, const Point p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}
*/
bool operator<(const Point p1, const Point p2)
{
    if (p1.y != p2.y) {
        return (p1.y < p2.y);
    }
    return (p1.x < p2.x);
}
/*bool operator!=(const Point p1, const Point p2){
    return !(p1 == p2);
}*/
std::string pointToStr(Point p) {
    using std::literals::string_literals::operator""s;
    return "("s + std::to_string(p.x) + ", " + std::to_string(p.y) + ')';
}

enum class Direction { Up, Down, Left, Right };

} // namespace

auto day16Part2()
{
    std::stringstream inputStream{};
    inputStream << Input;

    std::vector<std::string> lines;

    Coord rowsLength{};

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

        if (lineCount == 1U) {
            rowsLength = line.size();
        } else if (rowsLength != line.size()) {
            throw std::invalid_argument(
                errorLine + "line with length different from previous ones");
        }

        if (!std::accumulate(line.cbegin(), line.cend(), true, [](bool acc, const char ch) {
                static std::string accepted = "|-\\/.";
                return acc && (accepted.find(ch) != std::string::npos);
            })) {
            throw std::invalid_argument(errorLine + "line with unexpected chars");
        }

        lines.push_back(std::move(line));
    }


    using Dir = Direction;
    using Beam = std::pair<Point, Direction>;
    using Beams = std::set<Beam>;

    const auto propagate = [&lines](const Beam& initBeam) {
        const Coord nRows = lines.size();
        const Coord nCols = lines[0].size();

        std::vector<std::string> tilesPrint;
        for (Coord i = 0U; i < nRows; ++i) {
            tilesPrint.emplace_back(nCols, '.');
        }

        const auto printTiles = [&tilesPrint]() {
            std::cout << "\n\n";
            for (const auto& tilesPrintRow : tilesPrint) {
                std::cout << tilesPrintRow << std::endl;
            }
            std::cout << "\n\n";
        };

        Beams beams;
        std::set<Point> tiles;

        beams.insert(initBeam);
        tiles.insert(initBeam.first);
        tilesPrint[initBeam.first.y][initBeam.first.x] = '#';

        std::set<Beam> beamsHistory;

        while (!beams.empty()) {
            Beams newBeams;
            for (const auto& beam : beams) {
                const auto& pos = beam.first;

                Point newPos{};

                Dir move{};

                bool splitBeam = false;
                Dir move2{};

                switch (beam.second) {
                case Dir::Up:
                    switch (lines[pos.y][pos.x]) {
                    case '.':
                    case '|':
                        move = Dir::Up;
                        break;
                    case '-':
                        move2 = Dir::Left;
                        splitBeam = true;
                        [[fallthrough]];
                    case '/':
                        move = Dir::Right;
                        break;
                    case '\\':
                        move = Dir::Left;
                        break;
                    }
                    break;
                case Dir::Down:
                    switch (lines[pos.y][pos.x]) {
                    case '.':
                    case '|':
                        move = Dir::Down;
                        break;
                    case '-':
                        move2 = Dir::Right;
                        splitBeam = true;
                        [[fallthrough]];
                    case '/':
                        move = Dir::Left;
                        break;
                    case '\\':
                        move = Dir::Right;
                        break;
                    }
                    break;
                case Dir::Left:
                    switch (lines[pos.y][pos.x]) {
                    case '.':
                    case '-':
                        move = Dir::Left;
                        break;
                    case '|':
                        move2 = Dir::Up;
                        splitBeam = true;
                        [[fallthrough]];
                    case '/':
                        move = Dir::Down;
                        break;
                    case '\\':
                        move = Dir::Up;
                        break;
                    }
                    break;
                case Dir::Right:
                    switch (lines[pos.y][pos.x]) {
                    case '.':
                    case '-':
                        move = Dir::Right;
                        break;
                    case '|':
                        move2 = Dir::Down;
                        splitBeam = true;
                        [[fallthrough]];
                    case '/':
                        move = Dir::Up;
                        break;
                    case '\\':
                        move = Dir::Down;
                        break;
                    }
                    break;
                }

                for (int i = 0; i < 2; ++i) {
                    newPos = pos;
                    bool exitBeam = false;

                    switch (move) {
                    case Dir::Up:
                        if (pos.y > 0U) {
                            newPos.y--;
                        } else {
                            exitBeam = true;
                        }
                        break;
                    case Dir::Down:
                        if (pos.y < lines.size() - 1U) {
                            newPos.y++;
                        } else {
                            exitBeam = true;
                        }
                        break;
                    case Dir::Right:
                        if (pos.x < nCols - 1U) {
                            newPos.x++;
                        } else {
                            exitBeam = true;
                        }
                        break;
                    case Dir::Left:
                        if (pos.x > 0U) {
                            newPos.x--;
                        } else {
                            exitBeam = true;
                        }
                        break;
                    }

                    if (!exitBeam) {
                        newBeams.insert(std::make_pair(newPos, move));
                        tiles.insert(newPos); // may be already present

                        if ((newPos.x >= nCols) || (newPos.y >= lines.size())) {
                            tilesPrint[newPos.y][newPos.x] = '#';
                        }

                        tilesPrint[newPos.y][newPos.x] = '#';
                    }

                    if (!splitBeam) {
                        break;
                    }
                    move = move2;
                }
            }

            auto oldSize = beamsHistory.size();
            beams = newBeams; // copied, not moved
            // beamsHistory.merge(newBeams);
            for (auto beam : newBeams) {
                beamsHistory.insert(beam);
            }

            if (beamsHistory.size() == oldSize) {
                break;
            }
        }

        // printTiles();

        {
            size_t tilesCount = 0U;

            for (const auto& tilesPrintRow : tilesPrint) {
                tilesCount += static_cast<size_t>(std::count_if(
                    tilesPrintRow.cbegin(), tilesPrintRow.cend(), [](const char ch) {
                        return (ch == '#');
                    }));
            }

            if (tilesCount != tiles.size()) {
                throw std::runtime_error("failed tiles count confirmation");
            }
        }
    
        return tiles.size();
    };

    size_t maxConfig = 0U;
    Point bestPoint{};

    for (Coord y = 0U; y < lines.size(); ++y) {
        auto newV = propagate(Beam{Point{0U, y}, Dir::Right});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = Point{0U, y};
        }
        // break;

        newV = propagate(Beam{Point{rowsLength - 1U, y}, Dir::Left});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = Point{rowsLength - 1U, y};
        }
    }

    for (Coord x = 0U; x < rowsLength; ++x) {
        auto newV = propagate(Beam{Point{x, 0U}, Dir::Down});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = Point{x, 0U};
        }

        newV = propagate(Beam{Point{x, lines.size() - 1U}, Dir::Up});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = Point{x, lines.size() - 1U};
        }
    }

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Max energized tiles " << maxConfig << std::endl;
    std::cout << "When from " << pointToStr(bestPoint) << std::endl;
    // TODO: specify direction in case of corner bestPoint.

    std::cout << "Result: " << maxConfig << std::endl;
    return maxConfig;
}

int main()
{
    try {
        day16Part2();
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
Lines count 10
Max energized tiles 51
When from (3,0)
Result: 51

real input:
Lines count 110
Max energized tiles 8444
When from (109,36)
Result: 8444
*/
