set term wxt
set xlabel 'TAille du Tableau'
set ylabel 'Temp (ms)'
set title 'Performance des Algorithme de tri'
set key outside

# Define line colors and styles
set style line 1 lc rgb 'blue' lw 2
set style line 2 lc rgb 'red' lw 2
set style line 3 lc rgb 'green' lw 2
set style line 4 lc rgb 'orange' lw 2
set style line 5 lc rgb 'purple' lw 2
set style line 6 lc rgb 'brown' lw 2
set style line 6 lc rgb 'yellow' lw 2


plot 'donnees.txt' using 1:2 title 'bulle' with lines linestyle 1, \
          '' using 1:3 title 'Insertion' with lines linestyle 2, \
     '' using 1:4 title 'rapide' with lines linestyle 3, \
     '' using 1:5 title 'Selection' with lines linestyle 4, \
     '' using 1:6 title 'tas' with lines linestyle 5, \
     '' using 1:7 title 'base' with lines linestyle 6, \
     '' using 1:8 title 'comptage' with lines linestyle 7
set output 'tri.png'
pause -1 "Press enter to exit"
