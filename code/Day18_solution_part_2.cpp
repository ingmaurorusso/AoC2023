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

namespace{

constexpr std::string_view Input =

false ?

"R 6 (#70c710)\n"
"D 5 (#0dc571)\n"
"L 2 (#5713f0)\n"
"D 2 (#d2c081)\n"
"R 2 (#59c680)\n"
"D 2 (#411b91)\n"
"L 5 (#8ceee2)\n"
"U 2 (#caa173)\n"
"L 1 (#1b58a2)\n"
"U 2 (#caa171)\n"
"R 2 (#7807d2)\n"
"U 3 (#a77fa3)\n"
"L 2 (#015232)\n"
"U 2 (#7a21e3)\n"

:

"L 4 (#3b05c0)\n"
"U 7 (#9ccb53)\n"
"L 7 (#b37500)\n"
"D 2 (#88c1c3)\n"
"L 2 (#17a960)\n"
"D 10 (#d78923)\n"
"L 4 (#5e2830)\n"
"D 7 (#889403)\n"
"L 9 (#172fc2)\n"
"U 7 (#1dff43)\n"
"L 2 (#5b9832)\n"
"U 12 (#121513)\n"
"L 3 (#be4c92)\n"
"U 5 (#121511)\n"
"L 7 (#3337d2)\n"
"U 5 (#3a59f3)\n"
"R 7 (#775a10)\n"
"U 6 (#161c23)\n"
"L 7 (#134750)\n"
"U 6 (#e05843)\n"
"R 8 (#69cd12)\n"
"U 2 (#467933)\n"
"R 3 (#8f52f2)\n"
"U 5 (#6706d3)\n"
"L 7 (#840c60)\n"
"U 3 (#7e7463)\n"
"L 4 (#7513a0)\n"
"U 3 (#7bf2d3)\n"
"R 3 (#ae9d42)\n"
"U 8 (#8a9dd3)\n"
"R 3 (#536812)\n"
"U 3 (#36b703)\n"
"R 8 (#7144f2)\n"
"U 7 (#83ae83)\n"
"R 5 (#238092)\n"
"U 3 (#83ae81)\n"
"R 4 (#758bb2)\n"
"U 5 (#00eaf3)\n"
"R 6 (#c78c12)\n"
"U 5 (#8501b3)\n"
"L 4 (#6a6d90)\n"
"U 5 (#663513)\n"
"R 6 (#a57700)\n"
"U 4 (#677833)\n"
"L 6 (#a22710)\n"
"U 5 (#13f923)\n"
"L 5 (#1fd1a0)\n"
"D 6 (#441a23)\n"
"L 3 (#b3dca0)\n"
"D 8 (#05b553)\n"
"L 3 (#4e28b0)\n"
"U 9 (#95e4d3)\n"
"L 4 (#3def80)\n"
"U 4 (#44afe1)\n"
"L 4 (#21ee50)\n"
"U 8 (#428591)\n"
"L 6 (#576120)\n"
"U 7 (#7839a1)\n"
"R 8 (#8686f0)\n"
"U 2 (#babf33)\n"
"R 4 (#3d8f90)\n"
"U 7 (#44afe3)\n"
"R 3 (#a4aa30)\n"
"U 7 (#7461a3)\n"
"R 4 (#3738c0)\n"
"U 7 (#6e5413)\n"
"L 7 (#122532)\n"
"U 5 (#372073)\n"
"R 7 (#122530)\n"
"U 3 (#755d93)\n"
"R 5 (#32b3d2)\n"
"U 7 (#c58be3)\n"
"R 7 (#7fe1e2)\n"
"U 4 (#5888e3)\n"
"R 7 (#06b0b2)\n"
"U 6 (#57fb61)\n"
"R 4 (#932122)\n"
"U 4 (#64bac1)\n"
"R 5 (#400e72)\n"
"U 8 (#615ea1)\n"
"R 6 (#cac272)\n"
"U 9 (#370f93)\n"
"L 5 (#bf3d40)\n"
"U 4 (#8bd443)\n"
"L 6 (#1d6be0)\n"
"U 4 (#5c9943)\n"
"L 4 (#ad0200)\n"
"U 4 (#4ecdb3)\n"
"R 10 (#678230)\n"
"U 5 (#5d6fb1)\n"
"R 5 (#84c0e0)\n"
"U 2 (#5d6fb3)\n"
"R 3 (#44cbe0)\n"
"U 9 (#5db673)\n"
"L 3 (#15f5a0)\n"
"U 3 (#4b6dd3)\n"
"L 2 (#3ea330)\n"
"U 2 (#1be133)\n"
"L 10 (#643292)\n"
"D 5 (#8702b3)\n"
"L 10 (#53c452)\n"
"U 3 (#1e2753)\n"
"R 6 (#353852)\n"
"U 5 (#41b5c3)\n"
"R 8 (#6a8132)\n"
"U 2 (#2d5753)\n"
"R 4 (#874862)\n"
"U 2 (#2d5751)\n"
"R 7 (#53b102)\n"
"U 5 (#2d3f23)\n"
"R 4 (#1161b0)\n"
"U 7 (#b8f5c3)\n"
"R 5 (#036990)\n"
"U 7 (#138ad3)\n"
"L 8 (#47a7d0)\n"
"U 4 (#813631)\n"
"L 6 (#1c4ee0)\n"
"U 5 (#421741)\n"
"L 3 (#909fd0)\n"
"D 5 (#a2bd43)\n"
"L 9 (#0321e0)\n"
"U 5 (#209033)\n"
"L 6 (#35ba20)\n"
"U 9 (#138ad1)\n"
"R 7 (#414390)\n"
"D 6 (#2272c1)\n"
"R 6 (#5df4c0)\n"
"U 6 (#968301)\n"
"R 5 (#62c5d0)\n"
"U 4 (#366641)\n"
"R 3 (#1e9952)\n"
"D 9 (#8c71d1)\n"
"R 7 (#1e9950)\n"
"U 9 (#287e11)\n"
"R 4 (#21e850)\n"
"U 3 (#90fd21)\n"
"R 4 (#5b1c52)\n"
"D 5 (#3dd851)\n"
"R 2 (#0353a0)\n"
"D 7 (#a37241)\n"
"R 4 (#0353a2)\n"
"U 7 (#046661)\n"
"R 2 (#5b1c50)\n"
"U 5 (#228711)\n"
"R 6 (#2820a0)\n"
"D 7 (#2f77a1)\n"
"R 2 (#92c4e0)\n"
"D 5 (#038e51)\n"
"R 5 (#617e32)\n"
"D 4 (#8240e1)\n"
"R 3 (#84f1d0)\n"
"D 5 (#4d0051)\n"
"R 6 (#84f1d2)\n"
"D 3 (#4b6571)\n"
"R 8 (#617e30)\n"
"D 4 (#6712c1)\n"
"R 6 (#703990)\n"
"D 2 (#11f981)\n"
"R 7 (#e3f2e0)\n"
"D 7 (#06a011)\n"
"R 3 (#86de00)\n"
"D 3 (#673f33)\n"
"R 3 (#8c8820)\n"
"D 7 (#4eb723)\n"
"R 7 (#645e80)\n"
"D 3 (#b5f651)\n"
"R 10 (#8a2430)\n"
"U 2 (#89f4d1)\n"
"R 2 (#050a70)\n"
"U 5 (#45ab31)\n"
"L 6 (#3daa70)\n"
"U 2 (#8ed951)\n"
"R 6 (#25e9c0)\n"
"U 6 (#693c91)\n"
"R 5 (#93df80)\n"
"U 8 (#9644d3)\n"
"R 2 (#7a8230)\n"
"U 4 (#9644d1)\n"
"R 7 (#affd70)\n"
"D 6 (#54ddb1)\n"
"R 8 (#0d9e70)\n"
"D 4 (#0888b1)\n"
"R 7 (#0b2b30)\n"
"D 9 (#0dcc91)\n"
"L 7 (#64dcc0)\n"
"D 6 (#91d211)\n"
"R 4 (#1a0d80)\n"
"D 2 (#53c0f1)\n"
"R 5 (#4c0310)\n"
"D 4 (#0122b1)\n"
"R 2 (#d61882)\n"
"D 11 (#6cb921)\n"
"R 5 (#82d122)\n"
"D 2 (#61e653)\n"
"R 8 (#5d4ab2)\n"
"U 5 (#7ec313)\n"
"R 6 (#4e5192)\n"
"U 3 (#99ef93)\n"
"R 3 (#b18092)\n"
"U 6 (#1fc273)\n"
"R 5 (#665bc2)\n"
"D 5 (#afc9d1)\n"
"R 2 (#0f03f2)\n"
"D 4 (#a92be1)\n"
"R 9 (#6b0542)\n"
"D 5 (#30f231)\n"
"R 9 (#7a0930)\n"
"U 5 (#107381)\n"
"R 4 (#22d782)\n"
"U 10 (#34af91)\n"
"L 4 (#70f2c2)\n"
"U 5 (#34af93)\n"
"R 7 (#278b62)\n"
"D 4 (#1169b1)\n"
"R 8 (#556022)\n"
"D 2 (#159651)\n"
"R 6 (#6547c2)\n"
"D 4 (#a2f3e3)\n"
"L 2 (#43cf72)\n"
"D 2 (#a2f3e1)\n"
"L 9 (#5e80a2)\n"
"D 3 (#439c61)\n"
"L 3 (#5af2d2)\n"
"D 5 (#538dc1)\n"
"R 6 (#1b7680)\n"
"D 7 (#a265e1)\n"
"R 5 (#938a70)\n"
"D 6 (#459c41)\n"
"L 8 (#55f7e0)\n"
"D 3 (#47c5f1)\n"
"R 8 (#30fc72)\n"
"D 4 (#066f11)\n"
"R 5 (#875572)\n"
"U 5 (#7eaa11)\n"
"R 3 (#4ca6f2)\n"
"U 8 (#1c3191)\n"
"R 3 (#60edd2)\n"
"U 3 (#1621c1)\n"
"R 9 (#42bb90)\n"
"U 7 (#84add1)\n"
"R 4 (#a3c300)\n"
"D 6 (#84add3)\n"
"R 6 (#1d6e70)\n"
"D 4 (#028311)\n"
"R 12 (#57ec70)\n"
"D 2 (#70a6e1)\n"
"R 4 (#9a3380)\n"
"D 9 (#6e24f1)\n"
"R 5 (#4cba10)\n"
"D 7 (#decbd3)\n"
"R 7 (#2f3010)\n"
"U 7 (#028313)\n"
"R 3 (#0ad150)\n"
"D 4 (#6b7271)\n"
"R 3 (#4ba390)\n"
"U 6 (#574e51)\n"
"R 8 (#9ce7e0)\n"
"U 5 (#2223e3)\n"
"R 10 (#8b33b0)\n"
"U 3 (#a09ce3)\n"
"R 2 (#23f6e0)\n"
"U 11 (#91a151)\n"
"R 5 (#28c8e0)\n"
"U 6 (#4b1ea1)\n"
"L 5 (#58c292)\n"
"U 6 (#5a4961)\n"
"L 8 (#29f382)\n"
"D 6 (#2a72e1)\n"
"L 4 (#c70bb2)\n"
"U 9 (#2a72e3)\n"
"R 4 (#1f2592)\n"
"U 5 (#57e761)\n"
"R 7 (#4cda90)\n"
"U 2 (#035b73)\n"
"R 3 (#d3a710)\n"
"U 3 (#035b71)\n"
"R 4 (#4865b0)\n"
"U 5 (#6dc6a1)\n"
"R 6 (#28c8e2)\n"
"D 3 (#3efa01)\n"
"R 7 (#779652)\n"
"U 3 (#966c01)\n"
"R 2 (#08e862)\n"
"U 4 (#0e11a1)\n"
"R 8 (#3a6142)\n"
"D 7 (#5c49c1)\n"
"R 4 (#054370)\n"
"D 5 (#1f0881)\n"
"L 2 (#054372)\n"
"D 5 (#752fa1)\n"
"L 7 (#6b97c2)\n"
"U 5 (#29adc1)\n"
"L 4 (#5ee480)\n"
"D 5 (#657901)\n"
"L 4 (#628ed0)\n"
"D 3 (#708781)\n"
"L 4 (#c17352)\n"
"D 7 (#7ee9d1)\n"
"R 6 (#a7e4b2)\n"
"D 10 (#0287d1)\n"
"R 6 (#7233e2)\n"
"D 9 (#08e581)\n"
"R 4 (#588172)\n"
"D 2 (#d6cf61)\n"
"R 5 (#3ca6b2)\n"
"D 5 (#8ff473)\n"
"R 2 (#24ffa2)\n"
"D 6 (#4fc073)\n"
"R 4 (#0057f2)\n"
"D 8 (#6e9b91)\n"
"L 3 (#089c12)\n"
"D 5 (#56c251)\n"
"L 3 (#827ba2)\n"
"D 9 (#07f9f1)\n"
"L 4 (#2c0de2)\n"
"U 2 (#2d9f71)\n"
"L 6 (#a6bdd2)\n"
"U 8 (#534e41)\n"
"L 3 (#8d2960)\n"
"U 4 (#592ee1)\n"
"L 3 (#ad94c0)\n"
"D 5 (#69bd71)\n"
"L 7 (#3c5d40)\n"
"D 3 (#a25bf1)\n"
"L 2 (#88dda0)\n"
"D 8 (#687061)\n"
"L 2 (#92cef0)\n"
"D 2 (#690113)\n"
"L 10 (#0e3ce0)\n"
"D 3 (#a1cb43)\n"
"L 7 (#07c0b0)\n"
"D 8 (#5426f1)\n"
"L 7 (#7d1c80)\n"
"D 3 (#06cb31)\n"
"R 6 (#392870)\n"
"D 2 (#d2c171)\n"
"R 9 (#0d53c0)\n"
"D 4 (#3baf61)\n"
"L 9 (#4ec030)\n"
"D 4 (#02f2c3)\n"
"L 6 (#8aadf0)\n"
"D 3 (#02f2c1)\n"
"L 8 (#0aaae0)\n"
"D 3 (#03cfa1)\n"
"R 4 (#087c20)\n"
"D 10 (#3cd711)\n"
"L 4 (#66d142)\n"
"D 3 (#08e551)\n"
"L 5 (#a75212)\n"
"D 7 (#2277d1)\n"
"L 4 (#8409a2)\n"
"D 7 (#a66481)\n"
"L 7 (#1ffb60)\n"
"D 9 (#2041f1)\n"
"L 6 (#a7a760)\n"
"D 6 (#315b31)\n"
"L 5 (#352770)\n"
"D 4 (#67d6c1)\n"
"L 6 (#91fdd0)\n"
"D 6 (#461601)\n"
"L 7 (#7732a0)\n"
"D 4 (#3fe621)\n"
"L 4 (#b1d530)\n"
"D 5 (#364e31)\n"
"R 4 (#3740c0)\n"
"D 7 (#38bd21)\n"
"L 6 (#52e6f2)\n"
"D 5 (#390041)\n"
"L 6 (#1abff0)\n"
"D 2 (#a3d5b1)\n"
"L 3 (#1abff2)\n"
"D 8 (#0816d1)\n"
"L 4 (#468af2)\n"
"D 6 (#264353)\n"
"R 4 (#4d46e2)\n"
"D 6 (#b33e83)\n"
"L 8 (#4d46e0)\n"
"D 3 (#0b6af3)\n"
"R 7 (#4fa412)\n"
"D 3 (#43c8c1)\n"
"R 4 (#01b542)\n"
"D 5 (#6690a3)\n"
"L 4 (#d6fab2)\n"
"D 4 (#6f0f53)\n"
"L 7 (#82b282)\n"
"D 3 (#a6ecc1)\n"
"L 5 (#0ecea2)\n"
"D 4 (#2eb331)\n"
"L 6 (#3315f2)\n"
"D 5 (#a3b781)\n"
"L 7 (#68b3a2)\n"
"U 6 (#6d7571)\n"
"L 7 (#8c7ea0)\n"
"U 3 (#26c711)\n"
"L 8 (#14bba0)\n"
"U 5 (#ac23a1)\n"
"L 8 (#a13a42)\n"
"U 4 (#3ea631)\n"
"L 6 (#1dcc02)\n"
"U 6 (#5b70a1)\n"
"L 3 (#1d51a2)\n"
"U 6 (#991d63)\n"
"L 3 (#8f1392)\n"
"U 4 (#991d61)\n"
"L 7 (#419f52)\n"
"U 3 (#75fba3)\n"
"L 3 (#324ec2)\n"
"U 3 (#adb673)\n"
"L 3 (#9f02c2)\n"
"U 3 (#3ac471)\n"
"L 5 (#17eda2)\n"
"U 4 (#15b3e1)\n"
"L 5 (#3a32a2)\n"
"U 5 (#d339c1)\n"
"L 3 (#3abd12)\n"
"U 5 (#5b70a3)\n"
"R 6 (#53bc52)\n"
"U 4 (#b2d4c3)\n"
"R 3 (#530272)\n"
"U 5 (#2dbb53)\n"
"R 5 (#43fcd2)\n"
"U 3 (#603603)\n"
"R 8 (#4835d2)\n"
"U 5 (#93a603)\n"
"L 5 (#1e0e82)\n"
"U 2 (#37fff3)\n"
"L 8 (#8fed80)\n"
"U 4 (#4cbd33)\n"
"L 6 (#1a53a0)\n"
"U 2 (#aa1d43)\n"
"L 3 (#530270)\n"
"U 6 (#a87e03)\n"
"L 4 (#07da10)\n"
"U 9 (#7b0c33)\n"
"L 4 (#2412f0)\n"
"U 3 (#3ac983)\n"
"L 8 (#7ffb80)\n"
"U 5 (#ad4a21)\n"
"L 6 (#660320)\n"
"U 3 (#ad4a23)\n"
"L 3 (#1e60b0)\n"
"U 6 (#03a1c3)\n"
"R 6 (#0d92f2)\n"
"U 6 (#83cb03)\n"
"R 2 (#b4c392)\n"
"U 4 (#83cb01)\n"
"R 4 (#6df5d2)\n"
"U 4 (#347e43)\n"
"R 2 (#3b9262)\n"
"U 4 (#4d0963)\n"
"R 7 (#9c3dc2)\n"
"U 3 (#303963)\n"
"L 3 (#9d4772)\n"
"U 10 (#374ab3)\n"
"L 3 (#24ea32)\n"
"U 9 (#0e5ba3)\n"
"L 5 (#3ca720)\n"
"U 3 (#292293)\n"
"L 11 (#993be0)\n"
"U 3 (#2a88b3)\n"
"L 4 (#177f92)\n"
"U 5 (#843e43)\n"
"L 9 (#be6372)\n"
"D 5 (#0d45a3)\n"
"R 5 (#2d63f2)\n"
"D 4 (#1509f3)\n"
"R 4 (#a5eea2)\n"
"D 3 (#764283)\n"
"R 7 (#5070a2)\n"
"D 4 (#2180e3)\n"
"R 5 (#34e012)\n"
"D 5 (#757a13)\n"
"L 6 (#34e010)\n"
"D 5 (#729d13)\n"
"L 7 (#5a6472)\n"
"U 5 (#112493)\n"
"L 4 (#7bc2c2)\n"
"D 5 (#2510e3)\n"
"L 4 (#9c0a92)\n"
"D 4 (#131863)\n"
"L 4 (#8be052)\n"
"D 4 (#4caca1)\n"
"L 3 (#20b432)\n"
"D 9 (#60a703)\n"
"L 3 (#5275e2)\n"
"U 4 (#dc4313)\n"
"L 3 (#395152)\n"
"U 9 (#dc4311)\n"
"L 3 (#6c9ad2)\n"
"U 5 (#60a701)\n"
"L 2 (#22a1a2)\n"
"U 6 (#0ac771)\n"
"R 8 (#73bf42)\n"
"U 4 (#275271)\n"
"L 8 (#5ce540)\n"
"U 5 (#4fba31)\n"
"L 3 (#581a70)\n"
"U 3 (#528d11)\n"
"R 9 (#b4ffb2)\n"
"U 2 (#4bcb41)\n"
"R 2 (#1304f0)\n"
"U 5 (#423c71)\n"
"L 11 (#441b40)\n"
"U 5 (#27b871)\n"
"L 3 (#bfcce0)\n"
"D 7 (#27b873)\n"
"L 3 (#988a00)\n"
"D 3 (#4841f1)\n"
"L 7 (#1f5e02)\n"
"D 3 (#471301)\n"
"L 5 (#674332)\n"
"D 5 (#4077b1)\n"
"L 4 (#9d03b2)\n"
"D 6 (#7bf3b1)\n"
"L 2 (#04b082)\n"
"D 4 (#ba5663)\n"
"L 5 (#95ffd2)\n"
"D 5 (#249f53)\n"
"L 8 (#03a442)\n"
"D 3 (#7911a3)\n"
"L 4 (#03a440)\n"
"D 3 (#992453)\n"
"L 4 (#467c72)\n"
"U 13 (#5c2e63)\n"
"L 3 (#c60ca2)\n"
"D 11 (#43b263)\n"
"L 2 (#c60ca0)\n"
"D 2 (#69c963)\n"
"L 4 (#3ef652)\n"
"D 5 (#05a3a3)\n"
"R 8 (#166472)\n"
"D 3 (#a398f3)\n"
"R 5 (#037ee2)\n"
"D 3 (#4d21a3)\n"
"R 4 (#a90f62)\n"
"D 5 (#4ca5c3)\n"
"R 8 (#a00b90)\n"
"D 2 (#140e23)\n"
"R 3 (#8d5c80)\n"
"D 3 (#05fa23)\n"
"R 10 (#78c0b0)\n"
"D 6 (#603a53)\n"
"R 6 (#4b7682)\n"
"D 4 (#2b2333)\n"
"R 7 (#7bc3a2)\n"
"D 6 (#5eaa03)\n"
"L 8 (#760b92)\n"
"D 4 (#881bb3)\n"
"L 3 (#8e47f2)\n"
"D 4 (#297df3)\n"
"L 8 (#56ad00)\n"
"D 4 (#0408e3)\n"
"L 5 (#56ade0)\n"
"D 4 (#d627f3)\n"
"L 12 (#2c1580)\n"
"D 3 (#395e43)\n"
"L 2 (#971660)\n"
"D 3 (#815ff3)\n"
"R 5 (#08d170)\n"
"D 9 (#16e141)\n"
"R 3 (#176840)\n"
"U 9 (#9575f1)\n"
"R 6 (#0cd362)\n"
"D 4 (#266661)\n"
"L 3 (#0cd360)\n"
"D 10 (#b46e81)\n"
"L 5 (#176842)\n"
"D 8 (#0dc2f1)\n"
"L 7 (#523570)\n"
"D 3 (#6bd893)\n"
"R 4 (#72c810)\n"
"D 7 (#129a11)\n"
"R 2 (#3d0540)\n"
"D 8 (#5ea281)\n"
"R 3 (#401cd2)\n"
"U 6 (#1c7f41)\n"
"R 2 (#be6752)\n"
"U 7 (#1c7f43)\n"
"R 2 (#53f6c2)\n"
"U 2 (#4797a1)\n"
"R 4 (#17f752)\n"
"U 4 (#6ebfc1)\n"
"R 9 (#3ce9a0)\n"
"D 5 (#5f5a23)\n"
"R 5 (#6b2ff0)\n"
"D 9 (#263df3)\n"
"L 5 (#7e0220)\n"
"D 5 (#859811)\n"
"R 3 (#445680)\n"
"D 3 (#5672a1)\n"
"L 4 (#40d370)\n"
"D 9 (#59d2e1)\n"
"L 3 (#5b3140)\n"
"D 3 (#359a61)\n"
"L 9 (#6899d0)\n"
"D 4 (#140e21)\n"
"L 4 (#380660)\n"
"U 7 (#4ccd23)\n"
"L 9 (#82a732)\n"
"D 5 (#7983e3)\n"
"L 8 (#82a730)\n"
"D 8 (#3fb533)\n"
"L 7 (#56cb72)\n"
"D 7 (#588163)\n"
"L 4 (#366172)\n"
"U 13 (#543c33)\n"

;

using Coord = size_t;

struct Point {
    Coord x;
    Coord y;
};
bool operator==(const Point p1, const Point p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}
/*
bool operator<(const Point p1, const Point p2){
    if (p1.y < p2.y) return true;
    if (p1.y > p2.y) return false;
    return (p1.x < p2.x);
}
*/
bool operator!=(const Point p1, const Point p2)
{
    return !(p1 == p2);
}
std::string pointToStr(Point p) {
    using std::literals::string_literals::operator""s;
    return "("s + std::to_string(p.x) + ", " + std::to_string(p.y) + ')';
}

enum class Direction { Right, Down, Left, Up };
template<typename E>
constexpr auto toUnderlying(const E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

bool toUnsigned(const std::string& s, unsigned long& res) {
    try {
        if (s.empty()) {
            return false;
        }
        if (!std::all_of(std::next(s.cbegin()), s.cend(), [](const char ch) {
                return std::isdigit(ch); // avoid first, with '-' in order to allow '-0'.
            })) {
            // stoul would ignore tailing non-digits.
            // Here ignore first char, that is, allowing '-' (specific check later for future use).
            return false;
        }
        res = std::stoul(s);
        // Note also that stoul would have converted into unsigned a value starting with minus
        // ('-').

        if (s.find('-') != std::string::npos) {
            // stoul converts negative values with a reinterpret cast.
            if (s.substr(0U, 2U) != "-0") {
                return false;
            }
        }

        return errno != ERANGE;
    } catch (...) {
        // std::invalid_argument, eventually std::out_of_range
        return false;
    }
}

bool hexToUnsigned(const std::string& s, unsigned long& res) {
    try {
        if (s.empty()) {
            return false;
        }
        if (!std::all_of(s.cbegin(), s.cend(), [](const char ch) {
                return (std::isdigit(ch) || ((ch >= 'a') && (ch <= 'f'))
                        || ((ch >= 'A') && (ch <= 'F')));
            })) {
            // operator>> would ignore tailing non-digits (TODO: check if so).
            return false;
        }

        std::stringstream ss;
        ss << std::hex << s;
        if (ss >> res) {
            return true;
        }

        return true;
    } catch (...) {
    }

    return false;
}

struct TraitDir {
    // Coord firstPos; // minimum -> in the key of the map
    char firstChar;

    Coord lastPos; // maximum
    char lastChar;
};

struct VertTrait {
    Coord x;
    Coord yMin;
    Coord yMax;
};
bool operator<(const VertTrait& v1, const VertTrait& v2)
{
    if (v1.x != v2.x) {
        return v1.x < v2.x;
    }
    if (v1.yMin != v2.yMin) {
        return v1.yMin < v2.yMin;
    }
    return v1.yMax < v2.yMax;
}

constexpr bool UseRgb = true; // false to switch to first part.

} // namespace

auto day18Part2(std::string_view streamSource, bool sourceIsFilePath)
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

