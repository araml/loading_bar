#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <loading_bar.h>

loading_bar *loading_bar_create(char loading_symbol, int width) {
    loading_bar *bar = (loading_bar *) malloc(sizeof(loading_bar));
    bar->symbol = loading_symbol;
    bar->bar = (char *) malloc(width + 3);
    for (int i = 0; i < width + 2; i++)
        bar->bar[i] = ' ';
    bar->bar[0] = '[';
    bar->bar[width + 1] = ']';
    bar->bar[width + 2] = 0;
    bar->width = width;
    bar->size = width + 3;
    bar->current_percentage = 0;
    bar->display_percentage = false;
    return bar;
}

int display_percentage(loading_bar *b, int display_percentage) {
    if (!b)
        return LB_ERR;
    if (!b->display_percentage && display_percentage) {
        char *nb = (char *)realloc(b->bar, b->size + 5);
        if (!nb) { // realloc err
            return LB_ERR;
        }
        b->bar = nb;
        sprintf(&b->bar[b->width + 2], " %d%%", b->current_percentage);
        b->size += 5;
        b->bar[b->size - 1] = 0;
        b->display_percentage = display_percentage;
    } else if (b->display_percentage && !display_percentage) {
        char *nb = (char *)realloc(b->bar, b->size - 5);
        b->bar = nb;
        if (!nb) { // realloc err
            return LB_ERR;
        }
        b->size -= 5;
        b->bar[b->size - 1] = 0;
        b->display_percentage = display_percentage;
    }

    return LB_OK;
}

static float clamp(float value, float low, float high) {
    float result = value;
    if (value < low)
        result = low;
    if (value > high)
        result = high;
    return result;
}

void loading_bar_update(loading_bar *bar, float percentage) {
    bar->current_percentage  = percentage = clamp(percentage, 0., 100.);
    int prctg = (percentage * (float)bar->width) / 100.;


    for (int i = 1; i <= bar->width; i++) {
        if (i <= prctg)
            bar->bar[i] = bar->symbol;
        else
            bar->bar[i] = ' ';
    }
}

void loading_bar_destroy(loading_bar *bar) {
    free(bar->bar);
    free(bar);
}

