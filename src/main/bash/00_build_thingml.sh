#!/usr/bin/env bash
source common.sh

cd $BASEDIR/src/main/docker
docker build -t thingml .