#include <algorithm>
#include <array>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace{

constexpr std::string_view Input =
false ?

"#.#####################\n"
"#.......#########...###\n"
"#######.#########.#.###\n"
"###.....#.>.>.###.#.###\n"
"###v#####.#v#.###.#.###\n"
"###.>...#.#.#.....#...#\n"
"###v###.#.#.#########.#\n"
"###...#.#.#.......#...#\n"
"#####.#.#.#######.#.###\n"
"#.....#.#.#.......#...#\n"
"#.#####.#.#.#########v#\n"
"#.#...#...#...###...>.#\n"
"#.#.#v#######v###.###v#\n"
"#...#.>.#...>.>.#.###.#\n"
"#####v#.#.###v#.#.###.#\n"
"#.....#...#...#.#.#...#\n"
"#.#########.###.#.#.###\n"
"#...###...#...#...#.###\n"
"###.###.#.###v#####v###\n"
"#...#...#.#.>.>.#.>.###\n"
"#.###.###.#.###.#.#v###\n"
"#.....###...###...#...#\n"
"#####################.#\n"

:

"#.###########################################################################################################################################\n"
"#.###.....................#...#.............#...#...###.......#.....#.....#.............###...#...#######...#...#...#...#...#.......#.......#\n"
"#.###.###################.#.#.#.###########.#.#.#.#.###.#####.#.###.#.###.#.###########.###.#.#.#.#######.#.#.#.#.#.#.#.#.#.#.#####.#.#####.#\n"
"#...#.#...................#.#.#.........#...#.#.#.#...#...#...#.#...#...#.#...#.........#...#...#...###...#.#.#.#.#.#.#.#.#.#.#.....#.#.....#\n"
"###.#.#.###################.#.#########.#.###.#.#.###.###.#.###.#.#####.#.###.#.#########.#########.###.###.#.#.#.#.#.#.#.#.#.#.#####.#.#####\n"
"###...#.........#...###...#.#.###.......#...#.#.#...#.#...#.....#.#...#.#...#.#.....>.>.#.#.........#...#...#.#...#...#.#.#...#.....#.#.#...#\n"
"###############.#.#.###.#.#.#.###.#########.#.#.###.#.#.#########.#.#.#.###.#.#######v#.#.#.#########.###.###.#########.#.#########.#.#.#.#.#\n"
"#.............#.#.#...#.#...#...#.......#...#.#.....#.#.......###...#.#...#...###.....#.#.#.#...#...#...#.###.#.......#...#.......#...#...#.#\n"
"#.###########.#.#.###.#.#######.#######.#.###.#######.#######.#######.###.#######.#####.#.#.#.#.#.#.###.#.###.#.#####.#####.#####.#########.#\n"
"#.......#...#...#.#...#.......#.#...#...#...#.......#.###...#.......#...#.#.......#...#.#.#...#.#.#...#.#...#...#.....#...#.....#.#...#...#.#\n"
"#######.#.#.#####.#.#########.#.#.#.#.#####.#######.#.###.#.#######.###.#.#.#######.#.#.#.#####.#.###.#.###.#####.#####.#.#####.#.#.#.#.#.#.#\n"
"#.......#.#.....#.#.#.......#.#.#.#.#.....#.#.....#.#.>.>.#.#...#...#...#.#.........#.#...#.....#...#.#.#...###...#.....#.......#...#...#...#\n"
"#.#######.#####.#.#.#.#####.#.#.#.#.#####.#.#.###.#.###v###.#.#.#.###.###.###########.#####.#######.#.#.#.#####.###.#########################\n"
"#.........#.....#.#.#...#...#.#...#.#.....#.#...#.#.###...#...#.#...#...#.#.........#...#...#.....#.#.#.#...>.>.###.....#...................#\n"
"###########.#####.#.###.#.###.#####.#.#####.###.#.#.#####.#####.###.###.#.#.#######.###.#.###.###.#.#.#.#####v#########.#.#################.#\n"
"#...........#...#.#...#.#.###.....#.#.#...#.....#.#...#...#...#.#...###...#.......#.....#...#.###.#.#.#.#.....#########...#.......#.........#\n"
"#.###########.#.#.###.#.#.#######.#.#.#.#.#######.###.#.###.#.#.#.###############.#########.#.###.#.#.#.#.#################.#####.#.#########\n"
"#.....#...###.#.#.#...#.#.###...#.#.#...#.....###.#...#.....#.#...#.......#.......#.......#.#.#...#.#.#.#.......###.......#.....#.#.........#\n"
"#####v#.#.###.#.#.#.###.#.###.#.#.#.#########.###.#.#########.#####.#####.#.#######.#####.#.#.#.###.#.#.#######.###.#####.#####.#.#########.#\n"
"#...#.>.#...#.#.#.#.#...#.#...#.#.#.>.>.#...#...#.#.#...#.....#.....#.....#.......#.#.....#...#.#...#...###...#...#.....#.......#...........#\n"
"#.#.#v#####.#.#.#.#.#.###.#.###.#.###v#.#.#.###.#.#.#.#.#.#####.#####.###########.#.#.#########.#.#########.#.###.#####.#####################\n"
"#.#...#...#...#.#.#.#.#...#...#...#...#.#.#...#.#...#.#.#.......#.....###.........#.#.......#...#.#.........#.....#...#.....................#\n"
"#.#####.#.#####.#.#.#.#.#####.#####.###.#.###.#.#####.#.#########.#######.#########.#######.#.###.#.###############.#.#####################.#\n"
"#.#...#.#.#...#...#...#.......###...###...#...#...#...#.....#...#...#...#...........#.......#.#...#...............#.#.......#...............#\n"
"#.#.#.#.#.#.#.###################.#########.#####.#.#######.#.#.###.#.#.#############.#######.#.#################.#.#######.#.###############\n"
"#...#...#...#.......#.....#.....#.#.......#.......#.#.....#...#.....#.#.........#...#.......#...#...#...#.........#...#...#...###...#...#####\n"
"###################.#.###.#.###.#.#.#####.#########.#.###.###########.#########.#.#.#######.#####.#.#.#.#.###########.#.#.#######.#.#.#.#####\n"
"#...........#...#...#...#.#...#.#.#.#.....###.....#...###...........#.....#...#...#.........#.....#...#.#...........#...#.......#.#...#.....#\n"
"#.#########.#.#.#.#####.#.###.#.#v#.#.#######.###.#################.#####.#.#.###############.#########.###########.###########.#.#########.#\n"
"#.#.......#...#...#####.#.#...#.>.>.#.###.....#...#.........#...#...#...#...#.....#.....#...#.........#.###.........#...#.......#.#.........#\n"
"#.#.#####.#############.#.#.#####v###.###.#####.###.#######.#.#.#.###.#.#########.#.###.#.#.#########.#.###v#########.#.#.#######.#.#########\n"
"#.#.#.....#.....#...#...#...#####...#...#.....#.###.......#...#...###.#...###...#...#...#.#.#...###...#...>.>.......#.#.#.....#...#.........#\n"
"#.#.#.#####.###.#.#.#.#############.###.#####.#.#########.###########.###.###.#.#####.###.#.#.#.###.#######v#######.#.#.#####.#.###########.#\n"
"#.#.#.#...#.###...#.#...###...###...###...#...#...###...#.....#.......#...#...#.....#...#.#.#.#.#...###.....#.......#.#.#.....#.#...........#\n"
"#.#.#.#.#.#.#######v###.###.#.###.#######.#.#####.###.#.#####.#.#######.###.#######.###.#.#.#.#.#.#####.#####.#######.#.#.#####.#.###########\n"
"#.#.#.#.#...###...#.>.#...#.#.....###...#...#.....#...#.#.....#.....#...#...#.....#.....#.#.#.#.#.....#.#...#.#...###.#.#.....#.#.#.......###\n"
"#.#.#.#.#######.#.#v#.###.#.#########.#.#####.#####.###.#.#########.#.###.###.###.#######.#.#.#.#####.#.#.#.#.#.#.###.#.#####v#.#.#.#####.###\n"
"#.#.#.#.#.......#.#.#.#...#.....#...#.#.....#.#...#.###.#...#...###.#...#.....###.#...#...#.#.#.....#.#...#.#.#.#.#...#...#.>.#.#.#.....#...#\n"
"#.#.#.#.#.#######.#.#.#.#######.#.#.#.#####.#.#.#.#.###.###.#.#.###.###.#########v#.#.#.###.#.#####.#.#####.#.#.#.#.#####.#.#v#.#.#####.###.#\n"
"#...#...#.......#.#.#...#.......#.#.#...#...#...#...#...#...#.#...#...#...#.....>.>.#...#...#.....#...#...#.#.#.#.#...#...#.#...#...#...#...#\n"
"###############.#.#.#####.#######.#.###.#.###########.###.###.###.###.###.#.#####v#######.#######.#####.#.#.#.#.#.###.#.###.#######.#.###.###\n"
"#...###...#.....#.#...#...#.....#.#...#.#.#...#...###...#.###...#.###...#.#...#...###.....#.....#.#.....#.#.#.#.#...#.#.....#.......#.#...###\n"
"#.#.###.#.#.#####.###.#.###.###.#.###.#.#.#.#.#.#.#####.#v#####.#.#####.#.###.#.#####.#####.###.#.#.#####.#.#.#.###.#.#######.#######.#.#####\n"
"#.#.....#.#.....#.#...#...#.#...#.#...#.#...#...#.....#.>.>...#.#.#...#.#.#...#.....#.#...#...#.#.#.....#.#.#...###...#...###.........#.....#\n"
"#.#######.#####.#.#.#####.#.#.###.#.###.#############.###v###.#.#.#.#.#.#.#.#######.#.#.#.###.#.#.#####.#.#.###########.#.#################.#\n"
"#...#...#.......#...#####...#.....#...#.###...........###...#...#.#.#.#.#.#.#...#...#...#.....#...#...#.#.#...........#.#...................#\n"
"###.#.#.#############################.#.###.###############.#####.#.#.#.#.#.#.#.#.#################.#.#.#.###########.#.#####################\n"
"#...#.#.#.........#.....###...........#.#...#.....#.......#.....#.#.#.#.#.#.#.#...#...###.....#.....#...#.......#.....#.#...#...#...#...#####\n"
"#.###.#.#.#######.#.###.###.###########.#.###.###.#.#####.#####.#.#.#.#.#.#.#.#####.#.###.###.#.###############.#.#####.#.#.#.#.#.#.#.#.#####\n"
"#.....#...#.......#.#...#...#.....#...#.#.....#...#.....#.#.....#.#.#.#.#...#.#...#.#.....#...#...............#.#.....#.#.#.#.#...#...#.....#\n"
"###########.#######.#.###.###.###.#.#.#.#######.#######.#.#.#####.#.#.#.#####.#.#.#.#######.#################.#.#####.#.#.#.#.#############.#\n"
"###...#...#.........#...#...#...#...#.#.#.....#...#...#.#.#.....#...#.#.#.....#.#.#.#.......#.....#####.......#.......#...#...#...#...#.....#\n"
"###.#.#.#.#############.###.###.#####.#.#.###.###.#.#.#.#.#####.#####.#.#.#####.#.#.#.#######.###.#####v#######################.#.#.#.#.#####\n"
"#...#...#.....#...#...#...#.....#...#...#...#.....#.#.#.#.......#...#...#.....#.#.#.#.......#...#...#.>.>.....#...#.....###...#.#...#...#...#\n"
"#.###########.#.#.#.#.###.#######.#.#######.#######.#.#.#########.#.#########.#.#.#.#######.###.###.#.#v#####.#.#.#.###.###.#.#.#########.#.#\n"
"#...........#.#.#...#.#...#.....#.#...#...#.......#.#.#.....###...#...###...#.#.#...#.......###...#...#.#...#...#...#...#...#.#...........#.#\n"
"###########.#.#.#####.#.###.###.#.###.#.#.#######.#.#.#####v###.#####.###.#.#.#.#####.###########.#####.#.#.#########.###.###.#############.#\n"
"#...#.......#.#.....#...#...#...#...#...#.........#.#.....>.>.#.#.....#...#.#.#.#.....#...###.....#.....#.#.#.......#.###...#.#...#.........#\n"
"#.#.#.#######.#####.#####.###.#####.###############.#######v#.#.#.#####.###.#.#.#.#####.#.###.#####.#####.#.#.#####.#.#####.#.#.#.#.#########\n"
"#.#.#.......#.....#...#...#...#...#.........#.....#.......#.#.#.#...###.#...#...#.......#...#.....#.....#.#...#...#...#...#.#...#.#.....#####\n"
"#.#.#######.#####.###.#.###.###.#.#########.#.###.#######.#.#.#.###.###.#.#################.#####.#####.#.#####.#.#####.#.#.#####.#####.#####\n"
"#.#.###.....#...#.....#.#...#...#.#.......#.#...#.###...#.#.#.#...#...#.#...#...#...#.......###...#.....#...#...#.#...#.#.#.....#.....#.....#\n"
"#.#.###.#####.#.#######.#.###.###.#.#####.#.###.#.###.#.#.#.#.###.###.#.###.#.#.#.#.#.#########.###.#######.#.###.#.#.#.#.#####.#####.#####.#\n"
"#.#...#.....#.#.......#.#.#...#...#.....#.#...#.#...#.#.#.#.#.#...###.#.#...#.#.#.#.#.#...###...###...#.....#.#...#.#.#.#.#...#.....#.#...#.#\n"
"#.###.#####.#.#######.#.#.#.###.#######.#.###.#.###.#.#.#.#.#.#.#####.#.#.###.#.#.#.#.#.#.###.#######.#.#####.#.###.#.#.#.#.#.#####.#.#.#.#.#\n"
"#...#.#...#...#.......#.#.#...#.#...###.#.#...#.#...#.#...#.#...#.....#.#...#.#.#.#.#.#.#.#...###.....#...#...#...#.#.#.#.#.#.#...#.#.#.#.#.#\n"
"###.#.#.#.#####v#######.#.###.#.#.#.###.#.#v###.#.###.#####.#####.#####.###.#.#.#.#.#v#.#.#.#####.#######.#.#####.#.#.#.#.#.#.#.#.#.#.#v#.#.#\n"
"#...#...#...###.>...#...#...#.#.#.#.#...#.>.>...#...#.#...#.....#.#.....#...#.#.#.#.>.>.#.#.....#.....#...#.#.....#.#...#.#.#.#.#.#.#.>.#...#\n"
"#.#########.###v###.#.#####.#.#.#.#.#.#####v#######.#.#.#.#####.#.#.#####.###.#.#.###v###.#####.#####.#.###.#.#####.#####.#.#.#.#.#.###v#####\n"
"#.........#.#...###...#...#...#...#...#####.......#...#.#.......#.#.....#...#.#.#.###...#.#.....#...#.#.#...#.....#.###...#.#...#.#.###.....#\n"
"#########.#.#.#########.#.#######################.#####.#########.#####.###.#.#.#.#####.#.#.#####.#.#.#.#.#######.#.###.###.#####.#.#######.#\n"
"#.........#...###...#...#...#...#...#...###...#...#.....#.......#...#...#...#.#...#...#.#...#...#.#.#.#...#.......#...#.#...#...#...#...#...#\n"
"#.###############.#.#.#####.#.#.#.#.#.#.###.#.#.###.#####.#####.###.#.###.###.#####.#.#.#####.#.#.#.#.#####.#########.#.#.###.#.#####.#.#.###\n"
"#...#.......#...#.#.#.....#.#.#.#.#.#.#...#.#.#.###.......#...#...#...###...#.#.....#...###...#.#.#...#...#.#...#.....#...###.#.#...#.#...###\n"
"###.#.#####.#.#.#.#.#####.#.#.#.#.#.#v###.#.#.#.###########.#.###.#########.#.#.###########.###.#.#####.#.#.#.#.#.###########.#.#.#.#.#######\n"
"#...#.#.....#.#.#.#.#.....#.#.#...#.>.>.#...#.#.#...#.......#.#...###...#...#.#.............#...#.......#.#...#...#.....#...#.#.#.#.#.#.....#\n"
"#.###.#.#####.#.#.#.#.#####.#.#######v#.#####.#.#.#.#.#######.#.#####.#.#.###.###############.###########.#########.###.#.#.#.#.#.#.#.#.###.#\n"
"#.....#...#...#.#.#.#.#.....#...#...#.#...###...#.#.#.......#...#...#.#.#...#.#...............#...#.......###...###...#.#.#.#.#.#.#.#...#...#\n"
"#########.#.###.#.#.#.#.#######.#.#.#.###.#######.#.#######.#####.#.#.#.###.#.#.###############.#.#.#########.#.#####.#.#.#.#.#.#.#.#####v###\n"
"#.........#.###...#.#.#...#.....#.#.#...#...#...#.#.#.......###...#.#.#...#.#.#.....#...###...#.#.#.....#.....#...#...#.#.#.#.#.#.#.....>.###\n"
"#.#########.#######.#.###.#.#####.#.###.###.#.#.#.#.#.#########.###.#.###.#.#.#####.#.#.###.#.#.#.#####.#.#######.#.###.#.#.#.#.#.#######v###\n"
"#.........#.....#...#.#...#.#.....#.#...###.#.#.#.#.#...###...#.#...#.#...#...#...#...#...#.#...#.#.....#.#.......#...#.#.#.#.#.#.#.......###\n"
"#########v#####.#.###.#.###.#.#####.#.#####.#.#.#.#.###v###.#.#.#.###.#.#######.#.#######.#.#####.#.#####.#.#########.#.#.#.#.#.#.#.#########\n"
"###...###.>.....#.....#...#.#.#...#...###...#.#.#.#...>.>.#.#.#.#.#...#.#...#...#.#...#...#.....#.#...###.#.#...#...#.#.#.#.#.#...#.........#\n"
"###.#.###v###############.#.#.#.#.#######.###.#.#.#####v#.#.#.#.#.#.###.#.#.#.###.#.#.#.#######.#.###v###.#.#.#.#.#.#.#.#.#.#.#############.#\n"
"#...#.....###.........###...#...#.......#...#.#...#.....#.#.#.#.#.#.#...#.#.#.#...#.#.#.#...#...#...>.>.#.#.#.#.#.#.#.#.#.#...#...#...#...#.#\n"
"#.###########.#######.#################.###.#.#####.#####.#.#.#.#.#.#.###.#.#.#.###.#.#v#.#.#.#######v#.#.#.#.#.#.#.#.#.#.#####.#.#.#.#.#.#.#\n"
"#.............#...#...#...........###...###...#.....#...#...#.#.#.#.#.#...#.#.#...#.#.>.>.#.#...#.....#...#...#...#.#.#.#.#.....#...#...#...#\n"
"###############.#.#.###.#########.###.#########.#####.#.#####.#.#.#.#.#.###.#.###.#.###v###.###.#.#################.#.#.#.#.#################\n"
"#...............#...###.........#.....#.......#.......#.....#.#.#.#.#.#.#...#.###...#...###.#...#.........#...#...#...#...#.#...#...#...#...#\n"
"#.#############################.#######.#####.#############.#.#.#.#.#.#.#.###.#######.#####.#.###########.#.#.#.#.#########.#.#.#.#.#.#.#.#.#\n"
"#...........#...........###...#.........#.....#.............#...#.#.#...#.#...#.....#.....#.#...#.........#.#...#.....#...#...#...#...#.#.#.#\n"
"###########.#.#########.###.#.###########.#####.#################.#.#####.#.###.###.#####.#.###.#.#########.#########.#.#.#############.#.#.#\n"
"#...........#.#.........#...#.............#####.#...#.....#.....#...#...#...###...#.#.....#...#.#...........#.........#.#.#...#...#...#...#.#\n"
"#.###########.#.#########.#####################.#.#.#.###.#.###.#####.#.#########.#.#.#######.#.#############.#########.#.#.#.#.#.#.#.#####.#\n"
"#...........#.#.#.....###.....................#.#.#...###...#...#...#.#.#.........#.#...#...#...#...#####.....#...#...#.#...#.#.#...#.......#\n"
"###########.#.#.#.###.#######################.#.#.###########.###.#.#.#.#.#########.###.#.#.#####.#.#####.#####.#.#.#.#.#####.#.#############\n"
"#...........#.#...#...#...###...#...#.........#...#.....#.....#...#.#.#.#.......###.....#.#.#...#.#.......#...#.#.#.#.#.....#...#...#...#...#\n"
"#.###########.#####.###.#.###.#.#.#.#.#############.###.#.#####.###.#.#.#######.#########.#.#.#.#.#########.#.#.#.#.#.#####.#####.#.#.#.#.#.#\n"
"#.#.....#.....#.....###.#...#.#...#...#...#...#...#...#...#####...#.#.#.###.....#...#...#.#.#.#.#.........#.#.#.#...#.#.....#...#.#...#.#.#.#\n"
"#.#.###.#.#####.#######.###.#.#########.#.#.#.#.#.###.###########.#.#.#.###v#####.#.#.#.#.#.#.#.#########.#.#.#.#####.#.#####.#.#.#####.#.#.#\n"
"#.#.#...#...#...###...#...#.#...........#.#.#...#...#.....#.....#.#.#.#.#.>.>.....#.#.#.#.#.#.#...###...#...#...#.....#.......#...#.....#.#.#\n"
"#.#.#v#####.#.#####.#.###.#.#############.#.#######.#####.#.###.#.#.#.#.#.#v#######.#.#.#.#.#.###.###.#.#########.#################.#####.#.#\n"
"#...#.>...#.#...#...#...#.#.......#.......#...#.....#...#.#...#.#.#.#.#...#...#.....#.#.#.#.#...#.###.#.#.........#...#.....#.....#.#.....#.#\n"
"#####v###.#.###.#.#####.#.#######.#.#########.#.#####.#.#.###.#.#.#.#.#######.#.#####.#.#.#.###.#.###.#.#v#########.#.#.###.#.###.#.#.#####.#\n"
"#...#...#.#.###...#...#.#.#.......#.......#...#...#...#.#.#...#.#.#.#...#.....#.....#.#.#.#.#...#.#...#.>.>...#...#.#.#.#...#...#.#...#...#.#\n"
"#.#.###.#.#.#######.#.#.#.#.#############.#.#####.#.###.#.#.###.#.#.###.#.#########.#.#.#.#.#.###.#.#####v###.#.#.#.#.#.#.#####.#.#####.#.#.#\n"
"#.#.#...#...#...###.#...#.#.#...#...#.....#...#...#...#.#.#...#.#.#...#.#.........#.#.#.#.#.#...#.#.#...#...#.#.#.#.#.#.#.#...#.#.#...#.#.#.#\n"
"#.#.#.#######.#.###.#####.#.#.#.#.#.#v#######.#.#####.#.#v###.#.#.###.#.#########.#.#.#.#.#.###.#.#.#.#.###.#.#.#.#.#.#.#.#.#.#.#.#.#.#v#.#.#\n"
"#.#...###...#.#...#.#.....#...#.#.#.>.>.#...#.#.#...#.#.>.>.#.#...#...#.#.........#.#.#.#.#.#...#...#.#.#...#...#.#.#...#.#.#.#.#...#.>.#.#.#\n"
"#.#######.#.#.###.#.#.#########.#.###v#.#.#.#.#.#.#.#.###v#.#.#####.###.#.#########.#.#.#.#.#.#######.#.#.#######.#.#####.#.#.#.#######v#.#.#\n"
"#.#...###.#...#...#.#.......#...#...#.#...#.#.#.#.#.#.#...#...#...#...#.#.......###.#.#.#.#.#...#.....#...#...#...#.....#...#...###...#.#...#\n"
"#.#.#.###.#####.###.#######.#.#####.#.#####.#.#.#.#.#.#.#######.#.###.#.#######.###.#.#.#.#.###.#.#########.#.#.#######.###########.#.#.#####\n"
"#.#.#...#.....#...#.#...#...#.#.....#...#...#.#.#.#...#.......#.#...#.#.#.....#...#...#...#.#...#...........#.#...#.....#...###.....#.#.....#\n"
"#.#.###.#####.###.#.#.#.#.###.#.#######.#.###.#.#.###########.#.###.#.#.#.###.###.#########.#.###############.###.#.#####.#.###.#####.#####.#\n"
"#...###.#.....#...#...#...#...#.#.......#...#.#...#...........#.#...#...#...#.....###...###...###.............###...###...#.....#...#.......#\n"
"#######.#.#####.###########.###.#.#########.#.#####.###########.#.#########.#########.#.#########.#####################.#########.#.#########\n"
"#.......#.#.....#...#...###...#.#.....#####...#...#.........#...#.......###.........#.#...###...#.......#...#...###...#...........#.#...#...#\n"
"#.#######.#.#####.#.#.#.#####.#.#####.#########.#.#########.#.#########.###########.#.###.###.#.#######.#.#.#.#.###.#.#############.#.#.#.#.#\n"
"#...#...#.#...#...#...#...###...#...#.......#...#.....#.....#.#.........#...........#...#.#...#.#...###...#...#.....#.....#.........#.#...#.#\n"
"###.#.#.#.###.#.#########.#######.#.#######.#.#######.#.#####.#.#########.#############.#.#.###.#.#.#####################.#.#########.#####.#\n"
"###.#.#.#.###...#...#...#.....#...#.........#...#.....#.......#...###...#...........#...#.#.#...#.#.....#...........#...#.#.........#.#.....#\n"
"###.#.#.#.#######.#.#.#.#####.#.###############.#.###############.###.#.###########.#.###.#.#.###.#####.#.#########.#.#.#.#########.#.#.#####\n"
"###...#.#.#.......#...#.......#...........#...#.#.....#...........#...#.###...#.....#...#.#.#...#.....#.#.........#...#...###.......#.#.....#\n"
"#######.#.#.#############################.#.#.#.#####.#.###########.###.###.#.#v#######.#.#.###.#####.#.#########.###########.#######.#####.#\n"
"#.....#...#.......#...###...#...#.........#.#.#.#.....#.......#...#...#.#...#.>.>...###.#.#.#...#...#.#.###.......#.....#.....#.......#.....#\n"
"#.###.###########.#.#.###.#.#.#.#.#########.#.#.#.###########.#.#.###.#.#.#########.###.#.#.#.###.#.#.#.###v#######.###.#.#####.#######.#####\n"
"#...#.#...........#.#...#.#...#.#.....#...#.#.#.#.#...###...#...#...#.#.#.....#...#...#.#.#.#...#.#.#.#...>.>.......#...#.....#.#.....#.....#\n"
"###.#.#.###########.###.#.#####.#####.#.#.#.#.#.#.#.#.###.#.#######v#.#.#####.#.#.###.#.#.#.###.#.#.#.###############.#######.#.#.###.#####.#\n"
"#...#.#...........#...#.#.#.....#...#.#.#.#.#.#.#.#.#.#...#...#...>.>.#.#...#.#.#.....#.#.#.#...#.#.#.#...............#######...#...#...#...#\n"
"#.###.###########.###.#.#.#.#####.#.#v#.#.#.#.#.#.#.#.#.#####.#.#######.#.#.#.#.#######.#.#.#.###.#.#.#.###########################.###.#.###\n"
"#...#.............#...#.#.#.#...#.#.>.>.#.#.#.#.#.#.#.#.#.....#.......#.#.#.#.#.#...#...#...#.#...#.#.#.#.......#.......###...#...#.###...###\n"
"###.###############.###.#.#.#.#.#.#######.#.#.#.#.#.#.#.#.###########.#.#.#.#.#.#.#.#.#######.#.###.#.#.#.#####.#.#####.###.#.#.#.#.#########\n"
"###...............#...#.#.#.#.#.#...#.....#.#.#.#...#.#.#.....#.....#.#.#.#.#.#...#.#.###.....#...#...#...#...#...#.....#...#...#.#...#.....#\n"
"#################.###.#.#.#.#.#.###.#.#####.#.#.#####.#.#####.#.###.#.#.#.#.#.#####.#.###.#######.#########.#.#####.#####.#######.###.#.###.#\n"
"#.......#...#...#.#...#.#.#...#.#...#...#...#.#.#.....#...#...#...#...#.#.#.#...#...#.#...#...#...#.........#.......#...#.....#...#...#...#.#\n"
"#.#####.#.#.#.#.#.#.###.#.#####.#.#####.#.###.#.#.#######.#.#####.#####.#.#.###.#.###.#.###.#.#.###.#################.#.#####.#.###v#####.#.#\n"
"#.#...#...#...#...#...#.#.....#.#.....#.#...#.#.#...#...#.#.....#.....#.#.#.#...#.#...#...#.#.#.#...#.....#.....#...#.#.#...#.#.#.>.#...#.#.#\n"
"#.#.#.###############.#.#####.#.#####.#.###.#.#.###.#.#.#.#####.#####.#.#.#.#.###.#.#####.#.#.#.#.###.###.#.###.#.#.#.#.#.#.#.#.#.#v#.#.#.#.#\n"
"#...#.................#.......#.......#.....#...###...#...#####.......#...#...###...#####...#...#.....###...###...#...#...#...#...#...#...#.#\n"
"###########################################################################################################################################.#\n"

