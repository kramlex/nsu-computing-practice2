//
// Created by markd on 06.02.2020.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Общее число операций n^2 + O(n)
double LagrangePolynomial(double x, vector<double>& xv, vector<double>& yv) {
    int size = xv.size();
    double sum = 0; // Результат
    for(int i = 0; i < size; i++){
        double multi = 1; // Произведение П (x-xj)/(xi-xj)
        for(int j = 0; j < size; j++){
            if(i != j) multi *= (x - xv[j])/(xv[i]-xv[j]);
        }
        sum += yv[i] * multi;
    }
    return sum;
}

int main() {
    int n; // Кол-во узлов интерполяции
    double a; // Левая граница
    double b; // Правая граница
    vector<double> xv;
    vector<double> yv;
    double data;

    cout << "Enter the number of interpolation nodes: ";
    cin >> n;
    cout << "Enter the left and right border [a,b]: ";
    cin >> a >> b;


    cout << endl << "Enter n pairs (x,y):" << endl;
    for(int i = 0; i < n*2; ){
        cin >> data;
        i++ % 2 ? yv.push_back(data) : xv.push_back(data);
    }

    double x;
    cout << endl << "Enter the point x where you want to find the value of the Lagrange polynomial: ";
    cin >> x;
    double res = LagrangePolynomial(x, xv, yv);
    cout << endl << fixed << setprecision(8) << "L(x) = " << res << endl << " R(x) = f(x) - L(x) = " << exp(x) - res;
    return 0;
}