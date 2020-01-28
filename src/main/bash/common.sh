#!/usr/bin/env bash

N=1

WIN=1	#Set to 1 if running on Windows and having problems with Docker volumes or paths...

LANGUAGES=(java nodejs go posix) # Languages to use
TOOLS=(monitor monitor-bin monitor-bin_string)
MODES=(on off no) # Logging modes

#((WIN)) && BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../ && pwd -W)
#((!WIN)) && BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../ && pwd)
BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../ && pwd)
chmod -R 777 $BASEDIR
echo "BASEDIR set to $BASEDIR"
BASEMODELDIR=$BASEDIR/src/main/thingml/
TARGETDIR=$BASEDIR/src-gen

function _docker
{
((WIN)) && export MSYS_NO_PATHCONV=1
echo "docker $@"
timeout -k 300s 600s docker $@
((WIN)) && export MSYS_NO_PATHCONV=0
}
