//
// Created by markd on 20.02.2020.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
    return sqrt(1-x*x*x);
}

double GaussByTwoNodes(double a, double b, double n, double (*f)(double)){
    const double width = (b-a)/n;

    double integral = 0;
    for(int step = 0; step < n; ++step) {
        double x1 = a + step*width;
        double x2 = a + (step+1)*width;

        integral += (x2-x1)/2 * ( f( (x1+x2)/2 - (x2-x1) / (2*sqrt(3.)) ) + f( (x1+x2)/2 + (x2-x1) / (2 * sqrt(3.)) ) );
    }
    return integral ;
}
double GaussByThreeNodes(double a, double b, double n, double (*f)(double)) {
    const double width = (b-a)/n;

    double integral = 0;
    for(int step = 0; step < n; ++step) {
        double x1 = a + step*width;
        double x2 = a + (step+1)*width;

        integral += (x2 - x1) / 10 * ( 5./9 * f( (x1+x2)/2 - (x2-x1)/2 * sqrt(3./5) )  + 8.9 * f((x1+x2)/2) +
                5./9 * f( (x1+x2)/2 - (x2 - x1)/2 * sqrt(3./5) ));
    }
    return integral;
}

int main(){
    int n; // Кол-во отрезков дробления
    double a; // Левая граница
    double b; // Правая граница

    cout << "Enter the left and right border [a,b]: ";
    cin >> a >> b;


    cout << endl << "Gauss by Two Nodes :" << endl;
    cout << endl << "n = 20  :  integral f(x) = " << fixed << setprecision(8) << GaussByTwoNodes(a,b,20,func) << endl;
    cout << endl << "n = 50  :  integral f(x) = " << fixed << setprecision(8) << GaussByTwoNodes(a,b,50,func) << endl;
    cout << endl << "n = 100  :  integral f(x) = " << fixed << setprecision(8) << GaussByTwoNodes(a,b,100,func) << endl;

    cout << endl << "Gauss by Three Nodes :" << endl;
    cout << endl << "n = 20  :  integral f(x) = " << fixed << setprecision(8) << GaussByThreeNodes(a,b,20,func) << endl;
    cout << endl << "n = 50  :  integral f(x) = " << fixed << setprecision(8) << GaussByThreeNodes(a,b,50,func) << endl;
    cout << endl << "n = 100  :  integral f(x) = " << fixed << setprecision(8) << GaussByThreeNodes(a,b,10000,func) << endl;
    return 0;
}