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
#include <stack>
#include <string>
#include <string_view>
// #include <unordered_set>
#include <vector>

namespace{

constexpr std::string_view Input =
false ?

"px{a<2006:qkq,m>2090:A,rfg}\n"
"pv{a>1716:R,A}\n"
"lnx{m>1548:A,A}\n"
"rfg{s<537:gd,x>2440:R,A}\n"
"qs{s>3448:A,lnx}\n"
"qkq{x<1416:A,crn}\n"
"crn{x>2662:A,R}\n"
"in{s<1351:px,qqz}\n"
"qqz{s>2770:qs,m<1801:hdj,R}\n"
"gd{a>3333:R,R}\n"
"hdj{m>838:A,pv}\n"
"\n"
"{x=787,m=2655,a=1222,s=2876}\n"
"{x=1679,m=44,a=2067,s=496}\n"
"{x=2036,m=264,a=79,s=2244}\n"
"{x=2461,m=1339,a=466,s=291}\n"
"{x=2127,m=1623,a=2188,s=1013}\n"

:

"jtx{s<3181:R,R}\n"
"rkd{s>2386:tdr,R}\n"
"svj{x>1520:A,A}\n"
"vkv{x<3627:A,x>3794:A,A}\n"
"ksz{m<1450:R,a<2837:R,a<2928:R,A}\n"
"fp{x<1293:sjt,bv}\n"
"jq{m>1493:R,m>1377:A,m<1344:R,R}\n"
"gts{m<3166:R,A}\n"
"xxr{s<231:R,x<3055:R,R}\n"
"rz{a<2982:A,m<1763:R,x>1878:A,A}\n"
"kq{s<2900:R,s>3591:A,R}\n"
"tmg{s<1500:A,x>2504:R,a<1166:A,R}\n"
"dvn{s<1632:R,A}\n"
"znj{m>1884:A,R}\n"
"db{m<1554:cg,m>3173:R,x<1203:A,xsm}\n"
"chr{a<682:R,x>3120:R,m>2313:A,R}\n"
"pd{x<1433:kp,a<2715:fjd,xtx}\n"
"qkd{s<666:R,R}\n"
"rbf{x>2541:R,R}\n"
"gx{s>1347:A,m<812:gxz,s>1079:tpg,lt}\n"
"fqb{x<1290:A,R}\n"
"jf{x<1340:A,s>2972:dq,x>1378:bqh,jps}\n"
"sr{m>776:A,A}\n"
"vs{s<1377:R,R}\n"
"vx{x>1237:R,A}\n"
"dz{m<192:A,m<271:A,R}\n"
"mhr{m<2568:R,m<3466:R,a>3791:A,R}\n"
"vv{m<3559:A,s>3108:R,R}\n"
"psk{a>2830:A,a<2278:A,A}\n"
"gvv{a>2993:A,a>2553:A,R}\n"
"gsx{x<2656:A,A}\n"
"jps{a<1216:A,R}\n"
"lt{s<967:A,A}\n"
"ng{s<3259:R,s<3674:R,A}\n"
"zd{s>2267:R,R}\n"
"ks{a>1951:bg,m<1522:gpf,gj}\n"
"prk{m<2242:R,s>56:R,R}\n"
"nr{x>3432:R,sg}\n"
"fkd{s>2014:mxf,sps}\n"
"tk{x<1133:jzj,vq}\n"
"sgl{a<1237:R,A}\n"
"smg{x<2071:R,m<387:R,A}\n"
"qd{s<3197:sl,x>1479:lqs,m>1300:rrp,gm}\n"
"tr{s<1306:R,x>1183:A,A}\n"
"bxh{a>1123:fpp,R}\n"
"hjp{a>2545:nb,a>2381:qx,m>2463:nn,bt}\n"
"zg{s<1932:smc,m<1443:rq,jf}\n"
"nnq{m>3341:lx,s<2737:A,a<3408:A,R}\n"
"lx{s>3219:A,a>2886:A,m<3691:A,R}\n"
"stl{s<2701:R,m>3442:A,s<3282:A,A}\n"
"gsp{m<619:R,s<529:R,A}\n"
"fkk{x<3359:svx,sp}\n"
"dsk{x<1499:kn,xj}\n"
"jmx{m<1426:zq,fvz}\n"
"st{s>2257:slt,rvv}\n"
"prm{a<470:A,tts}\n"
"fkj{x<2514:R,x>2784:R,a>2830:R,qft}\n"
"bh{m<1740:mmf,a>503:zn,s>1702:vfp,fft}\n"
"rv{m<2642:A,sfv}\n"
"qk{s<1846:A,A}\n"
"nqr{a>786:ssx,qbh}\n"
"kng{a<3059:A,a<3463:A,a<3661:A,A}\n"
"tcd{m<3753:R,a<2566:pq,m<3792:R,hsq}\n"
"rhc{x>1415:mzt,x>1395:qp,x>1386:rk,nnq}\n"
"hn{x>3532:A,a>1227:R,a>1109:A,R}\n"
"btd{s<2462:ftz,A}\n"
"xv{s>1573:pv,m>730:pn,s<1201:vtz,fjk}\n"
"sm{a>787:R,R}\n"
"mqz{m<645:R,m<682:A,A}\n"
"rvv{m<867:vkv,a>556:R,mx}\n"
"fft{x>581:jb,a<314:R,R}\n"
"txz{s<1338:R,x>2633:A,m<1168:A,A}\n"
"pcq{x<1531:A,R}\n"
"kvj{s<2721:A,x>2637:A,R}\n"
"kfj{x<1129:kz,s>1501:zfm,pk}\n"
"rd{m<3742:A,A}\n"
"qft{x<2653:A,s>1281:A,A}\n"
"zzr{a<3875:R,m>249:A,a<3917:R,A}\n"
"nh{a>3744:zcn,gxg}\n"
"fsp{m>3306:R,R}\n"
"rt{m<310:zlk,qgj}\n"
"mpb{m>2954:R,R}\n"
"qgj{s>1083:R,m<502:A,s<949:A,A}\n"
"hq{x<1527:dfg,m>3017:jvm,a>947:jts,gqf}\n"
"bfc{x>1423:R,a<2789:A,A}\n"
"bnv{a>900:R,A}\n"
"tdr{a>518:R,m>657:A,x>2576:R,R}\n"
"jmm{a<3410:mq,fv}\n"
"qjr{a>2534:R,s<1365:A,m<261:A,R}\n"
"in{x<1624:zsf,ks}\n"
"jgs{m<702:R,A}\n"
"qg{a<1733:A,R}\n"
"pv{x<1559:hnp,x>1588:gbv,R}\n"
"rpx{m<2361:zv,A}\n"
"bzm{x<1510:rhc,x<1580:lct,m>3357:rrj,zld}\n"
"dnf{x>2931:xkp,s>1747:A,s<858:qhb,zf}\n"
"sk{x>3528:A,x<3113:bnx,psk}\n"
"xgt{s>2544:vn,sft}\n"
"kjv{s>1334:gsh,a>95:rbf,a>50:bmf,trd}\n"
"pvt{s>2784:A,s<2303:qk,a<1589:A,R}\n"
"nv{a>3108:R,x>1923:R,s>652:A,A}\n"
"nlg{m>383:A,s>1520:A,s>749:R,R}\n"
"lk{a<2425:R,s>598:R,a>2517:R,A}\n"
"nt{m>1682:R,m>999:A,m>428:A,A}\n"
"rmp{m>2634:R,s<317:nt,lk}\n"
"fs{m<2408:A,x<1842:R,R}\n"
"sjt{x<1133:nqr,vt}\n"
"tbk{m<2779:R,a>3554:R,a>3415:A,R}\n"
"jr{m>3312:A,R}\n"
"bmf{s<509:xxs,a<68:qxr,R}\n"
"xz{s<1845:A,x<1392:A,A}\n"
"tpn{m>2419:A,x>2999:A,s<2347:A,R}\n"
"fcg{a<196:A,m>1248:nbt,a>276:R,R}\n"
"kv{x>1467:R,m>891:R,s>2429:A,A}\n"
"rq{m>570:bft,x<1349:R,m<215:R,A}\n"
"cpr{s>140:cdl,m<2079:znj,prk}\n"
"fc{a<3507:R,x<1454:A,s<1296:A,A}\n"
"kfs{x<2459:R,A}\n"
"vr{m<3596:A,a<2837:R,A}\n"
"vg{a>3513:xl,x<569:sr,x>740:bp,qxs}\n"
"mzc{m<3026:R,a>1169:A,A}\n"
"jhk{m<3520:A,m<3692:A,a<701:R,A}\n"
"qx{s<1241:A,A}\n"
"bv{x<1412:zg,m<1721:hh,hq}\n"
"pj{s>3641:A,x>1535:mj,m<1145:A,jxb}\n"
"svx{x<3194:A,m<1734:gsp,m<2937:zk,kng}\n"
"kp{x<1404:jj,m>1015:R,x>1415:bfc,A}\n"
"cxh{m>619:R,m>536:A,R}\n"
"ffj{x<2728:R,s<231:A,R}\n"
"fh{m<1629:A,a<1260:A,A}\n"
"trd{a>29:qc,A}\n"
"hj{a<706:kvj,s<3197:grd,a>1057:mzc,gsx}\n"
"qcx{a<265:R,R}\n"
"bhz{x<1415:R,A}\n"
"ccq{a<3195:mtr,a<3700:jzv,x>1501:xv,tj}\n"
"qpn{s>499:vpz,a>804:qsc,lsm}\n"
"jk{x<3497:R,x>3734:A,A}\n"
"bz{x>568:A,a<773:A,R}\n"
"hkv{a<1753:R,x<2544:A,a>1849:R,ps}\n"
"gj{m>2405:fkd,s>1405:pf,qpn}\n"
"lg{a<1611:rlx,a<1731:fps,A}\n"
"ln{a<1637:R,s<3175:A,A}\n"
"shk{a<1729:htt,m>1833:R,A}\n"
"sct{m>1497:A,R}\n"
"rnj{a>2878:R,m>1475:R,a<2792:R,A}\n"
"qp{a<3308:R,m>3268:vv,A}\n"
"vq{s<2622:R,R}\n"
"nbt{s<1656:A,m<1413:R,m>1485:A,A}\n"
"bdm{x<2476:gv,x>2650:vhv,kh}\n"
"bjh{x<2660:R,A}\n"
"fnx{a<3874:A,A}\n"
"qzt{s>3620:A,A}\n"
"ft{a<1286:A,m>1846:R,R}\n"
"cx{a>2841:A,m<425:qjr,s>1229:qm,R}\n"
"rrj{m<3695:nm,m>3867:sz,a>3080:cd,tcd}\n"
"ghj{s<2416:A,m<2698:R,R}\n"
"xm{a<3638:pcq,m>2433:pnx,tsc}\n"
"hkg{a<1186:A,R}\n"
"ts{s>905:A,m<299:R,R}\n"
"dbf{m<1691:sct,s<3740:mnr,A}\n"
"ssq{s>3183:A,m<2388:A,A}\n"
"bd{s>291:jbg,s<217:R,s<250:ffj,vl}\n"
"dq{a<1136:R,R}\n"
"rpf{s>2706:ll,x<2910:ghj,A}\n"
"qxr{s<877:A,A}\n"
"lct{s>3272:kx,hcp}\n"
"bbc{a<3031:R,x<1554:A,R}\n"
"zlk{m>176:R,A}\n"
"lh{a<3217:fld,x<504:jr,rgg}\n"
"zct{x>2738:sk,x>2209:bdm,gdm}\n"
"dj{x>1137:A,a>2578:A,R}\n"
"gc{a>2861:R,a<2739:A,A}\n"
"lhn{s>2175:jz,m>1213:hcq,lxj}\n"
"qm{x<1501:R,s>1724:R,A}\n"
"bnx{s>3556:R,x<2924:A,a>2767:A,R}\n"
"zr{s<2643:A,ms}\n"
"smc{x<1354:R,x>1374:R,s>1279:fh,cxb}\n"
"jvm{s>1609:zmn,a<1172:jhk,cxl}\n"
"sz{s>3310:A,R}\n"
"bxf{a>2995:A,rnj}\n"
"qn{x>1577:A,R}\n"
"rm{x>3502:sm,x<3166:rzf,R}\n"
"zzd{a<2945:A,s<530:A,a<3360:A,A}\n"
"ns{x<1515:A,a<2501:A,R}\n"
"rnb{s<1360:A,m>2498:R,s<1805:R,A}\n"
"srj{x>1408:R,R}\n"
"jzv{m>750:ltd,s<1511:rt,tcc}\n"
"gps{a>3444:A,x>1039:R,x<989:R,A}\n"
"cmr{x<2302:A,R}\n"
"mgq{a>3431:A,m<2513:R,R}\n"
"zps{m<2495:R,x>1582:A,a>3314:R,A}\n"
"xj{s<2468:A,x>1516:A,a>3292:A,A}\n"
"hfv{a>2835:phz,x<1072:jc,dj}\n"
"vmf{a<2879:qdv,m<1506:xsn,x>2082:rr,xdq}\n"
"ndj{m>605:A,a>1367:R,A}\n"
"sd{x>1431:A,a<3334:A,s>3667:A,A}\n"
"fjt{a<2589:R,A}\n"
"slp{x<583:A,A}\n"
"jfx{s>639:R,s>549:R,zc}\n"
"zrc{m<2490:A,fsp}\n"
"sqf{s>3315:A,m<2054:A,R}\n"
"hlm{a<3112:R,m>1347:A,R}\n"
"bp{s>2210:A,R}\n"
"htt{a<1620:R,R}\n"
"lhg{x>1534:rb,m>1305:qmz,a>2889:dsk,rs}\n"
"cxl{a<1794:R,a<2060:R,m>3613:R,R}\n"
"lrt{x>1214:A,m<826:A,x<1148:R,A}\n"
"kdt{a>3422:A,a>3354:vx,a<3313:A,ff}\n"
"qc{s>566:R,a<43:R,A}\n"
"jnn{s>1664:zsx,m<3370:tmg,m<3740:R,lj}\n"
"rlx{s>2568:A,s>1841:R,x<2496:A,R}\n"
"cxb{x>1364:R,A}\n"
"vp{m<625:mt,m>1209:psm,prx}\n"
"jbz{x<1581:A,R}\n"
"fld{x>580:A,a<2939:vz,qt}\n"
"gz{m<2078:A,m>2102:A,m>2086:R,A}\n"
"pq{s<3162:R,s<3713:R,R}\n"
"nvr{a>3064:R,x>1573:A,a>2695:R,A}\n"
"mt{m<212:xgt,m<391:msk,a<1427:dh,nqj}\n"
"qq{m<1871:A,x>2374:A,m>2819:R,R}\n"
"kx{s>3712:R,a<3138:A,a>3552:A,sb}\n"
"zl{a<3279:R,s>3644:R,s<3369:R,A}\n"
"zhr{x>1414:mhr,s<1315:R,R}\n"
"lr{a<3472:fl,x<1240:qzt,m>1702:A,A}\n"
"zn{m>3032:bz,R}\n"
"kdb{m>2017:lh,vg}\n"
"xdq{a>3298:fs,s>454:nv,R}\n"
"jj{x<1385:R,s>2524:A,a<2778:R,R}\n"
"hh{s>1624:bqx,m<725:lf,m<1340:hkg,qkd}\n"
"tt{x>3601:A,R}\n"
"ff{m>2244:A,x>1175:R,s>652:A,A}\n"
"nb{m<2342:sx,s<1466:A,gc}\n"
"gg{x>2442:R,A}\n"
"zf{x>2749:A,R}\n"
"ms{a<3730:A,A}\n"
"pnx{a>3878:A,R}\n"
"thm{a<2994:R,m<2863:R,R}\n"
"dcn{x<1937:R,x>2071:A,m<1510:R,R}\n"
"zh{x<1391:A,a<2729:A,R}\n"
"mzt{m>3358:R,s>2801:thm,x>1477:kzl,A}\n"
"vk{x<1245:hfv,a<2636:rmp,ldb}\n"
"cdl{x>2787:A,A}\n"
"gsh{x>2372:A,s<2731:tgk,ng}\n"
"ss{s>1887:A,R}\n"
"lsm{a<346:qqd,s<179:pls,a<518:hxk,bd}\n"
"kl{m<767:cm,s>2943:hlm,s<2861:R,R}\n"
"jc{a>2461:R,R}\n"
"lq{x<3091:A,m>3019:R,s<338:R,A}\n"
"dc{m>3120:R,s<2936:R,A}\n"
"fjx{a<3729:R,m>577:bhz,A}\n"
"slh{s<2472:A,x>841:A,x>782:A,R}\n"
"jn{a>3008:A,m<154:R,A}\n"
"rnt{m<1544:fqb,pt}\n"
"lzl{a>2640:kk,s<3306:A,x<1073:R,kft}\n"
"rjm{a<2579:R,x<1122:A,x<1178:A,A}\n"
"xxn{a>3097:R,x>2616:R,x>2520:A,R}\n"
"gmk{a>432:rkd,m<699:mp,np}\n"
"gk{a<343:xnh,st}\n"
"mtr{m<974:cx,a>2634:lp,a>2480:mb,vvl}\n"
"sn{s<1735:R,x>3011:R,A}\n"
"hcp{m<2836:A,A}\n"
"bzv{m<2882:A,m>3102:A,x>1615:A,R}\n"
"gpf{a>786:vp,x>3204:gk,fgh}\n"
"bqh{x>1390:A,a<781:A,a<1479:R,A}\n"
"zk{s<581:R,a>3168:R,A}\n"
"rzf{x>2996:R,A}\n"
"pt{m>2840:R,sqf}\n"
"dr{a<1633:R,rx}\n"
"bj{m<2330:A,R}\n"
"rp{a<2416:A,x<1528:A,R}\n"
"fv{x<1478:zhr,xm}\n"
"zkq{s>2684:zct,jmx}\n"
"hg{x>1427:xkb,s>2386:R,s>2348:jgs,R}\n"
"ljp{x<3070:qmk,vkc}\n"
"qcd{x>2958:kq,m<1982:R,A}\n"
"dh{a<1030:A,x<2896:tns,s>1349:hn,A}\n"
"nn{a<2330:A,s<1631:A,x>1119:R,A}\n"
"tcc{x<1454:xz,s>1712:xb,x>1524:dvn,tb}\n"
"prd{m>3593:R,s<3539:A,A}\n"
"prx{s<1392:pm,a<1410:bxh,lg}\n"
"dnj{s>2561:zr,m>1174:nh,s<2439:hg,fjx}\n"
"ltr{s<2819:chr,x>3007:fmv,ndx}\n"
"zls{s<2833:R,x>2257:R,R}\n"
"tj{a>3851:bfb,gx}\n"
"cqn{x>1072:rjm,s<3160:ktb,fjt}\n"
"sps{a<845:gts,a>1373:hkv,s>1282:jnn,mcd}\n"
"pk{x>1234:A,s>1197:tr,x<1173:cl,R}\n"
"lp{a>3002:R,s>1470:R,m<1336:A,ksz}\n"
"bnl{a<1615:A,s<1889:R,a<2234:R,R}\n"
"px{x>2650:ln,m>3593:A,zls}\n"
"bqx{m<671:zvx,m>1076:A,x>1511:R,kv}\n"
"tg{x<1547:R,a>3186:A,a<2861:R,A}\n"
"bbv{x>1046:A,R}\n"
"nl{m>2498:A,s<1270:R,s>1844:R,R}\n"
"gxg{a<3560:A,A}\n"
"htm{a>1548:R,ft}\n"
"jzj{a<3414:R,s>2535:R,a<3803:A,R}\n"
"tl{m>591:R,s<2128:R,A}\n"
"lj{a>1135:R,A}\n"
"qt{x>217:A,a>3101:A,R}\n"
"zmn{x>1568:R,m<3662:A,s>2942:R,A}\n"
"gqf{a<319:A,lc}\n"
"pn{x<1566:fnx,R}\n"
"lm{x<748:A,m>1097:slh,mnc}\n"
"xb{a>3483:A,R}\n"
"hbn{x<2347:rz,s<1021:xxn,bj}\n"
"fps{s<2809:R,m>978:R,a<1677:R,A}\n"
"tns{m>508:A,R}\n"
"ftz{m<1047:A,R}\n"
"hsq{s<3306:A,R}\n"
"rcf{m<789:R,a>3811:A,R}\n"
"zsx{m<3362:A,A}\n"
"qnm{m<1707:jq,m>1918:A,klh}\n"
"ktb{a>2476:R,a<2324:R,m<1618:R,R}\n"
"tts{s<974:A,a>655:R,x>2433:A,A}\n"
"nf{a<3288:vk,zpd}\n"
"cj{x<1368:dll,m>2179:bzm,s<2729:ntm,qd}\n"
"vtz{s>967:zzr,x<1579:R,ts}\n"
"zv{a>3078:R,A}\n"
"xxs{a>80:R,m<655:R,A}\n"
"tsc{a<3864:A,a>3938:R,m>1924:R,R}\n"
"bf{x>2895:fkk,vmf}\n"
"rk{m>3266:R,m>2870:dc,a<3009:zh,mgq}\n"
"nqj{s>1829:R,s>913:vs,mnk}\n"
"fd{s<871:A,R}\n"
"mj{m>871:A,a>2639:R,a<2371:A,A}\n"
"qbm{m>1109:A,s>3601:R,x>1512:R,A}\n"
"dpc{m<2093:sgl,R}\n"
"vkc{a>3311:ghs,a>2714:bxf,rv}\n"
"sx{s>1313:R,A}\n"
"gl{x>1498:qbm,m<1020:rg,A}\n"
"jbx{a>706:R,x>2598:A,pb}\n"
"hxk{a>436:tgn,gs}\n"
"tpg{s>1250:R,m>1185:A,s<1173:A,R}\n"
"qdv{s<616:mkj,qq}\n"
"msk{a<1506:sn,s>2324:A,qg}\n"
"xjk{s>2290:R,R}\n"
"grd{s<2548:R,A}\n"
"xlg{s>3562:A,a>543:A,A}\n"
"xnh{x<3580:nr,m>777:fcg,m<313:vpk,vbp}\n"
"kh{m<1498:A,A}\n"
"zsf{x<948:mf,a<2235:fp,s>2045:cj,zhj}\n"
"xsm{s<799:R,x<1241:R,a>872:A,R}\n"
"xp{m<1016:R,R}\n"
"vpk{x<3813:tv,R}\n"
"rr{s<604:R,R}\n"
"slt{s<3054:tt,s>3473:A,R}\n"
"pxn{m<2918:R,R}\n"
"tqg{m>2713:gvv,x<1585:zps,A}\n"
"xl{a<3724:R,m<814:A,m<1249:R,R}\n"
"lqs{a<3226:pj,x<1533:gl,a>3574:nqz,cnm}\n"
"qhb{m>398:R,s>521:A,x<2791:A,R}\n"
"pp{a>3287:A,s<2490:R,a<3039:A,A}\n"
"klh{a>3097:A,a<2627:A,x>1416:A,R}\n"
"kzl{x>1498:A,R}\n"
"cd{m>3789:R,s>2774:rd,jjh}\n"
"qvj{s>2916:lb,m>1773:gg,A}\n"
"nm{m<3503:stl,a>3204:jtx,s<3198:vr,prd}\n"
"zfm{a<3405:cf,x>1270:dk,A}\n"
"dll{a>2858:kr,x<1210:cq,rnt}\n"
"zvx{m<440:A,R}\n"
"rs{s>2487:A,m>583:A,m<352:zvt,ns}\n"
"gv{x>2386:A,x<2306:A,A}\n"
"tsg{x>1593:R,A}\n"
"bft{m<1111:R,A}\n"
"zld{x<1595:tqg,a<3278:pxn,ds}\n"
"nlj{s<37:A,R}\n"
"dd{m<360:jn,x<1406:xlx,zl}\n"
"xkp{a>723:R,a>685:A,a>649:A,A}\n"
"phz{a>3010:R,R}\n"
"zvv{m>587:btd,m<276:jbx,x>2637:dnf,smg}\n"
"ldb{s>500:R,s<176:A,x>1432:svj,sv}\n"
"gm{m<544:dd,sd}\n"
"rrp{s>3471:dbf,qnm}\n"
"tgk{s>1833:R,m>698:A,a<170:A,A}\n"
"tf{a<2989:R,s<2648:R,m<978:A,A}\n"
"jv{a>1049:bk,bh}\n"
"zjq{x<394:A,s<2172:A,x>409:R,A}\n"
"sb{a>3392:A,s<3499:A,s<3590:A,A}\n"
"gbv{s>1783:R,m<518:A,R}\n"
"mb{a<2566:R,A}\n"
"jbg{x<2977:A,R}\n"
"cq{m>2591:lzl,cqn}\n"
"gpp{s>127:A,R}\n"
"qxs{x<630:R,R}\n"
"ltd{m<1040:fc,s<1339:R,fzh}\n"
"tv{m<191:R,R}\n"
"vbp{m>508:A,a<198:hc,m<391:R,qcx}\n"
"qhx{s<1393:A,A}\n"
"zt{x<829:A,s>2272:A,m>3119:R,A}\n"
"xlx{s<3549:R,s<3703:R,a<2825:A,A}\n"
"mnc{m>410:R,x<820:R,A}\n"
"jts{s>2528:A,a>1459:A,nl}\n"
"vfp{a<268:slp,a<349:A,A}\n"
"xkb{s>2400:A,a>3661:R,s<2364:A,R}\n"
"jxb{x>1512:R,m>1668:R,s<3371:R,A}\n"
"jjh{s>2302:A,s<2157:R,R}\n"
"dfg{m<3080:bnv,R}\n"
"sft{m>85:R,A}\n"
"kft{s<3765:R,x<1151:A,A}\n"
"ql{m<2989:bnl,A}\n"
"hmq{s>328:A,R}\n"
"zgl{s<3038:xp,s>3136:R,tg}\n"
"jz{x<1535:nz,vcx}\n"
"fpp{a<1269:A,s<2540:R,m<877:A,A}\n"
"sl{x<1465:kl,zgl}\n"
"ghs{s<1180:jk,A}\n"
"gdm{s<3410:A,dcn}\n"
"mp{a>355:nlg,x>2257:A,R}\n"
"tgn{s>384:A,A}\n"
"rck{a>3096:A,m<729:R,R}\n"
"bfh{s<2430:A,A}\n"
"dm{x<3740:A,a<84:A,R}\n"
"cl{x>1152:A,a>3659:A,A}\n"
"lf{s<590:A,m<384:dz,ndj}\n"
"kr{s<3089:tk,x>1116:lr,fq}\n"
"ps{x<3131:R,a>1808:R,R}\n"
"zc{a<3742:R,s<459:A,A}\n"
"hdq{a>1180:A,a<969:A,m<1327:xjk,vxc}\n"
"vtn{x>2571:gz,A}\n"
"vsp{m<1477:kf,m>1506:A,x<1988:A,R}\n"
"pf{m<1916:zj,nsl}\n"
"qqb{a<3381:R,a<3544:A,R}\n"
"qmk{s>1137:fkj,hbn}\n"
"fjk{m<484:qhx,s>1346:mqz,a<3843:qn,cxh}\n"
"fzh{a>3465:R,s<1753:A,R}\n"
"ll{a<1599:A,m>2800:R,m<2548:R,R}\n"
"pm{x<2958:A,A}\n"
"ds{s>3322:A,x>1607:bzv,s<2559:A,tbk}\n"
"qqd{a>147:xxr,x<2716:hmq,x<3308:R,dm}\n"
"zj{x>2856:rm,a>694:qvj,jkr}\n"
"ntm{s<2328:lhn,x>1477:lhg,a<3351:pd,dnj}\n"
"gs{x>3009:R,m>1822:R,m>1623:A,A}\n"
"vpz{a<955:prm,htm}\n"
"fl{s<3647:A,R}\n"
"vf{m>1405:R,x<364:R,x<439:zjq,A}\n"
"sfv{m>3249:R,a<2323:A,a<2508:A,R}\n"
"ssx{s<1450:R,R}\n"
"xtx{s<2531:bfh,tf}\n"
"fvz{s<1875:R,a<2683:tpn,s<2272:kfs,pp}\n"
"zpd{s<374:gpp,a<3568:kdt,jfx}\n"
"bq{a>2468:A,R}\n"
"mx{x>3691:R,A}\n"
"zvt{m<232:R,x<1498:R,R}\n"
"qbh{a>359:bbv,A}\n"
"rx{s<1895:R,x<93:A,R}\n"
"pls{s<102:nlj,m>1957:A,x>2610:R,R}\n"
"gxz{x<1441:A,a>3782:A,a<3736:A,A}\n"
"vcx{x<1581:A,x>1598:R,A}\n"
"mnk{x>2686:R,A}\n"
"hc{m>386:R,s<1896:R,x>3841:A,R}\n"
"jkr{x<2289:R,a<434:bjh,s>2706:xlg,ddr}\n"
"lxj{x<1526:A,a<2868:tl,s<2105:A,R}\n"
"cs{s>2587:A,s<2454:R,x>1605:A,A}\n"
"tb{a<3403:R,x<1483:A,m<408:A,R}\n"
"jrk{x<1493:R,A}\n"
"np{s<2392:txz,R}\n"
"fgh{a<278:kjv,a>610:zvv,gmk}\n"
"nsl{a>1286:pvt,m>2128:ltr,m<2048:qcd,vtn}\n"
"sp{x<3783:zzd,R}\n"
"mnr{a<2963:R,R}\n"
"kn{s>2492:R,R}\n"
"sg{x>3309:R,A}\n"
"kf{x>1948:A,A}\n"
"sv{x>1311:A,m>2072:A,R}\n"
"ddr{a>588:R,A}\n"
"mmf{s>1614:A,a<588:fd,s>637:A,R}\n"
"mzd{a>3041:kfj,hjp}\n"
"jb{x>749:A,x<663:R,a<217:R,A}\n"
"zq{x<2680:rck,zd}\n"
"kk{s>3062:A,x<1054:R,x>1150:R,A}\n"
"mcd{s>737:R,lq}\n"
"km{a<454:ssq,x>1215:A,R}\n"
"jp{m>1384:R,a>1361:A,m<1302:R,A}\n"
"zcn{m>1641:A,x<1412:R,a<3907:R,R}\n"
"hnp{m<624:R,m<1118:R,a>3867:A,A}\n"
"vvl{a>2360:jrk,A}\n"
"vt{a>1209:zrc,s>2239:km,a>526:db,rnb}\n"
"xsn{a<3485:A,x>2424:rcf,x<2143:R,cmr}\n"
"fmv{m>2241:A,A}\n"
"mq{a<2726:rp,rpx}\n"
"qsc{a>1561:shk,s>289:dpc,cpr}\n"
"vn{x<2495:A,R}\n"
"zhj{s<820:nf,x<1349:mzd,m<1523:ccq,jmm}\n"
"rb{x>1585:cs,x<1567:bbc,m>1281:nvr,R}\n"
"vl{a<701:A,a<749:R,R}\n"
"bk{m>2181:ql,x>534:lm,x>246:vf,dr}\n"
"bt{s<1575:R,x>1110:lrt,A}\n"
"cg{x<1226:R,R}\n"
"pb{s>1976:R,R}\n"
"qmz{x>1511:R,hx}\n"
"hx{s<2479:A,a>3026:R,x>1492:A,R}\n"
"vxc{s<1908:R,R}\n"
"psm{x>2500:vmq,m<1395:hdq,vsp}\n"
"bg{s>1448:zkq,s<952:bf,ljp}\n"
"rg{a<3524:R,R}\n"
"mxf{a<1247:hj,m<3013:rpf,px}\n"
"cnm{m<854:A,s>3702:A,A}\n"
"fjd{m>911:A,s>2513:bq,A}\n"
"mkj{x>2290:R,m<1691:A,s>347:A,A}\n"
"vhv{s>3440:A,x<2695:R,R}\n"
"hcq{a>2835:R,R}\n"
"vmq{s>2256:A,s<1332:jp,x<3237:ss,A}\n"
"nz{a<3118:A,x<1466:R,s<2259:A,R}\n"
"ndx{m>2236:R,x>2459:A,s<3532:R,A}\n"
"kz{s<1342:R,R}\n"
"lb{s>3471:A,a>1457:A,A}\n"
"vz{a>2782:R,A}\n"
"cm{a<3264:R,a>3609:R,A}\n"
"nqz{s>3591:R,m>1381:jbz,m<596:A,tsg}\n"
"dk{x<1297:A,a>3642:R,A}\n"
"mf{a<2621:jv,kdb}\n"
"lc{x<1574:A,m>2523:R,a<541:A,A}\n"
"cf{a<3177:R,R}\n"
"rgg{x>754:zt,a<3650:qqb,mpb}\n"
"fq{s<3534:R,s<3736:gps,R}\n"
"bfb{s>1404:R,s>1128:R,srj}\n"
"\n"
"{x=61,m=577,a=1750,s=1892}\n"
"{x=8,m=603,a=567,s=987}\n"
"{x=1398,m=1265,a=702,s=949}\n"
"{x=2322,m=693,a=2401,s=946}\n"
"{x=348,m=2812,a=613,s=1788}\n"
"{x=3353,m=2070,a=1617,s=3088}\n"
"{x=24,m=963,a=4,s=1053}\n"
"{x=396,m=877,a=3375,s=127}\n"
"{x=1490,m=100,a=1060,s=724}\n"
"{x=413,m=95,a=944,s=847}\n"
"{x=1580,m=960,a=880,s=1400}\n"
"{x=1956,m=597,a=3294,s=284}\n"
"{x=1924,m=21,a=726,s=1276}\n"
"{x=1338,m=1630,a=348,s=114}\n"
"{x=11,m=1649,a=475,s=1091}\n"
"{x=1660,m=563,a=1047,s=150}\n"
"{x=18,m=226,a=33,s=3744}\n"
"{x=3145,m=482,a=866,s=629}\n"
"{x=474,m=260,a=1408,s=9}\n"
"{x=361,m=1348,a=592,s=380}\n"
"{x=2632,m=1281,a=234,s=1114}\n"
"{x=1871,m=543,a=1285,s=383}\n"
"{x=1870,m=364,a=106,s=70}\n"
"{x=536,m=528,a=272,s=2050}\n"
"{x=1519,m=1564,a=434,s=103}\n"
"{x=301,m=2005,a=1069,s=79}\n"
"{x=293,m=143,a=3201,s=68}\n"
"{x=1308,m=1701,a=271,s=1627}\n"
"{x=1538,m=1576,a=249,s=290}\n"
"{x=320,m=110,a=1490,s=492}\n"
"{x=494,m=904,a=2049,s=1122}\n"
"{x=13,m=695,a=1851,s=145}\n"
"{x=136,m=1102,a=90,s=879}\n"
"{x=1786,m=8,a=663,s=86}\n"
"{x=238,m=2582,a=1288,s=3169}\n"
"{x=1628,m=1807,a=373,s=116}\n"
"{x=86,m=51,a=500,s=1893}\n"
"{x=2848,m=36,a=2897,s=1757}\n"
"{x=774,m=530,a=970,s=2379}\n"
"{x=353,m=1490,a=844,s=2085}\n"
"{x=1363,m=938,a=1103,s=1200}\n"
"{x=1843,m=6,a=1853,s=882}\n"
"{x=1966,m=3149,a=327,s=201}\n"
"{x=1116,m=849,a=1822,s=326}\n"
"{x=233,m=3172,a=32,s=1141}\n"
"{x=3523,m=19,a=38,s=176}\n"
"{x=2896,m=511,a=1180,s=2859}\n"
"{x=292,m=843,a=98,s=98}\n"
"{x=923,m=606,a=2898,s=2343}\n"
"{x=46,m=1317,a=78,s=51}\n"
"{x=462,m=1255,a=1485,s=737}\n"
"{x=1238,m=1292,a=27,s=1525}\n"
"{x=2731,m=411,a=1831,s=1574}\n"
"{x=202,m=426,a=483,s=349}\n"
"{x=33,m=394,a=941,s=1705}\n"
"{x=2648,m=510,a=703,s=2332}\n"
"{x=1429,m=836,a=316,s=63}\n"
"{x=2817,m=1701,a=174,s=160}\n"
"{x=261,m=206,a=76,s=2192}\n"
"{x=204,m=2989,a=283,s=597}\n"
"{x=1068,m=1881,a=3293,s=2503}\n"
"{x=31,m=37,a=826,s=2983}\n"
"{x=547,m=466,a=1586,s=481}\n"
"{x=1419,m=822,a=273,s=1670}\n"
"{x=392,m=168,a=452,s=61}\n"
"{x=1245,m=2719,a=778,s=2034}\n"
"{x=1150,m=1565,a=1098,s=502}\n"
"{x=1180,m=30,a=1228,s=223}\n"
"{x=727,m=6,a=224,s=144}\n"
"{x=1784,m=863,a=741,s=1461}\n"
"{x=1200,m=1331,a=113,s=1114}\n"
"{x=3108,m=312,a=246,s=1943}\n"
"{x=970,m=1845,a=3752,s=940}\n"
"{x=2062,m=420,a=290,s=264}\n"
"{x=1626,m=1844,a=337,s=321}\n"
"{x=1124,m=1302,a=335,s=1250}\n"
"{x=205,m=203,a=102,s=292}\n"
"{x=228,m=1798,a=562,s=326}\n"
"{x=897,m=832,a=1193,s=1826}\n"
"{x=336,m=1941,a=1348,s=2270}\n"
"{x=162,m=275,a=3043,s=1022}\n"
"{x=361,m=268,a=2199,s=1749}\n"
"{x=328,m=1482,a=1865,s=1420}\n"
"{x=474,m=2434,a=2447,s=1199}\n"
"{x=1066,m=3051,a=1482,s=50}\n"
"{x=252,m=1317,a=349,s=894}\n"
"{x=1241,m=283,a=3431,s=503}\n"
"{x=958,m=403,a=928,s=487}\n"
"{x=1193,m=830,a=3266,s=2617}\n"
"{x=914,m=1239,a=275,s=3325}\n"
"{x=2885,m=1206,a=1998,s=313}\n"
"{x=831,m=1327,a=447,s=181}\n"
"{x=3912,m=2397,a=522,s=1136}\n"
"{x=2222,m=375,a=1129,s=595}\n"
"{x=3340,m=205,a=1197,s=1910}\n"
"{x=2206,m=20,a=1354,s=63}\n"
"{x=1068,m=916,a=10,s=1564}\n"
"{x=316,m=827,a=371,s=1808}\n"
"{x=3287,m=329,a=2730,s=22}\n"
"{x=863,m=2792,a=321,s=1546}\n"
"{x=1470,m=301,a=795,s=249}\n"
"{x=582,m=96,a=2814,s=1126}\n"
"{x=387,m=461,a=1526,s=355}\n"
"{x=23,m=1590,a=1448,s=269}\n"
"{x=1983,m=165,a=714,s=1140}\n"
"{x=513,m=1006,a=835,s=1438}\n"
"{x=25,m=280,a=1263,s=2950}\n"
"{x=823,m=973,a=949,s=166}\n"
"{x=720,m=255,a=92,s=184}\n"
"{x=867,m=1262,a=153,s=569}\n"
"{x=443,m=376,a=4,s=656}\n"
"{x=108,m=600,a=958,s=64}\n"
"{x=609,m=1212,a=3436,s=1060}\n"
"{x=267,m=645,a=2807,s=959}\n"
"{x=159,m=2,a=557,s=1673}\n"
"{x=2744,m=49,a=49,s=2043}\n"
"{x=835,m=33,a=1119,s=440}\n"
"{x=2697,m=499,a=386,s=1553}\n"
"{x=456,m=110,a=666,s=625}\n"
"{x=1274,m=1335,a=336,s=124}\n"
"{x=2341,m=1835,a=100,s=2163}\n"
"{x=2104,m=1161,a=234,s=1831}\n"
"{x=915,m=1660,a=792,s=429}\n"
"{x=314,m=384,a=33,s=294}\n"
"{x=628,m=579,a=2605,s=1746}\n"
"{x=2,m=2227,a=1151,s=38}\n"
"{x=294,m=1196,a=1330,s=295}\n"
"{x=517,m=2634,a=994,s=267}\n"
"{x=272,m=25,a=882,s=217}\n"
"{x=599,m=652,a=951,s=126}\n"
"{x=255,m=650,a=955,s=102}\n"
"{x=25,m=1704,a=2216,s=13}\n"
"{x=142,m=817,a=208,s=921}\n"
"{x=1932,m=746,a=1646,s=2252}\n"
"{x=1157,m=6,a=2213,s=3366}\n"
"{x=595,m=10,a=2,s=2750}\n"
"{x=696,m=955,a=3215,s=8}\n"
"{x=2223,m=3582,a=47,s=1055}\n"
"{x=302,m=330,a=420,s=495}\n"
"{x=128,m=2241,a=1155,s=387}\n"
"{x=225,m=151,a=682,s=916}\n"
"{x=844,m=181,a=1842,s=2310}\n"
"{x=270,m=837,a=1311,s=2122}\n"
"{x=3135,m=829,a=1974,s=164}\n"
"{x=1061,m=1019,a=2238,s=571}\n"
"{x=2109,m=1065,a=316,s=1054}\n"
"{x=1523,m=512,a=42,s=342}\n"
"{x=1378,m=2105,a=1968,s=3674}\n"
"{x=51,m=94,a=683,s=832}\n"
"{x=235,m=1036,a=121,s=741}\n"
"{x=18,m=713,a=250,s=484}\n"
"{x=193,m=2650,a=569,s=210}\n"
"{x=1203,m=2854,a=644,s=515}\n"
"{x=3,m=881,a=967,s=1500}\n"
"{x=375,m=2028,a=214,s=135}\n"
"{x=1693,m=696,a=2186,s=138}\n"
"{x=1347,m=655,a=722,s=111}\n"
"{x=678,m=995,a=3274,s=183}\n"
"{x=1720,m=242,a=1637,s=933}\n"
"{x=798,m=1710,a=3735,s=1521}\n"
"{x=3046,m=335,a=1055,s=296}\n"
"{x=632,m=6,a=207,s=591}\n"
"{x=109,m=2344,a=40,s=413}\n"
"{x=387,m=121,a=171,s=2554}\n"
"{x=1546,m=159,a=2373,s=1578}\n"
"{x=875,m=21,a=377,s=2524}\n"
"{x=1641,m=1125,a=694,s=2737}\n"
"{x=188,m=310,a=378,s=498}\n"
"{x=589,m=174,a=2495,s=2769}\n"
"{x=2918,m=258,a=643,s=47}\n"
"{x=833,m=214,a=333,s=24}\n"
"{x=1982,m=200,a=569,s=1014}\n"
"{x=341,m=196,a=1404,s=286}\n"
"{x=1009,m=248,a=281,s=1903}\n"
"{x=547,m=2531,a=215,s=117}\n"
"{x=904,m=249,a=46,s=109}\n"
"{x=186,m=1706,a=1307,s=732}\n"
"{x=1182,m=1615,a=299,s=1275}\n"
"{x=2136,m=1349,a=1907,s=523}\n"
"{x=13,m=1375,a=1617,s=1599}\n"
"{x=786,m=131,a=541,s=67}\n"
"{x=12,m=223,a=1565,s=129}\n"
"{x=837,m=261,a=22,s=363}\n"
"{x=1011,m=249,a=146,s=251}\n"
"{x=711,m=230,a=3042,s=246}\n"
"{x=2794,m=1052,a=243,s=457}\n"
"{x=2289,m=1093,a=2061,s=1219}\n"
"{x=2223,m=176,a=1227,s=444}\n"
"{x=1744,m=37,a=1590,s=87}\n"
"{x=2590,m=2444,a=894,s=1864}\n"
"{x=13,m=1356,a=648,s=121}\n"
"{x=117,m=125,a=1222,s=669}\n"
"{x=1048,m=419,a=1031,s=210}\n"
"{x=397,m=2126,a=412,s=977}\n"
"{x=1256,m=875,a=3898,s=3195}\n"
"{x=3273,m=322,a=702,s=4}\n"
"{x=956,m=500,a=522,s=596}\n"
"{x=339,m=1107,a=2588,s=970}\n"
"{x=493,m=43,a=1683,s=1244}\n"
"{x=303,m=484,a=425,s=207}\n"

;

bool toUnsigned(const std::string& s, unsigned long& res) {
    try {
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

enum class Feature : unsigned { Xcool, Music, AeroDyn, Shiny, NoRule };
constexpr auto FourFeat = 4U; // number of possible features.

template<typename E>
constexpr auto toUnderlying(const E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

std::string featToStr(Feature f)
{
    using std::literals::string_literals::operator""s;
    switch (f) {
    case Feature::Xcool:
        return "_x_";
    case Feature::Music:
        return "_m_";
    case Feature::AeroDyn:
        return "_a_";
    case Feature::Shiny:
        return "_s_";
    case Feature::NoRule:
        return "NoRule";
    default:
        throw std::runtime_error(
            "Inconsistent feature to print: "s + std::to_string(toUnderlying(f)));
    }
}

Feature charToFeat(const char ch)
{
    switch (ch) {
    case 'a':
        return Feature::AeroDyn;
    case 'm':
        return Feature::Music;
    case 's':
        return Feature::Shiny;
    case 'x':
        return Feature::Xcool;
    default:
        return Feature::NoRule;
    }
}

using Value = unsigned long;

struct Rule {
    Feature feature;
    bool higher;
    Value threshold;

    std::string dest; //'A' and 'R' special values.
};

using CombCount = unsigned long;

using Workflow = std::list<Rule>;
using Workflows = std::map<std::string, Workflow>;

using Thresholds = std::array<Value, FourFeat>;

struct Range {
    Thresholds minValues;
    Thresholds maxValues;

    Workflows::const_iterator itW;

    Workflow::const_iterator itRule;
};

} // namespace

auto day19Part2(std::string_view streamSource, bool sourceIsFilePath)
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

    // std::vector<std::string> lines;

    using Part = std::array<Value, FourFeat>;

    Workflows workflows;
    std::list<Part> parts;
    // This is used to allow mixed workflows and parts, otherwise they
    // can be managed on the fly after having acquired the workflows.

    bool listingParts = false; // workflow first.
    unsigned long ruleCount = 0U;

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

        if (line.empty()) {
            if (!parts.empty()) {
                std::cout << "WARNING: empty line after some part\n";
            }

            listingParts = true;
        } else if (line[0] == '{') {
            if (!listingParts) {
                std::cout << "WARNING: part not after an empty line\n";
            }

            // a Part
            if ((line.front() != '{') || (line.back() != '}')) {
                throw std::invalid_argument(errorLine + "part without compound");
            }

            Part part;

            std::set<Feature> featFound;

            size_t featIndex = 0U;

            size_t pOpen = 0U;
            while (pOpen < line.length() - 1U) {
                ++featIndex;

                Feature feat = charToFeat(line[pOpen + 1U]);
                if (feat == Feature::NoRule) {
                    throw std::invalid_argument(
                        errorLine + "unexpected code for the feature: "
                        + std::string(1U, line[pOpen + 1U]));
                }

                if (featFound.count(feat)) {
                    throw std::invalid_argument(
                        errorLine + "part with repeated " + featToStr(feat));
                }
                featFound.insert(feat);

                if (line[pOpen + 2U] != '=') {
                    throw std::invalid_argument(
                        errorLine + "part without '=' for " + featToStr(feat));
                }

                auto pClose = line.find(',', pOpen + 1U);
                if (pClose == std::string::npos) {
                    pClose = line.find('}', pOpen);
                    if (pClose == std::string::npos) {
                        throw std::runtime_error( // runtime because '}' has been checked above.
                            errorLine + "part without end: n. " + std::to_string(featIndex));
                    }
                }

                std::string vStr = line.substr(pOpen + 3U, pClose - (pOpen + 3U));

                Value val{};

                if (!toUnsigned(vStr, val)) {
                    throw std::invalid_argument(
                        errorLine + "part with non-positive value for " + featToStr(feat));
                }

                part.at(toUnderlying(feat)) = val;

                pOpen = pClose;
            }

            if ((pOpen != line.length() - 1U) || (line[pOpen] != '}')) {
                throw std::invalid_argument(errorLine + "part not ending with '}");
            }

            if (featFound.size() != FourFeat) {
                throw std::invalid_argument(errorLine + "part with some missing feature");
            }

            parts.push_back(part);
        } else {
            if (listingParts) {
                std::cout << "WARNING: workflow after an empty line\n";
            }

            // A workflow
            Workflow wf;

            auto pOpen = line.find('{');
            if (pOpen == std::string::npos) {
                throw std::invalid_argument(errorLine + "workflow without opening '{'");
            }

            std::string name = line.substr(0U, pOpen);

            bool lastRuleNoCond = false;

            size_t ruleIndex = 0U;

            while (pOpen < line.length() - 1U) {
                ++ruleIndex;

                // search comma or closure
                auto pClose = line.find(',', pOpen + 1U);
                if (pClose == std::string::npos) {
                    pClose = line.find('}', pOpen);
                    if (pClose == std::string::npos) {
                        throw std::invalid_argument(errorLine + "workflow without closing '}'");
                    }
                }

                Feature feat{};
                bool higher{};
                Value thres{};
                std::string dest;

                auto pCol = line.find(':', pOpen);
                if (pCol < pClose) {
                    if (pCol + 3U >= pClose + 3U) {
                        throw std::invalid_argument(
                            errorLine + "rule with too few data: n. "
                            + std::to_string(ruleIndex));
                    }

                    feat = charToFeat(line[pOpen + 1U]);
                    if (feat == Feature::NoRule) {
                        throw std::invalid_argument(
                            errorLine + "unexpected code for the feature: "
                            + std::string(1U, line[pOpen + 1U]) + " ; rule n. "
                            + std::to_string(ruleIndex));
                    }

                    switch (line[pOpen + 2U]) {
                    case '<':
                        higher = false;
                        break;
                    case '>':
                        higher = true;
                        break;
                    default:
                        throw std::invalid_argument(
                            errorLine + "unexpected comparison sign ("
                            + std::string(1U, line[pOpen + 2U])
                            + ") for the rule n.: " + std::to_string(ruleIndex));
                    }

                    std::string thStr = line.substr(pOpen + 3U, pCol - (pOpen + 3U));
                    if (!toUnsigned(thStr, thres)) {
                        throw std::invalid_argument(
                            errorLine + "non-positive threshold value for rule n. "
                            + std::to_string(ruleIndex));
                    }

                    pOpen = pCol; // aimed at sharing code to extract destination name.
                } else {
                    feat = Feature::NoRule;
                }

                dest = line.substr(pOpen + 1U, pClose - (pOpen + 1U));

                wf.push_back(Rule{feat, higher, thres, dest});
                ++ruleCount;
                lastRuleNoCond = (feat == Feature::NoRule);

                pOpen = pClose;
            }

            if ((pOpen != line.length() - 1U) || (line[pOpen] != '}')) {
                throw std::invalid_argument(errorLine + "workflow not ending with '}");
            }

            if (!lastRuleNoCond) {
                // includes check of non-empty list.
                throw std::invalid_argument(
                    errorLine + "workflow not ending with an always-rule");
            }

            workflows[name] = std::move(wf);
        }

        // lines.push_back(std::move(line));
    }

    const auto itIn = workflows.find("in");
    if (itIn == workflows.end()) {
        throw std::invalid_argument("Absent workflow named 'in'");
    }

    // Apply a stack of residual try, each with a Value of combination
    // to consider.
    std::stack<Range> rangesToTry;

    constexpr Value MaxValue = 4000U;

    {
        Thresholds ones;
        Thresholds maxs;
        for (unsigned i = 0; i < FourFeat; ++i) {
            ones.at(i) = 1U;
            maxs.at(i) = MaxValue;
        }

        rangesToTry.push(Range{ones, maxs, itIn, itIn->second.cbegin()});
    }

    static const auto compWorflows
        = [](const Workflows::const_iterator& cIt1, const Workflows::const_iterator& cIt2) {
                return cIt1->first < cIt2->first; // keys in workflows map is unique.
            };
    std::set<Workflows::const_iterator, decltype(compWorflows)> wfSet( // TODO: unordered_set
        compWorflows); // to check cycles.
    wfSet.insert(itIn);

    std::list<Range> acceptedRanges;
    size_t rejectedRanges = 0U;
    size_t rejectForCycle = 0U;

    CombCount res = 0U;

    while (!rangesToTry.empty()) {
        // pop a range
        auto range = rangesToTry.top();
        rangesToTry.pop();

        wfSet.erase(range.itW);

        // const auto itW = range.itW; never used
        const auto itRule = range.itRule;

        const auto& rule = *itRule;

        const auto thres = rule.threshold;
        const auto feat = rule.feature;
        const auto higher = rule.higher;

        bool matchedRule = false;

        if (feat == Feature::NoRule) {
            matchedRule = true;
        } else {
            // based on the rule, break the range in two parts, once
            // accepted and one refused.
            auto i = toUnderlying(feat);
            Value min1 = range.minValues.at(i);
            Value max1 = thres;

            Value min2 = thres;
            Value max2 = range.maxValues.at(i);

            if (higher) {
                ++min2;
            } else {
                if (max1 == 0U) {
                    throw std::runtime_error("zero threshold not managed!");
                }
                --max1;

                // swap so that the second range is the one to move to another workflow.
                std::swap(min1, min2);
                std::swap(max1, max2);
            }

            if (min1 <= max1) {
                range.minValues.at(i) = min1;
                range.maxValues.at(i) = max1;
                range.itRule++; // next rule for non-matched.

                if (range.itRule == range.itW->second.end()) {
                    throw std::runtime_error("incosistent execution: ended rules!");
                }

                rangesToTry.push(range);
                if (!wfSet.insert(range.itW).second) {
                    // found a cycle.
                    ++rejectForCycle;

                    // just consider as not accepted.
                    rangesToTry.pop();
                }
            }

            if (min2 <= max2) {
                range.minValues.at(i) = min2;
                range.maxValues.at(i) = max2;
                matchedRule = true;
            }
        }

        if (matchedRule) {
            if (rule.dest == "A") {
                acceptedRanges.push_back(range);
                // no changes to rangesToTry.
            } else if (rule.dest == "R") {
                ++rejectedRanges;
                // no changes to rangesToTry.
            } else {
                const auto itWnew = workflows.find(itRule->dest);
                if (itWnew == workflows.end()) {
                    throw std::invalid_argument(
                        "Absent workflow named " + itRule->dest + " invoked from "
                        + range.itW->first);
                }
                range.itW = itWnew;
                range.itRule = itWnew->second.cbegin();

                rangesToTry.push(range);
                if (!wfSet.insert(range.itW).second) {
                    // found a cycle.
                    ++rejectForCycle;

                    // just consider as not accepted.
                    rangesToTry.pop();
                }
            }
        }
    }

    for (const auto& range : acceptedRanges) {
        Value partial = 1U;
        for (unsigned i = 0; i < FourFeat; ++i) {
            auto factor = range.maxValues.at(i) - range.minValues.at(i) + 1U;
            if (factor > std::numeric_limits<Value>::max() / factor) {
                throw std::runtime_error("Type Value to be enlarged");
            }
            partial *= factor;
        }

        if (partial > std::numeric_limits<CombCount>::max() - res) {
            throw std::runtime_error("Type CombCount to be enlarged");
        }
        res += partial;
    }

    std::cout << "Lines count " << lineCount << std::endl;
    std::cout << "Workflow count " << workflows.size() << std::endl;
    std::cout << "Rule count " << ruleCount << std::endl;
    std::cout << "Accepted ranges " << acceptedRanges.size() << std::endl;
    std::cout << "Rejected ranges " << rejectedRanges << std::endl;
    std::cout << "Further rejected ranges for cycle " << rejectForCycle << std::endl;
    std::cout << "\nResult: " << res << std::endl;
    return res;
}

int main()
{
    try {
        day19Part2(Input, false);
        // day19Part2("./19_input_file.txt",true);
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
Lines count 17
Workflow count 11
Rule count 25
Accepted ranges 9
Rejected ranges 6
Further rejected ranges for cycle 0
Result: 167409079868000

Real input:
Lines count 718
Workflow count 517
Rule count 1540
Accepted ranges 524
Rejected ranges 500
Further rejected ranges for cycle 0
Result: 138625360533574
*/
