#include <vector>
#include <iostream>

using namespace std;

/*
Patrick is making TOO MUCH MONEY!!! The bitcoin enforcers
now limit Patrick to one purchase and one sale. What is the
max amount of money Patrick makes now?

Note that an O(n^2) solution will not give Patrick enough time to work with to begin trading.

Example:

V: 1 2 3 4 5 6
Out: 5
Patrick buys at hour 1, sells at hour 6.

V: 1 2 4 5 3 4 3 4
Out: 4
Patrick buys at hour 1, sells at hour 4.

V: 5 4 3 2 1
Out: 0
Patrick doesn't buy any bitcoins.

V: 10 2 3 4 5 3 4 9
Out: 7
Patrick buys at hour 2, sells on the final hour.
*/

int maxStockMarket(vector<int>& v) {
    //code here
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