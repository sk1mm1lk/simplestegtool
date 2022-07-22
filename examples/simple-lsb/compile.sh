echo "Compiling and Linking"
gcc -I ../../include/simplestegtool/ ../../include/simplestegtool/*.o simple-lsb.c -o simple-lsb.out

echo "Running simple-lsb.out"
./simple-lsb.out testfile1.txt
