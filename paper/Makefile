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
#        create both flowcharts
# gv1    (visual - eps only - main only)
# gv2    (visual - eps only - ml only)
# gvh    (visual - eps only - highlevel only)
# gvl    (visual - eps only - lowlevel only)

LATEX=latex -output-directory=build paper
BIBTEX=bibtex build/paper

basic:
	${LATEX}

complete-dvi:
	${LATEX}
	${BIBTEX}
	${LATEX}
	${LATEX}

d: complete-dvi

dvi-visual: complete-dvi
	gnome-open build/paper.dvi &

dv: dvi-visual

complete-pdf: complete-dvi
	dvipdf build/paper.dvi build/paper.pdf

p: complete-pdf

pdf-visual: complete-pdf
	gnome-open build/paper.pdf

pv: pdf-visual

bib-only:
	${LATEX} > /dev/null
	${BIBTEX}
	${LATEX} > /dev/null
	${LATEX} > /dev/null

b: bib-only

bib-visual: b
	xdvi build/paper.dvi &

bv: bib-visual

g:
	cd figures
	dot -Teps flowchart.graphviz > flowchart.eps
	dot -Teps mlflowchart.graphviz > mlflowchart.eps
	dot -Teps mlhighlevel.graphviz > mlhighlevel.eps
	dot -Teps mllowlevel.graphviz > mllowlevel.eps
	epstopdf flowchart.eps
	pstopdf mlflowchart.eps
	epstopdf mlhighlevel.eps
	epstopdf mllowlevel.eps
	cd ..

gv1: g
	gnome-open flowchart.eps
gv2: g
	gnome-open mlflowchart.eps
gvh: g
	gnome-open mlhighlevel.eps
gvl: g
	gnome-open mllowlevel.eps

commit:
	git commit figures/*graphviz *tex

push:
	git push

git: commit push
