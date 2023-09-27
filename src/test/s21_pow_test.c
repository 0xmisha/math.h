#include "s21_math_test.h"

START_TEST(simple_test) {
  double base = 0.5;
  double exp = 2.0;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(negative_exp) {
  double base = 0.234;
  double exp = -7.5;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(negative_base) {
  double base = -2.0;
  double exp = 10.0;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(zero_base) {
  double base = 0;
  double exp = 2.5;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(zero_exp) {
  double base = 2.0;
  double exp = 0;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(negative_dauble_base) {
  double base = -0.2;
  double exp = 10.0;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(big_test_2) {
  for (double k = -1e-1; k <= 1; k += 1.1e-1) {
    for (double g = -2.55; g < 2; g += 1.1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-5);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-5);
      }
    }
  }
}
END_TEST

START_TEST(big_test_3) {
  ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_double_eq(pow(-1, 4), s21_pow(-1, 4));
  ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
  ck_assert_double_eq(pow(INFINITY, 0), s21_pow(S21_INF, 0));
  ck_assert_double_eq(pow(INFINITY, -1), s21_pow(S21_INF, -1));
  ck_assert_double_eq(pow(-1, -INFINITY), s21_pow(-1, -S21_INF));
  ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, S21_INF));
  ck_assert_double_nan(s21_pow(0, S21_NAN));
  ck_assert_double_eq(pow(NAN, 0), s21_pow(S21_NAN, 0));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(S21_INF, S21_INF));
  ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(S21_INF, -S21_INF));
  ck_assert_double_eq(pow(-INFINITY, INFINITY), s21_pow(-S21_INF, S21_INF));
  ck_assert_double_eq(pow(-INFINITY, -INFINITY), s21_pow(-S21_INF, -S21_INF));
  ck_assert_double_eq(pow(1, -INFINITY), s21_pow(1, -S21_INF));
  ck_assert_double_eq(pow(1, NAN), s21_pow(1, S21_NAN));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF));
  ck_assert_double_nan(s21_pow(S21_INF, S21_NAN));
  ck_assert_double_nan(s21_pow(S21_NAN, -S21_INF));
  ck_assert_double_nan(s21_pow(-S21_INF, S21_NAN));
  ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, S21_INF));
  ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, S21_INF));
}
END_TEST

Suite* suite_pow() {
  Suite* suite = suite_create("pow_suite");
  TCase* tcase_core = tcase_create("pow_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, negative_exp);
  tcase_add_test(tcase_core, negative_base);
  tcase_add_test(tcase_core, zero_base);
  tcase_add_test(tcase_core, zero_exp);
  tcase_add_test(tcase_core, negative_dauble_base);
  tcase_add_test(tcase_core, big_test_2);
  tcase_add_test(tcase_core, big_test_3);

  suite_add_tcase(suite, tcase_core);
  return suite;
}