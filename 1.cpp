#include <iostream>

using namespace std;

float calcByRule(float x, int n){
	if(n % 2 == 0 && n != 0)
		return pow((pow(x, n/2)), 2);
	else
		return x*calcByRule(y, (n-1));
}

int main(){
	setlocale(LC_ALL, "Rus");
	float x = 0;
	int n = 0;
	cout << "Введите x = ";
	cin >> x;
	cout << "Введите n = ";
	cin >> n;
	cout << "Ответ = " << calcByRule(x, n);
	system("pause");
	return 0;
}