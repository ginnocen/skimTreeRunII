#!/bin/bash

SAMPLES=("GoldenJSON" "TrackerOnly")
nSAMPLES=${#SAMPLES[@]}

INPUTFILE=("/data/wangj/Data2015/Dntuple/PbPb/HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_skimOPTcuts.root"
           "/data/wangj/Data2015/Dntuple/PbPb/Dntuple_crab_PbPb_HIMinimumBias1to11_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON_skimOPTcuts.root")
 
OUTPUTFILE=("/data/wangj/Data2015/Dntuple/PbPb/HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_skimOPTcuts_removesomebranches.root"
            "/data/wangj/Data2015/Dntuple/PbPb/Dntuple_crab_PbPb_HIMinimumBias1to11_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON_skimOPTcuts_removesomebranches.root")

i=0
while (($i<$nSAMPLES))
do
    cp skimBranchesHead/skimTree_Dzero_${SAMPLES[i]}.h skimTree_Dzero.h
    root -b -q 'skimTree_Dzero.C+('\"${INPUTFILE[i]}\"','\"${OUTPUTFILE[i]}\"')'
    rm skimTree_Dzero.h
    i=$(($i+1))
done