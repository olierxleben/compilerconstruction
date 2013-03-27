#include "util.h"

typedef struct table *Table_;

struct table{string id; int value; Table_ tail;};

Table_ Table(string id, int value, struct table *tail);

