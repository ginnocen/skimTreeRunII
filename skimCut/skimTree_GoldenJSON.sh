FILELIST=(
    "HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016"
)

ipd=0
nFILELIST=${#FILELIST[@]}
while ((ipd<$nFILELIST))
do
    INPUTFILE="/data/jisun/PbPb2015/${FILELIST[ipd]}.root"
    OUTPUTFILE="/data/wangj/Data2015/Dntuple/PbPb/${FILELIST[ipd]}_skimNewcuts.root"
    ipd=$(($ipd+1))
    g++ skimTree_TrackerOnly.C $(root-config --cflags --libs) -g -o skimTree_TrackerOnly.exe 
    ./skimTree_TrackerOnly.exe "$INPUTFILE" "$OUTPUTFILE" 0
    rm skimTree_TrackerOnly.exe
done