/*
	By: facug91
	From: https://www.hackerrank.com/challenges/saveprincess
	Name: Bot saves princess
	Date: 02/08/2016
*/

#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    int bx, by;
    bool found = false;
    for (int i=0; i<grid.size() && !found; i++) {
        for (int j=0; j<grid[i].length() && !found; j++) {
            if (grid[i][j] == 'm') {
                bx = i; by = j;
                found = true;
            }
        }
    }
    int px, py;
    if (grid[0][0] == 'p') {
        px = 0, py = 0;
    } else if (grid[0][n-1] == 'p') {
        px = 0, py = n-1;
    } else if (grid[n-1][0] == 'p') {
        px = n-1, py = 0;
    } else {
        px = n-1, py = n-1;
    }
    if (px < bx) {
        for (int i=px; i<bx; i++) {
            cout << "UP" << endl;
        }
    } else if (px > bx) {
        for (int i=bx; i<px; i++) {
            cout << "DOWN" << endl;
        }
    }
    if (py < by) {
        for (int i=py; i<by; i++) {
            cout << "LEFT" << endl;
        }
    } else if (py > by) {
        for (int i=by; i<py; i++) {
            cout << "RIGHT" << endl;
        }
    }
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
