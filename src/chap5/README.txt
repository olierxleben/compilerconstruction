Chapter 5: Semantic Analyzer

- Add env.c/.h, types.c/.h, translate.c/.h and semant.c/.h to your project.
  (translate.c will be extended later.)

- Replace parse.c and makefile with the new versions provided.
  
- Complete the function transExp in semant.c to perform the type checking of
  expressions. transVar, transDec and transTy (for variables, declarations
  and types) as well as some auxiliary functions are already given.

- You don't have to check the correct placement of break statements.

- Use sem_test1.tig - sem_test3.tig to check your program.
  Note that these tests don't check all semantic rules.

