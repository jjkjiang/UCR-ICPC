#include <iostream>

using namespace std;

/*

CS 14 RECOMMENDED

The Indian mathematician Kaprekar is famous in the world of mathematics for
many things - one of which is his constant, 6174. Consider the following rules:

Take any number, where at least two digits are different values. Repeat
the following operations however many times you want.

1. Order the digits in descending order to obtain X.
2. Order the digits in ascending order to obtain Y.
3. Your new number is X - Y.

For the sequence of 3 digit numbers, the result after some runs is 495. For 4
digit numbers, it is the constant - 6174.

You are a student doing research under a professor who is the great-great-great
-great-great-great-great-great-great-great-great-great-great-great-great-great-
great-great-great-great-great-great-great-great-great-great-great-great grandson
of Kaprekar and is interested in these constants. He wants to find the constant
for a 5 digit number.

It turns out, the 5 digit case is very special. He therefore wants you to write
a program to print the number resulting from 999,999 trials of this method.

Note that he might ask for a large amount of queries as part of his research, and
expect them quickly.

Example:
3
87433
53955
63954

For the first number, let us try the formula.
87433 - 33478 = 53955
95553 - 35559 = 59994
99954 - 45999 = 53955
.............
53955
*/

int kaprekar999999(int num) {

}


int main() {
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        int num;
        cin >> num;

        cout << kaprekar999999(num) << endl;

    }

    return 0;
}