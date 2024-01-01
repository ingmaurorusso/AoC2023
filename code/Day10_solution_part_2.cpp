#include <algorithm>
#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace{

constexpr std::string_view Input =

false ?

/*
"7-F7-\n"
".FJ|7\n"
"SJLL7\n"
"|F--J\n"
"LJ.LJ\n"
*/
/*
"...........\n"
".S-------7.\n"
".|F-----7|.\n"
".||.....||.\n"
".||.....||.\n"
".|L-7.F-J|.\n"
".|..|.|..|.\n"
".L--J.L--J.\n"
"...........\n"
*/
/*
".F----7F7F7F7F-7....\n"
".|F--7||||||||FJ....\n"
".||.FJ||||||||L7....\n"
"FJL7L7LJLJ||LJ.L-7..\n"
"L--J.L7...LJS7F-7L7.\n"
"....F-J..F7FJ|L7L7L7\n"
"....L7.F7||L7|.L7L7|\n"
".....|FJLJ|FJ|F7|.LJ\n"
"....FJL-7.||.||||...\n"
"....L---J.LJ.LJLJ...\n"
*/

"FF7FSF7F7F7F7F7F---7\n"
"L|LJ||||||||||||F--J\n"
"FL-7LJLJ||||||LJL-77\n"
"F--JF--7||LJLJ7F7FJ-\n"
"L---JF-JLJ.||-FJLJJ7\n"
"|F|F-JF---7F7-L7L|7|\n"
"|FFJF7L7F-JF7|JL---7\n"
"7-L-JL7||F7|L7F-7F7|\n"
"L.L7LFJ|||||FJL7||LJ\n"
"L7JLJL-JLJLJL--JLJ.L\n"

:

