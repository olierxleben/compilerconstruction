Perform the PROGRAM exercise (Appel, Chapter 1, p. 12).

prog2.c defines an additional test program.

# Straight-Line Programs

## Intro
Tree representations can be described with grammars, just like program- ming languages. To introduce the concepts, I will show a simple program- ming language with statements and expressions, but no loops or if-statements (this is called a language of straight-line programs).

## Grammar

Stm			-> Stm : Stm				(compountStm)
Stm			-> id := Exp				(AssignStm)
Stm			-> print (ExpList)	(printStm) 
Exp			-> id								(IdExp)
Exp			-> num							(NumExp)
Exp			-> Exp Binop exp		(OpExp)
Exp			-> (Stm, Exp)				(EseqExp)
ExpList	-> Exp, ExpList			(PairExpList)
ExpList	-> Exp							(LastExpList)
Binop		-> +								(Plus)
Binop		-> -								(Minus)
Binop		-> x								(Times)
Binop		-> /								(Div)