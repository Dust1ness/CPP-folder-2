#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f_net(double q1, double q2, double r) {
    double k = 8.99 * pow(10, 9);
    return k * q1 * q2 / pow(r, 2);
}

double distance(double dx, double dy) {
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

double f_x(double f_net, double dx, double dy) {
    return f_net * dx / distance(dx, dy);
}

double fy(double f_net, double dx, double dy) {
    return f_net * dy / distance(dx, dy);
}

int main() {
    cout << scientific << setprecision(3);

    double q1, q2, q3, dx2, dy2, dx3, dy3;
    cout << "Enter q1, q2, q3, dx2, dy2, dx3, dy3: " << endl;
    cin >> q1 >> q2 >> q3 >> dx2 >> dy2 >> dx3 >> dy3;

    
    double f_12 = f_net(q1, q2, distance(dx2, dy2));
    double f_13 = f_net(q1, q3, distance(dx3, dy3));

    cout << "f_12 = " << f_12 << " N and f_13 = " << f_13 << " N" << endl;

    double f_12_x = f_x(f_12, dx2, dy2);
    double f_12_y = fy(f_12, dx2, dy2);

    double f_13_x = f_x(f_13, dx3, dy3);
    double f_13_y = fy(f_13, dx3, dy3);

    double f_net_x = -(f_12_x + f_13_x);
    double f_net_y = -(f_12_y + f_13_y);

    cout << "f_net_x = " << f_net_x << " N and f_net_y = " << f_net_y << " N" << endl;

    double f_total = distance(f_net_x, f_net_y);

    cout << f_total << endl;
    cout << sqrt(f_net_x * f_net_x + f_net_y*f_net_y ) << endl;

    return 0;
}