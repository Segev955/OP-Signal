all: signal

signal: signal.c
	gcc -o signal signal.c


clean:
	rm -f *.o signal 
