#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "output.h"


void structuredOutput(css_RuleList rules, char* fileName) {
	FILE *outFile;
	
	outFile = fopen(fileName, "w");
	
	if(outFile == NULL) {
		printf("could not open output file\n");
		return;
	}
	
	
	// output
	while(rules != NULL) {
		// output rule
		if(rules->rule != NULL) {
			css_Rule rule = rules->rule;
			css_SelectorList sels = rule->selectorList;
			css_DeclarationList decs = rule->declarationList;
			
			// output selectors
			while(sels != NULL) {
				fprintf(outFile, "%s ", trimSpaces(sels->selector->name));		
				if(sels->next != NULL)
					fprintf(outFile,", ");
				// next item
				sels = sels->next;
			}
			
			fprintf(outFile, " {\n");
			
			//output declations
			while(decs != NULL) {
				fprintf(outFile, "\t%s: %s;\n", trimSpaces(decs->declaration->dec_key), trimSpaces(decs->declaration->dec_val));
				
				// next item
				decs = decs->next;
			}
			
			fprintf(outFile, "}\n");
			
		}		
		fprintf(outFile, "\n");
		
		// next rule
		rules = rules->next;
	}	
	
	fclose(outFile);
}

void minifiedOutput(css_RuleList rules, char* fileName) {
	FILE *outFile;
	
	outFile = fopen(fileName, "w");
	
	if(outFile == NULL) {
		printf("could not open output file\n");
		return;
	}	
	
	// output
	while(rules != NULL) {
		// output rule
		if(rules->rule != NULL) {
			css_Rule rule = rules->rule;
			css_SelectorList sels = rule->selectorList;
			css_DeclarationList decs = rule->declarationList;
			
			// output selectors
			while(sels != NULL) {
				fprintf(outFile, "%s", trimSpaces(sels->selector->name));		
				if(sels->next != NULL)
					fprintf(outFile, ",");
				// next item
				sels = sels->next;
			}
			
			fprintf(outFile, "{");
			
			//output declations
			while(decs != NULL) {
				if(decs->next != NULL)
					fprintf(outFile, "%s:%s;", trimSpaces(decs->declaration->dec_key), trimSpaces(decs->declaration->dec_val));
				else
					fprintf(outFile, "%s:%s", trimSpaces(decs->declaration->dec_key), trimSpaces(decs->declaration->dec_val));
				
				// next item
				decs = decs->next;
			}
			
			fprintf(outFile, "}");
			
		}		
		
		// next rule
		rules = rules->next;
	}	
	
	fclose(outFile);
}

char* trimSpaces(char* string) {
	int len = strlen(string);
	int i = 0;
	
	// remove whitespaces at the front
	while(i < len) {
		if(string[0] == ' ')
			++string;
		else
		  break;
		++i;
	}
	
	i = strlen(string) - 1;
	
	// remove whitespaces at the end
	while(i > 0) {
		if(isspace(string[i]))
			string[i] = '\0';
		else
		  break;
		--i;
	}
	
	return strdup(string);
}

void trimTree(css_RuleList rules) {
    // All rules
	while(rules) {
	    // Get selectorlist and declarationlist
		css_SelectorList sels = rules->rule->selectorList;
		css_DeclarationList decs = rules->rule->declarationList;
	    
	    // remove whitespaces from all selector names
		while(sels) {
			sels->selector->name = trimSpaces(sels->selector->name);
								
			sels = sels->next;
		}
		
		// remove whitespaces from all declaration values and keys
		while(decs) {
			decs->declaration->dec_key = trimSpaces(decs->declaration->dec_key);
			decs->declaration->dec_val = trimSpaces(decs->declaration->dec_val);
			
			decs = decs->next;
		}
	
		rules = rules->next;
	}	
}

