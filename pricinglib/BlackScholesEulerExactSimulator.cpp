#include "BlackScholesEulerExactSimulator.h"
#include "math.h"

BlackScholesEulerExactSimulator::BlackScholesEulerExactSimulator():BlackScholesSimulator(){}
BlackScholesEulerExactSimulator::BlackScholesEulerExactSimulator(const BlackScholesModel& _model,long _steps,	double _T): BlackScholesSimulator(_model, _steps,_T){}
BlackScholesEulerExactSimulator::~BlackScholesEulerExactSimulator(){}

double BlackScholesEulerExactSimulator::simulate_one_step(double S0, double dt, double xsi) const
{
	BlackScholesModel model = get_model();
	return S0 * exp( ( model.get_mu() - pow(model.get_sigma(),2)/2 )* dt + model.get_sigma() * (sqrt(dt) * xsi) );
}
