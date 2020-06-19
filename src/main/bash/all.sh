#!/usr/bin/env bash

source common.sh

./00_build_thingml.sh

export BASIC=1
./01_instrument_models.sh
./02_generate_code.sh
./03_run_in_docker.sh

mv $BASEDIR/src-gen $BASEDIR/src-gen-basic

export BASIC=0
./01_instrument_models.sh
./02_generate_code.sh
./03_run_in_docker.sh
