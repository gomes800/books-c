#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"
#include "book.h"
#include <stdio.h>

int main() {

    Book b1 = {"20216574", "beautiful book", "beautiful writer", true};

    addBook(b1);
    printf("Book name: %s\n", map_book[0].name);

    Book *b = findBook("20216574");
    if (b) {
        printf("%s\n", b->name);
    }

    deleteBook("20216574");

    return 0;
}
