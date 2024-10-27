#!/bin/bash

# Check if a gnuplot file argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <gnuplot_script>"
    exit 1
fi

gnuplot $1
pdflatex --interaction=batchmode figure.tex
rm *.aux *.log *-inc.eps *.tex *converted-to.pdf
open figure.pdf
