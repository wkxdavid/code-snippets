// This file contains some examples of string manipulation.  The use of a value
// parameter for the strings is inefficient.
//
// some common string operations:
//     output << str;              insert str onto output stream
//     input >> str;               extract str from input stream (one token)
//     getline(input, str)         read into str one line from input
//     str.empty()                 is str empty?
//     str.size()                  how many characters in str?
//     str[index]                  reference to character at given index
//     str1 + str2                 result of adding two strings (a new string)
//     ==, !=, <, >, <=, >=        relational operators to compare two strings
//     istringstream input(str)    make an input stream from the given string
//     str.substr(index, n)        string of n characters starting at index
//     str.substr(index)           string of characters starting at index
//     str.find(str2)              first occurrence of str2 in str or -1
//     str.rfind(str2)             last occurrence of str2 in str or -1

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// takes a string of the form "last name, first name" and returns a string in
// the form "first name last name"
string rearrange(string text) {
    int index = text.find(", ");
    return text.substr(index + 2) + " " + text.substr(0, index);
}

// returns the result of collapsing whitespace in a string so that tokens are
// separated by single spaces
string fix(string s) {
    istringstream input(s);
    string result;
    string word;
    if (input >> word) {
        result = word;
        while (input >> word) {
            result += " " + word;
        }
    }
    return result;
}

int main() {
    // examples of string construction
    string s1 = "hello";   // copies the C-style string into s1
    string s2 = s1;        // s2 is an independent copy of s1
    string s3(20, '*');    // s3 is set to 20 occurrences of '*'
    string s4;             // s4 is set to an empty string
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl << endl;

    string name = "Reges, Stuart T.";
    string name2 = rearrange(name);
    cout << name << " => '" << name2 << "'" << endl << endl;

    // example of setting every other character to an asterisk
    for (int i = 0; i < name2.size(); i += 2) {
        name2[i] = '*';
    }
    cout << "changed name = " << name2 << endl << endl;

    string line;
    cout << "line to fix: ";
    getline(cin, line);
    string fixed = fix(line);
    cout << "fixed line is '" << fixed << "'" << endl;

    return 0;
}