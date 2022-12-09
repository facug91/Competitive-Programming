/*
        By: facug91
        From: https://acm.javeriana.edu.co/maratones/2015/07
        Name: Draughts
        Date: 08/08/2015
*/

#include <bits/stdc++.h>

using namespace std;
#define prev d392rhbcdgausidhdsadasda

typedef long long ll;

int ans, dx[] = {-1, 1, 1, -1}, dy[] = {1, 1, -1, -1};
string mat[15];

void dfs (int i, int j, int act) {
	if (act > ans) ans = act;
	int x, y, w, z;
	for (int d=0; d<4; d++) {
		x = i+dx[d]; y = j + dy[d];
		if (x >= 0 && x < 10 && y >= 0 && y < 10 && mat[x][y] == 'B') {
			w = x + dx[d];
			z = y + dy[d];
			if (w >= 0 && w < 10 && z >= 0 && z < 10 && (mat[w][z] == '.' || mat[w][z] == '#')) {
				mat[i][j] = '.';
				mat[x][y] = '.';
				mat[w][z] = 'W';
				dfs(w, z, act+1);
				mat[i][j] = 'W';
				mat[x][y] = 'B';
				mat[w][z] = '.';
			}
		}
	}
}

int main() {
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		ans = 0;
		for (i=0; i<10; i++) cin>>mat[i];
		for (i=0; i<10; i++) for (j=0; j<10; j++) if (mat[i][j] == 'W') dfs(i, j, 0);
		cout<<ans<<endl;
	}
	
}

