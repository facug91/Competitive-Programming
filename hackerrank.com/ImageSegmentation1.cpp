/*
	By: facug91
	From: https://www.hackerrank.com/challenges/dip-image-segmentation-1
	Name: Image Segmentation #1
	Date: 02/08/2016
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<string> mat;
vector<vector<bool>> vis;
string line;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
stack<pair<int, int>> stk;

void dfs (int i, int j) {
    stk.push(make_pair(i, j));
    while (stk.size()) {
        i = stk.top().first;
        j = stk.top().second;
        stk.pop();
        vis[i][j] = true;
        for (int d=0; d<4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && x < mat.size() && y >= 0 && y < mat[x].length() && mat[x][y] == '1' && !vis[x][y]) {
                stk.push(make_pair(i, j));
                stk.push(make_pair(x, y));
                break;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    mat.push_back("000110001010");
    mat.push_back("111011110001");
    mat.push_back("111010010010");
    mat.push_back("100000000100");
    vis.assign(mat.size(), vector<bool>(mat[0].length(), 0));
    int ans = 0;
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].length(); j++) {
            if (mat[i][j] == '1' && !vis[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
