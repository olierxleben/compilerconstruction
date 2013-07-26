#ifndef CLI_PARSE_H
#define CLI_PARSE_H

/*
	parameter for css optimization
	-s 				structured output
	-m 				minified output
	-f "filename" 	html file to be optimized
	-p "path"		path with html files to be optimized
*/

enum output_type {STRUCTURED, MINIFIED};  // -s, -m
enum input_type {FILE_INPUT, PATH_INPUT}; // -f, -p

struct input_data {
	int output_type;
	int input_type;
	char* src;
};

struct input_data parse_cli(int argc, char** argv);

#endif