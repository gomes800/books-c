#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"
#include "book.h"
#include <stdio.h>

int main() {

    FILE *f = fopen("data.csv", "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char line[256];

    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f)) {
        char id[32];
        char name[64];
        char author[64];
        int read;

        if (sscanf(
                    line,
                     " %31[^,],%63[^,],%63[^,],%d",
                     id, name, author, &read
                  ) == 4) {
            printf("ID=%s | Name=%s | Author=%s | Read=%d\n",
                    id, name, author, read);
        }
    }

    fclose(f);

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
