#include "s21_math_test.h"

START_TEST(simple_test) {
  double x = 5.0;

  ck_assert_double_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(big_num) {
  double x = 5.00000008;

  ck_assert_double_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(negative_num) {
  double x = -5.0;

  ck_assert_double_nan(s21_log(x));
}
END_TEST

START_TEST(test1) {
  double x = 0;

  ck_assert(isinf(s21_log(x)));
  ck_assert(isinf(log(x)));
  ck_assert(s21_log(x) == log(x));
}
END_TEST

START_TEST(test2) {
  double x = 2;

  ck_assert_double_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(test3) {
  double x = 1;

  ck_assert_double_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

Suite* suite_log() {
  Suite* suite = suite_create("log_suite");
  TCase* tcase_core = tcase_create("log_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, negative_num);
  tcase_add_test(tcase_core, test1);
  tcase_add_test(tcase_core, test2);
  tcase_add_test(tcase_core, test3);

  suite_add_tcase(suite, tcase_core);
  return suite;
}