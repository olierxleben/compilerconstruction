#ifndef OUTPUT_H
#define OUTPUT_H

#include "grammar/css_types.h"
#include "cli_parse.h"

char* trimSpaces(char* string);
void trimTree(css_RuleList rules);
void structuredOutput(css_RuleList rules, char* fileName);
void minifiedOutput(css_RuleList rules, char* fileName);

#endif 
