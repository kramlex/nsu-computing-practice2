//
// Created by markd on 21.02.2020.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double delta = 1e-10;
const double eps = 1e-8;

double derivative(double x, double (*f)(double)){
    return (f(x+delta)-f(x))/delta;
}

double func(double x) {
    return x*x - sin(x) - 1;
}

pair<double, int> Newton(double x_start, double (*f)(double)){
    double x1 = x_start;
    double x2 = x1 - f(x1) / derivative(x1,f);
    int counter = 0;
    while(fabs(x2 - x1) > eps){
        x1 = x2;
        x2 = x1 - f(x1) / derivative(x1,f);
        counter++;
    }
    return {x2,counter};
}


int main() {
    pair<double, int> pair1 = Newton(-1.5, func);
    pair<double, int> pair2 = Newton(0.5, func);
    cout << fixed << setprecision(8) <<
            "x_start = -1.5"  << "   root 1 = " << pair1.first << "   count operation = " << pair1.second <<endl <<
            "x_start = 0.5"<< "   root 2 = " << pair2.first << "   count operation = " << pair2.second;
    return 0;
}