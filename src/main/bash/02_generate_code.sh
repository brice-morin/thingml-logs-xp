#!/usr/bin/env bash
source common.sh

function generate
{
  LANG=$1
  TOOL=$2
  COMPILER=`echo $LANGUAGE | cut -d'_' -f1`
  
  ((BASIC)) && BASESOURCE=/thingml-logs-xp/src/main/thingml/basic/$LANG.thingml
  ((!BASIC)) && BASESOURCE=/thingml-logs-xp/src/main/thingml/$LANG.thingml
  
  _docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $COMPILER --output /thingml-logs-xp/src-gen/main/$TOOL/on/$LANG --source /thingml-logs-xp/src-gen/main/thingml/monitor/$TOOL-$LANG.thingml
  _docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $COMPILER --output /thingml-logs-xp/src-gen/main/$TOOL/off/$LANG --source /thingml-logs-xp/src-gen/main/thingml/monitor/$TOOL-$LANG-off.thingml
  _docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $COMPILER --output /thingml-logs-xp/src-gen/main/$TOOL/no/$LANG --source $BASESOURCE
}

for LANGUAGE in ${LANGUAGES[@]}; do
  for TOOL in ${TOOLS[@]}; do
    generate $LANGUAGE $TOOL &  
  done
done
wait
