#!/usr/bin/env bash
source common.sh

function run_in_mode
{
  LANG=$1
  i=$2
  mode=$3
 
  cd $TARGETDIR/main/$mode/$LANG
  docker build -t thingml-$LANG-log-$mode .
  docker run --name thingml-$LANG-log-$mode_container thingml-$LANG-log-$mode &> $TARGETDIR/logs/$mode/thingml-$LANG-log$i.log
  docker rm -f thingml-$LANG-log-$mode_container
  docker rmi thingml-$LANG-log-$mode
}

function run
{
  LANG=$1
  i=$2
  
  run_in_mode $LANG $i on
  run_in_mode $LANG $i off
  run_in_mode $LANG $i no  
}

mkdir $TARGETDIR/logs
mkdir $TARGETDIR/logs/on
mkdir $TARGETDIR/logs/off
mkdir $TARGETDIR/logs/no

for i in `seq 0 $((N-1))`; do
  for LANGUAGE in ${LANGUAGES[@]}; do
    run $LANGUAGE $i
  done
done
