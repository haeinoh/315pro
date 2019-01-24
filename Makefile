main: cstack.o convert.o main.o
	gcc -o main cstack.o convert.o main.o

main.o: cstack.h convert.h main.c
	gcc -c main.c

cstack.o: cstack.h cstack.c
	gcc -g -c cstack.c

convert.o: convert.h convert.c
	gcc -c convert.c

clean:
	rm -f main main.exe cstack.o convert.o main.o
