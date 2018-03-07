#pragma once
#include <tr1/functional>

double Int_4d(double a, double b, std::tr1::function< double(double, double, double, double) > F);
