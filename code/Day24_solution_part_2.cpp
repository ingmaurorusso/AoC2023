#include <algorithm>
#include <array>
#include <cmath>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace {

constexpr bool Example = false;

using CoordD = long double;
constexpr CoordD Scale = Example ? 1.0L : 1000000000000000.L;
// It does not matter to scale only position and not velocuty.

// constexpr auto MinFieldCoord = Example ? 7.L : 0.2L;
// constexpr auto MaxFieldCoord = Example ? 27.L : 0.4L;

// TODO: with higher threshold fails, however it should be added some automatic check.
// Here the Scale and the Thres are calibrated on the visual check of the effective inputs,
// but basically it is tedious to write general code.
constexpr CoordD Thres
    = Example ? 0.01L : 1 / Scale; // TODO: 0.01 is enough ? -> use underflow facility from C++
    // using 0.1/Scale leads to non-matching hail n. 7

constexpr std::string_view Input = Example
?

"19, 13, 30 @ -2,  1, -2\n"
"18, 19, 22 @ -1, -1, -2\n"
"20, 25, 34 @ -2, -2, -4\n"
"12, 31, 28 @ -1, -2, -1\n"
"20, 19, 15 @  1, -5, -3\n"

:

"212542581053874, 357959731032403, 176793474286781 @ -88, -256, -240\n"
"154677220587564, 207254130208265, 139183938188421 @ 184, 74, 235\n"
"216869547613134, 38208083662943, 397740686492049 @ 109, 262, -66\n"
"221241619250961, 303902532813154, 249144641113790 @ 48, 24, -112\n"
"432610900189894, 347346225570463, 389169322099761 @ -166, -99, -81\n"
"247078054674939, 279574769079583, 357168683293046 @ 68, -13, -42\n"
"282963504691878, 53019767043895, 238787901458543 @ -17, 399, 62\n"
"337163551253985, 323723171285276, 476752372944125 @ -8, -74, -103\n"
"253985064168104, 111063839515573, 450754418443501 @ -10, 456, -513\n"
"258074760233454, 457117599855759, 244857473415713 @ 49, -247, 92\n"
"314400910480251, 261232162431814, 339725786848352 @ -14, 8, -14\n"
"246590774392044, 268326724153423, 252283137292781 @ -76, 195, -225\n"
"283441229604303, 368965998122557, 461958957382550 @ -8, -135, -282\n"
"175273393192850, 325589084134993, 358406853832354 @ 167, -63, -156\n"
"208105215242940, 346463859222197, 284004541154973 @ 25, -119, -783\n"
"336054085870446, 539099420004527, 243053582150753 @ -125, -451, 41\n"
"192157026866775, 221346796869463, 239193597650948 @ 138, 27, 138\n"
"276769382377332, 404564336355307, 139075528478897 @ -118, -279, 221\n"
"244171538000181, 413561793671125, 231547901494709 @ 6, -271, -7\n"
"247208942851962, 296793553833683, 207661499518285 @ -14, 32, 36\n"
"234192138385646, 334863379919503, 180826848665889 @ -28, -63, 52\n"
"130437043915331, 177551493108966, 166468122354373 @ 338, 448, 129\n"
"253559901772970, 311389465584945, 216687040440642 @ -9, -19, 42\n"
"254322299286702, 321942519715615, 221793429844513 @ -17, -42, 21\n"
"317611519474313, 509405643844478, 492629597734339 @ -24, -308, -221\n"
"312434433255435, 526132170689517, 256217852328836 @ -50, -379, 50\n"
"192520813054515, 351604734054654, 148333436370478 @ 130, -152, 132\n"
"225639342892974, 304654108851055, 198053006284713 @ 19, 39, 12\n"
"264606145094124, 239752767682501, 207210412874243 @ 29, 61, 131\n"
"73119136879824, 45456753334198, 74136546109856 @ 253, 194, 300\n"
"231632956914705, 457605979777570, 302698719514094 @ 26, -414, -234\n"
"229858006692918, 295381637696215, 265115021539193 @ -34, 118, -354\n"
"461793485716737, 253291754164921, 311510874631043 @ -158, 5, 47\n"
"325336710582066, 310550712766927, 330361932845723 @ 5, -61, 46\n"
"272391892781881, 310661548818291, 260226744483606 @ -34, -25, -30\n"
"191540619797068, 314621834402429, 114137462106199 @ 138, -22, 288\n"
"191146615936494, 272599606676084, 172343941415066 @ 139, 136, 110\n"
"267901500435402, 344752144584613, 304856136274139 @ -39, -98, -158\n"
"190703217190290, 247560977233459, 149406776287313 @ 142, 550, 121\n"
"201153500629286, 339132186878755, 150323637135481 @ 35, -57, 45\n"
"179357508767544, 21932393507743, 145226556713621 @ 154, 315, 227\n"
"307987323598344, 301312391795996, 300888123246103 @ -11, -40, 27\n"
"181344541654818, 250938115658739, 239246377640253 @ 196, 440, -384\n"
"324550882422222, 211574061061843, 237485412093545 @ -29, 72, 111\n"
"98537457698304, 238200330125587, 135289135303526 @ 249, 31, 240\n"
"313205485078410, 121081864504891, 172268217697865 @ -104, 348, 163\n"
"284584577159870, 144278803049487, 200681374736457 @ -57, 323, 99\n"
"226456734486356, 282983479210501, 218425710839487 @ -108, 324, -366\n"
"548706725108910, 277311257109343, 307850918038817 @ -217, -28, 69\n"
"275949926976102, 282022314903463, 311454924607825 @ -113, 87, -291\n"
"213263551904504, 318546624732143, 175742955114241 @ 36, 19, 37\n"
"216681369963291, 296454359998620, 462583452318421 @ 82, 10, -495\n"
"219979404537774, 211918469842543, 232459433192801 @ 77, 188, 27\n"
"325980549629430, 547508205102316, 314702156232182 @ -13, -324, 38\n"
"284385758172543, 352024785807952, 218382195747631 @ -128, -120, -5\n"
"190048554539654, 289779355315179, 173904022587641 @ 149, 388, -145\n"
"246873768466142, 272467557005199, 232828642561081 @ -39, 131, -80\n"
"163218080831461, 148606013314170, 142402007207516 @ 176, 164, 230\n"
"343986154477558, 348372021296886, 250152291857989 @ -205, -106, -23\n"
"197767130311944, 180525916592167, 161798814812969 @ 114, 519, 129\n"
"198370970228262, 298346938466104, 174124739099332 @ 115, 54, 102\n"
"380807631586707, 369450765586399, 481309114237823 @ -200, -141, -381\n"
"187175525195694, 309586416720283, 109735015379081 @ 171, 173, 417\n"
"281478516067897, 366561714660494, 230365710762598 @ -204, -184, -132\n"
"208535431591002, 325419351576169, 191516365446671 @ 57, -12, -40\n"
"226624736718348, 308650992940298, 199188859982218 @ -23, 62, -66\n"
"236728026197754, 172425510194479, 206288955041960 @ 79, 131, 146\n"
"405157823215560, 285719256118206, 491621031364803 @ -83, -34, -129\n"
"204644528670384, 339896525956405, 151222667113763 @ -56, -54, -46\n"
"185135616546414, 293907013443535, 166394249527601 @ 179, 231, 10\n"
"238567782335982, 328412098910479, 192473102467361 @ -85, -26, -45\n"
"337502877434493, 307749379575088, 369033005648444 @ -8, -58, 6\n"
"241635494672614, 304729449451093, 326150295954981 @ 51, -27, -95\n"
"243264345725652, 264419513819446, 345867847848017 @ 73, 6, -27\n"
"262661477328582, 274242124962679, 187580319707945 @ -42, 80, 102\n"
"208059705739518, 217157359130755, 219168637501631 @ 115, 85, 120\n"
"242872575971229, 425458083316108, 227500835165921 @ 36, -258, 53\n"
"448263894001344, 301783842143683, 426560436553661 @ -176, -43, -117\n"
"322545182274254, 452642407811057, 305182728508413 @ -21, -227, 33\n"
"75201284514819, 160785119325533, 104951102720081 @ 352, 241, 293\n"
"185323568951310, 233171350573267, 165775283064269 @ 163, 358, 102\n"
"242854931589532, 319092328660893, 243043088450517 @ 18, -38, -17\n"
"216818686888044, 223426989024383, 346281309297331 @ 58, 283, -434\n"
"248624452315030, 297434951348619, 284011728475200 @ 83, -49, 96\n"
"308774084417184, 254923461188383, 324690057597731 @ -22, 27, -20\n"
"477086131906062, 293633862617983, 289717304778929 @ -153, -43, 83\n"
"310556413418768, 388389186178424, 201218392651440 @ -67, -172, 124\n"
"294335453543209, 239407270896468, 327371176340196 @ 6, 40, -8\n"
"198704436992819, 423313637384734, 211494844150179 @ 114, -360, -21\n"
"329848820747522, 171413007628813, 298751280762187 @ -19, 102, 54\n"
"232791155115204, 389793252905721, 200914316887487 @ -56, -314, -82\n"
"371238777825072, 364331369420770, 349467249711398 @ -35, -114, 34\n"
"290194660125822, 286241186809255, 265989895196345 @ -93, 39, -71\n"
"138500514403427, 150096241065480, 90891764345181 @ 270, 386, 345\n"
"342432728761822, 169489883251125, 160900448427412 @ -69, 145, 204\n"
"387284555873510, 268651056280939, 472485507519965 @ -235, 48, -406\n"
"348183642749259, 358775680962680, 425167151051150 @ -26, -110, -64\n"
"214564960481976, 332636582662001, 166341733116147 @ -35, -19, -17\n"
"288352094438008, 172713636729509, 508999993126113 @ 32, 94, -171\n"
"429522310493674, 350751066474876, 353772711184036 @ -241, -106, -110\n"
"235317931818252, 321016228988431, 221782559196323 @ 8, -29, -24\n"
"237395224369976, 271952629687205, 200198427527953 @ 48, 46, 109\n"
"267689676493904, 197692176620362, 371002531720142 @ -151, 456, -664\n"
"245022629101794, 336310573633898, 178670106406896 @ 79, -86, 192\n"
"308555808260267, 235053234862080, 386617281992034 @ 20, 16, -14\n"
"254939001555789, 196490967246088, 344406853138846 @ 46, 120, -66\n"
"198067603029891, 228271655034477, 230280443116238 @ 112, 353, -142\n"
"286182290367015, 324356938662982, 337470234197366 @ 40, -74, 30\n"
"182772323746872, 243078357133489, 180935879286305 @ 182, 418, -11\n"
"334555295661618, 283598866844113, 307163703216413 @ -19, -28, 51\n"
"268032515539496, 179884088413109, 201707373095034 @ 53, 89, 166\n"
"314152706857177, 231973181098005, 294537386515547 @ -10, 41, 47\n"
"211145445957746, 256130578705417, 227544572919273 @ 105, 54, 81\n"
"240281216930434, 308871905093706, 201208104074959 @ -81, 58, -69\n"
"194990331403464, 353680311245143, 148152875882771 @ 96, -217, 54\n"
"376506453102756, 282681817701967, 308014018133222 @ -59, -29, 56\n"
"270559608594507, 293243401201593, 219465840278274 @ -38, 17, 48\n"
"271434227107862, 301909819058233, 255037189953162 @ -157, 57, -212\n"
"228819748864119, 35415178477933, 360982336746131 @ 100, 225, 7\n"
"282571416535269, 237239909717928, 361818410574456 @ 34, 28, -20\n"
"237878607070278, 316580360861695, 326197735422041 @ 42, -39, -160\n"
"182576050978588, 187101572838317, 131079628110881 @ 153, 161, 245\n"
"235076492312502, 318319071558547, 260428708551349 @ -203, 96, -762\n"
"187583408959494, 313306547152243, 102716500573961 @ 189, 318, 643\n"
"239870832918417, 26077551674877, 194534422319897 @ 10, 745, 77\n"
"268344200395759, 336594882856173, 201457637971271 @ -144, -71, -13\n"
"351502642713711, 343426968745552, 327993505552334 @ -54, -94, 8\n"
"203247301060818, 304211148313729, 144668102389835 @ 17, 294, 108\n"
"205287991254828, 326526363823258, 176717703001868 @ 73, -18, 32\n"
"228237293076774, 492607291603871, 215976066898633 @ 49, -457, 39\n"
"210744469193866, 242345551455857, 338364614486931 @ 87, 173, -305\n"
"283795432748766, 324397233772201, 303141716476529 @ 27, -71, 37\n"
"318328668468378, 290176478743420, 393177776909696 @ -9, -32, -60\n"
"296886504660264, 330367685997713, 290768439652901 @ -8, -76, 23\n"
"354925965270690, 204310714489876, 324988197369764 @ -73, 86, -6\n"
"277940901110162, 351813200734015, 35068250706381 @ 26, -105, 370\n"
"302119534267998, 319648005021051, 257122942759009 @ -185, -26, -123\n"
"220643077695684, 355855985807773, 179518771733771 @ 30, -142, 66\n"
"281128245154754, 261417029969318, 390265842706956 @ 47, -10, -20\n"
"401214520647879, 209382315271573, 394433050114910 @ -66, 37, -12\n"
"202419387388134, 370308338321798, 371095720268716 @ 115, -152, -266\n"
"243933688132567, 284238541251243, 160523673406178 @ -60, 127, 134\n"
"207949728449758, 342146025132292, 160034991638202 @ 27, -90, 52\n"
"328107083354006, 506783656792851, 68374835799249 @ -27, -292, 321\n"
"334371695727666, 295677547881937, 372669058678174 @ -209, 21, -342\n"
"425555650358416, 141386636896383, 400700320063993 @ -94, 107, -23\n"
"354111348691934, 360815768065903, 286452836048521 @ -183, -129, -62\n"
"186640407106107, 302586436160656, 178053441373097 @ 172, 200, -99\n"
"184504662208422, 279753007845271, 194263341780489 @ 217, 645, -497\n"
"207498586652070, 122966697911623, 453309639270761 @ 88, 592, -760\n"
"175420575327994, 240376844547933, 227794777853156 @ 159, 37, 122\n"
"164379037426222, 314155556336019, 361113505933531 @ 171, -59, -30\n"
"276158080997198, 255307550628353, 190284041278157 @ 27, 22, 167\n"
"188538116291142, 332645165411655, 164893512402481 @ 166, 10, -105\n"
"206485169181270, 324400373771635, 174538862304413 @ 37, 28, -44\n"
"231705775027484, 354858179856273, 282940665637611 @ 53, -119, -77\n"
"192935594972436, 232318329359044, 140280091724297 @ 125, 770, 173\n"
"195865425610134, 156203126394403, 201075304936541 @ 121, 618, -22\n"
"220291544685654, 60861797261303, 192839119984101 @ 97, 313, 156\n"
"216421547979532, 166625355222409, 138232910764571 @ 33, 645, 215\n"
"454745381031134, 359071031321598, 433358646779191 @ -229, -116, -177\n"
"241211456940334, 274238344824863, 449761596808401 @ 87, -22, -86\n"
"300489403237401, 150600505604740, 311021695401350 @ 12, 130, 36\n"
"351714451571994, 313870670017933, 87623195530631 @ -79, -54, 304\n"
"206304315814166, 322825195619263, 165678725657741 @ 47, 27, 35\n"
"235260754952454, 192089045978143, 324835846533921 @ 88, 81, 21\n"
"234012378392974, 220537666254223, 244419610199201 @ 21, 243, -67\n"
"271646520250074, 328249590902743, 281718062915501 @ 38, -75, 56\n"
"221872342890713, 311155829759331, 169665424751063 @ 96, -49, 191\n"
"234965964033108, 289605268944487, 264575781614519 @ 53, 11, -17\n"
"302656676541801, 314956862712124, 279759708917957 @ 22, -64, 89\n"
"194778772231287, 358987377936095, 94944329588325 @ 100, -269, 633\n"
"213962227655009, 360175350319088, 187183591353131 @ 78, -140, 95\n"
"335872446070469, 310194803249308, 258956779512841 @ -196, -18, -51\n"
"237632929340327, 282862400087895, 329308829827744 @ -54, 155, -578\n"
"195165381881310, 334127994548035, 177008381765921 @ 83, 25, -395\n"
"322431513433582, 335929297302159, 292621591828001 @ -117, -80, -70\n"
"315117522492294, 188045711663619, 217859262699941 @ -11, 94, 140\n"
"373704262775700, 207296292228736, 462531809606177 @ -143, 116, -267\n"
"251431566932470, 262653021312867, 228387402272864 @ -45, 151, -52\n"
"200968557727895, 335950123937744, 148782648944484 @ -28, 20, -56\n"
"236191762393467, 21120063276068, 319730241477691 @ 22, 742, -245\n"
"208913018909190, 375167847286459, 97238860543841 @ -29, -401, 565\n"
"290435031159135, 56359235789263, 318028085602160 @ 28, 227, 36\n"
"205348838719584, 129089359330730, 397134601580767 @ 109, 358, -317\n"
"194757851501280, 310732265284483, 257897724121307 @ 122, 57, -352\n"
"322105170096600, 281140697612407, 384217392018125 @ -40, -9, -101\n"
"227263802927379, 293407939553692, 217416903679568 @ 34, 50, -6\n"
"253024402494847, 472881498291876, 346563578286452 @ -60, -512, -448\n"
"314479634908016, 119470812770471, 423291884678263 @ -102, 343, -326\n"
"285064202741996, 260225765977046, 328922413430668 @ 17, 14, -12\n"
"164764803937924, 131918495543174, 24421731030948 @ 209, 466, 528\n"
"302401846001018, 47953136574059, 415330628001011 @ -43, 389, -220\n"
"136889723461149, 102922183481659, 257049978466682 @ 254, 415, -22\n"
"266977346640134, 399124471391351, 389593482782381 @ 29, -175, -130\n"
"372790937915094, 329723676236983, 408552056960081 @ -242, -66, -337\n"
"295046549007926, 307216389914204, 245279985581636 @ -93, -14, -10\n"
"222962551504923, 300940192862044, 205863476663477 @ 42, 34, 17\n"
"217936499850689, 313784346557728, 244304797861441 @ 86, -36, 21\n"
"167754243520824, 183008145578501, 255319117162995 @ 184, 214, 6\n"
"210177003182478, 429234450438847, 105538845228113 @ 101, -266, 296\n"
"199347157290654, 270021317518867, 163266752925959 @ 99, 261, 88\n"
"236595610312209, 357567541944595, 163695965251100 @ -116, -177, 62\n"
"312426175948804, 126535043607303, 334910821408881 @ 20, 119, 45\n"
"250185142335527, 339957515144567, 186490088641817 @ -40, -85, 77\n"
"187486534782198, 153491915531223, 178050669591013 @ 145, 217, 168\n"
"264452793637374, 364051575147343, 278407165734113 @ -66, -153, -167\n"
"321652447174633, 234494711812364, 293511778578951 @ -94, 100, -45\n"
"101178528277354, 45310253629503, 279722555547721 @ 231, 211, 93\n"
"311483135370989, 117588178673003, 195876215498686 @ -30, 223, 154\n"
"349074097657518, 71980788262470, 67744127629012 @ -53, 236, 322\n"
"205665951950534, 317578175678991, 174079200152461 @ 9, 131, -140\n"
"172224556223070, 207776433045037, 341587542422723 @ 163, 78, -22\n"
"199777030731058, 159408594476631, 309534334024285 @ 108, 565, -396\n"
"464121799742544, 439378219125328, 480156984371951 @ -191, -210, -177\n"
"512533623338691, 269596699742212, 497024716185359 @ -200, -16, -141\n"
"449327916519144, 205855641898298, 303200495165981 @ -131, 50, 65\n"
"283724606928492, 240851979789205, 384065029237529 @ 38, 18, -31\n"
"288013100270877, 208780552824757, 275880042837536 @ 42, 41, 100\n"
"225018718395018, 305644724002975, 271186961007503 @ 73, -21, -28\n"
"252580597893096, 289594241717095, 283259230473967 @ -14, 39, -134\n"
"217696966439229, 236860502115098, 202812154030551 @ 82, 134, 91\n"
"290383585895985, 172960262418583, 413523311841740 @ 22, 107, -88\n"
"246394854383374, 404386901502983, 316452007110281 @ 63, -178, -10\n"
"277440283560394, 298664786803743, 343675845620671 @ 29, -37, -26\n"
"549218613325353, 365039367598781, 370814441177496 @ -212, -115, 10\n"
"314422297180566, 290227116094987, 220524013374437 @ -127, 20, 52\n"
"208288985823519, 332582248866208, 173680963176656 @ 38, -34, -6\n"
"344954667419544, 271844404820980, 373070962444213 @ -11, -24, 9\n"
"253707352980234, 336179622652543, 293095895839541 @ 22, -81, -58\n"
"348619876072741, 233964822099034, 330658038016178 @ -48, 36, 8\n"
"294065185957476, 303581225750131, 130406957718587 @ -14, -35, 246\n"
"299497691666274, 143845614560983, 193269298796021 @ -30, 217, 148\n"
"243761048715324, 305091461548017, 163187922986167 @ -56, 46, 126\n"
"228852534457750, 321833988811099, 195275147618589 @ -19, -6, -24\n"
"210326083482005, 405825122389483, 255008495328029 @ 48, -393, -343\n"
"234154015900814, 320051906908983, 254552486072961 @ 15, -28, -111\n"
"221069337881082, 268544927933243, 253793013055353 @ 40, 152, -161\n"
"350843574391570, 546291208573433, 245148884150221 @ -57, -343, 105\n"
"321884637993916, 151517460880797, 338566691457073 @ -108, 268, -147\n"
"332310394683086, 296925474202815, 290407863681483 @ -133, -5, -62\n"
"238868612579282, 442767280701488, 312738360614324 @ -73, -538, -562\n"
"238005301025171, 315819717023939, 310603161892176 @ 62, -49, -50\n"
"184500511341324, 354706787987715, 106858269141817 @ 184, -175, 409\n"
"218719926572754, 248846852339899, 417842058727985 @ 109, 9, -67\n"
"61527743340558, 41910468004471, 21054306023633 @ 311, 306, 391\n"
"206891968805558, 359036109292941, 96347232076181 @ 71, -164, 395\n"
"358569854122062, 275252683087759, 280731684589601 @ -219, 51, -75\n"
"281134641567294, 255607683726743, 288258712879345 @ -11, 52, -17\n"
"325364111053745, 294010589908703, 211245733791773 @ -82, -13, 113\n"
"268578371026014, 236127445255093, 380797038274583 @ 59, 17, -13\n"
"489485534335218, 226913670756739, 271116263277629 @ -155, 21, 107\n"
"200091726654254, 345151854422543, 355346332534721 @ 125, -97, -106\n"
"288773407987668, 371116294945099, 330355289788371 @ -128, -171, -300\n"
"398345872685398, 211733420030191, 256489704564165 @ -127, 75, 84\n"
"410444070061341, 232446702321753, 270268423194688 @ -80, 17, 106\n"
"223446110503560, 342994867695369, 176936935212271 @ -23, -95, 15\n"
"221456980555537, 346760891427937, 198873039052710 @ 8, -111, -48\n"
"241138246161499, 378379591190555, 197910544306414 @ 44, -161, 118\n"
"239309488603942, 346974551472951, 243277229211186 @ 51, -101, 40\n"
"266720686719534, 249073195909171, 326627536261997 @ 59, 6, 38\n"
"175265275057344, 233389584704983, 166232708483831 @ 228, 519, 48\n"
"199647143220834, 333605166183208, 126338949433076 @ 87, -38, 274\n"
"355059474706240, 112909300036023, 456817283755217 @ -18, 127, -67\n"
"291234253229982, 225827198327447, 300458706607553 @ -17, 89, -19\n"
"289865647604208, 451420237900663, 518182602681917 @ 12, -233, -253\n"
"351557916167787, 226921027459900, 441676807044779 @ -112, 88, -241\n"
"171724416708978, 120198249743035, 113845845697733 @ 210, 720, 308\n"
"324992776605402, 546442272740313, 176464245808959 @ -35, -358, 186\n"
"266166769986634, 268730110669199, 328440341073557 @ 9, 35, -97\n"
"225525857274734, 233012276737543, 309959118198911 @ 75, 111, -88\n"
"183405703797942, 309355721084695, 182533926443609 @ 173, 53, 19\n"
"210515462842953, 291925001904295, 215164290510485 @ -72, 459, -671\n"
"235537482505454, 310690173156743, 156326933471977 @ -21, 22, 154\n"
"273084618253552, 382626888261135, 273689280998585 @ 8, -157, 17\n"
"253722385917350, 315123819243295, 240205666004325 @ 57, -57, 102\n"
"196398380835834, 355900579581511, 153312099518087 @ 109, -169, 118\n"
"283444009699329, 366561045831077, 202002888581270 @ -146, -167, 26\n"
"296532850164962, 253904723261403, 296984689916093 @ 38, -8, 86\n"
"356774602967614, 373148843974943, 387561802202761 @ -67, -131, -74\n"
"252770877244094, 318171858594683, 216752381636081 @ -25, -28, 17\n"
"338919821368038, 232645806842808, 377368303830121 @ -29, 32, -35\n"
"209566211606045, 338493165391956, 150634080385665 @ -72, -46, 21\n"
"328388255345246, 295645021337031, 342359520358565 @ -13, -41, 11\n"
"357923314873354, 213990132914548, 252051459029871 @ -145, 126, 39\n"
"300794330404169, 291383403542233, 331991009111531 @ -28, -15, -61\n"
"171452764273723, 106269888549931, 325980849738994 @ 168, 255, -42\n"
"400651551538638, 227035846405175, 440348818761665 @ -113, 46, -127\n"
"183528864416638, 337358904333282, 149647897440530 @ 155, -82, 206\n"
"407834029671234, 363038317346083, 326507144649005 @ -126, -118, 6\n"
"261232554625244, 272762277507558, 260158766990881 @ -139, 184, -267\n"
"276291421501401, 231191690007043, 332403327250334 @ 32, 47, -8\n"
"213146770430035, 320595954009642, 182342124018161 @ 36, 10, 5\n"
"431072263340031, 549716908674601, 541461834661703 @ -234, -415, -393\n"
"271067118142410, 252860807780751, 293724860670289 @ 25, 35, 13\n"
"230424456187626, 346336855193767, 374228162998841 @ 76, -99, -145\n"
"233683858918340, 451654359126852, 407119183631371 @ 45, -334, -365\n"
"309530132675051, 360560922327322, 427729374335125 @ -118, -132, -399\n"
"171253360815090, 226755112694191, 106314555408725 @ 286, 763, 428\n"
"195185795409569, 365215513552403, 270027401984661 @ 134, -121, 73\n"

