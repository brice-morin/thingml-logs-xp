#!/usr/bin/env bash
source common.sh

function run_in_mode
{
  LANG=$1
  i=$2
  mode=$3
  TOOL=$4

  echo "--- $TOOL $LANG$i in mode $mode ---"

  cd $TARGETDIR/main/$TOOL/$mode/$LANG
  _docker build -t thingml-$TOOL-$LANG-log-$mode .
  _docker run --rm --name thingml-$TOOL-$LANG-log-$mode_container thingml-$TOOL-$LANG-log-$mode &> $TARGETDIR/logs/$TOOL/$mode/thingml-$LANG-log$i.log
  _docker rm -f thingml-$TOOL-$LANG-log-$mode_container
  _docker rmi thingml-$TOOL-$LANG-log-$mode
}

function run
{
  LANG=$1
  i=$2
  TOOL=$3
  for j in $(shuf --input-range=0-$(( ${#MODES[@]} - 1 ))); do
    run_in_mode $LANG $i ${MODES[j]} $TOOL
  done
}

mkdir -p $TARGETDIR/logs/$TOOL
mkdir $TARGETDIR/logs/$TOOL/on
mkdir $TARGETDIR/logs/$TOOL/off
mkdir $TARGETDIR/logs/$TOOL/no

for i in `seq 0 $((N-1))`; do
  for j in $(shuf --input-range=0-$(( ${#LANGUAGES[@]} - 1 ))); do
    run ${LANGUAGES[j]} $i "monitor"
    run ${LANGUAGES[j]} $i "monitor-bin"
  done
done
