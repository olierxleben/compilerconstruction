#ifndef CSS_MERGE_H
#define CSS_MERGE_H

#define MAX_CSS_CNT 10

struct css_data {
	char* src_html;
	char* merged_css;
};

struct css_data merge_css(int input_type, char* src);

#endif