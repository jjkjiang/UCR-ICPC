#include <vector>
#include <iostream>

using namespace std;

/*
Tristan is a real estate investor that often ends up owning homes
with terrible power grids. So terrible, that turning on a few lights
might cause an overload. Fixing all of them might be expensive, so
he wants to avoid fixing it if it's not worth it.

Tristan decides to make some simple tests with various lights and other
electronics. He will make a guess of a home owner's power usage, and
see if at any point he goes over the house's limit.

For each house, he knows the max power the house can take before overloading,
and for an array of electronics he knows each of their power consumption.

He writes a list of things to flip either off or on, and everything is
initially off. Tell Tristan in this function if the house overloads.

Example:

1
10 6 4
1 2 5 8 20 3
3 3 4 2

Limit = 10
Electronics = 1, 2, 5, 8, 20, 3
Instructions = 3, 3, 4, 2

Step 1:
Electronic #3 turned on, power is now at 5.

Step 2:
Electronic #3 is already on, so turn it off. Power is now at 0.

Step 3:
Electronic #4 turned on, power is now at 8.

Step 4:
Electronic #5 turned on, power is now at 10.

No overload!
*/

/*
 * This question is a bit tricky, this might come up in a real
 * interview as an exercise in class oriented programming. You
 * could either have two arrays, one for switch status and one
 * for the value, or you can have one array of classes.
 *
 * Then just keep a value and check it every iteration.
 */

class Switch {
private:
    int power;
    bool isOn;
public:
    Switch(int power) {
        this->power = power;
        isOn = false;
    }

    int interact() {
        if (isOn) {
            isOn = false;
            return -power;
        } else {
            isOn = true;
            return power;
        }
    }
};

bool willOverload(vector<int>& instructions, vector<int>& electronics, int limit) {
    int val = 0;
    vector<Switch> switchVector;
    for (int i = 0; i < electronics.size(); i++) {
        switchVector.push_back(Switch(electronics.at(i)));
    }

    for (int i = 0; i < instructions.size(); i++) {
        Switch& currentSwitch = switchVector.at(instructions.at(i) - 1);
        val += currentSwitch.interact();

        if (val > limit)
            return true;
    }

    return false;
}

int main() {
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        int limit, esize, isize, temp;
        vector<int> electronics, instructions;
        cin >> limit >> esize >> isize;

        for (int j = 0; j < esize; j++) {
            cin >> temp;
            electronics.push_back(temp);
        }

        for (int j = 0; j < isize; j++) {
            cin >> temp;
            instructions.push_back(temp);
        }

        if (willOverload(instructions,electronics,limit)) {
            cout << "OVERLOAD" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
}