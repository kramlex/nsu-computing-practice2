//
// Created by markd on 21.02.2020.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double delta = 0.000000001;
const double eps = 0.000000001;

double derivative(double x, double (*f)(double)){
    return (f(x+delta)-f(x))/delta;
}

double func(double x) {
    return x*x*x - x;
}

pair<double, int> Newton(double x_start, double (*f)(double)){
    double x1 = x_start;
    double x2 = x1 - f(x1) / derivative(x1,f);
    int counter = 0;
    cout << "x[0] = " << x1 << endl;
    while(fabs(x2 - x1) > eps){
        x1 = x2;
        x2 = x1 - f(x1) / derivative(x1,f);
//        cout << x2-x1 << endl;
        cout << counter+1 << ")   " << "x[" << counter+1<< "] = " << x2 << endl;
        cout <<  "        x[" << counter+1 << "]-x[" << counter << "]=" << x2-x1<< endl;
        counter++;
    }
    return {x2,counter};
}


int main() {
    double x1 = 1;
    double x2 = 1;
    cout << delta << endl;
    pair<double,int> pair1 = Newton(1/sqrt(5), func);
    cout << fixed << setprecision(8) << pair1.first;
//    pair<double, int> pair1 = Newton(x1, func);
//    pair<double, int> pair2 = Newton(x2, func);
//    for(double i = 0; i < 1; i+=0.005){
//        cout << i << ":               " << fixed << setprecision(8) << Newton(i,func).first << endl;
//    }
    /*
    cout << fixed << setprecision(8) <<
            "x_start = "<< x1 << "   root 1 = " << pair1.first << "   count operation = " << pair1.second <<endl <<
            "x_start = "<< x2 <<  "   root 2 = " << pair2.first << "   count operation = " << pair2.second;
    */
    return 0;
}