#include "s21_math.h"

long double s21_powd(long double a, int n);

long double s21_pow(double base, double exp) {
  long double result;
  if (base == 1 || exp == 0) {
    result = 1;
  } else if (base == -1 && s21_fabs(exp) == S21_INF) {
    result = 1;
  } else if (base == 0 && exp > 0) {
    result = 0;
  } else if (base == 0 && exp >= 0) {
    result = S21_INF;
  } else if (base != base || exp != exp) {
    result = S21_NAN;
  } else if ((exp == S21_INF && s21_fabs(base) > 1) ||
             (exp == -S21_INF && s21_fabs(base) < 1)) {
    result = S21_INF;
  } else if (exp == -S21_INF || (exp == S21_INF && s21_fabs(base) < 1)) {
    result = 0;
  } else {
    if (exp == (long int)exp || s21_fabs(exp) == S21_INF) {
      result = s21_powd(base, (int)exp);
    } else {
      result = exp > 0 ? s21_exp(exp * s21_log(base))
                       : 1 / (s21_exp(-exp * s21_log(base)));
    }
  }
  return result;
}

// реализация операции возведения в степень для случая, когда степень - целое
// число
long double s21_powd(long double a, int n) {
  long double answ = 1;
  if (n < 0) {
    n = -n;
    a = 1 / a;
  }
  for (int i = 0; i < n; i++) {
    answ = answ * a;
  }
  return answ;
}
