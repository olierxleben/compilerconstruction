#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "cli_parse.h"

struct input_data parse_cli(int argc, char** argv) {
	struct input_data data;
	int c;

	// default output
	data.output_type = STRUCTURED;

	while((c = getopt(argc, argv, "smf:p:")) != -1) {
		switch(c) {
			case 's' : {
				data.output_type = STRUCTURED;
				break;
			}
			case 'm' : {
				data.output_type = MINIFIED;
				break;
			}
			case 'f' : {
				data.input_type = FILE_INPUT;
				data.src = optarg;
				break;
			}
			case 'p' : {
				data.input_type = PATH_INPUT;
				data.src = optarg;
				break;
			}
			case '?' : {
				if (optopt == 'p' || optopt == 'f') {
					printf("Option %c needs an argument!\n", optopt);
				}
				else {
					printf("Option %c is not supported!\n", optopt);
				}
			}
			default : {
				abort();
			}
		}
	}

	return data;
}
