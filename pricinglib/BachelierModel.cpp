#include "BachelierModel.h"
#include <algorithm>
#include "math.h"
#include <cmath>


double normalCDF(double value){return 0.5 * erfc(-value * M_SQRT1_2);}
double normalPDF(double value){return (1 / sqrt(2 * M_PI)) * exp(-(pow(value,2) / 2));} 
    
BachelierModel::BachelierModel(){F0 = 1; R = 0; Sigma = 0;};

BachelierModel::BachelierModel(double _F0, double _Sigma, double _R){
    F0 = _F0;
    Sigma = _Sigma;
    R = _R;
}

double BachelierModel::BachelierPrice(bool flag, double T, double K) const
{
    double D0 = exp(-R*T);
    double d1 = ((F0 - K) == 0) ? 0: (D0 * (F0-K)) / (Sigma * sqrt(T));
    double call_price = D0*((Sigma * sqrt(T)) * normalPDF(d1) + ((F0 - K)* normalCDF(d1)) );
    double price = (flag) ? call_price: call_price - (F0 * D0) + (K * D0);
    return price;
}

