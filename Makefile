CC=g++
CFLAGS=-std=c++11

all: lab3.exe

lab3.exe: lab3_funcs.o lab3_main.o lab1_funcs.o
	$(CC) $(CFLAGS) -o lab3.exe lab3_funcs.o  lab3_main.o lab1_funcs.o


lab3_funcs.o: lab3_funcs.cpp lab3_funcs.h
	$(CC) $(CFLAGS) -c lab3_funcs.cpp

lab1_funcs.o: lab1_funcs.cpp
		$(CC) $(CFLAGS) -c lab1_funcs.cpp

lab3_main.o: lab3_main.cpp lab3_funcs.h
	$(CC) $(CFLAGS) -c lab3_main.cpp

clean:
	rm *.exe *.o
