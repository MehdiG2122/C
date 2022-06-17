#pragma once

class BachelierModel{

private:
    double F0;
    double Sigma;
    double R;

public:

    BachelierModel();

    BachelierModel(double _F0, double _Sigma, double _R);

    ~BachelierModel(){};

    double BachelierPrice(bool flag, double T, double K) const;

};

