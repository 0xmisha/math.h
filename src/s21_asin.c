#include "s21_math.h"

long double s21_asin(double x) {
  long double asin = x;
  int k = 1;
  long double element = x;
  long double result;
  if (x > 1 || x < -1)
    result = S21_NAN;
  else if (x == 1) {
    result = S21_PI_2;
  } else if (x == -1) {
    result = -S21_PI_2;
  } else {
    while (s21_fabs(element) >= S21_EPS) {
      element = ((element) * (x * x) * (2 * k - 1) * (2 * k - 1)) /
                ((2 * k + 1) * (2 * k));
      asin += element;
      k++;
    }
    result = asin;
  }
  return result;
}
