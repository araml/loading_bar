#include <stdio.h>
#include <loading_bar.h>

int main() {
    loading_bar *b = loading_bar_create('/', 10);
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

    loading_bar *b2 = loading_bar_create('/', 40);
    loading_bar_update(b2, 60);
    printf("%s\n", b2->bar);
    return 0;
}
