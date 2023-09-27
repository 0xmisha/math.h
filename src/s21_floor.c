#include "s21_math.h"

long double s21_floor(double x) {
  if (S21_IS_NAN(x) || x == 0 || x == S21_NEGZERO || S21_IS_INF(x)) return x;
  long double answer = (long long int)x;
  return (answer <= x ? answer : answer - 1);
}
