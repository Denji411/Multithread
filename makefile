
all: main contatori report

main: src/main.c
	gcc -c src/main.c -Iinclude -o build/main.o

contatori: src/contatori.c
	gcc -c src/contatori.c -Iinclude -o build/contatori.o

report: src/report.c
	gcc -c src/report.c -Iinclude -o build/report.o

programma:
	gcc -Iinclude build/*.o -o bin/programma

clean:
	rm -f build/*.o bin/programma