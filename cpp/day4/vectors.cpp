// This file contains some examples of vector manipulation and more examples
// of string manipulation, this time passing proper parameters using const &
//
// some common vector operations:
//     v.push_back(n)            append n to end of vector
//     v.back()                  return a reference to last value in vector
//     v.pop_back()              remove last item in vector
//     v.empty()                 is v empty?
//     v.size()                  how many elements in v?
//     v[index]                  reference to value at given index
//     ==, !=                    compares all values for equality

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// pre : 0 <= n < 256
// post: returns an 8-character string with the binary representation of n
string binary_8(int n) {
    string result = "";
    for (int i = 0; i < 8; i++) {
	result = static_cast<char>('0' + n % 2) + result;
	n /= 2;
    }
    return result;
}

// pre : bits contains a sequence of bits (the characters 0 and 1)
// post: returns the integer equivalent of the binary representation
int from_binary(const string & bits) {
    int result = 0;
    for (char ch : bits) {
	result = result * 2 + ch - '0';
    }
    return result;
}

// post: prints the contents of v to cout as a comma-separated, bracketed, list
void print(const vector<int> & v) {
    cout << "[";
    if (v.size() > 0) {
        cout << v[0];
        for (int i = 1; i < v.size(); i++) {
            cout << ", " << v[i];
        }
    }
    cout << "]";
}

// pre : bits contains a sequence of bits (the characters 0 and 1)
// post: the individual bits are appended to the end of the given vector
void to_vector(vector<int> & digits, const string & bits) {
    for (char ch : bits) {
        digits.push_back(ch - '0');
    }
}

// pre : digits contains a sequence of bits (the values 0 and 1)
// post: returns a string representation of the bits
string bits_to_string(const vector<int> & v) {
    string result = "";
    for (int n : v) {
        result += static_cast<char>(n + '0');
    }
    return result;
}

// post: doubles all values in the given vector
void double_all(vector<int> & v) {
    for (int & n : v) {
        n *= 2;
    }
}

int main() {
    // examples of vector construction
    vector<int> v1;                          // constructs an empty vector
    vector<int> primes = {2, 3, 5, 7, 11};   // constructs vector with values
    vector<int> v2 = primes;                 // independent copy of primes
    vector<string> v3 = {"hi", "there"};     // vector of string values

    vector<int> v4(10, 42);           // constructs a vector with 10 42s
    vector<int> v5(20);               // constructs a vector of 20 0s
    vector<string> v6(10, "hello");   // constructs a vector of 10 "hello"s
    vector<string> v7(5);             // constructs a vector of 5 empty strings

    print(primes);
    cout << endl;
    cout << endl;
    
    string bits = binary_8(209);
    cout << bits << endl;
    cout << from_binary(bits) << endl;
    to_vector(v1, bits);
    print(v1);
    cout << endl;
    cout << endl;

    string bits2 = bits_to_string(v1);
    cout << bits2 << endl;
    cout << endl;

    print(primes);
    cout << endl;
    double_all(primes);
    print(primes);
    cout << endl;

    return 0;
}