"L-77.L-J7F.-7FFF77.F7-|7.7-F-7L--|-|-7-F|FL7FF|.7FF-L7LFJ77-J--|.F7.-FF--77..FLJ7.FFF.|7FF--F--7-.|J.FFJ-7.F-7-|-7F77..77L-L-|.F-7-|-F--L7F-\n"
"LFL-L.F--|-JF-L-7-L7JLL|-J.-.-7J.L7J.7F7--.|L7|.F-L--7.F|777L.-J7LJF-77J-L7F-L.FL.FFJ.FJJF||||J.F|.|7.J-F|7F.LLJ.LL-J7F|F|..FF7-7|.LLF7FFL7J\n"
"|FJ.F-JF.||J|7J-|7L|F-7J|J-L|-----JL|||JJ-JJFL-.J7.LJ|-LJL-JL-.F|7||7||.|F|.7|.L7F7||F|-LFJ-L-77|JF7-L-F7L-.F7JFL.|..FFF|--77L|-J7JF7J||JLLJ\n"
"-|.F|J7L-7J-|||7L7J.7L7JJL.L|||-J---L7--7.|F7J7.FJ7-F7|L7..|L||.-|7|.FJFJFFJLF-7F|LF77JLLLLJ|.F-7-7.LL7.F7F-JF77-L7-LL-F||.F--|7-L|LJ-JLLF|.\n"
"LLL-JFJ.F|7FL77-7-JLL.|-JFFFF7|7777FL|.|JFFF.F|FJJFFJ|-F.J.F---7L77--L.LL|J..|LL777|L7-F7||-JFL-JLJFF7F-JL77-|L|..|..|L-J-FJL-||F7-J7.|.|FJJ\n"
"LFFLF--|-J7JLLJFJ7.FJ-|L-F7.L-J7--|7.L.|7--JFFJFJF-JFJJ|7LLJ7J.|-F77J.FJ||.7FJ-.|L|JFF7|J7.|.|.FFJFF||L7F-J7-|F|7FL.-F.L7-FFJ-L-JLJFF-J-J|F.\n"
"FLL-7.F|J||FJLJFLL--J.L7LLJ7.LLL7FJFLJ7.7---JJFF.L-7L-7-7.|LL-FJFJL--77F|F-7-JJ.|.LF-JL77F7LFL-F-7F7||FJL7J||.FLL7J7LL-J.L|..FLJ-F7|7J77L|LF\n"
"|..LJ77|.FJ77L-7J7||7L.77.F|7.|FL|L|J-|7|||L|7|F7F7L7FJFF777|7LJ|F7F-J7FJJJ.L|.F|FJL-7FJF7J7F7LL7LJLJLJF7L-7-FJ|L-J.L-7FJ.---F..L|LL-7J7||.F\n"
"F7-7JL|LLJJL--J.|L7J7L7L|F|-|.||7L-L7FF||FF7JF7||||F||FFJL-7-|..LJ||F7F-7JJ|7F7-7F-7FJL7||-|.-JFL----7FJL--JF-7JJJ7L7L|7.F|L--77.|7.L--7|L||\n"
"FJJL7LL7|LL-J.|F7J|LFJJF--JF-7FF7--J||.F7FJ|FJ|||||FJL7L7F-JF-7FJFJLJ|L7|-|FFJ|LLL7||F-J||-FFJ-F7F7F7||F7LF7|FJJ7FJ-||.LF-7J-|LL7JLLJ|LLFJL7\n"
"|FF-|7L|--F7..-L7.--JJF||L-F|-F|L77FL77||L7LJFJ||||L7FJFJL7|-LFF-JF--JFJ|77FJFJ|LFJLJ|F7|L7F7|.|||||||||L7|||L---7-FLF7FL.L7FF-LF.|7.|J||7-L\n"
"7-L-L|7|..LL-7|..|7FFJFLLJ.F-7FJFJ7.||-|L-JF7|FJLJL7|L-JF-J7|F7L-7L--7L7L7FJFJ|7FL7F7LJ||FJ|L7FJLJLJ||||FJ|||F---JL7.LF||F-7-7----F-JJ.7LJFJ\n"
"FF7FJJF--7|JF|F-..L|.FLFJ7F|FJL7||L7F7.L--7|LJL--7FJL7F7L--7FJL-7|F--JFJFJL7|F7F7LLJL-7|||FJFJL-7F-7LJ||L7|LJL7.|--L---LJJ.FJJ.LL-J.|.F--7L.\n"
"J.FJ|7F-.F7FL7-|7|LL7FF|FF7|L7FJL7FF7F7F--JL-7JF-J|-FJ|L---JL--7LJ|F7.L7L7FJ||||L-7LF-J|||L7L7F7LJLL7FJL7LJF-7L7|.J.L--LJL-J.|L-L-L---|..J|7\n"
"F|J7.F|LFFJJ7|7L-JFJ|J-J-|||FJL7FJFJ||LJF---7L7L-7L7L7L---7LF77L-7|||F7|FJ|FJ|||F-JJL-7LJ|FJFJ||FF7FJ|F-JF-JFJFJF7F7-|J|77L|-77.|F-7L7|--F|7\n"
"-7||.|||L||7LJ-|FFF7JJ.LFJLJL7FJL7|FJL--JF--JFJF7|FJ-|F---JFJL---J||||LJL7||J||||F7-F7|F-JL7|FJL7||L7||F-JF7L-JFJL7|FF7-JLF|-77.F--J7-J7F---\n"
"|JFLL-J7.L--77LLF7LLFF7.L---7||F-J|L-7F-7L-7FJFJ|||F7||F7F7L-7F--7LJ||F--J||FJLJ|||FJ|||F7FJLJF-J|L7|||L7FJL-7FJF7|J-|L|LFF77F7JJJLL|7-F7FF|\n"
"L7|LLF--7LJ.J--L-JF.|JF7F7F-JLJ|F7|F-JL7|F7|L7L7LJLJLJLJLJL7-LJF7L-7LJL7F7||L-7FJ||L7LJLJ||F-7|F7L7||||FJ|F--J|FJLJLLF7J-FJL-J|F|7|-77.--J-F\n"
"L7|L||FLL.|L|F7.LLF-7F||||L--7FJ|||L7F7|LJLJFJJL7F7F7F7F7F-JF-7||F-JF--J|||L7L||FJ|LL--7FJ||JLJ|L7||||||L||F7FJL---7F|||7|F---JF7JJ7L|-L7F7|\n"
"FLL.FL7JF77LJ7LJ7-L-J-|LJL-7.||.|||FJ||L--7FJF-7LJ||LJLJLJF-JFJ||L-7L--7||L7|FJ|L7L--7FJSFJL-7FL7||LJLJL7||||L7F---JFJL7FJ|-F7FJ|JL|7|.|-J.|\n"
"F.L-F-JLJ--7J|7||F--7FL---7|FJ|FJLJL7|L---JL7L7|F-J|F---7|L-7L7||F7L7F-J|L7||L7L7|F--JL7|L7F-JF7||L7F7F-J||||FJL---7L-7||FJFJLJFJF-F-7-.J7FL\n"
"L.|||||.|7LF-L--FJFLLF7F-7||L7|L7F--JL-7F--7L7|LJF-J|F--JF-7L7||LJ|7||F7|FJ|||L7LJL7F7FJL-JL7FJLJ||||LJF7||||L7F---J7.||||FJF--JLL7|.J.|FF-J\n"
"FJ7L-J7-LJLF7|JLL77J7||L7LJ|FJ|FJL-7F-7LJF7|FJL-7L-7||F-7L7|J||L-7|FJ|||||.||F7L--7||||F----JL--7|FJL7FJ|||||FJL-7F-7FJ||LJFJF7-F-|-7|-||LJ.\n"
"|J|J-|JLL|||FL-LLF7FFJ|.L-7LJFJL7F-JL7L7FJLJ|-F7|F7LJLJFJFJL7|L-7||L7|||||FJ|||FF7|||||L--7F----J||F7|L7||||||F--JL7LJFJ|F7|L||7|.|.|..LJLLJ\n"
"LFJF-|.F7-LLF.FF7F7FL7L7F7L-7L7|||F7FJFJL7F-JFJ|||L----JFJF-J|F7LJ|||LJ|||L7LJL-JLJLJLJF--JL--7F7|||LJFJLJ||LJL--7FJF-JFLJ|L7||F7-FJJ.FL-77|\n"
".F|7L7-FJLFL|-F|LJL7F|FJ||F7|FJFJ|||L7L-7||F7L7LJ|F-7F7FJFJF7LJL-7L7L7FJ||.L-7F-7F--7F-JF----7LJ|||L7FJF--JL7F---JL7|.F-7FJFJ|LJL-7J--F|LF-|\n"
"F.||.J-|7FFF--||F-7|FJL-JLJLJL7L7|||J|F-J|||L7L-7LJFJ||L7|.||F-7FJFJ7||7||F-7LJLLJF-J|F-JF---JLFJ|L7LJFJF7F-JL-7F7FJL7|FJL7|LL7F--JL|.L-.L-|\n"
"L-J|-|FL|F|.L7FLJJ||L----7F-7FJFJ|||FJL7FJ||FJ.FJF-JFJL7|L7|||FJ|FJF7||FJ||FJF-7F7L-7||F7|F7F7FJFJ.|F-JFJ|L7F--J||L7FJ||L||L-7||F7|F-7J|-LF.\n"
".|.-J|7.-L|FF-7.LL|||F7F7LJFJL7L7LJLJF-JL7||L7FJFJ7FJF-JL7|||||FJL7|LJLJFJ|||L7|||F-JLJ|LJ|||||FJF7||F7|FJFJ|F7FJL7|L7|L7FJF7LJLJL-7.|.LJJJ|\n"
"FJ.LF77-L7|.L7L7|FJL-J|||7FJF7L7L---7|F7FJ|L7||FJF7L7L-7.|||LJ|L7FJL--7FJ.|L7FJ|||L-7F-JF7|LJ|||FJ||LJLJL7L7|||L7FJ|FJL7||FJL------J7F-JFF77\n"
"F-L-FJ7.L|.-LL7L7L---7||L7L-JL7|-F7F||||L7|7|LJL-J|FL7FJFJ|L-7|FJL-7F-J|F7L7|L7|||7FJ|F7||L-7|||L7||F----JF|LJ|FJ|FJL--JLJL-----7JF77J|--7LJ\n"
".||.7-JJ||7-J|L7L-7F7|LJFJF7FL|L7||FJLJL-JL7L-7F-7L7FJL7|FJFFJ|L-7FJL-7|||FJL7|||L-JFJ||||F-J|||FJ||L7F7F--JF-J|FJ|F---------7F7L-J|LLJ7JF7|\n"
"-JJ.L|FF7||.LJ-|F7LJ|L-7|FJL7FJFJ||L------7|.FJL7|FJL-7|||F7L7||FJL7-FJLJ||F-J||L-7FJ-||||L-7|||L7|L7|||L--7L-7|L-JL--------7||L---J777FF.LJ\n"
"|JL77FL|-J--JJFLJL-7L--JLJF-JL7L7|L7F-7F7FJ|FJF-JLJF-7|||LJ|FJL7L-7L7|F--J||F7|L7FJL7FJ||L7FJ||L7|L-JLJ|F7||F-J|F--7F7F-7F7FJLJF7||L|L7JJF.|\n"
"J|F|7JL..|L|7F----7L7F---7|LF7L7||FJ|FJ||L7|L7|F7F7L7|||L7FJL7FJF7|FJ||F7F||||L7||F-JL7||FJL7||FJ|F----J||FJ|F-JL-7LJ|L7|||L---JL-7.|.||.L|7\n"
"LFJ.|7|.FF-F7L---7|FLJF--JL-JL-JLJ|FJL7|L7|L7||||||FJ|||FJL-7||FJ||L7|||L7|||L7|LJL7F-J|||F7|||L7|L7F--7||L7|L7F--JF7L-J|||F---7F7|J|FL77F77\n"
"LJLF-J-F--FJ|F7F-JL---JF---------7|L-7||FJ|FJ||||||L7||||F--J||L7LJFJ|||FJ|||FJL-7.|L-7||LJLJ||-LJJ||F7LJL-J|FJL---JL--7|||L--7||||.|FLJJ||F\n"
"FLF77.F.7-L7LJLJF-7F7F7L7F-------JL--JLJL-JL7|LJ|||FJ||||L7F7||FJF7|FJ|||FJ||L7F-JFJF7||L-7F-JL-7F-J||L----7LJF7F7F---7|||L7F-J||LJ.--JLFJLL\n"
"--7.F.L7|LLL7F7FJ-LJLJL-JL--7F7F7F-7F--7F---JL7FJ||L7|||L7LJ|||L-J|||FJ|||L|||||F-JFJ|||F7|L-7F-J|F7||F7F7FL-7|LJLJLF7LJLJ.|L-7||JJ.LL-JL-JJ\n"
"L7|FF-|7.LFF||||F-7F----7.F7LJLJLJ.LJF-JL7F7F7||FJ|FJ|||FJF7|||F7FJ||L7|||FJL7LJL7FJ7LJ||||F-JL-7||||LJLJL--7|L-----JL7FF7F|F7|LJJJ7.|.-FJ|.\n"
"||-LL7L7--F-J|||L7LJF--7L-JL----7F7F7|F7J||||||||FJL7||||7|LJ|LJ|L7|L7LJLJ|F7|F--JL--7FJ|LJL7F--JLJ||F------J|F------7L-JL7LJLJJ7F.JJ--|JLJ7\n"
"FF7FL|.|.FL--J|L7L--JF7L-7F----7||LJ|LJL7||||LJ||L7FJ||||FJF7L7.|FJL7|-F7FJ|||L--7F--JL7L7F-JL----7||L-7F--77|L-77F-7|F--7L-7|..L|7LJ-F7J|L-\n"
"FJL-.7F-7-F---JFJF--7||F7LJF-7FJLJF7L---JLJ||F-JL7LJFLJLJL7|L7L7LJF7LJFJLJFJLJF--J|F7LFJFJL--7F-7FJ|L77LJF7L7L-7L-JFJ||F7|F-J7-|.LFJF-J||L7L\n"
"JJ|L-JL.L7L----JJL-7||LJL-7L7|L---JL------7LJL7F7L-------7|L7L7L7L||F-JF-7|F7FJF-7LJL7L7L7F--J||LJ|L-JF--JL-JLFJF7FJLLJ||LJFF7LF7-|-J|.F||-J\n"
"J7LJ7LLFJL.|F|F--7|||L7F-7L-JL---7JF------JF--J|L7F7F----JL7L7L7L7||L--JFJLJ|L7|FJF--JFJFJ|F-7|F7F7F--JF-7F--7|FJLJF7LFJL7F-JL-JL-7JF|J--77.\n"
".|||7|||-|--LFJF-JFJL7LJJL----7F7L-J|F----7L--7|J|||L----7FJFJLL7LJ|-F-7|F7FJFJ|L7L--7L7|FJ|FJ|||||L--7L7LJF-JLJ|F7||FJF7||F------J7-7--7||.\n"
"LL77-JJ-.L7.LL7|-FJF7L----7F--J|L----JF7F7L7FFJ|FJ|L-7F--J|FJ-F7|F7L-JFJ|||L7L7|FL7F7L7LJL7|L-J|LJL--7L-JF7L-7F--JLJLJFJLJ|L7F--7.F77-7-F|F7\n"
"|-L-7.LJ-LFFF-JL-JFJL7F--7|L---JF---7FJLJL7|FJFJL7L7FJL--7LJF7||LJ|F--J7|||FJ|LJF7||L7L7F-J|F7JL-7F--JF7FJL--JL7F---7FJF7L|FJ|F-JFJ|JFL-|-LJ\n"
"|J|LJ-J.F-LFJF7F-7L-7LJF-J|F---7L--7|L7F-7|||FJ|7|FJL-7F-JF7||||F-JL---7LJ|L7F--JLJL7|FJ|F-J|L7F7|L7F7||L---7.FJL--7|L-JL-JL-JL-7|FJ77|L|7J|\n"
"F7F77|7|J.LL-JLJFJF-JF7L-7|L-7FJF7J|L7LJFJ|||L-7FJL-7FJL-7|LJLJ|L-7F--7L-7|FJL-7F7F-J|||LJF7L7LJ||FJ|||L---7L-JF7F7||F7F--7F7F-7LJ|F77..L-.7\n"
"L|77--L77|..F---JFJF-JL--JL7FJL-JL7|J|F-J|LJL7FJL7F-JL7F-JL7F-7L--JL-7|F7||L7FFJ|||F-J|F--JL-JF7||L-JLJF--7L---JLJLJLJLJF7||LJFL7FJ|L---7J.J\n"
"|LJ.7.LLL|-F|F7F7|FL------7LJF---7|L7|L--7|F7LJF-JL--7|L-7FJ|7L--7F7FJLJLJL-JFJFJ|||F7|L7F7F--J|LJF--7FJ|FJF-----------7|||L--7FJL-JF-7FJ7-J\n"
"|JLFFL7L--7|||LJLJF7F7F7F7L-7|F--JL-JL---JFJL7LL-----JL7FJL7L7F7FJ||L---7F--7L-J|LJLJLJFLJLJF--JF7|F-JL7FJFJF7F-7F7F--7LJ|L-7FJL-7F7|FJ|-F7|\n"
"|L--J7|-7.FF||F---JLJ||LJ|F-J|L-------7F7|L7FJF-----7F7|L7FJFJ|LJFJL-7F7LJF7L-7F--7F7F-----7L7F7|||L7F-JL-JFJLJ-LJ|L-7|F7L-7LJF7FLJLJ|FJF||L\n"
"|F|L-J|FF-FFLJL7F---7|L-7LJF7|F-------J||F-J|FJF---7LJ|L7|L-JFJF7L-7-|||F-JL--J|F7|||L----7L-J|||||-||F---7L-----7L-7||||F-JF7||F---7|L77--J\n"
"--L-J-FFJFL|7|FLJ-F-JL--JF-JLJL--------JLJF-JL7L--7|F7L7|L--7L7||F-JFJ||L--7F7|LJ|LJ|FF7F7L---J||LJFJ|L--7|F-7F-7L-7|||||L--JLJLJF--J|FJ7|F7\n"
"|.|-|JF|L|.|FF---7L------JF7F-----------7FJF77|F--J||L-JL---JF|||L7||FJL-7FJ||F--JF7L-JLJL-----JL7FJFJF--JLJL|L7L7FJ|||||F-7F7F7FJF-7|L7J-|-\n"
"LFF---||..-L-L7F7L--------JLJF7F7F-----7|L-JL-JL--7LJF----7F7FJ||FJFJL-7FJL7||L--7|L-7F--7F-7F-7FJL7|7L-----7L-JLLJ-||LJLJ||||||L-JFJL-JJFLJ\n"
"F-J--JL77.|JJLLJL---7F7F--7F7|LJLJF----JL7F-7F-7F-JF7|F---J|LJFJLJFJF--JL-7LJL7F-J|FFJ|F7||FJ|FJL-7LJF7F----J-F7F7F7LJ-F7F7LJ|||F7FJ7|J|.7F-\n"
"||LJ--FLF-J.|J|.FF7FJ|LJF7LJ||F--7L-----7||L||-||F7|||L7F7FJF7L--7L-JFF--7|F7FJL-7|FJFJ|LJ|L7|L7F7|F-J|L------JLJLJL7.FJLJL-7||||LJLJJ---JLJ\n"
"F-L7F-|-J.|FF---7||L-JF-J|F7LJL-7L------J|L7|L7|LJ|||L7LJ|L7||F-7L-7.LL-7LJ|LJF--J|L7||L7FJJLJFJ|||L-7L-------7F----JFJF--7FJLJLJJJ7J7|L-7|.\n"
"7--|7L|.LF7-L--7LJL--7|F7LJL7F77L-------7|FJL-JL--J|L-JF7L7||||J|F-J7||L|F7L7.L7F7|FJ|F-JL-7F-JFJLJF7|F------7LJF---7|FJF7LJ7-||.F7F7-|-7J7.\n"
"LF7JLF7.|.||LL7L---7FJLJL--7||L---------JLJF7F7F--7|F-7||FJ|||L7|L-77LFFJ|L7|.L||||L-J|F-7FJL--JF7FJLJ|F----7L-7|F--J||FJL7F77FJ-L|L|.L7LJ.L\n"
"F-||.|L-L7--JLFLF--J|F7F---J|L-------7F7F7-|||LJF7LJ|7LJLJL|||FJ|F-J--FJFJ-||7J||LJJF-J|FJ|F--7FJLJF7FJ|F--7L-7LJL7FFJLJF7LJL7F7FF77.LJJ.|7.\n"
"JF7-7-7-F|F|-FFFJF-7|||L---7|F7FF----J|LJL7|||F-J|F7L7F7|F7LJ||FJL-7LL|FJJ.LJ--LJJFFL-7|L-JL-7LJF-7|LJLLJF-JF7L7F7L7|F--JL7F7||L7||77.|7-F-J\n"
".|L7L7|.JLJFF-7L-JFJLJL-7F-JLJL-JF-7F7|F--J|LJL-7||L7LJL7|L7-LJL-7FJJ|LJ7LJ7|JLJJ7F|-LLJF7F7FL7FJFLJFF---JF-JL7LJL7LJ|F--7LJLJ|FJ|L-7-|L-|.|\n"
"F|7|L-J7LF--L7|F7FJF7F-7||F-7F7F7|FJ|||L---JF-7FJLJFJF-7LJFJF|FLLLJJ-7L7|-.L7J|||LF7FF--JLJL--J|F---7|F7F7|F--JF-7L--JL7FJF-7J|L-JF-JF-7F|-L\n"
"FLFF7J|L7|F|-|LJLJFJLJFJLJ|FJ|||LJL-JLJF7F7FJ-LJ-F7L-J7L7FJF--7L-.FF7FJ-L.JL|F|.F.|L7|F-----7F7|L--7LJ|LJLJL--7|FJ.F77FJL7|FJFJF7FJJ-J-L-J-|\n"
"|F-J77||F7F7.L7F--JF--JF7FJL7|||F------JLJLJF7F-7|L--7F7|L-JF7L7|.LJF-7LF7J||FJF|.L7|LJF----J|LJF--JF-JF------J||F7|L-JF7LJL-JFJ||L|-|.LF|..\n"
"L.|FL77F||F77-LJF-7L--7|||F-J|LJL------7-F7FJLJFJ|F--J|||F--JL-J7FL-.LJF|JFJ-F.LLJ-||7FL-----JF7L-7FJFFJF7FF7-FJLJLJF-7|L-----JLLJ-J-7-F-J-|\n"
"L-J-L|7F|LJL7F7FJFJF7FLJ||L--J|F7F--7F7|FJLJF--JFJL--7||LJF7F-7JF-|L|.FL|-L7.||J.FFJ|F7.F7F7JFJL-7LJLFJFJL-JL-JF---7L7|L-----7F7F77|.|.|L7-|\n"
"7J|L||77L7F7LJLJFJFJ|F7FJ|F---7|LJF7LJ|LJF7FJF-7|F---J||F7|||FJ.--7-|-F7L7L-77|L7-L7|||FJLJL7L--7L--7L-JF---7F7L--7L-J|F-7F--J||||F77J|7J|J|\n"
"L.7FFJFFLLJ|F7F7L7L7|||L-JL--7|L--JL-7L-7|LJ7L7|||F7F7|||||LJL77-JL-JLL7.-F77F7F|.||||LJF--7L7F7L7F7L7F7L--7|||F--JJF7LJFJ|F--JLJ||L77|JF7.|\n"
"FF77|---.LL||||L7L-JLJ|F7F7LFJL------JJFJ|F7FFJLJLJLJ||LJLJF-7L777|FJ.77F.LJFJL-7F-J||F-JF7L7|||7LJL7||L---JLJ|L----JL7JL-J|F-7F-J|FJ-L7.|FL\n"
"|.LF--J7.J-LJLJFL-7F-7LJ|||FJF---7F7LF7L7LJL-JF7F-7F-J|F---J-L7L7JL|JFL777FFL7F-JL-7|LJF-JL-JLJL77F7||L------7|F7F-7F7L7F7FJL7LJ|-||J|F|F-.|\n"
"|--F--.F7|FF7F---7LJFJF7LJ|L-JJF7LJL-JL7L-----J|L7LJF7||LF7F7JL-J|FFF7-|L-J-FJL7F--J|F7L-------7L-JLJL7-F----JLJ|L7||L7LJLJF7L-7F-JL7F7L-J7J\n"
".JF7|.L7LF-J|L--7L-7|FJ|F7L----JL7F----JF7FF7F7L-JF7|LJL-JLJL7F-7---L7|L-7-FL-7|L--7|||F------7|F-7F-7L7L7F-7LF7L-JLJJL7F-7|L--JL--7LJ|77-J7\n"
"F.F|7|7LF|F7L-7FL-7|LJFJ|L-7F-7F7|L-----JL7|LJL7F7|LJF7F7F7F7LJFJ-JL7J|.F---7FJ|F--J|||L-----7LJ|FJ|7L7|FJ|FJFJL-7F-7F7||FJL--7FF7FJF-J77.|F\n"
"|-||F--7FLJL-7L-7FJ|F7L-JF-J|FJ||L---7F7F7LJF--J||L7FJLJ||LJ|F7L-7F7JFJ-|F--JL7|L7F7LJL-----7L7FJL7|F-J|L-JL7|F--J|FJ||LJL----JFJ||FJ|||7F7J\n"
"|-FL7F|LJFL7FL-7|L7LJL-7|L--JL-J|F-7-LJLJL-7L---JL-JL--7LJF7LJL--JF7..FF||F7F7|||LJL-7F----7L-JL7-LJL-7L---7LJL---JL7||F7F7F7F7L7LJL--7JF7F.\n"
"J7|LJF7LF7JF7|FJL-JF7F7L7F-7F7F7LJFJF7F7F77L-7F-7F-----J|FJL--7-F7|L7F7FJLJ||LJL-7F--J|F---JF7F7|F----JF-7LL--7F7F-7LJLJLJLJLJL7|F-7F-J-.LL-\n"
"|L|.L|LFJL-JL-JF-7FJLJL7LJFJ||||F7L-JLJ||L--7|L7|L--7-F7FJF7F-JFJ|L7LJ|L7F-J|F7F-JL---J|F7F7|||||L7F7F7L7L---7||LJ7L---7F-7F7F7LJL7||-F|JJ.|\n"
"|-J.L--L-7F---7L7||F7F7|F7L7|||LJ|F----J|F--JL-JL7F7L-JLJFJLJF7L7L7L-7|FJL-7LJ||F7F-7F7LJLJLJLJLJFLJLJL-JF-7FJLJF7F7.F7|L7||LJ|F7FJLJFF7JJ.7\n"
"|7LF-L-LLLJF--JFJ|||LJ|LJL7LJ|L-7|L-----JL7F---7|LJ|F7F7FJ7.FJL7|FJF-J|L--7L7FJ|||L7LJL7F7F7F---7F77F----J7LJF--JLJL-J||FJ||F7LJ||F7F-J|-.F|\n"
"L|.LLJJLJJFJF7FJ7LJL-7||F7|F7L--JL---7F7F7|L7F-JF-7LJLJ|L-7FJF7|||FJF-JF7JL7LJFJ|L7L7F7||LJ|L--7LJL7|F-7F7F77|F---7F7FJ||FJ||L-7|LJLJF-J-7--\n"
".L7-F7L-FFL7|LJF-----JL7||LJ|F7F-7F7|LJLJ||FJL7L|FJF7F7|F-JL-J|||||FJ-FJ|F7L-7L7|FJFJ|LJL-7|F--JF-7LJ|LLJLJ|FJL--7|||L7LJL7||F-JL----JJJ||.|\n"
"F-J7LF7LFLJLJF7L------7|||F7LJLJ.LJL--7|FJLJF7|FJL-JLJ|LJ7F7F7||||||F7|FJ|L-7L7||L7L7L-7F-JLJF-7L7L7FJF---7LJF7F-JLJL7L7F7LJ||F7F--7FF7-F.FJ\n"
"F.|F.F|JFLF--JL-------JLJLJ|F7F7.F---7L7L7F-J|LJF-----JLF7|LJLJLJ||LJLJ|FJF7L7|||FJFJF-JL---7|FJFJFJL7|F-7L7FJLJF77F7L-J|||FJLJLJF7L-JL7-7JJ\n"
".F|-7-JF7.L-----------7F--7||LJL-JF-7|FJ.|L7FJF7L---7JF7||L---7F7LJF---JL-JL7||||L7L7L7F7F-7LJL7L7L7FJLJLL7|L---J|FJL7F7||FJF7F7FJ|F7F-J.JL7\n"
"|LJF|-FJ|7.F7F7LF7F7F-J|F-J|L----7|FJ||F7L7|L7|L7F-7L-JLJ|F--7LJL-7L-7F7F-7FJ||LJFJJL7LJ||FJF-7L-JFLJJF7F-JL-----J|F7||||LJFJLJ|L7||LJ7.FL7J\n"
"LF-7J7L7|F-JLJL-JLJLJF7|L-7L----7LJL7LJ|L7LJFJL7|L7L7F---JL-7|F7F-JF-J||L7|L7||F7|F--|F-J|L7|FJF-7F-7FJ|L-----7F--J|LJ|||F-JF7-L-JLJJ|J-L-J7\n"
"F..J.LFJ|L-----------JLJF-JF---7L---JF7|FJF7L--JL-JFLJF7F7F-J|||L7FJF-JL7|L-J|LJ|L7FFJ|F-JFJ|L7L7|L7|L7L------J|F--JF-JLJL--JL----7J.J...77|\n"
"|-7-|FL7L----7F---------JF-JF7FJF7F7FJ|||FJL--7F----7FJ|||L-7|||FJ|.|F--JL7F7|F7L7|FJFJL7FJJL7|FJL-J|JL--7F7F--JL---JF-7F7F-------J-JL|77|F|\n"
"L7-77FLL7F--7|L--7F7F7F7FJF7||L-JLJLJFJ|||F---J|F---JL7|||7FJLJ||FJFJ|F7F7LJ|LJL-J|L7|F7|L-7J|LJF-7FJF7F7LJLJF7F----7L7|||L----7FF-7||L|L7-|\n"
"F|FL7|-|LJF-JL--7LJLJLJ||FJLJ|F---7F-J||LJL7F7FJL7|F7FJ||L7L--7LJL7L7LJLJL-7L----7L7|LJ||F-JFJF7|FJL-JLJL----J|L-7F7L-JLJ|F--7FJFJFJ77-|FJ|J\n"
"FFJ.LF-F-7L-7F-7|F-7F--J|L7F7LJF-7|L---JF--J||L-7|FJ||FJL7|-F7|F--JFJF-7F--JF----JFJ|F-J||F7L-JLJL-7F7F-----77L-7LJL---7FJL-7||FJFJLL|7L--77\n"
"LJ7-||7L7L--JL7LJL7|L---JL||L7FJFJL----7L--7|L7FJ||FJ|L7J||FJLJL--7L7L7LJ|F7|F---7|FJL--J||L-7F7F-7LJLJF----JF77|F7F---JL-7FJ|LJFJ77JJL-|-J7\n"
".|L-F---JF---7L7F7|L7F-7F7LJFJL7L----77|F--J|FJL7|||FJFJFJ|L--7F--JFJFJF7FJ|||F-7||L--7F-JL7FJ||L7L-7F7L-----JL7LJ|L-----7|L7|F7L7F7JFLF|JF|\n"
"F-|-L-7F7|F--JFJ||L7|L7|||F-JF-JLF7F7L7|L--7|L-7|LJ|L7|7|FJF-7|L7F-JFJFJ||FJLJL7||L7F7|L7F7||FJL7|F-J||F------7|F7L---7F7|L7|LJL7|||.7-LJ-|J\n"
"|-J77FLJLJL7F7L-JL-JL7|LJ||F-JJF-JLJL-JL---J|F-J|F-J|||FJL7L7|L7||F-JJ|FJ||F7F7|||FJ||L7LJ|||L-7LJ|F-J|L----7FJLJL--7FLJLJFJL--7|LJ|JL-J7-7-\n"
"L-7|-||F7F7LJL--7F--7||F-J||F--JF7F--7F7-F7.|||FJ|F7FJ|L7FJFJ|L|||||F7||FJ||LJ||LJL7||JL-7||L7FJF-JL-7L---7FJL-----7|F7F77L----JL7FJJ-7.JL||\n"
"JLLJ-JFJLJL--7F-J|F-JLJL7.LJL-7FJLJF-J||FJL7|L7|FJ|||FJFJL7L7L-JLJ|FJ||||FJL-7|L7F-J|L7F-J||FJL7|F-7-L-7F7LJF7F--7FJLJLJL7LF--7J|LJ.|.77.LL-\n"
"L7|7L-|F7F--7LJF7||F7F-7|F7JF7LJF--JF7|||F-J|FJ|L-J||L-JF7L7L-7F--J|FJ|||||F7||FJL-7|FJL-7|||F7|||FJF7FLJL--JLJF-JL----7FJFJF-J|-|-FF7LF---|\n"
"LF77|FLJLJF-JF7|LJLJLJFJLJL7|L--JF-7|||||L7FJL7L-7FJL-7FJL-JF7||F7FJL7|||L7||||L--7||L7F7|LJ|||||||FJ|F-7F--7F7L-7LF7F7LJ||FJF7F7..-.7-L7|FJ\n"
".||-L-LLF7L-7|||F-7JF-JF--7|L----JFJ||||L7|L7FJF7|||F7||7.F7||||||L7FJ|||FJ||||F7|||L7|||L7FJ|||||||FJ|FJL-7|||F7L-JLJL7F7||7|LJL7FLJ77--.J.\n"
"|-77L.|L||F7LJLJL7L-JF-JF-JL------JFJ||L7|L7||FJ||L7|LJL7FJ||||||L7||FJ||L7|LJ|||FJ|FJ||L7|L7|LJLJ|||FJL7F-J|||||F7F---J||||FJF-7|FLLJL-..|-\n"
"||LJ.FF-JLJL-----JF-7|F-JF-7F7F---7|FJ|J|L7LJ||FJ|FJ|7F-J||LJ||||FJ|||FJL7||F-J|||F|L7|L7||FJL-7F-J||L7FJL-7|||||||L----JLJLJFJ7|L77-77JFF|J\n"
"FJ-L|-L--7F7F-7F-7|FJ|L-7|FJ|||F--J||FJFJFJF7||L7|L7L7|F7L-77||LJL7||||F7|||L-7|||FJFJL7|||L7F7|L7FJL7|L7F-JLJLJLJ|F-7F------J-LL-J.FJL---J7\n"
"|J7-F-|LFJ|LJFJ|FJ|L-J.FJ|L-JLJL-7FJ||LL7|FJLJL7|L7L7|LJ|F7|FJL--7LJ||||LJ|L-7||LJL7|F7LJLJL|||L7|L7FJ|FJL--7F7F-7||.|L-------7|-JJF|J-LJ7F-\n"
"L|J.L-7.L-JF-JFJL7|-F--JFJF------J|FJL77LJL--7FJL-JFJL-7||LJ|F7F-JF-J|||F7L7FJ||F--JLJL7.F7FJ||FJ|FJL7||F7F7LJLJFJ|L7|F7F-7F7FJJ.|.-J|L|L-F7\n"
"L-7|J.LFF--JF7|F-JL7|F7FJ7|F-7F7F7|L7FJF-----JL--7LL-7FJLJF7|||L7JL7FJ|||L-JL7LJL---7F7L7|LJFJLJFJL7FJ|||||L7F-7|FJFJLJ||-LJLJ|-LJ7L-F.L7JLJ\n"
".L|||LF7|F-7||||F7FJLJLJF7||FJ|||LJFJL7L---7F-7F7|F--JL--7||||L7L-7|||LJL7F-7L--7F--J|L7||F7L7F-JF-J|FJ||||LLJ.||L7L-7FJL---7L||.7-F7LL-J77.\n"
"|7|---|LJ|FJ|||LJ|L7F---JLJ|L7||L7FL7FJF---JL7||LJ|F7F--7LJ||L7|F7|||F---JL7|F7FJL7F7L7||||L7|L-7L7FLJFJ||L---7|L7|F-J|F7F-7L7||-|7L|7LFLJFJ\n"
"--J.LF|F7||FJ||F-JFJ|F-7F-7|||||FJF-JL7L--7F-J|L-7||||F-JF7|L-J||||LJL7F-7FJ||||JFJ|L7|||LJFJL-7|FJF7FL7|L7F--J|FJLJF7|||L7L7L77-L7.-7.JJ7J|\n"
".F|.|JLJLJLJLLJL-7L7||FJL7LJFJ||L7L-7FJF--J|F-JF-J||LJL-7||L--7|||L-7FJ|FJL7|||L7L7L7|||L7LL-7FJ|L-JL-7||FJL--7|L--7||LJL7L7L-JJFJ|.FF7-F7F|\n"
"F7J7|F|7||JLFLF-7|FJLJL7FJF-JFJ|FJ-FJ|FJF-7||F7L-7LJF---J|L7F-J|||F-JL7|L7FJ||L-JF|FJ||L7L7F-JL7L--7F7|LJL-7F-JL7F7LJL--7L-J-|7L||L7-7L-FLJJ\n"
"7|LJ-|L|-77.LFL7LJL7JF-JL7L7FJFJ|F-JFJL7|FJ|||L7FJF-JF-7FJFJL-7||||.F-J|FJL7LJF---JL7||JL7|L7F7L--7|||L--7FJL-7FJ|L7F7F7L7F7-F-7JLJ|..--LJ.7\n"
"FJ-|F|-J|F-LJ|.L7F-J-L-7FJFJL7L7||F7|F7LJL7||L7LJ.|F-JFJL7|F7FJ||||FJF7|L7FJ7FJF7F7FJ|L7FJ|J||L7F7|||L7F7|L-7FJL7|FJ|LJL-J||-J7JLL7LLLLF7F7J\n"
"FJLFLL.LL|-JJL7L|L-7-L7LJ||F-JFJ||||||L--7||L7L-7FJL7JL7FJ|||L7||LJL7|LJFJL-7L7|LJ||7|FJL-JFJ|F||LJLJLLJ|L7FJ|F7||L7L---7L||-|FF7.J.LLL7--J7\n"
"L7.FJL.LFFJF-L-FJF-J7LJLF7|L-7L7|||||L7F7LJL7L-7|L7FJF-JL7||L7|LJF--JL7FJF7FJ-|L-7|L7LJF7F7|FJFJL---7F--JFJ|FJ|LJ|FJF7F7L-JL--7LJ7|.FJ.LLJL.\n"
"||-L.J7.LLJ|J|FL7L7J-LLFJLJF-JFJ|||LJFJ|L7F7L-7LJFJL7L-7FJ|L7|L-7L-7F7|L7||L-7|F7||FJF-JLJLJ|JL7F---J|F7FJFJ|FJF7||FJ|||F-7F-7|..L7-|.LJ|7.F\n"
"F|||7FF.J..L.FF7|FJJ|LFL--7|JFL7|||F-JFJFJ|L7FJF-JF7|.FJL7L7|L--JF7||LJFJ||F7|LJ||LJF|F--7F7|F-JL---7LJ||||FJ|FJ||LJJ|||L7|L7LJ--|..L7|FFFFJ\n"
"F|7LL|-7|F||-JLL||J7-FJL|FJL-7-LJLJL7FJ.L-JFJL7|F7|LJFJF7|FJL---7|LJ|F-JFJ|||L-7||JF7||F-J|LJL-7F7F7L7FJL7|L7LJLLJF--J||FJL-J7|JF|7.L-|7L7LJ\n"
"JL7||FJ|LJL-F-7-LJF--||-LL-7FJF--7F7||F-7F-JF-JLJ||F-JFJ|||F7F--JL7FJ|F7L7LJ|F7||L-J|||L7FJF---J|||L7|L--JL-JJ-|FLL---JLJ||LLJJ.||L|JLJ7|.F.\n"
"|FL|-LJ|J7L.J7F-JJ-F-LJ.|7L||LL-7||LJ|L7LJF7L--7-|||F7L7||||LJ-F-7LJFJ||FJF-J|||L-7FJ|L7LJ-L--7FJLJFJL---7F7J.F7-J-L-L|J.L7JFJ..LL-L77LF7.--\n"
"F7JJ7L-JFL.|JF-J|J|||L77|FFLJ-F-J|L--J-L-7||F7FJFJ||||FJLJ|L---JFJF7L7|||FL-7||L-7||F|FJF-----JL-7FJF7F-7LJL-7FJL-.L|L|J7FJ.JF-7J|.F7-J.7-J|\n"
"-J|F77F7|J-JFF7F7F7J7L|LFJ.L7|L-7|7F7F7F-J|LJ||JL7|||||F7FJF-7F-JFJL-J||L7|.LJ|F-J|L7|L7L-----7F-J|FJ||FJF---JJ..|77|.F-77.7|LFJ--F-|L-F.F-J\n"
"FL-L7FLJJ7.LFF-FJ-F-7-7F||FFLF--JL-JLJLJF7L-7||F-J||||LJ|L7|FJL77|F7F7|L7L7-7.|L7FJFJL-J7F---7|L-7|L7||L7L--7|J-F77-7.F7FF7LF---LLF-|L|LL7J.\n"
"F7F||LJJ|FF.F|-.FJFJ|JL7F|F-LL7F-7F7F-7FJ|F-J||L7FJ|||F-JLLJL7FJFLJ||||FJFJ.FFJFJL-J7-|F-|F-7LJF7|L7||L7L7F7L7J77J|FF-L-LJL-|-L--F|..FLFJJ.F\n"
".L|L7L7L-JJ7L|7-FFJ-|7FJJLJJ|7LJL||||FJL7|L-7||FJ|FJ|||J7LJ.|LJLL.LLJ||L-JLFFL7|-JJ-LF-7|LJFJF7|LJ.|||FJFJ|L-JJLL-F7L-7.LJ--|.LL|JL77F|J|..|\n"
"LL7-F.F.F|L-J.FFJ||.-J|JJ||-F-|LFLJ||L7FJ|F7||||FJ|FJLJ-7-LFFLJJ|-F|LLJ-LL--LL||7.L--7JJ77FJFJ|L-7-LJLJLL7L7J.77FF|.LL|-7|..FF--77-7-LJLF|7L\n"
"L|JJ|FJFFJ.|F7JJ|7FFL.||FF7.-.L7|7|LJFJL7LJ||LJLJ.LJJJ|-F7|LJ7.-|.LJ-||-F|-LLFJL77.FFL7|L-L7|FJF-JJL-F|J|L7|J.L-JLJFFJ..LJ7LJ.FLL|L|-F|.7LFL\n"
"F7.F|J-F7-FFJ.LF--LL7FL---|7J.L-|L|FL|F-J7JLJ-L-J-7|F7L7|-F7FJ7F|L|.F7|-FFJFFL7FJ7-F7-F-.L-||L-JFL.LFLJ|LJLJ---7LFL|.LFL.L7L.-LFJL-F-J-FJ-|J\n"
"LJ-FLJFJJ.FJJ7.--F.LJJJL|L|-F7|.J|.|LLJJ.F-LJ-|.LLFJ|F7L|L7-7.F|7F|7L||-FJ.-7JLJJLJL7JL..L7|L-7F-.J-FL-FL.|LL-FFJFJL7.---J||F7.|||FJJ..F-J||\n"
"|JFLL-L7LLJ77.FJ..7||J..|7.FJ7-7L-7L77|F7JFL---||.L.JF-JJJ|LF7.|F7JLFJLF|FJFF7.|LF7|LJ|--7LL--J-|7||L|-JLFF77FLJF|-7JFL7L7J||LJ-L77FJFFJJFJ7\n"
"|.J|FLL7||LLL---J7LL7-7-7-FJ7J.FJ||.LL7FL7L7.F|.7FL77|LJ7-J-F-L7-J7.7.FF.|J|L|.7|L7JF7-7L|FJ|7L7LLJJ7L7.7LJJ7J|-F.7L77LL--7F|-|.-J--.F-..F7.\n"
"L7FL-F-7J|L-|JJ|FL|JJLF-|JLJ|.F|LL..JL|-|-|7-J77J|J|FJ||L-|-|.JJ7.|7L-FJ-7--.L|||7JLF|LF7LJLFJL|7JF.|L7-F--F-J.FL7L7JJ.L-.7JLLJ|.-J-|J-J7LJ-\n"
"|L7FLJ-J-JJJLJ.F7JL|-7|.|.FL-7-J7|.FF|LFLF|JF7|LFJ--F|-FJJJJFJL77-L|J.|J|LJJLFF-L7.F-||.J77.JJJ|L-7-7.|LFJ.||L-7J.FJJFJF|.|L7J.FFJ..LLLJL.|J\n"
"7-||7J|L7.FJLJFF-7.F7FF-7-F-.J.|LJFLL7LF7|J..LJLJ|.|F|7|FLF-||L|77-L-7.FJ|.7.7JJL|7L7-FF-7-L-JF-7|LJ|JJF7-L--7|J-||L7LFF7F|-L7F-J.F7.|.LFFJ7\n"
"L7JJF-7L|-LFJ.L7J|J-|.JL7.F.-J-7LL|J-|-|-J-F.L-7-L|--.LJ-FJ-JJ.LLL.LLF|LL77.JJ.L-|JJLJLJ-F7J..L-LJJL7J-J..|-L--J-J-L7--JFL7-JF|-F77-FLJL-JLJ\n"
;

