#!/usr/bin/env bash
source common.sh

cd $BASEDIR/src/main/docker
docker build -q -t thingml .
