#include <iostream>
#include <tr1/functional>           // For using function inside another func
#include <cmath>

using std::tr1::function;
using namespace std;

double Transform(double x1, double x2, double x3, double x4, \ 
                 double a, double b, double c, double d, \
                 double e, double f, double g, double h, \
                 function< double(double, double, double, double) > F) {
    /*
    Transforms integration limits from (a,b) to (-1,1) using
    int_a^b f(x) dx = (b-a)/2 int_(-1)^1 f((b-a)/2 x + (b+a)/2) dx
    */
    
    double coeff_a = (b-a)/2; 
    double coeff_c = (d-c)/2;
    double coeff_e = (f-e)/2;
    double coeff_g = (h-g)/2;
    
    return coeff_a*coeff_c*coeff_e*coeff_g * F(a + coeff_a*(1+x1), c + \
           coeff_c*(1+x2), e + coeff_e*(1+x3), g + coeff_g*(1+x4));
}

double Int_4d(double a, double b, function< double(double, double, double, double) > F) {
    /*
    Integrating using Gaussian Quadrature 3 point in 4D, i.e, a polynomial of 
    order 5 or less is integrated exact. The limits a and b are assumed to be
    the same for all the integrals
    */
    
    double C = (b-a)/2;    // Transforms from (a, b) to (-1, 1)
    
    double c1 = 0.0952598689;    // (5/9)^4
    double c2 = 0.1524157903;    // (5/9)^3(8/9)
    double c3 = 0.2438652644;    // (5/9)^2(8/9)^2
    double c4 = 0.3901844231;    // (5/9)(8/9)^3
    double c5 = 0.6242950770;    // (8/9)^4
    double x = 0.7745966692;    // sqrt(3/5)
    double x1 = a + C*(1+x);
    double x2 = a + C*(1-x);
    
    double res;
    
    res = c1*F(x1,x1,x1,x1) + c2*F(0,x1,x1,x1) + c1*F(x2,x1,x1,x1) +\
          c2*F(x1, 0,x1,x1) + c3*F(0, 0,x1,x1) + c2*F(x2, 0,x1,x1) +\
          c1*F(x1,x2,x1,x1) + c2*F(0,x2,x1,x1) + c1*F(x2,x2,x1,x1) +\
          c2*F(x1,x1, 0,x1) + c3*F(0,x1, 0,x1) + c2*F(x2,x1, 0,x1) +\
          c3*F(x1, 0, 0,x1) + c4*F(0, 0, 0,x1) + c3*F(x2, 0, 0,x1) +\
          c2*F(x1,x2, 0,x1) + c3*F(0,x2, 0,x1) + c2*F(x2,x2, 0,x1) +\
          c1*F(x1,x1,x2,x1) + c2*F(0,x1,x2,x1) + c1*F(x2,x1,x2,x1) +\
          c2*F(x1, 0,x2,x1) + c3*F(0, 0,x2,x1) + c2*F(x2, 0,x2,x1) +\
          c1*F(x1,x2,x2,x1) + c2*F(0,x2,x2,x1) + c1*F(x2,x2,x2,x1) +\
          c2*F(x1,x1,x1, 0) + c3*F(0,x1,x1, 0) + c2*F(x2,x1,x1, 0) +\
          c3*F(x1, 0,x1, 0) + c4*F(0, 0,x1, 0) + c3*F(x2, 0,x1, 0) +\
          c2*F(x1,x2,x1, 0) + c3*F(0,x2,x1, 0) + c2*F(x2,x2,x1, 0) +\
          c3*F(x1,x1, 0, 0) + c4*F(0,x1, 0, 0) + c3*F(x2,x1, 0, 0) +\
          c4*F(x1, 0, 0, 0) + c5*F(0, 0, 0, 0) + c4*F(x2, 0, 0, 0) +\
          c3*F(x1,x2, 0, 0) + c4*F(0,x2, 0, 0) + c3*F(x2,x2, 0, 0) +\
          c2*F(x1,x1,x2, 0) + c3*F(0,x1,x2, 0) + c2*F(x2,x1,x2, 0) +\
          c3*F(x1, 0,x2, 0) + c4*F(0, 0,x2, 0) + c3*F(x2, 0,x2, 0) +\
          c2*F(x1,x2,x2, 0) + c3*F(0,x2,x2, 0) + c2*F(x2,x2,x2, 0) +\
          c1*F(x1,x1,x1,x2) + c2*F(0,x1,x1,x2) + c1*F(x2,x1,x1,x2) +\
          c2*F(x1, 0,x1,x2) + c3*F(0, 0,x1,x2) + c2*F(x2, 0,x1,x2) +\
          c1*F(x1,x2,x1,x2) + c2*F(0,x2,x1,x2) + c1*F(x2,x2,x1,x2) +\
          c2*F(x1,x1, 0,x2) + c3*F(0,x1, 0,x2) + c2*F(x2,x1, 0,x2) +\
          c3*F(x1, 0, 0,x2) + c4*F(0, 0, 0,x2) + c3*F(x2, 0, 0,x2) +\
          c2*F(x1,x2, 0,x2) + c3*F(0,x2, 0,x2) + c2*F(x2,x2, 0,x2) +\
          c1*F(x1,x1,x2,x2) + c2*F(0,x1,x2,x2) + c1*F(x2,x1,x2,x2) +\
          c2*F(x1, 0,x2,x2) + c3*F(0, 0,x2,x2) + c2*F(x2, 0,x2,x2) +\
          c1*F(x1,x2,x2,x2) + c2*F(0,x2,x2,x2) + c1*F(x2,x2,x2,x2);

    return C*C*C*C*res;
}
