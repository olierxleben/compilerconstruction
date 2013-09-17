#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "css_merge.h"
#include "cli_parse.h"

#define BUFFER_SIZE 256

void merge_files(char* dest, char* src) {
	char buffer[BUFFER_SIZE];
	FILE *dest_css, *src_css;
	dest_css = fopen(dest, "a+");
	if(dest_css == NULL) {
		printf("error while merging files\n");
		exit(1);
	}
	src_css = fopen(src, "r");
	if(src_css == NULL) {
		printf("error while opening %s\n", src);
		exit(1);
	}

	while(!feof(src_css)) {
		buffer[0] = '\0';
		fgets(buffer, BUFFER_SIZE, src_css);
		fputs(buffer, dest_css);
	}
	fputs("\n",dest_css);

	fclose(src_css);
	fclose(dest_css);
}

char* scan_html(char* src) {
	char css_file[BUFFER_SIZE];
	char* merged_css = "merged.css";
	int css_cnt = 0;
	char buffer[BUFFER_SIZE];
	FILE* src_file;

	// init merge css file
	src_file = fopen(merged_css, "w");
	if(src_file == NULL) {
		printf("error initializing merge files\n");
		exit(1);
	}
	fclose(src_file);

	src_file = fopen(src, "r");
	if(src_file == NULL) {
		printf("Could not open html file: %s\n", src);
		exit(1);
	}

	while(!feof(src_file)) {
		fgets(buffer, BUFFER_SIZE, src_file);

		if(strstr(buffer, "text/css") != NULL) {
			char* tmp = strtok(buffer, " ");

			while(tmp != NULL) {
				if (strstr(tmp, "href=")) {
					char* pos = strchr(tmp, '\"');
					strcpy(css_file, pos+1);
					css_file[strlen(css_file) - 1] = '\0';

					merge_files(merged_css, css_file);
				}
				tmp = strtok(NULL, " ");
			}
		}
	}
	fclose(src_file);

	return merged_css;
}

struct css_data merge_css_file(char* src) {
	struct css_data data;
	data.src_html = src;

	data.merged_css = scan_html(src);

	return data;
}

struct css_data merge_css_path(char* src) {
	printf("path input isn't supported yet\n");
	exit(2);
}

struct css_data merge_css(int input_type, char* src) {
	switch(input_type) {
		case FILE_INPUT : {
			return merge_css_file(src);
		}
		case PATH_INPUT : {
			return merge_css_path(src);
		}
		default : {
			printf("wrong usage of merge_css\n");
			exit(1);
		}
	}
}

