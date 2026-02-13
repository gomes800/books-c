#include "stb_ds.h"
#include "book.h"
#include <stdio.h>

Book *map_book = NULL;

void addBook(Book book) {
    shputs(map_book, book);
}

Book *findBook(char *key) {
    return shgetp_null(map_book, key);
}

void deleteBook(char *key) {
    (void) shdel(map_book, key);
    printf("Book deleted\n");
}

