#include <iostream>
#include <1d.h>
#include <2d.h>
#include <tr1/functional>

using namespace std;

double Function_1d(double x){
    return x;
}

double Function_2d(double x, double y){
    return x + y;
}

int main()
{
    double twod = Int_2d(0, 1, 0, 1, 3, Function_2d);
    cout << twod << endl;

    double oned = Int_1d(0, 1, 2, Function_1d);
    cout << oned << endl;
    return 0;
}
