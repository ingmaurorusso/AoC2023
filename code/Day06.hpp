#include <string_view>

namespace Day06{

constexpr std::string_view Input =

false ?

"Time:      7  15   30\n"
"Distance:  9  40  200\n"

:

"Time:        47     98     66     98\n"
"Distance:   400   1213   1011   1540\n"
;

} // namespace Day06

unsigned long day06Part1(std::string_view streamSource, bool sourceIsFilePath);
unsigned long day06Part2(std::string_view streamSource, bool sourceIsFilePath);