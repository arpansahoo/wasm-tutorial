CC = g++
CFLAGS = -Wall -Wextra -pedantic -emit-llvm --target=wasm32 -Oz

functions.bc: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp -o functions.bc
