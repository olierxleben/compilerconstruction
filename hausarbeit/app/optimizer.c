#include "optimizer.h"
#include <stdlib.h>

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
		while(tmpList) {
			if(containsSelector(tmpList->rule->selectorList, currSel)) {
				css_Rule old = newRule;
				newRule = mergeToNewRule(tmpRule, tmpList->rule, currSel);
				
				//free(old); // TODO MAL gucken wegen speicherlecks
			}
			
		
			tmpList = tmpList->next;
		}
		
		newRules = create_CSSRuleList(newRule, newRules);
		
		sels = sels->next;
	}
	
	
	return newRules;
}

int containsSelector(css_SelectorList list, css_Selector selector) {
	while(list) {
		if(list->selector->name == selector->name)
			return 1;
			
		list = list->next;
	}
	return 0;
}

css_Rule mergeToNewRule(css_Rule rule1, css_Rule rule2, css_Selector selector) {
	css_DeclarationList decList = NULL;
	css_DeclarationList tmpList;
	
	tmpList = rule1->declarationList;
	while(tmpList) {
		css_Declaration tmpDec = create_CSSDeclaration(tmpList->declaration->dec_key, tmpList->declaration->dec_val);
		decList = create_CSSDeclarationList(tmpDec, decList);
		
		tmpList = tmpList->next;
	}
	
	tmpList = rule2->declarationList;
	while(tmpList) {
		css_Declaration tmpDec = create_CSSDeclaration(tmpList->declaration->dec_key, tmpList->declaration->dec_val);
		decList = create_CSSDeclarationList(tmpDec, decList);
		
		tmpList = tmpList->next;
	}
	
	return create_CSSRule(create_CSSSelectorList(selector, NULL), decList);
}

