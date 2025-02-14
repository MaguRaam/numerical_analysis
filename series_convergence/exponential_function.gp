# Gnuplot script to plot exponential functions

set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Set x and y range
set xrange [0:10]
set yrange [0:1]

# Scale tick size
set xtics scale 2.0  
set ytics scale 2.0  

# Customize x and y ticks
set xtics 2  # Set x-ticks every 2 units
set ytics 0.2  # Set y-ticks every 0.2 units

# Set xlabel
set xlabel '$n$'

# Set line styles with new colors
set style line 1 lc rgb '#1f77b4' lt 1 lw 8
set style line 2 lc rgb '#ff7f0e' lt 1 lw 8
set style line 3 lc rgb '#2ca02c' lt 1 lw 8
set style line 4 lc rgb '#FF00FF' lt 1 lw 8

# Plot power functions
plot 2.0**(-x) with lines linestyle 1 title '$2^{-n}$', \
     3.0**(-x) with lines linestyle 2 title '$3^{-n}$', \
     1./gamma(x+2) with lines linestyle 3 title '$1/(n+1)!$', \
     2.0**(-2**x) with lines linestyle 4 title '$2^{-(2^n)}$'
