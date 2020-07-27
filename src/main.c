#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char symbol;
    int width;
    int size;
    char *bar;
} loading_bar;

loading_bar *loading_bar_init(char loading_symbol, int width) {
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

float clamp(float value, float low, float high) {
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
    printf("prctg %d\n", prctg);
    printf("%d\n", bar->width);
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

int main() {
    loading_bar *b = loading_bar_init('/', 10);
    loading_bar_update(b, 30.f);
    printf("%s\n", b->bar);
    loading_bar_update(b, 50.f);
    printf("%s\n", b->bar);
    loading_bar_update(b, 100.f);
    printf("%s\n", b->bar);
    loading_bar_update(b, 70.f);
    printf("%s\n", b->bar);
    loading_bar_update(b, 200.f);
    printf("%s\n", b->bar);

    loading_bar *b2 = loading_bar_init('/', 40);
    loading_bar_update(b2, 60);
    printf("%s\n", b2->bar);
    return 0;
}
