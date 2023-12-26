#include <algorithm>
#include <array>
#include <cmath>
#include <exception>
#include <fstream>
#include <cfenv>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace{

constexpr std::string_view Input =

false ?

"LR\n"
"\n"
"11A = (11B, XXX)\n"
"11B = (XXX, 11Z)\n"
"11Z = (11B, XXX)\n"
"22A = (22B, XXX)\n"
"22B = (22C, 22C)\n"
"22C = (22Z, 22Z)\n"
"22Z = (22B, 22B)\n"
"XXX = (XXX, XXX)\n"

:

"LRRRLRLLLLLLLRLRLRRLRRRLRRLRRRLRRLRRRLLRRRLRRLRLRRRLRRLRRRLLRLLRRRLRRRLRLLRLRLRRRLRRLRRLRRLRLRRRLRRLRRRLLRLLRLLRRLRLLRLRRLRLRLRRLRRRLLLRRLRRRLLRRLRLRLRRRLRLRRRLLRLLLRRRLLLRRLLRLLRRLLRLRRRLRLRRLRRLLRRLRLLRLRRRLRRRLRLRRRLRLRLRRLRLRRRLRRRLRRRLRRLRRLRRRLLRLRLLRLLRRRR\n"
"HVX = (SCS, XQN)\n"
"DMK = (JKL, JKL)\n"
"FDF = (XHL, RMM)\n"
"JTK = (SVN, DVP)\n"
"QCF = (FCH, FCH)\n"
"TCG = (VMS, SDL)\n"
"JJP = (FQJ, RLT)\n"
"DRP = (RMJ, RMJ)\n"
"VKF = (XQB, VBX)\n"
"HRS = (BXK, DPM)\n"
"FHH = (FBF, TNX)\n"
"HDJ = (MBH, QRM)\n"
"TMG = (LJJ, JVM)\n"
"KJK = (GXP, FHS)\n"
"LKV = (VCV, JDP)\n"
"CVT = (MBM, BSQ)\n"
"RSD = (BFH, BPP)\n"
"KJG = (TMB, DMC)\n"
"DRH = (BFS, NCJ)\n"
"GRF = (MJL, TXX)\n"
"JVA = (XKG, RCL)\n"
"GFK = (NJF, NPR)\n"
"CQJ = (GVM, KKF)\n"
"TJC = (FNR, TFH)\n"
"BJP = (NMJ, JMX)\n"
"DRX = (MRR, QDL)\n"
"QFV = (TLM, XQM)\n"
"XQF = (NGF, NDC)\n"
"GDF = (TCV, PTP)\n"
"RHQ = (RGT, PXT)\n"
"NBR = (RRV, NCG)\n"
"PVF = (QPL, KRG)\n"
"CSQ = (TSC, GRF)\n"
"VMJ = (VTK, HRS)\n"
"BKH = (RPF, JGX)\n"
"GMM = (SRN, MSQ)\n"
"NLK = (BHP, TVR)\n"
"JDS = (LBV, TBN)\n"
"FQJ = (FMG, NRV)\n"
"JNG = (LTX, KHH)\n"
"DNM = (QPL, KRG)\n"
"BCJ = (LXV, BKQ)\n"
"LHD = (SGJ, JBX)\n"
"NMJ = (GPT, BCL)\n"
"DNJ = (DFT, BXT)\n"
"RDX = (QCX, VBF)\n"
"VMS = (HGR, MLS)\n"
"CSR = (PMC, BPT)\n"
"LFT = (FXN, SRJ)\n"
"JRK = (GDC, KVK)\n"
"BMB = (LJJ, JVM)\n"
"JMD = (JXX, JDS)\n"
"GPS = (LQF, QXR)\n"
"GQF = (VFK, GDR)\n"
"GGB = (MBP, RMV)\n"
"NRR = (CDX, MDJ)\n"
"VDM = (QRJ, LDJ)\n"
"FHM = (GFK, DSM)\n"
"XQM = (QSH, SXJ)\n"
"PSG = (RMP, CLT)\n"
"SPH = (VQQ, QTG)\n"
"XDB = (NSX, HDJ)\n"
"GDC = (SBL, XCL)\n"
"QBH = (HGS, KMR)\n"
"JDK = (PXR, LFT)\n"
"VBX = (DPL, VNL)\n"
"GXQ = (LFP, BXD)\n"
"RTT = (DHV, GDM)\n"
"RRV = (KRF, PLS)\n"
"XLA = (XMF, TRG)\n"
"LTP = (FNR, TFH)\n"
"SRP = (SNR, DLD)\n"
"JVV = (BCN, QXH)\n"
"JKM = (VCS, SQB)\n"
"DXX = (SDN, VXM)\n"
"XCV = (JBX, SGJ)\n"
"VXL = (XJM, HKT)\n"
"DGB = (RDQ, HGM)\n"
"SLT = (GDL, NQV)\n"
"XHH = (PQN, DNP)\n"
"FBK = (GMM, RHM)\n"
"PCG = (TCV, PTP)\n"
"GPT = (BCJ, NQH)\n"
"RLK = (TMG, BMB)\n"
"DSJ = (JKP, PKN)\n"
"XXJ = (VHX, RNJ)\n"
"LPS = (FBQ, NFG)\n"
"TMS = (KTV, VLT)\n"
"FXN = (CLC, HJJ)\n"
"GSV = (XSM, PPQ)\n"
"PQN = (XXJ, FJP)\n"
"HKX = (JSQ, RFS)\n"
"TRS = (BRL, FLC)\n"
"CPK = (QVN, PRR)\n"
"VFK = (KRH, LFV)\n"
"XVJ = (MQK, LRG)\n"
"BXT = (DMQ, JMD)\n"
"CDH = (VQJ, CLR)\n"
"FLP = (VPN, VBT)\n"
"KDF = (LPD, KMS)\n"
"HXH = (DNQ, CDL)\n"
"LLH = (SJD, JXB)\n"
"PKN = (KBD, RXT)\n"
"MJT = (FCH, CGS)\n"
"HMN = (PNK, QRK)\n"
"TXR = (QFV, DJM)\n"
"KNF = (HST, SLT)\n"
"XHL = (RXM, HXF)\n"
"VCM = (QBH, QHS)\n"
"NXD = (CXH, TKV)\n"
"BPP = (LBD, TBR)\n"
"TKX = (LPQ, JNG)\n"
"SVM = (LHN, PVJ)\n"
"BGH = (KNS, VBG)\n"
"HHX = (QJP, QMC)\n"
"CCN = (GSV, PHX)\n"
"TNH = (TRP, JXT)\n"
"LJM = (PMV, BGR)\n"
"TJX = (XNM, GBF)\n"
"LCD = (XQF, KRP)\n"
"PTP = (CSR, SDG)\n"
"RCL = (BMJ, RMH)\n"
"DVQ = (JCJ, SCX)\n"
"DJM = (XQM, TLM)\n"
"TVR = (VLX, XQZ)\n"
"KXH = (DHV, GDM)\n"
"HFB = (NQB, LKZ)\n"
"LBV = (MDV, LKP)\n"
"XMF = (DXS, JRM)\n"
"DSG = (XFF, HMN)\n"
"VNL = (FQD, RRC)\n"
"DPB = (TRP, JXT)\n"
"HHR = (DVT, DTJ)\n"
"CLR = (NXD, XPH)\n"
"QSF = (FTV, LLH)\n"
"JRM = (LPS, VGL)\n"
"QHK = (DRP, DRP)\n"
"GKJ = (QQN, JGC)\n"
"BKQ = (FBK, RJX)\n"
"VBG = (GCV, DHH)\n"
"JGC = (NFF, RHQ)\n"
"KBD = (TFJ, XBN)\n"
"QHG = (JMQ, XGL)\n"
"DFJ = (MMB, DRX)\n"
"HLJ = (GHG, HXG)\n"
"KKF = (TKX, XTM)\n"
"LXP = (GBF, XNM)\n"
"KKG = (TJX, LXP)\n"
"BGR = (PFQ, FSG)\n"
"BTS = (BCN, QXH)\n"
"BXK = (VKL, FSX)\n"
"JBS = (PXR, LFT)\n"
"KHF = (GBD, FCP)\n"
"CLK = (FHM, GVG)\n"
"NPR = (JTM, VDR)\n"
"XGL = (DMK, JHG)\n"
"SFV = (KXH, RTT)\n"
"DSM = (NJF, NPR)\n"
"DKH = (BSQ, MBM)\n"
"FTX = (LXP, TJX)\n"
"PLF = (DDS, LXJ)\n"
"JTB = (HLJ, DGS)\n"
"TJB = (QHG, LDQ)\n"
"RFC = (NPF, BXL)\n"
"MBH = (KFQ, DMT)\n"
"LCM = (DGV, HKX)\n"
"DLM = (GQD, KGH)\n"
"GSM = (QDQ, RHN)\n"
"PKV = (DTJ, DVT)\n"
"HNC = (PHX, GSV)\n"
"JBT = (DSR, DSL)\n"
"RMV = (XMT, GND)\n"
"QRK = (DFH, FFT)\n"
"QDQ = (RJC, FTF)\n"
"MFX = (DPB, TNH)\n"
"LGS = (JVF, JRK)\n"
"JFR = (QLV, JQN)\n"
"BXL = (LQH, JFR)\n"
"GDM = (DTB, GXR)\n"
"PTG = (XVJ, MNT)\n"
"HGS = (CGM, LSS)\n"
"LDQ = (JMQ, XGL)\n"
"LPR = (PQN, DNP)\n"
"TRG = (JRM, DXS)\n"
"VHX = (JTQ, BKP)\n"
"QPP = (LFP, BXD)\n"
"NNC = (RFQ, RDT)\n"
"PJL = (NGD, SXQ)\n"
"JQN = (PJL, CTJ)\n"
"JGH = (LRQ, JNN)\n"
"TRP = (PJR, SSS)\n"
"FTD = (HHR, PKV)\n"
"GXR = (VDL, VCM)\n"
"TXT = (HNC, CCN)\n"
"SQB = (LPR, XHH)\n"
"NLH = (QLR, LXH)\n"
"RCR = (DNQ, CDL)\n"
"CGM = (TJB, GCM)\n"
"DGS = (GHG, HXG)\n"
"TMB = (GGQ, MSB)\n"
"VJV = (PSR, BPR)\n"
"NNN = (LQF, QXR)\n"
"FNK = (PSG, HTG)\n"
"NCJ = (KJK, FSJ)\n"
"GRC = (SQP, NRR)\n"
"HQD = (LHN, PVJ)\n"
"NBL = (PNT, RSP)\n"
"JLF = (BHP, BHP)\n"
"HTG = (CLT, RMP)\n"
"QQN = (RHQ, NFF)\n"
"NRV = (LKV, FLQ)\n"
"RBV = (CMQ, GBG)\n"
"ZZZ = (SCX, JCJ)\n"
"NGF = (QFD, HVX)\n"
"XPH = (CXH, TKV)\n"
"CBR = (HTD, THC)\n"
"BCL = (NQH, BCJ)\n"
"SSS = (GMD, HBV)\n"
"GHL = (JTB, MHT)\n"
"QSH = (RRS, HGX)\n"
"CVS = (JKP, PKN)\n"
"QNK = (CVT, DKH)\n"
"JBX = (LSF, HNG)\n"
"HFQ = (DDT, QNK)\n"
"VQP = (BLP, PPF)\n"
"RGD = (BLP, PPF)\n"
"SDX = (PLX, SFL)\n"
"MLT = (XRS, LGS)\n"
"DSL = (QCF, MJT)\n"
"MFP = (HTS, GRC)\n"
"BRL = (MRS, JBT)\n"
"BJV = (HTD, THC)\n"
"PLV = (PNL, JKR)\n"
"PMV = (PFQ, FSG)\n"
"KHH = (MKL, RQF)\n"
"HCQ = (RQX, JVL)\n"
"VTD = (DNJ, KDB)\n"
"GXP = (JMF, RSD)\n"
"MGC = (DVQ, ZZZ)\n"
"CSS = (SRB, HTQ)\n"
"CTJ = (SXQ, NGD)\n"
"DNA = (RDJ, DGB)\n"
"FBH = (RGF, DRH)\n"
"DVM = (BXM, QFM)\n"
"MSB = (PVK, XKN)\n"
"XBQ = (JKR, PNL)\n"
"JXT = (PJR, SSS)\n"
"CLX = (XVJ, MNT)\n"
"DPL = (FQD, RRC)\n"
"QRJ = (CGT, KXN)\n"
"KRB = (TTV, DVM)\n"
"HGX = (RSM, GPP)\n"
"RMP = (XCV, LHD)\n"
"BXD = (CSS, FBT)\n"
"SRQ = (SXR, NBL)\n"
"JGX = (JLF, NLK)\n"
"DVP = (BKH, XXF)\n"
"SFL = (DFN, RLL)\n"
"BMF = (RHB, NTZ)\n"
"NPF = (LQH, JFR)\n"
"SMJ = (DSG, SQD)\n"
"CCH = (NCG, RRV)\n"
"KGH = (MBD, CCC)\n"
"DLS = (HMJ, PLF)\n"
"AAA = (JCJ, SCX)\n"
"XRP = (HCT, VXV)\n"
"SCS = (TLP, KKP)\n"
"RPL = (KBM, GKJ)\n"
"SVD = (NTN, BXF)\n"
"FMG = (LKV, FLQ)\n"
"XXF = (RPF, JGX)\n"
"QFJ = (VBT, VPN)\n"
"NKH = (GPS, NNN)\n"
"HST = (NQV, GDL)\n"
"CMK = (CLR, VQJ)\n"
"KTF = (LSN, RQS)\n"
"KDR = (HRD, SDX)\n"
"VLX = (XMF, TRG)\n"
"NFM = (MBP, RMV)\n"
"GRJ = (QDQ, RHN)\n"
"QHN = (TLL, GVB)\n"
"CRX = (SLT, HST)\n"
"DMS = (KGH, GQD)\n"
"QJP = (DLM, DMS)\n"
"KMR = (LSS, CGM)\n"
"FCH = (BCB, BCB)\n"
"PHX = (PPQ, XSM)\n"
"SGJ = (LSF, HNG)\n"
"TNX = (JHP, PDL)\n"
"RGT = (RXG, QRT)\n"
"DKC = (SRQ, TBK)\n"
"PVM = (CJP, VJV)\n"
"CDL = (FHT, SGR)\n"
"PBK = (PMD, QHN)\n"
"KTV = (MSX, SRP)\n"
"SQD = (XFF, HMN)\n"
"GQD = (CCC, MBD)\n"
"CFS = (VXL, MTH)\n"
"QVC = (LKS, PFT)\n"
"RQX = (NKD, RBV)\n"
"BXM = (JTP, PJD)\n"
"NKD = (CMQ, GBG)\n"
"VTK = (DPM, BXK)\n"
"SDG = (BPT, PMC)\n"
"KXR = (QNK, DDT)\n"
"FNJ = (LRQ, JNN)\n"
"RJX = (RHM, GMM)\n"
"QHS = (HGS, KMR)\n"
"GDL = (BGH, HPT)\n"
"GVM = (TKX, XTM)\n"
"DHV = (DTB, GXR)\n"
"NGD = (QMN, TCG)\n"
"NQB = (RDJ, DGB)\n"
"KRP = (NGF, NDC)\n"
"JKP = (KBD, RXT)\n"
"PGN = (VLT, KTV)\n"
"DFN = (CMK, CDH)\n"
"MHT = (HLJ, DGS)\n"
"BLP = (PCS, VMJ)\n"
"MDV = (HVV, KRB)\n"
"JXX = (LBV, TBN)\n"
"LDJ = (CGT, KXN)\n"
"NQV = (BGH, HPT)\n"
"NTZ = (FQL, JSG)\n"
"GND = (GSM, GRJ)\n"
"XHM = (LJM, TDR)\n"
"BNK = (QHK, RGP)\n"
"DMC = (GGQ, MSB)\n"
"FQL = (BJP, LXM)\n"
"CLT = (LHD, XCV)\n"
"JGD = (VXM, SDN)\n"
"XMT = (GRJ, GSM)\n"
"DFT = (JMD, DMQ)\n"
"CCC = (QFJ, FLP)\n"
"LFP = (FBT, CSS)\n"
"PMD = (GVB, TLL)\n"
"DGH = (RMJ, MGC)\n"
"TBK = (NBL, SXR)\n"
"FQD = (QBK, QBK)\n"
"RDJ = (RDQ, HGM)\n"
"FTV = (SJD, JXB)\n"
"GDR = (KRH, LFV)\n"
"GMD = (SFB, LQL)\n"
"DRV = (MPP, GFG)\n"
"TFH = (VDM, NMG)\n"
"FTF = (DFJ, CHK)\n"
"FLQ = (JDP, VCV)\n"
"JVF = (GDC, KVK)\n"
"PJD = (RVN, RVG)\n"
"XNM = (QCR, NLH)\n"
"RVG = (TXT, XVD)\n"
"TSC = (TXX, MJL)\n"
"KRF = (SVD, QJR)\n"
"VPQ = (PVF, DNM)\n"
"JHP = (JKM, DMJ)\n"
"QJK = (HCQ, VMT)\n"
"NRD = (XMH, STF)\n"
"RXF = (DVK, JFG)\n"
"RLT = (NRV, FMG)\n"
"TCV = (SDG, CSR)\n"
"XKG = (BMJ, RMH)\n"
"PXF = (JHS, GHP)\n"
"NFB = (BHJ, GLF)\n"
"FBT = (SRB, HTQ)\n"
"SRB = (GKB, TVB)\n"
"CLC = (RKB, DHT)\n"
"LKP = (HVV, KRB)\n"
"SPQ = (FHM, GVG)\n"
"MRR = (HHX, BPD)\n"
"QHQ = (BMB, TMG)\n"
"RLM = (BSF, BJH)\n"
"TBR = (KLV, XBZ)\n"
"BPR = (BSR, DKP)\n"
"MNL = (NKG, TXL)\n"
"DGV = (RFS, JSQ)\n"
"XBN = (KJG, CMV)\n"
"QMN = (VMS, SDL)\n"
"SDN = (TMS, PGN)\n"
"KMS = (FFD, MFB)\n"
"HJJ = (DHT, RKB)\n"
"HTS = (SQP, NRR)\n"
"FFT = (MMH, XXB)\n"
"KFQ = (LMH, KDF)\n"
"SHA = (JSG, FQL)\n"
"RXM = (RFC, KHD)\n"
"PCB = (TNX, FBF)\n"
"LFV = (DXC, SMJ)\n"
"XVD = (CCN, HNC)\n"
"GFG = (GMN, PNC)\n"
"RDQ = (GHL, MKP)\n"
"QCR = (QLR, LXH)\n"
"JCJ = (DLS, HMG)\n"
"GSJ = (QHN, PMD)\n"
"TLL = (GTD, BNK)\n"
"LPD = (MFB, FFD)\n"
"BPL = (GQF, JTF)\n"
"QVG = (LKS, PFT)\n"
"SQP = (CDX, MDJ)\n"
"SXR = (RSP, PNT)\n"
"XBZ = (PXF, SSF)\n"
"JDD = (DPB, TNH)\n"
"HGR = (QPP, GXQ)\n"
"PFT = (GLP, CBJ)\n"
"PNK = (FFT, DFH)\n"
"RMM = (RXM, HXF)\n"
"RXD = (BTS, JVV)\n"
"HVV = (TTV, DVM)\n"
"JMX = (GPT, BCL)\n"
"NFF = (PXT, RGT)\n"
"RHM = (SRN, MSQ)\n"
"DFH = (XXB, MMH)\n"
"PXT = (RXG, QRT)\n"
"VXM = (PGN, TMS)\n"
"FCP = (LDN, TRS)\n"
"NFG = (CFS, LGC)\n"
"RFS = (JDK, JBS)\n"
"RRC = (QBK, CCL)\n"
"KRH = (DXC, SMJ)\n"
"TKV = (VKF, HHL)\n"
"CGT = (HHF, BKT)\n"
"QLN = (FCP, GBD)\n"
"TTQ = (TDT, MQS)\n"
"CRJ = (MPP, GFG)\n"
"KDZ = (RCL, XKG)\n"
"TNC = (DVP, SVN)\n"
"TLM = (SXJ, QSH)\n"
"HCD = (VXV, HCT)\n"
"BCB = (NQB, NQB)\n"
"TXX = (LTJ, TTQ)\n"
"FJQ = (RXR, FTD)\n"
"KQG = (QFV, DJM)\n"
"JTP = (RVG, RVN)\n"
"DHH = (FKM, CKS)\n"
"GMN = (GGB, NFM)\n"
"DVK = (CMB, JJP)\n"
"MLX = (RCR, HXH)\n"
"MLS = (GXQ, QPP)\n"
"JKR = (QSF, RMR)\n"
"XRS = (JVF, JRK)\n"
"LTX = (RQF, MKL)\n"
"MBP = (GND, XMT)\n"
"MMH = (PFD, SFV)\n"
"LQH = (QLV, JQN)\n"
"KLV = (SSF, PXF)\n"
"LBD = (KLV, KLV)\n"
"LRQ = (LCM, FXB)\n"
"PLM = (GJF, FNK)\n"
"DNP = (FJP, XXJ)\n"
"PNT = (MLT, XGD)\n"
"VVS = (TBK, SRQ)\n"
"KXN = (HHF, BKT)\n"
"GTD = (QHK, RGP)\n"
"CDN = (XRP, HCD)\n"
"HNG = (DNC, VPQ)\n"
"QXR = (HBT, DCD)\n"
"FHV = (TXR, KQG)\n"
"GVB = (GTD, BNK)\n"
"KDB = (DFT, BXT)\n"
"PDH = (RFQ, RDT)\n"
"XST = (BSF, BJH)\n"
"VDL = (QBH, QHS)\n"
"RVN = (XVD, TXT)\n"
"HCT = (HQD, SVM)\n"
"VDR = (PDH, NNC)\n"
"RHN = (FTF, RJC)\n"
"BHF = (VBF, QCX)\n"
"GHX = (RHB, RHB)\n"
"CDX = (KVP, KDR)\n"
"NDC = (QFD, HVX)\n"
"GSH = (BHF, RDX)\n"
"MSQ = (KLJ, FLH)\n"
"BSR = (HPC, FBH)\n"
"SBL = (VNF, FDF)\n"
"RPF = (JLF, JLF)\n"
"LSS = (TJB, GCM)\n"
"GBG = (RXD, GSC)\n"
"JMQ = (DMK, DMK)\n"
"BKT = (PBK, GSJ)\n"
"PNL = (RMR, QSF)\n"
"LXJ = (CSQ, PHG)\n"
"JTF = (VFK, GDR)\n"
"KVK = (XCL, SBL)\n"
"MPG = (KQG, TXR)\n"
"JQC = (PCG, GDF)\n"
"JMF = (BFH, BFH)\n"
"PRR = (KLG, CDN)\n"
"PNJ = (KKF, GVM)\n"
"HHL = (XQB, VBX)\n"
"BXF = (NLF, JQC)\n"
"XQN = (TLP, KKP)\n"
"TTV = (QFM, BXM)\n"
"TXL = (KTF, QGQ)\n"
"XQZ = (TRG, XMF)\n"
"RQF = (LCD, SJC)\n"
"SCX = (DLS, HMG)\n"
"RXG = (PCB, FHH)\n"
"GSC = (JVV, BTS)\n"
"VQJ = (NXD, XPH)\n"
"JDP = (VTD, BNC)\n"
"PLX = (RLL, DFN)\n"
"FJP = (RNJ, VHX)\n"
"LHN = (XHM, NMC)\n"
"SGR = (MXT, QPR)\n"
"FKM = (JTK, TNC)\n"
"QXH = (HFQ, KXR)\n"
"RGF = (NCJ, BFS)\n"
"XKN = (NTT, MLX)\n"
"BPT = (VQP, RGD)\n"
"SJC = (XQF, KRP)\n"
"CBJ = (HRM, CPK)\n"
"TLP = (NPG, RPL)\n"
"KLJ = (CVS, DSJ)\n"
"SXJ = (RRS, HGX)\n"
"LGC = (VXL, MTH)\n"
"QGQ = (RQS, LSN)\n"
"HRM = (QVN, PRR)\n"
"GCV = (CKS, FKM)\n"
"SSF = (JHS, GHP)\n"
"HMJ = (LXJ, DDS)\n"
"PXR = (FXN, SRJ)\n"
"QJR = (NTN, BXF)\n"
"TSN = (XDB, RJV)\n"
"FLC = (MRS, JBT)\n"
"LMH = (KMS, LPD)\n"
"HTD = (TJC, LTP)\n"
"VJM = (BDR, GSH)\n"
"PLS = (SVD, QJR)\n"
"LTJ = (TDT, MQS)\n"
"HBT = (VXP, MNL)\n"
"HPT = (KNS, VBG)\n"
"NCG = (KRF, PLS)\n"
"HXF = (RFC, KHD)\n"
"QDL = (HHX, BPD)\n"
"NXX = (DVK, JFG)\n"
"DXC = (SQD, DSG)\n"
"FNR = (NMG, VDM)\n"
"PVK = (NTT, MLX)\n"
"KBM = (JGC, QQN)\n"
"XSM = (KHF, QLN)\n"
"HGM = (MKP, GHL)\n"
"QBK = (GHX, GHX)\n"
"XMH = (FHV, MPG)\n"
"JNN = (LCM, FXB)\n"
"SRN = (FLH, KLJ)\n"
"JVM = (MDH, XPQ)\n"
"QFD = (SCS, XQN)\n"
"PJR = (HBV, GMD)\n"
"FXB = (HKX, DGV)\n"
"VVD = (GSH, BDR)\n"
"FFD = (BJV, CBR)\n"
"SRJ = (HJJ, CLC)\n"
"MNT = (LRG, MQK)\n"
"THC = (TJC, LTP)\n"
"JVL = (NKD, RBV)\n"
"LXM = (JMX, NMJ)\n"
"RLL = (CMK, CDH)\n"
"XJM = (PNJ, CQJ)\n"
"DSR = (QCF, MJT)\n"
"RDT = (XBQ, PLV)\n"
"VNF = (XHL, RMM)\n"
"DNC = (PVF, DNM)\n"
"BNC = (KDB, DNJ)\n"
"JTQ = (QJK, CLJ)\n"
"CKS = (TNC, JTK)\n"
"PSR = (BSR, DKP)\n"
"QFM = (JTP, PJD)\n"
"PDL = (DMJ, JKM)\n"
"FSX = (RLM, XST)\n"
"DKP = (FBH, HPC)\n"
"BCN = (HFQ, KXR)\n"
"RMH = (RLK, QHQ)\n"
"NTT = (RCR, HXH)\n"
"RGP = (DRP, DGH)\n"
"QVM = (GJF, FNK)\n"
"BSQ = (MFX, JDD)\n"
"RMJ = (DVQ, DVQ)\n"
"BDR = (BHF, RDX)\n"
"XFF = (PNK, QRK)\n"
"VLT = (MSX, SRP)\n"
"KLG = (HCD, XRP)\n"
"GLP = (HRM, CPK)\n"
"LSN = (KCQ, PVM)\n"
"RFQ = (PLV, XBQ)\n"
"LBP = (GQF, JTF)\n"
"HTQ = (GKB, TVB)\n"
"MJL = (TTQ, LTJ)\n"
"TBN = (MDV, LKP)\n"
"KCQ = (VJV, CJP)\n"
"FSJ = (GXP, FHS)\n"
"DNQ = (SGR, FHT)\n"
"VMT = (JVL, RQX)\n"
"GCM = (QHG, LDQ)\n"
"PFD = (RTT, KXH)\n"
"JSQ = (JDK, JBS)\n"
"MPP = (GMN, PNC)\n"
"LKS = (GLP, CBJ)\n"
"XGD = (XRS, LGS)\n"
"HKT = (CQJ, PNJ)\n"
"LRG = (TSN, FGK)\n"
"GVG = (DSM, GFK)\n"
"HXG = (JGD, DXX)\n"
"RHS = (GRC, HTS)\n"
"RJC = (DFJ, CHK)\n"
"MXT = (FTX, KKG)\n"
"RXR = (PKV, HHR)\n"
"NLF = (GDF, PCG)\n"
"STF = (FHV, MPG)\n"
"BFH = (LBD, LBD)\n"
"CHK = (MMB, DRX)\n"
"NPG = (KBM, GKJ)\n"
"MMB = (QDL, MRR)\n"
"LXV = (RJX, FBK)\n"
"JSG = (BJP, LXM)\n"
"LQF = (HBT, DCD)\n"
"VCV = (BNC, VTD)\n"
"PHG = (TSC, GRF)\n"
"SNR = (SPQ, CLK)\n"
"LJJ = (XPQ, MDH)\n"
"HRD = (PLX, SFL)\n"
"QLR = (MFP, RHS)\n"
"FHS = (JMF, RSD)\n"
"LQL = (CRX, KNF)\n"
"GHP = (FNJ, JGH)\n"
"NTN = (JQC, NLF)\n"
"RXT = (XBN, TFJ)\n"
"BSF = (PLJ, NKH)\n"
"BJH = (PLJ, NKH)\n"
"LPQ = (KHH, LTX)\n"
"DMQ = (JXX, JDS)\n"
"PPF = (VMJ, PCS)\n"
"PMC = (RGD, VQP)\n"
"RNJ = (BKP, JTQ)\n"
"QPR = (KKG, FTX)\n"
"VXP = (NKG, TXL)\n"
"DVT = (DRV, CRJ)\n"
"SDL = (MLS, HGR)\n"
"NQH = (LXV, BKQ)\n"
"CMQ = (RXD, GSC)\n"
"FLH = (CVS, DSJ)\n"
"FGK = (RJV, XDB)\n"
"XXB = (SFV, PFD)\n"
"MQK = (FGK, TSN)\n"
"DCD = (MNL, VXP)\n"
"DXS = (LPS, VGL)\n"
"TDT = (LTB, NRD)\n"
"BFS = (FSJ, KJK)\n"
"TDR = (PMV, BGR)\n"
"RSP = (XGD, MLT)\n"
"QMC = (DLM, DMS)\n"
"NMC = (TDR, LJM)\n"
"GBF = (NLH, QCR)\n"
"XPQ = (KMC, FJQ)\n"
"KMC = (FTD, RXR)\n"
"HBV = (SFB, LQL)\n"
"BMJ = (RLK, QHQ)\n"
"LTB = (XMH, STF)\n"
"VVL = (XKG, RCL)\n"
"LKZ = (DGB, RDJ)\n"
"KNS = (GCV, DHH)\n"
"GPP = (VVD, VJM)\n"
"VQQ = (DKC, VVS)\n"
"VKL = (XST, RLM)\n"
"NMG = (QRJ, LDJ)\n"
"GJF = (HTG, PSG)\n"
"VBT = (LBP, BPL)\n"
"BPD = (QMC, QJP)\n"
"KVP = (SDX, HRD)\n"
"MFB = (BJV, CBR)\n"
"PNC = (NFM, GGB)\n"
"BHJ = (NXX, RXF)\n"
"PFQ = (VTG, NFB)\n"
"RKB = (FVM, SPH)\n"
"TVB = (NBR, CCH)\n"
"HMG = (HMJ, PLF)\n"
"NKG = (QGQ, KTF)\n"
"DLD = (CLK, SPQ)\n"
"RRS = (RSM, GPP)\n"
"RJV = (HDJ, NSX)\n"
"LXH = (MFP, RHS)\n"
"CMV = (DMC, TMB)\n"
"GKB = (NBR, CCH)\n"
"VPN = (BPL, LBP)\n"
"FBF = (JHP, PDL)\n"
"CCL = (GHX, BMF)\n"
"KKP = (NPG, RPL)\n"
"MKL = (LCD, SJC)\n"
"RSM = (VVD, VJM)\n"
"SVN = (BKH, XXF)\n"
"QRM = (DMT, KFQ)\n"
"CGS = (BCB, HFB)\n"
"XQB = (DPL, VNL)\n"
"QTG = (VVS, DKC)\n"
"KRG = (CLX, PTG)\n"
"DDT = (CVT, DKH)\n"
"SFB = (KNF, CRX)\n"
"GGQ = (XKN, PVK)\n"
"PPQ = (KHF, QLN)\n"
"DMJ = (SQB, VCS)\n"
"PLJ = (GPS, NNN)\n"
"BKP = (QJK, CLJ)\n"
"FSG = (NFB, VTG)\n"
"VBF = (PLM, QVM)\n"
"QRT = (PCB, FHH)\n"
"DMT = (KDF, LMH)\n"
"DTJ = (DRV, CRJ)\n"
"CMB = (FQJ, RLT)\n"
"MKP = (MHT, JTB)\n"
"RHB = (JSG, FQL)\n"
"PVJ = (XHM, NMC)\n"
"BHP = (VLX, VLX)\n"
"DLA = (SSF, PXF)\n"
"JXB = (QVG, QVC)\n"
"VCS = (XHH, LPR)\n"
"PCS = (HRS, VTK)\n"
"HPC = (DRH, RGF)\n"
"CJP = (PSR, BPR)\n"
"GBD = (TRS, LDN)\n"
"MDJ = (KDR, KVP)\n"
"SJD = (QVG, QVC)\n"
"QCX = (PLM, QVM)\n"
"JHM = (VVL, KDZ)\n"
"TFJ = (CMV, KJG)\n"
"GLF = (RXF, NXX)\n"
"SXQ = (TCG, QMN)\n"
"JKL = (VVL, VVL)\n"
"RQS = (PVM, KCQ)\n"
"VTG = (BHJ, GLF)\n"
"VGL = (FBQ, NFG)\n"
"XTM = (LPQ, JNG)\n"
"FBQ = (LGC, CFS)\n"
"XCL = (FDF, VNF)\n"
"VXV = (SVM, HQD)\n"
"MQS = (NRD, LTB)\n"
"MDH = (FJQ, KMC)\n"
"DHT = (SPH, FVM)\n"
"JHG = (JKL, JHM)\n"
"QVN = (KLG, CDN)\n"
"DTB = (VDL, VCM)\n"
"LDN = (BRL, FLC)\n"
"MSX = (SNR, DLD)\n"
"JTM = (NNC, PDH)\n"
"RMR = (FTV, LLH)\n"
"MTH = (XJM, HKT)\n"
"FVM = (QTG, VQQ)\n"
"LSF = (DNC, VPQ)\n"
"JHS = (FNJ, JGH)\n"
"CXH = (VKF, HHL)\n"
"FHT = (QPR, MXT)\n"
"QPL = (PTG, CLX)\n"
"NJF = (VDR, JTM)\n"
"MBD = (FLP, QFJ)\n"
"NSX = (MBH, QRM)\n"
"MBM = (JDD, MFX)\n"
"HHF = (PBK, GSJ)\n"
"DPM = (FSX, VKL)\n"
"JFG = (JJP, CMB)\n"
"KHD = (NPF, BXL)\n"
"DDS = (CSQ, PHG)\n"
"QLV = (PJL, CTJ)\n"
"CLJ = (HCQ, VMT)\n"
"MRS = (DSR, DSL)\n"
"GHG = (DXX, JGD)\n"

