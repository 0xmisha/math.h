#include "s21_math.h"

long double s21_atan(double x) {
  long double result;

  if (x == S21_INF_POS)
    result = S21_PI / 2;
  else if (x == S21_INF_NEG)
    result = -S21_PI / 2;
  else if (x != x)
    result = x;
  else if (x == 1)
    result = S21_PI_4;
  else if (x == -1)
    result = -S21_PI_4;
  else {
    int is_in_range = (x > -1 && x < 1);
    int flag = 0;
    if (!is_in_range) {
      x = 1.0 / x;
      flag = (x > 0) ? 1 : -1;
    }

    long double term = x;
    result = term;
    int i;
    for (i = 3; s21_fabs(term) > S21_EPS; i += 2) {
      term *= -1.0 * x * x;
      result += term / i;
    }

    if (flag == 1)
      result = S21_PI / 2 - result;
    else if (flag == -1)
      result = -S21_PI / 2 - result;
  }

  return result;
}
