#include "VanillaEuropeanOption.h"
#include <iostream>
#include <algorithm>

using namespace std;

VanillaEuropeanOption::VanillaEuropeanOption()
{
	T = 0;
	K = 0;
	cpflag = true;
}

VanillaEuropeanOption::VanillaEuropeanOption(double _T, double _K, bool _cpflag)
{
	T = _T;
	K = _K;
	cpflag = _cpflag; 
}

double VanillaEuropeanOption::evaluate_payoff(double S) const
{
	return (cpflag) ? max((S - K), 0.0) : max((K - S), 0.0); 
}
 
