#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace{

constexpr std::string_view Input =

false ?

"#.##..##.\n"
"..#.##.#.\n"
"##......#\n"
"##......#\n"
"..#.##.#.\n"
"..##..##.\n"
"#.#.##.#.\n"
"\n"
"#...##..#\n"
"#....#..#\n"
"..##..###\n"
"#####.##.\n"
"#####.##.\n"
"..##..###\n"
"#....#..#\n"
"\n"

:

".####..#.#.#.##..\n"
"........#..##....\n"
"..##..#.....#..##\n"
"......##.##.#####\n"
"######.#.####....\n"
"..##....#..##.#..\n"
".#..#..#####.#...\n"
"..##...#..#...#.#\n"
"#######.#....####\n"
"\n"
"#.###..####\n"
"..#####....\n"
"#.##...####\n"
"##..#.##..#\n"
"##.#.##.##.\n"
"##.#.##.##.\n"
"##..#.##..#\n"
"#.##...####\n"
"..###.#....\n"
"#.###..####\n"
".##....#..#\n"
"\n"
".##...#...#####\n"
"...######..#.#.\n"
"..#.#..#.####..\n"
"#..#...##.##..#\n"
"#..#...##.##..#\n"
"..#.#..#.####..\n"
"#..######..#.#.\n"
".##...#...#####\n"
"#..#..#.#...#.#\n"
"####.#####..#..\n"
"....#.##..##...\n"
"#..######..#.##\n"
"##.#...#..##.#.\n"
"##.#...#..##.#.\n"
"#..######..#.##\n"
"....#.##..##...\n"
"####.#####..#..\n"
"\n"
"#####..#####.##\n"
".............##\n"
"#..######..##..\n"
".##.#..#.##.#.#\n"
"....####....##.\n"
"#..##..##..###.\n"
"#.########.#.#.\n"
".##..##..##...#\n"
"#..##..##..##..\n"
"####....####..#\n"
"....####....#..\n"
"\n"
"...#....##...\n"
".#.##....#...\n"
"#..##.####.#.\n"
"#.#####.##.#.\n"
"##...#.##.#.#\n"
"##...#.##.#.#\n"
"#.#####.##.#.\n"
"#..##.####.#.\n"
".#.##....#...\n"
"...#....##...\n"
"...#....##...\n"
".#.##....#...\n"
"#..##.####.#.\n"
"#.###.#.##.#.\n"
"##...#.##.#.#\n"
"\n"
"####.##.#..#.#...\n"
"....##.####.#.#..\n"
"....##.####.#.#..\n"
"####.##.#..#.#...\n"
"..#####...####.##\n"
"#####..##.###...#\n"
".##...##.....###.\n"
".##...##.....###.\n"
"#####..##.###...#\n"
"..#####...####.##\n"
"#.##.##.#..#.#...\n"
"\n"
"#.##########.\n"
"##.#..##..#.#\n"
"..#.##..##.#.\n"
"#...#....#...\n"
"##.#......#.#\n"
"#.#.#....#.#.\n"
"###...##...##\n"
"###...##...##\n"
"#.#.#....#.#.\n"
"##.#......#.#\n"
"....#....#...\n"
"\n"
"....##....##.....\n"
".####.####.####..\n"
"###....##....###.\n"
"###....##....###.\n"
".####.####.####..\n"
"....##....##.....\n"
"..##..#..#..##..#\n"
".###############.\n"
".##.#..##..#.##..\n"
"\n"
"####.#..#.####..#\n"
"####..##..#######\n"
"#.#.#.##.#.#.####\n"
"##.#..##..#.##..#\n"
".#####...####....\n"
".###.#..#.###....\n"
".##..#..#..##....\n"
"..#.######.#..##.\n"
"#..#......#..#..#\n"
"######..######..#\n"
"#.##..##..##.####\n"
"..##.####.##..##.\n"
"...##.##.##...##.\n"
"..#.#....#.#..##.\n"
".##..#..#..##.##.\n"
"#####....########\n"
"##..##..##..#####\n"
"\n"
"..###.#..#.##\n"
"#####.####.##\n"
"...##.#..#.##\n"
"...##.####.##\n"
"###.#......#.\n"
"###..######..\n"
"###..........\n"
"..##..##.#..#\n"
"...###.##.###\n"
"\n"
"##...####...###\n"
"##...####...###\n"
"#....#..#....##\n"
"##..........###\n"
"#.##########.#.\n"
"..#..#..#.##...\n"
".#...####...#.#\n"
"#..#.####.#..#.\n"
".##..####..##.#\n"
"###..####..###.\n"
"#..##.##.##..#.\n"
"#.#........#.#.\n"
"#.....##.....#.\n"
"\n"
"#..#####.#.\n"
".#.#...####\n"
".##.#####.#\n"
"#...###.#.#\n"
"#..####.#.#\n"
".##.#####.#\n"
".#.#...####\n"
"#..#####.#.\n"
"####..#..##\n"
"####....##.\n"
"####....##.\n"
"####..#..##\n"
"#..#####.#.\n"
".#.#...####\n"
".##.#####.#\n"
"\n"
".######.####...\n"
"..#..#....##...\n"
"..#..#....##...\n"
".######.####...\n"
"###..######.##.\n"
".........#..###\n"
"..#####.#.#####\n"
"#.#..#.##.....#\n"
".##..##....####\n"
"...##...##..#..\n"
".#....#.#.#..##\n"
"...##....#####.\n"
".#.##.#.###.###\n"
"\n"
"###.#...#.#.##.#.\n"
"#.#...####...#..#\n"
"#.#...####...#..#\n"
"###.#...#.#.##.#.\n"
"..####..#####....\n"
".....###...#..###\n"
".....###...#..###\n"
"..####..#####....\n"
"###.#...#.#.##.##\n"
"\n"
"##.#..##.##.#\n"
".#...........\n"
".#####...##..\n"
"##.#...#.##.#\n"
"...#.###.##.#\n"
".##..#..#..#.\n"
"#.##..#......\n"
"#..###..#..#.\n"
"#.#.##.......\n"
"...#.###.##.#\n"
".#.###.#....#\n"
"##..#....##..\n"
"#..##########\n"
"##.##########\n"
"##..#....##..\n"
".#.###.#....#\n"
"...#.###.##.#\n"
"\n"
"##.######.##.\n"
"...#....#..##\n"
"####....#####\n"
"...#.##.#....\n"
"###..##..###.\n"
"#..######..##\n"
"..#.#..#.#..#\n"
"#.##.##.##.##\n"
"...##..##....\n"
"##...##...###\n"
"##...##...###\n"
"...##..##....\n"
"#.##.##.##.##\n"
"..#.#..#.#..#\n"
"#..######..##\n"
"###..##..###.\n"
"...#.##.#....\n"
"\n"
"####..#.#####\n"
"#..#...##.##.\n"
".##.##.######\n"
"#..#...#.....\n"
"#..#.##..####\n"
"###.#..#.....\n"
"#..###..#....\n"
"#..#......##.\n"
"####..##..##.\n"
"\n"
"###......\n"
"..#.##..#\n"
"...######\n"
"...###...\n"
"###.#####\n"
"#..##....\n"
"#..##....\n"
"###.#####\n"
"...###...\n"
"\n"
"..##..#########\n"
"####.....#.#.#.\n"
"###.#..####.###\n"
".#..##..####.#.\n"
"#.#.##.##......\n"
"....####..#..##\n"
"###.##..##.....\n"
".#..##....###.#\n"
".#..##....###.#\n"
"###.##..##.....\n"
"....####..#..##\n"
"#.#.##.##......\n"
".#..##..####.#.\n"
"###.#..####.###\n"
"####....##.#.#.\n"
"..##..#########\n"
"..##..#########\n"
"\n"
"......#.##.#.\n"
"#....#......#\n"
"##..###....##\n"
".#..#..#..#..\n"
"#....########\n"
".#..#...##...\n"
".#..#.##..##.\n"
"##..#########\n"
"..##........#\n"
"######......#\n"
".####...##...\n"
".#..#...##...\n"
"#....#......#\n"
"..##..#....#.\n"
"##..###....##\n"
"\n"
".###.###.\n"
"#.#..####\n"
"###.##.#.\n"
"###.##.##\n"
"#.#..####\n"
".###.###.\n"
".###.###.\n"
"#.#..####\n"
"###.##.##\n"
"###.##.#.\n"
"#.#..####\n"
".###.###.\n"
"#...#.#.#\n"
"\n"
".#....#..\n"
".##...#..\n"
".###.##..\n"
"#.##.#...\n"
".####..##\n"
"#.#.#.###\n"
"..#...#..\n"
"##...#...\n"
"##..####.\n"
"##..####.\n"
"##...#...\n"
"..#...#..\n"
"#.#.#.###\n"
".####..##\n"
"#.##.#...\n"
".###.##..\n"
".##...#..\n"
"\n"
"#..##....##..\n"
".##.#.##....#\n"
"#..#.#..#..#.\n"
"#####....##..\n"
"....##.##...#\n"
"#..#...######\n"
"#..####.#..#.\n"
".##.###..##..\n"
"....###......\n"
".##..#..####.\n"
"#..###.#.##.#\n"
".......######\n"
".....####..##\n"
"\n"
"####.#..##.##\n"
".##.########.\n"
".##.#.#..##.#\n"
"....#.#.#.###\n"
".##..#.##.###\n"
"#..##..###.##\n"
"#####.###....\n"
"######.#.#..#\n"
".##....###...\n"
".........##.#\n"
"#####.##.#...\n"
"#..###.##.##.\n"
"....###.#..##\n"
"######.#..#.#\n"
"#..#.#.#..###\n"
"#..#.#.#..#.#\n"
"######.#..#.#\n"
"\n"
".#.#.####\n"
".###.#..#\n"
"#..#.....\n"
"..#...##.\n"
"..#.##..#\n"
".#.#.....\n"
"...#.####\n"
"###......\n"
"...###..#\n"
"...###..#\n"
".##......\n"
"\n"
"#....####..\n"
".##.##..###\n"
".....####..\n"
".#..#...#.#\n"
"..#...#..#.\n"
"####.#.##..\n"
"####.#.##..\n"
"..#...#..#.\n"
".#..#...#.#\n"
".....####..\n"
".##.##..###\n"
"#....####..\n"
".....####..\n"
"\n"
".#..#..#.\n"
"#.#.####.\n"
".#.######\n"
"#..######\n"
"####.##.#\n"
"####.##.#\n"
"....#..#.\n"
"..##....#\n"
"###......\n"
"###......\n"
"..##....#\n"
"....#..#.\n"
".###.##.#\n"
"\n"
".#.##...#..##\n"
"#.#.#.#...#.#\n"
".##.....##.#.\n"
".##..##..####\n"
"...#.#####.##\n"
"#.#####..#...\n"
"#.#####..#...\n"
".#.#.#####.##\n"
".##..##..####\n"
".##.....##.#.\n"
"#.#.#.#...#.#\n"
".#.##...#..##\n"
".#.##...#..##\n"
"\n"
"####...##.#..##..\n"
"#######........##\n"
"..#..##.#....##.#\n"
"##....##..###.#.#\n"
".####..###...###.\n"
"..#.###.#..#.#..#\n"
"..#.###.#..#.#..#\n"
".####..###...###.\n"
"##....##..###.#.#\n"
"..#..##.#....##.#\n"
"#######........##\n"
"####...##.#..##..\n"
"#..#...#.##.##.#.\n"
".###.#..#.###.#.#\n"
".###.##.#.###.#.#\n"
"#..#...#.##.##.#.\n"
"####...##.#..##..\n"
"\n"
"#...####.#.....\n"
"#..#.#.#.....#.\n"
"####.#.#....##.\n"
"#..#...#.#.####\n"
".##......#.##..\n"
".##...#####....\n"
".##.#..#.......\n"
".##.#..#.......\n"
".##...#####....\n"
".##......#.##..\n"
"#..#...#.#.####\n"
"\n"
".###.#.....\n"
"...##..#.#.\n"
"##....##...\n"
"..#..#.#...\n"
"##.##.##..#\n"
"##.##.##..#\n"
"..#..#.#...\n"
"##....##...\n"
"...##..#.#.\n"
".###.#.....\n"
"..#.#.###.#\n"
"##.##..#.##\n"
"##.##..#.#.\n"
"\n"
".#....#.#.#.#....\n"
"#.####.#...####..\n"
"#..##..##.##..###\n"
".#.##.#..#####.##\n"
"#..##..##.#....##\n"
"#.#..#.#.#.#.#...\n"
".######....#.#...\n"
"#.####.#....#.###\n"
"...##...###..##..\n"
"..#..#..#.##..#..\n"
"#..##..#.#.##.#..\n"
".#....#.#..##..##\n"
"##..#.###.####.##\n"
"\n"
".##..##.###\n"
".######.#..\n"
"###..###...\n"
"#.#..#.###.\n"
"##....##...\n"
"##....###..\n"
"#..##..#.##\n"
"#########.#\n"
".#.##.#..#.\n"
"..#..#...##\n"
".#....#.##.\n"
".#....#.##.\n"
"..#..#....#\n"
".#.##.#..#.\n"
"#########.#\n"
"#..##..#.##\n"
"##....###..\n"
"\n"
"#...#.#..#.\n"
"####.#..#.#\n"
"##.#..####.\n"
"#.###.#..#.\n"
"......####.\n"
".###.######\n"
"#.#.##.##.#\n"
"...###....#\n"
".....#....#\n"
"##..#..##..\n"
"##.#.######\n"
"##.#.######\n"
"##..#..##..\n"
".....#....#\n"
"...###....#\n"
"#.#.##.##.#\n"
".###.######\n"
"\n"
"#.#####...#......\n"
"#.#####...#......\n"
".##...###..#.#...\n"
".#.####.####...#.\n"
"....##..#.##...##\n"
"###...#..#.##...#\n"
"....##.#.##.#.##.\n"
"##.#.#....#####.#\n"
"..##.#.#..###.#.#\n"
"##.###.####.#...#\n"
"#..###.####.#...#\n"
"..##.#.#..###.#.#\n"
"##.#.#....#####.#\n"
"....##.#.##.#.##.\n"
"###...#..#.##...#\n"
"\n"
"##..###\n"
".####..\n"
"#....##\n"
"..##...\n"
"#.##...\n"
"##..###\n"
"#.##.##\n"
"\n"
".#.#..#....##...#\n"
".###..#....##...#\n"
".#####.##..#.#..#\n"
"#.##.##.#........\n"
"#.##.##.#........\n"
".#####.##..#.#..#\n"
".###..#....##...#\n"
".#.#..#....##...#\n"
"###..#..###.##.#.\n"
"##.....###.#..###\n"
"####...####..####\n"
"\n"
"##..##.##.#\n"
"#...###..##\n"
".#...######\n"
"#..##......\n"
".##########\n"
"###........\n"
"###.#......\n"
"..#.#......\n"
"#.#.#######\n"
".#..###..##\n"
"#.#.#......\n"
".######..##\n"
"...#.######\n"
"..#.#..##..\n"
"..#####..##\n"
"#.#########\n"
"##.########\n"
"\n"
"..##..#..\n"
"#.#..##..\n"
"#..#####.\n"
".####...#\n"
".####...#\n"
"#..####..\n"
"#.#..##..\n"
"..##..#..\n"
"##..#....\n"
"..#....##\n"
"..#....##\n"
"##..#....\n"
"..##..#..\n"
"\n"
".#..#....\n"
"#.##.###.\n"
"#....####\n"
"#....##.#\n"
"#.##.#..#\n"
"##..##.#.\n"
"#....#.#.\n"
"#....#..#\n"
"#....##.#\n"
"#....#.#.\n"
"##..##.#.\n"
"#.##.#..#\n"
"#....##.#\n"
"#....####\n"
"#.##.###.\n"
".#..#....\n"
"##..###..\n"
"\n"
"...####.##..#\n"
"#.....####..#\n"
"...#...#.#..#\n"
"###..#.###..#\n"
".#.#.##.#.##.\n"
"...#.##.#.##.\n"
"###..#.###..#\n"
"...#...#.#..#\n"
"#.....####..#\n"
"...####.##..#\n"
".....###.####\n"
"\n"
"#.##...\n"
".#.#...\n"
"##.#.##\n"
".#.####\n"
".#.##..\n"
".##.#..\n"
".###.##\n"
"#.#..##\n"
"..###..\n"
".####..\n"
".###...\n"
"\n"
".##..##.########.\n"
".#.##.#...####...\n"
".######.#.#..#.#.\n"
".##..##.##....##.\n"
".######.#.####.#.\n"
"########..#..#..#\n"
"..#..#..#.#..#.#.\n"
"..#..#..#.#..#.#.\n"
".#......#.####.#.\n"
"\n"
"#...###..##..##\n"
".###..#####..##\n"
".##.#.##.#.##.#\n"
"..#..###.##..##\n"
"#...#....##..##\n"
"##.#####..####.\n"
"#####...#.#..#.\n"
"###..#..###..##\n"
"###.###.#######\n"
"#...##...#....#\n"
"##.#.#.#.#.##.#\n"
"##.#.#.#.#.##.#\n"
"#...###..#....#\n"
"\n"
".#.##.#..##.#..\n"
"##..#.##.##..##\n"
".#.#.#.....#...\n"
"#...###.####.##\n"
"#.#..#.##.##...\n"
"###..#.##.##...\n"
"#...###.####.##\n"
".#.#.#.....#...\n"
"##..#.##.##..##\n"
".#.##.#..##.#..\n"
"...#.#...#.##..\n"
"..###.#..####..\n"
"##..####.#.....\n"
"######.##...###\n"
"..#.....#.##.##\n"
"\n"
"......#\n"
"......#\n"
"..#..#.\n"
"####.#.\n"
"..#.##.\n"
"##.##..\n"
"..#.###\n"
"...###.\n"
"##.###.\n"
"...###.\n"
"..#...#\n"
"##...#.\n"
"##...#.\n"
"####.##\n"
"##.#.##\n"
"###..#.\n"
".#.##.#\n"
"\n"
"..####..#.#...#..\n"
".#....#.######..#\n"
".#.##.#.....#....\n"
".#.##.#.....#....\n"
".#....#.######..#\n"
"..####..#.#...#..\n"
"..####..####.####\n"
"##....##..#.###..\n"
".......##......#.\n"
"\n"
"###..##..\n"
"..#.#..#.\n"
"###.####.\n"
"##..####.\n"
"...#....#\n"
"##.#.####\n"
"...######\n"
"...######\n"
"..#.#..#.\n"
"..#######\n"
"##.......\n"
"..#..##..\n"
"..#......\n"
"##...##..\n"
"#####..##\n"
"\n"
"##........##...\n"
"...######......\n"
"..##....##..##.\n"
"###..##..######\n"
"##..#..#..#####\n"
"..###..###..###\n"
".....##.....#.#\n"
"..#.####.#...#.\n"
"###..##..####..\n"
"...######.....#\n"
"..#..##..#..#..\n"
"#...####...#..#\n"
"##.#....#.##...\n"
"###......###.#.\n"
"..###..###..#..\n"
"###.#..#.####..\n"
"..#..##..#..#.#\n"
"\n"
"#...##.#.\n"
"#...#..#.\n"
"...#.#...\n"
".######..\n"
".....#.#.\n"
".#...####\n"
"..#..#...\n"
"..#..#...\n"
".#...####\n"
".....#.#.\n"
".######..\n"
"...#.#...\n"
"#...#..#.\n"
"#...##.#.\n"
"#.#..#.##\n"
"#.#.##..#\n"
".#.###.##\n"
"\n"
".######....#.#.\n"
".........#...##\n"
".#....#.#.#....\n"
"..#..#....#.###\n"
"#.####.##..#..#\n"
"...##...#..####\n"
"...##...#..####\n"
"#.####.##..#..#\n"
"..#..#....#.###\n"
".#....#.#.#....\n"
".........#..###\n"
"\n"
"....###.#..\n"
"#...#...###\n"
"#...#...###\n"
"....###.#..\n"
".......#.#.\n"
"#.##.##.###\n"
"##..#..#...\n"
"#####..#.##\n"
"##..#......\n"
"##...#.#.##\n"
"#.#..##.#..\n"
"\n"
"..####...##.#\n"
"..####....###\n"
"##.##.##..###\n"
"...##...##.#.\n"
".##..##.#####\n"
"##.##.#####..\n"
"..####...#.#.\n"
"........#...#\n"
"###..###..#.#\n"
"...##....#...\n"
"##....##..###\n"
"..####..##.##\n"
"##.##.###.##.\n"
"\n"
"##...####...#\n"
"...#......##.\n"
"#####.##.####\n"
"##.#.#..#.#.#\n"
"###..#..#..##\n"
"....#....#...\n"
"...##.##.##..\n"
"\n"
".##.##...\n"
".#...#...\n"
"###.#.###\n"
"#......##\n"
".##.#####\n"
"###.#..##\n"
".#....#..\n"
"##...#...\n"
"#.##.#.##\n"
"#.##.####\n"
"##...#...\n"
"\n"
"####.#..#\n"
"...##.###\n"
"##.....#.\n"
"..#..###.\n"
"..#..###.\n"
"##.....#.\n"
"..###.###\n"
"####.#..#\n"
"....#.#.#\n"
".##.#..#.\n"
"..#..##..\n"
"#.##.#.#.\n"
"#.##.#.#.\n"
"..#..##..\n"
".##.#..#.\n"
"\n"
"...#.#.\n"
"###.#..\n"
"......#\n"
"#####..\n"
"##..###\n"
"##.....\n"
"##.#...\n"
"##.#...\n"
"##.....\n"
"##..###\n"
"#####..\n"
"...#..#\n"
"###.#..\n"
"\n"
"..#.#.#\n"
"####.##\n"
"######.\n"
"...#.#.\n"
"...#...\n"
"..##..#\n"
"...###.\n"
"###.##.\n"
"#####..\n"
"#####..\n"
"######.\n"
"...###.\n"
"..##..#\n"
"...#...\n"
"...#.#.\n"
"######.\n"
"####.##\n"
"\n"
".#..##.#.####\n"
"###.##....##.\n"
"..#####......\n"
"####.#.......\n"
".##..###..##.\n"
"....#...#####\n"
"####..#.#####\n"
"#.##.##.#....\n"
"#######......\n"
"##.#.....####\n"
"#.##.###..##.\n"
"#.##.###..##.\n"
"##.#.....####\n"
"#######......\n"
"#.##.#..#....\n"
"\n"
"....#.#...##.....\n"
"#..#..###...###.#\n"
"#..######..##.##.\n"
"#..#.#.#...#.#..#\n"
".......#.##......\n"
".##.##...####....\n"
".....#....####..#\n"
"\n"
"..####...\n"
"...##....\n"
"...##....\n"
"..####...\n"
"#.#..#.##\n"
".#.##.#.#\n"
"..####...\n"
"########.\n"
"##...####\n"
"#..##..##\n"
"##....###\n"
".######..\n"
"...##....\n"
"\n"
"#..##.#..#..#.#\n"
"#..##.#..#..#.#\n"
"#.###...##.###.\n"
"....#.####.#.##\n"
".##..#...#.#..#\n"
"###.#####..#.##\n"
"#.###...###.#.#\n"
"#..#.##....#.##\n"
"#..#.##....#.##\n"
"#.###...###.#.#\n"
"###.#####..#.##\n"
".##..#...#.#..#\n"
"....#.####.#.##\n"
"#.###...##.#.#.\n"
"#..##.#..#..#.#\n"
"\n"
".##.#..#.\n"
"####....#\n"
"#####..##\n"
".##.####.\n"
".##.####.\n"
"..#.#..#.\n"
"####....#\n"
"#..#.##.#\n"
"....#..#.\n"
"####.##.#\n"
".##.#..#.\n"
"####.##.#\n"
".##......\n"
"\n"
"....#..##..##\n"
"....#..##..##\n"
"..###.....##.\n"
"####.##..#.#.\n"
"#..#.#.#....#\n"
".##.#.#..#.##\n"
".#..##..#..##\n"
"#.#.....#.#..\n"
"###.....#.#..\n"
".#..##..#..##\n"
".##.#.#..#.##\n"
"#..#.#.#....#\n"
"####.##..#.#.\n"
"..###.....##.\n"
"....#..##..##\n"
"\n"
"##.#.######.#\n"
"....##.##.##.\n"
"#####.#..#.##\n"
"##.##..##..##\n"
"...#.##..##.#\n"
"..##..####..#\n"
"..#....##....\n"
"##.###.##.#.#\n"
"####.#....#.#\n"
"\n"
".###.....###.##\n"
"####.#.##..#.#.\n"
"###..#.##..#.#.\n"
".###.....###.##\n"
"#.#######.#..#.\n"
"#..#...#.#.#...\n"
"#...#.#####..#.\n"
"#...#.#####..#.\n"
"#..#...#.#.#...\n"
"#.#######.#..#.\n"
".###.....###.##\n"
"###..#.##..#.#.\n"
"####.#.##..#.#.\n"
".###.....###.##\n"
".#....###.#.#..\n"
"\n"
"..##.#....#\n"
".######.##.\n"
".######.##.\n"
"..##.#....#\n"
".#.##.#....\n"
"###.##.####\n"
"##..#..###.\n"
"...#..#.#.#\n"
"###...#.#.#\n"
"###...#.#.#\n"
"...#..#.#.#\n"
"##..#..###.\n"
".##.##.####\n"
".#.##.#....\n"
"..##.#....#\n"
"\n"
"#..#......###..\n"
"#..#......###..\n"
"#.####........#\n"
"#..##.....##..#\n"
"#..#.#######..#\n"
".##..#...#...##\n"
".....####..#...\n"
"#..##..##.#.#..\n"
".##.###.#..#.##\n"
"\n"
"###.###..\n"
"###.###..\n"
"..#.#.#.#\n"
"####.....\n"
"..#.....#\n"
"#....##..\n"
"###.##.##\n"
"#####..#.\n"
"#####..#.\n"
"###.#..##\n"
"#....##..\n"
"\n"
".###.#.##.#.###.#\n"
"##..#..##..#..###\n"
"#..##.#..#.##..##\n"
"##..#.#..#.#..##.\n"
"...###....###...#\n"
".#...##..##...#..\n"
"..........#......\n"
"#....######....#.\n"
"..####.##.####...\n"
".###.#.##.#.###.#\n"
"######.##.#######\n"
"##....#..#....###\n"
"##.#.#....#.#.##.\n"
"##.#.#....#.#.##.\n"
"##....#..#....###\n"
"######.##.#######\n"
".###.#.##.#.###.#\n"
"\n"
".#.#..###..##\n"
"#.##.#####...\n"
"####.#..#.#..\n"
".##...#.#####\n"
"#..#..###....\n"
"#..###.......\n"
"###..#.#.##..\n"
"..###.##.####\n"
"..#.#.##.####\n"
"###..#.#.##..\n"
"#..###.......\n"
"#..#..###....\n"
".##...#.#####\n"
"####.#..#.#..\n"
"#.##.#####...\n"
".#.#..###..##\n"
"##....#######\n"
"\n"
"#.###...#.#####\n"
"######.#.####.#\n"
"#....##...##.#.\n"
"#....##...##.#.\n"
"######.#.####.#\n"
"#.###...#.#####\n"
"####..#.#..#..#\n"
".##.###.##.##..\n"
"....########..#\n"
"##.##..###..#.#\n"
"##.##..###..#.#\n"
"....########..#\n"
".##.###.##.##.#\n"
"####..#.#..#..#\n"
"#.###...#.#####\n"
"\n"
"....##...\n"
"#######..\n"
".......#.\n"
"....#.#..\n"
"####..#.#\n"
"#####...#\n"
"####.#..#\n"
".....#.##\n"
".##.#.#..\n"
"######.#.\n"
".....#.##\n"
".....###.\n"
"#####..#.\n"
"####.###.\n"
"######.##\n"
"\n"
".#...#.####..\n"
".#...#.####..\n"
"..########...\n"
".###..#.#.#..\n"
"#...#....#.##\n"
".......#...#.\n"
".#.######.#.#\n"
"###.#.#.####.\n"
"....###..##.#\n"
"...#.#.####..\n"
"...#.#.####..\n"
"....###..##.#\n"
"###.#.#.####.\n"
".#.######.#.#\n"
"..#....#...#.\n"
"#...#....#.##\n"
".###..#.#.#..\n"
"\n"
"#.#..######\n"
"#.#.#######\n"
".##.##....#\n"
"#..........\n"
"###.##.##.#\n"
".##########\n"
"##.#...##..\n"
"\n"
"....####..###\n"
"##.###.####.#\n"
"##..#........\n"
"##.#.#......#\n"
"..#.#.#.##.#.\n"
"....#.#....#.\n"
"..##.###..###\n"
"###.##..##..#\n"
"...##...##.#.\n"
"..#.....##...\n"
"###.##......#\n"
"\n"
".##..#.#..#..\n"
"#.....#######\n"
"#.#####.##...\n"
"#######..####\n"
".####..####..\n"
".####...###..\n"
"#######..####\n"
"#.#####.##...\n"
"#.....#######\n"
"\n"
".#.##....##.#....\n"
".#.##....##.#....\n"
"####.####.#####..\n"
"#.##########.#.#.\n"
".#.##....##.#..#.\n"
"####......#####.#\n"
"#...######......#\n"
"#.#.######.#.#..#\n"
"#.##.####.##.#.##\n"
"..#........#.....\n"
"#.#...##...#.#.##\n"
"\n"
"####....#\n"
"##.#....#\n"
".########\n"
"#..######\n"
"#.#......\n"
"#.#######\n"
"##..####.\n"
"\n"
"###........##.##.\n"
"###...###.#..#...\n"
"#####.#.....#####\n"
"..#.##........#.#\n"
"..#.##........#.#\n"
"#####.#.....#####\n"
"###...###.#..##..\n"
"###........##.##.\n"
"######.###...#...\n"
"##..##.##.###.#.#\n"
"#####.#.##..#....\n"
"...#..#..#..#.##.\n"
"...##.####..###..\n"
"##.#....##.#....#\n"
"##.#.##.#####.###\n"
"\n"
"#...#.##.\n"
".###.#...\n"
".#####...\n"
"#...#.##.\n"
".......##\n"
"#.#...###\n"
"#.#...###\n"
"\n"
"..#.##.###.##.#\n"
".###.#.......##\n"
"#..#.#...#..#.#\n"
"########..####.\n"
"########..####.\n"
"#..#.#...#..#.#\n"
".###.#.......##\n"
"..#.##.###.##.#\n"
"#...#...##.....\n"
"#.#..#.###.....\n"
"#..##.#.##.####\n"
"..#######.###.#\n"
"..###########.#\n"
"\n"
".#..##.\n"
"##.##..\n"
"##.##..\n"
".#..##.\n"
"##.###.\n"
"#.#####\n"
"#..##.#\n"
"####..#\n"
"..##..#\n"
"..##..#\n"
"####...\n"
"\n"
"##..##..##..#\n"
"....######...\n"
"######..#####\n"
"##.##.##.##.#\n"
"...########..\n"
"###.######.##\n"
"###.######.##\n"
"#####....####\n"
"..#........#.\n"
"###........##\n"
"##.########.#\n"
"..#.#....#.#.\n"
"##...####...#\n"
"######..#####\n"
"..#.##..##.##\n"
"\n"
"#..####\n"
"....###\n"
"####.##\n"
".##.###\n"
"####.#.\n"
".##.#.#\n"
".##.#..\n"
"....#.#\n"
"....#.#\n"
".##.#..\n"
".##.#.#\n"
"######.\n"
".##.###\n"
"\n"
"...######\n"
".#..###.#\n"
"####.##.#\n"
"#.#.....#\n"
"#.#.....#\n"
"####.##.#\n"
".#..###.#\n"
"...######\n"
"####.####\n"
".#..##..#\n"
"##..#.##.\n"
".....###.\n"
".#..#.#..\n"
".#..#.#..\n"
".....##..\n"
"\n"
"..#..#..#.#.....#\n"
"##.##.##.#...#.#.\n"
"##.##.##.#...#.#.\n"
"..#..#..#.#.....#\n"
".#######.#..##.##\n"
".........###..##.\n"
".#....#..#.#..##.\n"
"\n"
"......#..#.\n"
"..##...#.#.\n"
"#######.###\n"
"#....#.#..#\n"
"######....#\n"
"......#..#.\n"
"..##.......\n"
"##..######.\n"
"#.#####..#.\n"
"#....#.#.##\n"
"..##...#.##\n"
"..##......#\n"
"..##......#\n"
"\n"
"...#.#..#\n"
"...######\n"
"..#......\n"
"..#######\n"
"...#..##.\n"
"...#.####\n"
"..#.#.##.\n"
"..##..##.\n"
"..#...##.\n"
"##.##.#..\n"
"##....##.\n"
"..#..#..#\n"
"###..#..#\n"
"\n"
".##.#..###.#...##\n"
"#..#.##....#.#..#\n"
".........##.#.###\n"
".##.....###...###\n"
".##.##.#...###.#.\n"
".##.##.#...###.#.\n"
".##.....###...###\n"
".........##.#.###\n"
"#..#.##.#..#.#..#\n"
"\n"
"#.###.##.##\n"
"#..#......#\n"
"#.#.##..##.\n"
".###.#..#.#\n"
".###.#..#.#\n"
"#...##..##.\n"
"#..#......#\n"
"#.###.##.##\n"
"####......#\n"
"\n"
"...##.##.#.#.#.\n"
"...##.##.#.#.#.\n"
".##...#..##.#.#\n"
".###.#.##..#.#.\n"
"....###..#.####\n"
"....###..#.####\n"
".###.#.##..#.#.\n"
".##...#..##.#.#\n"
"#..##.##.#.#.#.\n"
"\n"
"#..##......##\n"
"#.#....##....\n"
"##.##.####.##\n"
".#...##..##..\n"
".#.####..####\n"
".##...#..#...\n"
".####.####.##\n"
".#.##..##..##\n"
"#..##..##..##\n"
"#.#..#.##.#..\n"
"#..#.##..##.#\n"
"#.###.####.##\n"
"##.####..####\n"
"#.#....##....\n"
"..#..........\n"
"\n"
".#.##.#.#..##.#\n"
"#..##..##......\n"
"##....###......\n"
".#....#.##..##.\n"
"#.#..#.#..#.##.\n"
"#......#.#.#..#\n"
"...##...#.#....\n"
"...##...#.#.##.\n"
"#########.#.##.\n"
"##....###......\n"
"#.####.#..#.##.\n"
"\n"
"##..........##..#\n"
"..####..####..##.\n"
"..####..####.....\n"
"..##......##..##.\n"
"#..#..##..#..####\n"
"#.#........#.####\n"
"#####.###########\n"
"\n"
"###########..\n"
"##.##.##...#.\n"
"#.#..#.##.#.#\n"
"###..######..\n"
"#..##..##....\n"
"#..##..##....\n"
"###..######..\n"
"#.#..#.##.#.#\n"
"##.##.##...#.\n"
"###########..\n"
".#...##.#.#.#\n"
"\n"
"..#.#.##..##.\n"
"....##.#.#.#.\n"
"#####......#.\n"
"#...#.#####..\n"
"##..##.....##\n"
".#.##..###.#.\n"
"..###.##..#.#\n"
"..###.##..#.#\n"
".#.##..###.#.\n"
"##...#.....##\n"
"#...#.#####..\n"
"#####......#.\n"
"....##.#.#.#.\n"
"..#.#.##..##.\n"
"..#.#.##..##.\n"
"\n"
"..#.#.#..#...\n"
"..#.#.#..#...\n"
"....#...####.\n"
"..##.#.#.#..#\n"
".#.#....#....\n"
"#####..#.#.##\n"
".####.##.....\n"
"..######.#...\n"
"..##.#.#..###\n"
"..##...#..###\n"
"..######.#...\n"
".####.##.....\n"
"#####..#.#.##\n"
".#.#....#....\n"
"..##.#.#.#..#\n"
"....#...####.\n"
"..#.#.#..#...\n"
"\n"
".##.#.#.#..\n"
".##.#.#.#..\n"
"#.####.#.#.\n"
"#.##.....##\n"
"...#.##.#..\n"
".##.##.#..#\n"
"...##.##.#.\n"
"#.....#.#.#\n"
"#.....###.#\n"
"...##.##.#.\n"
".##.##.#..#\n"
"\n"
".###..###\n"
".##....##\n"
"#.#....#.\n"
".########\n"
"##.#..#.#\n"
"##......#\n"
"##..###.#\n"
"#.#.##.#.\n"
".#......#\n"
"..#....#.\n"
"####..###\n"
"...#..#..\n"
"...#..#..\n"
"####..###\n"
"..#....#.\n"
"\n"
;

