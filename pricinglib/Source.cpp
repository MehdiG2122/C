#include <iostream>

#include <iostream>
#include <string>
#include <random>

#include <random>
#include "math.h"
#include <algorithm>
#include "BlackScholesModel.h"
#include "ForwardContract.h"
#include "VanillaEuropeanOption.h"
#include "BlackScholesEulerSimulator.h"
#include "BlackScholesEulerExactSimulator.h"

using namespace std;

int main()
{

	double S0 = 107;
	double mu = 0.02;
	double r = mu;
	double sigma = 0.15;

	double T = 1;
	double F = S0 * exp(mu * T);

	double K = F;


	// analytical price; 
	BlackScholesModel BS(S0, mu, r, sigma);

	long long_or_short_forward = 1;

	double ITM = 1;
	K = ITM * F;

	double forward_price_analytical = BS.forwardPrice(long_or_short_forward, T, K);

	double price_forward_analytical = 0;

	price_forward_analytical = BS.forwardPrice(long_or_short_forward, T, K);
	double price_forward_numerical = 0;

	cout << "Forward Analytical Price: \n\n";
	cout << price_forward_analytical << "\n\n";

	double price_option_analytical = 0;

	long cp = 1;
	price_option_analytical = BS.vanilla_european_option_price(cp, T, K);

	double price_option_numerical = 0;


	cout << "\n\n";
	cout << "Option analytical price: \n\n";
	cout << price_option_analytical << "\n\n";


	ForwardContract aForward(T, K, long_or_short_forward);

	cout << "Forward Analytical Price: \n\n";
	cout << price_forward_analytical << "\n\n";
	
	
	 unsigned num_step_mc = 10;

	BlackScholesEulerSimulator BSEulerSimulator(BS,
		num_step_mc,
		T);

	// simulation 
	unsigned num_path = 1000000;

	double price_forward_mc_euler = BSEulerSimulator.compute_monte_carlo_price(num_path, aForward);

	cout << "Forward Analytical Price: \n\n";
	cout << price_forward_analytical << "\n\n";
	cout << "Forward MC Price using Euler Scheme: \n\n";
	cout << price_forward_mc_euler << "\n\n";

  VanillaEuropeanOption VEO(T, K, true);

  double EuropeanVanillapo = VEO.evaluate_payoff(S0);
  cout << "Vanilla European Analytical price: \n\n ";
  cout << EuropeanVanillapo << "\n\n";

  double price_option_mc_euler = BSEulerSimulator.compute_monte_carlo_price(num_path, VEO);
  cout << "Option Euler MC price: \n\n";
  cout << price_option_mc_euler << "\n\n";

  BlackScholesEulerExactSimulator BSEulerExactSimulator(BS, 1, T);

  double price_option_mc_euler_exact = BSEulerExactSimulator.compute_monte_carlo_price(num_path, VEO);
  cout << "Option Euler Exact MC price: \n\n";
  cout << price_option_mc_euler_exact << "\n\n";
  
  
	return 0;
}
