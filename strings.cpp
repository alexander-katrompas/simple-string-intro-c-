/*
 * This is a quick and dirty program to demonstrate C-style strings,
 * C++ strings, and passing by reference. DO NOT write programs like
 * this! This does not use proper header files or loose coupling.
 */

#include <iostream> // this is a c++ library
#include <string> // this is a c++ library

using std::cout;
using std::endl;
using std::string;

// never use literals in your code, make defines and constants and use them
#define BUFFER 32
#define ALPHABETSIZE 26
// we use some literals below for demonstration purposes, DO NOT DO THIS!

/*
 * This function will take a character array and fill it with 'x'
 * and also make that into a string by adding a null terminator
 * Notice there is no return. Arrays pass by reference. So the
 * original passed array IS affected by this function.
 */
void process_c_string(char *str, const int SIZE){
    for (int i = 0; i < SIZE-1; i++) {
        str[i] = 'x';
    }
    str[SIZE-1] = '\0';
}

/*
 * this accepts a C++ string object and it passes by value
 * so you can use the string in the function but you CANNOT
 * affect the original passed string.
 * this is very inefficient
 */
void process_cpp_string1(string str){
    // this line does NOT affect the original passed string
    str = "hello world";
}

/*
 * this accepts a C++ string object POINTER so it passes by reference
 * so you can BOTH use the string in the function and you CAN
 * affect the original passed string.
 * this is very efficient, but dangerous
 */
void process_cpp_string2(string *str){
    // this line DOES affect the original passed string
    *str = "hello world";
}


int main() {
    
    // this declares a character array
    // it is NOT a string, but it can hold a string
    char mystring1[BUFFER];

    // this declares a C++ string object
    // it is NOT a string, it is an object, that holds a string
    string mystring2;

    // print the alphabet, demonstrating using chars as ints
    cout << "'Printing the alphabet using chars as control variables..." << endl;
    for (int i = 'a'; i < 'a' + ('z' - 'a' + 1); i++) {
        cout << (char)i;
    }
    cout << endl << endl;

    // put the alphabet in a character array
    for (int i = 0; i < ALPHABETSIZE; i++) {
        mystring1[i] = i + 'a';
    }
    // this is not a string yet! You cannot print it or use it as such

    mystring1[ALPHABETSIZE] = '\0';
    // now it's a string
    cout << "Printing mystring1 after putting the alphabet in it..." << endl;
    cout << mystring1 << endl << endl;

    // put the alphabet in a c++ string
    cout << "Printing mystring2 after putting the alphabet in it..." << endl;
    mystring2 = "abcdefghijklmnopqrstuvwxyz";
    cout << mystring2 << endl << endl;
    
    // pass the C-style string to a function and do something to it.
    // notice the original string is affected outside the function because
    // it was passed by reference
    process_c_string(mystring1, BUFFER);
    cout << "Printing mystring1 after passing it by reference..." << endl;
    cout << mystring1 << endl << endl;
    
    // pass the C++ string to a function. this will NOT affect the original string
    // this is a pass by value. you shouldn't do this, it's very inefficient.
    cout << "Printing mystring2 before passing it by value..." << endl;
    cout << mystring2 << endl << endl;
    process_cpp_string1(mystring2);
    cout << "Printing mystring2 after passing it by value..." << endl;
    cout << mystring2 << endl << endl;
    
    // pass the C++ string to a function. this WILL affect the original string
    // this is a pass by reference. it is very efficient, but dangerous (in this form)
    // because the function can modify the string object.
    cout << "Printing mystring2 before passing it by reference..." << endl;
    cout << mystring2 << endl << endl;
    process_cpp_string2(&mystring2);
    cout << "Printing mystring2 after passing it by reference..." << endl;
    cout << mystring2 << endl << endl;
    

    return 0;
}

