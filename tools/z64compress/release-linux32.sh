# build compression functions (slow)
gcc -m32 -DNDEBUG -s -Ofast -flto -lm -c -Wall -march=native -mtune=native src/enc/*.c src/enc/lzo/*.c src/enc/ucl/comp/*.c src/enc/apultra/*.c
mkdir -p o
mv *.o o

# build everything else
gcc -m32 -o z64compress -DNDEBUG src/*.c o/*.o src/enc/libdeflate/lib/deflate_compress.c src/enc/libdeflate/lib/utils.c -Isrc/enc/libdeflate -Wall -Wextra -s -Os -flto -lpthread -lz -march=native -mtune=native

# move to bin directory
mkdir -p bin/linux32
mv z64compress bin/linux32



