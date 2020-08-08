//
// Created by Markiian Benovskyi on 08/08/2020.
//

#include <stdio.h>
#include <time.h>
#include "app.h"

void print_header() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("~~~~~ [%s] [%s] ~~~~~\n", COMPILER_NAME, COMPILER_VERSION);
    printf("[cassowary] %s\n", COMPILER_DESC);
    printf("[cassowary] (c) 2020-%d by %s\n", tm.tm_year + 1900, COMPILER_AUTHOR);
    printf("[cassowary] version %s\n", COMPILER_VERSION);
    printf("[cassowary] %s\n", COMPILER_EATER);
    printf("[cassowary] %s\n", COMPILER_PAGE);
    printf("\n");
}

int main() {
    print_header();

    return 0;
}
