#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "cli_parse.h"
#include "css_merge.h"
#include "guiCSS.h"
#include "grammar/css_types.h"
#include "grammar/test.tab.h"
#include "optimizer.h"

int main(int argc, char* argv[]) {
	struct input_data id;
	struct css_data cd;
	css_RuleList rules;

/*	// parse command line arguments
	printf("parsing parameters...\n");
	id = parse_cli(argc, argv);

	// merge css files from given html documents
	printf("merging css files...\n");
	cd = merge_css(id.input_type, id.src);
*/
	
	// parse CSS
	rules = parseCSS(argv[1]);

	//print CSS tree
	printGUI(rules);


	// optimize CSS
	//rules = optimize(rules);

	//printGUI(rules);

	// start css optimization
	printf("optimizing css...\n");

	return 0;
}
