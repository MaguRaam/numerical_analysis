# Gnuplot script to plot exponential functions

set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Set log scale for both axes
set logscale y

# Set x and y range
set xrange [1:60]
set yrange [1e-20:1]

# Specify y tick format to use scientific notation
set ytics format "10^{%L}" scale 2 

# Specify x tick
set xtics 10 scale 2

# Unset minor ticks along x
unset mytics
unset mxtics

# Set xlabel
set xlabel '$n$'

# Set line styles with new colors
set style line 1 lc rgb '#1f77b4' lt 1 lw 8
set style line 2 lc rgb '#ff7f0e' lt 1 lw 8
set style line 3 lc rgb '#2ca02c' lt 1 lw 8
set style line 4 lc rgb '#D96AA0' lt 1 lw 8 

# Plot power functions
plot 2.0**(-x) with lines linestyle 1 title '$2^{-n}$', \
     3.0**(-x) with lines linestyle 2 title '$3^{-n}$', \
     1./gamma(x+2) with lines linestyle 3 title '$1/(n+1)!$', \
     2.0**(-2**x) with lines linestyle 4 title '$2^{-(2^n)}$'