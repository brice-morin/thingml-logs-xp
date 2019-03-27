#!/usr/bin/env bash
source common.sh

function run
{
  LANG=$1
  i=$2
  cd $TARGETDIR/main/on/$LANG
  docker build -t thingml-$LANG-log-on .
  docker run --name thingml-$LANG-log-on_container thingml-$LANG-log-on > $TARGETDIR/logs/on/thingml-$LANG-log$i.log
  docker rm -f thingml-$LANG-log-on_container
  docker rmi thingml-$LANG-log-on
  
  cd $TARGETDIR/main/off/$LANG
  docker build -t thingml-$LANG-log-off .
  docker run --name thingml-$LANG-log-off_container thingml-$LANG-log-off > $TARGETDIR/logs/off/thingml-$LANG-log$i.log
  docker rm -f thingml-$LANG-log-off_container
  docker rmi thingml-$LANG-log-off
    
  cd $TARGETDIR/main/no/$LANG
  docker build -t thingml-$LANG-log-no .
  docker run --name thingml-$LANG-log-no_container thingml-$LANG-log-no > $TARGETDIR/logs/no/thingml-$LANG-log$i.log
  docker rm -f thingml-$LANG-log-no_container
  docker rmi thingml-$LANG-log-no
}

mkdir $TARGETDIR/logs
mkdir $TARGETDIR/logs/on
mkdir $TARGETDIR/logs/off
mkdir $TARGETDIR/logs/no

for i in `seq 0 $((N-1))`; do
  for LANGUAGE in ${LANGUAGES[@]}; do
    run $LANGUAGE $i &
  done
  wait
done
