#!/usr/bin/env bash
source common.sh

function generate
{
  LANG=$1
  docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $LANG --output /thingml-logs-xp/src-gen/main/$TOOL/on/$LANG --source /thingml-logs-xp/src-gen/main/thingml/monitor/$TOOL-$LANG.thingml
  docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $LANG --output /thingml-logs-xp/src-gen/main/$TOOL/off/$LANG --source /thingml-logs-xp/src-gen/main/thingml/monitor/$TOOL-$LANG-off.thingml
  docker run -v $BASEDIR:/thingml-logs-xp thingml --compiler $LANG --output /thingml-logs-xp/src-gen/main/$TOOL/no/$LANG --source /thingml-logs-xp/src/main/thingml/$LANG.thingml
}

for LANGUAGE in ${LANGUAGES[@]}; do
  generate $LANGUAGE &
done
wait