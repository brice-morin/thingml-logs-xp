#!/usr/bin/env bash

N=1

BASIC=$1 #Use basic example or big one

WIN=1	#Set to 1 if running on Windows and having problems with Docker volumes or paths...

LANGUAGES=(java_8_hotspot nodejs go posix) # Languages to use
TOOLS=(monitor-bin monitor-bin_string monitor)
MODES=(on off no) # Logging modes

BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../ && pwd)
chmod -R 777 $BASEDIR
echo "BASEDIR set to $BASEDIR"
BASEMODELDIR=$BASEDIR/src/main/thingml/basic/
TARGETDIR=$BASEDIR/src-gen

function _docker
{
((WIN)) && export MSYS_NO_PATHCONV=1
timeout -k 300s 600s docker $@
((WIN)) && export MSYS_NO_PATHCONV=0
}
