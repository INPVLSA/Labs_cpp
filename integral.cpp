#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

float f(float x) {
  return pow(sin(x), 2) - 3 * cos(x);
}

int main() {
  setlocale(LC_ALL, "rus");
  int a, b; // границы отрезка интегрирования
  cout << "Введите границы интрегрирования: " << endl;
  cin >> a >> b;
  if (a > b) {
    int c;
    c = a;
    a = b;
    b = c;
  }
  float h; // шаг
  cout << "Введите точность: " << endl;
  cin >> h;
  float n; // число разбиений
  n = (b - a) / h;
  double integral = 0.0;
  //------------метод трапеций ------------
  integral = h * (f(a) + f(b)) / 2.0;
  for (int i = 1; i <= n - 1; i++)
    integral = integral + h * f(a + h * i);
  cout << "I = " << integral << "\n";

  system("pause");
  return 0;
}