#ifndef PRINT_CSS_H
#define PRINT_CSS_H

#include "css_types.h"

void printRuleList(css_RuleList root);
void printRule(css_Rule rule);
void printSelectorList(css_SelectorList list);
void printDeclarationList(css_DeclarationList list);
void printSelector(css_Selector selector);
void printDeclaration(css_Declaration declaration);

#endif
