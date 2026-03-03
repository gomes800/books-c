#define _DEFAULT_SOURCE
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"
#include "book.h"
#include <stdio.h>
#include <string.h>

int main() {

    char *tmp;

    FILE *f = fopen("data.csv", "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char line[256];

    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = 0;
        tmp = strtok(line, ";");
        if (tmp) {
            Book new;
            new.key = strdup(tmp);

            tmp=strtok(NULL, ";");
            new.name = tmp ? strdup(tmp) : strdup("null");

            tmp = strtok(NULL, ";");
            new.author = tmp ? strdup(tmp) : strdup("null");

            new.read = false;

            addBook(&map_book, new);
        }
    }

    fclose(f);

    printf("Book name: %s\n", map_book[0].name);

    Book *b = findBook("20263045");
    if (b) {
        printf("%s\n", b->name);
    }

    return 0;
}