;

using Coord = signed long long;

struct Point2D {
    CoordD x;
    CoordD y;
};
/*bool operator==(const Point2D& p1, const Point2D& p2)
{
    return (std::fabs(p1.x - p2.x) < Thres) && (std::fabs(p1.y - p2.y) < Thres);
}
bool operator<(const Point2D& p1, const Point2D& p2)
{
    if (std::fabs(p1.y - p2.y) >= Thres) {
        return (p1.y < p2.y);
    }
    if (std::fabs(p1.x - p2.x) >= Thres) {
        return (p1.x < p2.x);
    }
    return false; // equivalent.
}
bool operator!=(const Point2D& p1, const Point2D& p2)
{
    return !(p1 == p2);
}*/

struct Point3D {
    CoordD x;
    CoordD y;
    CoordD z;
};
/*bool operator==(const Point3D& p1, const Point3D& p2)
{
    return (std::fabs(p1.x - p2.x) < Thres) && (std::fabs(p1.y - p2.y) < Thres)
        && (std::fabs(p1.z - p2.z) < Thres);
}
bool operator<(const Point3D& p1, const Point3D& p2)
{
    if (std::fabs(p1.z - p2.z) >= Thres) {
        return (p1.z < p2.z);
    }
    if (std::fabs(p1.y - p2.y) >= Thres) {
        return (p1.y < p2.y);
    }
    if (std::fabs(p1.x - p2.x) >= Thres) {
        return (p1.x < p2.x);
    }
    return false; // equivalent.
}
bool operator!=(const Point3D& p1, const Point3D& p2)
{
    return !(p1 == p2);
}
*/
bool toSigned(const std::string& s, signed long& res)
{
    try {
        if (s.empty()) {
            return false;
        }
        if (!std::all_of(
                std::next(s.cbegin()), s.cend(), [](const char ch) { return std::isdigit(ch); })) {
            // stol would ignore tailing non-digits.
            // Here ignore first char, that is, allowing '-' (specific check later for future use).
            return false;
        }
        res = std::stol(s);

        return errno != ERANGE;
    } catch (...) {
        // std::invalid_argument, eventually std::out_of_range
        return false;
    }
}