    using Quantity = Coord; // should be Coord^2

    // std::unordered_map<std::string> lines; TODO: to record '#'
    using LineDir = std::map<Coord, TraitDir>;
    using LinesDir = std::map<Coord, LineDir>;
    LinesDir linesDir;

    Quantity cubes = 1U;

    Direction oldDir{};
    Direction firstDir{};

    using Dir = Direction;

    Point currPos{0U, 0U};

    // 'U' = unconstrained
    const auto movePointU = [](Point& p, Dir d, Coord stepMoreThan1 = 0U) {
        const Coord step = stepMoreThan1 + 1U; // include now the first.
        switch (d) {
        case Dir::Down: {
            if (step > std::numeric_limits<Coord>::max() - p.y) {
                return false;
            }
            p.y += step;
        } break;
        case Dir::Up:
            if (step > p.y) {
                return false;
            }
            p.y -= step;
            break;
        case Dir::Right: {
            if (step > std::numeric_limits<Coord>::max() - p.x) {
                return false;
            }
            p.x += step;
        } break;
        case Dir::Left:
            if (step > p.x) {
                return false;
            }
            p.x -= step;
            break;
        default:
            return false;
        }

        return true;
    };

    const auto printLines = [](const LinesDir& cLinesDir) {
        /* TODO: implement something
        std::cout << "\n";
        for(const auto& line : lines){
            std::cout << line << std::endl;
        }
        std::cout << "\n\n";*/
        ;
    };

