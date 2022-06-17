#include "ExchangeOption.h"
#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

ExchangeOption::ExchangeOption()
{
	S1 = 0;
	S2 = 0;
    r = 0;
    T = 0;
	cpflag = true;
}

ExchangeOption::ExchangeOption(double _S1, double _S2, double _r, double _T, bool _cpflag)
{
	S1 = _S1;
	S2 = _S2;
    r = _r;
    T = _T;
	cpflag = _cpflag; 
}

double ExchangeOption::exchange_value(double S1, double S2) const
{
    double payoff = (cpflag) ? max((S1 - S2), 0.0) : max((S1 - S2), 0.0); 
    double D0 = exp(-r*T);
	return D0 * payoff;
}
 
