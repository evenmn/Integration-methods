#include <iostream>
#include <tr1/functional>

double Trans_2d(double x, double y, double a, double b, double c, double d, std::tr1::function< double(double, double) > f) {
    /*
    Transforms integration limits from (a,b) to (-1,1) using
    int_a^b f(x) dx = (b-a)/2 int_(-1)^1 f((b-a)/2 x + (b+a)/2) dx
    */

    double coeff_a = (b-a)/2;
    double coeff_c = (d-c)/2;

    return coeff_a*coeff_c * f(a + coeff_a*(1+x), c + coeff_c*(1+y));
}

double Trans_1d(double x, double a, double b, std::tr1::function< double(double) > f) {
    /*
    Transforms integration limits from (a,b) to (-1,1) using
    int_a^b f(x) dx = (b-a)/2 int_(-1)^1 f((b-a)/2 x + (b+a)/2) dx
    */

    double coeff_min; double coeff_plus;
    coeff_min = (b-a)/2;
    coeff_plus = (b+a)/2;

    return coeff_min * f(coeff_min*x + coeff_plus);
}
