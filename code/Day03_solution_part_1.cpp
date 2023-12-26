#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <string_view>

namespace{

constexpr std::string_view Input =

false ?

"467..114..\n"
"...*......\n"
"..35..633.\n"
"......#...\n"
"617*......\n"
".....+.58.\n"
"..592.....\n"
"......755.\n"
"...$.*....\n"
".664.598..\n"

:

".........398.............551.....................452..................712.996.................646.40...1.....875..958.553...................\n"
"..................................661..-844......*.../781...835..#163....*.......698.239.........*.....*.............*............*57.......\n"
".....................&...............*......+..139..................................*.........-.......282......................301..........\n"
"........518..........918..-....472..172....776......207............38........................860..............274..945.....162..............\n"
"........@..........#.....845..*........................*.............*....896...+.....153................@......*...*.......#.........441...\n"
"..................740.21.....303...744.........190......173.395...729...-....&..925....@..5..............172...566..193...........#.........\n"
"...598...967*.........*...........*.......164.=......91......*...........192................292...........................414=.215..........\n"
".............238.......661.....-.149.....&..........*........299...@644.................919*......*661..760....@.110*.......................\n"
".............................742.............$...125...+......................696..............523.......@..166......496..............#462..\n"
".588-.........#867.........................945.......457..505........%875......./.....+.........................965.........190.671.........\n"
"........24.........278........934....*569................*..........................180............................=...........*............\n"
"....988...*....151..@.........@............&...........242.................409................807..900#...417.886...........................\n"
"...........330..#.......................729........&.........105......482..........679.........#...........*....$......752...749............\n"
"...=............................../.............995...........*..689.....*.....-....#..............*604..696.......489..........+...193.&336\n"
"..287.........17..737.......468....869.+.....................673...*......480...860........23...435............-..%.........................\n"
"..............*............./..........552.............529.......271.+864..............848..#................771.......216........588...@...\n"
"...........262.................185.........688....848.....*56...............%....$.......*...............362..............-..............250\n"
"..507..............812.........*......................112.....556........754......841....959.........2..*...........248......232.527........\n"
"....$....................478.627....175..........960.....+.....*......................#........790...=........503.....*.....$......*...%....\n"
"..........................%........*........694.....*.......930...451+....248.......20..........*...........$...$..285..203......904..184...\n"
"........531......30..969........435..772.........234..542.................*...............706....351.......571..........*...................\n"
".........#.......*...................*....&.8.........*.......313....+...807..398...........=.........540.........+....867............#.....\n"
"............34...231.......934*....802..120........965........*.....424......*.........@.................@......974...........53......619...\n"
".....504....*........640.......127.............................671......316...538....151.......498........................914*..............\n"
"......./.562........*...............504.....................................*.................+.....=..........835...................500....\n"
"..787.........*122..149...$.................*....227.335....863*396......941.230.................847...215.......%..49..982..73.....*.......\n"
"...-.......843..........240...932....@...352.830....*....*........................950........11...........*..........*........+.....819.....\n"
"......354...........-...............66............&...501...................*.........39......*............513.651...482....................\n"
".....................160.........................437......&..797....551..337.383..735...*...546.............................................\n"
".......=........184......./.......67........476.........336....#......=...........*....426..........972..../960.....981......684*...........\n"
"2...473....#....%......449........*......=.....%...........................877..890........+..../...................................834.....\n"
"...........498..............926..887......147..................%.260...+..................965...939..../................894.....659*........\n"
"....163...........*237................409......858...........184.*....33.......705...993*.............139..791....955.....@.639......668.455\n"
".......*.................128.....................-................677...........&........899...@....%......*.........*.........$.......*....\n"
"613&.208..975......./837.-........772.554...........635#...927...........392....................761.300.....42.......68.................969.\n"
"................389......................*.@...851.........*....344........*...90.....@231......................+...................182.....\n"
"...-.286.296...&.......424...313......656..758....*.../..294...............722.#.......................689.......853.................%......\n"
"546..+......*.................*...698...........664..190.....637.10...122........-758.........&753.827*.................#..@.....777....177.\n"
"........490....$.............961.*....31..@................&..+..@.........781.........................................690.285.....*........\n"
"...........*...421................720.*..133.=............298.......933.....&..=......805.461....531.......888.....................965......\n"
".....923*..310........219.302.................107.....457.....186#.*............691......*........*....89..*.....*..%695.946$...............\n"
"........................#..........867.87...........................9......................623.432....*....678.819................+670......\n"
"....673.......#809.68................*..$...127......422.......954........516*291.685..661..........163........................=............\n"
".....*....................648.....325........-......*....308..*....................-.....=.709&.366.........................219.............\n"
"..132...439......$.......*.............134...........188.....134...257*38.300.77=...............................707.....................357.\n"
"...........*..298........602..............%......940.......................*...........986@......438........710*...........594.....919......\n"
".....667..77................................305..*.......................941.....126...............*...............637......*..549*....116..\n"
"......................876+..#516...........*....467.....981.....................*.......726.737.....434..149......%......776................\n"
".......@474..%..............................506........*........58............92.../37...*.....*633........+.........605.....239*72.........\n"
"...148.......262......729....430.....................748...&...*...995...925........................*................*......................\n"
"......=............................*....655..............254.566..*.....................*628.-356..769.............805......................\n"
".........229.................48@.251......*.......................733...521..........593..................148..............59%..632.........\n"
"............*....69......................758........477........-......+......654.............................*173....................543....\n"
"..........624.....#..480......@.................959....*......124..980...233*..........278........799/.260*........130......../741......*...\n"
"............................373...=........265........436..%......................552.....*.........................*..423...............733\n"
"316..93.............205............606....................994.316........824.#654...*..860.........947.956..470...550.+.............*682....\n"
"......%....*487............185.........955..-...................$.364....-.........874......#865......*....../...................756........\n"
"...........................*....512....*.....702.852....595.........*........942.......357........620....=......814..107....................\n"
"....#275..650....204..840.......%......57.........*....#...........71.540/.........616....&.......*......899....=.....%....627.....435...849\n"
".....................*....../.....483.............363........................832..=............&..855.............-..........%.....@........\n"
"..697..+..........661......36......-...*........%.........644...49......245..@...............434...............237...=................=.....\n"
".......398....773.............*131...248.300....627..............*.......=..........261....................422........621....780&..599......\n"
"...............*......855@.517.....&......*..............592.721.714...........195.....%...........701.612..................................\n"
"....855......943................182.......726..................*........274.6.....%.......799.........*........584..............972.........\n"
".....*............92.....637....................648............781.......*...-.............*............513...........542*.......@..........\n"
"..249....834........+.........190....................216...........123...263.........................72.........413.......829...............\n"
"............*...773.....*510....*.211=.................%...988......................488-.......214...#...........*....................315...\n"
".........+..508...&..144.....873........403....484../........@..606.533........918=...............*...........421.............230.528.......\n"
"......650................34................-...%...74..........*......-..............*119.......25..749.....%............828.*....@....68...\n"
"379.............&275..../.....768*805...................112.....237.......*855.....20........................773.....987.*....814.....*.....\n"
".........$.929.......&....................436..669.........@...........363...................278.....229.........402*................646....\n"
"......897...*.......528............662@..........$.....#..........789.......&....436..282.............*.....................863.=...........\n"
"..........311...........902..819....................118..679..710.......$...314...*......*181..345.530..$..388*......791....*...347.....#...\n"
".279................74*....$.................237...........#.*.........900......604............&.......455.....485.....*.548.........477....\n"
"............928........734..............440.@.........................................989..........902...............431.................896\n"
"........279........949.....659.....952....*....797.795...$...............4*..............*........*..........960*568........491.....236.....\n"
"..........@.549.....*........$.670*.....254....*...*......184......&42.....129..........121.....486..................*.........&............\n"
"...486......*.....846.......................757..................%.............................................699..829.....................\n"
"....*..88..321...........4......535....594.......=...........=.511..167....-......*............853...............*.......87...........763...\n"
".303..$...................=.....*.........#..265..697.....462.......&...360....163.528.........*......774...127...770....@........891./.....\n"
"........31......731..+278......667.....#........=...........................................328...591..*............................*...31..\n"
"...................*.......927........420.650.......21.......918.......464.685.451..@................*..317....471*47.384...217..83.15..*...\n"
"....234..219....303..700........#348........#.....%...@.......=...+..................403......419...82................&..........&.......798\n"
"....*....*..........+..................738......857.....203*.....746...........................*..................*.........#...............\n"
"...768.527.....77..................%........................623......393............643.......832........647+..773.421...402...29.370.......\n"
".................*175.......352.564.....237...*.+681.............=...*......&37...........832......../..........................*../..%.....\n"
"......187..............218...................46......817.......893.139.............*..253*........436............../....619*.772.....532....\n"
".....*........165...+..................910......647.$..................@.511....143...................784..416...373........................\n"
"..442...834...*....566....+876...34-..+........*...........507.......348.*............*..................*....%........590..................\n"
".........*..157.....................................344.......@..........988.......745.867............526..+...........*.....109.331.254-...\n"
".....456.............%..375*...........*.......199.+.........................846............=...............656.................*...........\n"
"....*.......266...893.......441.....686.2...............455*748.............*..../980........726..................384................76.....\n"
"....59......&..............................389..../.............427......645...............-......551..167..............130........*...*....\n"
".................=......10.....642........*.......536.29*........=...566........72*904..935...155*.......+...$360...703..*..252..870...739..\n"
".......252.......158......*......*.........695...........949............*............................................*.........*............\n"
".......*................830.......758...........................917...377......*519..622*439..../802..........665....481....231.............\n"
".......823..563.....................................167........*............334...................................................../.......\n"
"..............*.................&.418/.&49......209*.......495..783..............185...%.............418/..........470.............289..831.\n"
".............60.559..........599............247......@.......$......170....884..*.......387..........................*......................\n"
".................*......*61.......................954...........216..*....*............................@.331....695.958.891*............351.\n"
"......$...396........947.......234*....................994.981.......85....819.....435......./......594.....-...../.........592.............\n"
"......605..*........................16....$.....907%....*..*...629.............958*....950.321...................................671........\n"
"..........867.....821........987.....*...928.........275..687..*...904...300............*........864...................960.111.....*.148.19.\n"
"..494.............*......410...#...517..........700...........714...*................988...........*.............445..*....*....473....-....\n"
".....*138............221*..............970......#....717...........26......$.....749..........253..330....214....*.........293..............\n"
".................%..........636..#........-.............*............./....180......&.532........*........*...403...........................\n"
"............*..684......242...*...653..............374...822..........575...............*.....133...#...440...............322..780..........\n"
".........685..............*..658.......224...-.................%..........*118.........322........615.......981..........................806\n"
".337..............856..843............*....816....448..83=...824.839...568........989.........562......594.....*..........*21...833.........\n"
".....708...........*.......355.........437.......*..................*......*........-.944....../..185.....*...286..723..........+....552.652\n"
"........-..73.......230....*......................927.%137.......754....490....782.......-...........*945.682......$...+............*.......\n"
"............*.616=......*.595.......*...842..........................84.......*..................+....................80.........383..1.....\n"
"..........357.........492...........771........68..........927*363..*.......262......69*224.......882.785..&313.............................\n"
"...............................%391..............*....865............947.........583........*120........*..............449..../.../557......\n"
".........................634........8.....610..240.......*......508..............*.......875............297...717.941..*.......92...........\n"
".....874*180...&107.100......................*............453.......561....738.758..168.......................*....*....835........260..97..\n"
".650.....................230..................980.....................*....=...........*...605..396..........753..642..........537..........\n"
"...*...........149.......&..........797.219............./743...................=.......333..*......*....882.................40*.............\n"
"....103...348....%...............86..$.....*..99....................&...........25...........749..950..*.........................&..........\n"
".........@..............719.175.........652.....*............/......565.191.575.........................583........#./...........223........\n"
"...........................*................295..358.806..520.............*..-...................%....+.....118..632.709...901...........790\n"
"..562....221........735...........338..........*......+..........980....315............682....630.....762......*............................\n"
"...............761....*......408.%.......971..246.................*................307......................949...............553...........\n"
".................*....194...*...............+...../.....$....$...301..............*.....857..........752#..........680.188..................\n"
"..............551..........689.......*29...........345.75...898..................625....-......#732................&..../....876........576.\n"
"..................................487......326*71......................143..................%........#.=.......................=............\n"
"..42*....563......./..........976.......................496..233..224.....................270.....540..114....972.208....*...*.......950....\n"
".....667........915...283.....*........161*.......*764.........-....#.178...634+......569....................+........945...340.$.....*.....\n"
".........550............*.....973.694......209.228.....................*.................#..+..179@....832.......@..............67.448......\n"
"............*...337..284..656......*..433............126.............860...857....*........411.........@.....=...977.....................726\n"
"...815...896.....*.......*......993.....*.....309.....-..........735........./...985...*.....................797......842........$93........\n"
".....*.........424.......348........94...82.....*..........#25..*.....46*380...#......618.902.142.......972......$906...-....%96........482.\n"
".....12.............................../.......340...46.756.....327..=.........897...........@....*435...*..........................*546.....\n"
".................................185.....654........*.....*........772..+959............................581...13...918..388/....895.........\n"
".90............915.......758.664*........../.......885...564../160................830.869...........474.......*.......#.....................\n"
"...*.....510....@........$..........$..............................813..795..........*....210........%......438..........786.......778.77...\n"
"....984.....%...............+..712...83..*....130..................+....*...545.............*......+.............../.727./....826......*....\n"
"................490......519../...........16....%...42.822..486......214..../...............985.480..............798....................249.\n"
"........369*........317*.........632...#.............=...*.$........................-703.............+341............88.....*659...@........\n"
"............595.........566.............847............456...................................182.........................791........533.....\n"
;

} // namespace

