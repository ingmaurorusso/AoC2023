#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace{

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

auto day14Part1(std::string_view streamSource, bool sourceIsFilePath)
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

    std::vector<std::set<Coord>> rocks;

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
            if (i >= rocks.size()) {
                rocks.emplace_back(std::set<Coord>());
            }

            const auto ch = line[i];
            switch (ch) {
            case '#':
                rocks[i].insert(lineCount); // 1-based
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
        }

        lines.push_back(std::move(line));
    }

    // slide to north and compute the result.

    for (size_t i = 0; i < lines.size(); ++i) {
        const auto& line = lines[i];

        // std::cout << line << '\n';
        for (size_t j = 0; j < line.size(); ++j) {
            const auto ch = line[j];

            if (ch == 'O') {
                auto& rocksCol = rocks[j];

                Coord rockPos = 0U; // 1-based

                // check the rock with minimum coord
                auto it = rocksCol.lower_bound(i + 1U);
                // it refers to higher (cannot even be equal)
                if (it != rocksCol.begin()) {
                    --it;
                    rockPos = *it;
                } // else: no rocks on less coord.

                const auto deltaRes = (lines.size() - rockPos);
                if (deltaRes > std::numeric_limits<Value>::max() - res) {
                    throw std::runtime_error("Need a higher-size type as Value");
                }
                res += (lines.size() - rockPos);

                // This rock will also represent a stop for other round rocks
                rocksCol.insert(rockPos + 1U); // above the previous
            }
        }
    }

    std::cout << "Number of lines " << lineCount << std::endl;
    std::cout << "Total cube rocks " << totCubeRocks << std::endl;
    std::cout << "Total round rocks " << totRoundRocks << std::endl;
    std::cout << "\nResult Day 14 p.1 : " << res << "\n\n\n";

    return res;
}

int main14p1()
{
    try {
        day14Part1(Input, false);
        // day14Part1("./14_input_file.txt",true);
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
Result: 136

Real input:
Number of lines 100
Total cube rocks 1605
Total round rocks 1991
Result: 106648
*/
