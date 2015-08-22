/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4280
        Name: Digital Clock
        Date: 27/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define clock asoudh219udhjdgausdhs9udy
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, aux, h, m, t;
bool pass, working[4][7], clock[55][4][7];
bool wset[][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
vector<ii> ans;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k;
	
	while (scanf("%d", &n) != EOF) {
		memset(working, 0, sizeof working);
		for (i=0; i<n; i++) {
			scanf("%d:%d", &h, &m);
			for (k=0; k<4; k++) {
				if (k == 0) t = h / 10;
				else if (k == 1) t = h % 10;
				else if (k == 2) t = m / 10;
				else t = m % 10;
				for (j=0; j<7; j++) {
					working[k][j] |= wset[t][j];
					clock[i][k][j] = wset[t][j];
				}
			}
		}
		ans.clear();
		for (int a=0; a<=2; a++) {
			for (int b=0; b<=((a==2)?3:9); b++) {
				for (int c=0; c<=5; c++) {
					for (int d=0; d<=9; d++) {
						h = a*10+b; m = c*10+d;
						pass = true;
						for (i=0; i<n; i++) {
							for (k=0; k<4; k++) {
								if (k == 0) t = h / 10;
								else if (k == 1) t = h % 10;
								else if (k == 2) t = m / 10;
								else t = m % 10;
								for (j=0; j<7; j++) {
									if (!working[k][j]) continue;
									if (clock[i][k][j] && wset[t][j]) continue;
									if (!clock[i][k][j] && !wset[t][j]) continue;
									pass = false;
								}
							}
							m++;
							if (m == 60) h++, m = 0;
							if (h == 24) h = 0, m = 0;
						}
						if (pass) ans.push_back(ii(a*10+b, c*10+d));
					}
				}
			}
		}
		if (ans.size() == 0) printf("none\n");
		else {
			printf("%02d:%02d", ans[0].first, ans[0].second);
			for (i=1; i<ans.size(); i++) printf(" %02d:%02d", ans[i].first, ans[i].second);
			printf("\n");
		}
	}
	
	return 0;
}
