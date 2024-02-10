#include <iostream>
using namespace std;

int tens[250001][2];
long long prefix[500][500];
int grid[501][501];
int PIE[250001];
int side;
int numTen = 0;
long long total;

int main() {
    cin >> side;
    for (int a = 1; a < side + 1; a++) {
        for (int b = 1; b < side + 1; b++) {
            cin >> prefix[a][b];
            if (prefix[a][b] == 100) {
                tens[numTen][0] = a;
                tens[numTen][1] = b;
                numTen++;
                prefix[a][b] = 1;
                grid[a][b] = 1;
            }
            else if (prefix[a][b] < 100) {
                prefix[a][b] = -250001;
                grid[a][b] = -1;
            }
            else {
                prefix[a][b] = 0;
            }
        }
    }
    for (int a = 1; a < side + 1; a++) {
        for (int b = 1; b < side + 1; b++) {
            prefix[a][b] += prefix[a][b - 1];
        }
    }
    for (int a = 1; a < side + 1; a++) {
        for (int b = 1; b < side + 1; b++) {
            prefix[b][a] += prefix[b - 1][a];
        }
    }
    for (int a = 1; a < side + 1; a++) {
        for (int b = 1; b <= a; b++) {
            for (int c = 1; c < side + 1; c++) {
                for (int d = 1; d <= c; d++) {
                    if (prefix[a][c] - prefix[a][d - 1] - prefix[b - 1][c] + prefix[b - 1][d - 1] > 0) {
                        total++;
                    }
                }
            }
        }
    }
    cout << total;
    return 0;
}