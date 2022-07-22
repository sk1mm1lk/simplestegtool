echo "Compiling and Linking"
gcc -I ../../include/simplestegtool/ ../../include/simplestegtool/*.o simple-lsb-multifile.c -o simple-lsb-multifile.out

echo "Running simple-lsb-multifile.out"
./simple-lsb-multifile.out testfile1.txt testfile2.txt
