#pragma once
#include "BlackScholesSimulator.h"
class BlackScholesEulerExactSimulator : public BlackScholesSimulator
{
  public:
	BlackScholesEulerExactSimulator();
	BlackScholesEulerExactSimulator(const BlackScholesModel&, long _steps, double _T);
	~BlackScholesEulerExactSimulator();
	virtual double simulate_one_step(double S0 ,double dt,  double xsi) const;
};