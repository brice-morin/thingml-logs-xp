#!/usr/bin/env bash

source common.sh

./00_build_thingml.sh

./01_instrument_models.sh 1
./02_generate_code.sh 1
./03_run_in_docker.sh 1

mv $BASEDIR/src-gen $BASEDIR/src-gen-basic
_docker rm -f $(_docker ps -aq)

./01_instrument_models.sh 1
./02_generate_code.sh 1
./03_run_in_docker.sh 1

_docker rm -f $(_docker ps -aq)