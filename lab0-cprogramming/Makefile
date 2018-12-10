CC = gcc
CFLAGS = -O0 -g -Wall 


all: testmain

queue.o: queue.c queue.h 
	$(CC) $(CFLAGS) -c queue.c

testmain: queue.o
	$(CC) $(CFLAGS) -o testmain testmain.c queue.o

clean:
	rm -f *.o 