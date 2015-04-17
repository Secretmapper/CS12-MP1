rm -rf emcc-build
mkdir emcc-build 
emcc main.cpp 2048.cpp utility.cpp -o emcc-build/index.html