template<size_t Nrows, size_t Ncols = Nrows>
auto computeDet(
    const std::array<std::array<CoordD, Ncols>, Nrows>& matrix, const size_t nCalc = Nrows)
{
    if (nCalc == 0U) {
        return 0.L;
    }
    if (nCalc > std::min(Nrows, Ncols)) {
        throw std::runtime_error("nCalc > std::min(Nrows,Ncols)");
    }

    static const std::function<CoordD(
        const std::array<std::array<CoordD, Ncols>, Nrows>& allMatrix,
        const std::vector<std::pair<size_t, size_t>>& rowsCols)>
        computeMinor = [](const std::array<std::array<CoordD, Ncols>, Nrows>& allMatrix,
                          const std::vector<std::pair<size_t, size_t>>& rowsCols) {
            const size_t n = rowsCols.size();

            if (n == 1U) {
                // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
                return allMatrix[rowsCols[0].first][rowsCols[0].second];
            } // else:

            // choose elements from last row in the wanted columns.
            std::vector<std::pair<size_t, size_t>> rowsColsInner = rowsCols;
            rowsColsInner.pop_back();
            const size_t lastRow = rowsCols[n - 1U].first;
            size_t colRemove = rowsCols[n - 1U].second;

            CoordD res = 0U;

            constexpr CoordD Unit = 1.L;
            CoordD factor = ((n % 2U) == 1U) ? Unit : -Unit;

            for (size_t i = n; i > 0;) {
                --i;
                res +=
                    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
                    (computeMinor(allMatrix, rowsColsInner) * allMatrix[lastRow][colRemove]
                     * factor);

                if (i > 0U) {
                    const size_t newColRemove = rowsColsInner[i - 1U].second;
                    rowsColsInner[i - 1U].second = colRemove; // reinsert previous one.
                    colRemove = newColRemove;
                }

                factor = -factor;
            }

            return res;
        };

    std::vector<std::pair<size_t, size_t>> rowsCols;
    for (size_t i = 0; i < nCalc; ++i) {
        rowsCols.emplace_back(i, i);
    }

    return computeMinor(matrix, rowsCols);
}

