#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(void) {
    list_t *l = list_alloc();
    assert(list_length(l) == 0);

    list_add_to_back(l, 2);
    list_add_to_back(l, 3);
    list_add_to_front(l, 1);
    list_add_at_index(l, 99, 2);          // 1,99,2,3
    list_print(l);

    assert(list_length(l) == 4);
    assert(list_get_elem_at(l, 2) == 99);
    assert(list_get_elem_at(l, 9) == -1);
    assert(list_get_index_of(l, 3) == 4);
    assert(list_get_index_of(l, 42) == -1);
    assert(list_is_in(l, 2) && !list_is_in(l, 42));

    assert(list_remove_at_index(l, 2) == 99);
    assert(list_remove_from_front(l) == 1);
    assert(list_remove_from_back(l) == 3);
    assert(list_remove_from_back(l) == 2);
    assert(list_length(l) == 0);
    assert(list_remove_from_front(l) == -1);

    list_add_to_back(l, 7);
    char *s = listToString(l);
    printf("%s\n", s);
    free(s);

    list_free(l);
    printf("all tests passed\n");
    return 0;
}