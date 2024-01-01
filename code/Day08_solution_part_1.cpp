#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace{

constexpr std::string_view Input =

false ?

"RL\n"
"AAA = (BBB, CCC)\n"
"BBB = (DDD, EEE)\n"
"CCC = (ZZZ, GGG)\n"
"DDD = (DDD, DDD)\n"
"EEE = (EEE, EEE)\n"
"GGG = (GGG, GGG)\n"
"ZZZ = (ZZZ, ZZZ)\n"

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

auto day08Part1(std::string_view streamSource, bool sourceIsFilePath)
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

    using Node = std::string;
    using Near = std::pair<Node, Node>;

    std::vector<bool> leftInstructions;
    std::map<Node, Near> network;

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
                if (!lineStream.eof()){ // likely to change: no firther token (accept final spaces)
                    throw std::invalid_argument(errorLine + "something more after dest couple");
                }
            }

            if (!network.emplace(
                    std::move(node),
                    std::make_pair(std::move(left), std::move(right))
                ).second){ // node already existing
                throw std::invalid_argument(errorLine + "repeated sequence");
            };
        }

        firstNonEmptyLine = false;
    }

    std::cout << "Instruction sequence length: " << leftInstructions.size() << std::endl;
    std::cout << "Node number: " << network.size() << std::endl;

    static const std::string seqAAA = "AAA";
    static const std::string seqZZZ = "ZZZ";

    if (network.count(seqAAA) + network.count(seqZZZ) != 2U){
        throw std::invalid_argument("absent AAA or ZZZ");
    }

    unsigned long stepCount = 0;
    size_t instrIndex = 0;
    Node currentNode{seqAAA};
    while (currentNode != seqZZZ) {
        // std::cout << "current node: " << currentNode;
        const auto it = network.find(currentNode);
        if (it == network.end()) {
            // mvoed to this non-existing node in previous step.
            throw std::invalid_argument(
                "not existing node " + currentNode + " after "
                + std::to_string(stepCount));
        }
        if (leftInstructions[instrIndex]) {
            // std::cout << " -> move left" << std::endl;
            currentNode = it->second.first;
        } else {
            // std::cout << " -> move right" << std::endl;
            currentNode = it->second.second;
        }

        ++instrIndex;
        instrIndex %= leftInstructions.size();

        if ((network.size() * leftInstructions.size()) == ++stepCount) {
            throw std::invalid_argument(
                "Will turn around forever: " + std::to_string(stepCount));
        }
    }

    std::cout << "\nResult: " << stepCount << "\n\n\n";

    return stepCount;
}

int main08p1()
{
    try {
        day08Part1(Input, false);
        // day08Part1("./08_input_file.txt",true);
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
Node number: 7
Result: 2

Real input:
Instruction sequence length: 263
Node number: 762
Result: 15517
*/
