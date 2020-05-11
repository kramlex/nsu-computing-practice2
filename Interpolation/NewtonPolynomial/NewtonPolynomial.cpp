//
// Created by markd on 06.02.2020.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

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

int main(){
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
    cout << endl << "Enter the point x where you want to find the value of the Newton polynomial: ";
    cin >> x;
    double res = NewtonPolynomial(x, xv, yv);
    cout << endl <<fixed << setprecision(8) << "N(x) = " << res << endl << " R(x) = f(x) - L(x) = " << log10(x) - res;
    return 0;


}
