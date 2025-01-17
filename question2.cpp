#include <iostream>
#include <cmath>
#include <iomanip>
#include "coulombs_law.cpp"

using namespace std;

int question2(){

    double q1{5.79e-9}, q2{11.6e-9}, q3{11.6e-9};

    double rq = 0.02;
    double r2 = distance(-0.03, -0.02);
    double r3 = distance(0.03, -0.02);

    double f_q2y = (8.99e9 * q1 * q2 / pow(r2, 2)) * sin(atan(0.02/0.03));
    double f_q3y = (8.99e9 * q1 * q3 / pow(r3, 2)) * sin(atan(0.02/0.03));

    double q =( 1/(8.99e9) * (rq * rq) * (f_q2y + f_q3y) )/ q1;
    cout << scientific << setprecision(3) << q << endl;


}