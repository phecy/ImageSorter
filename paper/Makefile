# all    default, single latex
#
# d      complete dvi
#        latex, bibtex, outputs dvi
# dv     (visual)
#
# p      complete pdf:
#        makes a pdf from the dvi
# pv     (visual)
#
# b      bib:
#        silences everything except bib
# bv     (visual)
#
# g      graphviz:
#        create the main flowchart
# gv     (visual - eps only)

basic:
	latex README_PAPER

complete-dvi:
	latex README_PAPER
	bibtex README_PAPER
	latex README_PAPER
	latex README_PAPER

d: complete-dvi

dvi-visual: complete-dvi
	xdvi README_PAPER.dvi &

dv: dvi-visual

complete-pdf: complete-dvi
	dvipdf README_PAPER.dvi

p: complete-pdf

pdf-visual: complete-pdf
	gnome-open README_PAPER.pdf

pv: pdf-visual

bib-only:
	latex README_PAPER > /dev/null
	bibtex README_PAPER
	latex README_PAPER > /dev/null
	latex README_PAPER > /dev/null

b: bib-only

bib-visual: b
	xdvi README_PAPER.dvi &

bv: bib-visual

g:
	dot -Teps flowchart.graphviz > flowchart.eps

gv: g
	gnome-open flowchart.eps

commit:
	git commit README*

push:
	git push

git: commit push
