#pragma once
#include "EuropeanPayoff.h"
class VanillaEuropeanOption : public EuropeanPayoff
{
private:
    double T;
    double K; 
    bool cpflag; 
public:
    VanillaEuropeanOption(); 
    VanillaEuropeanOption(double _T, double _K, bool _cpflag);    
    virtual double evaluate_payoff(double S) const;
    ~VanillaEuropeanOption() {};
};

