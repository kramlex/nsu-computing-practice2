//
// Created by markd on 07.02.2020.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
    return log10(x);
}

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

double NewtonPolynomial(double x, vector<double>& xv, vector<double>& yv) {
    int size = xv.size();
    double res = yv[0], delta, multi;
    for(int i = 1; i < size; ++i){
        delta = 0;
        for(int j = 0; j <= i; ++j) {
            multi = 1;
            for(int k = 0; k<=i; ++k){
                if (k != j) multi *= (xv[j]-xv[k]);
            }
            delta += yv[j] / multi; // разделенная разность
        }
        for(int k = 0; k < i; ++k)
            delta *= (x-xv[k]);
        res+=delta;//полином
    }
    return res;
}

double Chebyshev(double n, double a, double b, double (*InterpolatePolynomial)(double, vector<double>&, vector<double>&),
                double (*InterpolateFunction)(double) , double x){
    vector<double> xC(n);
    vector<double> yC(n);
    cout << endl;
    for(int i = 0; i < n; ++i){
        xC[i] = 0.5 * (a + b) + 0.5 * (b - a) * cos(M_PI * ((i+1) * 2 - 1) / (2 * n));
        yC[i] = InterpolateFunction(xC[i]);
        cout << " (" <<xC[i] << ", " << yC[i] << ") ";
    }
    cout << endl;
    return InterpolatePolynomial(x, xC, yC);

}

int main() {

    int n; // Кол-во узлов интерполяции
    double a; // Левая граница
    double b; // Правая граница
    vector<double> xv;
    vector<double> yv;

    cout << "Enter the number of interpolation nodes: ";
    cin >> n;
    cout << "Enter the left and right border [a,b]: ";
    cin >> a >> b;

    double x;
    cout << endl << "Enter the point x where you want to find the value of the Lagrange polynomial: ";
    cin >> x;
    double res = Chebyshev(n, a, b, NewtonPolynomial, func, x);
    cout << endl << fixed << setprecision(8) << "Ch(x) = " << res << endl << " R(x) = f(x) - L(x) = " << log10(x) - res;
    return 0;

}

