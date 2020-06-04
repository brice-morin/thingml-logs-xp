#!/usr/bin/env bash
source setup.sh

cd $BASEDIR/src/main/docker
docker build -t thingml .