#include <stdlib.h>
#include <stdio.h>

#include "cli_parse.h"
#include "css_merge.h"
#include "grammar/css_types.h"
#include "grammar/test.tab.h"
#include "optimizer.h"
#include "grammar/parsecss.h"

#include "output.h"

int main(int argc, char* argv[]) {
	struct input_data id;
	struct css_data cd;
	css_RuleList rules;

	// parse command line arguments
	printf("parsing parameters...\n");
	id = parse_cli(argc, argv);

	// merge css files from given html documents
	printf("merging css files...\n");
	cd = merge_css(id.input_type, id.src);

	// parse CSS
	rules = parseCSS(cd.merged_css);
	trimTree(rules);


	// optimize CSS

	printf("optimizing css...\n");
	rules = optimize(rules, argv[1]);

	// output
	if(id.output_type == STRUCTURED)
		structuredOutput(rules, "output.css");
	else
		minifiedOutput(rules, "output.css");

	return 0;
}
