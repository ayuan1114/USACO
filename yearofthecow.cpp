#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cows, maxTP;
int temp;
vector<int> cow;
vector<int> space;
int final = 12;
int numTP = 2;

int main() {
    cin >> cows >> maxTP;
    for (int a = 0; a < cows; a++) {
        cin >> temp;
        temp /= 12;
        cow.push_back(temp);
    }
    sort(cow.begin(), cow.end());
    space.push_back(cow[0]);
    for (int a = 1; a < cows; a++) {
        if (cow[a] != cow[a - 1]) {
            space.push_back(cow[a] - cow[a - 1] - 1);
            final += 12;
            numTP++;
        }
    }
    sort(space.begin(), space.end());
    for (int a = 0; a < numTP - maxTP; a++) {
        final += space[a] * 12;
    }
    cout << final;
    return 0;
}