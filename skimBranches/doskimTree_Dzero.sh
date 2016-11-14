#!/bash/bin

SAMPLES=("GoldenJSON" "TrackerOnly" "GoldenJSONHP" "TrackerOnlyHP")
nSAMPLES=${#SAMPLES[@]}

INPUTFILE=("/data/wangj/Data2015/Dntuple/PbPb/HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_skimNewcuts.root"
           "/data/wangj/Data2015/Dntuple/PbPb/Dntuple_crab_PbPb_HIMinimumBias1to11_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON_skimNewcuts.root"
           "/data/wangj/Data2015/Dntuple/PbPb/ntD_EvtBase_20160405_HIHardProbes_DfinderData_PbPb_20160402_dPt0tkPt2p5_D0Dstar3p5p_FINALJSON.root"
           "/data/wangj/Data2015/Dntuple/PbPb/Dntuple_crab_PbPb_HIHardProbes_tkpt6p0eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON.root")
OUTPUTFILE=("/data/wangj/Data2015/Dntuple/PbPb/HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_skimNewcuts_removesomebranches.root"
            "/data/wangj/Data2015/Dntuple/PbPb/Dntuple_crab_PbPb_HIMinimumBias1to11_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON_skimNewcuts_removesomebranches.root"
            "/data/wangj/Data2015/Dntuple/PbPb/ntD_EvtBase_20160405_HIHardProbes_DfinderData_PbPb_20160402_dPt0tkPt2p5_D0Dstar3p5p_FINALJSON_removesomebranches.root"
            "/data/wangj/Data2015/Dntuple/PbPb/Dntuple_crab_PbPb_HIHardProbes_tkpt6p0eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON_removesomebranches.root")

i=2
while (($i<$nSAMPLES))
do
    cp skimBranchesHead/skimTree_Dzero_${SAMPLES[i]}.h skimTree_Dzero.h
    root 'skimTree_Dzero.C+('\"${INPUTFILE[i]}\"','\"${OUTPUTFILE[i]}\"')'
    rm skimTree_Dzero.h
    i=$(($i+1))
done