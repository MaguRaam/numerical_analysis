set terminal epslatex standalone size 10cm,8cm color colortext 12
set output 'figure.tex'

# Set log scale for both axes
set logscale xy

# Set range for x-axis
set xrange [1:1e6]

# Specify tick format to use scientific notation
set ytics format "10^{%L}" scale 2 
set xtics format "10^{%L}" scale 2

# Unset minor ticks along y and x
unset mytics
unset mxtics

# Set legend at bottom left
set key bottom left

# Set x-axis label
set xlabel '$n$'

# Set line styles with custom colors and widths
set style line 1 lc rgb '#1f77b4' lt 1 lw 8  # Blue for n^(-1/2)
set style line 2 lc rgb '#ff7f0e' lt 1 lw 8  # Orange for n^(-1)
set style line 3 lc rgb '#2ca02c' lt 1 lw 8  # Green for n^(-2)
set style line 4 lc rgb '#D96AA0' lt 1 lw 8  # Pink for n^(-4)

# Plot the power functions with log scale
plot x**(-0.5) with lines linestyle 1 title '$n^{-1/2}$', \
     x**(-1) with lines linestyle 2 title '$n^{-1}$', \
     x**(-2) with lines linestyle 3 title '$n^{-2}$', \
     x**(-4) with lines linestyle 4 title '$n^{-4}$'
