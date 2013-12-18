<?php

$gr='
Axiom → T dot
{
	↓1 := ↑ ∪ [mood:indicative];
};

T → T comma parConséquent T
{
	[PRED:cause, arg1:Arg1, arg2:Arg2];
	[tense:Tense, aspect:Aspect, tenseCause:TenseCause, aspectCause:AspectCause, tenseEffect:TenseEffect, aspectEffect:AspectEffect] < ↑;
	↓1 := Arg1 ∪ [mood:indicative, tense:Tense, aspect:Aspect] ∪ [tense:TenseCause, aspect:AspectCause];
	↓4 := Arg2 ∪ [mood:indicative, tense:Tense, aspect:Aspect] ∪ [tense:TenseEffect, aspect:AspectEffect];
};

T → T dot T
{
	[PRED:succession, arg1:Arg1, arg2:Arg2];
	↓1 := Arg1 ∪ [mood:indicative];
	↓3 := Arg2 ∪ [mood:indicative];
};

/***
T → T comma cependant T
{
	[PRED:contradiction, arg1:Arg1, arg2:Arg2];
	↓1 := Arg1 ∪ [mood:indicative];
	↓4 := Arg2 ∪ [mood:indicative];
};

T → siCependant T comma alors T
{
	[PRED:cependant, arg1:Arg1, arg2:Arg2];
	↓2 := Arg1 ∪ [mood:indicative];
	↓5 := Arg2 ∪ [mood:indicative];
};

***/
T → S
{
	[modS:NIL];
	↓1 := ↑;
};

T → NP
{
	[modS:NIL];
	↓1 := ↑ ∪ [det:+];
};

T → time comma T
{
	[modS:(Head::Tail), Rest];
	↓1 := Head ∪ [time:date];
	↓3 := Rest ∪ [mod:Tail];
};

T → T lap
{
	[modS:(Head::Tail), Rest];
	↓1 := Rest ∪ [mod:Tail];
	↓2 := Head ∪ [time:lap];
};

lap →  de time à time
{
	[PRED:from_to, arg1:A, arg2:B];
	↓2 := A;
	↓4 := B;
};

S → NP|cln|Empty VP
{
	[subj:S, Rest];
	↓1 := S ∪ [strong:-];
	SyntS := ⇓1 ∪ [det:+];
	↓2 := Rest ∪ [subj:SyntS];
};

NP → (det) N2
{
    [num:NIL];
    order ↓2 ↓1 ;
    ↓2 := ↑;
    if (↓1) {
       ↓1 := ↑ ∪ ⇓2;
       ⇑ := ↑ ∪ ⇓1 ∪ ⇓2 ∪ [person:3, det:+];
    } else {
       ⇑ := ↑ ∪ ⇓2 ∪ [person:3, det:-];
    }
};

NP → num N2
{
    [num:NUM];
    ↓1 := NUM;
    ↓2 := ↑;
    ⇑ := ↑ ∪ ⇓2 ∪ [person:3, number:pl, det:+];
};

NP → pn
{
	↓1 := ↑;
	⇑ := ⇓1;
};

NP → civ name surname
{
	[PRED:literal_person, name:Name, surname:Surname, X];
	↓1 := X;
	↓2 := Name;
	↓3 := Surname;
	⇑ := X;
};

NP → pro
{
	[strong:+] < ↑;
	↓1 := ↑;
	⇑ := ⇓1;
};

N → nc
{
	[mod:NIL];
	↓1 := ↑;
	⇑ := ⇓1;
};

NP → constantNoun
{
	↓1 := ↑;
	⇑ := ⇓1;
};

N2 → N1 RP
{
	[mod:(Head::Tail), Rest];
	[number:Nh, gender:Gh] < ↑;
	// Passage des traits communs entre la relative et le nom
	↓1 := [Rest, mod:Tail];
	[number:Ns, gender:Gs] < ⇓1;
	↓2 := Head ∪ [number:Nh, gender:Gh] ∪ [number:Ns, gender:Gs];
	⇑ := Rest ∪ ⇓1;
};

N2 → N1 NP
{
	[mod:(Head::Tail), X];
	↓2 := Head;
	↓1 := [X, mod:Tail];
	⇑ := X ∪ ⇓1;
};

N2 → N1 PP
{
	[mod:(Head::Tail), X];
	↓2 := Head;
	↓1 := [X, mod:Tail];
	⇑ := X ∪ ⇓1;
};

N2 → N1
{
	↓1 := ↑;
	⇑ := ⇓1;
};

N1 → A N1
{
	[mod:(Elt::Rest), X];
	[number:N, gender:G, anim:A] < ↑;
	↓1 := Elt ∪ [number:N, gender:G, anim:A];
	[number:N1, gender:G1, anim:A1] < ⇓1;
	test [pre:yes, post:no] ∪ ⇓1;
	↓2 := [X, mod:Rest] ∪ [number:N1, gender:G1, anim:A1];
	⇑ := X ∪ ⇓2 ∪ [number:N1, gender:G1, anim:A1];
};

