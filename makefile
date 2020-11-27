all: work13.o
	gcc -o work13 work13.o
work13.o: work13.c
	gcc -c work13.c
run:
	./work13