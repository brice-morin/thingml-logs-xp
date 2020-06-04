#!/usr/bin/env bash
source setup.sh

# Make a clean output directory
mkdir -p $LOGSDIR
rm -r $LOGSDIR/* 2> /dev/null

function perform
{
  DIR=$1
  LANGUAGE=$2
  LOGS=$3
  i=$4

  cd $DIR
  docker build -t $LANGUAGE .
  _docker2 run --name $LANGUAGE-c --rm -v $LOGS:/data --cap-add=ALL $LANGUAGE:latest > $LOGS/$i.log
  docker rmi -f $LANGUAGE
}

### Generate platform code ###

for k in $(shuf --input-range=0-$(( ${#LANGUAGES[@]} - 1 ))); do
  LANGUAGE=${LANGUAGES[k]}
  mkdir -p $LOGSDIR/$LANGUAGE
  for i in `seq 0 $((N-1))`; do  
    echo "---- RUN $LANGUAGE : $i ----"
    perform $PLATFORMDIR/$LANGUAGE $LANGUAGE $LOGSDIR/$LANGUAGE $i        
  done
done