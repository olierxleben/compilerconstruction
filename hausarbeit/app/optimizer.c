#include "optimizer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gumbo.h" // HTML 5 parser

/*
* Set hex pair values to one value #336699 -> #369 or #34228 -> #3428
* char ** because I need the adress of the pointer to set the new value
*/ 
static void shortHandColour(char** val){
    int i = 1;  // position in value 
    int j = 1;  // position in newValue
    char *value = *val;
    char newValue[sizeof(value)/sizeof(char)] = {0};    // Init    
    // Isn't a hex value don't do anything
    if(value && value[0] == '#'){
        newValue[0] = '#';
        for(; i < (sizeof(value)/sizeof(char)-1); i++, j++){
            newValue[j] = value[i];   
            if(value[i] == value[i+1]){
                i++;
            }           
        }
        *val = strdup(newValue);   
    }
}

css_RuleList shortHandMargin(css_RuleList list){
	while(list) {	
		if(list->next) {	
	//		if(strcmp(list->selector->name, sel->name) == 0) {
				
		//	}
		}
		
		list = list->next;
	}
}

void parseHTML(char* file) {
	// create output
	GumboOutput* output = gumbo_parse(file);
	// ...
	
	// destroy   
	gumbo_destroy_output(&kGumboDefaultOptions, output);
}

/*
* Add this moment only removes px from 0px for marging
*/
static void shortHandMargin0PX(char** val){
    if(strcmp(*val, "0px") == 0){
        (*val)[1] = '\0';
    }
}

void removeDeclaration(css_Declaration dec, css_DeclarationList list) {
	while(list) {
		if(list->next) {	
			printf("%s,", dec->dec_key);
			printf("%s\n", list->declaration->dec_key);
			if(strcmp(list->declaration->dec_key, dec->dec_key) == 0) {
				list->declaration = list->next->declaration;
				list->next = list->next->next;
			}
		}
		else {
			list->declaration = NULL;
			list->next = NULL;
		}
		list = list->next;
	}
}

css_RuleList removeDoubleDeclarations(css_RuleList list) {
	css_RuleList ret = list;
	while(list) {
		css_DeclarationList decs = list->rule->declarationList;
		
		while(decs) {
			removeDeclaration(decs->declaration, decs->next);
						
			decs = decs->next;	
		}				
		
		list = list->next;
	}
	
	return ret;
}

css_RuleList optimize(css_RuleList list, char* filename) {
	// merge nodes with same selector
	list = mergeNodes(list);
	list = removeDoubleDeclarations(list);
//	list = shortHandMargin(list);
	
	parseHTML(filename);
	
	return list;
}

void removeSelector(css_Selector sel, css_SelectorList list) {
	while(list) {	
		if(list->next) {	
			if(strcmp(list->selector->name, sel->name) == 0) {
				list->selector = list->next->selector;
				list->next = list->next->next;
			}
		}
		else {
			list->selector = NULL;
			list->next = NULL;
		}
		list = list->next;
	}
}

css_RuleList mergeNodes(css_RuleList list) {	
	css_RuleList newRules = NULL;	
	
	while(list) {
		css_Rule tmpRule = list->rule;		
		css_SelectorList sels = tmpRule->selectorList;	
		
		while(sels) {
			css_Selector currSel = sels->selector;		
			css_RuleList tmpList = list->next;
	
			if(currSel == NULL) 
				break;
	
			css_Rule newRule = NULL;
			newRule = mergeToNewRule(tmpRule, NULL, currSel);
			while(tmpList) {
				if(containsSelector(tmpList->rule->selectorList, currSel)) {
					newRule = mergeToNewRule(newRule, tmpList->rule, currSel);					
					removeSelector(currSel, tmpList->rule->selectorList);
				}		
		
				tmpList = tmpList->next;
			}
			
			
			
			newRules = create_CSSRuleList(newRule, newRules);
		
			sels = sels->next;
		}
	
		list = list->next;
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
	    	// shorthand optimization
	        shortHandColour(&(tmpList->declaration->dec_val));
			shortHandMargin0PX(&(tmpList->declaration->dec_val));
			
		    css_Declaration tmpDec = create_CSSDeclaration(tmpList->declaration->dec_key, tmpList->declaration->dec_val);
		    decList = create_CSSDeclarationList(tmpDec, decList);
		    tmpList = tmpList->next;
	    }
    }
	
	if(rule2){
	    tmpList = rule2->declarationList;
	    while(tmpList) {
	    	// shorthand optimization
	        shortHandColour(&(tmpList->declaration->dec_val));
			shortHandMargin0PX(&(tmpList->declaration->dec_val));
			
		    css_Declaration tmpDec = create_CSSDeclaration(tmpList->declaration->dec_key, tmpList->declaration->dec_val);
		    decList = create_CSSDeclarationList(tmpDec, decList);
		    tmpList = tmpList->next;
	    }
	}
	
	return create_CSSRule(create_CSSSelectorList(selector, NULL), decList);
}

