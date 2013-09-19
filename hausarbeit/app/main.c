#include <stdlib.h>
#include <stdio.h>

#include "cli_parse.h"
#include "css_merge.h"
#include "grammar/css_types.h"
#include "grammar/css.tab.h"
#include "optimizer.h"
#include "grammar/parsecss.h"

#include "output.h"

int countRules(css_RuleList list) {
	int cnt = 0;
	while(list){
		if(list->rule)
			++cnt;
	
		list = list->next;
	}
	
	return cnt;
}

int main(int argc, char* argv[]) {
	struct input_data id;
	struct css_data cd;
	css_RuleList rules;
	int parsed_rules, optimized_rules;

	// parse command line arguments
	printf("parsing parameters...\n");
	id = parse_cli(argc, argv);

	// merge css files from given html documents
	printf("merging css files...\n");
	cd = merge_css(id.input_type, id.src);

	// parse CSS
	rules = parseCSS(cd.merged_css);
	trimTree(rules);	

	parsed_rules = countRules(rules);

	// optimize CSS
	printf("optimizing css...\n");
	rules = optimize(rules, argv[1]);

	optimized_rules = countRules(rules);

	printf("parsed_count: %i, optimized_count; %i\n", parsed_rules, optimized_rules);

	// output
	if(id.output_type == STRUCTURED)
		structuredOutput(rules, "output.css");
	else
		minifiedOutput(rules, "output.css");

	return 0;
}
