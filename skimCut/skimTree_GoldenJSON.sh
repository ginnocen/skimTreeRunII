#!/bin/bash

CUTLIST=("New" "OPT")
nCUTLIST=${#CUTLIST[@]}
FILELIST=(
    "HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016"
)
nFILELIST=${#FILELIST[@]}

j=1
while ((j<$nCUTLIST))
do
    cp skimCutHeads/skimTree_Cut_${CUTLIST[j]}.h skimTree_Cut.h
    ipd=0
    while ((ipd<$nFILELIST))
    do
        INPUTFILE="/data/jisun/PbPb2015/${FILELIST[ipd]}.root"
        OUTPUTFILE="/data/wangj/Data2015/Dntuple/PbPb/${FILELIST[ipd]}_skim${CUTLIST[j]}cuts.root"
        ipd=$(($ipd+1))
        root -b -q 'skimTree_Cut.C+('\"$INPUTFILE\"','\"$OUTPUTFILE\"','0')'
    done
    rm skimTree_Cut.h
    j=$(($j+1))
done