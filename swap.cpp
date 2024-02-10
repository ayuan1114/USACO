#include <iostream>
#include <fstream>
using namespace std;

ofstream fout;
ifstream fin;

int cows, swaps, reps;
int first, last, temp;
int curVal;
int mod;
bool repeat;
int cow[100000];

int main() {
    fin.open("swap.in");
    fin >> cows >> swaps >> reps;
    for (int a = 0; a < cows; a++) {
        cow[a] = a;
    }
    for (int a = 0; a < swaps; a++) {
        fin >> first >> last;
        first--;
        last--;
        for (int b = 0; b < (last - first + 1) / 2; b++) {
            temp = cow[first + b];
            cow[first + b] = cow[last - b];
            cow[last - b] = temp;
        }
    }

    fout.open("swap.out");
    for (int a = 0; a < cows; a++) {
        curVal = a;
        repeat = false;
        for (int b = 0; b < reps; b++) {
            curVal = cow[curVal];
            if (curVal == a) {
                mod = b + 1;
                repeat = true;
                break;
            }
        }
        if (repeat) {
            curVal = a;
            for (int b = 0; b < reps % mod; b++) {
                curVal = cow[curVal];
            }
        }
        fout << curVal + 1 << endl;
    }
}