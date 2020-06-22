#!/usr/bin/env bash

N=25

WIN=1	#Set to 1 if running on Windows and having problems with Docker volumes or paths...

LANGUAGES=(java_8_hotspot nodejs go posix) # Languages to use
#LANGUAGES=(java_8_hotspot) # Languages to use
TOOLS=(monitor monitor-bin monitor-bin_string)
MODES=(on off no) # Logging modes

BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../ && pwd)
chmod -R 777 $BASEDIR
#echo "BASEDIR set to $BASEDIR"
((BASIC)) && BASEMODELDIR=$BASEDIR/src/main/thingml/basic/
((!BASIC)) && BASEMODELDIR=$BASEDIR/src/main/thingml/
TARGETDIR=$BASEDIR/src-gen

function _docker
{
((WIN)) && export MSYS_NO_PATHCONV=1
timeout -k 300s 600s docker $@
((WIN)) && export MSYS_NO_PATHCONV=0
}