constexpr bool CheckMultipleReflections = false; // when true, slows down the search.

} // namespace

auto day13Part1(std::string_view streamSource, bool sourceIsFilePath)
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
    using Reflection = std::pair<bool, Coord>;

    enum class FindResult { Success, NoReflection, MoreReflections };

    const auto findReflection = [](std::vector<std::string>& lines, Reflection& combRes) {
        if (lines.empty()) {
            throw std::runtime_error("unexpected empty set of lines");
        }

        const auto rowsLength = lines[0].size();
        const auto patternCount = lines.size();

        bool foundOne = false;

        // horizontal
        for (Coord i = 0U; i < patternCount - 1U; ++i) {
            Coord rowCount = i + 1U; // above
            if (patternCount - i - 1U < rowCount) {
                rowCount = patternCount - i - 1U;
            }

            bool okReflection = true;
            for (Coord j = 0; j < rowCount; ++j) {
                if (lines[i - j] != lines[i + 1U + j]) {
                    okReflection = false;
                    break;
                }
            }

            if (okReflection) {
                if (foundOne) {
                    return FindResult::MoreReflections; // for the case CheckMultipleReflections
                }
                combRes = std::make_pair(true, i);
                foundOne = true;

                // cppcheck 1.90 ignores about 'new' if in C++17
                // cppcheck-suppress knownConditionTrueFalse
                if constexpr (!CheckMultipleReflections) {
                    return FindResult::Success;
                }
            }
        }

        // vertical
        for (Coord i = 0U; i < rowsLength - 1U; ++i) {
            Coord colCount = i + 1U; // above
            if (rowsLength - i - 1U < colCount) {
                colCount = rowsLength - i - 1U;
            }

            bool okReflection = true;
            for (Coord j = 0; j < colCount; ++j) {

                for (Coord k = 0; k < patternCount; ++k) {
                    const auto& lineScroll = lines[k];
                    if (lineScroll[i - j] != lineScroll[i + 1U + j]) {
                        okReflection = false;
                        break;
                    }

                    if (!okReflection) {
                        break;
                    }
                }
            }

            if (okReflection) {
                if (foundOne) {
                    return FindResult::MoreReflections; // for the case CheckMultipleReflections
                }
                combRes = std::make_pair(false, i);
                foundOne = true;

                // cppcheck 1.90 ignores about 'new' if in C++17
                // cppcheck-suppress knownConditionTrueFalse
                if constexpr (!CheckMultipleReflections) {
                    return FindResult::Success;
                }
            }
        }

        return foundOne ? FindResult::Success : FindResult::NoReflection;
    };

    std::string errorLine;

    std::vector<std::string> lines;
    Coord rowsLength{};

    using Value = size_t;
    Value res = 0U;

    const auto processLines = [&errorLine, &res, &lines, &findReflection]() {
        // Search reflections.
        Reflection comb{};

        switch (findReflection(lines, comb)) {
        case FindResult::NoReflection:
            throw std::invalid_argument(errorLine + "pattern with no reflections");
        case FindResult::MoreReflections:
            throw std::invalid_argument(errorLine + "pattern with multiple reflections");
        case FindResult::Success: {
            Value deltaRes{};
            if (comb.first) {
                // horizontal
                constexpr Value RowsPoints = 100U;
                deltaRes = ((comb.second + 1U) * RowsPoints);
            } else {
                // vertical
                constexpr Value ColsPoints = 1U;
                deltaRes = ((comb.second + 1U) * ColsPoints);
            }

            if (deltaRes > std::numeric_limits<Value>::max() - res) {
                throw std::runtime_error("Need a higher-size type as Value");
            }
            res += deltaRes;
        } break;
        default:
            throw std::runtime_error("unexpected result from basic-findReflection");
        }
    };

    unsigned patternCount{0U};
    unsigned nonEmptyLines{0U};

    unsigned lineCount{0U};

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

        if (line.length() == 0U) {
            ++patternCount;
            processLines();

            rowsLength = 0;
            lines.clear();
        } else {
            ++nonEmptyLines;

            if (!std::accumulate(line.cbegin(), line.cend(), true, [](bool acc, char ch) {
                    return acc && ((ch == '.') || (ch == '#'));
                })) {
                throw std::invalid_argument(errorLine + "line with unexpected characters");
            }

            if (rowsLength == 0U) {
                rowsLength = line.length();
            } else if (line.length() != rowsLength) {
                throw std::invalid_argument(
                    errorLine + "line length different from previous ones in the pattern");
            }

            lines.push_back(line);
        }
    }

    if (!lines.empty()) { // in case of missing final empty line
        ++patternCount;
        processLines();
    }

    std::cout << "Number of lines " << lineCount << std::endl;
    std::cout << "Total non-empty lines " << nonEmptyLines << std::endl;
    std::cout << "Total patterns " << patternCount << std::endl;
    std::cout << "\nResult: " << res << std::endl;
    return res;
}

int main()
{
    try {
        day13Part1(Input, false);
        // day13Part1("./13_input_file.txt",true);
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
Number of lines 16
Total non-empty lines 14
Total patterns 2
Result: 405

Real input:
Number of lines 1378
Total non-empty lines 1278
Total patterns 100
Result: 27202
*/
