#!/usr/bin/env bash
source common.sh

function generate
{
  LANG=$1
  TOOL=$2
  COMPILER=`echo $LANGUAGE | cut -d'_' -f1`
  _docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $COMPILER --output /thingml-logs-xp/src-gen/main/$TOOL/on/$LANG --source /thingml-logs-xp/src-gen/main/thingml/monitor/$TOOL-$LANG.thingml
  _docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $COMPILER --output /thingml-logs-xp/src-gen/main/$TOOL/off/$LANG --source /thingml-logs-xp/src-gen/main/thingml/monitor/$TOOL-$LANG-off.thingml
  _docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $COMPILER --output /thingml-logs-xp/src-gen/main/$TOOL/no/$LANG --source /thingml-logs-xp/src/main/thingml/$LANG.thingml
}

for LANGUAGE in ${LANGUAGES[@]}; do
  generate $LANGUAGE "monitor" &
  generate $LANGUAGE "monitor-bin" &
done
wait
