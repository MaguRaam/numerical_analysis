# Gnuplot script to load data and plot points with stars

set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Set log scale for x axes
set logscale xy

# Unset minor ticks along x and y
unset mxtics
unset mytics

# Set x and y range
set xrange [1:1e18]
set yrange [1e-16:2.0]

# Specify tick format to use scientific notation
set ytics format "10^{%L}" scale 2 
set xtics format "10^{%L}" scale 2

# Set labels
set xlabel '$n$'

# Set legend at bottom left
set key bottom left

# Set line style
set style line 1 lc rgb '#ff7f0e' lt 1 lw 8  # Orange for n^(-1)

# Load data and plot with stars
plot 'output.dat' using 1:3 title '$|e - (1 + \frac{1}{n})^n|$' with points pt 3 ps 3 lc rgb 'blue',\
                                x**(-1) with lines linestyle 1 title '$n^{-1}$