auto day03Part1(std::string_view streamSource, bool sourceIsFilePath)
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

	unsigned long sum{0U};
	unsigned nZeroValues{0U};
	unsigned nLeadingZeros{0U};
	unsigned nAlphabetic{0U};
	unsigned nTotalPositiveValues{0U};
	unsigned nTotalUsedValues{0U};

	using StartRange = size_t;
	using EndRange = size_t;
	using Value = unsigned long;
	std::map<StartRange, std::pair<EndRange, Value>> prevNumberRanges;
	std::set<size_t> prevSymbols;

	unsigned lineCount{0U};
	std::string line;
	constexpr auto MaxLineLength = 1000;
	std::array<char, MaxLineLength + 1> cc{};
	while (inputStream->getline(cc.data(), MaxLineLength, '\n')) {
	    ++lineCount;
	    std::string errorLine
		= "Input error at the line n. " + std::to_string(lineCount) + " : ";

	    auto c = static_cast<size_t>(inputStream->gcount());
	    // 'c' includes the delimiter, which is replaced by '\0'.
	    if (c > MaxLineLength) {
		throw std::invalid_argument(
		    errorLine + "longer than " + std::to_string(MaxLineLength));
	    }

	    std::string line;
	    // std::cout << "length = " << c << '\n';

	    cc.at(c - 1U) = '\n';
	    // replaces '\0' (if it replaced '\n').
	    // string_view assures the correct initialization of 'line'.

	    line = std::string_view(cc.data(), c); // includes '\n'
	    // std::cout << line; // line contains already '\n'.

	    {
		std::map<StartRange, std::pair<EndRange, Value>> numberRanges;
		std::set<size_t> symbols;

		Value v = 0U;
		StartRange r = 0U;
		for (size_t p = 1U; p <= line.length(); ++p) {
		    auto ch = line[p - 1U];
		    if (std::isdigit(ch)) {
		        if (r == 0U) {
		            r = p;
		        }
		        if ((v == 0U) && (ch == '0')) {
		            ++nLeadingZeros;
		        }

		        constexpr auto BaseDec = 10U;
		        v = v * BaseDec + static_cast<unsigned long>(ch - '0');
		    } else if ((ch == '.') || (ch == '\n')) {
		        if (v > 0) {
		            ++nTotalPositiveValues;
		            if (symbols.count(r - 1) > 0) {
		                // a symbol was there just before the number.
		                sum += v;
		                v = 0U; // avoids enriching numberRanges
		                ++nTotalUsedValues;
		            } else if (const auto it = prevSymbols.lower_bound(r - 1);
		                       it != prevSymbols.end()) {
		                if (*it <= p) {
		                    // a symbol was in previous line above the number,
		                    // including positions r-1 and p corresponding to diagonal
		                    // touch.
		                    sum += v;
		                    v = 0U; // avoids enriching numberRanges
		                    ++nTotalUsedValues;
		                }
		            }

		            if (v > 0) { // else: already added
		                numberRanges[r] = std::make_pair(v, p - 1);
		                v = 0U;
		            }
		        } else if (r > 0U) {
		            ++nZeroValues;
		        }
		        r = 0U;
		    } else { // this is a symbol
		        symbols.insert(p);
		        if (std::isalpha(ch)) {
		            ++nAlphabetic;
		        }
		        if (v > 0) {
		            ++nTotalPositiveValues;
		            // A value has just ended, followed by a symbol.
		            sum += v;
		            v = 0U;
		            ++nTotalUsedValues;
		        } else if (r > 0U) {
		            ++nZeroValues;
		        }
		        r = 0U;

		        // Check also for numbers in previous line: up to two values.
		        if (!prevNumberRanges.empty()) {
		            auto it = prevNumberRanges.lower_bound(p + 1);
		            // it points to the first that starts after p.
		            if (it != prevNumberRanges.end()) {
		                if (it->first == p + 1) {
		                    // a number in previous line starts exactly at 'p+1' (diagonal
		                    // touch).
		                    sum += it->second.first;
		                    ++nTotalUsedValues;

		                    // avoids to count it again.
		                    it = prevNumberRanges.erase(it); // 'it' moves after
		                }
		            }

		            if (it != prevNumberRanges.begin()) {
		                --it; // begins at most on 'p+1' (or lefter).
		                if (it->second.second >= p - 1) {
		                    // a number in previous line ended at least on 'p-1' (diagonal
		                    // touch), or above the symbol.
		                    sum += it->second.first;
		                    ++nTotalUsedValues;

		                    // avoids to count it again.
		                    static_cast<void>(prevNumberRanges.erase(it));
		                }
		            }
		        }
		    }
		}

		prevNumberRanges = numberRanges;
		prevSymbols = symbols;
	    }
	}

    std::cout << "Number of lines: " << lineCount << std::endl;
    std::cout << "N. of total used values: " << nTotalUsedValues << std::endl;
    std::cout << "N. of alphabetical symbols: " << nAlphabetic << std::endl;
    std::cout << "N. of leading zero: " << nLeadingZeros << std::endl;
    std::cout << "N. of zero values: " << nZeroValues << std::endl;
    std::cout << "N. of total positive values: " << nTotalPositiveValues << std::endl;
    std::cout << "\nResult: " << sum << std::endl;

    return sum;
}


int main()
{
    try {
        day03Part1(Input, false);
        // day03Part1("./03_input_file.txt",true);
    } catch (std::invalid_argument& ex) {
        std::cerr << "Bad input: " << ex.what() << std::endl;
        return 1;
    } catch (std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error: " << std::endl;
        return 1;
    }

    return 0;
}

/*
OUTPUT:

Example:
Number of lines: 10
N. of total used values: 8
N. of alphabetical symbols: 0
N. of leading zero: 0
N. of zero values: 0
N. of total positive values: 10
Result: 4361

Real input:
Number of lines: 140
N. of total used values: 1077
N. of alphabetical symbols: 0
N. of leading zero: 0
N. of zero values: 0
N. of total positive values: 1215
Result: 544433
*/