    static const auto getTurn = [](Dir prevDir, Dir nextdir, bool avoidTurnWarn = false) {
        bool turnWarn = false;
        bool opposite = false;
        char resNonTurn{};

        switch (nextdir) {
        case Dir::Right:
            switch (prevDir) {
            case Dir::Up:
                return 'F';
            case Dir::Down:
                return 'L';
            case Dir::Left:
                opposite = true;
                break;
            case Dir::Right:
                turnWarn = true;
                resNonTurn = '-';
                break;
            default:
                // goes to throw
                ;
            }
            break;

        case Dir::Down:
            switch (prevDir) {
            case Dir::Right:
                return '7';
            case Dir::Left:
                return 'F';
            case Dir::Up:
                opposite = true;
                break;
            case Dir::Down:
                turnWarn = true;
                resNonTurn = '|';
                break;
            default:
                // goes to throw
                ;
            }
            break;

        case Dir::Left:
            switch (prevDir) {
            case Dir::Up:
                return '7';
            case Dir::Down:
                return 'J';
            case Dir::Right:
                opposite = true;
                break;
            case Dir::Left:
                turnWarn = true;
                resNonTurn = '-';
                break;
            default:
                // goes to throw
                ;
            }
            break;

        case Dir::Up:
            switch (prevDir) {
            case Dir::Right:
                return 'J';
            case Dir::Left:
                return 'L';
            case Dir::Down:
                opposite = true;
                break;
            case Dir::Up:
                turnWarn = true;
                resNonTurn = '|';
                break;
            default:
                // goes to throw
                ;
            }
            break;
        }

        if (opposite) {
            // TODO: print dir enum names
            throw std::runtime_error("Opposite dig move not managed !");
        } // else:
        if (turnWarn) {
            if (!avoidTurnWarn) {
                // TODO: print dir enum names
                std::cout << "Turn is not turn\n";
            }
            return resNonTurn;
        }

        throw std::runtime_error("bad nextDir!");
    };

