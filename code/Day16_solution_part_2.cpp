#include <array>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
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

auto day16Part2(std::string_view streamSource, bool sourceIsFilePath)
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
        std::string errorLine
            = "Input error at the line n. " + std::to_string(static_cast<int>(lineCount)) + " : ";

        auto c = static_cast<size_t>(inputStream->gcount());
        // 'c' includes the delimiter, which is replaced by '\0'.
        if (c > MaxLineLength) {
            throw std::invalid_argument(errorLine + "longer than " + std::to_string(MaxLineLength));
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
            continue;
        }

        if (lines.empty()) {
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


    using Dir = Direction;
    using Beam = std::pair<Point, Direction>;
    using Beams = std::set<Beam>;
    using Tiles = std::set<Point>;

    const Coord nRows = lines.size();
    if (nRows == 0U) {
        throw std::invalid_argument("no line");
    }
    const Coord nCols = lines[0].size();

    std::set<Point> tilesSplit;
    /*
    const auto tileSplitsVert = [&tilesSplitIsVert](const Point& tile) {
        std::optional<bool> split{std::nullopt};
        const auto it = tilesSplitIsVert.find(tile);
        if (it != tilesSplitIsVert.end()) {
            split = it->second;
            // Will include also in case on the boundary, which is not really needed,
            // but this is not a big deal.
        }
        return split;
    };
    */

    {
        Point tile{};
        for (tile.y = 0U; tile.y < nRows; ++tile.y) {
            const auto& line = lines[tile.y];
            for (tile.x = 0U; tile.x < nCols; ++tile.x) {
                /*
                if (line[tile.x] == '-') {
                    tilesSplitIsVert[tile] = false;
                }
                if (line[tile.x] == '|') {
                    tilesSplitIsVert[tile] = true;
                }
                */
                if ((line[tile.x] == '-') || (line[tile.x] == '|')) {
                    tilesSplit.insert(tile);
                }
            }
        }
    }

    constexpr size_t Two = 2U;

    /*static const auto rotateDir = [](Dir& dir, bool clockwise = true) {
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

    static const auto isVertDir = [](const Dir dir) {
        switch (dir) {
        case Dir::Down:
            [[fallthrough]];
        case Dir::Up:
            return true;
            break;
        default:
            return false;
        }
    };*/

    const auto movePoint = [nRows, nCols](Point& p, Dir d) {
        bool ok = true;
        switch (d) {
        case Dir::Down: {
            if (p.y == nCols - 1U) {
                ok = false;
            } else {
                p.y++;
            }
        } break;
        case Dir::Up:
            if (p.y == 0U) {
                ok = false;
            } else {
                p.y--;
            }
            break;
        case Dir::Right: {
            if (p.x == nRows - 1U) {
                ok = false;
            } else {
                p.x++;
            }
        } break;
        case Dir::Left:
            if (p.x == 0U) {
                ok = false;
            } else {
                p.x--;
            }
            break;
        }

        return ok;
    };

    const auto nextBeams = [&lines, &movePoint](const Beam& beam) {
        std::array<std::optional<Beam>, Two> reachedBeams;

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

        for (size_t i = 0; i < Two; ++i) {
            newPos = pos;

            if (movePoint(newPos, move)) {
                reachedBeams.at(i) = Beam{newPos, move}; // std::make_pair(newPos,move)
            }

            if (!splitBeam) {
                break;
            }
            move = move2;
        }

        return reachedBeams;
    };

    std::map<Beam, Tiles> nextTilesForBeamSplit;
    std::map<Beam, Beams> nextSplitBeamsForBeamSplit;
    Beams beamsSplittEver;

    const auto propagate = [&lines,
                            nRows,
                            nCols,
                            &tilesSplit,
                            &beamsSplittEver,
                            &nextTilesForBeamSplit,
                            &nextSplitBeamsForBeamSplit,
                            &nextBeams](const Beam& initBeam) {
        std::vector<std::string> tilesPrint;
        for (Coord i = 0U; i < nRows; ++i) {
            tilesPrint.emplace_back(nCols, '.');
        }

        Tiles tiles{initBeam.first};
        tilesPrint[initBeam.first.y][initBeam.first.x] = '#';

        Beams beamsSplitAlready{initBeam};

        static Beam dummyBeam{{nCols, nRows}, Dir{}};

        // TODO: study why the source code that just uses a history memory in each
        // single call of propagate (as in solution for part 1), ends earlier.

        // use dummyTile as initBeam is supposed to be on the boundary and
        // to come from external.
        std::map<Beam, Beam> beamsAndOrgBeamSplit{{initBeam, dummyBeam}};
        while (!beamsAndOrgBeamSplit.empty()) {
            std::map<Beam, Beam> newBeamsAndOrgBeamSplit;
            for (const auto& [beam, beamOrg] : beamsAndOrgBeamSplit) {

                const auto twoNewBeams = nextBeams(beam);

                // regardless of direction beam.second.
                const bool split = (tilesSplit.count(beam.first) > 0U);

                for (size_t i = 0; i < Two; ++i) {
                    if (twoNewBeams.at(i)) {
                        const auto& newBeam = twoNewBeams.at(i).value();
                        const auto& newPos = newBeam.first;

                        // in case of split, newBeam is considered originated by corresponding tile.
                        const auto& newBeamOrg = split ? newBeam : beamOrg;

                        bool firstTimeInThisPropagate
                            = (!split) || beamsSplitAlready.insert(newBeam).second;
                        bool firstTimeEver = (!split) || beamsSplittEver.insert(newBeam).second;

                        tiles.insert(newPos);
                        tilesPrint[newPos.y][newPos.x] = '#';
                        nextTilesForBeamSplit[beamOrg].insert(newPos);
                        // even in case of 'split', newPos is still recorded as a tile
                        // proceeding as effect of tileOrg and then the next tiles will
                        // be recorded as proceeding (in turn) from newBeamOrg.

                        // if (const auto it = tilesSplitIsVert.find(tileOrg); it !=
                        // tilesSplitIsVert.end())
                        if (split) { // means that tileOrg is in tilesSplitIsVert.
                            nextSplitBeamsForBeamSplit[beamOrg].insert(newBeam);
                        }

                        if (firstTimeInThisPropagate) { // otherwise: may avoid to repeat.
                            if (!firstTimeEver) {
                                // may reuse the information from nextTilesForBeam
                                // and nextSplitBeamsForBeamSplit.
                                // It is also possible that nextTilesForBeam and
                                // nextSplitBeamsForBeamSplit are not yet complete, but this means
                                // that some produced beams are still 'running', therefore no loss o
                                // information comes from using nextTilesForBeam and
                                // nextSplitBeamsForBeamSplit.

                                auto nextTilesCopy
                                    = nextTilesForBeamSplit[newBeamOrg]; // need a copy.
                                for (const auto& tile : nextTilesCopy) {
                                    tilesPrint[tile.y][tile.x] = '#';
                                }
                                tiles.merge(nextTilesCopy);
                                const auto& nextSplitBeams
                                    = nextSplitBeamsForBeamSplit[newBeamOrg]; // need a copy
                                for (const auto& nextBeam : nextSplitBeams) {
                                    newBeamsAndOrgBeamSplit.insert(
                                        std::make_pair(nextBeam, nextBeam));
                                }
                            } else {
                                newBeamsAndOrgBeamSplit.emplace(newBeam, newBeamOrg);
                            }
                        }
                    }
                }
            }

            beamsAndOrgBeamSplit = std::move(newBeamsAndOrgBeamSplit); // copied, not moved
        }

        // clean information for dummyBeam, otherwise next call with a different initBeam
        // will wrongly use the same tile passed starting from initBeam.
        nextTilesForBeamSplit.erase(dummyBeam);
        nextSplitBeamsForBeamSplit.erase(dummyBeam);

        return tiles.size();
    };

    size_t maxConfig = 0U;
    Point bestPoint{};

    Point p{0U,0U};
    for (; p.y < lines.size(); ++p.y) {
        p.x = 0U;
        auto newV = propagate(Beam{p, Dir::Right});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = p;
        }
        // break;

        p.x = rowsLength - 1U;
        newV = propagate(Beam{p, Dir::Left});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = p;
        }
    }

    p.x = 0U;
    for (; p.x < rowsLength; ++p.x) {
        p.y = 0U;
        auto newV = propagate(Beam{p, Dir::Down});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = p;
        }

        p.y = lines.size()-1U;
        newV = propagate(Beam{p, Dir::Up});
        if (newV > maxConfig) {
            maxConfig = newV;
            bestPoint = p;
        }
    }

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Max energized tiles " << maxConfig << std::endl;
    std::cout << "When from " << pointToStr(bestPoint) << std::endl;
    // TODO: specify direction in case of corner bestPoint.

    std::cout << "Result Day 16 p.2 : " << maxConfig << "\n\n\n";
    return maxConfig;
}

int main16p2()
{
    try {
        day16Part2(Input, false);
        // day16Part2("./16_input_file.txt",true);
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

real input:
Lines count 110
Max energized tiles 8444
When from (109,36)
*/

