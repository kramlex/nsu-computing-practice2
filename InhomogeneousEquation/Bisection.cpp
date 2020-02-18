//
// Created by markd on 13.02.2020.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;
const double eps = 1e-8;

double func(double x) {
    //...
}

double FindRoot(double a, double b) {
    while (b-a > eps) {
        if (f(a) * f((b + a) / 2) == 0) break;
        else if (f(a) * f((b + a) / 2) > 0)
            a = (b+a) / 2;
        else
            b = (b+a) / 2;
    }
    return (b+a) / 2;
}

int main(){
    string s;
    double a, b, root;
    while(true){
        cout << "Your action: ";
        cin >> s;
        if(s == "Stop") break;
        if(s == "Find"){
            cout << "Enter the left and right border [a,b]: ";
            cin >> a >> b;
            cout << "Root in the range from " << a << " to " << b << " = " << FindRoot(a,b);
        }
    }
    return 0;
}
