#include <vector>
#include <iostream>

using namespace std;

/*
Patrick is an investor in the bitcoin market. He also happens to be
a time wizard, and has a theoretically limitless amount of funds to
start with. He travels n hours into the future, and obtains a list
of all bitcoin prices from the time he departed to the time he arrived.
Unfortunately, he can only do this once.

The bitcoin police is aware of his nonsense and limits him having only one
whole bitcoin at any given time.

He wants to maximize his profit. What is the most money he can make?

Note that an O(n^2) solution will not give Patrick enough time to work with to begin trading

Example:

V: 1 2 3 4 5 6
Out: 5
Patrick buys at hour 1, sells at hour 6.

V: 1 2 4 5 3 4 3 4
Out: 6
Patrick buys at hour 1, sells at hour 4, buys on hour 5, sells on hour 6,
buys on hour 7, sells on hour 8.

V: 5 4 3 2 1
Out: 0
Patrick is smart enough to not buy at any point because there is no profit.

V: 10 2 3 4 5 3 4 9
Out: 9
Patrick buys at hour 2, sells at hour 5, buys at hour 6, sells on the
final hour
*/

/*
 * So its basically always optimal to buy at local minimums and sell at local maximums.
 * The below code does essentially do that.
 */

int maxStockMarket(vector<int>& v) {
    // im lazy, basically this http://www.geeksforgeeks.org/stock-buy-sell/
}

int main() {
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        int size, temp;
        vector<int> v;

        cin >> size;

        for (int j = 0; j < size; j++) {
            cin >> temp;
            v.push_back(temp);
        }

        cout << maxStockMarket(v) << endl;
    }
}