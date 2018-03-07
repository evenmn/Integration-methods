#pragma once
#include <tr1/functional>

double Trans_2d(double x, double y, double a, double b, double c, double d, std::tr1::function< double(double, double) > f);
double Trans_1d(double x, double a, double b, std::tr1::function< double(double) > f);
