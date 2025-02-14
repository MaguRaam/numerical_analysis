# Gnuplot script to load data and plot points with stars

set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Set log scale for y axes
set logscale y

# Unset minor ticks along x and y
unset mxtics
unset mytics

# Set x and y range
set xrange [0:20]
set yrange [1e-16:10]

# Specify tick format to use scientific notation
set ytics format "10^{%L}" scale 2

# Set labels
set xlabel '$n$'

# Set legend at bottom left
set key bottom left

# Set line style
set style line 1 lc rgb '#ff7f0e' lt 1 lw 8  # Orange for n^(-1)

# Load data and plot with stars
plot 'output.dat' using 1:4 title '$|e - \sum_{i = 0}^n1/i!|$' with points pt 3 ps 3 lc rgb 'blue',\
                                1./gamma(x+2) with lines linestyle 1 title '$1/(n+1)!$'
