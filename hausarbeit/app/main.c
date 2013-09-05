#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "cli_parse.h"
#include "css_merge.h"

int main(int argc, char* argv[]) {
	struct input_data id;
	struct css_data cd;

	// parse command line arguments
	printf("parsing parameters...\n");
	id = parse_cli(argc, argv);

	// merge css files from given html documents
	printf("merging css files...\n");
	cd = merge_css(id.input_type, id.src);

	// start css optimization
	printf("optimizing css...\n");

	return 0;
}