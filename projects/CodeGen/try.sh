make
./csimple < tests/test1.lang > csimple.s
gcc -c -m32 -o csimple.o csimple.s
gcc -c -m32 -o start.o start.c
gcc -m32 -o start start.o csimple.o
./start