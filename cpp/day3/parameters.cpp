// This program contains some functions that we discussed.  The first is a
// classic "parameter mystery."  f2 is an ordinary function, but f3 doesn't
// initializer its variables and yet ends up getting the values from f2
// (maybe).  We experimented with various versions of f4 with calls in main
// that involved f4(n)++.

#include <iostream>

using namespace std;

void f1(int& a, int b) {
    a += 3;
    b *= 2;
    cout << a << " " << b << endl;
}

void f2() {
    int x;
    double y;
    x = 15;
    y = 38.9;
    cout << x << endl;
    cout << y << endl;
}

void f3() {
    int a;
    double b;
    cout << a << endl;
    cout << b << endl;
}

int f4(int n) {
    n *= 2;
    return n;
}

int main() {
    int x = 3;
    int y = 4;
    cout << x << " " << y << endl;
    f1(x, y);
    cout << x << " " << y << endl;
    f1(y, x);
    cout << x << " " << y << endl;
    f1(x, x);
    cout << x << " " << y << endl;
    cout << endl;

    f2();
    f3();
    cout << endl;

    cout << "x = " << x << endl;
    cout << f4(x) << endl;
    cout << "x = " << x << endl;

    return 0;
}