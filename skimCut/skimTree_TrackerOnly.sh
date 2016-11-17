#!/bin/bash

CUTLIST=("New" "OPT")
nCUTLIST=${#CUTLIST[@]}

FILELIST=(
    "Dntuple_crab_PbPb_HIMinimumBias1_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias2_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias3_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias4_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias5_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias6_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias7_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias8_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias9_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias10_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
    "Dntuple_crab_PbPb_HIMinimumBias11_tkpt0p5eta1p5_Dy1p1_EvtPlaneCalibration_v2v3etagap_05142016new_TrackerOnly_JSON"
)
nFILELIST=${#FILELIST[@]}

j=1
while ((j<$nCUTLIST))
do
    cp skimCutHeads/skimTree_Cut_${CUTLIST[j]}.h skimTree_Cut.h
    ipd=0
    while ((ipd<$nFILELIST))
    do
        INPUTFILE="/data/wangj/Data2015/Dntuple/PbPb/TrackerOnly/${FILELIST[ipd]}.root"
        OUTPUTFILE="/data/wangj/Data2015/Dntuple/PbPb/TrackerOnly/${FILELIST[ipd]}_skim${CUTLIST[j]}cuts.root"
        ipd=$(($ipd+1))
        root -b -q 'skimTree_Cut.C+('\"$INPUTFILE\"','\"$OUTPUTFILE\"','$ipd')'
    done
    rm skimTree_Cut.h
    j=$(($j+1))
done