#include <vector>
#include <iostream>

using namespace std;

/*
CS 14 recommended

Jeff Coughlin, a NASA scientist, recently stated that one of the most earth-like
planets out there right now is KOI-7923.0. The temperature of this planet is warm
enough such that liquid water can stay liquid.

We travel several hundred years into the future, and NASA is now colonizing this
planet. As part of the space program, they send a terraformer designed to create
an atmosphere with oxygen, wildlife, and an ocean with water.

It's now time to land the first colonists. There's just one problem. NASA made a
bit too much ocean, and now the planet is entirely islands. They take some n x n
images from space showing the planet in this kind of format:

0000000000
0000000000
0000111000
0000010000
0000000000
0000010000
0000001000
0000000000
0010000000
0011110000

0 represents ocean water, while 1 represents land. NASA wants to figure out
how many islands there are so they can create separate cities, and make
different landing craft for each one. They define islands as a landmass
surrounded by water in all cardinal directions.

That's where you come in. Tell NASA how many islands are in each picture.

Example:
1
10
0000000000
0000000000
0000111000
0000010000
0000000000
0000010000
0000001000
0000001100
0010000000
0011110000

This is the same photograph from the example. We have 4 islands, which are

111
1

1

1
11

1
1111

Two of the islands has a diagonal neighbor but they each are surrounded
by water on all 4 cardinal sides, so they are unique islands.

So, we output 4.
*/


int numIslands(vector<vector<int> >& photo) {
    // code here
}

int main() {
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        int size, temp;
        cin >> size;
        vector<vector<int> > photo(size, vector<int>(size, 0));
        cin.ignore();
        for (int j = 0; j < size; j++) {
            string value;
            getline(cin, value);
            for (int k = 0; k < size; k++) {
                photo[j][k] = value.at(k) - 48;
            }
        }

        cout << numIslands(photo) << endl;
    }

}