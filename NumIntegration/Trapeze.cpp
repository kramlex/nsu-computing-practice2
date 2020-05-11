//
// Created by markd on 13.02.2020.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Подинтегральная функция
double func(double x) {
    return sqrt(1-x*x*x);
}

double Trapeze(double a, double b, double n, double (*f)(double)){
    const double width = (b-a)/n;

    double integral = 0;
    for(int step = 0; step < n; ++step) {
        double x1 = a + step*width;
        double x2 = a + (step+1)*width;

        integral += 0.5 * (x2-x1) * (f(x1) + f(x2));
    }
    return integral;
}

int main(){
    int n; // Кол-во отрезков дробления
    double a; // Левая граница
    double b; // Правая граница

    cout << "Enter the left and right border [a,b]: ";
    cin >> a >> b;

    cout << endl  << "n = 20 " << fixed << setprecision(8) << Trapeze(a, b, 20, func);
    cout << endl  << "n = 50 " << fixed << setprecision(8) << Trapeze(a, b, 50, func);
    cout << endl  << "n = 100 " << fixed << setprecision(8) << Trapeze(a, b, 100, func);
    return 0;
}
