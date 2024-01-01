#include <string_view>

namespace Day20{

constexpr std::string_view Input =

false ?

/*
"broadcaster -> a, b, c\n"
"%a -> b\n"
"%b -> c\n"
"%c -> inv\n"
"&inv -> a\n"
*/

"broadcaster -> a\n"
"%a -> inv, con\n"
"&inv -> b\n"
"%b -> con\n"
"&con -> output\n"

:

"%bd -> lg, cm\n"
"broadcaster -> ct, hr, ft, qm\n"
"%bh -> lj\n"
"&zz -> th, hr, jk, bh, js\n"
"&js -> cl\n"
"&cl -> rx\n"
"%rn -> ml\n"
"%ks -> xk, kd\n"
"&cm -> jp, sk, ft, dt, gb\n"
"%gk -> qv, kd\n"
"%lg -> cm\n"
"%qd -> jp, cm\n"
"%jk -> fs\n"
"%vq -> qj, kd\n"
"%lj -> cx, zz\n"
"%th -> bh\n"
"%rp -> bk, cm\n"
"%xk -> nv, kd\n"
"%qv -> ks\n"
"%mj -> xg, mh\n"
"%lh -> zz, pz\n"
"&mh -> ct, qs, vs, vk, pg\n"
"%kb -> hv, kd\n"
"%pg -> lz\n"
"%qm -> kb, kd\n"
"%pc -> cm, xl\n"
"%hv -> kd, rn\n"
"%fr -> fl, mh\n"
"%mp -> zz\n"
"%xl -> cm, gb\n"
"%tp -> mh\n"
"%gb -> rp\n"
"%pz -> mf, zz\n"
"%qn -> cm, sk\n"
"%fl -> tp, mh\n"
"%zq -> th, zz\n"
"%sk -> qd\n"
"%tk -> mh, vk\n"
"%bk -> bd, cm\n"
"%ml -> gk\n"
"%jg -> fr, mh\n"
"%nv -> vq, kd\n"
"%xg -> mh, vs\n"
"%hr -> zz, zq\n"
"%vk -> jg\n"
"%qj -> kd\n"
"&qs -> cl\n"
"%cx -> jk, zz\n"
"%mf -> mp, zz\n"
"&dt -> cl\n"
"%lz -> tk, mh\n"
"%vs -> pg\n"
"%ct -> mh, mj\n"
"%jp -> pc\n"
"%ft -> qn, cm\n"
"%fs -> zz, lh\n"
"&kd -> qm, ml, ts, qv, rn\n"
"&ts -> cl\n"

;

} // namespace Day20

unsigned long day20Part1(std::string_view streamSource, bool sourceIsFilePath);
unsigned long day20Part2(std::string_view streamSource, bool sourceIsFilePath);