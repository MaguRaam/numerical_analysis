# Gnuplot script to plot power functions

set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Set x and y range
set xrange [1:10]
set yrange [0:1]

# Scale tick size
set xtics scale 2.0  
set ytics scale 2.0  

# Customize x and y ticks
set xtics 2  # Set x-ticks every 1 unit
set ytics 0.2  # Set y-ticks every 0.1 units

# Set xlabel
set xlabel '$n$'

# Set line styles with new colors
set style line 1 lc rgb '#1f77b4' lt 1 lw 8  # Blue for n^(-1/2)
set style line 2 lc rgb '#ff7f0e' lt 1 lw 8  # Orange for n^(-1)
set style line 3 lc rgb '#2ca02c' lt 1 lw 8  # Green for n^(-2)
set style line 4 lc rgb '#FF00FF' lt 1 lw 8  # Magenta for n^(-4)

# Plot power functions
plot x**(-0.5) with lines linestyle 1 title '$n^{-1/2}$', \
     x**(-1) with lines linestyle 2 title '$n^{-1}$', \
     x**(-2) with lines linestyle 3 title '$n^{-2}$', \
     x**(-4) with lines linestyle 4 title '$n^{-4}$'
