#include "s21_math_test.h"

START_TEST(simple_test) {
  double x = 0.5;

  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(big_num) {
  double x = 12345678910;

  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(big_double_num) {
  double x = 0.00000008;

  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(negative_num) {
  double x = -100.05;

  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

Suite* suite_exp() {
  Suite* suite = suite_create("exp_suite");
  TCase* tcase_core = tcase_create("exp_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, big_double_num);
  tcase_add_test(tcase_core, negative_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}