    Coord startX = 0;
    Coord startY = 0;

    std::list<std::pair<Dir, Coord>> digMoves;
    size_t countDirJokes = 0U;

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

        std::stringstream lineStream;
        lineStream << line;

        /*
                    if (lineCount == 1U) {
                        rowsLength = line.size();
                    } else if (rowsLength != line.size()) {
                        throw std::invalid_argument(errorLine + "line length different from
            preious ones");
                    }

                    for (const char ch : line) {
                        if (!std::isdigit(ch)) {
                            throw std::invalid_argument(
                                errorLine + "non-digit character: " + std::string(1U, ch));
                        }
                    }
        */

        char chDir{};
        if (!(lineStream >> chDir)) {
            throw std::invalid_argument(errorLine + "missing dig direction");
        }

        std::string digLenStr;
        if (!(lineStream >> digLenStr)) {
            throw std::invalid_argument(errorLine + "missing dig length");
        }

        std::string rgbCodeStr;
        if (!(lineStream >> rgbCodeStr)) {
            throw std::invalid_argument(errorLine + "missing dig length");
        }
        {
            char ch{};
            if (lineStream >> ch) {
                throw std::invalid_argument(errorLine + "unexpected further data");
            }
        }

        unsigned long digLen{};
        if (!toUnsigned(digLenStr, digLen)) {
            // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
            throw std::invalid_argument(errorLine + "dig length not numeric: " + digLenStr);
        }
        if (digLen == 0U) {
            throw std::invalid_argument(errorLine + "dig length zero");
        }

