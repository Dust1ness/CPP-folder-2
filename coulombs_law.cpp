#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fc_net(double q1, double q2, double r) {
    double k = 8.99 * pow(10, 9);
    return k * q1 * q2 / pow(r, 2);
}

double distance(double dx, double dy) {
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

double f_x(double fc_net, double dx, double dy) {
    return fc_net * dx / distance(dx, dy);
}

double fy(double fc_net, double dx, double dy) {
    return fc_net * dy / distance(dx, dy);
}

void question2(){

    double q1{1e-9}, q2{2e-9}, q3{2e-9};

    double rq = 0.02;
    double r2 = distance(-0.03, -0.02);
    double r3 = distance(0.03, -0.02);

    double f_q2y = (8.99e9 * q1 * q2 / pow(r2, 2)) * sin(atan(0.02/0.03));
    double f_q3y = (8.99e9 * q1 * q3 / pow(r3, 2)) * sin(atan(0.02/0.03));

    double q =( 1/(8.99e9) * (rq * rq) * (f_q2y + f_q3y) )/ q1;
    cout << scientific << setprecision(3) << q << endl;

}



int coulomb_3body() {
    cout << scientific << setprecision(3);

    double q1, q2, q3, dx2, dy2, dx3, dy3;
    cout << "Enter q1, q2, q3, dx2, dy2, dx3, dy3: " << endl;
    cin >> q1 >> q2 >> q3 >> dx2 >> dy2 >> dx3 >> dy3;

    
    double f_12 = fc_net(q1, q2, distance(dx2, dy2));
    double f_13 = fc_net(q1, q3, distance(dx3, dy3));

    cout << "f_12 = " << f_12 << " N and f_13 = " << f_13 << " N" << endl;

    double f_12_x = f_x(f_12, dx2, dy2);
    double f_12_y = fy(f_12, dx2, dy2);

    double f_13_x = f_x(f_13, dx3, dy3);
    double f_13_y = fy(f_13, dx3, dy3);

    double fc_net_x = -(f_12_x + f_13_x);
    double fc_net_y = -(f_12_y + f_13_y);

    cout << "fc_net_x = " << fc_net_x << " N and fc_net_y = " << fc_net_y << " N" << endl;

    double f_total = distance(fc_net_x, fc_net_y);

    cout << f_total << endl;
    cout << sqrt(fc_net_x * fc_net_x + fc_net_y*fc_net_y ) << endl;

    return 0;
}
