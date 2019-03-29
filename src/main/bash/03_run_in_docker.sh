#!/usr/bin/env bash
source common.sh

function run_in_mode
{
  LANG=$1
  i=$2
  mode=$3
 
  echo "--- $LANG$i in mode $mode ---"
 
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
  for j in $(shuf --input-range=0-$(( ${#MODES[@]} - 1 ))); do
    run_in_mode $LANG $i ${MODES[j]}
  done
}

mkdir $TARGETDIR/logs
mkdir $TARGETDIR/logs/on
mkdir $TARGETDIR/logs/off
mkdir $TARGETDIR/logs/no

for i in `seq 0 $((N-1))`; do
  for j in $(shuf --input-range=0-$(( ${#LANGUAGES[@]} - 1 ))); do
    run ${LANGUAGES[j]} $i
  done
done
