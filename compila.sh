rm -rf build && mkdir build
cd build
gcc -c ../app/router.c
gcc -c ../src/util.c
gcc -c ../src/terminal.c
gcc -c ../src/read_file.c
gcc -o Router router.o terminal.o util.o read_file.o -lm -pthread
