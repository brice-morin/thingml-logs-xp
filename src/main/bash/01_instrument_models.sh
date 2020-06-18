#!/usr/bin/env bash
source common.sh

function instrument
{
  LANG=$1
  TOOL=$2
  BINARY=$3
  LOGGER=$4
  
  THINGMLTOOL=`echo $TOOL | cut -d'_' -f1`

  echo $BASEDIR
  
  ((BASIC)) && SOURCE=/thingml/src/main/thingml/basic/$LANG.thingml
  ((!BASIC)) && SOURCE=/thingml/src/main/thingml/$LANG.thingml

  _docker run -v /$BASEDIR:/thingml thingml --tool $THINGMLTOOL --output /thingml/src-gen/main/thingml --source $SOURCE

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
  configure $TARGETDIR/main/thingml/monitor/$TOOL-$LANG.thingml "true" $BINARY $LOGGER
  configure $TARGETDIR/main/thingml/monitor/$TOOL-$LANG-off.thingml "false" $BINARY $LOGGER
}

function configure
{
  THINGML_FILE=$1
  IS_ON=$2
  BINARY=$3
  LOGGER=$4

  head -n -1 $THINGML_FILE > temp.thingml ; mv temp.thingml $THINGML_FILE
  ((!BASIC)) && echo "set main.period = 3" >> $THINGML_FILE
  ((!BASIC)) && echo "set main.QUIET = true" >> $THINGML_FILE
  ((!BINARY)) && echo "set main.DEBUG_ID = \"game\"" >> $THINGML_FILE
  ((BINARY)) && echo "set main.DEBUG_BIN_ID = 0" >> $THINGML_FILE
  echo "instance log : $LOGGER" >> $THINGML_FILE
  ((BINARY)) && ((HAS_SIGNED_BYTE)) && echo "set log.HAS_SIGNED_BYTE = true" >> $THINGML_FILE
  ((BINARY)) && ((!HAS_SIGNED_BYTE)) && echo "set log.HAS_SIGNED_BYTE = false" >> $THINGML_FILE
  echo "set log.ACTIVATE_ON_STARTUP = $IS_ON" >> $THINGML_FILE
  echo "connector main.log => log.log" >> $THINGML_FILE
  echo "}" >> $THINGML_FILE
}

for LANGUAGE in ${LANGUAGES[@]}; do
  instrument $LANGUAGE "monitor" 0 "ConsoleLogger"
  instrument $LANGUAGE "monitor-bin" 1 "ConsoleLogger"
  instrument $LANGUAGE "monitor-bin_string" 1 "Binary2StringLogger"
done
