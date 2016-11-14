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

ipd=0
nFILELIST=${#FILELIST[@]}
while ((ipd<$nFILELIST))
do
    INPUTFILE="/data/wangj/Data2015/Dntuple/PbPb/TrackerOnly/${FILELIST[ipd]}.root"
    OUTPUTFILE="/data/wangj/Data2015/Dntuple/PbPb/TrackerOnly/${FILELIST[ipd]}_skimNewcuts.root"
    ipd=$(($ipd+1))
    g++ skimTree_TrackerOnly.C $(root-config --cflags --libs) -g -o skimTree_TrackerOnly.exe 
    ./skimTree_TrackerOnly.exe "$INPUTFILE" "$OUTPUTFILE" "$ipd"
    rm skimTree_TrackerOnly.exe
done