N1 → N1 A
{
	[mod:(First::Rest), X];
	order ↓2 ↓1;
	[number:N, gender:G, anim:A] < ↑;
	↓2 := First ∪ [number:N, gender:G, anim:A];
	[number:N2, gender:G2, anim:A2] < ⇓2;
	test [pre:no, post:yes] ∪ ⇓2;
	↓1 := [X, mod:Rest] ∪ [number:N2, gender:G2, anim:A2];
	⇑ := X ∪ ⇓1 ∪ [number:N2, gender:G2, anim:A2];
};

N1 → N
{
	↓1 := ↑;
	⇑ := ⇓1;
};

A → adj
{
	[mod:NIL];
	↓1 := ↑;
	⇑ := ⇓1;
};

A → advA A
{
	[mod:(First::Rest), X];
	↓1 := First ∪ [pre:yes, post:no];
	↓2 := [X, mod:Rest];
	⇑ := X ∪ ⇓2;
};

A → A advA
{
	[mod:(First::Rest), X];
	[number:N, gender:G] < ↑;
	↓1 := [X, mod:Rest];
	↓2 := First ∪ [pre:no, post:yes];
	[number:N, gender:G] < ⇓1;
	⇑ := X ∪ [number:N, gender:G, post:yes, pre:no];
};

VP → VP Empty
{
	[obj:OBJ, obl:NIL];
	[obj:OBJ, X] < ↑;
	[obj:OBJSynt] < ⇓1;
	↓1 := X ∪ [objExtr:OBJ];
	↓2 := OBJ ∪ OBJSynt;
	⇑ := ⇓1 ∪ ↑;
};

VP → VP NP
{
	[obj:[PRED:P], Rest];
	[obj:Obj];
	test P ≠ pro; 
	↓1 := Rest;
	↓2 := Obj ∪ [det:+];
	⇑ := ⇓1;
};

VP → VP PP
{
	[de_obj:[PRED:P], Rest];
	[de_obj:DeObj];
	test P ≠ pro; 
	↓1 := Rest;
	↓2 := DeObj ∪ [det:+, pcas:de];
	⇑ := ⇓1;
};

VP → VP PP
{
	[à_obj:[PRED:P], Rest];
	[à_obj:DeObj];
	test P ≠ pro; 
	↓1 := Rest;
	↓2 := DeObj ∪ [det:+, pcas:à];
	⇑ := ⇓1;
};

VP → VP PP
{
	[par_obj:[PRED:P], Rest];
	[par_obj:ParObj];
	//test P ≠ pro; 
	↓1 := Rest;
	↓2 := ParObj ∪ [pcas:par];
	⇑ := ⇓1;
};

VP → VP SComp
{
	[scomp:SComp, Rest];
	↓1 := Rest;
	[scomp:SCompSynt] < ⇓1;
	↓2 := SComp ∪ SCompSynt;
	⇑ := ⇓1;
};

VP → VP VComp
{
	[vcomp:VComp, Rest];
	↓1 := Rest;
	[vcomp:VCompSynt] < ⇓1;
	↓2 := VComp ∪ VCompSynt;
	⇑ := ⇓1;
};

VP → V (NP)
{
    trace ↑;
    [obj:NIL, scomp:NIL, de_obj:NIL, par_obj:NIL];
    [objC:Obj, X] < ↑;
    ↓1 := X;
    [objC:ObjSynt] < ⇓1;
    if (↓2) {
        ↓2 := Obj ∪ ObjSynt;
    } else {
	test ¬ObjSynt;
    }
    ⇑ := ⇓1;

};

VP → V
{
	[obj:[PRED:pro], scomp:NIL];
	↓1 := ↑;
	⇑ := ⇓1;
};

// passive
V → (clneg) CLITICS auxEA (ADVV) (advneg) v
{
	[X, subj:S];
	[tense:T, aspect:A, mood:M, diathesis:passive] < ↑;
	[number:N, gender:G] < S;
	order ↓6 ↓3 ↓2 ↓1 ↓4 ↓5;
	↓6 := X ∪ [aux:avoir, pastp:+, gender:G, number:N];
	⇑ := ⇓6;
        ↓3 := [aux:être, diathesis:passive, tense:T, aspect:A, mood:M, subj:S, finite:+];
	if (↓4) {
		[modV:ModV];
		↓4 := [modV:ModV];
	} else {
		[modV:NIL];
	}
	test ⇓5 ⇔ ⇓1;
	if (↓5) {
		[neg:+];
	} else {
		[neg:-] < ↑;
	}
};

// compound passive
V → (clneg) CLITICS auxEA (ADVV) (advneg) été v
{
	[X, subj:S];
	[tense:T, aspect:A, mood:M, diathesis:passive] < ↑;
	[number:N, gender:G] < S;
	order ↓6 ↓7 ↓3 ↓2 ↓1 ↓4 ↓5;
	↓7 := X ∪ [aux:avoir, pastp:+, gender:G, number:N];
	⇑ := ⇓7;
        ↓3 := [aux:avoir, tense:T, aspect:A, mood:M, subj:S, finite:+];
	if (↓4) {
		[modV:ModV];
		↓4 := [modV:ModV];
	} else {
		[modV:NIL];
	}
	test ⇓1 ⇔ ⇓5;
	if (↓5) {
		[neg:+];
	} else {
		[neg:-] < ↑;
	}
};

