CC=g++
CFLAGS=-std=c++11

all: lab2.exe

lab2.exe: lab2_funcs.o lab2_main.o  
	$(CC) $(CFLAGS) -o lab2.exe lab2_funcs.o  lab2_main.o


lab2_funcs.o: lab2_funcs.cpp lab2_funcs.h
	$(CC) $(CFLAGS) -c lab2_funcs.cpp



lab2_main.o: lab2_main.cpp lab2_funcs.h
	$(CC) $(CFLAGS) -c lab2_main.cpp

clean:
	rm *.exe *.o