;

using Coord = size_t;

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
/*std::string pointToStr(Point p)
{
    using std::literals::string_literals::operator""s;
    return "("s + std::to_string(p.x) + ", " + std::to_string(p.y) + ')';
}*/

enum class Direction : unsigned { Right, Down, Left, Up };

constexpr unsigned FourDir = 4U;

template<typename E>
constexpr auto toUnderlying(const E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

/*std::string dirToStr(Direction d)
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
}*/

} // namespace

auto day23Part1(std::string_view streamSource, bool sourceIsFilePath)
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

    using Dir = Direction;

    using PosCount = unsigned long;

    Point startP{};
    Point goalP{};

    size_t tilesCount = 0U;
    size_t arrowCount = 0U;

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

        if (line.empty()) {
            std::cout << "WARNING: empty line\n";
            continue;
        }

        static std::set<char> acceptedChars{'#', '.', '<', '>', '^', 'v'};

        if (!std::all_of(line.cbegin(), line.cend(), [](const char ch) {
                return acceptedChars.count(ch) > 0U;
            })) {
            throw std::invalid_argument(errorLine + "some unexpected character");
        }

        if (lines.empty()) {
            rowsLength = line.size();

            // look for the single start
            auto posPath = line.find('.');

            if ((posPath == std::string::npos)
                || (line.find('.', posPath + 1U) != std::string::npos)) {
                throw std::invalid_argument(
                    errorLine + "multiple dots '.' in first line as start");
            }

            startP = Point{posPath, 0U};
        } else if (rowsLength != line.size()) {
            throw std::invalid_argument(errorLine + "line length different from previous ones");
        }

        --arrowCount; // against overflow (despite not really a problem)
        for (const auto ch : line) {
            switch (ch) {
            case '#':
                break;
            case '.':
                ++tilesCount;
                --arrowCount;
                [[fallthrough]];
            default:
                ++arrowCount;
            }
        }
        ++arrowCount; // restore

        lines.push_back(std::move(line));
    }

    if (lines.size() < 2U) {
        throw std::invalid_argument("The number of lines in the field is less than 2");
    }

    const auto& cLines = lines;

    const auto movePoint = [&lines = cLines](
                                Point& p,
                                Dir d,
                                Coord stepMoreThan1 = 0U,
                                bool acceptBeyond = false,
                                bool toroidal = false) {
        static const Coord nRows = lines.size();
        static const Coord nCols = lines[0].size();

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

    static const auto getArrowDir = [](const char ch) {
        switch (ch) {
        case '>':
            return Dir::Right;
        case '<':
            return Dir::Left;
        case '^':
            return Dir::Up;
        default:
            return Dir::Down; //'v'
        }
    };

    const auto nRows = lines.size();
    const auto nCols = lines[0].size();

    {
        // look for the single goal
        const auto& lastLine = lines.back();
        auto posPath = lastLine.find('.');
        if ((posPath == std::string::npos)
            || (lastLine.find('.', posPath + 1U) != std::string::npos)) {
            throw std::invalid_argument("multiple dots '.' in last line as goal");
        }
        goalP = Point{posPath, nRows - 1U};
    }

    // search longest path with dynamic programming.
    std::map<Point, PosCount> maxPathFrom;
    maxPathFrom.emplace(goalP, 0U);

    std::map<Point, Point> nextPointsBack;
    nextPointsBack.emplace(goalP, Point{nCols, nRows});

    std::set<Point> knotTiles;

    size_t numCycles = 0U;
    bool cyclesExist = false;
    while (!nextPointsBack.empty()) {
        if (tilesCount < ++numCycles) {
            cyclesExist = true;
            break;
        }
        std::map<Point, Point> newPointsBack;

        for (const auto [p, pSource] : nextPointsBack) {
            PosCount currMaxPath = maxPathFrom[p];

            // look around for paths or anti-sloop directions
            currMaxPath++; // for near points.

            size_t multipleNear = 0U;

            Dir dir = Direction::Up;
            for (auto d = 0U; d < FourDir; ++d) {
                Point pNear = p;
                if (movePoint(pNear, dir) && (pNear != pSource)) {
                    bool okPoint = false;
                    switch (lines[pNear.y][pNear.x]) {
                    case '.':
                        okPoint = true;
                        break;
                    case '#':
                        okPoint = false;
                        break;
                    default:
                        okPoint = (dir != getArrowDir(lines[pNear.y][pNear.x]));
                        break;
                    }

                    if (okPoint) {
                        ++multipleNear;

                        const auto [itM, newPoint] = maxPathFrom.emplace(pNear, 0U);
                        if (!newPoint) {
                            okPoint = (currMaxPath > itM->second);
                        }
                        if (okPoint) {
                            itM->second = currMaxPath;
                            newPointsBack.emplace(pNear, p);
                        }
                    }
                }

                rotateDir(dir);

                // TODO: check infinite... in realtà era un controllo da fare !
            }

            if (multipleNear > 1U) {
                // not a performance problem for the case of start tile, as the start
                // cannot have more than one near element (that is also scrolled
                // as equivalent to the source).
                knotTiles.insert(p);
            }
        }

        nextPointsBack = std::move(newPointsBack);
    }

    if (cyclesExist) {
        // need a general algorithm
        throw std::runtime_error(
            "cycles exist: run algorithm of part 2 with parameter runPart1=true");
    }

    PosCount res = maxPathFrom[startP];
    if (res == 0U) {
        std::cout << "No good path from start to goal!\n";
    }

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Tiles (including arrows) count " << tilesCount << std::endl;
    std::cout << "Arrow count " << arrowCount << std::endl;
    std::cout << "\nResult: " << res << "\n\n\n";
    return res;
}

int main23p1()
{
    try {
        day23Part1(Input, false);
        // day23Part1("./23_input_file.txt",true);
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
Lines count 23
Tiles (including arrows) count 191
Arrow count 22
Result: 94

Real input:
Lines count 141
Tiles (including arrows) count 9316
Arrow count 118
Result: 2154
*/
