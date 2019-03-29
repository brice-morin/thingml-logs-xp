#!/usr/bin/env bash
source common.sh

function instrument
{
  LANG=$1
  docker run -v $BASEDIR:/thingml-logs-xp thingml --tool monitor --output /thingml-logs-xp/src-gen/main/thingml --source /thingml-logs-xp/src/main/thingml/$LANG.thingml

  cd $TARGETDIR/main/thingml/monitor/

  #clean up
  rm -f temp.thingml
  mv merged.thingml $LANG.thingml
  cp $LANG.thingml $LANG-off.thingml

  #simulate a user instantiating the console logger
  head -n -1 $LANG.thingml > temp.thingml ; mv temp.thingml $LANG.thingml
  echo "set game.period = 3" >> $LANG.thingml
  echo "set game.DEBUG_ID = \"game\"" >> $LANG.thingml
  echo "instance log : ConsoleLogger" >> $LANG.thingml
  echo "set log.ACTIVATE_ON_STARTUP = true" >> $LANG.thingml
  echo "connector game.log => log.log" >> $LANG.thingml
  echo "}" >> $LANG.thingml
  
  head -n -1 $LANG-off.thingml > temp.thingml ; mv temp.thingml $LANG-off.thingml
  echo "set game.period = 3" >> $LANG-off.thingml
  echo "set game.DEBUG_ID = \"game\"" >> $LANG-off.thingml
  echo "instance log : ConsoleLogger" >> $LANG-off.thingml
  echo "set log.ACTIVATE_ON_STARTUP = false" >> $LANG-off.thingml
  echo "connector game.log => log.log" >> $LANG-off.thingml
  echo "}" >> $LANG-off.thingml  
}

for LANGUAGE in ${LANGUAGES[@]}; do
  instrument $LANGUAGE
done
