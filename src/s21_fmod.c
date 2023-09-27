#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double answer = 0;
  if (S21_IS_NAN(x) || S21_IS_NAN(y) || S21_IS_INF(x) || y == 0) {
    answer = S21_NAN;
  } else if (S21_IS_INF(y)) {
    answer = x;
  } else if (x == 0.0 && y != 0) {
    answer = 0.0;
  } else {
    if (x < 0 || y < 0)
      answer = -s21_abs(x / y);
    else
      answer = s21_abs(x / y);
    answer = x - answer * y;
  }
  return answer;
}