        Dir dir{};
        switch (chDir) {
        case 'R':
            dir = Dir::Right;
            break;
        case 'D':
            dir = Dir::Down;
            break;
        case 'L':
            dir = Dir::Left;
            break;
        case 'U':
            dir = Dir::Up;
            break;
        default:
            throw std::invalid_argument(errorLine + "unexpected char-dir");
        }

        Dir dirJoke = dir;

        if constexpr (UseRgb) {
            constexpr auto LengthRgbCode = 9U;
            constexpr auto OpenInRgbCode = 0U;
            constexpr auto CloseInRgbCode = 8U;
            constexpr auto DirInRgbCode = 7U;
            constexpr auto SharpInRgbCode = 1U;
            constexpr auto StartDeltaInRgbCode = 2U;
            constexpr auto LenDeltaInRgbCode = 5U;
            if (rgbCodeStr.size() != LengthRgbCode) {
                throw std::invalid_argument(errorLine + "RGB code length wrong");
            }
            if ((rgbCodeStr[OpenInRgbCode] != '(') || (rgbCodeStr[CloseInRgbCode] != ')')
                || (rgbCodeStr[SharpInRgbCode] != '#')) {
                throw std::invalid_argument(errorLine + "RGB code wrong format wrong");
            }

            switch (rgbCodeStr[DirInRgbCode]) {
            case '0':
                dir = Dir::Right;
                break;
            case '1':
                dir = Dir::Down;
                break;
            case '2':
                dir = Dir::Left;
                break;
            case '3':
                dir = Dir::Up;
                break;
            default:
                throw std::invalid_argument(
                    errorLine + "unexcpected encode for dir in RGB code");
            }

            if (dir != dirJoke) {
                ++countDirJokes;
            }

            rgbCodeStr = rgbCodeStr.substr(StartDeltaInRgbCode, LenDeltaInRgbCode);
            if (!hexToUnsigned(rgbCodeStr, digLen)) {
                throw std::invalid_argument(
                    // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                    errorLine + "dig length in RGB code not numeric: " + digLenStr);
            }
            if (digLen == 0U) {
                throw std::invalid_argument(errorLine + "dig length zero in RGB code ");
            }
        }

        // the first time, just check how much top-left will go.
        if ((dir == Dir::Left) && (digLen > currPos.x)) {
            startX += (digLen - currPos.x);
            currPos.x = digLen;
        } else if ((dir == Dir::Up) && (digLen > currPos.y)) {
            startY += (digLen - currPos.y);
            currPos.y = digLen;
        }

        if (!movePointU(currPos, dir, digLen - 1U)) {
            throw std::runtime_error("movePointU failed: bad direction ?");
        }

        digMoves.emplace_back(dir, digLen);
    }

