#include "s21_math.h"

long double s21_log(double x) {
  long double result;
  if (x != x || x == S21_INF) {
    result = x;
  } else if (x == 0) {
    result = -S21_INF_POS;
  } else if (x == 1) {
    result = 0;
  } else if (x < 0) {
    result = S21_NAN;
  } else if (x == S21_INF_NEG) {
    result = 1;
  } else if (x == 2) {
    result = S21_LN2;
  } else {
    int pow = 0;
    while (x - 1 > 1) {
      x *= 0.1;
      pow++;
    }
    long double ln = x - 1;
    long double element = (x - 1);
    for (int k = 2; s21_fabs(element) >= S21_EPS && s21_fabs(x - 1) <= 1; k++) {
      element = (element * (-1 * (x - 1)) * (k - 1)) / k;
      ln += element;
    }
    result = ln + S21_LN10 * pow;
  }
  return result;
}
