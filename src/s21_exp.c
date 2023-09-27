#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1, temp = 1;
  long double e = 1;
  int flag = (x < 0 ? 1 : 0);
  x = (x < 0 ? -x : x);
  while (s21_fabs(result) > S21_EPS) {
    result *= x / e;
    e += 1;
    temp += result;
    if (temp > DBL_MAX) return S21_INF;
  }
  return (flag == 1 && temp <= DBL_MAX ? 1. / temp : temp);
}
