#include <iostream>
#include <tools.h>
#include <tr1/functional>

double Int_1d(double a, double b, int n, std::tr1::function< double(double) > f) {
    /*
    Integrating using Gaussian Quadrature, temporary only working for
    n=2. A polynomial is integrated exact.
    */

    double c1 = 0.5555555556;    // (5/9)
    double c2 = 0.8888888889;    // (8/9)
    double x1 = 0.7745966692;    // sqrt(3/5)

    return c1*Trans_1d(-x1,a,b,f) + c2*Trans_1d(0,a,b,f) + c1*Trans_1d(x1,a,b,f);
}
