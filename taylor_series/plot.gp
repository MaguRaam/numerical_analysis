# Gnuplot script to load data and plot a continuous line

set terminal pngcairo size 800,600 enhanced font 'Arial,12'
set output 'figure.png'

# Set x and y range
set xrange [0:1]
set yrange [0:3.0]

# Scale tick size
set xtics scale 2 
set ytics scale 2 

# Set labels
set xlabel 'x'

# Load data and plot as a line
plot 'data.txt' using 1:2 title 'exp(x)' with lines lw 2 lc rgb 'blue', \
     'data.txt' using 1:3 title 'Taylor Polynomial' with lines lw 2 lc rgb 'red'

