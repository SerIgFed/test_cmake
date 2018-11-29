#!/bin/bash

TINYXML2_DIR=

config=RelWithDebInfo
blddir=build

if [ -d blddir ]; then
   rm -rf $blddir
fi;
mkdir -p $blddir;
cd    $blddir

cmake ../ -G "Unix Makefiles" -Wno-dev -DCMAKE_CONFIGURATION_TYPES=%config%

cmakeResult=$?
if [ $cmakeResult != "0" ] ; then
  echo -e "CMake project generation failed with status $cmakeResult"
  exit;
fi;

cmake --build . --config %config%

cmakeResult=$?
if [ $cmakeResult != "0" ] ; then
  echo -e "CMake project build failed with status $cmakeResult"
  exit;
fi;

cd ..
chmod 777 ./$blddir/bin

./$blddir/bin/lib1_tests
./$blddir/bin/run_Lib1
