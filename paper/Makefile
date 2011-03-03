all:
	latex README_PAPER
	bibtex README_PAPER
	latex README_PAPER
	latex README_PAPER

f:
	latex README_PAPER

b:
	latex README_PAPER > /dev/null
	bibtex README_PAPER
	latex README_PAPER > /dev/null
	latex README_PAPER > /dev/null

bv: b
	xdvi README_PAPER.dvi

fv: f
	xdvi README_PAPER.dvi
