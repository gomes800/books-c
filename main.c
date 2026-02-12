#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"
#include "book.h"
#include <stdio.h>

int main() {

    Book b1 = {"20216574", "test book", "tester", true};

    addBook(b1);
    printf("Book name: %s\n", map_book[0].name);

    return 0;
}
