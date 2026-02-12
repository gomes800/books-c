#ifndef BOOKS_H
#define BOOKS_H

#include <stdbool.h>

typedef struct {
    char *key;
    char *name;
    char *author;
    bool read;
} Book;

extern Book *map_book;

void addBook(Book book);
void deleteBook(char *key);

#endif
