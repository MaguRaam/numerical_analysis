# Gnuplot script to load data and plot points with stars

set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Unset minor ticks along x
unset mxtics

# Set x and y range
set xrange [0:20]
set yrange [0:4.0]

# Scale tick size
set xtics scale 2 
set ytics scale 2.0 

# Set labels
set xlabel '$n$'

# Load data and plot with stars
plot 'output.dat' using 1:2 title '$\sum_{i = 0}^n1/i!$' with points pt 3 ps 3 lc rgb 'blue'
