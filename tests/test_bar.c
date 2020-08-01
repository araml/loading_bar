#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>
#include <loading_bar.h>

#define cmp_str(s1, s2) { \
    for (int i = 0; s1[i] != 0; i++) { \
        assert_true(s1[i] == s2[i]); \
    } \
}

static void test_create_destroy(void **state) {
    loading_bar *b = loading_bar_create('#', 10);
    const char cmp[] = "[          ]";

    cmp_str(cmp, b->bar);

    loading_bar_destroy(b);
}

static void test_overflow_percentage(void **state) {
    loading_bar *b = loading_bar_create('4', 20);
    char cmp[] = "[44                  ]";
    loading_bar_update(b, 10);

    cmp_str(cmp, b->bar);

    // Overflow value bar should be filled like 100%
    loading_bar_update(b, 100);
    for (size_t i = 1; i <= 20; i++) {
        cmp[i] = '4';
    }

    cmp_str(cmp, b->bar);
    loading_bar_destroy(b);
}

static void test_underflow_percentage(void **state) {
    loading_bar *b = loading_bar_create('c', 20);
    char cmp[] = "[cccc                ]";
    loading_bar_update(b, 20);

    cmp_str(cmp, b->bar);

    // Overflow value bar should be filled like 100%
    loading_bar_update(b, 0);
    for (size_t i = 1; i <= 20; i++) {
        cmp[i] = ' ';
    }

    cmp_str(cmp, b->bar);

    cmp[1] = cmp[2] = 'c';
    loading_bar_update(b, 10);
    cmp_str(cmp, b->bar);

    cmp[1] = cmp[2] = ' ';
    loading_bar_update(b, -1000);


    loading_bar_destroy(b);
}

static void test_display_percentage(void **state) {
    loading_bar *b = loading_bar_create('4', 20);
    char cmp[] = "[44                  ]";
    loading_bar_update(b, 10);

    cmp_str(cmp, b->bar);
    display_percentage(b, false);
    cmp_str(cmp, b->bar);
    char cmp2[] = "[44                  ] 10%";
    display_percentage(b, true);
    cmp_str(cmp2, b->bar);
    display_percentage(b, false);
    cmp_str(cmp, b->bar);

    loading_bar_destroy(b);


}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_destroy),
        cmocka_unit_test(test_overflow_percentage),
        cmocka_unit_test(test_underflow_percentage),
        cmocka_unit_test(test_display_percentage),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
