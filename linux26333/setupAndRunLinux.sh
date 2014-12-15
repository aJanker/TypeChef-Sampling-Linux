#!/bin/bash

#current casestudy
STUDY=linux
TIMEOUT=3h

cd /local/janker/

mkdir $STUDY 2>/dev/null

cd $STUDY

#check if case study is setup
if mkdir setup.init 2>/dev/null; 
	then
		# get typechef
		git clone https://github.com/aJanker/TypeChef
		cd TypeChef
		# compile typechef
		git checkout StaticAnalysis
		java -jar sbt-launch.jar update compile mkrun
		cd ..
		#get linux case study
		git clone https://github.com/aJanker/TypeChef-LinuxAnalysis
		cd TypeChef-LinuxAnalysis/linux26333/
		./prepareLinuxTestCase.sh
		cd ../../
		touch setup.done
fi

#wait until atomic setup is ready
while [ ! -f setup.done ]
	do
    	sleep 10;
	done;

cd TypeChef
timeout $TIMEOUT ./typechef.sh "$@"
