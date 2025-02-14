# Gnuplot script to load data and plot points with stars

set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Set log scale for x axes
set logscale x

# Unset minor ticks along x
unset mxtics

# Set x and y range
set xrange [1:1e15]
set yrange [1.0:3.0]

# Scale tick size
set xtics format "10^{%L}" scale 2 
set ytics scale 2.0 

# Set labels
set xlabel '$n$'

# Load data and plot with stars
plot 'output.dat' using 1:2 title '$(1 + \frac{1}{n})^n$' with points pt 3 ps 3 lc rgb 'blue'
