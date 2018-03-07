#include <iostream>
#include <tr1/functional>           // For using function inside another func
#include <tools.h>

using std::tr1::function;
using namespace std;

double Int_2d(double a, double b, double c, double d, int n, function< double(double, double) > f) {
    /*
    Integrating using Gaussian Quadrature, temporary only working for
    n=3. A polynomial of order 2n-1 is integrated exact.
    */

    // Magic numbers
    double c1 = 0.3086419753;    // (5/9)^2
    double c2 = 0.7901234568;    // (8/9)^2
    double c3 = 0.4938271605;    // (8/9)(5/9)
    double x1 = 0.7745966692;    // sqrt(3/5)

    return c1 * Trans_2d(-x1, -x1, a, b, c, d, f) + \
           c3 * Trans_2d(0,   -x1, a, b, c, d, f) + \
           c1 * Trans_2d(x1,  -x1, a, b, c, d, f) + \
           c3 * Trans_2d(-x1, 0,   a, b, c, d, f) + \
           c2 * Trans_2d(0,   0,   a, b, c, d, f) + \
           c3 * Trans_2d(x1,  0,   a, b, c, d, f) + \
           c1 * Trans_2d(-x1, x1,  a, b, c, d, f) + \
           c3 * Trans_2d(0,   x1,  a, b, c, d, f) + \
           c1 * Trans_2d(x1,  x1,  a, b, c, d, f);
}