using Coord = unsigned long;

struct Point {
    Coord x;
    Coord y;
};
bool operator==(const Point p1, const Point p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}
bool operator!=(const Point p1, const Point p2)
{
    return !(p1 == p2);
}

struct Near {
    Point p1;

    Point p2;
};

struct Orient {
    bool internDown;
    bool internRight;
};

} // namespace

auto day10Part2(std::string_view streamSource, bool sourceIsFilePath)
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

    constexpr size_t SeedHash = 10000U;
    static constexpr auto HashPoints = [](const Point p) { return p.x + (SeedHash * p.y); };
    static constexpr auto EquiPoints = [](const Point p1, const Point p2) { return p1 == p2; };

    std::unordered_map<Point, Near, decltype(HashPoints), decltype(EquiPoints)> network(
        0U, HashPoints, EquiPoints);
    Point start{};
    bool startFound = false;

    static const auto pointToStr = [](Point p) {
        using std::literals::string_literals::operator""s;
        return "("s + std::to_string(p.x) + ", " + std::to_string(p.y) + ')';
    };

    std::vector<std::string> rows;

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

        if constexpr (sizeof(Coord) < sizeof(decltype(line.length()))) {
            // TODO, likely... just define Coord as size_t to be sure.
            if (line.length() > std::numeric_limits<Coord>::max()) {
                throw std::invalid_argument(errorLine + "Too long line");
            }
        }

        Coord y = lineCount; // from 1. Use 0 to indicate 'nothing'.
        Coord x = 0U;
        for (auto ch : line) {
            ++x;
            Point p{x, y};

            switch (ch) {
            case '.':
                break;
            case '-':
                network[p] = Near{Point{x - 1U, y}, Point{x + 1U, y}};
                break;
            case '|':
                network[p] = Near{Point{x, y - 1U}, Point{x, y + 1U}};
                break;
            case 'L':
                // turn right toward p1, i.e., turn left toward p2
                network[p] = Near{Point{x, y - 1U}, Point{x + 1U, y}};
                break;
            case 'F':
                // turn left toward p1, i.e., turn right toward p2
                network[p] = Near{Point{x, y + 1U}, Point{x + 1U, y}};
                break;
            case 'J':
                // turn left toward p1, i.e., turn right toward p2
                network[p] = Near{Point{x, y - 1U}, Point{x - 1U, y}};
                break;
            case '7':
                // turn right toward p1, i.e., turn left toward p2
                network[p] = Near{Point{x, y + 1U}, Point{x - 1U, y}};
                break;
            case 'S':
                start = Point{x, y};
                startFound = true;
                break;
            default:
                // TODO: understand why passing here determines printing the message
                // "too few near to start" (thrown below) in the catch clause where
                // the caught exception really has such a message.
                throw std::invalid_argument("unknown symbol: " + std::string(1U, ch));
            }
        }

        rows.emplace_back(std::move(line));
    }

    if (lineCount > SeedHash) {
        std::cout << "WARNING: better to generalize code\n";
        // but still works.
    }

    if (!startFound) {
        throw std::invalid_argument("No start found");
    }

    // Search points connecting to start.
    {
        Point p1{}, p2{};
        unsigned nNearToStart = 0U;
        for (const auto& [p, near] : network) {
            if ((near.p1 == start) || (near.p2 == start)) {
                switch (++nNearToStart) {
                case 1U:
                    p1 = p;
                    break;
                case 2U:
                    p2 = p;
                    break;
                default:
                    // TODO: generalize for the case when multiple points
                    // may move to 'S'. That is, search also which selectable
                    // double-connection from S really leads to a loop and accept
                    // the input if one loop only is possible.
                    std::cout << "p1: " << pointToStr(p1) << '\n';
                    std::cout << "p2: " << pointToStr(p2) << '\n';
                    std::cout << "p3: " << pointToStr(p) << '\n';
                    throw std::invalid_argument("too many near to start, at least 3U");
                }
            }
        }

        if (nNearToStart < 2U) {
            if (nNearToStart == 1) {
                std::cout << "p1: " << pointToStr(p1) << '\n';
            }
            throw std::invalid_argument(
                "too few near to start: " + std::to_string(nNearToStart));
        } // else:
        {
            char ch{};
            if (p1.x == p2.x) {
                ch = '|';
            } else if (p1.y == p2.y) {
                ch = '-';
            } else {
                // push p1 having the same 'x'.
                if (p1.x != start.x) {
                    std::swap(p1, p2);
                }
                // => p1.y != start.y
                // => p2.x != start.x
                // => p2.y == start.y

                if (p1.y > start.y) { // p1 below
                    if (p2.x > start.x) { // p2 on right
                        ch = 'F';
                    } else {
                        ch = '7'; // p2 on left
                    }
                } else { // p1 above
                    if (p2.x > start.x) { // p2 on right
                        ch = 'L';
                    } else {
                        ch = 'J'; // p2 on left
                    }
                }
            }
            rows[start.y - 1U][start.x - 1U] = ch;

            std::cout << "start char is '" << ch << "'\n";
        }

        network[start] = Near{p1, p2};
    }

    // Find the max loop starting from 'p'.
    std::unordered_set<Point, decltype(HashPoints), decltype(EquiPoints)> pipePoints(
        0U, HashPoints, EquiPoints);
    std::list<Point> loopPath;

    pipePoints.insert(start);
    {
        Point scroll = start;
        Point prev = start;
        // std::cout << "Start from " << pointToStr(start) << std::endl;
        while ((scroll != start) || loopPath.empty()) {
            const auto& near = network[scroll];

            // move to next
            static const auto goodPoint = [&network, &prev](const Point& p) {
                return (network.count(p) > 0U) && (p != prev); // avoid to go back
                // Not even possible a special case with loopMax==2U,
                // based on the shape of the connections.
            };

            Point newP{};
            if (goodPoint(near.p1)) {
                newP = near.p1;
            } else if (goodPoint(near.p2)) {
                newP = near.p2;
            } else {
                throw std::invalid_argument(
                    "no move possible anymore at the step n. "
                    + std::to_string(loopPath.size() + 1U));
            }

            prev = scroll;
            scroll = newP;

            // std::cout << "move to " << pointToStr(newP) << std::endl;

            pipePoints.insert(newP);
            loopPath.emplace_back(newP);
        }
    }

    unsigned long long internCount = 0U;

    // To count internal points, lines may be scrolled one by one.
    // On each line, a pipe symbol may switch from in to out and that's all.
    Point p{0U, 0U};
    for (const auto& row : rows) {
        ++p.y;
        p.x = 0U;

        Coord nonPipeBucket = 0U;
        bool inUp = false;
        bool inDown = false;


        const auto excMsg = [&p](std::string head, char ch) {
            head.append(" at ");
            head.append(pointToStr(p));
            head.append(" : ");
            head.push_back(ch);

            return head; // moves
        };

        for (auto ch : row) {
            ++p.x;

            if (pipePoints.count(p) == 0) {
                ++nonPipeBucket;
            } else {
                switch (ch) {
                case '|':
                    if (inUp != inDown) {
                        throw std::runtime_error(excMsg("impossible middle-break", ch));
                    }

                    if (inUp) { // <=> inUp && inDown
                        internCount += nonPipeBucket;
                    }
                    nonPipeBucket = 0U; // in any case (were external if not added)

                    inUp = !inUp;
                    inDown = !inDown;

                    break;
                case 'F':
                    if (inUp != inDown) {
                        if (inUp) {
                            throw std::runtime_error(excMsg("impossible switch-break", ch));
                        } // else
                        {
                            throw std::runtime_error(excMsg("impossible reopen-down", ch));
                        }
                    }

                    if (inDown) {
                        // as starting walking on horizontal pipe trait.
                        internCount += nonPipeBucket;
                    }
                    nonPipeBucket = 0U; // in any case (were external if not added)

                    inDown = !inDown;
                    // inUp unchanged

                    break;
                case 'L':
                    if (inUp != inDown) {
                        if (inDown) {
                            throw std::runtime_error(excMsg("impossible switch-break", ch));
                        } // else
                        {
                            throw std::runtime_error(excMsg("impossible reopen-up", ch));
                        }
                    }

                    if (inUp) {
                        // as starting walking on horizontal pipe trait.
                        internCount += nonPipeBucket;
                    }
                    nonPipeBucket = 0U; // in any case (were external if not added)

                    inUp = !inUp;
                    // inDown unchanged

                    break;
                case '7':
                    if (inUp == inDown) {
                        if (inUp) {
                            throw std::runtime_error(excMsg("impossible middle-break", ch));
                        } // else
                        {
                            throw std::runtime_error(excMsg("impossible middle-open-down", ch));
                        }
                    }

                    /*if (!inDown){
                        //ending walking on horizontal pipe trait.
                        // No need of any job.
                    }*/

                    inDown = !inDown;
                    // inUp unchanged

                    break;
                case 'J':
                    if (inUp == inDown) {
                        if (inDown) {
                            throw std::runtime_error(excMsg("impossible middle-break", ch));
                        } // else
                        {
                            throw std::runtime_error(excMsg("impossible middle-open-up", ch));
                        }
                    }

                    /*if (!inUp){
                        //ending walking on horizontal pipe trait.
                        // No need of any job.
                    }*/

                    inUp = !inUp;
                    // inUp unchanged

                    break;
                case '-':
                    if (inUp == inDown) {
                        throw std::runtime_error(excMsg("impossible middle-continue", ch));
                    }
                    break;
                default:
                    throw std::runtime_error(excMsg("corrupted char", ch));
                }
            }
        }
    }

    std::cout << "Number of lines: " << lineCount << std::endl;
    std::cout << "Start point " << pointToStr(start) << std::endl;
    std::cout << "Max loop " << loopPath.size() << std::endl;
    std::cout << "\nResult: " << internCount << "\n\n\n";

    return internCount;
}

int main10p2()
{
    try {
        day10Part2(Input, false);
        // day10Part2("./10_input_file.txt",true);
    } catch (std::invalid_argument& ex) {
        std::cout << std::endl; // flash
        std::cerr << "Bad input: " << ex.what() << std::endl;
        return 1;
    } catch (std::exception& ex) {
        std::cout << std::endl; // flash
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    } catch (...) {
        std::cout << std::endl; // flash
        std::cerr << "Unknown error: " << std::endl;
        return 1;
    }

    return 0;
}


/*
OUTPUT:

Example 1:
start char is 'F'
Number of lines: 5
Start point (1, 3)
Max loop 16
Result: 1

Example 2:
start char is 'F'
Number of lines: 9
Start point (2, 2)
Max loop 46
Result: 4

Example 3:
start char is 'F'
Number of lines: 10
Start point (13, 5)
Max loop 140
Result: 8

Example 4:
start char is '7'
Number of lines: 10
Start point (5, 1)
Max loop 160
Result: 10

real input:
start char is '|'
Total lines 140
Start point (89, 20)
Max loop 13434
Result: 381
*/
