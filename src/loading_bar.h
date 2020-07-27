#ifndef LOADING_BAR_H
#define LOADING_BAR_H

#include <stdlib.h>

typedef struct {
    char symbol;
    int width;
    int size;
    char *bar;
} loading_bar;

loading_bar *loading_bar_create(char loading_symbol, int width);
void loading_bar_update(loading_bar *bar, float percentage);
void loading_bar_destroy(loading_bar *bar);

#endif // LOADING_BAR_H

