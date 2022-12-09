/*
	By: facug91
	From: https://www.hackerrank.com/challenges/dip-morphological-operations-dilation
	Name: Morphological Operations: Dilation
	Date: 02/08/2016
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<string> mat, dil;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    mat.push_back("0000000000");
    mat.push_back("0111111100");
    mat.push_back("0000111100");
    mat.push_back("0000111100");
    mat.push_back("0001111100");
    mat.push_back("0000111100");
    mat.push_back("0001100000");
    mat.push_back("0000000000");
    mat.push_back("0000000000");   
    
    dil.push_back("0000000000");
    dil.push_back("0111111100");
    dil.push_back("0000111100");
    dil.push_back("0000111100");
    dil.push_back("0001111100");
    dil.push_back("0000111100");
    dil.push_back("0001100000");
    dil.push_back("0000000000");
    dil.push_back("0000000000");   
    
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].length(); j++) {
            if (mat[i][j] == '0') continue;
            for (int d=0; d<8; d++) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (x >= 0 && x < mat.size() && y >= 0 && y < mat[x].length()) {
                    dil[x][y] = '1';
                }
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].length(); j++) {
            if (dil[i][j] == '1') ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
