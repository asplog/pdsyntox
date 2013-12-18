SUFFIXES: .poslemma .formmorpho .lemma2 .lemmamorpho .syntox

CLEANFILES = lefff.fsa lefff.tbl
BUILDLEXICON = ../../src/buildlexiconmain

all:
	@make lefff.fsa

%.poslemma: %.pos %.lemma
	paste $^ | tr '\t' '#' > $@

%.formmorpho: %.form %.predmorpho
	paste $^ | tr '\t' '#' > $@

%.pred: %.lemma
	sed 's/\(.*\)/PRED:\1,/' < $^ > $@

%.predmorpho: %.pred %.morpho
	paste $*.pred $*.morpho | sed -e 's/	//' -e 's/\(.*\)/[\1]/' > $@

%.syntox: %.poslemma %.formmorpho
	paste $^ > $@

%.fsa: %.syntox
	$(BUILDLEXICON) -d . -f $* build $<
