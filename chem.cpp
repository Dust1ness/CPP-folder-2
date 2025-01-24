#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PLANK = 6.626e-34;

double e_light(double lambda){
    return PLANK * 3e8 / lambda;
}

