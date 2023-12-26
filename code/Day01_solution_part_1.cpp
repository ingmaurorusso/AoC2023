#include <algorithm>
#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>

namespace{

constexpr std::string_view Input =

false?

"1abc2\n"
"pqr3stu8vwx\n"
"a1b2c3d4e5f\n"
"treb7uchet\n"

:

"shrzvdcghblt21\n"
"sixdddkcqjdnzzrgfourxjtwosevenhg9\n"
"threevt1onegxgvc9flk\n"
"7dmqzksnlcpbsqkzqlfour1four\n"
"4seven9gdlnhqxfseven94five\n"
"nldeightwoshgnsjnzmbkbxcxltsqtstrgdmvqvxbfour6six\n"
"87mmlvfr4\n"
"six1vvrlxx8two\n"
"znmfvdlhvjtwo9three4tzjqcfcgnsevenccvnsjczlpm\n"
"5sixninesixnh\n"
"three1tbtwo\n"
"five9seventwobqsjqzxkptkhsix1\n"
"74fivemn\n"
"sevenfivetsglnine8three\n"
"spnvnfkbv4eightlmdkxmsfour574eight\n"
"one4four2fivedcpqjmgc8\n"
"two6sevensix33\n"
"krc34five\n"
"doneight64qgc251four7\n"
"vpjthc6\n"
"threethxbtffhbfourfive3\n"
"onetwo5\n"
"1sevenngjqsfrptq8stgzxgjfp\n"
"1576sevenninefhfqd4\n"
"nine4nine9ninefive\n"
"zp8sfveight9twotgbvscb\n"
"eight27nrzmfsix7nine7two\n"
"gsfivefivepmq9nineftndvlcph\n"
"znggdvvkjthreethree79eight4\n"
"7twofivethree7ninevtspmbfxnr\n"
"four9twoxthdxdc7two1\n"
"8ddcmt87xhkqjbgtmkpjlkhd7sevenfour\n"
"4four6\n"
"seven5tmzksnsv9six\n"
"6fivesixlxfrqbkfive\n"
"seven9one8jxqkhbfppt\n"
"hxsbgn6four7\n"
"7pglchqndpnknhvcnkthreefour2\n"
"bkkfjq6dklbppfvgsshgrbmtwo97\n"
"66eightsix3nine652\n"
"six6zjjfffhrflrvkjgdrstcqpqt1eight\n"
"four252bqdxzzfttkq85tqnl\n"
"pbgjmdfxjvzdxjjdtwo5sixtwofivesxdcxtn\n"
"jonesix2five4snxcbgmx\n"
"62rceightsix\n"
"fivenine5\n"
"nzcxfqhvninefive3nz\n"
"4474rcl\n"
"1bjlvthree1tjthreethree\n"
"bgx2six8vlbdmgsrkone9bdgzsfljlk\n"
"seven52\n"
"fivesixtwo1two\n"
"njznm98\n"
"3xhrsfshnine7five\n"
"four9eightzcmsevennzfrxtsixone\n"
"jjsxs4mgqnstgpreight1\n"
"bhv9kr8three\n"
"sklnine1six4\n"
"five52734eighttghkkszrdllrr\n"
"93one\n"
"qrlmcmfgsx55onetwo\n"
"86dnnrmms6gxskhcghct97glkrlzrdrscfcld\n"
"xxb283cftvdg\n"
"hxtwoneqpmbfgkhnr6three86eight7five\n"
"zjfczdbpgxtkffkl5\n"
"fivexnqvfiveoneszqkzdfclxkrj8\n"
"8onerj7mhl\n"
"6fivefive8eightsevenqc8\n"
"eight89nineonelmfst193\n"
"ninetwothree5six5gd8\n"
"eight6dvvd\n"
"sevenztbdzndhv5threefour\n"
"two8onebppzkln6\n"
"twothree54six\n"
"seven8ninetwonndtgkj1\n"
"cpjckcfnqrrgdzfbrtbdfive8vkl\n"
"6six5jzxqqtrpflpdqbkgktsvpjgrhggsmvltwomq\n"
"sixhbft5lnqfseventhreefour\n"
"23pqkgleightxvscbnxnp55rb\n"
"6fivesfhqmzm7qkdvjss8\n"
"twofivefiveeightdcl4\n"
"9fourfourdqfqhpbbkgtchk2nrvmrghnkdc\n"
"sixlzbpttdhlssixdhmvrrgxj6\n"
"glphjgxqvbjcqjpdsixlsgd3\n"
"qcghmvgbmj9fourfivepztxbjpnzpbxzckgnhd4\n"
"kjvoneighteightfivepsbkgdgpndxx7six8\n"
"five95oneeighttpdk64xxndq\n"
"1vqxhglhnhrpbnlvq\n"
"sixtwo34sevensevenrnflkfxmlthree\n"
"pbscshhhpeighteight668fourphkdcrjrf\n"
"threex1jpdsmc\n"
"4pnhtjzlfdcgffour3\n"
"338\n"
"62six7nn\n"
"1fgq3onethree\n"
"7eightzvxmvxbq965nine1hr\n"
"gsdqtgkhlhdff7fourtwo4threesixthree\n"
"918hjpgbz6kbdxeight9one\n"
"7dxhsk9ninejjbninefour\n"
"one2mblcjnine\n"
"9twoc\n"
"fxrkzvpkb3tdvlxxchbfsixbmmmctknxh1\n"
"pbzdkmkxczkgh5xsixtwo6kfgqsgx\n"
"6eighttwodsfppgxrzx9threeseven\n"
"zzkbhltv7ngthreetwofivegdzrmllnxp\n"
"sgfour67three2seven3\n"
"sqglnvlrn4sixmdnineeightthree\n"
"1kbkmkdnc35eightxbbknllscr\n"
"2bzrg\n"
"3onenine\n"
"threevkzrmdbnbsxrmzjtdhbeight12rncbzmq\n"
"sxcrgkvbrtwo17six527five\n"
"9rbsbcjp239jvlfpn5jrr\n"
"nine8vjcbjcxxprdcf4\n"
"nineeightsevenchjczgdvjvtqlkjsqvrzxxvlqlp65\n"
"hdgqninefive9sevensix3gzb\n"
"6fjv5\n"
"pmgdvcdp1fivetxkmjzone\n"
"eightsevenklxgcj8sixccqlnxzmbeight\n"
"bkcdmscssixsixtwozbdzcpgpbsvf38\n"
"ninefourrcmrfvszsqhpxcs89onecnzjvhrphs\n"
"54plhhmnmkvonethree2ktzncds\n"
"pkglbgdplgvlstpgpnsmlsixcpmfxfbfbtpsdxninenine4\n"
"one6qhcqnkqc9hfrsqpxmcm7eight3\n"
"threepdtshdskxgeightjtdpfbtlnph91\n"
"fmpjgjqpgbpx8two8jzqchdglhtfiveeightpzktj\n"
"njqhghlvm2\n"
"dj3\n"
"3j\n"
"eight9cgbcppzjbl1tgjhm\n"
"fvkhcvflpknqnh9ninetwoneqn\n"
"threemfour3eighteight\n"
"qjmtvcbvzzgxmmpdvrfv8\n"
"tlzqpfsix1fbhgdvhblvgk\n"
"eight451qvnhv4\n"
"7mxcvmpkdvdsjqdd\n"
"6ninetwodmbjfour52\n"
"jdq2sheight\n"
"seven2foursixvhlmsjld\n"
"ndoneight361\n"
"poneightfourfourdhlnmlnpvnsixone77\n"
"6gnxprrthree9\n"
"ktbhqxmvcbczfspfddnjjcz7\n"
"4nineqsk5two5ksljzqmnrrhftqvmvhfqvxtg\n"
"cgllkmq1fivevlcxkmj4twohpclqj\n"
"fivebdkfgmlzckstbmone58fourc1\n"
"6sixninebkmlgpspthreesevenhfrhtfqnl85\n"
"27fivezqskxvqqp7\n"
"7vklrcvmq2nldrglnlkmdjgzone\n"
"4fivemzjhhvmm\n"
"76fournineeightthreesix\n"
"threen45nctdxmgd\n"
"eightfivetwotjbsvvrfourseven4djjfftk9\n"
"lrxjcgdxhtprfpvn9eightsix\n"
"foursix7lbjqxb1lzsztxcrhx\n"
"dlxftspksone9mfive\n"
"ninefiveeightone2\n"
"nzbvf3ninexsixsix\n"
"1eightjsqbvpcfsevenvdkhbxzfournine5pttjffj\n"
"6kxdmlhtslf2rzmbrdrvvqmtceightwojj\n"
"3fjxhq\n"
"j9\n"
"lj7onesevennine7threeeightvmgvtzcg\n"
"pmmrbq4\n"
"seven3fourq81l\n"
"2four4gqdpczpg\n"
"6sevengzdxmfpflfivefivevgnhspxchsfive\n"
"3c7gpgbnlfhlrthpmtsvpctjhzf5seven\n"
"kgtczfjdeight8hpcmkz\n"
"one5xkhnfvjh92ninevxkzvkg6\n"
"nzp2\n"
"eight226three5sevenhhxhqxns\n"
"9hgfj85zxvppflblvjlq\n"
"sixfour8hzlrbqjtjcgrxseight\n"
"6tlxtwo4258kbdtx\n"
"ninemhvrlcqvdthree5\n"
"8xfmjzp\n"
"nineldrbpxqmhffrjrcx11\n"
"mqvjnkjr6dx8\n"
"575cfbnine14\n"
"threeqnxnfjmttwo7\n"
"pvmxfgvhrlqn4fivefivesevensix1znt\n"
"sevenphcrjjhnfive63three\n"
"sixxdjplseven8seven8qlxfvgktf\n"
"hdgnr6sevenddzptcvprbhvnine\n"
"onebrhnsqbnzvmckmtmprjkbfvn6\n"
"hxqdjrmr94five9qnkl5\n"
"g3fourfive6\n"
"22eight6vsmtrxsix78\n"
"jrlrfsnine9\n"
"tqpkqdtknvfj2xgzrjpsvgphlbtthree\n"
"qvczktnrfvmgpznspqtsevensevenslmjdqfdld5rrcfour\n"
"rmgeight36sxvxzgnine7bs\n"
"sevenlt2fnqjtkvrj\n"
"seven9lhfzhmhdonelxvxfqdlxlscjbqgvnlbm7\n"
"3183six4seven4two\n"
"bpl12mcdpzrzbph9fourninercpqzrn\n"
"eightzltzdmcd4615nmone\n"
"5bgzh8hrrtjhnine62\n"
"ndnzpnptz6twokdvg563fiveqkszkccqc\n"
"6npdfqtwo\n"
"onetwomcxkncm3mjsrknhktgdfbqjmone\n"
"sixtpmdfmrjone6six\n"
"7fourthreekqvbhfourfivenine\n"
"98337\n"
"pvkrzdzbdj9\n"
"8krztxtqkqksixr264\n"
"5sppmxxkdonezfvbdcsix\n"
"dhvmctjcjfivec7pjmtnlqs\n"
"dgzl9sixggxstwoneprr\n"
"gnbmxn1cjnq3three6rpsrqmtwo\n"
"176seven17six\n"
"sbvfive3six\n"
"8seventhree64pcffive\n"
"fourgvhbrsfjzsevenfivenineninesixznq2\n"
"nine426six8zk\n"
"4sevenfpnmsqlhllrxrhjonesmgfhzmhvstwo3\n"
"fivesixtwosevenlfbpczfv3six8\n"
"8fourltcpdnhg178fourglz\n"
"rdfqcdrxdc6twotwo8fourthreeftrlzseven\n"
"97threefive7\n"
"sevenoneoneszdxd77two\n"
"g91q392four\n"
"2twodb\n"
"jbtfkfourggc5zkc3nineninekv\n"
"379eight\n"
"hhxcbflcv6fiveszpch46\n"
"threexfsfv3dpfourfiveone\n"
"fivevd145one629\n"
"31vdzxxkxsmznrqjzpqj5onescbck\n"
"9onejbnvrbmtgm\n"
"thrjvpckm4vglthree\n"
"zvhmxzsixfjddvjq1four8lktthree\n"
"74seven84rslpcjtpfourcvvqlstmqn\n"
"dfxdqr3eighthfhcldhgmjcpbxbzp\n"
"sevenbgs1seven9bjntphktdktzhrzpfcfs\n"
"7kqkdzncd4sevensevenfourv8two\n"
"mjeightwolsk2sgnhgxstfourhbhthreeonenine3\n"
"4nts\n"
"nslvxzffoureightfour5eightczsptpg8\n"
"bcckncblzdsixxrdprtsmbjdzxzlnzfbgmkfd2\n"
"8fourninesix4fourseven\n"
"twospxvtbcjfour3seven\n"
"four2cqkxkbplbpb\n"
"54fourtwo2xd\n"
"tljfive7bsxmonesixl\n"
"8mxd8czpdrgxbtwoeightrqpghngcvt\n"
"3sxrzljnzlr9threetknfcc5seven4\n"
"eighteightfourtwo8fournine7\n"
"jjzxf153mdzhh\n"
"3three95one8vsmzkrlvhq\n"
"ninefour4pzqzntwo2nine\n"
"onefournine8gvp\n"
"45vmbrpblzjxthhonesix8\n"
"lmmrxm5\n"
"13mhm6zxmkhbcsixhz8\n"
"mhsjcprhdh7ninemgrxnqzt7pdtxxvsix\n"
"twothreesixqcjtzcxmd3ninezqrvnzlxt\n"
"hreightwo51tb27fivesevenseven\n"
"fivebktq86nine5kd\n"
"one6nglzxzkzrmfl12nine6\n"
"2th9mms4six3\n"
"msix5bqbtwosix\n"
"four1hfrmxsix3five\n"
"nrtjrkkfour6fivefour7fivertjnxbbzg\n"
"jmjqmxrtjr23phttwo\n"
"79\n"
"6twones\n"
"sn6fivesixfourhhjhrfthree\n"
"xdfxgzccsvonefivenmqleightfivel9nine\n"
"78sevensix21\n"
"rkmncslfr6hdhtlchnznineoneeight4\n"
"seven1496\n"
"8fivekhfrfjtwo3eight9six4\n"
"jnrtwoneslxrgkeight67fivetwolbhvfftqjhl\n"
"eight6eight4two\n"
"dhcxc1\n"
"fivenpblbgfive6moneighttzj\n"
"onef5nppkqcl6mnzhvsixjvcqpbtb\n"
"7tjggz68four4six28\n"
"zfntm7\n"
"3sgbsbn2fivefour3\n"
"8bmtcgtqcsmdktzmj3\n"
"617\n"
"7sjsshfgnpnjskhccdclrxmnl\n"
"trzeightwo1krbkxd9nslndznine\n"
"ninelmbxldnb1qfqkhqkp\n"
"3pf8vlmgtfouronefx\n"
"five7seven6\n"
"zckdhnzrppb3kqsix\n"
"6fivebgf6fourktdsqdxfqd46\n"
"four7nine5two4dkkdhvcfsf\n"
"5vtqrhbn1lhxm7one\n"
"three13fbtqxvmninegp\n"
"fiveseven1czvlmlncthreerstssbjdoneightpm\n"
"2lpdnfz3vghpszmtxnineeighthkfour\n"
"455hdvfivervnine\n"
"three64\n"
"six6threefivethreedbvvftm\n"
"667sevenzjxmrmpxd8\n"
"dsix62lrvqkfthree\n"
"sixthreefour5cpgsjznfdbtk\n"
"two4five4one\n"
"1hxbnvq\n"
"sevenkrzfvkkrprxzcfgchscbstwo73\n"
"nzhtgzzq448pftthpsneight\n"
"3197\n"
"one59fjdqjd9\n"
"pvcphzxnvnhhngl5dsix6fourone\n"
"5eightfourfivetbhh54eighthkbvcfrpc\n"
"threehvdqjdl45fourrqhqxs\n"
"8twonine\n"
"8mmc6tmc99rkttglnnxk4\n"
"pxnxckqbdhhvhbheightfivefivesix6two\n"
"3four2pzx23vhmzhrfourthree\n"
"five1four97\n"
"9eightpzznbpqgj\n"
"rrrgfxlb7vltwobjtdrghc\n"
"sgnd8ptgdfourbbcqsix\n"
"4chfmgsxnsd96\n"
"zthree3\n"
"zvvstf6twofivelftpmzkttwo3\n"
"1nineoneightxqt\n"
"2kzhkfoneeighteightqn\n"
"287cfour\n"
"lhmgblplseventhreenine9vcpnpvzhjronenhczffqt\n"
"5xrjqdjtdqnvlnrkkr7\n"
"38dbdthfive\n"
"onethktvdnfqgfourlxpksevenseven22nine\n"
"mjmt18blbfiverjsxjsktkgz\n"
"8hlrjjbvsix92grtmthree4\n"
"7threetxjztxseven\n"
"five5gfgfdjbkrpseven4\n"
"8jdzlvrgtcf8eightzpgstwo\n"
"bfpqdpfoursevennvgqt8\n"
"8one99\n"
"kfvmblbtthjrrmktmjmeight4d3lnctfzsvgmjtmd\n"
"2eightgppxscjvdgrzjgc3\n"
"5twonineknzone\n"
"onefourhb4\n"
"eightrxchxccxb7qqqqxzt\n"
"threeone14pvfive\n"
"nineseven1sixknvkmfkk86\n"
"onesmvscnf9ninezgfrps\n"
"ffhseven2\n"
"1sixrjseven8\n"
"rvzthzdtwosix6kzzqssrgc9tl\n"
"threeeight5svcrlrqtkmfpgqzhhs6\n"
"eight3bt7dp\n"
"zqhncxh25eight1\n"
"five3vmmmntnjtjrkbvpvphj6nine\n"
"eight6fsdqseventxgjkbvrleightfive2pqx\n"
"nkfbsdgrrfvsmfxx78onetwo\n"
"bsix5eightwox\n"
"fph3jzfmt9fiventnpvnxhjxplchjnvlxqkdbzv\n"
"kfxbjzcfpfk8chkrtvlrnine6\n"
"m7kfjz52eight4tworkpcqt\n"
"vmlhvdpxds8two\n"
"fourfiveoneeight478\n"
"3eightonefive\n"
"ninel5\n"
"lfqllfjcqztwofjnfnfx5\n"
"5tvqksfour\n"
"twogdg5fourmhninecrdcrheight4\n"
"two5six2\n"
"419vrvjln7\n"
"pbpmljqjzxghp3tkdeight7\n"
"sevensixfiveqmvtfggbqjone72fn\n"
"7four93cdgcpxpl86\n"
"9oneeight6three\n"
"threesixsixhzhpfive8ninetwothree\n"
"xlzddrthree2rmtwo6fivedhxsrrdcvpvgscnt\n"
"qfncszfsdgzqctdtbpkseven1fourpcmz5\n"
"7seven9fivefive\n"
"82nine7ztqmftkssm34j\n"
"twofoursv6\n"
"five2five51qrsrqrtmdk7\n"
"four7fhhjxcjtbr\n"
"hnbdbkmjc72\n"
"sxclpbzmbd4fivezjjnncmqpv6ckxzb2\n"
"98six4pkhfzkzj7\n"
"611thqkzttfffivenine7seven7\n"
"8sevensmqzxxlgpxpjqstsgkmxdgplrplsjxjgsmjdzzgf\n"
"rggphsjncpxkfzfplcgrnfgmnd9\n"
"three9sgfhdn3rbvqds3threeseven\n"
"nine9sixtthree94rs\n"
"sixthreebvmxtcqng67one\n"
"6ntrhzzkl8djptbnsixthreefourhnk\n"
"3sixxsj5five\n"
"1cghzppdcfnine\n"
"jtmkrvlmhthree58eightqbhlgppghc1\n"
"fivefourlpk5jtvrk9eight7gfzksqrv\n"
"tjrphpkhfgsix7eightwocj\n"
"threethree85ghjsnhgrv2jv\n"
"six64\n"
"3ptfzxjrtfsix\n"
"1583xpczlkvtwo\n"
"twoglkpldjthree717\n"
"six26three\n"
"three5qc1gz\n"
"9tworgcbxfourrxgxzzbljcb5mxn\n"
"838\n"
"four6zjdfd22kxpfhhgonefour7\n"
"seven132\n"
"zmml5\n"
"twozzzgrhseven5\n"
"four8eight4fivefour\n"
"g76nine4oneseven6eightwol\n"
"9kzlggh1ninefoursevenninelb2\n"
"three27kfmbdtpxncgpskvrq2\n"
"onegsnxggjlvn1six\n"
"8fivevgtszhfl2zqsqpnmgdbkfour\n"
"4fourtwo\n"
"mrllxmbfpqvpfzhghv8twotwo\n"
"3hjxpgkxpc91t3\n"
"four24\n"
"six385hsxtfone\n"
"8three9twotnpjkcdbrfive8\n"
"nine94tpfcmnzsjk\n"
"sevensevennbch64six\n"
"onefour99gcgvcfvfnzjtjzngc\n"
"fivefivedqdt4\n"
"onefrnpc4onejgvtwo7six\n"
"4568\n"
"tfrmonerljgxsbghm87hmgzfvlcmgbsbqc43\n"
"4kbxt9pqchtltg6sixjkzncffrpsixtzdtbdg\n"
"29pbpph\n"
"2szjrkkqvsix\n"
"six2twotwo1cfqzhjrlkbone4two\n"
"mdxmcknnmmnfzsbvh4\n"
"rzjnjrqjkmzmr4seight1two6\n"
"onehpqvvlsnkhcqhczbllbcfl3six\n"
"nine655nine81\n"
"two76threefourtwo54\n"
"8nine91\n"
"4threebspdskrp3\n"
"pktwonesx4sevensixfournine7\n"
"td2one4seven\n"
"eightseveneightfivetwothmngvb9one\n"
"9pkdcbgfhrf8mjtjksvjlf2\n"
"374four9two2seven6\n"
"98eight2\n"
"brmzpfgjone3\n"
"six4mdbthreezdgrktcdc5\n"
"mfmvcqdjlvzmeight8\n"
"smklgfour2\n"
"j3nineeight\n"
"fh45peight9nine6\n"
"two972fvkfzsfivefbgkktg\n"
"three9kdzkeightqmxcslnvhthree\n"
"ninekgjkdtcsrqgrmdtshsevenseven3four\n"
"2nineninetwomlt\n"
"jckvcvtwo7\n"
"348\n"
"cjzzxsix1hfqxxgdvphppxzvmqsv1xxxsqckhpbsix\n"
"jcnlxlccrtpmqqmfour8dzrn8lrzq\n"
"7sevenzrcgtldkjbhjt\n"
"three55gtrnineztxsdcdcdb2\n"
"sjnvr5\n"
"gvpcd4one2four2foursix8\n"
"mxskkrvdjkvpnine6834hsxsn2\n"
"one5fivesix\n"
"bfhbgfdkdftjtnhvgbr2zvmcmrpjs\n"
"threeeightmbjc5six\n"
"8zcxflfkbtdtwotwo44six4cnrvvft\n"
"sevenzggv2mkjsl\n"
"sevenvx8one55zhkjcxbpdz\n"
"zbxbftwo79leightsix2lgcmlpbpjz\n"
"one6twoqrfoursixtwofive\n"
"111threethreetwonehf\n"
"72fninesseven\n"
"gsrshxjfhr54jmsgnnninecvqdjtsevenfour\n"
"m49z51\n"
"2one27two\n"
"four9rlhsbfour\n"
"eight8sevenoneightjtj\n"
"pgv57nineeightxnblzsixxgjttbnzrqscb\n"
"3sevennine35gfbqvq8seven\n"
"fivesix252one1nsix\n"
"3qzvttqnmjb4pshrrdzpm\n"
"nvmlzzxfksevenlvngntztwotwo9mhjrjrxnckchs\n"
"seventwomzk699\n"
"33svrghbnine8seven\n"
"six48fourtwoeightphl\n"
"7fivekcrsvzdvsix\n"
"8sixjtdrl446btjlmfzqlg\n"
"g6sixjlsspqkthree\n"
"z2\n"
"sevenonec6xhddnxjzrn\n"
"one1bczmjxrnineonevjkbnine\n"
"eightttltnkcllm8snhbqptsztzkdffkcdbsixcncvr7\n"
"mnprx46jdttjtxrkhrninefvvphzthreethree\n"
"3bjrvbmlpv6threefivehrkcv\n"
"8hjkrlmg\n"
"lfrzztvtwomkgrtzvseven7\n"
"fcx2two\n"
"27hhbgl3x\n"
"mtveightwo3tcseventwox\n"
"nine8four1five4\n"
"six56qqvvtwo\n"
"fivelhhcjhpfnsvtzmnxdlp3fivefour\n"
"fourtsbq3six2\n"
"71vcmtqgfpdkx2\n"
"fourfiveninetwo5\n"
"qsfhrhkm4nvxdxzcnkcknvxjg2two\n"
"915dftd69foureight\n"
"qrhjdprpcbq3eight552kb5\n"
"rsone7nckeight\n"
"3ninecmsvkmlk8b\n"
"fourfrdgbrdzsfvjg2fthpptfjgzjsnvsxcxgxgcgdcl\n"
"sevenkpshht4threemthmfbdp7\n"
"sltzgqcqlvdbccvcbkzmmpsl957\n"
"75t3\n"
"4sevenkfourpxfkgkdpjccxpxrgsbmsrnxngd\n"
"2oneeight4mpndtnnone4onesix\n"
"six35sixfourfive2\n"
"81twokrqg\n"
"3dqcrlnzsnmhmzzxnsjsskchxqzvtfrdnkqg\n"
"17zzrcpnmshreight\n"
"gcvvczmldgh8mnsnpmjvdrpznine\n"
"oneeightjhmf9\n"
"1hlfour3three9\n"
"skjc82gthree6\n"
"eight9bszxphftdsixsixonesix\n"
"five9xbfgzfh\n"
"6nineone\n"
"tgnqfiveeight8qnlj\n"
"28fxrpdmdjgdnine6rpjdxgd58\n"
"gsxfivefourhgznkdhrtkn7nkt59\n"
"6m2eightbzndjnfthree2fjkpsm\n"
"9nine7one7rgsh\n"
"xnrqcllskcrlxglbshvrseven3nvjlcngxnine\n"
"sevenpltgmq9csxz1four\n"
"7threevbhfgnshtn5nine\n"
"gdj9\n"
"five6two931txb8\n"
"fourtwoone2hcbzlggvfive\n"
"7xlpjkrvbtq8qlgrqonetwo4bpxtcgjxv\n"
"nnxhcrgplrtrskbjzdd8lfive2six12\n"
"bqjdtwo98z\n"
"6ninerfqlbxpx\n"
"8seven642six\n"
"eight54\n"
"5two9eighteight7hzkfdzg\n"
"twofourninekhcztkhfour23xllcdb\n"
"zmpdb7jffqt7nhnmdrqqvtwo2krltbfjjdd\n"
"sixfourlxxshzfccgtzkdhjeightfourninehmrhqzfqld7\n"
"mblx1ninekfjhfnjtt4nine\n"
"seven7mhmkpqk\n"
"4rvzsftqscltzzj551\n"
"8gkvgs5oneninethree3three\n"
"5ldfllvzkhkfive8\n"
"jjblh64five1gzvvgcbrhbvrqfhjqvkrqvff\n"
"fourpqnpgjnclq7nine\n"
"eight4761\n"
"nddmqzx2four\n"
"8nkgjkkhqztwoeight\n"
"hlqtbfrgsfbgnine5qdfzrsnmb77\n"
"nineggdbpmhbmdnrfvpv5threefour3\n"
"jm4\n"
"sixfkxfzvrkxv9seventwo8one\n"
"threesix2oneoneightc\n"
"7three3615qqdbzsxrdv2\n"
"74fourdvgcgdgvxqgm4eightqqtmvone\n"
"5h58dmvkxbhtninefoureight\n"
"8fiveoneseven7\n"
"eight145zxgnzczcdkzrffnbfmsztwo\n"
"268nine3\n"
"6eight3nine86six\n"
"4qhtjbcd9\n"
"mblblmkhseven3tgdxslcnine\n"
"fivefivelgghthree5vkkfhjkc\n"
"4four5oneseventwosixfivetwo\n"
"6ninenine8\n"
"7ldg64five9twoninenine\n"
"3zmzlnninesrfourfivetzxlkcsr8\n"
"sgdzmk3lgxjrktsmzkczft\n"
"64nqhjdjs\n"
"9sznchv2nineclrfdpxnf378xhkjbbplqdeightwos\n"
"3sskrbzrpfqbbqtjzgcqjhnine3six5\n"
"vq95nine7lfiveonethree\n"
"3eight3eightfive4\n"
"twoninethreel7sixfour9\n"
"bszxlfz2mtmv\n"
"1cvhpxjlgjd\n"
"sixsevenksj77one\n"
"qglgjsh3zrsqqh9onehrkjxfsxt3nine\n"
"sevenlllqqkk4bxcgjqqllmcml4b3\n"
"bppqgfdfpm7753\n"
"68frjqbqmmq2fourncksn9\n"
"bdz42pjmmnmhkvd\n"
"6threetone2\n"
"8bmmdxf1dbnggxgpvhninezxmlzhvzb\n"
"48168\n"
"gvgkcsvmoneqvlxgzjsixfourshxzls9three\n"
"1zrgnghhm\n"
"klkrldxbjone6eight6sbglhrhlbnbq9dbkl\n"
"9threefivetplxdklc2zrnptzrzp2\n"
"sndxcznj9ninexttpfzbjcmbslghm83rp\n"
"73one8one\n"
"3eight8eighttlmpmh9five7\n"
"7vqcddvrgbm5foursix\n"
"fivedhzbdsnzd1sv\n"
"82fgntsxnsix3xdzk\n"
"threesix3qblcvkp\n"
"lfptgxqs2six35\n"
"eight33jtzdbstcmstjxtbseven8\n"
"seven4five958three9\n"
"3sevenhpvklhxxvx\n"
"rzsb5eighttwoglqtmf4\n"
"seven8fgkp\n"
"3rjfvpfiveonesfgdbb5\n"
"vpkkcrpdthree9threeninesix\n"
"3onethreenine7\n"
"9sixtwoninetqllkjtmjnine4\n"
"2lqsevenx1vsgbmgone\n"
"eight2kqsixfzcxvxfourp\n"
"gchhhrbxqlfphdjjdfsix4rcpmj\n"
"4pfrxtgr21\n"
"7fvndztkj\n"
"rtwonenine77lsglrqcxhgxrllftvqfvfive44one\n"
"two374343nine\n"
"eightseven7fthree\n"
"6lrrphgpnrlvgfqqzxfdxttdbfdfgjpmtztc9\n"
"61threegscxrcstkclln9\n"
"xk2dhkgbtggeightthree\n"
"5vbbrqfnfp49eightqvn71qpskg\n"
"sevenhgd9qxfn8twoeightsevengcqtt\n"
"1four17five\n"
"5seven5vnsbqpkjzeight7five\n"
"62qgxndqlninetmftkhp9\n"
"two8threeeightdpzzhhvmr8\n"
"kxgmtlzb7gcltm9cxp\n"
"8454nine\n"
"mtqqxgkvfdthree9rpbvl5sfourthreesix\n"
"7onenine\n"
"4fourthree\n"
"8fvr\n"
"1fourfhljbffive\n"
"lqltrsvkjsthjkxph3vrfive3vxvlf\n"
"xxfoursevenzbthcsdnrvjlnqqhlpbbpj8\n"
"6gvch2fiveeightsixmtfps\n"
"two7rljfhhdlcseventhree9four84\n"
"5lpseven\n"
"cdmnine1\n"
"oneeight97mxnine79\n"
"3thzbhxbcbf\n"
"two41fivefiveseventwo4r\n"
"shlz9\n"
"xxpgkqf9joneoneseven6\n"
"lpqvvzdbx27\n"
"gh1five\n"
"thzrmh2lpncngjrqrkmthlndl2six3\n"
"vrrhfour55\n"
"665qzpzlhfvrbsgblcvgzbqqkxbdtzctwonerx\n"
"five44\n"
"kpvqnxnlfouronerp5417j\n"
"4vxppbsfive235gqchjfhjsdgq\n"
"sixnine2lk8npzdbgcxvrd\n"
"3six6eightseventwo71pff\n"
"zbr1srxljjseven5ckjfour\n"
"one71z3threenvmtcd\n"
"six9zdchbfsdtbs\n"
"2qhqnrcmrninedqfivejseven8\n"
"zrhctxclslhlj24jhhseveneight1\n"
"knkvthzrbtxbbnnpsfbq1ninefivesix\n"
"vhr28rlrtpjbnn7\n"
"xcsjqrptg7one\n"
"gzdjq2fourpqmzjs5sixtc\n"
"threedzbjqd3568\n"
"threesixgcjx3onefourdskrfhldjhm\n"
"sixphnfkdtfxnvphxh3\n"
"rxldfbssevenfivemxtdbnvgpq6xxmbkdkxkjmth\n"
"five7five3four2qkrfmt\n"
"4fivefour\n"
"fivenine35tzhpqfkq31\n"
"9two2fourtwo8nlgzgbbp8\n"
"1threeoneqglrlnmcblpfhgcfhggm\n"
"7onerknmhpmonejzfqjng\n"
"nine81twoshgxqt\n"
"28dqfptxseven37jtqrklrqc\n"
"41two3\n"
"7gp\n"
"sixdzjfsv2sixeighteight\n"
"9three6\n"
"3fiveseven83tvtxf\n"
"ndtwone562kzfhdrhgcjv4two\n"
"jzvtjvnineeight42keightclbtddmdffsdttc\n"
"eight41mggmrzlkhsevenfoursix4two\n"
"rkllqvfjz13sixthreetdztlhlcldoneightj\n"
"7three4fbccblfvninelhvlthgh\n"
"btwone96two1onexconeonefour\n"
"jcvxrvkdsb6five\n"
"578947five\n"
"1819p\n"
"lgvxmnjkgmlkhkzrone6gnbgkxrlpspj2six\n"
"ntzsdxn8\n"
"mplcrhcz8\n"
"czggpkxcfthreefourjpcxnine4pvfqxcvh38\n"
"9dsfhtnrjv16\n"
"2ceighteight4ptzneight\n"
"2two8jvsgrtrht7lhxkdztqdhvcsdm\n"
"619six\n"
"cqmqkhpxjtwofm9one1one48\n"
"2nqbksgxxfoureightfiveeightbbvg\n"
"five5nineskphfdgxbp67\n"
"gsevenqgcsk9ninehlccsxn\n"
"pnqcdjknth94three4sevenninefivegl\n"
"eight9mnsb6\n"
"fzsfcbbvvqnksj85fbfour2cn\n"
"1kjzphbpp3spnbzhzeighthdnrdq\n"
"4nsglzjbk1\n"
"threetwoninethree2ninehm\n"
"35oneljcsixlmdxpxk1\n"
"jsix2\n"
"tgkfk8ninestnk2eightoneeightwotcs\n"
"chhflbq1xznbmj4oneightkc\n"
"3eighteightfivenine\n"
"six592bzj\n"
"xnqnxkpseventhreettv8jkds\n"
"honeighttpqxdbhsevengvzfourd4s5\n"
"sixeight8\n"
"pcflsgrvslxgmtqm6oneeight69zhlpddq\n"
"nqgeightthreelzcppk2vzdjrjqqx41\n"
"dqdcmtzbqeightfoureightthree7four3\n"
"ninesixhxrncgtwofivetwo5eightrvq\n"
"kzxgsfive644lthreefive\n"
"nine2one14four7\n"
"59gjc8fivetvjcjcq\n"
"lczn92c\n"
"3seven9tprznnsmznineqbpchxlnbqkssgqx1\n"
"3m22nine7\n"
"3mhzbqtscqrkjzjqtklxdn1\n"
"61pnjkfournine5\n"
"41one\n"
"99twonzsjsqk7fivedjlcgzjrfive\n"
"twoninexngksevenfive7xxrxpvq\n"
"1mfnggsgvqmplg5mrqmzsclpmeight\n"
"2ddgfivehxddfxbdfsseveneight\n"
"4nine579three13\n"
"fiveonethree44one\n"
"11four\n"
"cgqrbzdl6mnmvh6\n"
"qmzeightwosevenflbh72nine2\n"
"six59one9two1cvzslmdch4\n"
"fivesixtwo8\n"
"sixxvczqbbvctgmsjnffmfourfbr56\n"
"6seven5hndfourfcnone5\n"
"qdnjmcxtfgpk6eight\n"
"three24two7threetwoprztmh\n"
"foursevencfzcdzksevengh6nsnine3\n"
"sixseven4lmqshqzmk\n"
"xhrjx9eight\n"
"twodmcxbsn924\n"
"2zmcjlhqj4sevensjlnjjx4\n"
"pctwolxqvjsjdlfx8eighteightsevenhq\n"
"sgzzd5five87threershbhmqlbm9eightwoq\n"
"tlzmzt6jg7fiveeightgc\n"
"svlthlbrfive2fourdbfp9trvbjthvvthreetwo\n"
"nlqnmffxlsblnncqgcgsnkt7fjhfksvfxeight\n"
"hljgks3hfour5lzzpzpjpgdhzflrnqpfzjsfc\n"
"9eightfive\n"
"eightsb215qkphjjdrlg3\n"
"four7three\n"
"nine2eightrqh21\n"
"tnine8txbm121three\n"
"two1h495skpvbzsixnine\n"
"73five61pzlscqn2nine\n"
"threeeight3ffnjgk2mprkn9ninebqlvkl\n"
"58four\n"
"4pzb35twotldtcq363\n"
"jnzdhlzx4fvsjsffsxn45seventhree2\n"
"nsfrqntjhpq4qstwotwoonehs\n"
"fiveonethree5rnmlz\n"
"seven18jjcdcg\n"
"threesevenqqbrkbpzeightninethreefive1three\n"
"eight98\n"
"eightonetzggcjvpml2twoxlznrn\n"
"4dmndcrsc\n"
"9oneseventb\n"
"5pkf8zzmvfive6\n"
"rdlnxcx3nineqjpldqtwodkctfnn\n"
"8mpmgzgshszbcnrpzcszltd\n"
"2jvkc3\n"
"rc6clvgbz6bbtlzeight5\n"
"frnhbsgzpfeightqkt2ninethreetcnklsctc\n"
"threefivevgzhh2\n"
"tjoneightone9three9dkbnh\n"
"hv7hpx\n"
"7onetwozrl7fbxhqgrbtoneightpzv\n"
"3mtdnphsvtrrfeight9sevenfivethreedjcdxg\n"
"pqjcfjsix4tsxcthzbqzhklqncvb\n"
"fgrzvnnk3cfrxp6tsb1\n"
"czfdsjffqqrcgffx7seven\n"
"56jdtwo\n"
"sixxvjjmpcttwo7ninechbzv\n"
"8qckktnslsvrmpctknine91\n"
"4two9fivefshxvdfbdr\n"
"7sixtwo4rjspztpx\n"
"8onethreestjxv\n"
"3lvhvlnthreeonetwo323\n"
"hxjcbtrtcdgvg22ztn6xxnsdbffour\n"
"twolzone34crrcpcdb4\n"
"fourjhghcseven9gtmxrpbpxthreehkpfour5\n"
"qdrxfdlqtf4342threemlpb4d\n"
"nine6nfnrgd52jnqfourbzkgbxlvlmr\n"
"sevensixonem5two4\n"
"64one1nmxbmsq\n"
"fiveftmrkpmjthreekvsfqjchvf9two\n"
"ninepffbfjhjtg4grnzztqnfiveseven\n"
"1gkvsgsrrxvdfdtsrlgfthreedsrprjft3\n"
"foursixsevenninepxllctr4khsfxfvnine\n"
"onebfpbqmpmm6\n"
"cgkblkxtr2thqsixsixthree\n"
"qqfkvsntgf687\n"
"fournine2twotlvqhlrtbmckqlljhssevenghhttkvf2\n"
"ninenrvhhleightkxbzcmx2sevenvzsncp\n"
"eight766sixoneseven\n"
"8eight61gsxklbp\n"
"2ptzkzxsnsix9one\n"
"six9vfourseven5brmclpeight\n"
"821\n"
"one6hcsxp5njsthreesevenfive\n"
"pcf2\n"
"eightgxsjc456\n"
"threeseven57htjtqxbbdh\n"
"6twomsbq\n"
"gzknkt1twopccfh\n"
"7vpzmnt\n"
"8fiveqfzgbnxgnh\n"
"onepvtddfzn2three\n"
"5ninesix85\n"
"onejkgppztbmrbfqqrjzp24one\n"
"k3six817dvvjgqlnkd\n"
"zzvkseven9sixqxr4\n"
"lpgdnglg3threemtltwo\n"
"three9qfour8rxlzjllnskeight2t\n"
"sfxgmjzqs2cbqtwo5\n"
"one36\n"
"2tdknkgfhpj1nine9rtsjrjdlsix\n"
"59jvsoneninethree\n"
"fzjvgpsqrsninenlpxzbone6\n"
"fourkllsixbfive6fourone4\n"
"seven52zchsttccn3three7\n"
"6ncvnflrdqbfourx64nine\n"
"2vrhdchccppdseven4qkdghrjrxbdlfplc6\n"
"5cbdfvxxtwoone38dmjngzqlf\n"
"fsqgt6jqdqdj7cfdzrfd\n"
"9zqfiveznnmghtrtwozqbeight\n"
"twoninexmxnpbvtkn1tjzdsxjvbd\n"
"6fournine\n"
"15twotwo35kbbpcxbsmb9five\n"
"1two29dppbcqkxgq\n"
"six7sixpqqmdjlcgzrrnvkqfqmllqlbmfnvlnzjcs8\n"
"jhtgltv2qzhnkm2three8nine\n"
"mrttwonetjrt2eightoneqqgvllgpqqbpd\n"
"hhtnb72\n"
"sdzhtjmnkdtpfsfnsnk7rtwo\n"
"3sixsrqsjsts643five\n"
"338twomnqtwo4cl2\n"
"hgggrn2kvgkvrhngxx2xzmqsdpzbsxfqhg\n"
"hctwonefivenine4tnsixsfxlvppm17fvq\n"
"six3blppkhpjtr\n"
"trrxmdnhzsix47\n"
"5vsrhlvqpttwojczmeight\n"
"rzgrzbkk87nine\n"
"trgfsq1ninefour\n"
"lxbvlbpjz4eightsix\n"
"6zmmvchcgjqsrthkgc92\n"
"9thfthreemxlbt\n"
"eightpkhgpcnc8eightfive1hdtcjjdcsevennpz\n"
"fivepprkhhtg9cdfqhsqfivejsrxzvknndnvq\n"
"qfvjvgeight2vbpjnftcttwonegn\n"
"twolnln7pnlsxthfjpfivenine\n"
"hlseightwoone6qvcrsrttg1three7six\n"
"8xcsllfrlx6one7eight\n"
"fiveshnmbngmrnineqjjlvdrfnsmpdnine4c\n"
"three2rcfcrgmrvsjzcflqkb6487four\n"
"threelnbxcrhglnine534\n"
"5flztcjjeight7sevenfb\n"
"qgbplxgtdkrqqsvjntwothreens48eight\n"
"five34rbbxpnkftntrt\n"
"nmjtwonek4\n"
"cdnxnppnvthreexcsmbmcslh8ninefive1\n"
"6lttndjpcchdpgkfmmf\n"
"oneeight88\n"
"three4xctmtvvcp3sstxzfmgnine\n"
"6fivefivevnpnpknljlfp6lone3\n"
"one486twojknbmsqthree8\n"
"fkxfourfourlpslcbbtk29\n"
"6seveneight19four\n"
"fvcseven8hzlrgpmgfj136\n"
"sixfour9tn1tfmzkdjxxj\n"
"ffvmfqmsnineeight5\n"
"ninestmzctrthreesixqdbbvtkjfxpjpgzvpthree7zsfmsvsgxn\n"
"rz2eight6655\n"
"vhzqvbxr6eightninetwoeight66\n"
"2fiveeight7seven2\n"
"5six6vkvdbjnhbdht5rqhkfour\n"
"eightrntwocdchshssevenone2dxhmccpn\n"
"three4gsgleightxvgjpvqshlfzntwo43\n"
"9four5onebqlcmrrkvnine45\n"
"mtkkbxbfour5onemnxcglq\n"
"one18482sevenpkgxmfour\n"
"two3threexggpjbncmkvmd1\n"
"oneseven9\n"
"679b\n"
"7vc9threenine3\n"
"one35x\n"
"4eightthree9\n"
"1hclxskfgjfhvjtgqsztp\n"
"eight38d84fm\n"
"fiveone6five1five\n"
"qjpptvfsrs614fourssdrxtpqfz7\n"
"9qnrkp\n"
"six4one1zxhllkcd\n"
"six1fourtwormz7vxfbhmg\n"
"one3jxcjzz9\n"
"vzmtgdhpjneight83fivepcd\n"
"onexqhvqpvmncljmssix4twoseven\n"
"threeninenine2hg\n"
"bvjvgtdhjstsevengtbnqf4seven8two\n"
"twooneone5lrjpptxzd\n"
"hzlb1\n"
"nhrbfltwosix22rdjthctone\n"
"seven7eightthreepgj\n"
"fourfive45\n"
"nztwohnx3nine\n"
"fourhfxgmkcgbppdjkqpx2ninezdkbncsevengbdxb\n"
"sbzdcpxnine3nine\n"
"8grdrone78\n"
"1eightjldlllrxl2\n"
"588onethreesixlpdkxfc\n"
"vvvjrnzbfxgzxqlxx6vcqkkftxkdttnhpzrvtwo\n"
"3llpjrhrone5ninemdqjnpllprkphk\n"
"44pmxlrhsdsvsfxtg6\n"
"nine841jvpl\n"
"eightbpsqrkzhqbhjlrxmzsixvvmgtrseventwo7oneightjbx\n"
"znhjtgjk1three8\n"
"5xcsvvvzrqcxkqj346oneprztsfpdld6\n"
"67six1four1kqj\n"
"qvqlmqtzcj5\n"
"ninejrrhddqfivenine7psghccdhvfive\n"
"pznvtxdklpvqbsevenfiveninehzjfvrdxz8\n"
"eight46xpfdcqbmprchftkpfive\n"
"bkdvhbhlmn1\n"
"99sixv\n"
"gdoneight26pzghbjfeightttfbvhltwo8\n"
"three5nhd\n"
"three5nine\n"
"four9csdvvfdbkseven26peight\n"
"sevennszdbkkfdndjtzzpjmtqbxlkv43vxlnnrn\n"
"4fourpxzkmfksix39\n"
"9hz8crczlbbhkrsjblzd1q9jsbf\n"
"443twofour88one\n"
"2tpmlxltgsix\n"
"83835six\n"
"8twojvsgjtqvxgsevennjdvdbqccmgcldp\n"
"fivebpknnpxnjmpxntbhkjsp4fivefour\n"
"hvxnseven6two64five2six\n"
"5twoonefive\n"
"jzkd6hvcmfqsjztsixfivexlfrvn\n"
"xfbcskone12jvvbflfn\n"
"ninellrbqhshsxeight7two\n"
"4nine79jdkfkgvcr1\n"
"eight8twoltnpxckbqxnfbxtthree49\n"
"ctkfveight8\n"
"nine671seventwotwonejkf\n"
"5threesix\n"
"4sixsixzfmtzlspfcseven\n"
"4pqnrmqlscq1fkzxngndmgseven2\n"
"27four7znrkvxhvt6\n"
"lqkljjh79six7seven\n"
"2tlb84sixfour\n"
"onesevenseven5htsdxvfctkdgvqtwoeight3\n"
"66836qblqgdhnine\n"
"75ntphbdbpgktwo\n"
"jheightwovtone8fourtcsbhhntkq3nine1nine\n"
"5gcnnbjcgqn7\n"
"1nnxkfdmxhsqqttsfsgtwo5three\n"
"7sixtwoeight\n"
"9lsjcmcvqlconezxvrrptxlxleightlvghvxjgfive\n"
"one6xxf1bjjnkfeightwozv\n"
"4rqxnflktwo\n"
"5three1\n"
"vxqmbgjnr6one\n"
"eightfour538\n"
"gvjt1onetsevenonesixfive8\n"
"fourgtwopbjbcvgtwo3one\n"
"68four4htvj8bk\n"
"nmftgklbpj9onevbzzeightncszqgpl\n"
"154fnthzxccjxsztjzpvzcn4\n"
"three6fivefoursixgtzfzbkhmnplfm\n"
"63eightsixgdsdqqxzzsbnkt782\n"
"twovbntmfffivengfbkhzgm4\n"
"23sd6nnspq\n"
"nineeighttworhtvxdtxp8twoneh\n"
"four3threeonehbfhttgn39sqpctngqmzkhttn\n"
"rphtbkncs4nznsix\n"
"6three2sixsix9eightfour\n"
;

bool toUnsigned(const std::string& s, unsigned long& res) {
    try {
        if (!std::accumulate(std::next(s.cbegin()), s.cend(), true, [](bool acc, const char ch) {
                return acc & std::isdigit(ch); // avoid '-' in order to allow '-0'.
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

} // namespace

auto day01Part1(std::string_view streamSource, bool sourceIsFilePath)
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
    std::string line;
    unsigned lineCount{0U};
    unsigned lineCountOneDigit{0U};
    unsigned lineCountZero{0U};
    unsigned lineCountLeadingZero{0U};
    while ((*inputStream) >> line) { // suppose no space in each line
        ++lineCount;
        std::string errorLine
            = "Input error at the line n. " + std::to_string(lineCount) + " : ";

        const std::string::iterator posFirst = std::find_if(
            line.begin(), line.end(), [](const char ch) { return std::isdigit(ch); });
        if (posFirst == line.end()) {
            throw std::invalid_argument(errorLine + "no digit!");
        }
        const std::string::reverse_iterator posLast = std::find_if(
            line.rbegin(), line.rend(), [](const char ch) { return std::isdigit(ch); });

        if (&*posFirst == &*posLast) {
            ++lineCountOneDigit;
        }

        const std::array<char, 3> s{*posFirst, *posLast, '\0'};

        unsigned long v{};
        if (!toUnsigned(s.data(), v)) {
            throw std::invalid_argument(
                errorLine + "unable to extract non-negative value from '"
                + std::string(s.data()) + "' !");
        }
        sum += v;

        if (v == 0U) {
            ++lineCountZero;
        } else if (s[0] == '0') {
            ++lineCountLeadingZero;
        }
    }

    std::cout << "Number of lines: " << lineCount << std::endl;
    std::cout << "N. of lines with one digit only: " << lineCountOneDigit << std::endl;
    std::cout << "N. of lines with value zero: " << lineCountZero << std::endl;
    std::cout << "N. of lines with leading zero: " << lineCountLeadingZero << std::endl;
    std::cout << "\nResult: " << sum << std::endl;

    return sum;
}

int main()
{
    try {
        day01Part1(Input, false);
        // day01Part1("./01_input_file.txt",true);
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
Number of lines: 7
N. of lines with one digit only: 1
N. of lines with value zero: 0
N. of lines with leading zero: 0
Result: 142

Real input:
Number of lines: 1000
N. of lines with one digit only: 340
N. of lines with value zero: 0
N. of lines with leading zero: 0
Result: 55538
*/
