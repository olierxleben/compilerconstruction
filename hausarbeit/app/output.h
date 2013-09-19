#ifndef OUTPUT_H
#define OUTPUT_H

#include "grammar/css_types.h"
#include "cli_parse.h"

/**
 * Function to remove whitespaces at the front and at the end of the give String 
 *
 * string:  pointer to the string where the whitespaces will be removed
 * 
 * returns new pointer to the manipulated string
 *
 */
char* trimSpaces(char* string);

/**
 * Function to remove whitespaces in the given css rule list  
 *
 * rules: created rules (parsed tree)
 *
 */
void trimTree(css_RuleList rules);

/**
 * Function to write the css rule list in a structured format like
 *  a {
 *      margin : 0;
 *  }
 *
 * rules:       created rules (parsed tree)
 * filename:    file name where the rules will be written
 *    
 */
void structuredOutput(css_RuleList rules, char* fileName);

/**
* Function to write the css rule list in a minimised format like
 *  a{margin:0}
 *
 * rules:       created rules (parsed tree)
 * filename:    file name where the rules will be writteing 
 *
 */
void minifiedOutput(css_RuleList rules, char* fileName);

#endif 
