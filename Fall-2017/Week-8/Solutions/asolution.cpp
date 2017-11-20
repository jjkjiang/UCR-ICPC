#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
Rachel is the queen of a kingdom of 26 people. Each person has a
name, but for purposes of government each individual appears as
a letter from 'a' to 'z' on official documents.

She looks at person 'a' one day and sees them really tired. 'a'
was on guard duty last night, and each citizen is fine with doing
guard duty as long as they get a nice night's sleep afterwards.

She is worried that she is overworking her citizens by chance.
Ignoring the fact that she can resolve all her problems fairly by
proceeding in the order a, b, c, d, e... z, she decides to see if she
has wronged any of her citizens.

She looks through the records of her citizens at work, but it can be
tedious. She will grant you a plot of land and citizenship under
the character 'A' if you are able to produce a program that can
take in records as a string, and tell if she is being fair by outputting
your name, A. If she is not being fair, output the character of the first
person who is wronged.

Example:
3
abcdefg
abababa
aabcdee

abcdefg
In abcdefg, everyone gets at least one night's rest. So, output A.

In abababa, a and b are not quite happy but at least get a fair night's rest.
Output A.

In aabcdee, a and e are both being overworked, but output 'a' because they were
first.
*/

/*
 * The solution is fairly straightforward, just iterate and compare previous
 * and next characters.
 */

char overworkedCitizen(string& record) {
    char result = 'A';

    for (int i = 0; i < record.size() - 1; i++) {
        if (record.at(i) == record.at(i + 1)) {
            result = record.at(i);
            break;
        }
    }

    return result;
}

int main() {
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        string record;
        cin >> record;

        cout << overworkedCitizen(record) << endl;
    }

}