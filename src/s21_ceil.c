#include "s21_math.h"
long double s21_ceil(double x) {
  long double answer = (long long int)x;
  if (S21_IS_NAN(x) || x == 0 || x == S21_NEGZERO || S21_IS_INF(x) ||
      x == DBL_MAX)
    answer = x;
  else if (answer < x)
    answer++;

  return answer;
}