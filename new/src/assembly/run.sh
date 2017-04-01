#!/bin/bash

DIR=$(cd `dirname $0`; pwd)

export LD_LIBRARY_PATH=$DIR/lib
echo "SET LD_LIBRARY_PATH: $LD_LIBRARY_PATH"

cd $DIR

./09001Color