    Point startP{startX, startY};

    currPos = startP;

    linesDir[startY][startX] = TraitDir{'.', startX, '.'}; // no special character for '.'

    using VertTraits = std::set<VertTrait>;
    VertTraits vertTraits;

    lineCount = 0U; // to re-scroll
    for (const auto& digMove : digMoves) {
        ++lineCount;

        Dir dir = digMove.first;
        Coord digLen = digMove.second;

        if (lineCount == 1U) {
            // first time
            oldDir = dir;
            firstDir = dir;
        }

        std::map<Coord, TraitDir>& mapTraits = linesDir[currPos.y];
        if (mapTraits.empty()) {
            throw std::runtime_error("not found line");
        }

        auto it = mapTraits.upper_bound(currPos.x);
        /*if (it == mapTraits.begin()) {
            throw std::runtime_error("not found trait");
        } // else:*/

        --it;
        TraitDir& traitDir = it->second;
        /*if ((it->first != currPos.x) && (traitDir.lastPos != currPos.x)) {
            throw std::runtime_error("unexisting basic trait");
        }*/

        if (oldDir == Dir::Left) {
            traitDir.firstChar = getTurn(oldDir, dir, lineCount == 1U);
            // cannot be also lastChar because 0-moves are not accepted.
        } else {
            traitDir.lastChar = getTurn(oldDir, dir, lineCount == 1U);
            if (it->first == traitDir.lastPos) {
                traitDir.firstChar = traitDir.lastChar;
            }
        }

        Point newP = currPos;
        if (!movePointU(newP, dir, digLen - 1U)) {
            throw std::runtime_error("movePointU failed: bad direction ?");
        }

        
        // TODO: to manage crosses, don't fill now linesDir but 'lines' with '#' only.
        // Then in case of crosses, search the envelop by modyfing 'lines' (in order to contain
        // only the envelop), and finally generate linesDir based on the final 'lines'.

        cubes += digLen;
        switch (dir) {
        case Dir::Right: {
            /*if (traitDir.lastPos != currPos.x) {
                throw std::runtime_error("generalize for back and forth");
            }*/
            traitDir.lastPos = newP.x;
            // traitDir.lastChar = wait next move to set it.

            const auto it2 = std::next(it);
            if (it2 != mapTraits.end()) {
                if (it2->first <= newP.x) {
                    /*if (newP != startP) {
                        throw std::runtime_error("overlap: generalize for crosses");
                    } // else:*/

                    traitDir.lastPos = it2->second.lastPos;
                    // for the case of two consecutive right.

                    mapTraits.erase(it2);
                }
            }
        } break;
        case Dir::Down: {
            vertTraits.insert(VertTrait{currPos.x, currPos.y, newP.y});

            const auto addPair = std::make_pair(currPos.x, TraitDir{'|', currPos.x, '|'});

            // check if any intermediate line has a crossed trait.
            while (newP.y > currPos.y) {
                const auto itL = linesDir.lower_bound(++currPos.y);
                if ((itL == linesDir.end()) || (itL->first > newP.y)) {
                    currPos.y = newP.y;

                    auto& lineDir = linesDir[currPos.y];
                    lineDir.insert(addPair);

                    // Need to check for non-empty traits on right and left
                    // in order to add single '|' in this line.
                    for (const auto& traitVert : vertTraits) {
                        if ((traitVert.x != currPos.x) && (currPos.y >= traitVert.yMin)
                            && (currPos.y <= traitVert.yMax)) {
                            auto vertSingleton
                                = std::make_pair(traitVert.x, TraitDir{'|', traitVert.x, '|'});
                            lineDir.insert(vertSingleton);
                        }
                    }
                } else {
                    currPos.y = itL->first;
                    LineDir& lineDirV = itL->second;

                    auto [itV, ok] = lineDirV.insert(addPair);

                    /*if (!ok) {
                        if (newP != startP) {
                            throw std::runtime_error("generalize for cross");
                        }
                    } else*/ if (ok && (itV != lineDirV.begin())) {
                        const auto it2 = std::prev(itV);
                        if (it2->second.lastPos >= newP.x) {
                            /*if (newP != startP) {
                                throw std::runtime_error("overlap: generalize for crosses");
                            } // else:*/
                            lineDirV.erase(itV);
                        }
                    }
                }
            }
        } break;
        case Dir::Left: {
            /*if (it->first != currPos.x) {
                throw std::runtime_error("generalize for back and forth");
            }*/

            const auto traitDirCopy = traitDir;
            // traitDirCopy.firstChar = wait next move to set it.
            mapTraits.erase(it);

            const auto [itNew, _/*ok*/] = mapTraits.emplace(newP.x, traitDirCopy);

            /*if (!ok) {
                throw std::runtime_error("overlap: generalize for crosses");
            }*/

            if (itNew != mapTraits.begin()) {
                const auto it2 = std::prev(itNew);
                if (it2->second.lastPos >= newP.x) {
                    /*if (newP != startP) {
                        throw std::runtime_error("overlap: generalize for crosses");
                    } // else:*/

                    it2->second.lastPos = itNew->second.lastPos;
                    // for the case of two consecutive left.

                    mapTraits.erase(itNew);
                }
            }
        } break;
        case Dir::Up:
            // TODO: mix with Down, as most of code is equivalent.
            {
                vertTraits.insert(VertTrait{currPos.x, newP.y, currPos.y});

                const auto addPair = std::make_pair(currPos.x, TraitDir{'|', currPos.x, '|'});

                // check if any intermediate line has a crossed trait.
                while (newP.y < currPos.y) {
                    auto itL = linesDir.upper_bound(--currPos.y);
                    if ((itL == linesDir.begin()) || (std::prev(itL)->first < newP.y)) {
                        currPos.y = newP.y;

                        auto& lineDir = linesDir[currPos.y];
                        lineDir.insert(addPair);

                        // Need to check for non-empty traits on right and left
                        // in order to add single '|' in this line.
                        for (const auto& traitVert : vertTraits) {
                            if ((traitVert.x != currPos.x) && (currPos.y >= traitVert.yMin)
                                && (currPos.y <= traitVert.yMax)) {
                                auto vertSingleton = std::make_pair(
                                    traitVert.x, TraitDir{'|', traitVert.x, '|'});
                                lineDir.insert(vertSingleton);
                            }
                        }
                    } else {
                        --itL;
                        currPos.y = itL->first;
                        LineDir& lineDirV = itL->second;

                        auto [itV, ok] = lineDirV.insert(addPair);

                        if (!ok) {
                            /*if (newP != startP) {
                                throw std::runtime_error("generalize for cross");
                            }*/
                        } else if (itV != lineDirV.begin()) {
                            const auto it2 = std::prev(itV);
                            if (it2->second.lastPos >= newP.x) {
                                /*if (newP != startP) {
                                    throw std::runtime_error("overlap: generalize for crosses");
                                } // else:*/
                                lineDirV.erase(itV);
                            }
                        }
                    }
                }
            }
            break;
        }
        currPos = newP;
        oldDir = dir;
    }

