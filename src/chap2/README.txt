Perform the PROGRAM exercise (Appel, Chapter 2, p. 33):

- Use Flex instead of Lex.
- Use adjust() (or a macro ADJ) for each token to adjust the
  program position.
- Use exclusive states (start conditions), defined with %x,
  to distinguish normal operation from processing comments
  and strings.
- Assign the semantic value of a token to yylval. Make sure
  to assign a copy of yytext (using the function "string")
  for ID and STRING.
- Allow for UNIX and DOS text files (newline with or without \r).