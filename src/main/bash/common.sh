#!/usr/bin/env bash

N=10

WIN=1	#Set to 1 if running on Windows and having problems with Docker volumes or paths...

LANGUAGES=(java graal nodejs nodejs_chakra go go_gccgo posix posix_clang) # Languages to use
MODES=(on off no) # Logging modes

((WIN)) && BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../ && pwd -W)
((!WIN)) && BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../ && pwd)
chmod -R 777 $BASEDIR
BASEMODELDIR=$BASEDIR/src/main/thingml/
TARGETDIR=$BASEDIR/src-gen

function _docker
{
((WIN)) && export MSYS_NO_PATHCONV=1
timeout -k 300s 600s docker $@
((WIN)) && export MSYS_NO_PATHCONV=0
}
