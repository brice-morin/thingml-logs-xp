#!/usr/bin/env bash

N=100

LANGUAGES=(java nodejs go) # Languages to use
MODES=(on off no) # Logging modes


DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
BASEDIR=$DIR/../../..
chmod -R 777 $BASEDIR
BASEMODELDIR=$BASEDIR/src/main/thingml
TARGETDIR=$BASEDIR/src-gen
