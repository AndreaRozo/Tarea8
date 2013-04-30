run: cond1.txt cond2.txt

cond1.txt: Graf*_CondIn1.txt ejecutable.exe
	paste VectorX_CondIn1.txt Graf*_CondIn1.txt > cond1.txt
	gnuplot graph1.gp

cond2.txt: Graf*_CondIn2.txt ejecutable.exe
	paste VectorX_CondIn2.txt Graf*_CondIn2.txt > cond2.txt
	gnuplot graph2.gp

Graf*_CondIn1.txt: ejecutable.exe
	./ejecutable.exe 0 1 0 3 0.00005 0.0125 1

Graf*_CondIn2.txt: ejecutable.exe
	./ejecutable.exe -5 5 0 3 0.00005 0.05 2

ejecutable.exe: main.o functions.o makefile
	cc main.o functions.o -o ejecutable.exe -lm

main.o: main.c
	cc -c main.c

functions.o: functions.c
	cc -c functions.c

clean:
	rm *.txt *.o *~ *.exe *.jpg *.gp

all: run

