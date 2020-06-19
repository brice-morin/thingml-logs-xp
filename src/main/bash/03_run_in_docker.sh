#!/usr/bin/env bash
source common.sh

function run_in_mode
{
  LANG=$1
  i=$2
  mode=$3
  TOOL=$4

  txt="|--- $TOOL $LANG$i in mode $mode ---|"
  echo ""
  printf '%0.s-' $(seq 1 ${#txt})
  echo ""
  echo $txt
  printf '%0.s-' $(seq 1 ${#txt})
  echo ""
  echo ""

  cd $TARGETDIR/main/$TOOL/$mode/$LANG
  _docker build -q -t thingml-$TOOL-$LANG-log-$mode .
  _docker run --rm --name thingml-$TOOL-$LANG-log-$mode_container thingml-$TOOL-$LANG-log-$mode &> $TARGETDIR/logs/$TOOL/$mode/${LANG}_${i}.log
  #echo "===>"
  #head -n 10 $TARGETDIR/logs/$TOOL/$mode/thingml-$LANG-log$i.log
  #echo "..."
  #tail -n 10 $TARGETDIR/logs/$TOOL/$mode/thingml-$LANG-log$i.log
  #echo "<==="
  #_docker rm -f thingml-$TOOL-$LANG-log-$mode_container &> /dev/null
  _docker rmi thingml-$TOOL-$LANG-log-$mode &> /dev/null
}

mkdir -p $TARGETDIR/logs/monitor
mkdir $TARGETDIR/logs/monitor/on
mkdir $TARGETDIR/logs/monitor/off
mkdir $TARGETDIR/logs/monitor/no

mkdir -p $TARGETDIR/logs/monitor-bin
mkdir $TARGETDIR/logs/monitor-bin/on
mkdir $TARGETDIR/logs/monitor-bin/off
mkdir $TARGETDIR/logs/monitor-bin/no

mkdir -p $TARGETDIR/logs/monitor-bin_string
mkdir $TARGETDIR/logs/monitor-bin_string/on
mkdir $TARGETDIR/logs/monitor-bin_string/off
mkdir $TARGETDIR/logs/monitor-bin_string/no

for i in `seq 0 $((N-1))`; do
  for j in $(shuf --input-range=0-$(( ${#LANGUAGES[@]} - 1 ))); do
    for k in $(shuf --input-range=0-$(( ${#TOOLS[@]} - 1 ))); do
      for l in $(shuf --input-range=0-$(( ${#MODES[@]} - 1 ))); do
         run_in_mode ${LANGUAGES[j]} $i ${MODES[l]} ${TOOLS[k]}
      done
  	done
  done
done
