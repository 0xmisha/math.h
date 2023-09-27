

#include <float.h>
#include <stdio.h>

#define S21_INF __builtin_huge_valf()
#define S21_NAN __builtin_nan("")
#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)
#define S21_NEGZERO -0.0
#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define TEST_EPS 1e-6l
#define S21_EPS 1e-25
#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_PI_4 0.78539816339744830961566084581987572
#define S21_LN2 0.693147180559945309417232121458176568
#define S21_LN10 2.30258509299404568401799145468436421

int s21_abs(int);
long double s21_acos(double);
long double s21_asin(double);
long double s21_atan(double);
long double s21_ceil(double);
long double s21_cos(double);
long double s21_exp(double);
long double s21_fabs(double);
long double s21_floor(double);
long double s21_fmod(double, double);
long double s21_log(double);
long double s21_pow(double, double);
long double s21_sin(double);
long double s21_sqrt(double);
long double s21_tan(double);
