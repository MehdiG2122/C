#pragma once
#include "EuropeanPayoff.h"
class ExchangeOption : public EuropeanPayoff
{
private:
    double S1;
    double S2; 
    double r;
    double T;
    bool cpflag; 
public:
    ExchangeOption(); 
    ExchangeOption(double _S1, double _S2, double _r, double _T, bool _cpflag);    
    double exchange_value(double S1, double S2) const;
    ~ExchangeOption() {};
};

