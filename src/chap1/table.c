#include "table.h"

Table_ Table(string id, int value, struct table *tail){
    Table_ t = (Table_) checked_malloc(sizeof(*t));
    t->id = id;
    t->value = value;
    t->tail = tail;
    return t;
}
