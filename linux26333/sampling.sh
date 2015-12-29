#!/bin/bash
# Brute argument parsing
# The right thing to do would be to be a gcc replacement, parse its flags and
# select the ones we care about.
if [ $# -lt 1 ]; then
  echo "Not enough arguments!" >&2
  exit 1
fi
inp=$1
shift

if [ -z "$inp" ]; then
  echo "inp not defined!" >&2
  exit 1
fi


outBase="$(dirname $inp)/$(basename $inp .c)"
copyBase=$(echo $outBase | sed s/local/scratch/g)



# variability-aware analysis
#    export partialPreprocFlags="$partialPreprocFlagsBase --reuseAST --family"
#    ./jcpp.sh "$@" $extraFlags
#    mv ${srcPath}/${i}.err ${srcPath}/${i}_family.err
#    mv ${srcPath}/${i}.dbg ${srcPath}/${i}_family.dbg

# single conf
    extraFlagsSC="--singleconf --rootfolder /local/janker/linuxMax"
    ./jcpp_sampling.sh "$@" $extraFlagsSC
    gzip ${outBase}.err ${copyBase}_singleconf.err.gz
    gzip ${outBase}.dbg ${copyBase}_singleconf.dbg.gz
    mv ${outBase}.time ${copyBase}_singleconf.time
    mv ${outBase}.astimes ${copyBase}_singleconf.astimes
    mv ${outBase}.errreport ${outBase}_singleconf.errreport	

 # pairwise
    extraFlagsPW="--pairwise --rootfolder /local/janker/linuxMax"
    ./jcpp_sampling.sh "$@" $extraFlagsPW
    gzip ${outBase}.err ${copyBase}_pairwise.err.gz
    gzip ${outBase}.dbg ${copyBase}_pairwise.dbg.gz
    mv ${outBase}.time ${copyBase}_pairwise.time
    mv ${outBase}.astimes ${copyBase}_pairwise.astimes
    mv ${outBase}.errreport ${outBase}_pairwise.errreport 

 # code coverage nh
    extraFlagsCC="--rootfolder /local/janker/linuxMax --codecoveragenh"
    ./jcpp_sampling.sh "$@" $extraFlagsCC
    gzip ${outBase}.err ${copyBase}_codecoveragenh.err.gz
    gzip ${outBase}.dbg ${copyBase}_codecoveragenh.dbg.gz
    mv ${outBase}.time ${copyBase}_codecoveragenh.time
    mv ${outBase}.astimes ${copyBase}_codecoveragenh.astimes
    mv ${outBase}.errreport ${outBase}_codecoveragenh.errreport 	

# create condensed report
    find ${outBase} -type f -name "${filename}.c_*.errreport" | xargs cat > ${copyBase}.errreportall

    gzip ${outBase}_codecoveragenh.errreport ${copyBase}_codecoveragenh.errreport.gz
    gzip ${outBase}_pairwise.errreport ${copyBase}_pairwise.errreport.gz
    gzip ${outBase}_singleconf.errreport ${copyBase}_singleconf.errreport.gz

#mv to scratch
