make all
#echo "##############"
#./src/syntox -grammarFile data/p1.grammar -lexiconFile data/p1.lexicon -inputFile data/p1.input
#echo ""
#echo "##############"
#./src/syntox -grammarFile data/p2.grammar -lexiconFile data/p2.lexicon -inputFile data/p2.input
#echo ""
#echo "##############"
#./src/syntox -grammarFile data/p2.grammar -lexiconFile data/p2.lexicon -input 'Axiom [PRED:commander, diathese:active, subj:[PRED:pro, person:one, number:sg], obj:[PRED:article, number:sg, def:yes]]'
#echo ""
#echo "##############"
#./src/syntox -grammar 'Axiom → T dot T; T → a b c;' -lexicon 'a a[];b b[];c c[];"." dot[];' -input 'Axiom[]'
#echo ""
#echo "##############"
#./src/syntox -grammarFile data/p4.grammar -lexiconFile data/p4.lexicon -inputFile data/p4.input
#echo ""
#echo "##############"
#./src/syntox -grammarFile data/p5.grammar -lexiconFile data/p5.lexicon -compactLexiconDirectory data/lefff -compactLexiconFile lefff -input 'S [PRED:tournicoter,tense:present,mode:indicative,subj:[PRED:_pro_]]' -dotitems tmp.1.dot -dotforest tmp.2.dot
#echo ""
#echo "##############"
#./src/syntox -grammarFile data/p5.grammar -lexiconFile data/p5.lexicon -compactLexiconDirectory data/lefff -compactLexiconFile lefff -input 'S [PRED:admirer,tense:present,mode:indicative,subj:[FORM:"Babar"],obj:[FORM:"Celeste"]]' -dotitems tmp.1.dot -dotforest tmp.2.dot
#echo ""
#echo "##############"
#./src/syntox -grammar 'Axiom → T dot T; T → a b c {↓1 := [att2:2];};' -lexicon 'a(att1, att2) a[att1:1];b b[];c c[];"." dot;' -input 'Axiom'
#echo ""
#echo "##############"
./src/syntox -grammarFile data/p6.grammar -lexiconFile data/p6.lexicon -input 'S' --verbose
echo ""
echo "##############"
