#include "optimizer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
* Set hex pair values to one value #336699 -> #369 or #34228 -> #3428
* char ** because I need the adress of the pointer to set the new value
*/ 
static void shortHandColour(char** val){
    int i = 2;  // position in value 
    int j = 2;  // position in newValue
    char *value = *val;
    char newValue[sizeof(value)/sizeof(char)] = {0};    // Init    
    // Isn't a hex value don't do anything
    // IMPORTANT first character is a space :(
    if(value && value[1] == '#'){
        newValue[0] = ' ';
        newValue[1] = '#';
        for(; i < (sizeof(value)/sizeof(char)-1); i++, j++){
            newValue[j] = value[i];   
            if(value[i] == value[i+1]){
                i++;
            }           
        }
        *val = strdup(newValue);   
    }
}


/*
* Add this moment only removes px from 0px for marging
*/
static void shortHandMargin0PX(char** val){
    // IMPORTANT first character is a space :(
    if(strcmp(*val, " 0px") == 0){
        (*val)[2] = '\0';
    }
}

css_RuleList optimize(css_RuleList list) {
	// merge nodes with same selector
	return mergeNodes(list);
}

css_RuleList mergeNodes(css_RuleList list) {	
	css_RuleList newRules = NULL;	
	css_Rule tmpRule = list->rule;
		
	css_SelectorList sels = tmpRule->selectorList;	
	while(sels) {
		css_Selector currSel = sels->selector;		
		css_RuleList tmpList = list->next;
	
		css_Rule newRule = NULL;
		newRule = mergeToNewRule(tmpRule, NULL, currSel);
		if(newRule->declarationList->declaration){
		    shortHandMargin0PX(&(newRule->declarationList->declaration->dec_val));
	    }
		while(tmpList) {
			if(containsSelector(tmpList->rule->selectorList, currSel)) {
				newRule = mergeToNewRule(newRule, tmpList->rule, currSel);
				if(newRule->declarationList->declaration){
				    shortHandMargin0PX(&(newRule->declarationList->declaration->dec_val));
			    }
			}		
		
			tmpList = tmpList->next;
		}
		
		newRules = create_CSSRuleList(newRule, newRules);
		
		sels = sels->next;
	}
	
	
	return newRules;
}

int containsSelector(css_SelectorList list, css_Selector selector) {
    css_SelectorList tmp = list;
	while(tmp) {
		if(strcmp(tmp->selector->name ,selector->name) == 0)
			return 1;
			
		tmp = tmp->next;
	}
	return 0;
}

css_Rule mergeToNewRule(css_Rule rule1, css_Rule rule2, css_Selector selector) {
	css_DeclarationList decList = NULL;
	css_DeclarationList tmpList;
	if(rule1){
	    tmpList = rule1->declarationList;
	    while(tmpList) {
	        shortHandColour(&(tmpList->declaration->dec_val));
		    css_Declaration tmpDec = create_CSSDeclaration(tmpList->declaration->dec_key, tmpList->declaration->dec_val);
		    decList = create_CSSDeclarationList(tmpDec, decList);
		    tmpList = tmpList->next;
	    }
    }
	
	if(rule2){
	    tmpList = rule2->declarationList;
	    while(tmpList) {
	        shortHandColour(&(tmpList->declaration->dec_val));
		    css_Declaration tmpDec = create_CSSDeclaration(tmpList->declaration->dec_key, tmpList->declaration->dec_val);
		    decList = create_CSSDeclarationList(tmpDec, decList);
		    tmpList = tmpList->next;
	    }
	}
	
	return create_CSSRule(create_CSSSelectorList(selector, NULL), decList);
}


