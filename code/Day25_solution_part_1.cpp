#include <algorithm>
#include <array>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace {

constexpr size_t ExpectedCutSize = 3U;

constexpr std::string_view Input =
false ?

"jqt: rhn xhk nvd\n"
"rsh: frs pzl lsr\n"
"xhk: hfx\n"
"cmg: qnr nvd lhk bvb\n"
"rhn: xhk bvb hfx\n"
"bvb: xhk hfx\n"
"pzl: lsr hfx nvd\n"
"qnr: nvd\n"
"ntq: jqt hfx bvb xhk\n"
"nvd: lhk\n"
"lsr: lhk\n"
"rzs: qnr cmg lsr rsh\n"
"frs: qnr lhk lsr\n"

:

"llq: tzg\n"
"dns: dkp\n"
"fzx: hsc\n"
"qvt: dqr mzz spl\n"
"gvq: nql mmh ngb\n"
"nvc: gkt rhz\n"
"dvq: zqg lpt fdm btx\n"
"ghj: nnd\n"
"znm: ggz fqd ptj ztp\n"
"llg: pqx vbf szn zcr\n"
"nsm: cch fgv\n"
"fbq: dbv tts ltb\n"
"kbc: nhr jjj\n"
"vdf: vct\n"
"fcq: fnv tgd ltb hjv drn mss phg\n"
"fqj: gjh\n"
"xhj: rqs zhk\n"
"qkb: xbd hlx svj rph cbx\n"
"kgr: htp rfz\n"
"rhj: vdt pxz hzj rqs mll\n"
"cgb: rdj tkc smj hgh\n"
"vvf: dlj\n"
"gxg: vdh hlf hlg\n"
"cnz: vtf xnp ltl\n"
"hsc: jnd\n"
"lcf: xtv\n"
"ptr: qfq xcm zzt\n"
"rph: tpj cgh\n"
"gkv: xkx fnq fmh vpv\n"
"rkp: vfl rrs cjl cbz\n"
"rql: mdh plj xrq\n"
"sjd: jvx chn bbb\n"
"ptc: srn qgx xrd cch\n"
"pkr: qcn cfv stg ssv csr\n"
"tkx: chv dsr cgh\n"
"zhb: sgt zmb lbl\n"
"pjp: fjr kbj cqf\n"
"kxt: rrz nlx\n"
"kxx: tth sfh\n"
"qqd: nht mgm fqj xkh\n"
"jnj: qtg xpf dns lph kfs\n"
"knj: cjz qzc fzq lfc\n"
"mpr: nvv tgr kkt vkm\n"
"jkz: cpr hdn pmv djt\n"
"fth: qpx nth fkx hkl\n"
"vbs: crr chr vpn mjv\n"
"bnn: xcr glv hnh\n"
"rvs: hqd qmr\n"
"xkb: mfn\n"
"qml: lnk dgh kch lbj\n"
"cls: lsq ckn stg lrd\n"
"nhh: jnp nsh xds tth\n"
"nsk: fhr tfr\n"
"lgs: tth czk\n"
"bjg: tfr nmq\n"
"tjx: zht fzq fkv rbx xtf bjk lgs\n"
"thk: nth fff\n"
"svn: tbm jzk nld sjp\n"
"fkq: bxp kbc cps dtd\n"
"prx: jfk tkv\n"
"hjb: ctl pbx lqm kzm\n"
"vfs: mbj\n"
"ggh: slj dns bkf\n"
"rns: dmv fmb lcf\n"
"lxl: jvl rdv mpf\n"
"bdz: xxs\n"
"mtd: nsr zgd fqb\n"
"dkd: scf xqh xbd\n"
"mnc: qrl qjc zrp\n"
"ftg: vnk\n"
"vfd: xtv kds drk szg\n"
"fck: lrv tfr nvc\n"
"ldm: bdr skj xgv\n"
"xmt: bxp lcj kcn xvv\n"
"klq: xqn dch hpc ghj rxl lsh\n"
"fcv: bmv pzb hxk thc ndq\n"
"fmb: nnm\n"
"fvv: vdf\n"
"lxb: vxr cqp\n"
"xcs: ngx qrj flm rqs\n"
"bvk: csn qnq\n"
"gpc: bcd\n"
"tkv: gjf\n"
"sds: sbx glb pzd frq\n"
"gxs: lfr hpc vdt\n"
"slx: jxx qpg dfc\n"
"zjf: nql\n"
"xvv: rqs bnn\n"
"bbp: gtv\n"
"zlt: ddl btz nvj\n"
"bmd: kcf fjr\n"
"dkm: qlb\n"
"hdr: rqp lxb dvp kfn\n"
"xqr: mmh\n"
"hlm: kqj rxb psh xrd hkz\n"
"jgz: jcl gss nnd rdj kfk pfh\n"
"qgx: ddr\n"
"lxn: mmf snd lfc ltb\n"
"zjp: ctg zdx xdv skc\n"
"qgt: cdb ngq cqg qpg nqz\n"
"pvj: rjx xkk\n"
"zgc: grk bpd psh vct\n"
"ffc: xhk vnk kfx\n"
"bvc: phl glt bxl tgs mmr\n"
"lxz: nlh mfd dmv\n"
"qrf: hqd lzp fbq cpp\n"
"frj: zpb sks rrp bfg\n"
"bmm: rsn jzj qkk xkk\n"
"lqv: ghj cbz mnt pnf\n"
"chr: stz\n"
"nsr: jnp\n"
"sbz: khx qnn vdr\n"
"kxs: hqn ctg\n"
"drp: rpc bng\n"
"jlk: pdz\n"
"plh: gsr tpk nfr bhm\n"
"hpm: bkf lsq\n"
"ths: jpg pmc\n"
"gps: zmb hsc\n"
"jts: vpl gxm fnq\n"
"xtc: qpl qvk\n"
"hdt: tbc jpm stz hmn\n"
"qzl: lld fck hcx\n"
"rmd: fxx mvn jks cbz\n"
"hsh: glj\n"
"cdf: qnq ths\n"
"rjh: lsc mzv hbb qgx\n"
"jmd: nxm xgh ndt sjd\n"
"htk: bch ckh xgs rvq\n"
"qkg: njp nrz bml dpt fmh\n"
"vkq: fhr\n"
"drk: gtj cps\n"
"jqq: scf\n"
"qjv: blr xck ffg pmz\n"
"vgv: kxz ssb\n"
"dvj: nsm cqc rnt spg\n"
"kkt: gpc fqc gzp\n"
"cpj: rbl vxd ldf fqh\n"
"scs: cjz ntv\n"
"lnv: qfh nvj lzp\n"
"kjg: dgc vnj sjp\n"
"rcq: fhd nrh\n"
"smc: ckh rml rfl bfd\n"
"nkv: rfv rrp\n"
"fvm: mmr\n"
"skt: pfv\n"
"jgs: mjv fcp xtn\n"
"pxz: sqn\n"
"nkt: msq bfn cqj rql\n"
"nxs: ctc pbp\n"
"qhl: mpf xjf rfl lrv\n"
"fhl: qrl npg qfj\n"
"vsb: zht pdb qfh jmh rdr\n"
"xvp: krl lhj\n"
"khj: thd nlh dch dgh\n"
"fgs: fbc ltm\n"
"qlk: thj xcx bfq\n"
"fnn: khd xsz xxs\n"
"kpq: jrt\n"
"bck: fff lsq cbm\n"
"dbh: gxx lsc\n"
"nqs: dkm zmq scn hpz\n"
"mrn: tsc djf kxs fmz\n"
"scn: tgr\n"
"qkc: fbx bmf\n"
"str: tqn\n"
"ftt: xst cms pvc qjg\n"
"qbn: blm czk\n"
"spt: rvd bbn gvq jgs\n"
"qnn: rhh mll\n"
"ftv: rzd vkd\n"
"hzk: bvh kpq\n"
"tpj: rzj\n"
"vgh: qpl\n"
"ngf: mqn qfq zth\n"
"zkp: lnd glb\n"
"qpg: nql gbx scf\n"
"rhz: hnq dqr\n"
"tqn: zkm\n"
"xkk: hmv\n"
"vqx: zth rrb\n"
"vjk: rqh dps fmb nxs\n"
"cbp: pkd kgr kbc hlf dpc mdf\n"
"snc: glj mht fff\n"
"dfc: tgn dbv\n"
"ltl: fsp dbs\n"
"kbg: vqc cdn dpg\n"
"tkz: kkv\n"
"czz: hpc tjv fft lsh\n"
"sqz: pgl njs\n"
"kkr: bxb qng nns\n"
"bgm: knm jfg mlk\n"
"kcf: rhk nmq\n"
"cjq: tjv cvj lls gct qcn\n"
"fjt: jvn fkb mqz dbh\n"
"kgj: mgq knk bjd fdx qgm cpv\n"
"gsj: dld jtv\n"
"xfg: jbq hrc bmv dkm\n"
"txl: vvh jcm vgv vnf ssh\n"
"xlf: vcq grm\n"
"jfg: jfm\n"
"cdh: hxk pbr qfh dgd\n"
"bcb: mqf jcl kkk\n"
"vbv: csf qxv jxx nkq\n"
"hjv: xtc mgn\n"
"gsd: khp lsc plm sjs\n"
"mns: qdh chv\n"
"vjr: qpm\n"
"kxz: mll\n"
"khz: xlf jkm gxs\n"
"rvd: vdb nrl sgf lnv tkz bfq\n"
"bhx: fgs ghj tjv lsc\n"
"bnx: gjf fqv\n"
"mtc: jrt kfs\n"
"bxn: dcf lzg\n"
"dxk: nnq zkm\n"
"tqj: nql\n"
"qfv: spg xnp\n"
"zrf: grm kkc\n"
"vfr: kmb psl\n"
"xnm: kxt lmj xtc ngq jjv\n"
"bxb: jcr gpc\n"
"hbh: mvn fft sth bck\n"
"nzc: nfr rgr psh\n"
"dps: gtj fqx\n"
"xtd: nzc glv ltl\n"
"xhk: fjq mbj\n"
"ljl: fzx dqm\n"
"xkc: tzq\n"
"qnk: jhj zkm psl fcs\n"
"xgd: rrb\n"
"qlj: vqc nhz kkc\n"
"vfl: snh\n"
"nht: phn rvq xkx\n"
"stg: kpf\n"
"mpf: lnf lnx\n"
"nnk: xrn\n"
"nch: rms fdx\n"
"vvq: xnp\n"
"rjv: gkt gnt chn\n"
"dhl: nvl vfs rzd kmc stg\n"
"fxp: jzf thl fzh\n"
"jfq: dpc dcv bjd dfj\n"
"zlm: xcr qnn dgh\n"
"jmh: tqj vnk\n"
"jdc: xzc jrb\n"
"xpj: fcj vnv\n"
"zmq: bfn\n"
"fjc: njp lxg rrz gqd pbq\n"
"cgh: scn\n"
"kvn: grh lqm jcm\n"
"gkf: kpf htp\n"
"chf: llq thl mpv\n"
"srj: mfj zgp mmf fhg fgb\n"
"hcx: mgn rhx\n"
"dvb: lhj hxn ptj gkb\n"
"dcv: hcb rxb bqv llq\n"
"gdx: qlm xqr vfg\n"
"bnj: gcr fdm dkd tkq\n"
"lbh: kts khp\n"
"tmk: xqg glt pnf mjp\n"
"gln: xjq trn lkc\n"
"fhp: hxk gnt rxh tqp\n"
"zgh: zdg ggz\n"
"kmv: nch\n"
"rdr: zzv pdb\n"
"vbt: qzj nbq gxz mkz\n"
"hsr: kld\n"
"mgn: crz rhk\n"
"nlx: dfp jts\n"
"tpk: hfl kkp\n"
"sjs: tpf lxf\n"
"mls: ttq qcq bfn kmf rbl\n"
"ddj: rbv szn sks rrp\n"
"bmn: kfs lfr bdz\n"
"xcq: gxm scs xqr hsq xcf\n"
"hbp: pjp jzr thc gcr dxm\n"
"dtx: gvx rsg jdg\n"
"flk: hmn xcc ldx dxn qdh\n"
"nzn: grm pbq\n"
"jht: psc vzj hsr fcj vbb\n"
"pbz: nxs cch lxf rfv\n"
"rrs: fxk\n"
"zht: zmb\n"
"lvj: hjv tgd rhz hbv\n"
"ssf: qvt ngt str jdc kpx\n"
"nnx: lxf rsg xdt\n"
"rjg: fbt rbv vrc gsj\n"
"lsb: hmn vvf\n"
"ngq: qhs dkz\n"
"ndt: mbj zjf nrx zgv\n"
"dgd: nsr ddl gjf\n"
"bzr: pkt tdq csj\n"
"rxn: xcm zgp\n"
"hvd: lxf znv lxs cbp zqr\n"
"jcg: qnv\n"
"lxs: pdz\n"
"jvx: nrj\n"
"zzf: xgl gbx mhn hfs\n"
"mdf: fbt bqv cpr dvp\n"
"dqv: vbj mlk pfp nnk\n"
"tpf: fmr\n"
"dcf: rsq\n"
"grb: hzc mvz mht\n"
"xgh: scn lmj\n"
"kfv: dcx rpl\n"
"hcb: jlk\n"
"jpz: rxl msb bcl tpk ngs\n"
"kpv: kzs ftg mtd\n"
"kqs: vvh lxs lhr\n"
"lfj: xpj bqv\n"
"nst: zgh vdb zdg dzj\n"
"trb: mgx vvf jvx\n"
"kcd: brr dbj mbm\n"
"bzq: kxr lhr fmp qrk\n"
"stp: glb jtc nnd\n"
"dvp: xrn\n"
"dtr: fkb tsm\n"
"ssc: vhl xqh chn csn\n"
"pkd: xzn jkz glm dks\n"
"mkj: bqz hcx cbx\n"
"ksj: glj cmg fds\n"
"cgc: njp kfx fqv kpv mvt vqx\n"
"ctc: pfv czr lqf\n"
"mvp: fgv hzk rts\n"
"sln: vjr vnk\n"
"jbq: rxh njs lld\n"
"trz: rfz sgp\n"
"ldr: fmh hlx mgm tpj btz\n"
"njs: krl\n"
"bmv: dtj ckr lsb\n"
"jcc: fkx jrs\n"
"lvx: zhk jcg xzm\n"
"qfq: dgc gjj\n"
"bqd: gpv zlt mch txz qdc\n"
"qgv: mvn hzq kzf zkj kbb\n"
"jml: mmf cmp rmr llt kmf fjq\n"
"nrx: gdj\n"
"cmp: mdh vfr xcm lzp\n"
"kpx: vmv rfl qzd\n"
"pvv: bdc nzn gsm xrl xnp\n"
"bxl: fkt sqd dhq\n"
"xds: dfp ffs rzj\n"
"fvf: xtn\n"
"cps: qpx hsr bmn\n"
"fmp: ltv\n"
"tdp: lqf mht\n"
"dsv: mch\n"
"trn: xnl\n"
"pdb: qpg\n"
"mcr: jpg nkn jmd ssc\n"
"trq: jzf mvz\n"
"hfb: mns hhj tfr rxr\n"
"sfh: mdh bjf\n"
"qtm: tjh\n"
"xdt: qnv rsq\n"
"fbx: vfg tkv\n"
"hlx: dqr\n"
"rpn: dxl jfg mcn\n"
"xtn: mdh\n"
"rmt: mzj fns\n"
"fkt: ssb sth\n"
"rzx: rnl\n"
"lbc: gck\n"
"ngx: hlg\n"
"qcq: mbm bbb dsv\n"
"kkz: dmt qkc jvx\n"
"jcl: qxc\n"
"sgf: hqd vfg\n"
"lkk: qfv xsz csr\n"
"thj: xtl lrn\n"
"zqg: tjh\n"
"qzz: hbv srj dgg bts\n"
"ntq: xtd pbp lpl jtr\n"
"pph: xjd jhq dfp mkj\n"
"fgh: bjf bdr\n"
"hhp: tbb ptr\n"
"cmd: nmf pzb zlz hcx\n"
"mlj: lnf tzq\n"
"nmf: zlz fkv\n"
"nbq: mrm\n"
"ccx: trj xcc khb\n"
"jqg: hbb\n"
"vdm: krl zgd gjl fgh xjs\n"
"zgv: vgh sst kmb\n"
"ppx: dhq gsc ltm\n"
"dkq: czk cqg qvz\n"
"xhl: dbx jfz tgn nkn\n"
"rqh: ftv mlk\n"
"vjt: gkt lpt pkv hqh\n"
"njx: vbr kcn ltv tzz stp\n"
"zcq: dkz tbb fdm ldf krl\n"
"qsk: mjb skv\n"
"xsc: dgf\n"
"zcx: qng bbn xst phg\n"
"nrq: vhf mgk gpc\n"
"lsq: hkk\n"
"zxc: dks gkj vdh\n"
"lqj: gdj\n"
"nhr: kts jcc trz\n"
"mfh: srs lrn ttb tmz\n"
"xqg: ddr hbh mkz\n"
"qrj: tsm rms dcl\n"
"mkq: pqg qkg xhk\n"
"tsm: rmm lzg mrm\n"
"xqh: gjh\n"
"jgc: qpm\n"
"nbc: hbv bcd\n"
"bpd: fmz gtv\n"
"trg: bfk mgf\n"
"dmt: fkk vfs\n"
"crx: cpp ndt qdh mqn\n"
"qct: tjh\n"
"ntg: jzc jdg\n"
"zdx: fxx kcp\n"
"klb: xrq cqs lkc jnz\n"
"sqd: snh\n"
"hzq: jtv\n"
"ckr: vkq nkn jzr\n"
"tdm: hqn jxd xhr jqg mft sjl\n"
"njr: fgv skt czc cqh qkv drk fnl cbz\n"
"gsr: qps tzz\n"
"tkc: fgc gxz knk\n"
"kmc: khx htp hdn\n"
"mpm: bdc qjb fcj\n"
"xzp: vcq hkk fmb bnz\n"
"pfv: pdh\n"
"qsm: mlc lsl\n"
"ztv: hsh msb ftv bnz\n"
"pbr: bqz\n"
"fvg: xpf\n"
"cbz: lnk vfv\n"
"qsh: nrh rjx zdj dxn\n"
"rlf: thl mtc lcf\n"
"dcp: sts jzc qmj\n"
"jtf: csn\n"
"vxr: knk\n"
"gbz: hmn qng hhj\n"
"fbg: nsh rqb\n"
"fzq: fzc\n"
"gjj: zmb rrb\n"
"mlc: mmr\n"
"hrq: jzr qpm\n"
"htr: hqh dmt pzb xck zjt\n"
"sgt: dxn fbg dzj\n"
"kzs: dsr\n"
"qpx: fmr\n"
"xjq: fbm xkc\n"
"rnl: tzr qlb vgh lqq\n"
"ckn: dkj\n"
"hzj: bvh bnn\n"
"msv: kxx vpl dfp\n"
"hlf: vct\n"
"qjb: kpf\n"
"clh: bnv kkv mgf psl lbl\n"
"qpf: chv rxn\n"
"rjl: jrt zxc\n"
"kqp: fmr lsm xql hpm\n"
"znl: bfd dvr ttq zgp\n"
"lhn: zkm xkk\n"
"dqm: ttk vkm bvk rhk\n"
"nxj: phr pjp tbb rvc\n"
"jsd: rqh mvp rxb kgj nbd\n"
"zzc: fzq bkg thj\n"
"mnn: mbj rxn jmh jxx\n"
"tbb: fqb\n"
"dkz: tbr lnf fbm cqj\n"
"rvb: rxr jcr\n"
"lmj: fqh nnq\n"
"jkm: vcq bqv gkf\n"
"ngd: fhg xcx\n"
"xst: chr dfp dkz\n"
"bds: cqc\n"
"tdq: rpl vfs\n"
"khb: pbr\n"
"glh: tzz glv kzm\n"
"tsj: dsr xvp hrq\n"
"dbs: tzg\n"
"ttm: hsr skc xtj rqs mjp\n"
"jjv: bmd jtf qpg\n"
"dxn: gkt\n"
"crk: cch xxp\n"
"pgh: hrm tjh jnd\n"
"qdz: ntg cdk dcv\n"
"crr: fqb pmc\n"
"chj: pzd kxs hvc dhl\n"
"thd: lnk xbn\n"
"hzc: flv lfb\n"
"rfv: xxs zsv\n"
"vrc: flv xmt sgr\n"
"jfm: sgp zdx xnp ssd\n"
"lmg: ckn fmz jkt tcm\n"
"kdc: dfp\n"
"qkv: dch\n"
"cdx: rpn xql lfj pfh\n"
"npp: vmn lxb gsc mqz\n"
"gtj: bcl hqn\n"
"pxn: jzc mfl ntn ksj\n"
"bmf: nbc hnq\n"
"zzb: shk xxs\n"
"hdn: rrs gxx rmf\n"
"ddn: lqq fzx mzr\n"
"gcq: nvj zmq hbv rvs\n"
"qgd: hqd qgg bsc gvk rhx fmh fdn\n"
"sht: lcj stg zqr rts\n"
"jpf: gcr trb lrv rsn tkx bng cnr mzj\n"
"lnf: trj ccx\n"
"tqc: lqm dpg\n"
"qlv: kld kch\n"
"tbm: qpm nrz nld nsk\n"
"tmz: nrz prx kkz xnr\n"
"ltm: hlf\n"
"qjg: xnr pgl cqf\n"
"shn: hlh fxp mjb\n"
"csj: bvn zgd fzx\n"
"xkh: htk qpl cqf hlx\n"
"lzg: jrt\n"
"skj: bbn ngf vrl\n"
"sst: lzp ffg\n"
"tgf: lxg fqh bst hhp sbq gjk zsj\n"
"kbn: vxd vkm fvr qqd\n"
"cnr: qfj qpf fqj\n"
"clp: prx pbr tzr jnd\n"
"bxp: jks\n"
"mfj: xqr bnv tbr\n"
"bqg: xtn ttb\n"
"gkb: qzd xqh fbg\n"
"xdv: fjs\n"
"rbl: tpj hbv lms ntv\n"
"bst: cqs qkc rxr\n"
"bpl: tsm nlq vxr dlb\n"
"gdz: bnz znv fkb\n"
"qzc: xgv cdf dxk\n"
"rzq: zkm gpl fkk\n"
"pqz: dbv kdc rzx mns\n"
"hpz: pmc pmt\n"
"rmr: lnl nld\n"
"jtv: gxx\n"
"hzt: vdr zcr dpg rxl\n"
"xtf: llt kbj\n"
"bhd: rpc vkm mgn dgc\n"
"mml: gxg rjl\n"
"kqj: mnt rjl stp\n"
"kvr: rfl lqj\n"
"dfx: tnt xxq cfv mcn\n"
"kkp: mqz rns hkz\n"
"nzx: ksj pjv dtr bgv nhz\n"
"knf: lsm ssh cdx\n"
"mbk: bvn mgx dfc msv pft\n"
"btd: kzd rmf ggh sgj rsg\n"
"sqq: xrt jpm\n"
"blq: jqg nsm cpr\n"
"mtt: mjb qtg hrx kmv jsr\n"
"xch: zqr\n"
"kpg: qnq tct blr\n"
"mfp: rmr ffs ltb qzz prd bqd\n"
"xfc: bmn mkz fqs vvq\n"
"bbs: cdk fkb\n"
"pzq: jqg spg vdh vrr\n"
"trr: mgk rzj lqj kfv\n"
"tvp: slj tqc lsh vgv\n"
"xpx: ssh hgq zpc zhn\n"
"fjr: tbl\n"
"ssv: khd lsl tlp\n"
"ffs: fqv nld\n"
"fxm: sjp fcs vnj nfn\n"
"mzr: ldf ttb\n"
"hkz: bqp\n"
"srs: jqq njg vhf kgx\n"
"nvz: drp dbg\n"
"rbs: gck skd fcs bfd\n"
"xbl: bhk xgd jzj jvl\n"
"ldx: ttn xqr\n"
"cpp: xgd slx\n"
"jtc: bqv\n"
"jhq: hxk\n"
"xmd: dgf mkz nll lcx\n"
"xrt: ggz dpt\n"
"phr: xzc rml zjf snd\n"
"tgd: rph xls qsl\n"
"vlm: msj gxm stz cdf\n"
"pqx: qsm dxl kpf\n"
"lqh: xrt gln btx jrb\n"
"gjl: dbx fck scf\n"
"lrn: shm\n"
"fzt: mvt sqq cqf fqd jqn mzz\n"
"njg: rml npg\n"
"drn: rdv bch\n"
"jxf: vpn tfr hrm\n"
"vtx: fcj fgc\n"
"grk: lnk dhl lcx\n"
"rdd: phn scs bmf ngd\n"
"kzf: dtr cqp bbs\n"
"gcr: bcd\n"
"sgq: hsc qbn trr\n"
"glt: lkk\n"
"rml: vkq\n"
"mcl: vdc nrz sgf xgv lxl\n"
"hfs: fvr gqd\n"
"qxc: fxp nth\n"
"pkv: mfn\n"
"tbc: vvf\n"
"cfv: fgp\n"
"mjp: bqp vcm tdp kcp\n"
"xrl: ddt znv vnv bxn\n"
"khd: mtc grh tzk\n"
"xgc: lfk nfr xcr znv\n"
"jdf: dtj scf gpl\n"
"bbn: vqx mzr\n"
"hmv: tzq\n"
"pzz: rvp zgr kcn nmg vdf\n"
"ngs: gsc\n"
"jvn: qrm vcq hgq\n"
"srf: kdc lqj njs\n"
"rgd: tgd vdc ckh\n"
"xtb: ndt lfh qqt mkj\n"
"rlp: gnt fkk kdb\n"
"cdk: dvp\n"
"ctf: pqr vfv lsl\n"
"dkj: vgv drq\n"
"jhj: gjf zxg dsv\n"
"cms: gln tct tzp\n"
"jxx: dvg chv\n"
"xgl: cqf vpn dsr\n"
"czk: ddl\n"
"ddr: dks\n"
"rgr: flv gxg fmp rzd nch\n"
"mxq: vxq lxs qcp\n"
"rnr: nmg nnk dbs\n"
"dxl: ssb xdt\n"
"zpc: jsr skc xvp srn\n"
"krd: knj prd zrp tqp\n"
"fbc: gtv glv\n"
"ptk: prc tsc grb nsm\n"
"nbv: xch tpf xjk llq grt fgp fnb xdv\n"
"xcf: fns kcf\n"
"fds: bbp sqd cqc\n"
"jtj: rxl hhm cdx tpf cqp\n"
"dtd: rlf vnf cpv gkf ngs\n"
"vtb: spg sjl sth\n"
"vzj: skv cjl\n"
"ffp: ltv jsb\n"
"pqg: vfg dgc bch\n"
"lbj: gxz hsh\n"
"kzd: cqp\n"
"hrn: bds nvl kkk\n"
"bdr: mjv\n"
"qsl: xzf nrx chr\n"
"dxv: ppx jtc jcc\n"
"hsq: ndq mtd dpt\n"
"qrl: zxg\n"
"kjs: vrl gkb xsv rqb\n"
"jxp: xjq xls xtf fqk\n"
"vpb: zth hmv crz lfh\n"
"grt: xpf tpf\n"
"lfc: mqn tth kmb\n"
"sts: drq fzv\n"
"bkg: tkz hcx\n"
"rzj: ffg bbb\n"
"qdh: mgm bqg jtf\n"
"clq: jks jjj vnf cpv\n"
"sfc: rcq dvg mmf\n"
"lfh: qnq\n"
"lsl: lxf\n"
"gct: gss xtv qxc\n"
"bft: hbh qdz czc qkv slj fpl\n"
"cpv: ltv\n"
"tzr: zmq\n"
"blm: vkq\n"
"vdc: nlx snd\n"
"nhz: bnz dpg\n"
"jcm: shk\n"
"mzv: ltv rxb\n"
"sdz: zmq dcx zft hjc\n"
"gxm: gbx\n"
"pcn: trs bch\n"
"jfn: bxp gss txl mqg\n"
"nns: tgn dbg gkt\n"
"nfd: fqd hqh zfz\n"
"mch: klc bdr\n"
"hpg: kxz rnr xnp pdz\n"
"vxm: kcb qbm xpj nkv\n"
"svj: rvb kxt txz\n"
"dnj: qct ljl zkm str rjv\n"
"lhj: hnq\n"
"vrr: xhr\n"
"xzn: hpm qsm gzm\n"
"xxq: hfq fxx\n"
"fns: gjh\n"
"mcn: rrs\n"
"kjj: nld dcx jnz pmc fbm\n"
"hpl: fqd rpl nlx jcr\n"
"rbv: nnk cch\n"
"mss: mgm tgn\n"
"vbb: sqn gct lbh\n"
"dfk: scn khb xsv mjt\n"
"kkc: pdz\n"
"kdb: prd xnr\n"
"vxl: kfk mfl\n"
"fzb: msq xqh rpl jnd\n"
"gjk: tsj rlh ths\n"
"hgq: dgf\n"
"glm: sgr xjk\n"
"ccg: dbx kkv vks pzb\n"
"hfq: cpr hhm\n"
"nqz: fqc dkq mnc\n"
"smt: tnm mvz mlc kkc\n"
"qfp: xnl mqn pmt\n"
"sks: jvm\n"
"cbm: sgp gtv\n"
"nkq: qpf lsb vhl\n"
"mgq: lrd rsq ssd\n"
"mrm: jzf vct\n"
"vlj: ddd csr gtj xhr mpm rdl\n"
"kkv: rrb\n"
"tcm: nbq hfl zlm\n"
"fpq: qps nfr jtv bcl\n"
"qtg: xsc jcg\n"
"lcj: vcm dkp\n"
"dkc: xtv cdn hfq pxz tjv\n"
"mhs: hfs mjj vjr xjf\n"
"xpn: qng bnj mls vpl\n"
"nlh: fmr\n"
"ltg: mlj qpg zqg mbj\n"
"vnj: zsj nrj kcd mbm\n"
"rpc: nfd dbx pkv\n"
"dnp: vdh grh jsb\n"
"fsh: str sgt rxn cqg\n"
"sjh: qnq cbd vhl\n"
"qpl: brr\n"
"ktj: dck zpc bbp\n"
"hrx: qcp qsk fzh\n"
"lth: mmh fkv ttk\n"
"jhn: kbg qgx hrx fvc\n"
"nfn: njg crc klb\n"
"ntn: thd mml kfk\n"
"ngb: rrb mdh\n"
"frq: mqg dck htp\n"
"qfh: bvn qct\n"
"kpl: fnb pfv kzd\n"
"tkr: phg gbx fqc\n"
"fcs: xjs\n"
"bjk: rbg rjx\n"
"zgz: rdr bjg\n"
"zlk: vvq snh rsg\n"
"ttk: fdn\n"
"fnz: bjk xjd qsl cnk\n"
"rbx: fvf\n"
"bfk: rmt lkc jfz\n"
"cqh: ckn lvb kmv\n"
"vmn: rsq\n"
"pzd: xrd\n"
"zvg: nsk trg ffc rvb kpx\n"
"gnt: fqh\n"
"zjt: jzr fqv lfc\n"
"lqn: fkx xhj fsp kmv\n"
"dvr: zmb rhz\n"
"vjp: vdf lqf\n"
"kgf: fgv lkb trv dfj xtv\n"
"pzr: mpv slj djf xvv\n"
"lrd: vjp\n"
"zpb: pfp bxp drq\n"
"bfq: ccx cdf\n"
"lzk: cdn dtx mnt mfd\n"
"fvr: dbx trs\n"
"hvc: fzh pmv knk\n"
"gnv: mmh fnq vfr klc gqd\n"
"xvr: flc jxd hkk rmm\n"
"czc: fgv hpc\n"
"fdn: dlj xtl\n"
"qjc: qzc zgh thc\n"
"nzf: lgk jpm kvr scn\n"
"zkj: kpq xhr fnb\n"
"rdj: rrp jcm\n"
"phf: knk kgr vfv\n"
"bfg: bds jsb\n"
"nll: xhj\n"
"btp: vhc djt qlv vbf fmb\n"
"sxb: pxz dck bbp mlc rts zhk\n"
"jqn: jvl fkv njp\n"
"slp: vmv fhd lnx sfh\n"
"zcz: snh rjh xjk pdh\n"
"qjn: pgl kdb ttn zgh\n"
"jzj: fdn jdf\n"
"mfd: lrd\n"
"pfh: bbs xlf\n"
"ssd: vbf\n"
"txz: cqf gjf\n"
"knm: zhn jdg\n"
"dbj: rjx fhg\n"
"rvh: mkz hbh xmx\n"
"hhm: crk sqn\n"
"dts: lbc qzl dsv rzq\n"
"crz: ngt\n"
"mjl: kkc vzj mxq\n"
"hgh: kts tjv\n"
"vkd: bmn bnz glh\n"
"mjt: snd nbc\n"
"qmj: zlk pln srn ltl pvz\n"
"mjj: lgs dkm tbr\n"
"kcb: mjb dxl dps\n"
"jll: knf mmr lvb vtx\n"
"bqx: pqt sth\n"
"jrx: fbm vxd sqq\n"
"qtl: xcx spl dxm fkg fbx\n"
"cbx: tct fcs\n"
"tfr: shm\n"
"klc: tbc rxr\n"
"xvj: mft jxd sgp mtt\n"
"dfj: fvv zsv\n"
"zkz: fgp gsc mfl gtj\n"
"msb: xsc dbs\n"
"jtr: nlq tdp vlf\n"
"pdh: pfp mvn\n"
"tzg: lfr vfl\n"
"jfz: zfz\n"
"ttn: sln vrl\n"
"sjl: sqd\n"
"smj: tqz dmv xjk fnb\n"
"vlf: mvn vmn\n"
"fqc: gkt\n"
"cbd: xtl\n"
"sjp: mqn cbd\n"
"fqx: zcf msb\n"
"jtx: qlv pqt xmx hjb\n"
"vhf: xnr mzj fvf\n"
"nmg: jcg xsc\n"
"mlp: crr pph hbp\n"
"trv: fvg fvv ffp\n"
"qhs: xcx nsr\n"
"mgx: bnx ffg\n"
"vpv: jrx cgh mgk qqt bbb\n"
"phn: shm\n"
"szg: glb qqg\n"
"jzk: pvc ftg rmt\n"
"bml: xjq bdr dbv\n"
"fbj: xgh kgx lnl fcp\n"
"zdm: rgd qlk zgz bml\n"
"lms: fzm pmt\n"
"zsj: fzc lhn\n"
"ldp: jsr szg trp nkv\n"
"crc: lfh ddl\n"
"skd: nkt cqg hpz qzd cmd\n"
"ntr: lsc fdx zkp zzr\n"
"kgl: rnt hxp zrf fft lcx sjs\n"
"zrp: jhq\n"
"flm: shk qjb gvx\n"
"mqg: fbt\n"
"lnd: thl\n"
"trs: cqs nsh\n"
"bjp: qzm nbd trz fvc\n"
"tpn: dkq kpg vfs ljl\n"
"xck: xqr fkg\n"
"jjp: lfk gdz shn grt\n"
"cgp: fbt bpd zcm jzf\n"
"pgq: sgj rkp lvx qlj\n"
"nfz: rxh qzl jnp hrq\n"
"pvz: ngx bnn mmr\n"
"dhq: tpf\n"
"xpm: skt vxl gkj gxz\n"
"zft: tdq ffg znk\n"
"qlm: hmn jzr xkk\n"
"mdc: tzp dxk mlj xzf\n"
"vcq: qkv\n"
"qxf: bpd ltx mqf dcf tmk xql\n"
"nrl: hmv dxm ngt ttk\n"
"gvk: fsh fjr xlc\n"
"xtj: lcx fkb kvn\n"
"vng: xjk mft vxr cch\n"
"bhm: phf gsm lbh\n"
"fdm: phg jrb\n"
"dpr: mbm xgv xsv gzp fqj\n"
"pjt: tbl pcn jxf gcr\n"
"ztp: tqj hnq jgc\n"
"llt: dlj vrl rzx\n"
"vpn: tzr\n"
"fhd: cdb fgb crz nld\n"
"zlz: vhl pdb hhj\n"
"zkb: vgh rzx xnr pmz\n"
"bdd: tkr pcn kzs gjh xjd\n"
"dck: bdz\n"
"vkg: lms zth htl plj lnx\n"
"hxp: dkp bqx ctl qpx\n"
"qkk: xcm lsb cqj fzx\n"
"sgc: hqb hdr dns hzk\n"
"gjg: kfn qrm pqr bdc\n"
"jvc: gxm xgh xkx gkt\n"
"kfn: vcm\n"
"msm: hzc pkd jks dld\n"
"thc: rqb\n"
"tgs: hbb zzb zlm\n"
"plm: mzv hgh glm zqr ctl\n"
"jvm: csr xsz\n"
"mjn: vtf hzq skv ltm\n"
"rsn: tct nvz\n"
"zqd: pqt\n"
"spl: ngt\n"
"lqm: vxq\n"
"kts: xvv gsm\n"
"hjq: dkm qmr rlp bmd bnv tkx ptj\n"
"dgg: rpl xcx\n"
"nkk: qsn pgq sts srn\n"
"thr: fhl xkb hnq kxx\n"
"vmx: fzm tfb tkq xls xnl\n"
"gzm: xrx ltl rnt kkk\n"
"mjb: jsr\n"
"fjq: fqh xgd\n"
"xmx: sgr\n"
"tzk: qsk nbq kpl\n"
"qnt: xjq rdv zjf lld\n"
"hqd: bcd\n"
"gpz: tbc\n"
"gck: qdc\n"
"qzj: pnf xch mlk\n"
"ggz: ttq\n"
"gbj: qzj bjd vcq rfz\n"
"nxm: stz dbv lbc\n"
"xls: mjt xcf xjs\n"
"tnm: sgj\n"
"zdj: fkg qtm ttq\n"
"pjm: fqx hcb bgv qsk\n"
"gjb: jvl nrx msj bts\n"
"qnq: xjf\n"
"ltx: mfl gvx\n"
"bhk: tqn scn qtm\n"
"mht: kfk\n"
"lxf: pbp\n"
"tnt: pln qzm zlb vrr lnd\n"
"dml: mmr flc kch lnd\n"
"xjd: nxm\n"
"rpf: fvv kpq jlk\n"
"hlh: lls zqd gsc lsh\n"
"cvj: nbq hrn\n"
"cjz: gpl gdj\n"
"npg: fhr rqb\n"
"xzm: mfd vvh pqt bck\n"
"cmg: lnd mpv lfb\n"
"ptj: fkk zgz\n"
"htl: bnv rzj shq\n"
"kpn: kzs jgc chn sgq zmb\n"
"gmm: zdg qdh tqn lzq vfg bzr\n"
"pgr: dgg hgn tbc tgr\n"
"jqf: ssd zqd khp mjl khx fpl\n"
"zxg: rvq pkv dkq\n"
"mhk: cnr kjj klc tkz\n"
"xql: hsh lxb\n"
"ttb: shm\n"
"zgr: mlk plm lxz\n"
"hrm: rrz rfl\n"
"dlb: ktj mpv dcp psc\n"
"tth: xrq dbg\n"
"lgk: gpz sqz rrz kmb zrp\n"
"njp: vks\n"
"fzn: ddl kdc xgs gjj ldm\n"
"hrc: dgd gpl ftg\n"
"msq: bfd qdc\n"
"ssr: pmv hsn khz dnp\n"
"frx: dgf dxv nzn nlh\n"
"jkt: ffp bdz xrd\n"
"qvz: rhx qhs zdg\n"
"bts: cqs jpm lbc drp\n"
"vzd: rms vdh pqx tnm\n"
"btx: gpc fcs\n"
"pmv: bnz\n"
"khk: jdc vkm mlp zzc fgh\n"
"qmg: xqn hsr fjs xhj\n"
"xlc: bkg nql ldf\n"
"tmf: jcg flc pbx skc\n"
"zcf: xhr zsv\n"
"kds: qfv gdf sbx qsm\n"
"pft: jnp vkm kbj gps\n"
"tqp: khb fbp\n"
"kzm: qcp hbb zqd\n"
"vdt: pnf vtx\n"
"vqk: ntv xbd rcq bqz ngd blr hzd\n"
"stm: qxc snc crk khz\n"
"xbn: mqz zsv\n"
"ddt: hxp tdp hzj\n"
"ttv: fsp nll bck ctl\n"
"frl: xzf shm\n"
"gkj: dgh fff\n"
"ntf: vtf sks rmf fxx pln\n"
"fvc: glt pfp cfv jvm\n"
"vxp: rjh rpf jjj\n"
"kcn: zcf\n"
"bsc: tkz gpz tkq\n"
"glj: vbf\n"
"dld: vjp dcl\n"
"kld: xrn jlk fqx\n"
"dxm: fjr dtj\n"
"rxh: mss rbx\n"
"srb: blm lrn fhr xzf\n"
"lfb: rts nth\n"
"kfx: zth hjc\n"
"lld: czk nvc lhn\n"
"kxr: dhq fgc nnm jsb cnz\n"
"zlb: kzd xrx pbp\n"
"flc: vmn\n"
"vbj: fmr fgp fvm rms\n"
"bps: qfh bqg llt qlb\n"
"xlv: lbl lkc pvj mzj drn\n"
"znk: fcp dbj\n"
"fbp: csn qqt\n"
"hpj: zdx kgj lbh xmt\n"
"dcl: vdh\n"
"qcn: hcb mqg\n"
"gpv: nrj xkc\n"
"qsn: hgq jcl sbx shk\n"
"vhc: mcn pln ssb vjp\n"
"dtj: bjf\n"
"xnl: qnq\n"
"pjv: ngx dhl trq\n"
"qmr: dbg\n"
"lsm: hnh rhh zcr xhj tqc\n"
"vmv: kbj brr\n"
"pbq: sln xkk frl\n"
"mhn: nmf jrb fzm\n"
"vxg: fnq rdv fzm\n"
"tfb: vkq dcx tqn\n"
"ghk: cdk pkd fbc hkk\n"
"lrv: vxd\n"
"psc: ssh rjl\n"
"clc: lhj cgc ltb zhb\n"
"jjb: jgc bqz qrl mvt zgd\n"
"rxl: xxp\n"
"jjj: nlq zcm cjl\n"
"rbg: rbx gjh\n"
"qrk: rmm lfj bqx\n"
"hgd: zxc xgc pqt bfg\n"
"gxx: kcp\n"
"gzp: tbl tqj\n"
"djf: jrt vxq fgc xsz\n"
"jfk: ffg bxb nnq rzj gck blr\n"
"vqc: qpx bxn\n"
"pvc: ttq lth\n"
"vcv: vxg nrh mkq mgf\n"
"lls: jcm zzb\n"
"xxs: mqz\n"
"rdl: kqs vvh thk rhh fvm gsj\n"
"fqk: ftg brr dvr\n"
"vtf: lrd xqn\n"
"czr: vrr gvx\n"
"nvv: nnq dkq nmq\n"
"qpb: rfz lhr bnz mll\n"
"qqt: thj\n"
"fgx: hhp hgn bnx tpj\n"
"pnf: fmb\n"
"pkt: jqq sst xkx\n"
"fnl: cdn ddd dmv nnx\n"
"nvj: jpg\n"
"bqp: lhr\n"
"pcf: skv rzd fgs fmp\n"
"zgp: fqb\n"
"htp: fzv\n"
"msj: lnx vjr\n"
"flp: vbj chf bck nll\n"
"zcr: rvp\n"
"dlm: mqn mvt kkr fvf\n"
"ksc: rqp nnm nlq rvh\n"
"pnh: xvr rjl mqf xxq\n"
"pqr: mmr rms hqn\n"
"nmq: xjf\n"
"szn: fdx lcx mqf\n"
"rqp: zhk\n"
"hqb: dck lnk pdz thk\n"
"dql: sbz fbc djf jfg\n"
"fkh: njp nsh\n"
"djt: grm\n"
"brr: jcr\n"
"qrm: glh xtj\n"
"cnk: gbz njs trn fkh\n"
"rhh: qnv\n"
"frt: lqf kfn jfg qjb rvp\n"
"qgm: bgm xmx qqg\n"
"kxc: gxg hlg vfv qnv\n"
"lkb: ltm rfz czr\n"
"ndq: hqh fns gpz jnz\n"
"vxt: dbh mft rrs xdv rgr\n"
"zzr: dkj lhr jrs bkf\n"
"kgx: jpg bvk\n"
"kch: nnm jcm\n"
"xcp: kvr btz fkh srf\n"
"qps: gss lqf\n"
"dzj: nrx ttb\n"
"dks: nvl\n"
"qcp: bjd\n"
"bvn: qdc\n"
"ddd: tgs djt\n"
"vdb: tzp cjz bcd\n"
"rlh: nrh tzq\n"
"lqq: xkb kmf\n"
"lfk: fxk qnn\n"
"jxk: kkc bxl vnv ddr\n"
"mkz: dkp\n"
"hfl: gtj vvq cjl\n"
"dnl: crc qct kjg pmc\n"
"xzc: gps frl\n"
"lpt: jhq pvj\n"
"bng: vnk qlb\n"
"fqs: xch xxp fnb\n"
"csz: fvg pbx rlf mml\n"
"lgg: lfk vcm ddt ltx\n"
"fkg: rbg vkm\n"
"mzz: xbd trj phn\n"
"shq: ffs nrj gjf prd\n"
"vpl: tbl\n"
"klh: mnt hnh tsc kfs vnf snc\n"
"qzm: vfl fxk\n"
"xrx: rmf dcl\n"
"jxd: lcf\n"
"bgv: fvg bxn\n"
"qqg: kcn ntg dkp gxz\n"
"rvc: trg hdt zgh\n"
"qll: lnd bvh vxp flm grb\n"
"dpc: jtc xsc\n"
"xsv: jnz\n"
"xhs: vdr bdc qrm vlf\n"
"gzh: ckr rhx zzc nkn\n"
"qzd: sqz\n"
"lxg: zth\n"
"dvg: tfr cqs\n"
"fzh: cqc\n"
"trj: jnp\n"
"jrs: ctg xrn xrd\n"
"fmz: pmv\n"
"trp: tdp flv xvr\n"
"nbd: ctf sjl\n"
"zfz: gdj lxg\n"
"mfn: pmt qmr\n"
"fhg: blm\n"
"sbq: xrt dpt gdx\n"
"sgr: fbt\n"
"xgs: xkb\n"
"kkk: tnm\n"
"zhn: bkf\n"
"lfr: bds fkt\n"
"lnl: dbg\n"
"phk: kxz flm gsr rxb\n"
"mtg: xgv hjq ptj zzf gpv\n"
"tqz: hzq knm gvx\n"
"rrp: rmf rnt\n"
"zzt: ddn ldf xgs\n"
"btz: lnl rlh\n"
"prc: jdg bvh bqp zkp dcf\n"
"rmm: nnk\n"
"kbb: xvv skt nnd\n"
"kns: nmq str njg pgh\n"
"fzc: rhk jzr rrb\n"
"jtk: mlc grh fsp rfv\n"
"rrz: ckh zqg\n"
"mgk: fck\n"
"hkl: lzg bnn vkd\n"
"fjs: khx fkx\n"
"jnp: lrn\n"
"csf: hqh njs lbl\n"
"gpl: tbl\n"
"lzq: cdb dtb hzd bmd\n"
"xcc: mgf\n"
"lph: fcj mnt ngx\n"
"bjf: pgl tkz\n"
"qvk: fhg rjx jqq dqr\n"
"cqf: zqg\n"
"sxf: ngs ctg fkt zhn sks vct\n"
"kmf: xkc\n"
"tkq: vkm\n"
"bfn: mzj\n"
"lpl: pbx jzc nlh tzz gkj\n"
"gkx: qkc gvq cqj cbd\n"
"gpn: sbx dmv blq dch\n"
"fnv: dqm qbn jvx\n"
"shk: sgp\n"
"fft: xpf drq\n"
"gdf: fbc vxq jtc\n"
"hzd: gkb gdj\n"
"fbz: kkk zrf hkz ffp nfr dcf fnn\n"
"btj: trq xqn mfd lbj gsm\n"
"fzv: rqp sqn\n"
"qfj: rvs vks\n"
"chl: zrp dpt tbr cdb\n"
"vdr: kcp\n"
"tnq: qct trn cmd zht\n"
"sbf: tzp spl bch nrq\n"
"phl: mtc bcb xbn\n"
"hjc: xtn mjv nrx\n"
"vnv: khp xcr\n"
"vbr: psh mvz xxp\n"
"hxn: nld kfv rdr\n"
"hsn: qjb mkz vfv\n"
"ckt: ksc vvq bkf vtb pzd zlb\n"
"pmz: jtf kcf ldx tgr\n"
"fpl: bcl ltm\n"
"hgn: xcc bjg fbp\n"
"zzv: tct qtm vks\n"
"qxv: skj kpg xjs qfp\n"
"tts: nvz sjh tkv xrq\n"
"tlp: vng snh vlf\n"
"vms: hnh hlg rvp nth\n"
"plj: znk gpc\n"
"fgb: jzr rhk\n"
"hhj: dlj\n"
"zcm: vxl fkb xrd\n"
"qgg: fcp xtc sfc jfz\n"
"lvb: nvl fft\n"
"ntv: pmc\n"
"sgj: fxk\n"
"dtb: ngb rvq nrx\n"
"dpt: xtl\n"
"qbm: cbm fvm tsc cvj\n"
"gqd: hqd psl\n"

