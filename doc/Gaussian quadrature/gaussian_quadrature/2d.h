#pragma once
#include <tr1/functional>

double Int_2d(double a, double b, double c, double d, int n, std::tr1::function< double(double, double) > f);
