
#include "s21_math.h"
long double s21_cos(double x) {
  long double answer = S21_NAN;
  if (x != S21_INF_POS || x != S21_INF_NEG || !S21_IS_NAN(x))
    answer = s21_sin(S21_PI / 2 - x);
  return answer;
}