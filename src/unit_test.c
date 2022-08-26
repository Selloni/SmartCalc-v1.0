#include "calc.h"
#include <check.h>


START_TEST(test_push) {
    int test[] = {3, 15 ,6};
    Node *list = NULL;
    for(size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        push(&list, test[i]);
        printf(list);
    }
}
END_TEST










Suite *make_sub_suite(void) {
    Suite *s = suite_create("test");
    TCase *tc_sub = tcase_create("test");
    suite_add_tcase (s, tc_sub);
    tcase_add_test (tc_sub, test_push);
    return s;
}

int main(void) {
    int n, n1;
    SRunner *sr, *sr1;
        sr = srunner_create(make_sub_suite());
    srunner_run_all(sr, CK_NORMAL);
        n= srunner_ntests_failed (sr);
    srunner_free(sr);
    return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}