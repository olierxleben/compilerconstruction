#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "grammar/css_types.h"

/**
 * Function to optimize the created css rule list
 * Optimization:    - merge Nodes
 *                  - remove double declaration in selector
 *                  - merge selector with same declaration list
 *                  - some shorthands in css
 *                  - remove unused css rules of the given html file
 *
 * list:        pointer to the created css rule list
 * filename:    filename of the html file which will be used to analyse the used css rules
 * 
 * returns the optimized css rule list
 *
 */
css_RuleList optimize(css_RuleList list, char* filename);

/**
 * Function to merge Nodes of the given css rule list
 *
 * list:    pointer to the css rule list
 *
 * returns the merged css rule list
 *
 */
css_RuleList mergeNodes(css_RuleList list);

/**
 * Function to merge to given rules into a new rule
 *
 * rule1:       pointer to the rule
 * rule2:       pointer to the rule
 * selector:    pointer to the selector where the new rule will be saved
 * 
 * returns the merged css rule
 *
 */
css_Rule mergeToNewRule(css_Rule rule1, css_Rule rule2, css_Selector selector);

#endif 
