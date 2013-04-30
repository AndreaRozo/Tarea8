set terminal jpeg
set output 'GraficaCondInicial2.jpg'
set title "Caso 2"
set xlabel "x"
set ylabel "u"
plot 'cond2.txt' using 1:2, '' using 1:3, '' using 1:4, '' using 1:5, '' using 1:6, '' using 1:7, ''using 1:8, '' using 1:9, '' using 1:10, '' using 1:11, '' using 1:12
