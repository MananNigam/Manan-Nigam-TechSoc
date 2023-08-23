#include <iostream>
using namespace std;

int add(int a, int b){ return a+b; }

int sub(int a, int b){ return a-b; }

int prod(int a, int b){ return a*b; }

double divide(int a, int b){ return a/b; }

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
        result *= base;
    return result;
}

double factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

double inDomain(double angle){
    double twoPi = 2 * 3.141592865358979;
    while (angle > twoPi){
        angle -= - twoPi;
    }
    while (angle < 0){
        angle += twoPi;
    }
    return angle;    
}

double sin(double x) {
    double result = 0.0;
    for (int n = 0; n < 15; ++n) {
        result += power(-1, n) * power(x, 2 * n + 1) / factorial(2 * n + 1);
    }
    return result;
}

double cos(double x) {
    double result = 0.0;
    for (int n = 0; n < 15; ++n) {
        result += power(-1, n) * power(x, 2 * n) / factorial(2 * n);
    }
    return result;
}

double trigo(double angle, int trig){
    angle = inDomain(angle);
    if (trig == 1){
        return sin(angle);
    }
    if (trig == 2){
        return cos(angle);
    }
    if (trig == 3){
        return sin(angle) / cos(angle);
    }
}

int main() {
    int operation;
    int a, b;

    cout << "Enter 1 to add, 2 to subtract, 3 to multiply, 4 to divide, 5 for exponentiation, 6 for trigonometric functions: ";
    cin >> operation;

    switch (operation){
    case 1:
        cout << "Enter 1st number: ";
        cin >> a;
        cout << "Enter 2nd number: ";
        cin >> b;
        cout << add(a, b);
        break;

    case 2:
        cout << "Enter 1st number: ";
        cin >> a;
        cout << "Enter 2nd number: ";
        cin >> b;
        cout << sub(a, b);
        break;

    case 3:
        cout << "Enter 1st number: ";
        cin >> a;
        cout << "Enter 2nd number: ";
        cin >> b;
        cout << prod(a, b);
        break;

    case 4:
        cout << "Enter 1st number: ";
        cin >> a;
        cout << "Enter 2nd number: ";
        cin >> b;
        cout << divide(a, b);
        break;
    
    case 5:
        cout << "Enter the base: ";
        cin >> a;
        cout << "Enter the power: ";
        cin >> b;
        cout << power(a, b);
        break;

    case 6:
        int trig;
        double angle;

        cout << "Enter 1 for sine, 2 for cosine, 3 for tangent: ";
        cin >> trig;
        cout << "Enter angle: ";
        cin >> angle;
        cout << trigo(angle, trig);
        break;

    default:
        cout << "Wrong input.";
        break;
    }
    return 0;
}
