#!/usr/bin/env bash
source setup.sh

# Make a clean output directory
mkdir -p $PLATFORMDIR
rm -r $PLATFORMDIR/* 2> /dev/null

### Generate platform code ###
logo
for LANGUAGE in ${LANGUAGES[@]}; do
  mkdir -p $PLATFORMDIR/$LANGUAGE
  echo "-- GENERATING CODE FOR $LANGUAGE --"
  
  COMPILER=`echo $LANGUAGE | cut -d'_' -f1`
  
  _docker run --rm -v $BASEDIR:/thingml-div thingml-div thingml -c $COMPILER -s /thingml-div/src/main/resources/experiments1/perf/$LANGUAGE.thingml -o /thingml-div/target/code/$LANGUAGE  
  _docker run --rm -v $BASEDIR:/thingml-div --entrypoint /bin/sh thingml-div -c "cd /thingml-div/target/code/$LANGUAGE/base && cloc . > cloc.log"
done
wait
