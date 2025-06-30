/*
    This program contains some sample code to demonstrate basic C++ usage that
    is either identical to or similar to how it would be written in Java.

    Java                          C++
    ---------------------------------------------------------------------
    int, double, char             same
    boolean                       bool (also 0 is false, nonzero is true)
    x = y                         x = y    or x {y}    or x = {y}
    if/else statements            same
    for loops                     same
    while loops                   same
    static methods                functions
    define methods in any order   use function prototypes
    System.out.print(...)         cout << ...;
    System.out.println(...)       cout << ... << endl;
    console Scanner (System.in)   cin >> ...;
    import java.util.*;           #include <iostream>, using namespace std;
*/

#include <iostream>
#include <cmath>

using namespace std;  // allows us to say things like cout instead of std::cout

bool isprime(int);    // function prototype with actual function after main

int main() {
    cout << "Hello world!" << endl << endl;
    
    for (int i = 1; i <= 10; i++) {
        cout << i << "-squared = " << i * i << endl;
    }
    cout << endl;

    cout << "give me a number to show factors of 2: ";
    int n;
    cin >> n;
    cout << n << " = ";
    while (n % 2 == 0) {
        cout << "2 * ";
        n /= 2;
    }
    cout << n << endl << endl;

    cout << "give me two ints to compute an exponent: ";
    int x, y;
    cin >> x >> y;
    cout << x << "^" << y << " = " << pow(x, y) << endl << endl;

    cout << "what max for prime check? ";
    int max;
    cin >> max;
    cout << "primes up to " << max << ":";
    for (int i = 2; i <= max; i++) {
        if (isprime(i)) {
            cout << " " << i;
        }
    }
    cout << endl;
}

bool isprime(int n) {
    int max = sqrt(n);
    for (int i = 2; i <= max; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}