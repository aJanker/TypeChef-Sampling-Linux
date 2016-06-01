# TypeChef Analysis of Linux

Contains various scripts to run static analysis and sampling strategies with TypeChef on Linux.

The setup requires multiple steps. Contact me if there are any issues.

## Setup & Linux source code

First we need the source code of the Kernel and extract the correct version as some file presence condtions.

The script `./linux26333/prepareLinuxTestCase.sh` has some code to automate 
the download, extraction and preparation.


## How to run the analysis

Go to `./linux26333`.

Afterward run `runVAA.sh` to run the actual variability-aware analysis and for sampling `runSampling.sh`. Note this case study runs for a very long time. If you have some high-performance computing environment, you might want to checkout `runVAA_sbatch.sh` and `runSampling_sbatch.sh`
