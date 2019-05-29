#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double f1(double x1, double x2, double x3)
{
    return 4*x1 - x2 - x3 - 6;
}
 
double f2(double x1, double x2, double x3)
{
    return -x1 + 8*x2 - 4;
}
 
double f3(double x1, double x2, double x3)
{
 
    return x1 - x2 + 6*x3;
}
 
double g1(double x1, double x2, double x3)
{
    return x1 - 0.005*f1(x1, x2, x3);
}
 
double g2(double x1, double x2, double x3)
{
    return x2 - 0.005*f2(x1, x2, x3);
}
 
double g3(double x1, double x2, double x3)
{
    return x3 - 0.005*f3(x1, x2, x3);
}
 
int main()
{
    cout<<"\tEnter initial values of params\n";
    double x1;cout<<"x1 = ";cin>>x1;
    double x2;cout<<"x2 = ";cin>>x2;
    double x3;cout<<"x3 = ";cin>>x3;
    double er;
    cout<<"Accuracy of calculations = ";cin>>er;
    for
    (
        double it = 1; 
        er < fabs(f1(x1, x2, x3)) || er < fabs(f2(x1, x2, x3)) || er < fabs(f3(x1, x2, x3));
        it = it + 1
    )
    {
        cout<<"Iteration # "<<setprecision(0)<<it<<endl;
        cout<<"x1 "<<setprecision(0)<<(x1 = g1(x1, x2, x3))<<endl;
        cout<<"x2 "<<setprecision(0)<<(x2 = g2(x1, x2, x3))<<endl;
        cout<<"x3 "<<setprecision(0)<<(x3 = g3(x1, x2, x3))<<endl;
    }
    cout<<"f1(x1, x2, x3) = 4*x1 - x2 - x3 - 6 = "<<f1(x1, x2, x3)<<endl;
    cout<<"f2(x1, x2, x3) = -x1 + 8*x^2    - 4 = "<<f2(x1, x2, x3)<<endl;
    cout<<"f3(x1, x2, x3) = x1 - x2 + 6*x3     = "<<f3(x1, x2, x3)<<endl;
    system("pause");
    return 0;
}