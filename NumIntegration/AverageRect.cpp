//
// Created by markd on 13.02.2020.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Подинтегральная функция
double func(double x) {
    return exp(-0.1 / x);
}

double AverageRectangle(double a, double b, double n, double (*f)(double)){
    const double width = (b-a)/n;

    double integral = 0;
    for(int step = 0; step < n; ++step) {
        double x1 = a + step*width;
        double x2 = a + (step+1)*width;

        integral += f((x1 + x2) * 0.5) * (x2 - x1);
    }
    return integral;
}

int main(){
    int n; // Кол-во отрезков дробления
    double a; // Левая граница
    double b; // Правая граница

    cout << "Enter the number of segments: ";
    cin >> n;
    cout << "Enter the left and right border [a,b]: ";
    cin >> a >> b;

    cout << endl  << "Integral f(x) from " << a << " to " << b << " = " << fixed << setprecision(8) << AverageRectangle(a, b, n, func);
    return 0;
}
