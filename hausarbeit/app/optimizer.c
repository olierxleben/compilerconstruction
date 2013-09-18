#include "optimizer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "gumbo.h" // HTML 5 parser

#define BUFFER_SIZE 4096

/*
* Set hex pair values to one value #336699 -> #369 or #34228 -> #3428
* char ** because I need the adress of the pointer to set the new value
*/ 
static void shortHandColor(char** val){
    int i = 1;  // position in value 
    int j = 1;  // position in newValue
    char *value = *val;
    char newValue[BUFFER_SIZE] = {0};    // Init
    int shorting = 1;
        
    // Isn't a hex value don't do anything
    if(value && value[0] == '#'){
        newValue[0] = '#';
        for(; i < strlen(*val); i=i+2, j++){
            if(value[i] == value[i+1]) {
            	newValue[j] = value[i];
            }           
            else {
            	shorting = 0;
            	break;
            }
        }
        
        if(shorting == 1)        
        	*val = strdup(newValue);   
    }
}

void parseHTML(char* file) {
	// create output
	//GumboOutput* output = gumbo_parse(file);
	// ...
	
	// destroy   
	//gumbo_destroy_output(&kGumboDefaultOptions, output);
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
	css_DeclarationList last = NULL;
	
	while(list) {
		if(list->declaration != NULL ) {
		
		    if(strcmp(list->declaration->dec_key, dec->dec_key) == 0) {			
			    if(list->next) {	
				    list->declaration = list->next->declaration;
				    list->next = list->next->next;			
			    }
			    else {
				    if(last) {
					    last->next = NULL;
				    }
				    else {
					    list = NULL;
					    continue;
				    }
			    }								
		    }
	    }
		
		last = list;
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

int compareDeclarationLists(css_DeclarationList currDecs, css_DeclarationList nextDecs) {
	css_DeclarationList nextStart = nextDecs;
	while(currDecs) {
		int found = 0;
		nextDecs = nextStart;
		while(nextDecs) {
			if(strcmp(currDecs->declaration->dec_key, nextDecs->declaration->dec_key) == 0 &&
			   strcmp(currDecs->declaration->dec_val, nextDecs->declaration->dec_val) == 0) {
				found = 1;	
			}
			nextDecs = nextDecs->next;
		}
		
		if(found == 0) {
			return 1;
		}
		
		currDecs = currDecs->next;
	}
	
	return 0;
}

css_SelectorList mergeSelectors(css_SelectorList first, css_SelectorList second) {
	while(first) {
		
		second = create_CSSSelectorList(first->selector, second);
		
		first = first->next;
	}
	
	return second;
}

css_RuleList mergeDoubleDeclarations(css_RuleList list) {
	css_RuleList ret = list;
	while(list) {
		css_RuleList tmpList = list->next;
		css_RuleList lastList = NULL;
		while(tmpList) {
				css_DeclarationList currDecs = list->rule->declarationList;
				css_DeclarationList nextDecs = tmpList->rule->declarationList;
			    int isMerged = 0;
				if(compareDeclarationLists(currDecs, nextDecs) == 0 && compareDeclarationLists(nextDecs, currDecs) == 0) {
					// Selectors mergen
					css_SelectorList tmp = mergeSelectors(list->rule->selectorList, tmpList->rule->selectorList);
					list->rule->selectorList = tmp;
					if(lastList)
					    lastList->next = tmpList->next;
					else
					    list->next = tmpList->next;
				    isMerged = 1;
				}
			if(isMerged == 0)
			    lastList = tmpList;
			tmpList = tmpList->next;
		}
		list = list->next;
	}
	
	return ret;
}

css_RuleList optimize(css_RuleList list, char* filename) {
	// merge nodes with same selector
	list = mergeNodes(list);
	list = removeDoubleDeclarations(list);
	list = mergeDoubleDeclarations(list);
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
    
    if(selector == NULL)
    	return 0;
    
	while(tmp) {
		if(tmp->selector) {
			if(strcmp(tmp->selector->name ,selector->name) == 0)
				return 1;
		}	
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
	        shortHandColor(&(tmpList->declaration->dec_val));
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
	        shortHandColor(&(tmpList->declaration->dec_val));
			shortHandMargin0PX(&(tmpList->declaration->dec_val));
			
		    css_Declaration tmpDec = create_CSSDeclaration(tmpList->declaration->dec_key, tmpList->declaration->dec_val);
		    decList = create_CSSDeclarationList(tmpDec, decList);
		    tmpList = tmpList->next;
	    }
	}
	
	return create_CSSRule(create_CSSSelectorList(selector, NULL), decList);
}

