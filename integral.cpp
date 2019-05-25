#include <iostream>
#include <math.h>

using namespace std;
 
float f(float x){
	return pow(sin(x), 2) - 3 * cos(x);
}

int main() {
	int a = 1, b = 7, n = 0;
	cout << "n = ";
	cin >> n;
	float s = ( f(a) + f(b) ) / 2;
	float h = ( b - a ) / n;
	for (int i = 1; i <= n-1; i++)
		s += f ( a + i * h );
	float I = h * s;

	cout << "Answer = " << I << endl;
	return 0;
}