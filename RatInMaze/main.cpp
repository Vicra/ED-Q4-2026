
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;

bool isValid(vector<vector<int>>& adj, int x, int y) {
    int n = adj.size();

    if (x >= 0 && y >= 0 &&
        x < n && y < n &&
        adj[x][y] == 1) {
        return true;
    }

    return false;
}

void mazeRec(vector<vector<int>>& adj, int x, int y,
             string path, vector<string>& res) {

    int n = adj.size();

    // Destination reached
    if (x == n - 1 && y == n - 1) {
        res.push_back(path);
        return;
    }

    // Mark current cell as visited
    adj[x][y] = 0;

    // Down
    if (isValid(adj, x + 1, y)) {
        mazeRec(adj, x + 1, y, path + "D", res);
    }

    // Left
    if (isValid(adj, x, y - 1)) {
        mazeRec(adj, x, y - 1, path + "L", res);
    }

    // Right
    if (isValid(adj, x, y + 1)) {
        mazeRec(adj, x, y + 1, path + "R", res);
    }

    // Up
    if (isValid(adj, x - 1, y)) {
        mazeRec(adj, x - 1, y, path + "U", res);
    }

    // Backtrack: restore current cell
    adj[x][y] = 1;
}

vector<string> maze(vector<vector<int>>& adj) {
    vector<string> res;

    int n = adj.size();

    if (n == 0 || adj[0][0] == 0 || adj[n-1][n-1] == 0) {
        return res;
    }

    mazeRec(adj, 0, 0, "", res);

    return res;
}

int main() {
    vector<vector<int>> adj = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 1, 1, 1}
    }; //DRRDDDRR

    vector<string> paths = maze(adj);

    for (const string& path : paths) {
        cout << path << '\n';
    }

    return 0;
}
