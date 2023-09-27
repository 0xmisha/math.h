#include "s21_math.h"

long double s21_sin(double x) {
  long double answer = 0;
  if (S21_IS_INF(x) || S21_IS_NAN(x)) {
    answer = S21_NAN;
  } else {
    long double i = 1;
    long double sin = s21_fmod(x, 2 * S21_PI);
    long double q = sin;

    while (s21_fabs(q) > 1e-12) {
      // добавляем слагаемое к общей сумме
      answer = answer + q;
      // вычисляем следующее слагаемое
      q = (-1) * q * (sin * sin) / ((2 * i + 1) * (2 * i));
      // увеличиваем порядковый номер слагаемого в рядуТейлора
      i++;
    }
  }
  return answer;
}