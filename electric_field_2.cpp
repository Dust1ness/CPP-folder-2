#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const double k = 8.99 * pow(10, 9); // Coulomb constant
const double E0 = 8.85 * pow(10, -12);

// common functions
double distance(double dx, double dy){
    return sqrt(dx*dx + dy*dy);
}

class pointCharge{ // or sphere charge
    public:
        pointCharge(double x, double y, double q){
            this->x = x;
            this->y = y;
            this->q = q;
        }

        double E_x(){
            return (x / distance(x, y)) * k * q / pow(distance(x, y), 2);
        }

        double E_y(){
            return (y / distance(x, y)) * k * q / pow(distance(x, y), 2);
        }
    private:
        double x = 0;
        double y = 0;
        double q = 0;
        
};

class infinityLine{
    public:
        infinityLine(double x, double y, double lambda){ 
            // closest x and y point from origin
            this->x = x;
            this->y = y;
            this->lambda = lambda;
        }

        double r = x * y / distance(x, y);

        double E(){
            return k * 2 * lambda / r;
        }

    private:
        double x = 0;
        double y = 0;
        double lambda = 0;
};


int main (){
    cout << scientific << setprecision(4);








    return 0;
}