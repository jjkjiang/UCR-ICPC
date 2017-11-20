#include <vector>
#include <iostream>

using namespace std;

/*
Patrick is making TOO MUCH MONEY!!! The bitcoin enforcers
now limit Patrick to one purchase and one sale. What is the
max amount of money Patrick makes now?

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

/*
 This problem has several ways to approach it. The naive
 approach but also most natural one is, for each element,
 check the difference between your current one and all the
 ones after it. Keep track of the largest one and return.
 Basically iterate similarly to selection/bubble sort.

 O(n^2) time, O(1) space.

 The real trick is getting a solution in O(n), which is
 the goal. There are multiple approaches, but I will
 discuss the one I believe is most clean and efficient.

 You can note that we have basically two numbers we're
 trying to find. One maximum and one minimum, neither
 of which necessarily are the absolute max or min. We do
 realize, however, that we don't care about every value.

 Let m represent the smallest value so far you've seen for
 some arbitrary index i in the timeline. Let j represent
 the largest value after this index.

 Let's think about how the values to the right matter.
 If there are values to the right that are greater, is
 there any point in checking the values before this
 minimal point? No, because m IS the smallest value
 you've seen thus far. If there was a more optimal value,
 say, k, that is before i, it would have to be lower than
 m to warrant comparing it to j.

 If we find any other minimal values after that, the same
 holds true. For any value available to you, you really
 only want to compare the difference between it and the
 smallest value before it.

 So, keep track of the smallest value you've seen, and use
 that to compare with every value for a difference. Compare
 differences, and return the best.

 O(n) time complexity, O(1) space.
 */


int maxStockMarket(vector<int>& v) {
    int currMin = INT_MAX;
    int bestDiff = 0;

    for (auto i : v) {
        if (i < currMin)
            currMin = i;

        if ((i - currMin) > bestDiff) {
            bestDiff = i - currMin;
        }
    }

    return bestDiff;
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