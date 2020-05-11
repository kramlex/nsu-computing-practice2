//
// Created by markd on 13.02.2020.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const double eps1 = 0.0000001;
const double eps2 = 0.000000001;

double func(double x) {
    return x*x - sin(x) - 1;
}
int counter = 0;
double FindRoot(double a, double b , double (*f)(double)) {
    while (b-a > eps2) {
        counter++;
        if (f(a) * f((b + a) / 2) == 0) break;
        else if (f(a) * f((b + a) / 2) > 0)
            a = (b+a) / 2;
        else
            b = (b+a) / 2;
    }
    return (b+a) / 2;
}

int main(){
    cout << fixed << setprecision(8);
    counter = 0;
    cout << "root 1 = " << FindRoot(-2, 0, func) << endl;
    cout << endl << counter << endl;
    counter = 0;
    cout << "root 2 = " << FindRoot(1, 2, func);
    cout << endl << counter;
    return 0;
}
