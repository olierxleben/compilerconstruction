#include <stdio.h>
#include "printCSS.h"

// TODO fprintf um datei ausgabe, Baumstrukturen mit ausgeben

void printRuleList(css_RuleList root) {
	while(root != NULL) {
		// print rule
		if(root->rule != NULL) {
			printRule(root->rule);
		}		
		printf("\n");
		
		// next rule
		root = root->next;
	} 
}

void printRule(css_Rule rule) {
	if(rule->selectorList != NULL)
		printSelectorList(rule->selectorList);
	printf(" { \n");
	if(rule->declarationList != NULL)
		printDeclarationList(rule->declarationList);
	printf(" } \n");
}

void printSelectorList(css_SelectorList list) {
	while(list != NULL) {
		if(list->selector != NULL)
			printSelector(list->selector);		
		
		if(list->next != NULL)
			printf(", ");
		
		// next item
		list = list->next;
	}
}

void printDeclarationList(css_DeclarationList list) {
	while(list != NULL) {
		if(list->declaration != NULL)
			printDeclaration(list->declaration);		
		
		// next item
		list = list->next;
	}
}

void printSelector(css_Selector selector) {
	printf("%s ", selector->name);
}		

void printDeclaration(css_Declaration declaration) {
	printf("%s: %s;\n", declaration->dec_key, declaration->dec_val);
}

