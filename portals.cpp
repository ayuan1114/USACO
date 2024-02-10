#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int vertices;
int cost[200000];
pair<int, int> portal[400000][2];
int vertex[200000][4];
int group[200000][4];
int groupNum = 1;
queue<pair<int, int>> check;
pair<int, int> cur;
pair<int, int> other;
vector<int> order;
int parent[400000];
int inTree[400000];
int total = 0, connections = 0;

bool method(int a, int b) {
    return cost[a] < cost[b];
}

int par(int a) {
    if (parent[a] == a) {
        return a;
    }
    else {
        parent[a] = par(parent[a]);
        return parent[a];
    }
}

bool combine(int a, int b) {
    int parA = par(a);
    int parB = par(b);
    if (parA == parB) {
        return false;
    }
    parent[parB] = parA;
    return true;
}

int main() {
    cin >> vertices;
    for (int a = 0; a < 2 * vertices; a++) {
        for (int b = 0; b < 2; b++) {
            portal[a][b] = {-1, -1};
        }
    }
    for (int a = 0; a < vertices; a++) {
        cin >> cost[a] >> vertex[a][0] >> vertex[a][1] >> vertex[a][2] >> vertex[a][3];
        vertex[a][0]--;
        vertex[a][1]--;
        vertex[a][2]--;
        vertex[a][3]--;
        order.push_back(a);
        for (int b = 0; b < 4; b++) {
            if (portal[vertex[a][b]][0].first != -1) {
                portal[vertex[a][b]][1] = {a, b};
            }
            else {
                portal[vertex[a][b]][0] = {a, b};
            }

        }
    }
    for (int a = 0; a < vertices; a++) {
        for (int b = 0; b < 4; b++) {
            if (group[a][b] == 0) {
                check.push({a, b});
                while (!check.empty()) {
                    cur = check.front();
                    check.pop();
                    if (group[cur.first][cur.second] != 0) {
                        continue;
                    }
                    group[cur.first][cur.second] = groupNum;
                    if (portal[vertex[cur.first][cur.second]][0] == cur) {
                        other = portal[vertex[cur.first][cur.second]][1];
                    }
                    else {
                        other = portal[vertex[cur.first][cur.second]][0];
                    }
                    if (group[other.first][other.second] == 0) {
                        check.push(other);
                    }
                    if (cur.second < 2) {
                        if (group[cur.first][1 - cur.second] == 0) {
                            check.push({cur.first, 1 - cur.second});
                        }
                    }
                    else {
                        if (group[cur.first][5 - cur.second] == 0) {
                            check.push({cur.first, 5 - cur.second});
                        }
                    }
                }
                parent[groupNum] = groupNum;
                groupNum++;
            }
        }
    }
    sort(order.begin(), order.end(), method);
    for (int a = 0; a < order.size(); a++) {
        if (combine(group[order[a]][0], group[order[a]][2])) {
            connections++;
            total += cost[order[a]];
            if (connections >= groupNum - 2) {
                break;
            }
        }
    }
    cout << total;
    return 0;
}