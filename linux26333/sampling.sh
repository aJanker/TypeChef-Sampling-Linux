#!/bin/bash

outBase="$(dirname $inp)/$(basename $inp .c)"
copyBase=$(echo $outBase | sed s/local/scratch/g)



# variability-aware analysis
#    export partialPreprocFlags="$partialPreprocFlagsBase --reuseAST --family"
#    ./jcpp.sh "$@" $extraFlags
#    mv ${srcPath}/${i}.err ${srcPath}/${i}_family.err
#    mv ${srcPath}/${i}.dbg ${srcPath}/${i}_family.dbg

# single conf
    extraFlagsSC="--singleconf --rootfolder /loccal/janker/linuxMax"
    ./jcpp_sampling.sh "$@" $extraFlagsSC
    gzip ${outBase}.err ${copyBase}_singleconf.err.gz
    gzip ${outBase}.dbg ${copyBase}_singleconf.dbg.gz

 # pairwise
    extraFlagsPW="--pairwise --rootfolder /loccal/janker/linuxMax"
    ./jcpp_sampling.sh "$@" $extraFlagsPW
    gzip ${outBase}.err ${copyBase}_pairwise.err.gz
    gzip ${outBase}.dbg ${copyBase}_pairwise.dbg.gz

 # code coverage nh
    extraFlagsCC="--rootfolder /loccal/janker/linuxMax --codecoveragenh"
    ./jcpp_sampling.sh "$@" $extraFlagsCC
    gzip ${outBase}.err ${copyBase}_codecoveragenh.err.gz
    gzip ${outBase}.dbg ${copyBase}_codecoveragenh.dbg.gz

# create condensed report
    find ${outBase} -type f -name "${filename}.c_*.errreport" | xargs cat > ${copyBase}.errreportall

#mv to scratch
