#!/usr/bin/env bash

N=2

BINARY=1
((BINARY)) && TOOL=monitor-bin
((!BINARY)) && TOOL=monitor		 # posix/arduino cannot use string logging

LANGUAGES=(java graal nodejs nodejs_chakra go go_gccgo posix posix_clang) # Languages to use
MODES=(on off no) # Logging modes


DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
BASEDIR=$DIR/../../..
chmod -R 777 $BASEDIR
BASEMODELDIR=$BASEDIR/src/main/thingml
TARGETDIR=$BASEDIR/src-gen
