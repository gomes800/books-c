#include "stb_ds.h"
#include "book.h"

Book *map_book = NULL;

void addBook(Book book) {
    shputs(map_book, book);
}
