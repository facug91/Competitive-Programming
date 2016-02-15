/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=163
        Name: Puzzle
        Date: 31/12/2015
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-2
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int x, y;
string mat[5], moves;
bool legal;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (getline(cin, mat[0]), mat[0].length() == 5) {
		if (tc > 1) cout<<endl;
		for (i=1; i<5; i++) getline(cin, mat[i]);
		legal = true;
		for (i=0; i<5; i++) for (j=0; j<5; j++) if (mat[i][j] == ' ') x = i, y = j;
		do {
			getline(cin, moves);
			for (i=0; i<moves.length() && legal; i++) {
				switch (moves[i]) {
					case 'A':
						if (x > 0) {
							swap(mat[x][y], mat[x-1][y]);
							x--;
						} else legal = false;
						break;
					case 'B':
						if (x < 4) {
							swap(mat[x][y], mat[x+1][y]);
							x++;
						} else legal = false;
						break;
					case 'L':
						if (y > 0) {
							swap(mat[x][y], mat[x][y-1]);
							y--;
						} else legal = false;
						break;
					case 'R':
						if (y < 4) {
							swap(mat[x][y], mat[x][y+1]);
							y++;
						} else legal = false;
						break;
				}
			}
		} while (moves.back() != '0');
		cout<<"Puzzle #"<<tc++<<":"<<endl;
		if (!legal) cout<<"This puzzle has no final configuration."<<endl;
		else {
			for (i=0; i<5; i++) {
				cout<<mat[i][0];
				for (j=1; j<5; j++) {
					cout<<" "<<mat[i][j];
				}
				cout<<endl;
			}
		}
	}
	
	return 0;
}
