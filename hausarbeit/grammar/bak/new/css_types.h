#ifndef CSS_TYPES_H_
#define CSS_TYPES_H_

typedef struct css_Selector_* css_Selector;
typedef struct css_Declaration_* css_Declaration;
typedef struct css_SelectorList_* css_SelectorList;
typedef struct css_DeclarationList_* css_DeclarationList;
typedef struct css_Rule_* css_Rule;
typedef struct css_RuleList_* css_RuleList;

struct css_Selector_ {
	char* name;
};

struct css_Declaration_ {
	char* dec_key;
	char* dec_val;
};

struct css_SelectorList_ {
	css_Selector selector;
	css_SelectorList next;
};

struct css_DeclarationList_ {
	css_Declaration declaration;
	css_DeclarationList next;
};

struct css_Rule_ {
	css_SelectorList selectorList;
	css_DeclarationList declarationList;	
};

struct css_RuleList_ {
	css_Rule rule;
	css_RuleList next;
};

css_Selector create_CSSSelector(char* _name);
css_Declaration create_CSSDeclaration(char* _dec_key, char* _dec_val);
css_SelectorList create_CSSSelectorList(css_Selector _selector, css_SelectorList _next);
css_DeclarationList create_CSSDeclarationList(css_Declaration _declaration, css_DeclarationList _next);
css_Rule create_CSSRule(css_SelectorList _selectorList, css_DeclarationList _declarationList);
css_RuleList create_CSSRuleList(css_Rule _rule, css_RuleList _next);

#endif
