//
// Created by markd on 07.02.2020.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double z (double j, double n){
    return 2. * cos(M_PI * (2. * j - 1.) / n);
}

double ChebyshevPolynomial(double x, vector<double>& xv, vector<double>& yv , double a, double b) {
    int size = xv.size();
    vector<double> alpha(size,0);
    for(int j = 0; j < size; ++j) {
        vector<double> g(size);
        g[0] = yv[j];
        g[1] = 0.5 * z(j,size) * g[0];
        alpha[0] += g[0];
        alpha[1] += g[1];
        for(int i = 2; i < size; i++) {
            g[i] = z(j,size) * g[i-1] - g[i-2];
            alpha[i] += g[i];
        }
    }
    alpha[0] /= ((double)size);
    for(int i = 1; i < size; ++i){
        alpha[i] *= (2. / ((double)size));
    }

    double res = 0;
    double zFinal = 2 * ( ( 2 * x - (b + a) ) / ( b - a ) );
    vector<double> t(size);
    t[0] = 1;
    t[1] = zFinal / 2;
    res += (alpha[0] * t[0] + alpha[1] * t[1]);
    for(int i = 2; i < size; ++i){
        t[i] = zFinal * t[i-1] - t[i-2];
        res += (alpha[i] * t[i]);
    }
    return res;
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
    double res = ChebyshevPolynomial(x, xv, yv, a, b);
    cout << endl << "Ch(x) = " << res << endl << " R(x) = f(x) - L(x) = " << exp(x) - res;
    return 0;

}

