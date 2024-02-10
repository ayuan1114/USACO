#include <iostream>
using namespace std;

int cows;
int cow[100000][2];
int numAdj[2000][2000];
int taken[1000][1000];
int adj[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int temp, counter = 0;

void fix (int x, int y) {
    for (int a = 0; a < 4; a++) {
        if (numAdj[x + adj[a][0]][y + adj[a][1]] == -1) {
            counter++;
            temp = 0;
            for (int b = 0; b < 4; b++) {
                if (numAdj[x + adj[a][0] + adj[b][0]][y + adj[a][1] + adj[b][1]] != -1) {
                    numAdj[x + adj[a][0] + adj[b][0]][y + adj[a][1] + adj[b][1]]++;
                    temp++;
                }
            }
            numAdj[x + adj[a][0]][y + adj[a][1]] = temp;
            if (temp == 3) {
                fix(x + adj[a][0], y + adj[a][1]);
            }
            for (int b = 0; b < 4; b++) {
                if (numAdj[x + adj[a][0] + adj[b][0]][y + adj[a][1] + adj[b][1]] == 3) {
                    fix(x + adj[a][0] + adj[b][0], y + adj[a][1] + adj[b][1]);
                }
            }
        }
    }
}

int main() {
    cin >> cows;
    for (int a = 0; a < cows; a++) {
        cin >> cow[a][0] >> cow[a][1];
        cow[a][0] += 500;
        cow[a][1] += 500;
    }
    for (int a = 0; a < 2000; a++) {
        for (int b = 0; b < 2000; b++) {
            numAdj[a][b] = -1;
        }
    }
    for (int a = 0; a < cows; a++) {
        taken[cow[a][0]][cow[a][1]] = 1;
        if (numAdj[cow[a][0]][cow[a][1]] == -1) {
            temp = 0;
            for (int b = 0; b < 4; b++) {
                if (numAdj[cow[a][0] + adj[b][0]][cow[a][1] + adj[b][1]] != -1) {
                    numAdj[cow[a][0] + adj[b][0]][cow[a][1] + adj[b][1]]++;
                    temp++;
                }
            }
            numAdj[cow[a][0]][cow[a][1]] = temp;
            if (temp == 3) {
                fix(cow[a][0], cow[a][1]);
            }
            for (int b = 0; b < 4; b++) {
                if (numAdj[cow[a][0] + adj[b][0]][cow[a][1] + adj[b][1]] == 3) {
                    fix(cow[a][0] + adj[b][0], cow[a][1] + adj[b][1]);
                }
            }
        }
        else {
            counter--;
        }
        cout << counter << endl;
    }
    return 0;
}