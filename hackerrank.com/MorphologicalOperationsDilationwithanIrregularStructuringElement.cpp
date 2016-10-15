/*
	By: facug91
	From: https://www.hackerrank.com/challenges/dip-morphological-operations-dilation-with-an-irregular-structuring-element
	Name: Morphological Operations: Dilation with an Irregular Structuring Element
	Date: 04/08/2016
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<string> mat, dil;
int dx[] = {-1, 0}, dy[] = {0, 1};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    mat.push_back("0000");
    mat.push_back("0110");
    mat.push_back("0000");
    
    dil.push_back("0000");
    dil.push_back("0110");
    dil.push_back("0000");
    
    for (int i=1; i<mat.size()-1; i++) {
        for (int j=0; j<mat[i].length(); j++) {
            if (mat[i][j] == '0') continue;
            for (int d=0; d<2; d++) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (x >= 0 && x < mat.size() && y >= 0 && y < mat[x].length()) {
                    dil[x][y] = '1';
                }
            }
        }
    }
    
    //int ans = 0;
    for (int i=0; i<mat.size(); i++) {
        cout << dil[i] << endl;
    }
    
    //cout << ans << endl;
    
    return 0;
}
