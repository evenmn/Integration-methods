#include <iostream>
#include <1d.h>
#include <2d.h>
#include <4d.h>
#include <tr1/functional>

using namespace std;

double Function_1d(double x){
    return x;
}

double Function_2d(double x, double y){
    return x + y;
}

double Function_4d(double x, double y, double z, double v){
    return x + y + z + v;
}

int main()
{
    double oned = Int_1d(0, 1, 2, Function_1d);
    cout << oned << endl;

    double twod = Int_2d(0, 1, 0, 1, 3, Function_2d);
    cout << twod << endl;

    double fourd = Int_4d(0, 1, Function_4d);
    cout << fourd << endl;

    return 0;
}
