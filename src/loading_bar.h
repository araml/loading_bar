#ifndef LOADING_BAR_H
#define LOADING_BAR_H

#define LB_ERR 1
#define LB_OK 0

typedef struct {
    char symbol;
    int width;
    int size;
    char *bar;
    int current_percentage;
    int display_percentage;
} loading_bar;

loading_bar *loading_bar_create(char loading_symbol, int width);
void loading_bar_update(loading_bar *bar, float percentage);
void loading_bar_destroy(loading_bar *bar);
int display_percentage(loading_bar *bar, int display_percentage);

#endif // LOADING_BAR_H

