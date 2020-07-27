#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <loading_bar.h>

static void test_create_destroy(void **state) {
    loading_bar *b = loading_bar_create('#', 10);
    const char cmp[] = "[          ]";

    for (int i = 0; i < sizeof(cmp) ;i++) {
        assert_true(cmp[i] == b->bar[i]);
    }

    loading_bar_destroy(b);
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_destroy),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