;

} // namespace

auto day08Part2(std::string_view streamSource, bool sourceIsFilePath)
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

    constexpr bool OfByFe = ((math_errhandling & MATH_ERREXCEPT) != 0);

    if constexpr (OfByFe) {
        std::feclearexcept(FE_ALL_EXCEPT);
    }

    const auto checkOverflow = [](std::string_view errorMsg) {
        constexpr bool OfByErrno = ((math_errhandling & MATH_ERRNO) != 0);

        if ((OfByErrno && (errno == ERANGE)) || (OfByFe && std::fetestexcept(FE_OVERFLOW))) {
            throw std::invalid_argument(std::string{errorMsg});
        }
    };

    const auto transformToVector = [](const auto& container, auto&& translateOp) {
        using TdestVal = std::decay_t<decltype(translateOp(*std::begin(container)))>;
        std::vector<TdestVal> res;

        res.reserve(std::size(container));

        std::transform(
            std::begin(container),
            std::end(container),
            std::back_inserter(res),
            std::forward<decltype(translateOp)>(translateOp));

        return res;
    };

    using Node = std::string;
    using Near = std::pair<Node, Node>;

    std::vector<bool> leftInstructions;
    std::map<Node, Near> network;

    unsigned warnNodesMoveToNothing = 0U;
    std::vector<Node> startNodes;

    using NodeIndex = unsigned;
    std::map<Node, NodeIndex> translator;
    std::vector<Node> nodeList; // only debug aim: inverse translation

    unsigned lineCount{0U};

    constexpr auto MaxLineLength = 1000;
    std::array<char, MaxLineLength + 1> cc{};
    bool firstNonEmptyLine = true;
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

        if (line.empty()) { // allow empty lines
            continue;
        }

        if (firstNonEmptyLine) {
            // left-right instructions
            for (auto instr : line) {
                switch (instr) {
                case 'L':
                    leftInstructions.push_back(true);
                    break;
                case 'R':
                    leftInstructions.push_back(false);
                    break;
                default:
                    throw std::invalid_argument(errorLine + "unknown instruction: " + instr);
                }
            }
        } else {
            Node node, left, right;
            if (!(lineStream >> node)) {
                throw std::invalid_argument(errorLine + "absent node");
            }

            {
                std::string tokenEq;
                if (!(lineStream >> tokenEq)) {
                    throw std::invalid_argument(errorLine + "completely absent '='");
                }
                if (tokenEq != "=") {
                    // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                    throw std::invalid_argument(errorLine + "absent '=': " + tokenEq);
                }
            }

            {
                if (!(lineStream >> left)) {
                    throw std::invalid_argument(errorLine + "completely absent left node");
                }
                if (left[0] != '(') {
                    throw std::invalid_argument(errorLine + "missing '(' for left node");
                }
                if (left.back() != ',') {
                    throw std::invalid_argument(
                        errorLine + "missing ',' between left and right nodes");
                }

                // At least two chars as '(' and ',' are different.
                left = left.substr(1, left.length() - 2U);
            }

            {
                if (!(lineStream >> right)) {
                    throw std::invalid_argument(errorLine + "completely absent right node");
                }
                if (right.back() != ')') {
                    throw std::invalid_argument(errorLine + "missing ')' after right node");
                }

                right.resize(right.length() - 1);
            }

            {
                if (!lineStream
                            .eof()) { // likely to change: no firther token (accept final spaces)
                    throw std::invalid_argument(errorLine + "something more after dest couple");
                }
            }

            translator[node] = static_cast<unsigned>(network.size());
            if (network.size() != translator[node]) {
                throw std::invalid_argument(errorLine + "abnormal number of nodes");
            }
            nodeList.push_back(node);

            if (!network
                        .insert(std::make_pair(
                            node, std::make_pair(std::move(left), std::move(right))))
                        .second) { // node already existing
                throw std::invalid_argument(errorLine + "repeated sequence");
            };

            if (node.back() == 'A') {
                startNodes.emplace_back(node);
            }
        }

        firstNonEmptyLine = false;
    }

    std::cout << "Instruction sequence length: " << leftInstructions.size() << std::endl;
    std::cout << "Starting nodes number: " << startNodes.size() << std::endl;
    std::cout << "Total node number: " << network.size() << std::endl;

    if (startNodes.empty()) {
        throw std::invalid_argument("No starting node!");
    }

    // speed-up: translate strings into numbers
    using NearIndex = std::pair<NodeIndex, NodeIndex>;
    std::map<NodeIndex, NearIndex> networkIdx;
    std::vector<NodeIndex> currentNodesIdx;
    std::set<NodeIndex> nodesZindex;
    {
        for (const auto& [node, near] : network) {
            auto nodeIndex = translator[node];

            const auto itL = translator.find(near.first);
            const auto leftIdx = (itL != translator.end()) ? itL->second : network.size();

            const auto itR = translator.find(near.second);
            const auto rightIdx = (itR != translator.end()) ? itR->second : network.size();

            if ((leftIdx == network.size()) || (rightIdx == network.size())) {
                ++warnNodesMoveToNothing;
            }

            networkIdx[nodeIndex]
                = std::make_pair(translator[near.first], translator[near.second]);

            if (node.back() == 'Z') {
                nodesZindex.insert(nodeIndex);
                std::cout << "Z node: " << node << '\n';
            }
        }
        currentNodesIdx = transformToVector(
            startNodes, [&translator](const auto& node) { return translator[node]; });
    }

    using StepCount = unsigned long long;
    StepCount upperBoundStep{};
    bool incompleteCheck = false;
    {
        constexpr std::string_view AbnormalUBmsg = "Extremely Abnormal upper bound value";
        auto ubDouble = std::pow(network.size(), startNodes.size());
        checkOverflow(AbnormalUBmsg);

        ubDouble *= static_cast<double>(leftInstructions.size());
        checkOverflow(AbnormalUBmsg);

        upperBoundStep = static_cast<StepCount>(ubDouble);
        constexpr auto SomethingLessThanOne = 0.5;
        if (ubDouble > static_cast<double>(upperBoundStep) + SomethingLessThanOne) {
            // happens for the current input
            // throw std::invalid_argument("Abnormal upper bound value " +
            // std::to_string(ubDouble)); Reduced as: (which means incomplete solution check)
            upperBoundStep = std::numeric_limits<StepCount>::max();
            incompleteCheck = true;
        }
    }

    std::cout << "Bound step number = " << upperBoundStep << std::endl;

    std::cout << "N. of Z nodes = " << nodesZindex.size() << std::endl;

    std::cout << "N. of nodes that may move to nothing " << warnNodesMoveToNothing << std::endl;

    std::vector<StepCount> firstTimeReachedZ, secondTimeReachedSameZ;
    std::vector<NodeIndex> zedReached;
    firstTimeReachedZ.resize(
        currentNodesIdx.size(), 0U); // start from 'A', must be positive at the end.
    secondTimeReachedSameZ.resize(currentNodesIdx.size(), 0U);
    zedReached.resize(currentNodesIdx.size(), 0U); // don't care
    unsigned reachedZSometimes = 0U;
    unsigned reachedZAtLeastTwice = 0U;

    StepCount stepCount = 0;
    size_t instrIndex = 0;
    size_t currentZ = 0U;

    while (currentZ < currentNodesIdx.size()) {
        ++stepCount;

        currentZ = 0U;
        size_t i = 0U;
        for (auto& currentNodeIndex : currentNodesIdx) {
            // std::cout << "current node: " << currentNode;
            const auto it = networkIdx.find(currentNodeIndex);
            if (it == networkIdx.end()) {
                // should have been detected earlier.
                throw std::invalid_argument("internal bug");
            }
            if (leftInstructions[instrIndex]) {
                // std::cout << " -> move left" << std::endl;
                currentNodeIndex = it->second.first;
            } else {
                // std::cout << " -> move right" << std::endl;
                currentNodeIndex = it->second.second;
            }

            if (currentNodeIndex >= network.size()) {
                auto sourceNodeStr = nodeList[it->first];
                auto destNodeStr = leftInstructions[instrIndex] ? network[sourceNodeStr].first
                                                                : network[sourceNodeStr].second;
                throw std::invalid_argument(
                    // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                    "Tried to move from " + sourceNodeStr + " to unexisting " + destNodeStr);
            }

            if (nodesZindex.count(currentNodeIndex) > 0U) {
                ++currentZ;
                // std::cout << "step " << stepCount << " pos " << (i+1)
                //          << " hit Z " << currentNodeIndex << std::endl;
                if (firstTimeReachedZ[i] == 0U) {
                    firstTimeReachedZ[i] = stepCount;
                    zedReached[i] = currentNodeIndex;
                    ++reachedZSometimes;
                } else if (secondTimeReachedSameZ[i] == 0U) {
                    if (zedReached[i] == currentNodeIndex) {
                        secondTimeReachedSameZ[i] = stepCount;
                        ++reachedZAtLeastTwice;

                        std::cout
                            << "step " << stepCount << " pos " << (i + 1) << " hit same Z "
                            << currentNodeIndex << " twice : " << firstTimeReachedZ[i]
                            << " and " << secondTimeReachedSameZ[i] << " with loop count "
                            << (secondTimeReachedSameZ[i] - firstTimeReachedZ[i]) << std::endl;

                        if (reachedZAtLeastTwice == currentNodesIdx.size()) {
                            // NOLINT -> prefer uppercase.
                            auto L = leftInstructions.size(); // NOLINT
                            std::cout << "L = " << L << '\n';


                            bool okSpeedUp{};
                            {
                                auto loopCount
                                    = (secondTimeReachedSameZ[0] - firstTimeReachedZ[0]);
                                okSpeedUp = ((loopCount % L) == 0U);

                                if (!okSpeedUp) {
                                    std::cout << "okSpeedUp false for loop count " << loopCount
                                                << " of Z " << zedReached[0] << '\n';
                                }
                            }

                            StepCount residual = firstTimeReachedZ[i] % L;

                            std::cout << "residual model " << residual << '\n';

                            for (size_t j = 1U; j < reachedZAtLeastTwice; ++j) {
                                if ((firstTimeReachedZ[j] % L) != residual) {
                                    okSpeedUp = false;
                                    std::cout << "okSpeedUp false for residual "
                                                << (firstTimeReachedZ[j] % L) << " of Z "
                                                << zedReached[j] << '\n';
                                }

                                auto loopCount
                                    = (secondTimeReachedSameZ[j] - firstTimeReachedZ[j]);
                                if ((loopCount % L) != 0U) {
                                    okSpeedUp = false;
                                    std::cout << "okSpeedUp false for loop count " << loopCount
                                                << " of Z " << zedReached[j] << '\n';
                                }
                            }

                            if (!okSpeedUp) {
                                std::cout << "COULD NOT okSpeedUp\n";
                                // TODO: generalize the approach, accepting also cycles
                                // touching different Z nodes, but still multiple of L (anyway,
                                // finally check for a sub-period). In this case, all
                                // combinations of different Z-nodes touched in each of the
                                // Z-cycles, and the minimum sync has to be selected (discarding
                                // at all the combinations for which a sync is found not
                                // possible).
                            } else {
                                std::cout << "okSpeedUp\n";

                                // fast solution process considering steps of full L-cycles:
                                using PeriodCount = StepCount;
                                std::vector<std::pair<StepCount, PeriodCount>>
                                    deltaAndPeriodCycles;

                                for (size_t j = 0U; j < reachedZAtLeastTwice; ++j) {
                                    auto loopCount
                                        = (secondTimeReachedSameZ[j] - firstTimeReachedZ[j]);

                                    auto residualSteps = loopCount
                                        - ((stepCount - firstTimeReachedZ[j]) % loopCount);

                                    if (residualSteps == loopCount) {
                                        // possible in second case.
                                        residualSteps = 0U;
                                    }

                                    deltaAndPeriodCycles.emplace_back(
                                        std::make_pair(residualSteps / L, loopCount / L));

                                    std::cout << "residual for pos " << j << " : "
                                                << deltaAndPeriodCycles.back().first << '\n';
                                    std::cout << "period for pos " << j << " : "
                                                << deltaAndPeriodCycles.back().second << '\n';
                                }

                                StepCount totCycles = 0;

                                // Each sequence will hit the first time Z after 'delta %
                                // period' and then repeat again and again after 'period'. If
                                // all delta% would be zero, the solution is already there but
                                // it will be repeated even each lcm(period1, ..., periodN)
                                // cycles. In case of some delta% > 0, the first hit may be
                                // found accumulating a resulting couple (deltaTot, periodTot)
                                // adding a new couple (delta%,period) at a time and solve each
                                // time the problem for two couples only, the accumulated one
                                // and the new one. For two couples (d1,p1) and (d2,p2), the
                                // first time to hit together may be found considering the
                                // points d1, d1+p1, d1+p1*2, ..., up to d1+p1*(p2-1), if for
                                // any of these points the accumulated delay of the second
                                // compared to the first is multiple of p2 itself. therefore it
                                // is better to us as p1 the maximum and as p2 the minimum
                                // between them, which means we cannot start the accumulation
                                // through a dummy seed {0,1} because generally the accumulation
                                // may have higher period. Then, the cumulated period is
                                // lcm(p1,p2). So, this decays anyway to lcm(p1,...,pN) at the
                                // end of the story. Therefore, again, it is better to order by
                                // decreasing periods.
                                std::sort(
                                    deltaAndPeriodCycles.begin(),
                                    deltaAndPeriodCycles.end(),
                                    [](const auto dp1, const auto dp2) {
                                        return (dp2.second < dp1.second);
                                        // based on period. The higher first.
                                    });

                                // Here, with all nodes having reached Z at least once, the
                                // 'residual' value is something related to the periods only,
                                // that is each residual delta is less than corresponding
                                // period.
                                unsigned accStepIndex = 0U;
                                std::cout << "Starting with (delta="
                                            << deltaAndPeriodCycles.cbegin()->first << ", "
                                            << deltaAndPeriodCycles.cbegin()->second << ")\n";
                                auto deltaAndPeriod = std::accumulate(
                                    std::next(deltaAndPeriodCycles.cbegin()),
                                    deltaAndPeriodCycles.cend(),
                                    *deltaAndPeriodCycles.cbegin(),
                                    [&accStepIndex](const auto acc, const auto scrollDP) {
                                        ++accStepIndex;
                                        std::cout << "Accumulation n. " << accStepIndex
                                                    << " with (delta=" << scrollDP.first << ", "
                                                    << scrollDP.second << ")\n";

                                        const auto gcdPeriods
                                            = std::gcd(acc.second, scrollDP.second);

                                        auto absDiffDelta = (acc.first >= scrollDP.first)
                                            ? (acc.first - scrollDP.first)
                                            : (scrollDP.first - acc.first);

                                        if ((absDiffDelta % gcdPeriods) > 0U) {
                                            std::cout << "Diff between deltas " << absDiffDelta
                                                        << " is not a multiple of gdc "
                                                        << gcdPeriods << '\n';
                                            throw std::invalid_argument(
                                                "Will never meet together");
                                        }

                                        StepCount delay
                                            = // delay of the second over the first at the
                                                // moment the first has its first occurrence.
                                            (scrollDP.first >= acc.first)
                                            ? absDiffDelta // <= scrollDP.first <
                                                            // scrollDP.second
                                            : (scrollDP.second
                                                - (absDiffDelta % scrollDP.second));
                                        // Note that in second case it is possible absDiffDelta
                                        // is multiple of p2, therefore the correct value of
                                        // delay is zero (sync happening on first occurrence:
                                        // point d1).
                                        if (delay == scrollDP.second) {
                                            delay = 0U;
                                        }

                                        // TODO: is there a formula to understand deltaRes in
                                        // O(1) instead of O(p2) ?

                                        auto recoveryPerEachP1
                                            = (acc.second - scrollDP.second) % scrollDP.second;
                                        // zero only if p1 is multiple of p2, but in this case
                                        // delay is zero soon (if not, absDiffDelta % gcdPeriods
                                        // would have been positive, leading above to understand
                                        // impossible sync).
                                        auto delayForEachP1
                                            = scrollDP.second - recoveryPerEachP1;
                                        // Note also that reducing acc.second by scrollDP.second
                                        // before module is really useless
                                        // but it is kept to improve reading.

                                        // std::cout << "starting delay = " << delay
                                        //          << " (steps will be " << delayForEachP1 <<
                                        //          ")\n";
                                        StepCount deltaRes = acc.first;
                                        PeriodCount debug = 0U;
                                        while (delay > 0U) {
                                            delay += delayForEachP1;
                                            if (delay >= scrollDP.second) {
                                                delay -= scrollDP.second;
                                            }
                                            // std::cout << "new delay = " << delay
                                            //          << " (try " << (debug+1) << ")\n";

                                            deltaRes += acc.second;

                                            if (scrollDP.second == ++debug) {
                                                throw std::runtime_error("buggy code");
                                            }
                                        }

                                        auto periodRes = std::lcm(acc.second, scrollDP.second);
                                        if (((periodRes % acc.second) > 0U)
                                            || ((periodRes % scrollDP.second) > 0U)
                                            || (periodRes == 0U)) {
                                            // overflow problem. Despite in this case the
                                            // behaviour is undefined, for sure it would not be
                                            // possible the result is multiple of both.
                                            throw std::runtime_error(
                                                "Cannot manage the lcm between "
                                                + std::to_string(acc.second) + " and "
                                                + std::to_string(scrollDP.second));
                                        }
                                        std::cout
                                            << "Accumulation resulting in (delta=" << deltaRes
                                            << ", " << periodRes << ")\n\n";
                                        return std::make_pair(deltaRes, periodRes);
                                    });

                                totCycles = deltaAndPeriod.first;

                                std::cout << "additional cycles " << totCycles << std::endl;

                                if (totCycles
                                    > (std::numeric_limits<StepCount>::max() - stepCount) / L) {
                                    std::cout << "Fast compute: step number has to be manually "
                                                    "computed: "
                                                << stepCount << " + further " << totCycles
                                                << " cycles with"
                                                    "length "
                                                << L << " each" << std::endl;
                                    return static_cast<StepCount>(0U);
                                } // else
                                {
                                    std::cout << "Result: fast compute: "
                                                << (stepCount + L * totCycles) << std::endl;
                                    return (stepCount + L * totCycles);
                                }
                            }
                        }
                    }
                }
            }
            ++i;
        }

        ++instrIndex;
        instrIndex %= leftInstructions.size();

        if (stepCount >= upperBoundStep) {
            if (!incompleteCheck) {
                throw std::invalid_argument(
                    "Will turn around forever: " + std::to_string(stepCount));
            } // else
            {
                throw std::invalid_argument(
                    "Will likely turn around forever but cannot check for more than: "
                    + std::to_string(stepCount));
            }
        }
    }

    std::cout << "\nResult: " << stepCount << std::endl;
    return stepCount;
}

