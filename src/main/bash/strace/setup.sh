#!/usr/bin/env bash

N=1

WIN=1	#Set to 1 if running on Windows and having problems with Docker volumes or paths...

LANGUAGES=(java_11_hotspot java_11_openj9 java_8_hotspot java_8_openj9 graal nodejs nodejs_chakra go go_gccgo posix posix_clang posixmt posixmt_clang)

BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../../../../ && pwd)


BASEMODELDIR=$BASEDIR/src/main/resources/thingml

TARGETDIR=$BASEDIR/target
PLATFORMDIR=$TARGETDIR/code
LOGSDIR=$TARGETDIR/logs

function _docker
{
((WIN)) && export MSYS_NO_PATHCONV=1
timeout -k 300s 600s docker $@
((WIN)) && export MSYS_NO_PATHCONV=0
}

function _docker2
{
((WIN)) && export MSYS_NO_PATHCONV=1
timeout -k 15s 45s docker $@
((WIN)) && export MSYS_NO_PATHCONV=0
}