    if (currPos != startP) {
        // std::cout << "downDebug " << downDebug << std::endl;
        // std::cout << "rightDebug " << rightDebug << std::endl;
        std::cout << "startX " << startX << std::endl;
        std::cout << "startY " << startY << std::endl;
        std::cout << "point " << pointToStr(currPos) << std::endl;

        throw std::invalid_argument("circle not closed!");
    }

    {
        LineDir& lineDir = linesDir[startY];

        auto it = lineDir.upper_bound(startX);
        if ((it == lineDir.begin()) || (std::prev(it)->second.lastPos < startX)) {
            throw std::runtime_error("startX not found!");
        }
        --it;

        const auto chTurn = getTurn(oldDir, firstDir);

        if (it->second.lastPos == startX) {
            it->second.lastChar = chTurn;
        }
        if (it->first == startX) {
            it->second.firstChar = chTurn;
        }
    }

    printLines(linesDir);

    --cubes; // startP was counted twice
    std::cout << "Digged cubes " << cubes << std::endl;

    // check interior
    cubes = 0U; // this simplifies the counting.
    Coord oldY = 0U;
    for (const auto& [y, lineDir] : linesDir) {
        bool inUp = false;
        bool inDown = false;

        Coord lastX = 0U;

        for (const auto& [x, traitDir] : lineDir) {

            Coord deltaY = y - oldY;
            if (deltaY == 0U) {
                deltaY = 1U;
            }

            Coord xPos = x;
            char ch = traitDir.firstChar;

            for (int i = 0; i < 2; ++i) {
                Point p{xPos, y};
                const auto excMsg = [&p](std::string head, char chMsg) {
                    head.append(" at ");
                    head.append(pointToStr(p));
                    head.append(" : ");
                    head.push_back(chMsg);

                    return head; // moves
                };

                Coord deltaX = xPos - lastX;
                if (deltaX == 0U) {
                    // don't really care of case zero in the first step,
                    // as cubes is not increased using deltaX for the
                    // first x-coordinate.
                    deltaX = 1U;
                }

                if (deltaX > std::numeric_limits<Quantity>::max() / deltaY) {
                    throw std::runtime_error("Need a larger type for Quantity");
                }
                Quantity squadreMiddle = static_cast<Quantity>(deltaX) * deltaY;

                bool inUpWas = inUp;
                bool inDownWas = inDown;

                const auto oldCubes = cubes;

                if (inUp) {
                    cubes += squadreMiddle;
                    // regardless of inDown
                } else if (inDown) {
                    cubes += deltaX;
                }

                switch (ch) {
                case '|':
                    if (inUp != inDown) {
                        throw std::runtime_error(excMsg("impossible middle-break", ch));
                    }

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

                    inUp = !inUp;
                    // inUp unchanged

                    break;
                default:
                    throw std::runtime_error(excMsg("corrupted char", ch));
                }

                if (!inUpWas) {
                    if (inUp) {
                        cubes += deltaY;
                        if (inDownWas) {
                            --cubes;
                            // avoid counting twice, it was
                            // already accounted in the deltaX.
                        }
                    } else if (inDown && !inDownWas) {
                        ++cubes;
                    }
                }

                if (cubes < oldCubes) {
                    // overflow
                    throw std::runtime_error("Type of cubes-count must be larger");
                }

                lastX = xPos;
                xPos = traitDir.lastPos;
                ch = traitDir.lastChar;

                if ((i == 0) && (lastX == xPos)) {
                    if (traitDir.lastChar != traitDir.firstChar) {
                        throw std::runtime_error(
                            excMsg("lastChar not same as firstChar", traitDir.firstChar));
                    }
                    break;
                }
            }
        }

        oldY = y;
    }

    printLines(linesDir);

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "start Point " << pointToStr(startP) << std::endl;
    std::cout << "countDirJokes " << countDirJokes << std::endl;
    std::cout << "\nResult Day 18 p.2  : " << cubes << std::endl;
    return cubes;
}

int main18p2()
{
    try {
        day18Part2(Input, false);
        // day18Part2("./18_input_file.txt",true);
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
Digged cubes 6405262
Lines count 14
start Point (0, 0)
countDirJokes 3
Result: 952408144115

Real input:
Digged cubes 216354442
Lines count 606
start Point (3321135, 14844389)
countDirJokes 286
Result: 147839570293376
*/
