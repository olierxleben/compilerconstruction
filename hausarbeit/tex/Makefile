
MAIN = main
PDFLATEX = $(shell which pdflatex)
BIBTEX = $(shell which bibtex)

TEMPFILES = main.aux main.bbl main.blg main.log main.toc

# Zum endgültigen Bauen muss Bibtex gelaufen sein.
all: bibliography
	$(PDFLATEX) $(MAIN)

# Vor Bibtex erstmal einma pdflatex laufen lassen.
prerun:
	$(PDFLATEX) $(MAIN)

# BibTex muss unter Umständen zweimal laufen. Außerdem muss
# zuerst einmal Pdflatex gelaufen sein.
bibliography: prerun
	$(BIBTEX) $(MAIN)
	$(BIBTEX) $(MAIN)

# Alles weg, was keine Miete zahlt.
clean:
	rm $(TEMPFILES)
