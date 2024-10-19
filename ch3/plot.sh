#!/bin/bash
gnuplot power_function.gp
pdflatex --interaction=batchmode figure.tex
rm *.aux *.log *-inc.eps *.tex *converted-to.pdf