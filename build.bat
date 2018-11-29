:set TINYXML2_DIR=

if exist build rmdir /q /s build
mkdir build
cd build

set config=RelWithDebInfo

cmake ..\ -G "Visual Studio 15 2017 Win64" -Wno-dev -DCMAKE_CONFIGURATION_TYPES=%config%	|| echo cmake error! && exit %ERRORLEVEL%
cmake --build . --config %config%								|| echo cmake error! && exit %ERRORLEVEL%

cd ..
build\bin\RelWithDebInfo\lib1_tests.exe
build\bin\RelWithDebInfo\run_Lib1.exe
