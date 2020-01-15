#!/usr/bin/env bash

N=1

BINARY=0
((BINARY)) && TOOL=monitor-bin
((!BINARY)) && TOOL=monitor		 # posix/arduino cannot use string logging

#LANGUAGES=(java nodejs go posix) # Languages to use
LANGUAGES=(java nodejs go)
MODES=(on off no) # Logging modes


DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
BASEDIR=$DIR/../../..
chmod -R 777 $BASEDIR
BASEMODELDIR=$BASEDIR/src/main/thingml
TARGETDIR=$BASEDIR/src-gen
