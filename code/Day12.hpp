#include <string_view>

namespace Day12{

constexpr std::string_view Input =

false ?

"???.### 1,1,3\n"
".??..??...?##. 1,1,3\n"
"?#?#?#?#?#?#?#? 1,3,1,6\n"
"????.#...#... 4,1,1\n"
"????.######..#####. 1,6,5\n"
"?###???????? 3,2,1\n"

:

"??#??#????## 2,7\n"
"..?##????????.?#?.? 10,2\n"
"#??.???..? 1,1,1\n"
"#??.#??.??#?#????#?# 2,1,6,3\n"
"?.#??.????..?.??? 1,2\n"
"#???##?.???#? 2,3,5\n"
"?##??#????.??. 2,3,2\n"
"??.#??#?????##? 2,1,3,4\n"
"?#????#?#.. 2,1,3\n"
"?#???#???##?#??? 2,11\n"
"#?##??.#??#?? 6,2,1\n"
"#.?#????#?#.?? 1,2,5,2\n"
"????#?#?#???? 1,6,1,1\n"
".?????.??? 2,1\n"
"????????.?#.??? 5,1,1,1\n"
"????..???????.??? 1,1\n"
"?#???#??#??.????.# 11,1,1,1\n"
"???.#?.???#? 2,2,2\n"
"???.???.????##? 1,5\n"
"??#?#???.#??????#??? 1,5,3,3\n"
"???.???.????. 1,2,1,1\n"
"????#?...????. 4,1\n"
"?.????#??#? 1,7\n"
".?#?.?.##?.?????? 1,3,2,2\n"
"????.?????##?.# 3,8,1\n"
"????#..????? 1,1,3\n"
".?#???.#????. 1,2,1,2\n"
"????.??###.#??.??? 1,1,4,3,1\n"
"?????????? 1,1,1\n"
"?#.??#...???? 2,1,1\n"
"?#????#?????? 7,3\n"
"?????.#####??? 1,6\n"
"?..?##.#?????? 1,2,4\n"
"#??#?#???????????#? 1,4,1,4,1,1\n"
"??#??###.???#??. 3,3,3\n"
"??????.?#??.?? 3,2\n"
"?#???#??#??..?# 6,1,2\n"
"#.??.??##?????#?? 1,1,10\n"
".?#???#?.? 2,4\n"
"???..????## 2,1,2\n"
"??????????????? 1,3,1\n"
"??##???????### 1,6,4\n"
"?#??????.??? 2,1\n"
"??#??????#???? 5,2,2\n"
"?#.??#???#?? 2,2,1,1\n"
"??#?????#???????. 2,1,1,4\n"
"?#?##??#?.. 4,3\n"
"##?????#??.??? 9,1,1\n"
"??.?...????#???#? 2,9\n"
"?????????.? 3,1\n"
".???.??#?.????? 2,4,1\n"
"#?##.?#?#????? 4,1,6\n"
"????#??#?#??? 1,8\n"
".??.?.###?????? 1,7\n"
"??##????#. 4,1,2\n"
"???#?.???. 2,1\n"
".?##?##?#?.?#????# 7,3,3\n"
"#????..####??.#? 2,1,4,1,1\n"
"#..#?#?????#??? 1,9\n"
"#.??????.?#??#..???# 1,6,1,1,1,1\n"
"???????##?#???#.??? 1,1,5,2,2\n"
"?#????.???#? 5,3\n"
"#.?#?##??????#?#?? 1,14\n"
".????..?.#???#. 1,1,1,2,1\n"
"?#????#???.#????? 8,1,2\n"
"????#?.??#??????. 1,3,7\n"
"??.??.?.???? 1,1,1,1\n"
"??#????..??? 2,1,1,2\n"
"?.??#??#??#?.?.???# 10,2\n"
".?#.??#??.? 1,5\n"
"?.##????????##?? 4,1,3\n"
".?.??##?#??? 1,6\n"
"?????#.??? 1,1,1\n"
".#?#???#???? 4,3,1\n"
"????#??.??????? 1,3,1,1,1\n"
"???#?.??#?##?# 3,7\n"
"?#?#?#???????? 8,1\n"
"??.?#????? 1,2\n"
"?#???#????.??????? 1,1,3,1,1,1\n"
"##???.???.? 3,3\n"
"####???????.???? 4,3,1\n"
"??#?##??????? 6,3\n"
"?..??????? 3,2\n"
".?#??###????#? 8,3\n"
"##?###????? 8,1\n"
"?.?#?????###??.??#?? 10,1\n"
"??????#?????? 3,1,1,1\n"
".#???#?#?.?????? 1,5,1,2,1\n"
"???.#???#.??#?#?. 1,2,2,5\n"
"..???#????### 1,2,4\n"
"????#???#????. 1,7,1\n"
"??????#????#.? 3,7,1\n"
"???#???????#?...? 4,5,1\n"
"#????????##?# 1,3,4\n"
"?.#???.???#??. 3,4\n"
".???????.??????.? 4,2,1,3\n"
".?.??.???? 2,2\n"
".???.??????###?#. 3,10\n"
"????..?????## 2,1,2,4\n"
"#?.???#??.??? 1,4,1\n"
"?????..???? 1,4\n"
"??????#.????????? 3,1,8\n"
"????#??????? 5,1,1,1\n"
"????#?#??#????? 1,4,1,2,1\n"
"?#?.???#???.? 2,6,1\n"
"?.???#??.?#. 1,1,1,1\n"
"??.#.#.??????#???? 1,1,1,10\n"
".##?.?????.. 2,2,1\n"
"???#?#??#??#??#? 5,1,1,1\n"
"?#.?.????????????#? 1,1,10\n"
"??#?????.. 3,1\n"
"?#.?#?#?????.?????? 1,2,3,1,4,1\n"
"?#???..#?.??#?#. 2,1,2,1,1\n"
".????#????.?#?????# 7,1,3\n"
"..###??#???#???.??? 10,1,1\n"
"??????##?.?#?#.#??# 4,3,2,1,2,1\n"
"?.???####.?#?? 4,2\n"
"?#.???#???#??##?#?? 1,15\n"
"?.?##?#?#? 5,2\n"
"?#???#?#??????##??? 9,3\n"
".??????????.??. 6,3,1\n"
"???????.#? 1,2,1\n"
"????#?#??#?#.. 5,6\n"
"?????.?.?#????? 2,1,5\n"
"????..??#?#?#??.???? 3,8\n"
"#???.?.??????. 1,2,1,2\n"
"?????????.???????.?. 1,2,3,4,1\n"
"????????##???? 1,7\n"
"?.??#.?#??#? 1,1,5\n"
"#??????#?##??? 3,9\n"
"???#??.?.#?#??### 4,8\n"
"?.##??##?#??? 2,7\n"
".?.#?#?????.#?#??.? 1,8,1,1,1,1\n"
"?.???#.?????? 2,2\n"
".#.??##???.#??.??. 1,5,3,1\n"
"??#???##?? 1,1,4\n"
"??????#??##?#. 2,8,1\n"
"????#?????.???.?.? 6,1,3\n"
".?.#.?##.??.????#? 1,1,2,2,2,2\n"
".??#?.???? 4,1,1\n"
"?.?#?##??##?#??.?? 2,8,1,1\n"
"#???##???.??. 1,2,1,1\n"
"?#???##??.??#??? 3,3,5\n"
".???#??#??? 1,5,1\n"
"?#.?????#???. 2,7\n"
"?.???#????????.?. 1,1,1,4,1\n"
"??#??#.??#??? 4,1,2\n"
"???#.????#???##???? 2,12\n"
"..??????.??#??#?? 2,6\n"
"??#?.?#?#???..??#?? 3,4,1,1,2\n"
"?#????.#?????#?. 2,3,3,3\n"
"?????#????.? 2,3,1\n"
".?.?????.?.##.? 5,2\n"
".???.???.???#?? 1,2,3\n"
".????.?#?#???.??. 1,7,2\n"
"???#???#??????.. 1,9,1\n"
".#???#?.?? 1,2\n"
"##?#??#?##??????#??# 2,7,8\n"
"?.?????#????##??.?? 1,8,2,1\n"
"??????#.##??##?##?## 3,1,9,2\n"
"???#?#?#???#? 1,7,1\n"
"???#????.?????? 6,1,1\n"
"?.##?#.?#?.?. 1,2,1,2\n"
".????.?..?????? 1,2,1,3,1\n"
"?.??????.. 1,1\n"
".?????.?#??. 1,4\n"
"???.??????... 2,1\n"
"?#?#?#?#.?..#..??? 6,1,1,1,1,1\n"
".??..?#???? 2,1,1\n"
"??#?????????#?..??? 10,2,1\n"
"?.???.?.?.?.#? 1,2,1,2\n"
"#?.?#?.?#???.??????# 2,2,2,1,2,2\n"
"????..??####???#?? 4,1,10\n"
".????..??#?? 1,3\n"
".#??#?#?.?.##. 6,2\n"
"??#?#..?.??#?#??# 2,1,1,5,1\n"
"??##??#??###??..??? 3,7,1,1\n"
"????.#.???..??. 1,1,1,1,2\n"
"#?.??..??. 1,1,1\n"
".#??????#?.????? 1,5,3,1\n"
"?.???#?..??#??? 4,4\n"
"?????##?#..#???#?? 7,1,1,1,1,1\n"
"?????????? 5,2\n"
"????.????.?#?.. 1,1,3\n"
"????????????#????#? 4,2,5,4\n"
"???#???.??##? 1,1,1,5\n"
"?##????????#????##?. 2,7,3\n"
"???..??#?? 2,3\n"
"#.?#?.???..?? 1,3,3,1\n"
".????????? 2,1,1\n"
"???????????##? 6,1,2\n"
"?..#????#?? 2,3\n"
"????.??..#? 3,1,2\n"
".#.?????#.?#?? 1,2,1,3\n"
"????????.?# 7,1\n"
"?????#?#??##??#???? 15,2\n"
"?#.??.?????#?? 1,1,7\n"
"??????#????#?#????? 8,1,7\n"
"#..????#???. 1,4,1\n"
"##??#.??????. 2,1,2,2\n"
".????.#?#####?. 1,1,7\n"
"#????#???..?????? 9,4\n"
"???#??.#?.# 3,1,1\n"
".?#?#.?..???? 4,2\n"
"??...??.?#?##??? 1,2,8\n"
"?.??#?????..???.?.? 5,1,1\n"
"?.?##??.?#?##????# 5,5,3\n"
"??#?????##??????? 9,1\n"
"???#????#? 1,2,2\n"
"?.?????????#?#?.?#? 1,3,7,2\n"
"???.?#??##?#?? 1,1,5,2\n"
"?????.#.?? 3,1,1\n"
"?#???#???..??.##??? 2,6,1,5\n"
"#??#????????? 2,1,3,1\n"
".#??.?.??.?#. 2,2,1\n"
".???#???????#??##??? 12,2,2\n"
"##?#?#???###???????? 13,1,1,1\n"
".?#.??##?????.? 1,3,2,1\n"
"#????.???#????. 1,1,3,2\n"
"##????????? 2,1,2\n"
"?#?..?#????.??? 3,6\n"
".?..??.??#??#?#? 1,1,7\n"
"?????????.???.? 1,1,1,2,1\n"
"??.????#.???? 1,1,1,2\n"
"###?##.??? 6,2\n"
".?#####???????.#??? 5,6,4\n"
".???.??????????? 1,2,1,1,2\n"
"?????#?#?#.??#??? 6,1,1,2,1\n"
"??.??#???.. 2,1,1\n"
"#..?.?.##??. 1,1,3\n"
"?##???.?.? 4,1,1\n"
"????????##??????.??# 1,10,1,1,1\n"
"???#.???.?????? 1,2,1,2,2\n"
"????????????.????#? 1,3,3\n"
".?.?????..?#?? 1,1,1,3\n"
"?..???##????##? 1,9\n"
".??????#??? 1,2,5\n"
".#?????.?..#???## 1,3,1,1,3\n"
"#????.???.? 5,1,1\n"
".?#.?????#??##??? 1,12\n"
"???.?#???.?#?? 2,4,4\n"
"?.?.??????.?????#?? 1,5,8\n"
"???##?#?#?.#. 4,4,1\n"
".#.???.????#????? 1,6\n"
"??#?##???#??.????? 9,2\n"
"?.?.###??##?#?? 1,11\n"
"???.?.???.? 1,1,2\n"
".?#?????#? 3,2\n"
"?.??#??#???#?#?## 8,6\n"
"???###.?????????? 4,6,1\n"
"?.???#???#?## 1,2,2,4\n"
"??##??????..???#?? 1,3,3,1,1\n"
".??.#?????#???..?? 1,9,1\n"
"...??????? 2,1\n"
"???.?###??.????? 3,3,1,1,1\n"
"??.?#?..???#????. 2,1,1,3,1\n"
"??????..#???.#. 1,4,2,1,1\n"
"?.??##?#???##?..???. 11,3\n"
"???##?.?##??? 5,4\n"
"????.??#?????? 3,7\n"
"#??#..?#???#?.? 1,1,2,3,1\n"
"????##?#???.?#?# 2,6,4\n"
"?#???.##????.? 3,6\n"
".?#????.#????.?.#? 4,1,1,1,2\n"
".??##?#.????#.. 6,3\n"
".#?#??..?? 3,1\n"
"#.?.??..??.?? 1,2,1,1\n"
".?????????#???#????? 1,10\n"
"?#.#..#?#?#?#????#?? 2,1,3,1,8\n"
"??????#????# 6,3\n"
"??????..#??#?. 1,1,3\n"
"?.??#.??????#?. 1,1,3,1,2\n"
"???..##.??##?.????? 1,2,5,2\n"
"??????..???# 2,2,1\n"
"?????#?.????..?#??#? 4,3,2,3\n"
".??#??????????#??? 11,2,1\n"
"??.??..?????.?? 1,1,5,1\n"
"#?###?.????????##?? 1,4,9\n"
".?#?#???#??.# 9,1\n"
"?????#.??#??#. 1,3,3,1\n"
"????#???#??#?.?????. 6,1,2,5\n"
"????????.##?# 1,1,2,1\n"
"??#?##??????? 8,2\n"
"???.???#?#????#??. 1,1,6,2,1\n"
"#??.#??????#? 2,1,3,1\n"
".###??.??.? 4,2\n"
"?????.??#. 3,1\n"
"??????.#..?# 4,1,1,1\n"
"?.#??#?.??##?##???? 4,8\n"
"??????#?#???? 2,6,1\n"
"???..###???..??????? 1,1,4,1,2,1\n"
"??..?.???#?? 1,1,1,3\n"
".??#?#????.?.#??#??? 3,1,5\n"
"??????.??? 1,1,3\n"
"#?.???#??.??#?. 2,5,3\n"
"??#??##??.? 6,1\n"
"?#?????????#?? 1,10\n"
".????#.??? 4,1\n"
".?###?..?#?#??? 5,5,1\n"
"??#??#.?#????.?. 1,1,1,3,1\n"
".???#???#???????? 1,9,1\n"
"???..?????? 1,2\n"
"??#?.#??##?. 3,2,2\n"
"?#?#????.?? 4,2\n"
"??#????.##??? 6,4\n"
"???#.??.?#?###?.#?? 2,1,6,3\n"
"???.?#?##?.? 1,5\n"
"?#.?##?.?? 1,4\n"
"????###??? 1,4\n"
"???##????#?# 1,3,1,3\n"
"##???????? 6,2\n"
"????#??.####?.? 2,2,1,4,1\n"
"#.??#????#???.???? 1,11,1,1\n"
"?#??????.? 1,1,1\n"
"#..?.?#?.??###??.? 1,1,3,5,1,1\n"
"???.??#??#?#?##?? 1,12\n"
"??????#??#?##?? 1,2,7\n"
"???#???.??.???#? 4,1,5\n"
"?????#?????#.?#?#??? 3,1,1,2,5\n"
"#??.????#? 3,1,3\n"
"???????????...# 8,1\n"
"#??#.#.?..????.? 1,1,1,1,4\n"
"?#????.??.?. 1,1,2,1\n"
"?.??##?.?.???#????.. 5,5\n"
"?#??#????.##.## 2,2,2,2,2\n"
"?.#????.?? 2,1,1\n"
".#??????????? 1,6\n"
"??#.??.#????.??#.??. 2,2,1,1,3,2\n"
"??#?#??.??#??? 5,1,2\n"
"???#?#??.???.??? 6,2,1\n"
".??#????...?????#.? 6,1,2,1\n"
"??.???????.?#??? 2,2,1,4\n"
".?.??????? 1,1,1\n"
".????..??#?#? 2,5\n"
"?.?#?##.???.?#??# 1,5,2,1,1\n"
".#??#?.??#?#??.?#??? 2,1,1,5,2,1\n"
"?.#??..????#?????#.? 2,10\n"
"???#???.?#.???????? 6,1,1,3\n"
"?.??#?###??.??##???? 1,8,4,1,1\n"
"?????#.??##? 1,2,1,2\n"
"..??.##.?.???# 1,2,3\n"
"??#?.????#???????? 2,10\n"
"?#??????#??.????? 7,1,1,1\n"
"#???.?#?.???.??#?? 1,1,2,1,1,5\n"
"??##????.#.#?.#?. 6,1,1,1\n"
"?#???#??????????.?.? 1,11,1\n"
"??#????#???#???. 3,1,8\n"
"?#???????.#??? 2,1,2,1\n"
"?.#???????.?? 1,1,2\n"
"???.????#????#???#? 3,1,4,4,2\n"
"????.#??##???#?.### 1,1,6,2,3\n"
"??????.?#?#?#?? 2,1,8\n"
".??????.#? 3,1\n"
"#??????.????#.????? 1,1,1,2,1,4\n"
"???????????????.??# 1,1,7,2\n"
"#??.????#?#??.??#?#? 1,7,6\n"
"??#?????????## 5,4\n"
"????.??#?.. 1,2,4\n"
"#?#??.#?#.?? 1,2,3,2\n"
"..?#?#?.?#??????#?? 3,1,7\n"
".?????#??###..?#?? 1,6,3\n"
"?.#?#????.????###. 1,5,1,1,1,3\n"
"?????####?##?.#.??? 10,1,1\n"
".?##???###???. 3,1,6\n"
".??#.?.???.?.?.?? 1,2,1,1\n"
"?#????.???.?? 6,1,1\n"
"??#.?????#? 1,1,2\n"
".??#?.?.#????? 3,1,1,1\n"
"??.?????????# 1,3,1,1\n"
"?#.#?????.?????? 2,1,1,5\n"
".????#??..????#? 1,1,3,4\n"
"?????..#?.#??# 4,1,4\n"
"??.????##?..?#?? 1,2,3,2\n"
"???##??.#?##???? 1,2,1,5,2\n"
"??#???????#???#? 4,8\n"
"#?#??#.???????#?. 4,1,2,1,2\n"
"?????#?#??.??.??? 1,5,2,2\n"
"?#???#???.? 1,2,1\n"
"????.?##??#???#??##? 3,7,5\n"
"#?????#?.#? 1,3,2\n"
".??#?####?##?#??? 11,1,1\n"
"####??#.###.??.?? 4,2,3,2,1\n"
"#???.??#?#??# 1,1,5,1\n"
"?##.?????. 3,2\n"
".?.????????#? 1,2,2,3\n"
"??????#??.??#?#?.? 8,5\n"
"??.?...?..?.??.?.?.? 1,1\n"
".#??.???#.?#?#?? 2,1,1,6\n"
"?.#??##??#???????? 1,1,2,4,1,1\n"
"##?.?.##??????#??.?? 2,10\n"
".?????##????.?.??#? 1,6,1,1,2\n"
".##??#?#??##?#??? 2,8,2\n"
"??.?#.??#?.???#??? 1,2,2,5\n"
"?????.?????????#?.? 1,1,3,2,2,1\n"
".#?##???##??.?.# 9,1,1\n"
"??????#???????? 7,2\n"
"#?????.?????#?. 1,2,1,1,1\n"
"?.#?????????#.#?# 1,1,4,1,3\n"
"?.??#??#??#??#.. 1,2,2,1,2\n"
"??.##??????#?????. 1,2,2,1,1,4\n"
"#?.?????#?.?##?? 1,2,2,5\n"
".?#?#?#?.?.# 6,1\n"
"#.????#?#??# 1,6,2\n"
"??.??????? 1,2\n"
"???#?.?..??.??#????. 2,2,4\n"
"??????#??????? 2,2,4,1\n"
"?.????#?..???? 5,1\n"
"???..????.?????? 3,1,3\n"
"???.???#??. 1,1\n"
"?...?#?.??.?#?.? 2,3\n"
"???#..??..#?#??. 4,2,3\n"
"..?????#??? 4,1\n"
"???##?.#???#?? 6,3,1\n"
"????#??.??.. 5,1\n"
"??????#??? 3,2\n"
"??????????#?????? 3,3\n"
"?????.??#??#??? 3,8\n"
"?#?##..?#.?#? 1,2,1,2\n"
"#???##?#????. 10,1\n"
"??????.???#??? 2,2\n"
"?????###??.???. 9,1\n"
"??##???#????.?#??#? 1,2,5,1,1,2\n"
"?.?????#??#.?? 1,5\n"
"?#...???#?#??#?. 1,9\n"
"???.#?????????.???# 3,6,2,1,1\n"
".?#?#????.?? 7,1\n"
"??.#?.#??#??.?? 1,2,1,1,1\n"
"????????##?..? 1,1,5,1\n"
"?????????????.?.?. 3,5,1\n"
"??#?.#?????? 1,1,1,1\n"
"?????????#..??#? 3,6,1,1\n"
".?.??..?.??.?.???.?. 1,2\n"
"????#???.?###...???? 6,4,1,1\n"
"???#?#??#??????..??. 13,2\n"
".##???.?????? 4,2\n"
"??????????? 7,1\n"
".???.#?#?##?.???. 1,6,1,1\n"
"?????.#?.??#???# 3,2,1,2,1\n"
"?????#?#?###??##??# 1,1,1,5,6\n"
"???...?#?.#??#?. 2,2,1,2\n"
".?#???????? 2,1\n"
"?.?##????????? 1,5,1,1\n"
"..??????##?#???.?? 3,8,2\n"
"?????.?.??????#?.?? 1,2,3,1,2,2\n"
"??#..??##?.# 1,3,1\n"
"#?#??..??#.?.?#?.??? 5,3,1,3,1,1\n"
"?????#??#??#? 1,2,1,1\n"
"??.#???#?#???#?..??? 12,1\n"
"??#?#..???#??? 3,1,1,1\n"
"?.??.??.#??#???#?#?? 1,11\n"
"??#.??#??#??.?? 1,5,2\n"
"?#???#?#?#?????.?? 10,1,1,1\n"
"?#???#?????##?. 7,4\n"
"???##??#?#.???.??. 5,1,1,1,1,2\n"
"????.?????#??? 3,1,3,1\n"
".???#?.??#?.????# 3,2,5\n"
"??#?????#????#??#??? 4,2,8\n"
"?????#???.#?#??? 1,3,1,3,1\n"
"?###.???#?????.#? 3,5,1\n"
"#.?##..??.#???. 1,2,1,1,1\n"
"??#?#??????.#?..?.?? 8,1,2,1,1\n"
"????.?????.????#??? 1,1,3,2\n"
"?#?#????#????#??# 6,1,1,1,2\n"
".???#?#???#?#?#????? 15,1\n"
"..???##.??. 1,3,2\n"
".???#.?#??#???? 4,1,2,1\n"
"????????#?#?#??##.? 2,11\n"
"??.?.??????#??. 3,3\n"
"??.???###????##??? 1,10\n"
"#????.?#??.??.??? 5,3,1,1\n"
"?.????????##.? 1,5,2,1\n"
"???#?##??#??. 2,4,2\n"
"?.#??.??#??#?#? 1,1,8\n"
".##???.?#???. 4,1,1\n"
"??#.????.?.#??#? 2,2,1,2,2\n"
"???##????# 1,5,1\n"
"#???????#?..?#??? 4,5,3,1\n"
"??.?????.???? 2,1,1,2\n"
"??.???.?????.???#?? 1,2,2,1,5\n"
"??.??#??#?#?..??. 1,7,1\n"
"?#???#?##?..?.?????? 9,5\n"
"#?##?#????..#? 6,1,1,1\n"
"#????.???. 3,2\n"
"?????##.?..??##????? 6,4\n"
"??????.??.??? 2,2,1,1\n"
"??????#?.??# 1,2,3\n"
"????#?????## 1,1,1,2\n"
"..#????#??#????. 2,2,2\n"
"?#.??.??????? 2,1,1\n"
".#???????#.?#?##.. 1,1,1,1,4\n"
"?????#....?.# 3,1,1\n"
"???????#??.?#?#?? 1,2,3,4\n"
".???#??#?? 3,1\n"
"??#??#???##??.#????? 1,11,1,1,1\n"
"??????#.#? 1,4,2\n"
".???#?.#??.? 1,1,2,1\n"
".?#?#????#.# 9,1\n"
"?#?.##???.?.?#.#?? 3,4,1,2,1,1\n"
"????.???.???..??? 3,2,1,1,1\n"
"#?#??..????.?????# 1,2,2,1,1,1\n"
".??#??.#?#??#???? 1,1,1,6,3\n"
"?#?????????????#??? 2,1,3,9\n"
"?????#.?????? 1,1,1,4\n"
"?.??#???#?.#????. 1,3,2,1,1\n"
"??..#?#?.? 1,4\n"
"????#?????#. 3,1,4\n"
"??.?##??#?###??#???? 1,15\n"
"????.??#?.?..? 3,3,1\n"
"#?.??.??#?####?? 1,1,1,8\n"
"?#????##??????????? 14,2\n"
"?#????.#??.? 1,2,3\n"
"???.##?????#?????? 2,2,1,3,1\n"
".?????????##?.# 1,8,1\n"
"??.???????? 1,2,2\n"
"??????#?#? 2,1,1\n"
"???????.#?? 1,3\n"
"?...?####????.?#?? 1,4,2,1,1\n"
".?##?#??????? 9,1\n"
"????.???????#???#?? 2,9\n"
"?????.?.????? 2,2\n"
"????.?????. 1,1\n"
".?????????###.??.? 11,1,1\n"
"????##?????.?? 1,2,1,1\n"
"???#?.#??##???#?#?.. 4,1,2,5\n"
"???????#??.??. 3,1,1,2\n"
".??????????#??#?? 4,6,3\n"
"??.?????..?.?##?#??? 1,1,2,1,4,1\n"
"??#..??.????? 2,1,1,1\n"
".#??#??.#??#? 1,3,5\n"
".?????##??????.? 3,6,1\n"
"##?.?#..?. 3,1,1\n"
"?.#.??????#?????#?? 1,12\n"
"#??.????.?# 3,1,1\n"
"#.#?#.##??#?..???? 1,1,1,6,1,1\n"
"????#???.???#??.. 3,4\n"
"???????.##??.???? 2,2,4,1\n"
"??#??#?.####???#??? 4,10\n"
".????###???###???? 6,6\n"
"???.??????. 1,3\n"
"??##..?#??#??###? 2,3,1,5\n"
".????#?#????.#? 9,1\n"
"??.???#.#????????? 4,1,2,2\n"
"???#?.????#?# 1,1,4,1\n"
".#?????.#??? 2,1\n"
"??????...???????#??# 5,2,1,5\n"
"#.?????###?????. 1,2,6\n"
"??##..????..?# 3,2,2\n"
"##???????.?#?. 2,2,1,3\n"
"??#?.#.??#.? 1,1,1,1\n"
"??##.??????..?.??. 4,1,1,1,1,1\n"
"??##?#?????????#?#?? 3,8,1,1\n"
"???????#????.????#?. 8,1,1,1,2\n"
"??????????#????#?? 1,2,11\n"
"???#??.??#. 5,2\n"
".??????????# 3,1,2\n"
"??#.?????##?#???. 1,10\n"
"?.#???#?#???#????# 1,1,4,2,1,1\n"
"#????.?#?????#??? 2,2,9\n"
".???#???##? 1,3,3\n"
".??.??#???#? 3,2\n"
"???#???##??#???.??## 14,3\n"
"???##?##??.##?.?.#?? 2,6,3,1,1\n"
"???###????#???? 6,6\n"
"??.?.?#?##?##?#???? 1,1,1,5,5\n"
"?#???..?.???#?#.?? 5,1,4,1\n"
"#?????#????#???#??? 4,1,1,1,5\n"
"??#.???#????#???? 1,5,1,2\n"
".??#?#???? 5,1\n"
"?.???..#???#?? 1,2,5,1\n"
"???#?##????..???##? 7,4\n"
"??..#?.???? 2,2,2\n"
"?.??#?.##?????#? 4,5,2\n"
"?.?##???##??##?#?. 9,4\n"
"??#?#??..#??????? 6,4\n"
"???#??.??.? 4,1\n"
"?..#?#?#?????????#? 1,6,1,2\n"
"???.#?..?? 1,2\n"
"??????????.?.#?. 4,2,1,1,1\n"
"#..??.???###?.?.? 1,1,6,1,1\n"
"??.?????#?#??#.?? 1,1,6,2\n"
"?.?##???#?? 3,2\n"
"??.???????? 1,5,1\n"
"?.#???#????#??## 1,1,5,1,2\n"
"???????????###??? 2,1,8\n"
"???.????.?# 2,1,2\n"
".#?.??#????#.?????? 1,1,1,4,1,1\n"
"#???###?##?.??...? 10,2,1\n"
"..#.??????.?# 1,1,4,1\n"
"????#?????#.? 1,5,1,1\n"
"???#??#??#??# 2,1,2,2\n"
"?#??????????#? 1,1,3,1\n"
"??#??#??#?#?? 3,1,4\n"
"???.?????????#. 1,1,1,2,1\n"
"#??##??.?#? 5,1,1\n"
"..?##???#?#???? 2,6\n"
"#??????#?.?? 2,1,2,1\n"
".###???.??###??#?? 5,10\n"
"?.????..?????#??? 4,3,2,1\n"
"???##??????? 1,3,1,2\n"
"????.?.####??####??? 1,11\n"
"??##???.?? 4,1\n"
"??#?.?????# 1,3,1\n"
"??.???...#..?. 1,3,1,1\n"
".##?#??#?#??#??#??? 2,1,5,1,4\n"
"?#.????#??????????## 1,1,2,10\n"
".#?.??#???? 2,5\n"
"?#?.#?????.??.? 3,4,2,1\n"
".#?????.?..?? 6,1,1\n"
"###????????###? 6,3,3\n"
"#??????.??#?#? 4,1,6\n"
"??????#?????? 1,2,1\n"
".?#.???#??????????#? 2,1,2,1,2,2\n"
".????#?????????? 5,5\n"
".??????????. 5,1\n"
"?????????.?#?? 2,5,1\n"
".?#??.?.?? 2,1,2\n"
"?.#.?#?#?. 1,4\n"
"??##.??##?#??###?? 3,5,3,1\n"
".????..??#?.? 1,1,4\n"
".???#?????# 1,3,3\n"
"??????.?????##???.? 6,7\n"
"???#?###?.??#?##??# 6,9\n"
"##???#?.#?..#?????. 6,2,3,1\n"
"???????#?#????#.?.?# 3,11,1,1\n"
"?#?.??#??#? 2,3,2\n"
"???#?????.?? 7,1,1\n"
"?.???????#?#??.?.#? 4,2,3,2\n"
".#.?#.??#??????? 1,1,1,5,1\n"
"?.##??????????? 7,1\n"
"?.?#????????.? 6,1\n"
".##??#?.???? 2,1,3\n"
"#?.#?#?#????.? 1,1,6\n"
"?##???#??#.???.? 6,1,1,1\n"
"???????#?? 2,1,1\n"
"..?#????#???#?? 1,1,3,4\n"
".?.#??##?#.?#??..#? 1,1,5,1,1,1\n"
"?#?##?#????. 6,1,1\n"
"#?#?????#?##???#?#?# 1,4,12\n"
".????#???? 1,2,1\n"
"?..??.???. 1,1\n"
".????????????.???? 4,1,1,1,1,1\n"
"??.??##???.?#?? 2,4,1,2\n"
"?????#.##???#??#?.? 1,3,4,1,1,1\n"
"??#?.?#??##. 1,2,6\n"
".???.??#?#.#????##.? 2,3,1,7\n"
".?.????????. 3,3\n"
"?????#.?.#...? 2,2,1,1\n"
"??????.##????..?. 3,4\n"
"?#.??????#???### 1,1,9\n"
"??..???#.??##????#?# 2,1,1,10\n"
"?????#?..#?. 3,2,1\n"
"???????..?# 2,1,1\n"
"???#???#?? 1,3,2\n"
".#?#??.?????????.? 5,1,1,1,1\n"
"?.#?.?.??????# 2,6\n"
"???#.??????? 1,1,1,3\n"
"?#???#?????.#?? 3,5,2\n"
"???#???????.?? 1,6,1,1\n"
"..?#????#.. 1,4\n"
"?????.???# 1,1,3\n"
"??#.?????????..? 1,1,1,5,1\n"
"??##??...??#??? 6,3\n"
"#??#????#? 2,2,1\n"
"?#???##.##???? 6,2\n"
"?.?#????.?#?.????# 1,3,1,3,1,3\n"
"??.##??#?????????.. 1,8,1,1\n"
"?###?##.?????#?.???# 4,2,1,4,3\n"
"???.???????.#.??? 2,1,3,1,2\n"
"??.???#????. 1,4,1\n"
".?##?????##???.???? 13,2\n"
"??##.???????#??#??#? 2,1,2,5,2\n"
"#??????##???. 2,1,3,2\n"
"#.???????? 1,1,1\n"
"?#?.#.?#??.??????? 1,1,4,1,3\n"
"?????#??#??? 2,5\n"
"??.??#?#?? 2,5\n"
"?.#?#?#?????????. 1,9,2,1\n"
"??#??.?##.??#.??? 1,3,1,1,3\n"
"???????.?????? 4,6\n"
"#?.?#??#?????.??? 2,9,1\n"
"#??#??#?.??#????# 5,2,4,1\n"
"?#.#?#?.?? 1,4\n"
".?.?.????#??#?? 1,1,1,2,2\n"
"?.#???????#?.?. 1,1,3,1\n"
"#.??????..?.?. 1,4,1,1\n"
"???????.#???#??.? 7,6,1\n"
"?..##???##???? 3,3\n"
"?????###?#..???#.?#? 1,1,5,1,1,1\n"
"??.????#?.?..# 2,2,1,1\n"
"????#???##??#? 6,5\n"
"#?????##??????? 1,1,3,1,4\n"
"#?.?????#?.?? 1,2,1,1\n"
"??..#?#??##? 1,3,3\n"
"???#??#???#??. 4,1,1\n"
"???.#??##???????? 3,6,1,1,1\n"
"#?###?#?##?.#?.?.?.. 1,9,1,1,1\n"
"?#???#??#?.?.#???? 1,4,1,4\n"
"????..#.?.???#??.? 2,1,1,4,1\n"
"?????##??#.??#?.# 9,2,1\n"
"????.?##??#?????..?. 2,3,1\n"
"??????.#?#???#??.??# 4,8,3\n"
"?#?##?#????????#?? 7,1,3\n"
"?#??###??#?#?#?.? 13,1\n"
"?.??##???.??????#.? 1,6,1,2,1,1\n"
"??#??#????? 3,3,1\n"
"??.??????????#.. 5,5\n"
"????????#?? 2,6\n"
"#?.??#???.#??? 1,6,1,1\n"
"##.?????#?. 2,2,1\n"
"????#??.?#???? 4,1,5\n"
".?????????????##?.? 5,3\n"
".?.???.?#??.## 2,1,2\n"
".?????????###????? 3,5\n"
".###??.##?? 5,3\n"
"?#??????#?.??#???? 5,3,3\n"
".????#??????? 1,2\n"
"??#??????..#???#?. 3,1,5\n"
".???#?#?.???.?????? 6,3,2,2\n"
"??.#??.???. 3,2\n"
"?.??.???#.?? 1,4,1\n"
".?????.???..#?? 1,1,1,1,3\n"
"#????????? 4,2\n"
"????#?...????????#?# 1,2,1,9\n"
"??#?#####???? 2,5,1\n"
".??#???#?. 3,2\n"
"?#?#?.##????#?????? 1,1,9,2\n"
"?####?????.?.???? 8,2\n"
"#???#??.??.??? 2,3,1,3\n"
".#??##?????#.#?? 7,1,1,1,1\n"
"?..????.???###????. 1,7\n"
"???##???#???.??#?#? 9,1,6\n"
"???#?????????. 3,5\n"
"#?#??#??#?. 3,5\n"
"?#??.?.???? 3,1\n"
"???###.?#.. 3,2\n"
"?????????.??? 4,1,1,2\n"
"???#??#??.? 8,1\n"
"#..??.#???? 1,5\n"
"????#??###?#?#?#???? 2,1,6,7\n"
"???????????###????. 13,1\n"
"???####?.? 1,4,1\n"
"?##.???#????##?##?? 2,1,9\n"
"???..??..?.#?#??#.. 3,2,6\n"
".#?#???.?#?##??? 1,1,1,6,1\n"
"??#?..??????#??? 1,6,1\n"
"#.????#??????# 1,8\n"
"???#??..?? 1,1\n"
"???..????????? 1,1,4,1\n"
".????.#???. 1,1\n"
"#???#?#?#?.??.#?? 9,2\n"
"#??#?##????.??.?? 10,1\n"
".?#?.?????##????#? 2,11\n"
"????#??.#???#?????? 1,4,1,3,1,1\n"
".?.??..???#?? 1,2,5\n"
".#?????.?.???#?#??#? 1,4,2,1,1,1\n"
"??#????#??#???#.??? 1,1,10,1,1\n"
".???..#??#???.. 2,7\n"
"??.#???.#?????? 1,2,1,5\n"
"????#??.??????#? 1,3,1,3,2\n"
"##?????##..???.???.? 2,6,3,1,1\n"
"??##???.??????#?? 7,4,1\n"
"#..##.??#???#??? 1,2,1,1,3\n"
"#??.?##...?? 1,3\n"
"??##?...###... 5,3\n"
"#?#??#????#??#..#? 11,2,1\n"
"???#?????#?#???#??.? 4,8\n"
"??.??????#????????? 9,1\n"
"??.??.?????# 1,1,5\n"
"???.??????#??? 1,1,3,1\n"
".?.#???.???#?????? 2,7\n"
"???##??.?#?###? 2,2,1,2,3\n"
"???????#.??.#????#.? 1,4,1,1,2,1\n"
".???#.????#.?????? 1,1,5,2,1\n"
"?.?.???###?##???? 1,10\n"
"?????.?#?.? 5,1\n"
"????????##.?? 3,5,1\n"
".???#??##?####??? 1,6,4\n"
"#?????????#?. 3,4\n"
".?.??#?.??.???.? 1,1\n"
".???#?????? 4,1,1\n"
"???#?#?..?...#???.. 4,1,1,1\n"
"?????.????##???? 1,1,1,1,6\n"
"??#..????? 1,1\n"
"?#?.?????#??#..?#. 2,2,2,2,2\n"
"????#..????? 4,3\n"
"??????????#.?. 2,4,1\n"
"??..#?????..?.#???? 1,6,1,1,1\n"
"??#?####????? 10,1\n"
"?#???#.?..?? 3,1,1\n"
"?????#????????????? 5,4,2\n"
"##??.??..?.?? 2,1\n"
".?#?#??.??####???? 6,8\n"
"##?.??#???#?#???. 3,4,3\n"
"?#.?#...?#.???.# 1,1,2,2,1\n"
"?#..????#??? 2,2,3,1\n"
"??#??????? 2,1\n"
"????..?.????#?# 3,1,1,3\n"
"?????.??.????#???#?? 1,1,1,1,2,7\n"
".?##??.?#?.? 4,2\n"
"????#??.??. 5,1,1\n"
"??????.??? 5,2\n"
"????????#?#? 2,1,4\n"
"??.?????????#??.#?? 2,5,4,1\n"
"??.??????????? 1,4,1,1\n"
"???#????.? 2,4,1\n"
"??????.?#?# 1,2,3\n"
"#???????#?. 1,4,1\n"
"????#.??#???.???.? 5,1,1,1,2,1\n"
"?#?????.??##?? 1,1,2,3\n"
"?...???????? 1,1,3\n"
".##????#.?#?? 3,2,1\n"
"#??#?.?.#??##.????? 5,1,5,1,1\n"
".???#????? 6,1\n"
"?#???????.?###??#. 2,1,1,4,1\n"
"#??????.???????? 5,1,1,1,3\n"
".?#??###?#?#?##?..?? 15,2\n"
".?.??#?######?.??.?? 1,10,2\n"
"??#???.#??#?????# 5,8,1\n"
"????.????? 4,3\n"
"??#.???.??? 1,1,3\n"
".????.##??????#?##? 4,2,2,4\n"
"??#??????###????#?.? 4,1,10,1\n"
"????#..???? 4,2\n"
"#?????????#???????.# 1,2,1,1,3,1\n"
"?#??##???.#?#.? 8,3,1\n"
"????.#?#???#### 1,1,1,3,4\n"
"??.?#?#?#?.??. 1,1,4,1\n"
"??#??????????.# 2,4,1\n"
"???#??.???##??#? 6,1,2,3\n"
"?.???#?#??#??##?.?.. 14,1\n"
"??.#??#?#??? 4,3\n"
"?#?.??????#??????#? 2,15\n"
"???.???#??.???#??. 1,2,3,5\n"
"?#?.?#?#?#?#???#???? 2,4,1,1,5,1\n"
"???????????#???. 1,1,6\n"
"??????????.?? 2,5,1\n"
".##???????.?#???? 9,3\n"
".???..?.?###? 2,1,3\n"
"?#??##??????????. 10,1\n"
"?????.????.?##?? 4,1,4\n"
".???##?.???????#? 1,2,1,6\n"
"????????????.?? 5,1,2\n"
".?#????????? 3,1,3\n"
"#?.?#?.??. 2,1\n"
"?#?#????????. 7,1\n"
"??????####???????#? 2,10,1\n"
"?.???..????? 1,4\n"
".????##??#?##? 2,9\n"
"#??#?#?#??.#.#?? 9,1,2\n"
"?#??.?###???????? 1,1,6,2,1\n"
"?###??????.?# 4,2,1\n"
"#.??#??.?##?#. 1,4,5\n"
"?????.????????? 1,1,5,2\n"
"??.?#..#?????#?? 1,2,3,5\n"
"?.??#????.?????#?# 6,8\n"
"?.??#.?##?????? 1,2,6,1\n"
"#??#.?.?.#?#?????#?# 1,1,1,1,1,9\n"
".????#??##?????#??? 9,5\n"
"?#????#?##.????? 7,2,1,1\n"
"?.??????.??? 1,1,2,1\n"
"??##???#?##?? 4,5,1\n"
"#??????####?.???? 1,8,1,1\n"
"?.#?###?????#?#? 5,4\n"
"?.??#.???.#.#?#. 1,2,1,1,3\n"
"#.#?#?##??##?.??.. 1,10,2\n"
"???????#?????#??? 3,2,1,1,5\n"
".?.#??.?#?#?.?#???? 1,1,4,2,2\n"
"??##???.???# 6,1,1\n"
"?#??..???#?#???#.??? 1,1,2,5,1,1\n"
"##?.??#???#??###? 2,3,2,5\n"
"?.???#???#?#?#???#? 1,1,1,1,9\n"
"?#??#??#??.?.#?. 2,2,2,1,2\n"
"????#??.?##? 4,3\n"
"?.?#???..?####???? 1,2,1,7,1\n"
"#???????.? 1,2,1\n"
"#?..???..??????? 1,1,1,1\n"
".#??#?????? 1,6,1\n"
".#?.?.???##?? 1,1,5\n"
"??#????.###?##??? 2,2,3,2,2\n"
"?#?.?.???. 2,1\n"
".??..???????.????? 2,3,1,1,1,1\n"
".??.#???.???? 3,2\n"
"...?.??#???.. 1,1\n"
".??.?.?????????#??? 1,3,2,5\n"
"?.???..?#.#????# 1,2,1,6\n"
".?#???.??#?????. 4,5\n"
"?##?.???..#? 3,3,2\n"
".##???#?#?.?#??.??? 3,4,3,2\n"
".????#??.?? 4,1\n"
"?##??#?###???#???#?? 2,5,1,5,1\n"
"??#??.?.##??? 1,2\n"
"..#????#??#?? 1,2,1,3\n"
"??????##?. 2,3\n"
".????????.?#????? 1,6,1,2\n"
"??.?#????.#??#?. 1,2,2,1,1\n"
".?#?????????.#?# 2,5,1,1,1\n"
"???????.???????#?#? 2,10\n"
"?#?#?.#.?????#? 3,1,2,2\n"
"???????#?????????? 3,1,4,2\n"
"?.?.??????? 1,3,1\n"
"????.#???#?.##.?? 1,1,5,2\n"
"????..#????.????? 3,1,1,1,2\n"
"????#?.#???#?? 6,6\n"
"?.?#???.??.??### 1,2,1,1,3\n"
"..##?.??#?.?#?.#?. 3,1,2,2,2\n"
".?##?#??.? 2,1,1\n"
"?#???##?????. 6,1\n"
"???#?#???#?#?#???? 2,3,7,2\n"
".#?#?..####?? 1,1,6\n"
"#???#??#????? 2,9\n"
"?..?#??????#???.?#? 1,1,8,2\n"
"?.#???#??? 1,1,4\n"
"..???##???#?#?.#??. 11,2\n"
"????##????. 1,6\n"
"??????#??.?????. 1,1,1,2,2\n"
"?#?##???????#.?#? 13,2\n"
"?????????# 2,2\n"
"##???????. 5,3\n"
"????????##??# 2,5,1\n"
"???#?#?##???#?#??#? 8,1,1,4\n"
"?.????????. 6,1\n"
"???????#.??#?#??# 4,3,7\n"
"#####????#?????????. 10,1,1,1\n"
"#??????#?#.?????? 1,6,1,2\n"
".??.??????????#?# 4,3\n"
".???..#??. 1,3\n"
"???.?????? 1,1,2\n"
"#?.??#???.??? 1,3,1,1\n"
"???????.???.. 1,2\n"
".##???#?.#???#?#?# 2,2,9\n"
".?#???.?.? 1,1\n"
"?#?#????#?#.??#? 4,3,1,4\n"
".?????.?????????# 4,1,6,1\n"
"????.???#?#??###? 4,1,5,3\n"
"??#????????#??#?..# 3,1,1,3,1,1\n"
".?????.?????????.# 1,1,1,1,5,1\n"
"..?????????#???.??? 5,5,1\n"
"??#????#?? 1,1,1\n"
"????#?#?????? 1,1,4,1\n"
"???#??#??.?#?? 7,2\n"
"????.#??.?.##? 1,1,1,3\n"
"??.#???.??? 1,2,1\n"
"#?????##?#????? 11,1\n"
"?...??#??. 1,5\n"
"?????#?#?.???# 1,1,3,4\n"
"??.??##.####????.# 2,1,2,7,1\n"
"??#????..? 5,1\n"
"????#??#???#??#?##? 3,2,7\n"
".???##????.##?##?. 5,5\n"
"??#??#??#?#? 1,9\n"
"??#?#??#??.#???#???? 10,5,2\n"
".??.?????#? 2,1,2\n"
"???#.??#?#??#? 1,1,9\n"
"??#?????..???# 7,4\n"
"..#??.?###???#?#.? 3,9\n"
"???#?????##?.????# 3,4,5\n"
"#??#?#???# 1,4,2\n"
"??#??#???#?.#?#??? 1,1,6,1,1,1\n"
"??#????.???#.#? 2,2,1,1,2\n"
"##?#?????#?.????#?? 6,3,5\n"
"????#?.?????? 3,3\n"
"??#.???.?.#????#???? 2,1,2,7\n"
"??#?#???.???? 8,1\n"
"#.?#.?#????.???. 1,1,3,1,3\n"
"##???#????.?..?.??? 10,1,1,1,1\n"
"????#??#?????? 1,7,3\n"
"???.?.??.??? 2,1,1,1\n"
"?#?###?????.?#?#?.?? 9,1,1,1,1\n"
"???###?##???.#? 1,4,2,1,1\n"
"????###?????#?.? 1,11,1\n"
"????#??..??##??? 5,1,3\n"
".????##??????..##. 12,2\n"
"?.#????#?? 2,2\n"
"????????#?#????#??.? 2,4,3\n"
"????.#???.??#?#. 4,3,5\n"
"??##????.#?.?#. 7,1,1\n"
".?.??.??..? 1,2\n"
"##???.#?.? 2,2,2\n"
".?????#?.??#.? 4,2,1\n"
"..##??#??#? 2,2,2\n"
"??..?.?.??..?. 1,1\n"
"???.?.?..???#?#?? 1,1,8\n"
"???##?#???#????? 1,3,2,2,1\n"
"?.?????#?????#??.??? 1,1,2,6,2\n"
"?????.#?????#?#???. 1,1,9,2\n"
"?#?.????.???????## 1,4,1,1,1,2\n"
".?.?##??.### 2,3\n"
"??????##???# 2,4,2\n"
".?#.#.?#????..#.?? 2,1,1,3,1,1\n"
"?.#???..??????.? 2,3\n"
"#..#??????????? 1,1,3,5\n"
"??.??.???.?...? 1,2\n"
".?.#???#?#. 1,4\n"
"#??..??#.?#? 1,1,1,3\n"
"?.?##??.#.?? 4,1\n"
"???????.#??? 1,2,1,1\n"
".????#??.?. 2,3,1\n"
"????.?#???? 2,3,1\n"
"???#???.?#?????? 1,4,2,2,1\n"
".#?????..???????.? 6,7\n"
;

} // namespace Day12

unsigned long day12Part1(std::string_view streamSource, bool sourceIsFilePath);
unsigned long day12Part2(std::string_view streamSource, bool sourceIsFilePath);