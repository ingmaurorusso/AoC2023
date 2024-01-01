#include <string_view>

namespace Day17{

constexpr std::string_view Input =

false ?

"2413432311323\n"
"3215453535623\n"
"3255245654254\n"
"3446585845452\n"
"4546657867536\n"
"1438598798454\n"
"4457876987766\n"
"3637877979653\n"
"4654967986887\n"
"4564679986453\n"
"1224686865563\n"
"2546548887735\n"
"4322674655533\n"

:

"132422324334434224324232235332334512245232314554114222236526655634365435453542643424236544664154334112555152531112124353343132424323324332222\n"
"334232422421324113124334414434115245435442443516564333466652622655266255545344536255233336653646551131512323114215131434431111331422341241121\n"
"242222221313122342225541133544112335512455352522534232654565662546534235343455562453664363625534624512511125422245212445153521331422134224423\n"
"414444332412334414145121514354533333135325225626544656333364655533252623466324235432564236653343432552212214122113444112124214232112242224131\n"
"431321313343313322432325115144253525533125542446456244662223536222636423234244242643334463234532265225432151523122115242213235323243331244142\n"
"314121121331441133114133434345212431213442324254523634566542366332465456452524622634326426544526442565556154243155511233333442434213241214334\n"
"423414112233341513445514141511215424223432365253464256362646246365352643633433256626246366533643666525566631531445355445553214122324243233342\n"
"121123114214115345324125252123324465263532523534334655542342336232522456442656663566652654324525245622226223413235531524111143211314231414231\n"
"212323211243555223325333351312256226555536222625625262422362336655423244525433555432343565523342424624335356465415531432451531124312443422344\n"
"424233334222233211432244221345142556263552643554456533344452542622523422256335432243345625454345253535545346324655543254544235532552412131314\n"
"121322434122215523222412412434643533352534663533225646566554564565754455656647754535424265466325434642342543253532221235121212422451231234141\n"
"243423242553452251544424121165266356546666433456362353534354753467456474445767654667653444335326666334263355346263321515334133114431514424111\n"
"231314313143222252354222521345322343323254432363654226736734766557744354764466456634735444534666526226362632266454322215253132134451422321132\n"
"342244315412344432113335546462326622533432224642336743563334647676533445766646547357566443435266326562243365362566634221454242452145455431133\n"
"431112543445435135321243254554262435444253542564633675474357654453654433435344443667347367555472543446665555442363626262211425255323451343442\n"
"233114113112124541131234462424542344622522466743674366437764453663333573736745333367644356764346576455252435322446443526523322145231413151232\n"
"231422554443142254225426462436523262454223374733367446765453637366436543555645634545633474373675634666346532436336645542641552331441441532112\n"
"231115535442321255553464264255522544344645743656533536376677733655757377674333537643536664577745466443222632666362464646424443541441543413541\n"
"414142552154344525354336663432434243445573544556557433333547777467347354367376676375463656754473457666526522443366564663553232141521255133541\n"
"414423123144122414524243422426322455243477446567777355676473744344766446676555667437433437573365344447774463423263322256543232113525525354241\n"
"124233221225241355535652533662235543376457334754533777444346474734376466574547444664555563433736737575633464634523556563364532512154134514131\n"
"232152234512413236336624235325256224434354445765634437444737343757765377343664456335667645337654734364367745446235552244523435133552214552441\n"
"544322313545435225634363553526564466444374465434443676544575754745785774675846537773533673674555664456546575533454543332545622232325235541413\n"
"311113113525351663534263246256365363644757373453565756647555684786484655645545755763356565663537455455464757772236322233636566363453223531143\n"
"113341214411342456252553324246345665445655346454573573447687857678845854745668584458856735374566677776634765634356354554646426422342522141553\n"
"324154524512332235456262443362364454534746637676747458776885544546875888687766548857777788335347473733756577633564325533356633655552322524132\n"
"234535145235135464626465356224446456565433457756647668678464486654575548476448657457855455567663433674744636755765653654362245443422251554245\n"
"334352455435255323564252452236645656674657636736766678855685584846745876764664788857754866575743477335536357457334434623426226564561524422445\n"
"352455153532226256624352344345655547357665465676886847765757557547565578747465888775866767444574555477457666737744655546243344354354112455221\n"
"212215223243355246552242525477566536634747674566765746868555546755554474744744568786666655448745675735656354445343555354644663453432443553341\n"
"251545353426566264555544653574433355563335775846866647754458844457675658658788885464777675665645874534577777754335746666424634233446625514514\n"
"313415255523532422523423443367446344444633785746866475478488685664887664464587845556444557865475856673733456743646347443326245343464542313145\n"
"142512546536445544454536746366457574333477667477447876545775468786747767745457575448678786666745677875455544475457577456453665633244265345233\n"
"411241135354233424244663647676463473564478474775748887475885888757647874564548867474877677754664448584575537474636465354626236636345424425451\n"
"255222544542253635354443663676757475774865487464655575445465584554657659898486765547757658748874677484453653544734644366643634462654446532342\n"
"544551532634432263336567745637675444638648558664668867665487575658777658558585855686845887877867657556747737737446756647555624464635364245345\n"
"422354423644223655245643345347355736554444748557867476645478895897758778788755556587744878455544586577548445563653574634754224625462362345124\n"
"233115353245333522636333454364774633755564856445488684466988878865769559986867555958697585844464587846565655435337766557663225653323266225535\n"
"355223435555262336644433735445553348758776457887785877889769768759756798896799669765775858877755746747677586434556773773664525546365442434534\n"
"553325662635633562343447464645536756757865458768764869558769656786679688786778695589876689556848744686684547773475554775547733466423355426253\n"
"331436362553536226777465454763446675846787565848758966686558678555996657669795599989675569868648666485484446676665536775663745645526643542355\n"
"334356236222435335463555376744577754854756566788575579657676879986987559978699889987956979795854684866486884875554567373477645362656663423212\n"
"525222655422454535743767737337456574774488447554855866687979855697867588567755858985686858768668567778886655648834566737735555243344625553224\n"
"321346464655645237745477366675357768786866585766687757978578697766859585995578585556867758655759474756746488884555646556564635444634453356661\n"
"346354563666465636354374476433588788588754674588888669976956659676586855688887788679776589859957687466674747488454664756655637664532623562454\n"
"125243256234345355756445367538576545445845858956659586578569958859556765887665795788677588666886684687778686687755647476537473653262525633264\n"
"356563536345545454635437766358646484756565846696678675665869986957996959886579685698856565986878965765667577748856443757456463454665234553444\n"
"452363322632464666646677367754777554788557696576568976665965889798766968799978598596599988885956965785447546646558435467776564764523426435653\n"
"323233452553543445346666673745776867685674856995565679569585857888698698679777878756869679857577798866468665567487757355447463535256264253353\n"
"324324344646325433463763436687487474658458855765977666855555999886698979796698966896788777555687678888676647557685753654565653675355336434542\n"
"424425556362666345435756453875557578546879967868885696858579678669687966686798869977775776595787767557544466766775547477757343733455224435433\n"
"332664554255665343374557445458866644876555779899975975988988696669697767887997669987995696858687896859868475577588848347664464756435325522646\n"
"356545444354377735657455447557475644747465667658559786856676966789789889886999997777998587668856987779945467564688684555566367536333662225332\n"
"536546662422636665574776367776884854474888678778667769899879868667778686969668676967989865987696769679795486568687677576634666576636665222223\n"
"322434566643565754446336666477668547667876969859896556989668987676666687676676889886769788787779576769874458588864668474375346675542524442653\n"
"253362366254435355346637485444484487675667886775789667688669988677997766769766699897888978668787885667568846777866845537366765443764346466552\n"
"463233346243535375464473766847755788457969685959565799699688787698688899989967977676989686689897888556895556656784875584437347667473422242663\n"
"625565355664633544554576868656755668665685686867999686879678887786696968968887768797987696977967767756868967886768885575376655637766533424242\n"
"626652556426763565576647786476864487875959897895957776768897767669989697888879699697897989786579676758795948658585647543577477646334345565645\n"
"232243245257543533543564464664467788697766969769878786886967996777698899979687868768679969967696567557578578778576748783556774344475342256566\n"
"342342253624577764665734748768885567958885967957576996788697696896777898878899986697977868889797865656655556564575884578533334336746455333245\n"
"543326224646456444734536777888785577599865686696669889879687796998798888777979868969686797997699966579888588885764557558537667667735565344622\n"
"643334534373565373673645487478777885775967559677767769798889889977889889999788779798696988779696695966585876888867587474345575636766434423234\n"
"423262266434553673457664565748788878688578889696999886769796869788779898799978998886869688779975888777559688585847568666345366575634464224346\n"
"253626362535647766664577688644666777585756697759966999877977799898799997797879997769666978996687897568896775846856477456373335447566424356465\n"
"643544454455567456655676656765477746587798577999886777769896788977988788799878977897698789689795777988886985645646777448873376457357425643466\n"
"543364322347355747564676884755856488775579779859897796987698997787988979889799987976969868666766568995568866644855848888663437333543463633654\n"
"533425453345754467744487474578587857686985885577989996787688988979789899788997897977999787867988755868997955858477455785654734375345436525636\n"
"452532524243333555647657887877788585679565697656999686786799899997778987977979987988686678869686797769656566446666575555757476355743366435264\n"
"264443543564346677553377776475848889896656596786967796888887899788999989797977778999679696679999566965678895957558448756576444446736636624636\n"
"352254522266666363447746465445576567585695995878968898668988999898999879877897877889677666998898586959689655864655764654574464375363355532323\n"
"466362444243446765754758575855544859689896865877868868868998787789998788798779997799796886999688956655899667788877786585467457435445346345623\n"
"524245343374367446356467577546766768876695699889678998797867978788898788877979778999777776767679799969555957768764585884646445537433552335436\n"
"263443266355573655755545588578544496669668979887766869879897977888798789797999988887666769987896599656595686848877548768874764453773753226632\n"
"254523526543673773453377775688467485758597776697676887688777977898778887889979899789969966966886756677569675787587648578576357633374523535365\n"
"456266522563345675557764564687767776876858867569689769687689979778888877887777978879786768978689675667556768688668686745874654565745635366532\n"
"322545426236745433454576667565776786896575997766687977696768797787988977988988889997686998787778977885775788846575575867547556565743426535343\n"
"656323266256445776757645554588578475699956686869768896989887889987787978977887977886876699768888776998795998847848765868734675464644444523342\n"
"562622566265574553774376866467584777786998758975668878879997778787978777897789777979777898689765976977876979678664886466736666467465356636452\n"
"354636664653663773445347888565446845556965597796769896979698769878778777898787979969996998966978665899555955686748565545365645565663354255562\n"
"434344455673344774776556874486866656978696899788766996669969666879798798989987989897898878798967989598767798588855567774534775733653346254352\n"
"526346463473357566766576885447744785768795577685876768868798966798889799888778869968797878788865599589979897674776586678554473464546636533332\n"
"633536523565646365757348475746856575886887869985778866886898976697779979787999876989787798876768978898755698854474777746534365474645265632354\n"
"566623266264354334444545566666755588997765957995966767876797768979996798896786897677768697987988866857586787876485648847377776453745225666434\n"
"656332262246475336663665556666666785487997988759958989799667867969699769679867889976679876896769856695977687874584584776335375545475433564552\n"
"233255456327464563363365754765767646659985788599898789986999699798669888786667996979767789669586569677976786847464548784537536343443436253542\n"
"665564323365534537436365474454568864747796766757569788997899668686667786669999968676888878986898688888889845874756857644544754374546435232243\n"
"553566532543645465347754647775786868877778667988557579799979966787679969897776788697866667689678857988667655464645844746647336766374465554532\n"
"224632634663774756547755676645676757675697998976966658997798667966877668697796798879689678689896598775784556487777884536377374453746225356456\n"
"233235365355447745544633455444656754675875978656965989599886866987997767678777787988879659777757675585678847677875686736743633763662642233445\n"
"326653266452545466776477768444765687544788669655685659777878886897867688699779887768777687776986755976684777568846874337646777777533654323552\n"
"366244364565667637644346538666564585848469785986896695669969867977778787866876969966766769767765699575874444846447687644453533456354653323265\n"
"525522663662273466366544765585844747766658555756568958978568669778688798968989867688978557656957969969676774547587455645577467633632434363366\n"
"126463645443346637467646373547557547668585695565689776667979969776699687777879689699779788575996866654484445684584886743453733635462224325452\n"
"422625656242345357547773577586548784744855867955775995955768787898988896767978877699576575688687766754864567745745635645343736765263646254453\n"
"565325463436424766344337464357847668467466788858765976667965988896768967898777595798759986795985865854564568885658745574546655763224424644226\n"
"313643466264325736747337355667754464466476885768775668699869966858667575679976595885667798655789587687878845657468637374547533554663426634432\n"
"544252436663434346436645655554758768745487786655899765989757975656689655986568969775755895596656858557746867564854376663554576335363524536325\n"
"556663342446422653345666775645477657776846754596965567559657588655577997575995575999975767995577866555485877784574746477676435755436246243355\n"
"255445432355535554563436466735486686478656767678956667859655986886587788696968578566569875858598475758668784676663753363744436735345543236331\n"
"515223635435322433477363447544477854586485488886778877998788797676775777965675676589897697898874664675878588858655433433347373232252433256562\n"
"243246346252234535557567765633658874844558656487646587865785576656755899565978566679566867659687588467554578775366564437366754524365454255323\n"
"322235453336535624337353653577554646445546556775758697676577898787888797777578655969999955776755475744748585763644343746647536362326564352512\n"
"412442253634523522254443363734364355766756885844856576865756657896556677878957689575888766666875586548484444567734335373553743423464244464132\n"
"342345426556356623446773653464574435457777745448558785798567886687599595956685597765857875847786845464474476753733773357474425552565545526353\n"
"151124455653566446256433633674373773755768574548877546647796978586755698956898999998865485648865586688748886653665533743554256454644456245525\n"
"542323363553233636332536343454635337776478587458774756776849987956687788685897957978588784668785757874484754467655563475574542626346262563412\n"
"214424234644564363335363554764546465537866855646485464674766545855799855995688666588644854584848464475748456336447545665452446563262255352425\n"
"154314366665565642525233645535337674367788664847566446484688858655575575866574566656665547478558476855766663357344745765722432553366334654415\n"
"145132355554654442442327746673367763474776557885547577764586756666675655446648846766755578754656685665874457373434546337256426445662333531212\n"
"115555556226443465434664357364766336373556667848887476784877464858765465556784488878567645656855747488343745333435556553566426662653535342225\n"
"544454122524334442442324455754433553576633688464688488466578487786785848786586768474748766574875878753755563635435555365665666544326561551353\n"
"313454351322543524244566666455463537646656667874478676654665645457447778886867854458587587848867886463766576456564646723444635622464422523255\n"
"321243154262634364435456255466666354756355753578864745745466678476586855775484566785448787764878863436775475347566565324252565622264635331455\n"
"533422422454345256665433342535343637657755676465747855876766475886567688648856684674684487484784443656373465366654352553556244253562325255142\n"
"532431453224555365364525535445535675455337757736554475856687464644456848778877448884568786665634745545547566564773334236626243456432115342242\n"
"444332214224255323565345422336376346566545337534653558585776884467678576676688485687585644545364574546434357466755553642534662666454112152343\n"
"412134322351143643445524225254534535337463353736657637674758585845474766888666877667867556434744445546335353536742654633445646555452522351115\n"
"455312551323153464463524236564336767474366746634335363368684754664854888465566785468754637334755365776344574337463232666454562435143151414332\n"
"214324422315255662655534325643332655377545766444453654544333675548448657788866754765756733334757633363355675464233262564234535561524342525335\n"
"125413133533345533453643323353263373353635436476756763755473744678588764744656354367747754553473665553656434662422635253562546324522345121413\n"
"351345312555135552364342666655344426577767654655635635735355464655334743364745333435634756365673366345334575256654334222355555122133532134352\n"
"113133533342234455435446224443543234544535635643775436433473335365355664764676767446655557436457664346446364463645366563662225313123435251243\n"
"142323113122433425222432344522354243535777563467763334777336354375646476335745444674755764363373574735577456352553552633454623151211112422555\n"
"313334543553152342513352346523326463564656557653736533434777475574435433637643733643653543744547634476655642643426353365526441253211514421144\n"
"442123453513215123121552364543355642323357566747564646343546575356634563635735676333744737374577747376243524524244424532361212342513243144442\n"
"443324545554454315325556466363624242645456554637366633776454535545746346633375643644637334765454736423653264446352465545315311234555141444231\n"
"243114355334455313521315434364623332252462655545645766576746347444536576564733457633473664565777775322252522325445242562155125351435133534231\n"
"241221242123535244221231235563546263323456466652445736455677757777346434767443357447766344575472522624462442453535334562254255433341245122143\n"
"324334212522454351253445463335263362462253442332546475774564435653743366347446636554376375377644234546635334446663344342144313515145551513312\n"
"114142345452442523534542454542556456336463535452532354766554476646774474576377334747537567652662663422624236643262535543441424434323511123113\n"
"444212411143355544452534145425625332345563653233543646646674437633447667337753777366676522326644434256565556224326454443514525424223212112133\n"
"131131314134432355354414441352426255632553532324464655563464355434456473433563746322464234246565423633225355565554454354433113552223443121313\n"
"333313411444255155432112512415543626566465625463553234234632546223265225466535534624454545523436224232325433224633234542534434123252224332224\n"
"424444414443135441543214145424145365665663365345253652632434422344545363355362525436352522546433324354323355336314441323514453522143444124112\n"
"411341123431412511514113551345232324464326442543335224225436233563524433452365544665426463526253222653552666341414333555332445415344321334232\n"
"242244213241324341555331212355441432235566665544225424464362464555622442332653252546425662356445563466642342524144442223451141343412414244444\n"
"413234111341312352531313511122133211514543543635633622223653556462532522625323646254253452253436546266322545531213442334214541541212132413313\n"
"422122333124144414545151435223553355112142652563426243354526522565343343663343253454633434554324524626541135414324141524144132442344212434132\n"
"224224131233343141525332312454311442245151365353432425435266353346236624553365362223554355626555236255412431244124532233455453434224213114111\n"
"243313111243332234425314121543325521422424543353643642343236523625435525352232564645652445452364256345244412222535132541555534111331141444412\n"

;

} // namespace Day17

unsigned long day17Part1(std::string_view streamSource, bool sourceIsFilePath);
unsigned long day17Part2(std::string_view streamSource, bool sourceIsFilePath);