template<size_t Nelems>
auto scalarProd(
    const std::array<CoordD, Nelems>& vec1,
    const std::array<CoordD, Nelems>& vec2,
    const size_t nCalc = Nelems)
{
    if (nCalc == 0U) {
        return 0.L;
    }
    if (nCalc > Nelems) {
        throw std::runtime_error("nCalc > Nelems");
    }

    CoordD res = 0.L;
    for (size_t i = 0; i < nCalc; ++i) {
        // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
        res += (vec1[i] * vec2[i]);
    }

    return res;
}

} // namespace

auto day24Part2(std::string_view streamSource, bool sourceIsFilePath)
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

    using PosAndVel = std::pair<Point3D, Point3D>;
    std::vector<PosAndVel> hails;

    static const auto arrayToPoint3 = [](const std::array<CoordD, 3>& a) {
        return Point3D{a.at(0), a.at(1), a.at(2)};
    };

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

        if (line.empty()) {
            std::cout << "WARNING: empty line\n";
            continue;
        }

        std::stringstream lineStream;
        lineStream << line;

        std::array<CoordD, 3U> pos{};
        std::array<CoordD, 3U> vel{};

        for (size_t j = 0; j < 2; ++j) {
            for (size_t i = 0; i < 3; ++i) {
                std::string coordStr;
                if (!(lineStream >> coordStr)) {
                    throw std::invalid_argument(
                        errorLine + "missing coordinate n. " + std::to_string(i + 1)
                        + " of trilpe n. " + std::to_string(i + 1));
                }

                if (i != 2) {
                    if (coordStr.back() != ',') {
                        throw std::invalid_argument(
                            errorLine + "missing comma after coordinate n. "
                            + std::to_string(i + 1) + " of trilpe n. " + std::to_string(i + 1));
                    }
                    coordStr.resize(coordStr.size() - 1U);
                }
                signed long n{};
                if (!toSigned(coordStr, n)) { // the input really has only positive, but
                                                // negative need to be managed in this problem.
                    throw std::invalid_argument(
                        errorLine + "not a number for coordinate n. " + std::to_string(i + 1)
                        + " of trilpe n. " + std::to_string(i + 1));
                }

                if (j == 0) {
                    pos.at(i) = static_cast<CoordD>(n) / Scale;
                } else {
                    vel.at(i) = n;
                }
            }

            if (j == 0) {
                std::string atStr;
                if ((!(lineStream >> atStr)) || (atStr != "@")) {
                    throw std::invalid_argument(
                        errorLine + "missing separator between position and velocity");
                }
            }
        }

        if (lineStream >> line) {
            throw std::invalid_argument(
                errorLine + "unexpected more data after position and velocity");
        }

        hails.emplace_back(PosAndVel{arrayToPoint3(pos), arrayToPoint3(vel)});
    }

    std::cout << "digits10 of CoordD: " << std::numeric_limits<CoordD>::max_digits10 << '\n';
    std::cout << "maxExp10 of CoordD: " << std::numeric_limits<CoordD>::max_exponent10 << '\n';

    // It is a problem to find six integer numbers (Diofante) to solve lot of equations.
    // For each hail there are 2 equations, they are quadratic but all share the same
    // quadratic elements, therefore by each couple of Hails, two linear equations
    // may be found: the first hail is used as model.

    // time-space trajectory for the rock (with the six unknown).
    // x = x0 + v0x*t
    // y = y0 + v0y*t
    // z = z0 + v0z*t

    // time-space trajectory for any hail.
    // x = xi + vix*t
    // y = yi + viy*t
    // z = zi + viz*t

    // Putting together, the two (quadratic) equations are:
    //(xi - x0)*(v0y-viy) = (yi-y0)*(v0x-vix)
    //(xi - x0)*(v0z-viz) = (zi-z0)*(v0x-vix)
    // that is:
    // xi*v0y + viy*x0 - xi*viy - x0*v0y = yi*v0x + vix*y0 - yi*vix - y0*v0x
    // xi*v0z + viz*x0 - xi*viz - x0*v0z = zi*v0x + vix*z0 - zi*vix - z0*v0x
    // where for both equations, on each side there is the quadratic term listed as fourth/last.
    //
    // putting together a couple of couple of equations and then subtract:
    //(xi-xj)*v0y + (viy-vjy)*x0 + (xj*vjy-xi*viy) = (yi-yj)*v0x + (vix-vjx)*y0 +
    //(yj*vjx-yi*vix).
    //(xi-xj)*v0z + (viz-vjz)*x0 + (xj*vjz-xi*viz) = (zi-zj)*v0x + (vix-vjx)*z0
    //+ (zj*vjx-zi*vix)
    //
    // Therefore, after 4 hails, we have 6 equations that may lead to the solution in float
    // format. Then, velocity cannot be changed but the position should be 'moved' to the
    // instant t=0 as required by the assingment, which is already as computed because the
    // equations used for example x0 as position in t=0.

    constexpr size_t SolSize = 6U;

    constexpr size_t X0CoeffPos = 0U;
    constexpr size_t Y0CoeffPos = 1U;
    constexpr size_t Z0CoeffPos = 2U;
    constexpr size_t VX0CoeffPos = 3U;
    constexpr size_t VY0CoeffPos = 4U;
    constexpr size_t VZ0CoeffPos = 5U;
    constexpr size_t TermPos = 6U;

    using Equation = std::array<CoordD, SolSize + 1U>; // last term supposed 'before ='.

    static const auto computeEqs = [](const PosAndVel& hailI, const PosAndVel& hailJ) {
        Equation eq1;
        Equation eq2;

        eq1.at(X0CoeffPos) = hailI.second.y - hailJ.second.y; // viy-vjy with j = 0 for x0
        eq1.at(Y0CoeffPos) = hailJ.second.x - hailI.second.x; // vjx-vix with j = 0 for y0
        eq1.at(Z0CoeffPos) = 0.L;
        eq1.at(VX0CoeffPos) = hailJ.first.y - hailI.first.y; // yj-yi with j = 0 for v0x
        eq1.at(VY0CoeffPos) = hailI.first.x - hailJ.first.x; // xi-xj with j = 0 for v0y
        eq1.at(VZ0CoeffPos) = 0.L;
        eq1.at(TermPos) = // (xj*vjy-xi*viy)- (yj*vjx-yi*vix) with j = 0 for term.
            (hailJ.first.x * hailJ.second.y - hailI.first.x * hailI.second.y)
            - (hailJ.first.y * hailJ.second.x - hailI.first.y * hailI.second.x);

        eq2.at(X0CoeffPos) = hailI.second.z - hailJ.second.z; // viz-vjz with j = 0 for x0
        eq2.at(Y0CoeffPos) = 0.L;
        eq2.at(Z0CoeffPos) = hailJ.second.x - hailI.second.x; // vjx-vix with j = 0 for z0
        eq2.at(VX0CoeffPos) = hailJ.first.z - hailI.first.z; // zj-zi with j = 0 for v0x
        eq2.at(VY0CoeffPos) = 0.L;
        eq2.at(VZ0CoeffPos) = hailI.first.x - hailJ.first.x; // xi-xj with j = 0 for v0z
        eq2.at(TermPos) = // (xj*vjz-xi*viz) - (zj*vjx-zi*vix) with j = 0 for term.
            (hailJ.first.x * hailJ.second.z - hailI.first.x * hailI.second.z)
            - (hailJ.first.z * hailJ.second.x - hailI.first.z * hailI.second.x);

        return std::make_pair(eq1, eq2);
    };

    const size_t nHails = hails.size();

    if (nHails < (SolSize / 2U) + 1U) { // < 4U
        throw std::runtime_error(
            "generalize the code for infinite-solutions cases (few hails)");
    }

    std::array<Equation, SolSize> matrix{};
    // sequence of unknown: x0(0), y0(1), z0(2), v0x(3), v0y(4), v0z(5), term(6) [remains before
    // '=']

    const auto hailJ = hails[0U];
    bool found = false;
    std::vector<size_t> rowsToReplace;
    for (size_t i = SolSize; i > 0;) {
        rowsToReplace.push_back(--i);
    }
    size_t nextHail = 1U; // avoid 0U used as 'J'
    std::optional<Equation> rowPrepared = std::nullopt;
    size_t minRangeAlreadyChecked = 0U;

    CoordD posX{};
    CoordD posY{};
    CoordD posZ{};

    while ((nextHail < nHails) && !found) {
        while (!rowsToReplace.empty()) {
            const size_t row = rowsToReplace.back();
            rowsToReplace.pop_back();

            if (rowPrepared) {
                matrix.at(row) = rowPrepared.value();
                rowPrepared.reset();
            } else {
                const auto hailI = hails[nextHail++];

                auto [eq1, eq2] = computeEqs(hailI, hailJ);
                matrix.at(row) = eq1;
                rowPrepared = eq2;
            }
        }

        // Matrix ready, need to solve.
        auto det = computeDet<SolSize, SolSize + 1U>(matrix);

        std::array<CoordD, SolSize> dets;
        for (size_t i = 0; i < SolSize; ++i) {
            std::array<CoordD, SolSize> replacedCol{};
            for (size_t j = 0; j < SolSize; ++j) {
                replacedCol.at(j) = matrix.at(j).at(i);
                matrix.at(j).at(i) = -matrix.at(j).at(TermPos);
            }

            dets.at(i) = computeDet<SolSize, SolSize + 1U>(matrix);

            // restore.
            for (size_t j = 0; j < SolSize; ++j) {
                matrix.at(j).at(i) = replacedCol.at(j);
            }
        }

        if (std::fabs(det) >= Thres) {
            posX = dets.at(X0CoeffPos) / det;
            posY = dets.at(Y0CoeffPos) / det;
            posZ = dets.at(Z0CoeffPos) / det;

            const auto velX = dets.at(VX0CoeffPos) / det;
            const auto velY = dets.at(VY0CoeffPos) / det;
            const auto velZ = dets.at(VZ0CoeffPos) / det;

            std::cout << "after using the first " << nextHail << " hails:" << '\n';
            std::cout << "rock-pos-X (scaled): " << posX << '\n';
            std::cout << "rock-pos-Y (scaled): " << posY << '\n';
            std::cout << "rock-pos-Z (scaled): " << posZ << '\n';
            std::cout << "rock-vel-X: " << velX << '\n';
            std::cout << "rock-vel-Y: " << velY << '\n';
            std::cout << "rock-vel-Z: " << velZ << '\n';

            const Equation solution{posX, posY, posZ, velX, velY, velZ, 1.L};

            found = true;

            bool okCheck = true;
            if (rowPrepared) {
                okCheck = (std::fabs(scalarProd(rowPrepared.value(), solution)) < Thres);
            }
            while ((nextHail < nHails) && okCheck) {
                auto [eq1, eq2] = computeEqs(hails[nextHail++], hailJ);
                okCheck = (std::fabs(scalarProd(eq1, solution)) < Thres)
                    && (std::fabs(scalarProd(eq2, solution)) < Thres);
            }

            if (!okCheck) {
                throw std::invalid_argument(
                    "unique possible solution for first hails does not match the hail n."
                    + std::to_string(nextHail));
            }
        } else {
            for (size_t i = 0; i < SolSize; ++i) {
                if (std::fabs(dets.at(i)) >= Thres) {
                    throw std::invalid_argument(
                        "impossible to hit all together with one straight rock launch");
                }
                // TODO: generalize: range of matrices should be computed and exploit
                // Rouchè-Capelli.
            }

            // some equation needs to be replaced.
            // The first 'minRangeAlready' rows are already ok.

            size_t nextRow = minRangeAlreadyChecked;
            size_t maxPossibleRow = SolSize - 1U;
            while (nextRow <= maxPossibleRow) {
                while (std::fabs(computeDet<SolSize, SolSize + 1U>(matrix, nextRow)) >= Thres) {
                    ++nextRow;
                }

                // nextRow now is the index of the first row dependent on the previous ones.
                // replace it with the one in last position.
                if (nextRow < maxPossibleRow) { // else: useless swap, it will also end
                    std::swap(matrix.at(nextRow), matrix.at(maxPossibleRow));
                }
                --maxPossibleRow;
            }

            minRangeAlreadyChecked = nextRow;
            rowsToReplace.clear();
            for (size_t i = SolSize; i > nextRow;) {
                rowsToReplace.push_back(--i);
            }
        }
    }

    if (!found) {
        throw std::runtime_error("generalize the code for infinite-solutions cases (few "
                                    "independend hails trajectories)");
    }

    CoordD res = (posX + posY + posZ) * Scale;

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Hails count " << nHails << std::endl;
    std::cout << "Result: " << static_cast<Coord>(res + 0.1) << std::endl;
    return static_cast<Coord>(res + 0.1);
}

int main()
{
    try {
        day24Part2(Input, false);
        // day24Part2("./24_input_file.txt",true);
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
after using the first 4 hails:
rock-pos-X (scaled): 24
rock-pos-Y (scaled): 13
rock-pos-Z (scaled): 10
rock-vel-X: -3
rock-vel-Y: 1
rock-vel-Z: 2
Lines count 5
Hails count 5
Result: 47

Real input:
after using the first 4 hails:
rock-pos-X (scaled): 0.191147
rock-pos-Y (scaled): 0.342596
rock-pos-Z (scaled): 0.13108
rock-vel-X: 139
rock-vel-Y: -93
rock-vel-Z: 245
Lines count 300
Hails count 300
Result: 664822352550558
*/
