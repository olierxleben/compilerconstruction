#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "grammar/css_types.h"

css_RuleList optimize(css_RuleList list, char* filename);
css_RuleList mergeNodes(css_RuleList list);
css_Rule mergeToNewRule(css_Rule rule1, css_Rule rule2, css_Selector selector);

#endif 
