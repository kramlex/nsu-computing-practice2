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


double GaussByTwoNodes(double a, double b, double (*f)(double)){
    vector<double> t = {-sqrt(1./3), sqrt(1./3)};
    vector<double> h = {1 , 1};
    int n = 2;
    double integral = 0;
    for(int i = 0; i < n; ++i)
        integral += h[i] * f((a+b)/2 + (b-a)/2 * t[i]);
    integral *= (b-a)/2;
    return integral ;
}
double GaussByThreeNodes(double a, double b, double (*f)(double)) {
    vector<double> t = {-sqrt(3./5), 0 , sqrt(3./5) };
    vector<double> h = {5./9 , 8./9 , 5./9};
    int n = 3;
    double integral = 0;
    for(int i = 0; i < n; ++i)
        integral += h[i] * f((a+b)/2 + (b-a)/2 * t[i]);
    integral *= (b-a)/2;
    return integral;
}

double GaussByFiveNodes(double a, double b, double (*f)(double)) {
    vector<double> t = {-0.9061798459 , -0.5384693101, 0 , 0.5384693101 , 0.9061798459};
    vector<double> h = {0.2369268851, 0.4786286705, 0.5688888888, 0.4786286705, 0.2369268851};
    int n = 5;
    double integral = 0;
    for(int i = 0; i < n; ++i)
        integral += h[i] * f((a+b)/2 + (b-a)/2 * t[i]);
    integral *= (b-a)/2;
    return integral;
}

int main(){
    double a; // Левая граница
    double b; // Правая граница

    cout << "Enter the left and right border [a,b]: ";
    cin >> a >> b;


    cout << endl << "Gauss by Two Nodes :" << endl;
    cout << endl << "integral f(x) = " << fixed << setprecision(8) << GaussByTwoNodes(a,b,func) << endl;

    cout << endl << "Gauss by Three Nodes :" << endl;
    cout << endl << "integral f(x) = " << fixed << setprecision(8) << GaussByThreeNodes(a,b,func) << endl;

    cout << endl << "Gauss by Five Nodes :" << endl;
    cout << endl << "integral f(x) = " << fixed << setprecision(8) << GaussByFiveNodes(a,b,func) << endl;

    return 0;
}