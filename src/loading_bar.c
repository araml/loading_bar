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
    bar->size = width + 2;

    return bar;
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
    percentage = clamp(percentage, 0., 100.);
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

