#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double countF(double x){ // Функция вычисления значения заданной функции
	return pow(sin(x), 2) - 3 * cos(x);
}

int main() {
  int n, m, i, j, k, s;
  double X[100], Y[100], Y2[100], A[100][100], c[100], pog[100], d, a, b, f;
  cout << "a=";
  cin >> a;
  cout << "b=";
  cin >> b;
  cout << "n=";
  cin >> n;
  cout << "m=";
  cin >> m;
  cout << "\nZnacenie x,y:" << endl;
  for (i = 1; i <= m; i++) {
    X[i] = a + (i - 1) * (b - a) / (m - 1);
    Y[i] = countF(X[i]);
    printf("X[%d]=%3.2f       Y[%d]=%f\n", i, X[i], i, Y[i]);
  }

  for (k = 1; k <= n; k++) {
    A[k][1] = 1;
    int i = 0;
    for (s = 2; s <= n; s++) {
      i++;
      if (i == k) i++;
      d = X[k] - X[i];
      A[k][s] = A[k][s - 1] / d;
      for (j = s - 1; j >= 2; j--) A[k][j] = (A[k][j - 1] - A[k][j] * X[i]) / d;
      A[k][1] = -A[k][1] * X[i] / d;
    }
  }

  for (i = 1; i <= n; i++) {
    c[i] = 0;
    for (k = 1; k <= n; k++) c[i] = c[i] + A[k][i] * Y[k];
  }

  for (j = 1; j <= 21; j++) {
    X[j] = a + (j - 1) * (b - a) / 20;
    Y[j] = countF(X[j]);
  }
  for (j = 1; j <= 21; j++) {
    for (i = 1; i <= n; i++) {
      f = c[n - 1] + X[j] * c[n];
      for (s = 2; s <= n - 1; s++) f = c[n - s] + X[j] * f;
      Y2[j] = f;
      pog[j] = fabs(Y[j] - Y2[j]);
    }
  }

  cout << endl;
  printf("==========================================================================\n");
  printf("||   X:       ||      Y:       ||   Y aproksimacii: ||    Pogresnosti:  ||\n");
  printf("==========================================================================\n");
  for (i = 1; i <= 21; i++) 
  	printf("X[%-2d]=%3.2f      Y[%-2d]=%7.6f    Y2[%-2d]=%8.7f      pog[%-2d]=%7.6f\n", i, X[i], i, Y[i], i, Y2[i], i, pog[i]);
  return 0; }
