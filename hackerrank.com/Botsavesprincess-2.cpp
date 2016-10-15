/*
	By: facug91
	From: https://www.hackerrank.com/challenges/saveprincess2
	Name: Bot saves princess - 2
	Date: 02/08/2016
*/

#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
    int px, py;
    bool found = false;
    for (int i=0; i<n && !found; i++) {
        for (int j=0; j<n && !found; j++) {
            if (grid[i][j] == 'p') {
                px = i; py = j;
                found = true;
            }
        }
    }
    if (px < r) cout << "UP" << endl;
    else if (px > r) cout << "DOWN" << endl;
    else if (py < c) cout << "LEFT" << endl;
    else if (py > c) cout << "RIGHT" << endl;
}
int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
