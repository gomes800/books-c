#include "stb_ds.h"
#include "book.h"
#include <stdio.h>

Book *map_book = NULL;

void addBook(Book **map_ptr, Book new_book) {
    shputs(*map_ptr, new_book);
}

Book *findBook(char *key) {
    return shgetp_null(map_book, key);
}

void deleteBook(char *key) {
    (void) shdel(map_book, key);
    printf("Book deleted\n");
}

