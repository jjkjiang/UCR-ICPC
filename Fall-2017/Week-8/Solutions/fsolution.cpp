#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <math.h>

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

int descending(int num) {
    multiset<int> temp;
    int result = 0;

    for (int i = 0; i < 5; i++) {
        temp.insert(num % 10);
        num /= 10;
    }

    int cntr = 0;
    for (auto i : temp) {
        result += i * pow(10, cntr);
        cntr++;
    }

    return result;
}

int ascending(int num) {
    multiset<int> temp;
    int result = 0;

    for (int i = 0; i < 5; i++) {
        temp.insert(num % 10);
        num /= 10;
    }

    int cntr = 4;
    for (auto i : temp) {
        result += i * pow(10, cntr);
        cntr--;
    }

    return result;
}

/*
 * The brute force solution is simple. Y-X, 1000000 times.
 * Clearly in a programming contest, or in an interview,
 * that is basically unacceptable, especially when there
 * are multiple test cases to process in a single trial.
 *
 * One might believe that there is a mathematical solution to
 * this problem. There might be, but it's not needed!
 *
 * The efficient solution to this problem is very interesting -
 * we notice if we calculate the values, we end up with
 * sequences of numbers that are essentially cycles. The
 * solution then is to simply isolate this cycle, find its
 * length, and then modulus your goal from the remaining iterations.
 *
 * A possible algorithm that can be relevant here is the
 * floyd cycle finding algorithm, but alas we are creating the
 * graph as we go, so a map-like structure is unavoidable.
 *
 * You end up with basically an O(1) time and O(1) space algorithm
 * regardless - the highest distance number to reach a complete cycle
 * can be computed by running this algorithm for all possible numbers.
 * You will find that it is a (fairly small) constant number.
 */

int kaprekar999999(int num) {
    int iter = 999999;
    int cycleL = 0;
    // find cycle
    unordered_map<int, int> kapremap;

    int nextNum = num;

    while (kapremap.find(nextNum) == kapremap.end()) {
        //cout << nextNum << endl;
        kapremap.insert(pair<int,int>(nextNum, cycleL));
        iter--;
        cycleL++;

        nextNum = descending(nextNum) - ascending(nextNum);
    }

    int extraIter = iter % (cycleL - kapremap.find(num)->second);

    for (int i = 0; i < extraIter; i++) {
        nextNum = descending(nextNum) - ascending(nextNum);
    }

    return nextNum;
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