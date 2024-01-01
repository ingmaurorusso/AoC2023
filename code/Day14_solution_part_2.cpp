#include <algorithm>
#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace {

constexpr std::string_view Input =

false ?

"OOOO.#.O..\n"
"OO..#....#\n"
"OO..O##..O\n"
"O..#.OO...\n"
"........#.\n"
"..#....#.#\n"
"..O..#.O.O\n"
"..O.......\n"
"#....###..\n"
"#....#....\n"

:

"O..#OO..#...O..O#O.O...O##.O#..#O#...O.O.....O..........O..#...#.....O.O.O.O#..O........O...........\n"
".....O#.#O..OO.#......O.O..#...#..OO..O..###..#...O.#...#..O..O.#..#O...#O...............##O..O....#\n"
"..#...O...OO.#........O......O#O#......O.#OO....OOO..#...O....O.O.O#..#OO.##...OOO#.#.OO.#O.#....O..\n"
"..#...#..#....O...#.#O......O.....#O##.#..#.O..#.....#O.O#...#.......O.....O.##.O.O..#.....O.#.O.OOO\n"
"O....#..#.O.O..O.#.#....#.#..##O...O#..O.#.O.OOO.O.O..O..............O.#O.O....#..O.O..O..O.O.O.O.O.\n"
".O.#.#..#.OO.#O....O.O.O#O..O.O.O..O.##..O...OO#.#...O.OO.O..#..#..#.O#..#.....#OO....O.###....#O...\n"
".......#.O.......O.O####OOO..#.O#..#.O.......OOO..O....#........O##....O#O....O...#.O.##OO.O..OO...#\n"
"..O.....O.#O#O....O......O..##.#...O.#.O##.....O.#..O.........#...#.#.O#OO.....#O.....O#..##.....O..\n"
".#..O...##....O##O...#O....O..#...O...OOO..OO...OO...#..O.OO#..#.O...##.#..O..O..........O#..#O.O#..\n"
"#..#OO#.O#.#........#.........O......##....#...O....#O.....O..##..#O.OO#......O..O.O.OO...O#O.......\n"
"#........#.....O.#....O...OO..OO......###..........##O##O.#.....#....###...#.#...O...#.O#.........O.\n"
"...O.OO.....O..#...O.#.O#.OO#OO..#.#OO#......#.O.O#..#..OO..#O.O.....O.#..........##..O#.OO.....#...\n"
".O#..#.....O.#..O.....#O...#....#.O.OO....O...#.#..O......#.O...OO..#.O...O#......##O.OO...#....O.##\n"
"O#O......O.O....O.O#OO.......OOO..#..#..OO.#.##O#.....#.#O.O.........##........#O....##..#O.O#.#.O..\n"
".....O.OO.O...O..O...OO.#.......##....O..#....#.......O.O#.#.O...O.#O....##...#.O..#.#....O#........\n"
"O..#.#O...O.O..OO.....#........OO.#......O.O....O..#.O#.#.O.#....OO.O#..OO.....#.##.####.O##...O.O.#\n"
"...O..##O....#....O.O.....#......OO..#OO...#O#..O.......O.#.O.O...O.#.O......#...O...#O...#..##.O...\n"
"OOO..#.#....#..#.O.#O#......O......OO.......O..#..#.O#.....O.......#.OO.O.O.......#.O#.O............\n"
".O##O.....OO..O..O....#.O...#.#.#O.#.O#.O.#...##O..OO.O#......O.OO..#O.OO..O.O...O.O#......#...OO#..\n"
"..#.OO#..#O....O...O...#........#.O.......O#..O..#.#O.O#...O.............OO...#...O...#....O..#.O...\n"
"O..#..##O..O...O.O#.O.#..O.O.....#..O.##.##.O..#..OO...#...#.OOO......#.#.....O##.....#.OOO...O.#...\n"
"#.O#..O..#..O..#.#..#..#O#......O#.##O.........#..O.....#..O..#....##......OO#..O....##.O.....O#O.#.\n"
".O.......O.......O..O.#.#O....O.O..#.....O.#O#O.#.......##...O.#O..........O.###...#.##...O........O\n"
".......O.....O..#...##.O.#.#O...O##..O....O..O.##....#.O..#.##O.....O.#...#..OO.......#.....#O.##O..\n"
"......#O.........#..O#..#O....O.#..#.O...OO...O....###....O##O..O.O...O..#O.....O.#.......#...#..#..\n"
"#..#..#.OO##....O.###.#.....#O#.O....O.#.O......O....#.O..OO....#...O#.O#.....O#O..#.O..OO...OOO.O.#\n"
".#....O.......#O..##.#OO#....OO#....#..OO..#.....O.O.OO.O#OO##...O#..#..#..OO..OO.#..O..........O..#\n"
".O...O#..OO.O..O.#.O..##.O...O.O.....#O.....O.O#..OO...#.O....#O..#...##..#.#...O.O..OO#O...O..#...O\n"
"#O.##...O...OO.##.O.....O.......##..#.###...#.O..#.....#O.#....O......#.O#.#.O...O.....OOO.O.....O#O\n"
"...O.#....#....#..OO...#...##..O.O.O......O.#..O..OO....O...#..OO......O.#.O.OOOO...O.#OOOOO.OO#.#..\n"
".......O#.O#.O..O.#.O..#.OO.O..#.#.##.....O.#.O##...##..O...O...O.O.......#O.#......#......O.......#\n"
"...#..#O.......#O...O..OO....OOOO......OO...#....O............#.........#O...#.#.......OO.....O..#O.\n"
"O...OO###.....O.OO......#O.O...O..#..##..O..O...O#.#......O#O.O.OO.#O..#O.O.#.O##O.O.O..#..O........\n"
".O.O.O..#.O...#.##O..#OO###.O..O..#...O..#O........O#O.#.##..O.O....O...#...O.O#...OO.....OO.......#\n"
"O.O..O...#O#...#.#....#......OO..O#...O..OOO..O..O.....#...#...O.......#.....#O..O.....O#..O.O...O.#\n"
"...##..OOO..OO#.O#OOO.#......O...O.......##........OO..O.#....O....##..##O#...#.#..O.#O........#.O..\n"
".......##O#........O......O......#.............O..O..#.O....#.#OO##...#O...O.O.O#.#......##..O.##O#.\n"
"OO.OO##.O...O#..O..O#...#.###....##.O...O.OO.#..#.O.#...#...##...#.....O..O..O.O.#..#..O....#....##.\n"
"O.#...##...#.#OO..##...#......O.OO.#O#O......OO...O#OOO...#...O.............OO.O.O.#..#O......#.O.#.\n"
".O.O.....O....#.......O......#O.O..##.O#...O....#O....O..#.OO..O#.O.#.....O.O##...........O#..#O...#\n"
"....#OO....#..###..O.O#O......##.#.#.O#O.#.##........##.O...#.OO.......O......O.....#.#O.#.O..#...O#\n"
".....O..#..#...#.###.##....#O.O.O..O....OOO.##...O##..O.#...##..#..O......##....#.O....#O........#.#\n"
"...#OO#......O...O#.#..........OOO...#.##O.O..##..#.#.O......O#.....OO......O.#O..###..O...OOO..O..O\n"
".#.O.#.O.O.O.O.#..OO.O...OO...O..O........OO.........#.....##.....O#..#...#.#.#.O...O.......O#...OO.\n"
".....OO.O....O....O.#..##OO...#O#.......O....#....O.O..........O##.#...O..O.#..#..O....OO...#.......\n"
"....##...O.#.....##O...##.....O..O...#.##.O##...O....O..O...##.....O....#.OO...O..OO#.O....OO......O\n"
".O....#.....O.#O.#OO.O.##..O.....O..O...#.##.O##...O...O#OO#.O.OO...O.O.#O#....#.O#.O...O....O......\n"
"..O#O#.#.#.#....##.#O.O.O....#.##O..#O..O..O....O.....O.O..#...OO#O...#OO...#O..O...OO#O#...#..#....\n"
".#O......O.O.O#..OO.OOO.#......O...#.O......OOO#....O.#..O.......O.......#.....#....#O.....O#O....O.\n"
".....O..O..O#........#............O....O#OO.O..O.#O..O.OO...OO....O.#.O..#.OO.......O.O.OO..OO.##O..\n"
"..O#O......#.............#..#.O.O.........O.#OO.OO..##.O#O........#.....O..OO...O.##.##.O.O#....OO.O\n"
"O..#..#....#.....#O.O..O.O..O.#.O.O.#OO..O##O..#.#.O...O....OOO.O.#...........#...#...#O...#O.#.O...\n"
"OO.....O#..#.#...#...#...##..O...O.....#O..O#O..OO.....##.#.#.OO.....O##O.....#O.O.#.#...OO...O#.#..\n"
"....#...O#..O.OO#........O..#..O....#.O.....OO#..#....O..OO.........O..#..#...O...OO.......O.......#\n"
"##.O#.........O#.OO..O..#.OO.#O.....O#O...O......#O#.O..O.....#.#O.#O.O#......OO.O........O.....#...\n"
".#.O.OO....O#O..#..O.#.#O....OO...O#..#.O.##..#..O.#O#O..O.......O..#.O#.#.##...O.OO.O#O.#..#.#..O..\n"
"...O#.......O#......O#........O..O..#..O#.O...O#..#...O......#...#.#O....O..#.#....OOO.O.......O....\n"
"..O....#.....O.##..O..##O....#O..O.###.....O#..OOO..##........#O.O..O.....#......#O#.........#OO..#.\n"
"#.##...#.#...#.....#O.O.#..##.O..O.O.....#.#OO.........O.#...O....#......##.#.OOOO.O.OO...O.OO.O....\n"
"..#....#...OO..#O.....#..#O..##....#......#O.#..O.#OO.......OO.O....#.......OO..#.#..OO...O.....#OO.\n"
"O.....O.#.....#..#.O#......#O#...#....O......O#O.O#.O....#.OO##........O...O#..O#.OOOO.#O#O..##....#\n"
".O........OO.#.....O#O..OO.O#O#..O.......#.O..##.#.#.....#.OOOO...O..OOO.OO#....O....#....O.#....OOO\n"
".O#O.O.......O#O...O.#O...O.OO#O..O.#..#O...O.O.#.#OO....##..##..#......#..O#......#O.O.O#O#.#...#..\n"
"..O..O#.#..O#.O..OOOO...O..OOO#O......##.O..O..O..OO#O.#....O.......#..O#.O..O..#..O...OO.....##O#..\n"
"...OOO..O........OOO....#..#.O.O..##.O.O..#....O........#...##O#O..O.#OO.#...#..#O#......O.O....O...\n"
".#O#.#.#.O.#..#.O..O.....O.O..O.#.O#........#....##.O#O..#..#O#.#..O#O#.#.#..#......O...O#.O.....#..\n"
".#..O.#OO.#..#O...O...O..#O...#...O#..O.............#.....O.#O....#..#...#.#...OO.O.OOO.O....##O#O.#\n"
"OO..O...O....##...#.O...#.#....O.#....O..O##..O.......#O.#...O..##...OO.O#O.....OO...#....#.......O.\n"
".#O.O....#.#O........#.#..O....O.......#..O#.....O..O.O..##..O.O.O...O..O...OO......O.OO...#.#....OO\n"
".#.O..#O.....OO..O..#.O#.O.OO.#....#O....#.OO.....O.OO..#.O.O..OO.....O..##..O..#.#..O......O..OO..O\n"
".O.......OO#.#.O.OO..#OO.OO..#O..O##O..#......#.#O.O.#O..#.O.#..#O.OOO..OO...#.#.#.#.OO.O...#O##O...\n"
"O#...O.O.O........O#..OO.#.#.....#..O##....#.#...OO##..#..O..#..O.OO.O.O.......O.O#........OO.##O...\n"
".#.O.#.#...#.O..O##....#.O.#.O#O........#..#.#....O.....#..O#.##...#....#.##.#O.O#O.O..OO##.#..O#O..\n"
"O...##..#..#OO#.OO.#...##..O...#.O.O#.#....#O.O##....O........OO#O..O..#.......O.#OOOO........#O...#\n"
"O...#...#.O...#....O#O#......O#.OO#..#....#.#O...O#...OO##...O#.OO....####.......#.......O.........#\n"
"#O..OO.OO....#.....#....#O.#..OO.#....##.....#...OO.O#O......O.O.O........##..O..O....#..O..O#.O....\n"
"#O#.OOO.#O#.#.....#O.O....O.#.....OO...##....##O.#....O.O.#O.##O..#O#.O....O...O.#O.#.OO..#...OO..O.\n"
"....O.........O.O.....#.#...O.O....O..#.#...#..#..#..OO..OO.#..O..O....O........O#.O.O.O#.....#O.O.#\n"
"#...#O...#OOO...#..O.#..O..O...#.....OO#...##....#.##.##O.OOOO.#O.#...OO##.OO....#...OOO..###...O.##\n"
"..........#...#.#.....#O...O#OO....OO#...#..##..O..O...#.#.#..#.......#...OO....#O.......O..O....O.O\n"
"..O......#..OO..O#O.......#O...OO......#..O..OO..#.#O#OO..#.......OO#OO.O...#..O...O..##..OOOO.#...O\n"
"..OO.O#.#....O#O#O#..O....##..O.O#.O.O..O...O....O...#..O...#O.O..O#.#O..........O.........O..O.O.#.\n"
"...#....O#.#.#..OO....O.#.......#O#....OOOO.#O#O.O##.OO.#.#O##.....O.#OO#....O...#..OO#.O..........O\n"
".#......#O#.#.....O...OO..O.#.......OO..O.O...O.O.#O....#....O..OO.O#.....##.#....O.O....#.#O.O#.###\n"
"...##O.....#O......O.......O.O.....#.O...O.O....OO..#O...O......#......O...#....O...#.O.....O#.#..OO\n"
"O..#.....#O..........#..OO........OOO.O..O#O#...#OO....O.#...OO..O..#....O.O.#.O#........#O.#.#...#O\n"
"O...#..OOOO...#.....#........##..OOO#OO#..#..#.#.O.#.O.O......O.....#.#O#..##....O.#O#O.O.#...O.....\n"
".O.#.O....O.OOO..##.....O#.OO........................O..O..#.OOO......#OOO......#...OO........#..OOO\n"
".###...O##..#.O#..O#..#.O#.#.O..O.##..O...#.O..O.#.#.....OO..O.#O.O....OO.O.O..#....#O.OO#.O..O.....\n"
".......O.O.....O.....O#.....O.....OO#.O..#...O..O..##.O..OO.O....#O......###..#...O........#....O.OO\n"
"O..O..O...O.O.O.O.O.O...OO........OO..OO..O.#O.#.O....#..OOO.O.#...OO.#...O......OO.OO#.#...O#...##.\n"
"O#O.##...O#.#..O.#.O..#..#....#..O##...##....OO.#..##OO....##......O....#OO.O...#OO..OO#...O.OO.#.#.\n"
"..O.#OOO....O....#....#..O#O..O..O...O...O.........#..#.#O..#.#...OO.....##.O.......O#..O#.#...OO...\n"
".O.O.O.O..O.##...#..........O.O..............#....#.#O...OO.#..OO...#....O.O..#.......O.#..#..##.O##\n"
"..OO.#.....O..O.OO.#.##.O....#...#O....##..O#.O.....O.....#....OO#....##..#O..OO...#O#O#....#.O.O.O#\n"
"..O.#O....O.#..#.#.OO.##..OO......#...#....#O...OO....#.O..#.OO#.......O.#.#......O#O...#..OO.....##\n"
"#.........O....#..#O.....##....#O......##..O....OO.....O.....#..#O...O...O..#.OOO.O..#......#.....#.\n"
"O.##.O.#OO...#..#O.OO.....#.#.....O..##.O.#......#O##......OO..O..O.O.....#..O.O.#..O......O.OO.##..\n"
"....O....O#.##..O.O.O..#..##O#......O#.....O......O.#....O......#O.O..#..O..O..##..#O##..........O..\n"
"O#..##O..#...OO...#.OO....#..O.....O.......OOO#...##...OO.##....#O..#..#O.#.O#O..O...O.#..O.#O.O#...\n"
;

} // namespace

