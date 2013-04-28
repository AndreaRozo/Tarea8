temp.txt: cond1.txt cond2.txt

cond1.txt:  Grafica*_CondIn1.txt ejecutable.exe
	pr -m -t -s Grafica*_CondIn1.txt | awk '{print $1,$2,$4,$6,$8,$10,$12,$14,$16,$18,$20}' > cond1.txt

cond2.txt: Grafica*_CondIn2.txt ejecutable.exe
	pr -m -t -s Grafica*_CondIn2.txt | awk '{print $1,$2,$4,$6,$8,$10,$12,$14,$16,$18,$20}' > cond2.txt

Grafica*_CondIn1.txt: ejecutable.exe
	./ejecutable.exe 0 1 0 3 0.00005 0.05 1

Grafica*_CondIn2.txt: ejecutable.exe
	./ejecutable.exe 0 1 0 3 0.00005 0.05 2

ejecutable.exe: main.o functions.o makefile
	cc main.o functions.o -o ejecutable.exe -lm 

main.o: main.c
	cc -c main.c

functions.o: functions.c
	cc -c functions.c

all: temp.txt

