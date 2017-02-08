CLFAGS= -O3

.Phony: all clean

all: clean ex1 ex2 ex3

ex1: ex1.c
	gcc $(CLFAGS) ex1.c -o ex1
	
ex2: ex2.c
	gcc $(CLFAGS) ex2.c -o ex2 -lm
	
ex3: ex3.c
	gcc $(CLFAGS) ex3.c -o ex3 -lm
	
clean:
	rm -f ex1
	rm -f ex2
	rm -f ex3
