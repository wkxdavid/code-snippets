// This file contains several sample functions and code snippets that we
// explored in lecture.

#include <iostream>

using namespace std;

// this function prints n occurrences of the character ch and has default
// values of 10 and asterisk
void print(int n = 10, char ch = '*') {
    for (int i = 0; i < n; i++) {
        cout << ch;
    }
}

// This function swaps the values of its two parameters.  When we used value
// parameters instead of reference parameters, we could see that the local
// copies were swapped, but it had no effect on the variables passed as a
// parameter.  With reference parameters, it manages to change the values of
// the variables passed to it as parameters.
void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << ", b = " << b << endl;
}

// This function increments two int variables
void inc2(int & a, int & b) {
    a++;
    b++;
}

int main() {
    // we used the following code to explore what happens when the user types
    // illegal values for console input
    int a;
    double b;
    cout << "give me an int and a double: ";
    cin >> a >> b;
    cout << "a = " << a << ", b = " << b << endl << endl;

    // some calls on the print command where we specify both parameters
    print(10, '\\');
    print(10, '/');
    print(10, '*');
    cout << endl << endl;

    // some calls on print that sometimes leave out the second parameter
    // (defaults to '*')
    print(10);
    print(5, '&');
    print(10);
    cout << endl << endl;

    // a call on print that passes no parameters (defaults to 10 '*')
    print();
    cout << endl << endl;

    // some code we wrote to test the swap function
    int x = 13;
    int y = 75;
    cout << "x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "x = " << x << ", y = " << y << endl << endl;

    // some code we wrote to explore the inc2 function
    inc2(x, y);
    cout << "x = " << x << ", y = " << y << endl;
    // in the following version we pass x twice, which led to x being
    // incremented twice, so it went up in value by 2
    inc2(x, x);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}