#!/usr/bin/env bash
source common.sh

function instrument
{
  LANG=$1
  
  docker run -v $BASEDIR:/thingml-logs-xp thingml --tool $TOOL --output /thingml-logs-xp/src-gen/main/thingml --source /thingml-logs-xp/src/main/thingml/$LANG.thingml

  cd $TARGETDIR/main/thingml/monitor/

  #clean up
  rm -f temp.thingml
  mv merged.thingml $TOOL-$LANG.thingml
  cp $TOOL-$LANG.thingml $TOOL-$LANG-off.thingml
  
  if [ "$LANGUAGE" == "nodejs" ] || [ "$LANGUAGE" == "java" ] || [ "$LANGUAGE" == "graal" ]; then
  	HAS_SIGNED_BYTE=1
  else
  	HAS_SIGNED_BYTE=0  
  fi

  #simulate a user instantiating the console logger
  configure $TOOL-$LANG.thingml "true"
  configure $TOOL-$LANG-off.thingml "false"
}

function configure
{
  THINGML_FILE=$1
  IS_ON=$2
	
  head -n -1 $THINGML_FILE > temp.thingml ; mv temp.thingml $THINGML_FILE
  echo "set game.period = 3" >> $THINGML_FILE
  echo "set game.QUIET = true" >> $THINGML_FILE
  ((!BINARY)) && echo "set game.DEBUG_ID = \"game\"" >> $THINGML_FILE
  ((BINARY)) && echo "set game.DEBUG_BIN_ID = 0" >> $THINGML_FILE  
  echo "instance log : ConsoleLogger" >> $THINGML_FILE
  ((BINARY)) && echo "set log.QUIET = true" >> $THINGML_FILE
  ((BINARY)) && ((HAS_SIGNED_BYTE)) && echo "set log.HAS_SIGNED_BYTE = true" >> $THINGML_FILE
  ((BINARY)) && ((!HAS_SIGNED_BYTE)) && echo "set log.HAS_SIGNED_BYTE = false" >> $THINGML_FILE
  echo "set log.ACTIVATE_ON_STARTUP = $IS_ON" >> $THINGML_FILE
  echo "connector game.log => log.log" >> $THINGML_FILE
  echo "}" >> $THINGML_FILE 
}

for LANGUAGE in ${LANGUAGES[@]}; do
  instrument $LANGUAGE
done
