Chapter 4: Abstract Syntax Trees

- Make sure, you add all required include files to the corresponding sections of your
  tiger.lex file. Otherwise the new YYSTYPE of the extended yylval will cause compiler errors.
  (YYSTYPE is now defined in the file y.tab.h included by lex.yy.c.)

- Check the lecture slides on abstract syntax for comments on the use of the functions
  in absyn.h.