;

} // namespace

auto day25Part1(std::string_view streamSource, bool sourceIsFilePath)
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

    std::unordered_map<std::string, std::unordered_set<std::string>> connections;
    std::vector<std::string> components;

    using NodeIdx = size_t;
    std::unordered_map<std::string, NodeIdx> componentsIdx;

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

        std::string keyComp;
        lineStream >> keyComp;

        if (keyComp.back() != ':') {
            throw std::invalid_argument(errorLine + "Missing ':' after first component name");
        }
        keyComp.resize(keyComp.size() - 1U);

        auto& conn = connections[keyComp];

        std::string compName;
        while (lineStream >> compName) {
            connections[compName].insert(keyComp);
            conn.emplace(std::move(compName));
        }

        if (conn.empty()) {
            throw std::invalid_argument(errorLine + "no connected component list after ':'");
        }

        components.push_back(keyComp);
        // start with 1, so that 0U will mean 'no predecessor'
        componentsIdx[keyComp] = components.size();
    }

    // translate connection to numbers:
    std::unordered_map<NodeIdx, std::unordered_set<NodeIdx>> connectionsIdx;

    NodeIdx edgeCount = 0U;
    NodeIdx onlyRightCount = 0U;

    {
        std::unordered_set<std::string> addedComponents;

        for (const auto& [key, compSet] : connections) {
            const auto keyIdx = componentsIdx[key];
            if (keyIdx == 0) {
                // This is a node comparing only no the right, wait later.
                continue;
            }
            addedComponents.erase(key); // in case it was added before being scrolled.

            auto& connIdx = connectionsIdx[keyIdx];
            for (const auto& comp : compSet) {
                auto& compIdx = componentsIdx[comp];
                if (compIdx == 0U) {
                    // means this comp name was never on left side.
                    components.push_back(comp);
                    compIdx = components.size();
                    // on the queue, so that it will be tried first.
                    addedComponents.insert(comp);
                    ++onlyRightCount;
                }
                connIdx.insert(compIdx);
                ++edgeCount;
            }
        }

        for (const auto& addComp : addedComponents) {
            const auto keyIdx = componentsIdx[addComp];
            auto& connIdx = connectionsIdx[keyIdx];
            for (const auto& comp : connections[addComp]) {
                auto& compIdx = componentsIdx[comp];
                connIdx.insert(compIdx);
                ++edgeCount;
            }
        }
    }

    const NodeIdx vertCount = components.size();

    // apply Ford-Fulkerson / Edmonds-Karp algorithm:

    // 1) compute max-flow searching continuously for augmenting-flow paths,
    //    concurrently reducing the capacity of the edges.
    // 2) look for the nodes reacheable from the start by using only edges
    //    with residual capacities -> this gives one of the two subsets of nodes
    // 3) arcs connecting the first subset with the second subset is the cut.
    // Here we may use capacity 1 for each connection and reversed connection.

    // We should try any couple of nodes, as start/stop are not preliminarly assigned.

    using Flow = unsigned;
    using Capacity = int;

    using CapacityRow = std::vector<Capacity>;

    const CapacityRow capacityRowZero(components.size() + 1U, 0);
    // the element [0] is not used, therefore +1U is needed.

    std::vector<CapacityRow> orgCapacities(components.size() + 1U, capacityRowZero);
    // the element [0] is not used, therefore +1U is needed.

    for (const auto& [keyIdx, compIdxSet] : connectionsIdx) {
        auto& keyCap = orgCapacities[keyIdx];
        for (const auto& compIdx : compIdxSet) {
            keyCap[compIdx] = 1;
        }
    }

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Components count " << vertCount << std::endl;
    std::cout << "Components only-right n. " << onlyRightCount << std::endl;
    std::cout << "Connections (bi-directional) count " << (edgeCount / 2U) << std::endl;

    using CutSet = std::list<std::pair<NodeIdx, NodeIdx>>;
    using NodeSubset = std::unordered_set<NodeIdx>;

    CutSet solvingCuts;
    NodeIdx basicCutSize = 0U;

    std::string solvingStart{};
    std::string solvingStop{};
    NodeSubset solvingStartSubset;
    NodeSubset solvingStopSubset;

    NodeIdx triedCouples = 0U;
    NodeIdx casesWithSmallerCutsCount = 0U;
    bool found = false;
    for (const auto& startNode : components) {
        const auto startIdx = componentsIdx[startNode];
        for (auto itR = components.crbegin(); /*(itR != components.crend()) &&*/ !found;
                ++itR) {
            const auto& stopNode = *itR;

            const auto stopIdx = componentsIdx[stopNode];
            if (stopIdx == startIdx) {
                break;
            }

            // try with the current couple start-stop.

            auto capacities = orgCapacities;

            const auto& cConnectionsIdx = connectionsIdx;
            const auto bfsAugmentingPath = [edgeCount, &cConnectionsIdx, &capacities](
                                                NodeIdx start,
                                                NodeIdx stop,
                                                std::vector<NodeIdx>& preds) {
                // https://cp-algorithms.com/graph/edmonds_karp.html
                std::fill(preds.begin(), preds.end(), 0); // no predecessor for every node.

                preds[start] = 0;
                std::queue<std::pair<NodeIdx, Flow>> q;
                q.push(std::make_pair(start, edgeCount + 1U)); // edgeCount is an upper-bound

                while (!q.empty()) {
                    NodeIdx cur = q.front().first;
                    Flow flow = q.front().second;
                    q.pop();

                    for (const auto next : cConnectionsIdx.find(cur)->second) {
                        if ((preds[next] == 0) && (capacities[cur][next] > 0)) {
                            preds[next] = cur;
                            Flow newFlow
                                = std::min(flow, static_cast<Flow>(capacities[cur][next]));
                            if (next == stop) {
                                return newFlow;
                            }
                            q.push({next, newFlow});
                        }
                    }
                }

                return 0U; // flow zero
            };

            const auto maxFlow = [vertCount, &capacities, &bfsAugmentingPath](
                                        NodeIdx start, NodeIdx stop, Flow bound) {
                // https://cp-algorithms.com/graph/edmonds_karp.html
                Flow flow = 0U;
                std::vector<NodeIdx> preds(
                    vertCount + 1U); //+1U because node indexes start from 1.
                Flow newFlow{};

                do {
                    newFlow = bfsAugmentingPath(start, stop, preds);
                    if (newFlow > 0U) {
                        flow += newFlow;
                        if ((bound > 0U) && (flow > bound)) {
                            return 0U; // speed-up
                        }
                        NodeIdx cur = stop;
                        while (cur != start) {
                            NodeIdx prev = preds[cur];
                            capacities[prev][cur] -= static_cast<Capacity>(newFlow);
                            capacities[cur][prev] += static_cast<Capacity>(newFlow);
                            cur = prev;
                        }
                    }
                } while (newFlow > 0U);

                return flow;
            };

            // a) search max-flow
            Flow flow = maxFlow(startIdx, stopIdx, ExpectedCutSize);
            ++triedCouples;

            if ((flow > ExpectedCutSize) || (flow == 0)) {
                continue; // go to next couple
            }

            // b) look for the reachable nodes from startIdx, using residual capacities.
            const auto findSubset = [&connectionsIdx, &capacities](
                                        NodeIdx seedIdx, NodeIdx provdeAlsoResidualUpTo = 0U) {
                NodeSubset growing{seedIdx};
                NodeSubset residual;
                for (NodeIdx n = 1U; n <= provdeAlsoResidualUpTo; ++n) {
                    residual.insert(n);
                }
                residual.erase(seedIdx);

                NodeSubset newAdded{seedIdx};
                while (!newAdded.empty()) {
                    NodeSubset nextAdded;
                    for (const auto nodeIdx : newAdded) {
                        const auto& nodeResidualCap = capacities[nodeIdx];
                        for (const auto nearIdx : connectionsIdx[nodeIdx]) {
                            if ((nodeResidualCap[nearIdx] > 0)
                                && (growing.count(nearIdx) == 0U)) {
                                nextAdded.insert(nearIdx);
                                growing.insert(nearIdx);
                                residual.erase(nearIdx);
                            }
                        }
                    }

                    newAdded = nextAdded;
                }

                return std::make_pair(std::move(growing), std::move(residual));
            };

            const auto [startSubset, stopSubset] = findSubset(startIdx, components.size());

            // Finally look for the connections from growing to its complementary subset,
            // just for debug purposes.
            const auto findCut = [&connectionsIdx](const NodeSubset& nodeSubset) {
                CutSet cuts;
                for (const auto nodeIdx : nodeSubset) {
                    for (const auto nearIdx : connectionsIdx[nodeIdx]) {
                        if (nodeSubset.count(nearIdx) == 0U) {
                            cuts.emplace_back(nodeIdx, nearIdx);
                        }
                    }
                }

                return cuts;
            };

            solvingCuts = findCut(startSubset);
            basicCutSize = solvingCuts.size();

            if (basicCutSize != ExpectedCutSize) {
                throw std::runtime_error(
                    "failed check: cutCount is not the same as ExpectedCutSize");
            }

            // Look also for other edges to be cut within the two separated parts,
            // despite this code DOES NOT check for the unicity of the solution in
            // terms of two-subset-separation.
            if (basicCutSize < ExpectedCutSize) {
                // Search a set of cuts that does not further break: it is enough to
                // find cuts within the two separate subsets and we may use up
                // to mincut-1 for each of them.
                for (const auto& cut : solvingCuts) {
                    connectionsIdx[cut.first].erase(cut.second);
                    connectionsIdx[cut.second].erase(cut.first);

                    orgCapacities[cut.first][cut.second] = 0;
                    orgCapacities[cut.second][cut.first] = 0;
                }

                Flow residualCuts
                    = static_cast<Flow>(ExpectedCutSize) - static_cast<Flow>(basicCutSize);

                // Advance in parallel on the two subsets, as generally it is
                // easier to find two short cuts than one single major cut.

                Flow maxFlowStartSubset = 1U; // 1 is dummy, means no further cut to add.
                CutSet maxCutsStartSubset;
                Flow maxFlowStopSubset = 1U;
                CutSet maxCutsStopSubset;

                auto itRS = startSubset.begin();
                auto itRT = stopSubset.begin();

                while (((itRS != startSubset.end()) || (itRT != stopSubset.end())) && !found) {
                    const auto startInStartSubset = (itRS != startSubset.end()) ? *itRS : 0U;
                    const auto startInStopSubset = (itRT != stopSubset.end()) ? *itRT : 0U;

                    auto itRS2 = (startInStartSubset > 0U) ? std::next(itRS) : itRS;
                    auto itRT2 = (startInStopSubset > 0U) ? std::next(itRT) : itRT;

                    while (((itRS2 != startSubset.end()) || (itRT2 != stopSubset.end()))
                            && !found) {
                        const auto stopInStartSubset
                            = (itRS2 != startSubset.end()) ? *itRS2 : 0U;
                        const auto stopInStopSubset = (itRT2 != stopSubset.end()) ? *itRT2 : 0U;

                        capacities = orgCapacities;
                        Flow flowInStart = (stopInStartSubset > 0U)
                            ? maxFlow(startInStartSubset, stopInStartSubset, 0U)
                            : 0U;
                        Flow flowInStop = (stopInStopSubset > 0U)
                            ? maxFlow(startInStopSubset, stopInStopSubset, 0U)
                            : 0U;

                        if (flowInStart > maxFlowStartSubset) {
                            maxFlowStartSubset = flowInStart;
                            maxCutsStartSubset = findCut(findSubset(startInStartSubset).first);
                        }
                        if (flowInStop > maxFlowStopSubset) {
                            maxFlowStopSubset = flowInStop;
                            maxCutsStopSubset = findCut(findSubset(startInStopSubset).first);
                        }

                        if (maxFlowStartSubset + maxFlowStopSubset - 2U >= residualCuts) {
                            // It is possible to cut up to ExpectedCutSize-cutCount
                            // without further break. The list cutsMaxFlow may be
                            // oversized, it will be enough to remove some elements.
                            found = true;
                            --maxFlowStartSubset; // must remove one, otherwise break.
                            --maxFlowStopSubset;
                            maxCutsStartSubset.erase(maxCutsStartSubset.begin());
                            maxCutsStopSubset.erase(maxCutsStopSubset.begin());
                        } else {
                            if (itRS2 != startSubset.end()) {
                                ++itRS2;
                            }
                            if (itRT2 != stopSubset.end()) {
                                ++itRT2;
                            }
                        }
                    }

                    if (itRS != startSubset.end()) {
                        ++itRS;
                    }
                    if (startInStopSubset > 0U) {
                        ++itRT;
                    }
                }

                if (found) {
                    while ((maxFlowStartSubset > 0U)
                            && (maxFlowStartSubset + maxFlowStopSubset > residualCuts)) {
                        maxCutsStartSubset.erase(maxCutsStartSubset.begin());
                        --maxFlowStartSubset;
                    }
                    while (maxFlowStartSubset + maxFlowStopSubset > residualCuts) {
                        maxCutsStopSubset.erase(maxCutsStopSubset.begin());
                        --maxFlowStopSubset;
                    }
                    std::move(
                        maxCutsStartSubset.begin(),
                        maxCutsStartSubset.end(),
                        std::back_inserter(solvingCuts));
                    std::move(
                        maxCutsStopSubset.begin(),
                        maxCutsStopSubset.end(),
                        std::back_inserter(solvingCuts));
                }

                ++casesWithSmallerCutsCount;
            } else {
                found = true;
            }

            if (found) {
                solvingStart = components[startIdx - 1U];
                solvingStop = components[stopIdx - 1U];
                solvingStartSubset = std::move(startSubset);
                solvingStopSubset = std::move(stopSubset);
            }
        }

        if (found) {
            break;
        }
    }

    if (!found) {
        throw std::invalid_argument("Not possible to separate with the number of allowed cuts");
    } // else:

    std::cout << "Start node: " << solvingStart << '\n';
    std::cout << "Start node subset size: " << solvingStartSubset.size() << '\n';
    std::cout << "Stop node: " << solvingStop << '\n';
    std::cout << "Stop node subset size: " << (vertCount - solvingStartSubset.size()) << '\n';

    for (const auto& cut : solvingCuts) {
        std::cout << "cut from " << components[cut.first] << " to " << components[cut.second]
                    << '\n';
    }

    std::cout << "Tried couples start/stop: " << triedCouples << '\n';
    std::cout << "Cases met with initial lower cuts count: " << casesWithSmallerCutsCount
                << '\n';
    if (basicCutSize < ExpectedCutSize) {
        std::cout << "      and the last scrolled was successful with initial cut size: "
                    << basicCutSize << '\n';
    }

    auto res = solvingStartSubset.size() * (vertCount - solvingStartSubset.size());
    std::cout << "\nResult: " << res << '\n';

    return res;
}

int main()
{
    try {
        day25Part1(Input, false);
        // day25Part1("./25_input_file.txt",true);
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

example:
Lines count 13
Components count 15
Components only-right n. 2
Connections (bi-directional) count 33
Start node: jqt
Start node subset size: 6
Stop node: lhk
Stop node subset size: 9
cut from  to qnr
cut from rsh to lsr
cut from pzl to rhn
Tried couples start/stop: 2
Cases met with initial lower cuts count: 0

Result: 54

real input:
Lines count 1209
Components count 1501
Components only-right n. 292
Connections (bi-directional) count 3366
Start node: llq
Start node subset size: 734
Stop node: ngt
Stop node subset size: 767
cut from jht to mhn
cut from krd to khj
cut from fxp to ggh
Tried couples start/stop: 5
Cases met with initial lower cuts count: 0

Result: 562978
*/
