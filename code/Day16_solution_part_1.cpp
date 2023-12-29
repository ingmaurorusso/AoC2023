#include <array>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
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
/*bool operator==(const Point p1, const Point p2){
    return (p1.x == p2.x) && (p1.y == p2.y);
}*/
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

enum class Direction { Up, Down, Left, Right };

} // namespace

auto day16Part1(std::string_view streamSource, bool sourceIsFilePath)
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

    std::vector<std::string> lines;

    Coord rowsLength{};

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

        // std::stringstream lineStream;
        // lineStream << line;

        if (lineCount == 1U) {
            rowsLength = line.size();
        } else if (rowsLength != line.size()) {
            throw std::invalid_argument(
                errorLine + "line with length different from previous ones");
        }

        if (std::find_if_not(
                line.cbegin(),
                line.cend(),
                [](const char ch) {
                    static const std::string accepted = "|-\\/.";
                    return (accepted.find(ch) != std::string::npos);
                })
            != line.cend()) {
            throw std::invalid_argument(errorLine + "line with unexpected chars");
        }

        lines.push_back(std::move(line));
    }

    const Coord nRows = lines.size();
    const Coord nCols = rowsLength;

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

    using Dir = Direction;
    using Beam = std::pair<Point, Direction>;
    using Beams = std::set<Beam>;
    Beams beams;
    std::set<Point> tiles;

    if (nRows > 0U) {
        beams.insert(std::make_pair(Point{0, 0}, Dir::Right));
        tiles.insert(Point{0, 0});
        tilesPrint[0][0] = '#';
    }

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
                    if (pos.y < nRows - 1U) {
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

                    if ((newPos.x >= nCols) || (newPos.y >= nRows)) {
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
        beams.clear();
        // beamsHistory.merge(newBeams);
        for (auto& newBeam : newBeams) {
            if (beamsHistory.insert(newBeam).second) {
                // the new one is also inserted in 'beams'
                beams.emplace(std::move(newBeam));
            }
        }

        if (beamsHistory.size() == oldSize) {
            break;
        }
    }

    // printTiles();

    {
        size_t tilesCount = 0U;

        for (const auto& tilesPrintRow : tilesPrint) {
            tilesCount += static_cast<size_t>(
                std::count_if(tilesPrintRow.cbegin(), tilesPrintRow.cend(), [](const char ch) {
                    return (ch == '#');
                }));
        }

        if (tilesCount != tiles.size()) {
            throw std::runtime_error("failed tiles count confirmation");
        }
    }

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Result: " << tiles.size() << std::endl;

    return tiles.size();
}

int main()
{
    try {
        day16Part1(Input, false);
        // day16Part1("./16_input_file.txt",true);
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
Lines count 10
Result: 46

Real input:
Lines count 110
Result: 8249
*/

