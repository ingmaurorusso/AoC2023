#include "Day01.hpp"
#include "Day02.hpp"
#include "Day03.hpp"
#include "Day04.hpp"
#include "Day05.hpp"
#include "Day06.hpp"
#include "Day07.hpp"
#include "Day08.hpp"
#include "Day09.hpp"
#include "Day10.hpp"
#include "Day11.hpp"
#include "Day12.hpp"
#include "Day13.hpp"
#include "Day14.hpp"
#include "Day15.hpp"
#include "Day16.hpp"
#include "Day17.hpp"
#include "Day18.hpp"
#include "Day19.hpp"
#include "Day20.hpp"
#include "Day21.hpp"
#include "Day22.hpp"
#include "Day23.hpp"
#include "Day24.hpp"
#include "Day25.hpp"

#include <array>
#include <exception>
#include <string>
#include <utility>

int main()
{
    try {
        std::array<std::pair<unsigned long,unsigned long>,25U> results;

        results[0U].first = day01Part1(Day01::Input, false);
        results[0U].second = day01Part2(Day01::Input, false);
        results[1U].first = day02Part1(Day02::Input, false);
        results[1U].second = day02Part2(Day02::Input, false);
        results[2U].first = day03Part1(Day03::Input, false);
        results[2U].second = day03Part2(Day03::Input, false);
        results[3U].first = day04Part1(Day04::Input, false);
        results[3U].second = day04Part2(Day04::Input, false);
        results[4U].first = day05Part1(Day05::Input, false);
        results[4U].second = day05Part2(Day05::Input, false);
        results[5U].first = day06Part1(Day06::Input, false);
        results[5U].second = day06Part2(Day06::Input, false);
        results[6U].first = day07Part1(Day07::Input, false);
        results[6U].second = day07Part2(Day07::Input, false);
        results[7U].first = day08Part1(Day08::Input, false);
        results[7U].second = day08Part2(Day08::Input, false);
        results[8U].first = day09Part1(Day09::Input, false);
        results[8U].second = day09Part2(Day09::Input, false);
        results[9U].first = day10Part1(Day10::Input, false);
        results[9U].second = day10Part2(Day10::Input, false);
        results[10U].first = day11Part1(Day11::Input, false);
        results[10U].second = day11Part2(Day11::Input, false);
        results[11U].first = day12Part1(Day12::Input, false);
        results[11U].second = day12Part2(Day12::Input, false);
        results[12U].first = day13Part1(Day13::Input, false);
        results[12U].second = day13Part2(Day13::Input, false);
        results[13U].first = day14Part1(Day14::Input, false);
        results[13U].second = day14Part2(Day14::Input, false);
        results[14U].first = day15Part1(Day15::Input, false);
        results[14U].second = day15Part2(Day15::Input, false);
        results[15U].first = day16Part1(Day16::Input, false);
        results[15U].second = day16Part2(Day16::Input, false);
        results[16U].first = day17Part1(Day17::Input, false);
        results[16U].second = day17Part2(Day17::Input, false);
        results[17U].first = day18Part1(Day18::Input, false);
        results[17U].second = day18Part2(Day18::Input, false);
        results[18U].first = day19Part1(Day19::Input, false);
        results[18U].second = day19Part2(Day19::Input, false);
        results[19U].first = day20Part1(Day20::Input, false);
        results[19U].second = day20Part2(Day20::Input, false);
        results[20U].first = day21Part1(Day21::Input, false);
        results[20U].second = day21Part2(Day21::Input, false);
        results[21U].first = day22Part1(Day22::Input, false);
        results[21U].second = day22Part2(Day22::Input, false);
        results[22U].first = day23Part1(Day23::Input, false);
        results[22U].second = day23Part2(Day23::Input, false, false);
        results[23U].first = day24Part1(Day24::Input, false);
        results[23U].second = day24Part2(Day24::Input, false);
        results[24U].first = day25Part1(Day25::Input, false);
        results[24U].second = day25Part2(Day25::Input, false);

        std::cout << "\n\n\n";
        for(const auto& res : results){
            std::cout << res.first << " ; " << res.second << '\n';
        }
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
