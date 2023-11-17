mkdir build

cd build

cmake -G "MinGW Makefiles" ..
make -j8
copy %CD%\GameOnConsole.uf2 E:\