int main()
{
    try {
        day08Part2(Input, false);
        // day08Part2("./08_input_file.txt",true);
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
Instruction sequence length: 2
Starting nodes number: 2
Total node number: 8
Z node: 11Z
Z node: 22Z
Bound step number = 128
N. of Z nodes = 2
N. of nodes that may move to nothing 0
step 4 pos 1 hit same Z 2 twice : 2 and 4 with loop count 2
step 6 pos 2 hit same Z 6 twice : 3 and 6 with loop count 3
L = 2
residual model 1
okSpeedUp false for loop count 3 of Z 6
COULD NOT okSpeedUp
Result: 6

Real input:
Instruction sequence length: 263
Starting nodes number: 6
Total node number: 762
Z node: KDZ
Z node: LKZ
Z node: NTZ
Z node: XBZ
Z node: XQZ
Z node: ZZZ
Bound step number = 18446744073709551615
N. of Z nodes = 6
N. of nodes that may move to nothing 0
step 24722 pos 5 hit same Z 323 twice : 12361 and 24722 with loop count 12361
step 27878 pos 1 hit same Z 423 twice : 13939 and 27878 with loop count 13939
step 31034 pos 4 hit same Z 212 twice : 15517 and 31034 with loop count 15517
step 35242 pos 2 hit same Z 492 twice : 17621 and 35242 with loop count 17621
step 38398 pos 3 hit same Z 657 twice : 19199 and 38398 with loop count 19199
step 41554 pos 6 hit same Z 399 twice : 20777 and 41554 with loop count 20777
L = 263
residual model 0
okSpeedUp
residual for pos 0 : 1
period for pos 0 : 53
residual for pos 1 : 43
period for pos 1 : 67
residual for pos 2 : 61
period for pos 2 : 73
residual for pos 3 : 19
period for pos 3 : 59
residual for pos 4 : 30
period for pos 4 : 47
residual for pos 5 : 0
period for pos 5 : 79
Starting with (delta=0, 79)
Accumulation n. 1 with (delta=61, 73)
Accumulation resulting in (delta=5609, 5767)

Accumulation n. 2 with (delta=43, 67)
Accumulation resulting in (delta=386231, 386389)

Accumulation n. 3 with (delta=19, 59)
Accumulation resulting in (delta=22796793, 22796951)

Accumulation n. 4 with (delta=1, 53)
Accumulation resulting in (delta=1208238245, 1208238403)

Accumulation n. 5 with (delta=30, 47)
Accumulation resulting in (delta=56787204783, 56787204941)

additional cycles 56787204783
Result: fast compute: 14935034899483
*/
