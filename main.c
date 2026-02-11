#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"
#include "book.h"
#include <stdio.h>

int main() {
    Book *map_book = NULL;

    Book b1 = {"20216574", "test book", "tester", true};
    shputs(map_book, b1);

    int idx = shgeti(map_book, "20216574");
    if (idx != -1) {
        printf("Title: %s\n", map_book[idx].name);
    }

    shfree(map_book);

    return 0;
}
