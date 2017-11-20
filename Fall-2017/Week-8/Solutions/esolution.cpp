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

void dfs(vector<vector<bool> >& visited, vector<vector<int> >& photo, int x, int y) {
    // out of bounds
    if (x < 0 || x >= photo.size() ||
            y < 0 || y >= photo.size())
        return;

    // ocean
    if (photo[x][y] == 0)
        return;

    // visited
    if (visited[x][y] == true)
        return;

    visited[x][y] = true;
    dfs(visited, photo, x+1, y);
    dfs(visited, photo, x-1, y);
    dfs(visited, photo, x, y+1);
    dfs(visited, photo, x, y-1);
}

/*
  This type of problem is the kind you want to think in terms of graphs for.
  Each piece of land could be thought of as a node, and its edges are the 4 elements
  around it. An element of 0 could be thought of essentially as a null pointer.

  We then can simply call the search of our choice, and keep track of nodes we've
  explored to avoid extra work.

  This algorithm's worst case is O(n^2) time complexity and O(n^2) space complexity.
  Fairly common for 2D matrix problems, but we can improve space complexity slightly.

  We could perhaps maintain a hashmap for our values and assuming a perfect hashmap,
  it could be O(k), where k represents the number of land tiles and is n^2 still
  in the worst case. Alternatively a disjoint set works too, but does not have the
  same O(1) access.

 */


int numIslands(vector<vector<int> >& photo) {
    vector<vector<bool> > visited(photo.size(), vector<bool>(photo.size(), false));
    int islandCntr = 0;

    for (int i = 0; i < photo.size(); i++) {
        for (int j = 0; j < photo.size(); j++) {
            if (photo[i][j] == 1 && !visited[i][j]) {
                islandCntr++;
                dfs(visited, photo, i, j);
            } else if (!visited[i][j]) {
                visited[i][j] = true;
            }
        }
    }


    return islandCntr;
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