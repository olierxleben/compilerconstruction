#include "css_types.h"
#include <stdlib.h>

css_Selector create_CSSSelector(char* _name){
    css_Selector tmp = (css_Selector)malloc(sizeof(struct css_Selector_));
    tmp->name = _name;
    return tmp;
}

css_Declaration create_CSSDeclaration(char* _dec_key){
    css_Declaration tmp = (css_Declaration)malloc(sizeof(struct css_Declaration_));
    tmp->dec_key = _dec_key;
    return tmp;
}

css_SelectorList create_CSSSelectorList(css_Selector _selector, css_SelectorList _next){
    css_SelectorList tmp = (css_SelectorList)malloc(sizeof(struct css_SelectorList_));
    tmp->selector = _selector;
    tmp->next = _next;
    return tmp;
}

css_DeclarationList create_CSSDeclarationList(css_Declaration _declaration, css_DeclarationList _next){
    css_DeclarationList tmp = (css_DeclarationList)malloc(sizeof(struct css_DeclarationList_));
    tmp->declaration = _declaration;
    tmp->next = _next;
    return tmp;
}

css_Rule create_Rule(css_SelectorList _selectorList, css_DeclarationList _declarationList){
    css_Rule tmp = (css_Rule)malloc(sizeof(struct css_Rule_));
    tmp->selectorList = _selectorList;
    tmp->declarationList = _declarationList;
    return tmp;
}

css_RuleList create_RuleList(css_Rule _rule, css_RuleList _next){
    css_RuleList tmp = (css_RuleList)malloc(sizeof(struct css_RuleList_));
    tmp->rule = _rule;
    tmp->next = _next;
    return tmp;
}