#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate the Euclidean distance
double distance(double dx, double dy) {
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

// Function to calculate the electric field magnitude
double electric_field(double q, double r) {
    double k = 8.99 * pow(10, 9); // Coulomb constant
    return k * q / pow(r, 2);
}

// Functions to calculate electric field components
double electric_field_x(double q, double r, double dx, double dy) {
    return electric_field(q, r) * (dx / distance(dx, dy));
}

double electric_field_y(double q, double r, double dx, double dy) {
    return electric_field(q, r) * (dy / distance(dx, dy));
}


void sum_of_three_charge(double q1, double q2, double q3, double dx1, double dy1, double dx2, double dy2, double dx3, double dy3) {
    // master module electric field 1 level 2 question 3
    cout << scientific << setprecision(3);

    // Calculate the total electric field at the origin
    double net_e_x = electric_field_x(q1, distance(dx1, dy1), dx1, dy1)
                   + electric_field_x(q2, distance(dx2, dy2), dx2, dy2)
                   + electric_field_x(q3, distance(dx3, dy3), dx3, dy3);
    double net_e_y = electric_field_y(q1, distance(dx1, dy1), dx1, dy1)
                   + electric_field_y(q2, distance(dx2, dy2), dx2, dy2)
                   + electric_field_y(q3, distance(dx3, dy3), dx3, dy3);
    double net_e = distance(net_e_x, net_e_y);

    // Output results
    cout << "The total electric field at the origin is: " << net_e << " N/C" << endl;
    cout << "The x-component of the electric field at the origin is: " << net_e_x << " N/C" << endl;
    cout << "The y-component of the electric field at the origin is: " << net_e_y << " N/C" << endl;

    // Calculate and output the direction in degrees
    cout << fixed << setprecision(3);
    cout << "The direction of the electric field is: " << atan2(net_e_y, net_e_x) * 180 / M_PI << " degrees" << endl;
}