// active
V → (clneg) CLITICS auxEA (ADVV) (advneg) v
{
	[X, subj:S];
	[tense:T, aspect:A, mood:M, diathesis:active] < ↑;
	if (↓4) {
		[modV:ModV];
		↓4 := [modV:ModV];
	} else {
		[modV:NIL];
	}
	test ⇓1 ⇔ ⇓5;
	if (↓5) {
		[neg:+];
	} else {
		[neg:-] < ↑;
	}
	// Si l&apos;objet est extrait, il s&apos;accorde
	// en genre et en nombre avec le participe
	[objExtr:OBJEXTR] < ↑;
	↓3 := [tense:T, aspect:A, mood:M, subj:S, finite:+];
	[aux:AUX] < ⇓3;
	if (AUX == avoir){
        	if (OBJEXTR) {
			[objExtr:[gender:G, number:N]] < ↑;
			↓6 := X ∪ [aux:AUX, pastp:+, gender:G, number:N];
		} else
	     		↓6 := X ∪ [aux:avoir, pastp:+, gender:ms, number:sg];
	}
	else if (AUX == être){
        	if (OBJEXTR) {
			[objExtr:[gender:G, number:N]] < ↑;
			↓6 := X ∪ [aux:AUX, pastp:+, gender:G, number:N];
		} else {
			[number:N, gender:G] < S;
			↓6 := X ∪ [aux:être, pastp:+, gender:G, number:N];
	     	}
	} else if (AUX == aller){
	     	↓6 := X ∪ [aux:AUX, finite:-];
	}
	⇑ := ⇓6;
};

// active future
V → (clneg) auxV (ADVV) (advneg) CLITICS v
{
	[X, subj:S];
	[tense:T, aspect:A, mood:M, diathesis:active] < ↑;
	if (↓3) {
		[modV:ModV];
		↓3 := [modV:ModV];
	} else {
		[modV:NIL];
	}
	test ⇓1 ⇔ ⇓4;
	if (↓4) {
		[neg:+];
	} else {
		[neg:-] < ↑;
	}
	↓2 := [tense:T, aspect:A, mood:M, subj:S, finite:+];
	↓6 := X ∪ [pastp:-, finite:-];
	⇑ := ⇓6;
};

V → (clneg) (advneg) CLITICS v (ADVV) (advneg)
{
	order ↓1 ↓2 ↓3 ↓5 ↓6 ↓4; 
	[diathesis:active] < ↑;
	test (⇓2 ∨ ⇓6) ⇔ ⇓1;
	test ¬ (⇓2 ∧ ⇓6);
	if (↓5) {
		[modV:ModV];
		↓5 := [modV:ModV];
	} else {
		[modV:NIL];
	}
	if (↓2) {
		[neg:+, finite:-];
		//[finite:-] < ↑;
		↓4 := ↑ ∪ [pastp:-, finite:-];
	} else if (↓6) {
		[neg:+];
		[finite:+] < ↑;
		↓4 := ↑ ∪ [pastp:-, finite:+];
	} else {
		[neg:-] < ↑;
		↓4 := ↑ ∪ [pastp:-, finite:+];
	}
	⇑ := ⇓4;
};

ADVV → adv ADVV
{
	[modV:(Head::Tail)];
        ↓1 := Head;
        ↓2 := [modV:Tail];
};

ADVV →
{
	[modV:NIL];
};

CLITICS → (cld) (cla) (cld)
{
	test ¬(⇓1 ∧ ⇓3);
	if (↓1) {
		[à_obj:[PRED:pro, person:1|2]];
		[à_obj:AObj];
        	↓1 := AObj;
	} 
	else if (↓3) {
		[à_obj:[PRED:pro, person:3]];
		[à_obj:AObj];
        	↓3 := AObj;
	} else {
		[à_obj:NIL];
	}
	if (↓2) {
		[obj:[PRED:pro]];
		[obj:Obj];
        	↓2 := Obj;
	} else {
		[obj:NIL];
	}
};

SComp → csu T
{
	↓1 := ↑;
       	↓2 := ↑;
	⇑ := ⇓1 ∪ ⇓2;
};

VComp → VP
{
	↓1 := ↑ ∪ [finite:+];
       	⇑ := ⇓1;
};

PP → prep NP
{
	↓1 := ↑;
       	↓2 := ↑;
	⇑ := ⇓1 ∪ ⇓2;
};

RP → prel S
{
	[number:N, gender:G, REST] < ↑;
	↓1 := [];
	[fct:FCT] < ⇓1;
	↓2 := REST ∪ [FCT:[PRED:none, number:N, gender:G]] ∪ [mood:indicative];
};

Empty →
{
	[PRED:none, person:nc];
};

';

?>