auto day14Part2(std::string_view streamSource, bool sourceIsFilePath)
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

    using Coord = size_t;

    std::string errorLine;

    std::vector<std::string> lines;
    Coord rowsLength{};

    std::vector<std::set<Coord>> cubeRocksCol;
    // std::vector<std::set<Coord>> cubeRocksRow; never needed

    using Value = size_t;
    Value res = 0U;

    unsigned lineCount{0U};

    Coord totCubeRocks = 0U;
    Coord totRoundRocks = 0U;

    constexpr auto MaxLineLength = 1000;
    std::array<char, MaxLineLength + 1> cc{};
    while (inputStream->getline(cc.data(), MaxLineLength, '\n')) {
        ++lineCount;

        errorLine = "Input error at the line n. " + std::to_string(static_cast<int>(lineCount))
            + " : ";

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
        } else if (line.size() != rowsLength) {
            throw std::invalid_argument(errorLine + "line with different length");
        }

        for (size_t i = 0; i < line.size(); ++i) {
            // cubeRocksRow.push_back(std::set<Coord>()); never needed
            if (i >= cubeRocksCol.size()) { // <-> when lineCount==1U
                cubeRocksCol.emplace_back(std::set<Coord>());
            }

            const auto ch = line[i];
            switch (ch) {
            case '#':
                cubeRocksCol[i].insert(lineCount); // 1-based
                ++totCubeRocks;
                break;
            case 'O':
                ++totRoundRocks;
                [[fallthrough]];
            case '.':
                break;
            default:
                throw std::invalid_argument(
                    errorLine + "contains unexpected char " + std::string(1U, ch));
            }

            // cubeRocksRow[lineCount-1U].insert(i+1U); // 1-based
            // never needed
        }

        lines.push_back(std::move(line));
    }

    constexpr auto NumIterations = 1000000000UL;

    using Iter = std::remove_cv_t<decltype(NumIterations)>;

    // TODO: prepare a way to translate 'lines' into a unique key-integer
    // and use it, also with hash==value.
    std::map<std::vector<std::string>, Iter> firstAndSecondTimeConfig;

    Iter firstTimeRepeat = 0U;
    Iter secondTimeRepeat = 0U;

    /*
    std::cout << "\n\nstarting:\n";
    for (const auto& line : lines) {
        std::cout << line << '\n';
    }
    */

    for (Iter iter = 0; iter < NumIterations; ++iter) {

        // move north
        std::vector<std::string> newLines = lines;
        std::vector<std::set<Coord>> newColRocks = cubeRocksCol;

        // 'i' variable is needed during the loop.
        // NOLINTNEXTLINE(modernize-loop-convert)
        for (size_t i = 0; i < lines.size(); ++i) {
            const auto& line = lines[i];
            auto& newLine = newLines[i];

            // std::cout << line << '\n';
            for (size_t j = 0; j < line.size(); ++j) {
                const auto ch = line[j];

                if (ch == 'O') {
                    auto& rocksCol = newColRocks[j];

                    Coord rockPos = 0U; // 1-based

                    // check the rock with minimum coord
                    auto it = rocksCol.lower_bound(i + 1U);
                    // it refers to higher (cannot even be equal)
                    if (it != rocksCol.begin()) {
                        --it;
                        rockPos = *it;
                    } // else: no rocks on less coord.

                    // rockPos is the 1-based position of another rock,
                    // hence it willl be the 0-based position of the round rock.

                    // This rock will also represent a stop for other round rocks
                    rocksCol.insert(rockPos + 1U); // 1-based

                    if (rockPos < i) {
                        newLine[j] = '.'; // space left

                        // lines[rockPos] already scrolled
                        newLines[rockPos][j] = 'O';
                    }
                } /*
                else{
                    // newLines[i][j] = ch; already so
                }*/
            }
        }

        lines = std::move(newLines);

        /*
        std::cout << "\n\nafter moving to north:\n";
        for (const auto& line : lines) {
            std::cout << line << '\n';
        }
        */

        // now move west
        // directly modify 'lines' as it is hoirizontal move

        // 'i' variable is needed during the loop.
        // NOLINTNEXTLINE(modernize-loop-convert)
        for (size_t i = 0; i < lines.size(); ++i) {
            auto& line = lines[i];

            // std::cout << line << '\n';

            Coord lastRockPos = 0U; // 1-based
            for (size_t j = 0; j < line.size(); ++j) {
                const auto ch = line[j];

                switch (ch) {
                case 'O':
                    line[lastRockPos] = 'O';
                    ++lastRockPos;
                    break;
                case '#':
                    while (lastRockPos < j) {
                        line[lastRockPos++] = '.';
                    }
                    line[lastRockPos] = '#'; // TODO: likely useless.
                    ++lastRockPos;
                    break;
                default:
                    line[lastRockPos] = '.'; // TODO: likely useless.
                }
            }

            while (lastRockPos < line.size()) {
                line[lastRockPos++] = '.';
            }
        }

        /*
        std::cout << "\n\nafter moving to west:\n";
        for (const auto& line : lines) {
            std::cout << line << '\n';
        }
        */

        // now move south
        newLines = lines;
        newColRocks = cubeRocksCol;

        for (size_t i = lines.size(); i > 0U;) {
            --i;

            const auto& line = lines[i];
            auto& newLine = newLines[i];

            // std::cout << line << '\n';
            for (size_t j = 0; j < line.size(); ++j) {
                const auto ch = line[j];

                if (ch == 'O') {
                    auto& rocksCol = newColRocks[j];

                    Coord rockPos = lines.size(); // 0-based

                    // check the rock with minimum higher coord
                    auto it = rocksCol.lower_bound(i + 1U);
                    // it refers to higher (cannot even be equal)
                    if (it != rocksCol.end()) {
                        rockPos = *it - 1U; // from 1-based to 0-based
                    } // else: no rocks on higher coord.

                    // rockPos is the 0-based position of another rock,
                    // hence it has to be reduced to become the 0-based position
                    // of the round rock.

                    // This rock will also represent a stop for other round rocks
                    rocksCol.insert(rockPos); // 1-based

                    --rockPos;

                    if (rockPos > i) {
                        newLine[j] = '.'; // space left

                        // lines[rockPos] already scrolled
                        newLines[rockPos][j] = 'O';
                    }
                } /*
                else{
                    // newLines[i][j] = ch; already so
                } */
            }
        }

        lines = std::move(newLines);

        /*
        std::cout << "\n\nafter moving south:\n";
        for (const auto& line : lines) {
            std::cout << line << '\n';
        }
        */

        // now move east
        // directly modify 'lines' as it is hoirizontal move

        // 'i' variable is needed during the loop.
        // NOLINTNEXTLINE(modernize-loop-convert)
        for (size_t i = 0; i < lines.size(); ++i) {
            auto& line = lines[i];

            // std::cout << line << '\n';

            Coord lastRockPos = line.size(); // 0-based
            for (size_t j = line.size(); j > 0U;) {
                --j;

                const auto ch = line[j];

                switch (ch) {
                case 'O':
                    line[--lastRockPos] = 'O';
                    break;
                case '#':
                    while (j < --lastRockPos) {
                        line[lastRockPos] = '.';
                    }
                    // line[lastRockPos] = '#'; useless
                    break;
                default:
                    // line[lastRockPos-1U] = '.'; useless
                    ;
                }
            }

            while (lastRockPos > 0U) {
                line[--lastRockPos] = '.';
            }
        }

        /*
        std::cout << "\n\nafter move east: full cycle:\n";
        for (const auto& line : lines) {
            std::cout << line << '\n';
        }
        */

        /*
        { // self-check 'O' and '#' numbers
            unsigned cube = 0U;
            unsigned round = 0U;

            for (const auto& line : lines)
                for (auto ch : line)
                    switch (ch) {
                    case '#':
                        ++cube;
                        break;
                    case 'O':
                        ++cube;
                        break;
                    case '.':
                        break;
                    default:
                        throw std::runtime_error("unexpected");
                    }

            static unsigned savedCube = cube;
            static unsigned savedRound = round;

            if ((cube != savedCube) || (round != savedRound)) {
                throw std::runtime_error("different");
            }
        }
        */

        const auto [it, isFirstTime]
            = firstAndSecondTimeConfig.insert(std::make_pair(lines, iter + 1U));

        if (!isFirstTime) {
            const auto& firstTime = it->second;

            const auto secondTime = iter + 1U;

            if (((NumIterations - secondTime) % (secondTime - firstTime)) == 0U) {
                firstTimeRepeat = firstTime;
                secondTimeRepeat = secondTime;
                break; // solution found
            }
            // else: the element might be removed from map but by then
            // the memory does not increase anymore.
        }
    }

    /*
    std::cout << "\n\nfinal lines:\n";
    for (const auto& line : lines) {
        std::cout << line << '\n';
    }
    */

    // finally compute north load without considering rolling.

    // 'i' variable is needed during the loop.
    // NOLINTNEXTLINE(modernize-loop-convert)
    for (size_t i = 0; i < lines.size(); ++i) {
        const auto& line = lines[i];

        // std::cout << line << '\n';
        const auto contribute = (lines.size() - i);

        const auto roundCount =
        static_cast<Value>(std::count_if(
            line.cbegin(), line.cend(), [](const char ch) {
                return (ch == 'O');
            }));

        const auto deltaRes = (contribute * roundCount);
        if (deltaRes > std::numeric_limits<Value>::max() - res) {
            throw std::runtime_error("Need a higher-size type as Value");
        }
        res += deltaRes;
    }

    std::cout << "Number of lines " << lineCount << std::endl;
    std::cout << "Total cube rocks " << totCubeRocks << std::endl;
    std::cout << "Total round rocks " << totRoundRocks << std::endl;
    std::cout << "firstTimeRepeat " << firstTimeRepeat << std::endl;
    std::cout << "secondTimeRepeat " << secondTimeRepeat << std::endl;
    std::cout << "\nResult: " << res << "\n\n\n";
    return res;
}

int main14p2()
{
    try {
        day14Part2(Input, false);
        // day14Part2("./14_input_file.txt",true);
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
Number of lines 10
Total cube rocks 17
Total round rocks 18
firstTimeRepeat 6
secondTimeRepeat 13
Result: 64

Real input:
Number of lines 100
Total cube rocks 1605
Total round rocks 1991
firstTimeRepeat 136
secondTimeRepeat 172
Result: 87700
*/
