/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=78
        Name: Mouse Clicks 
        Date: 11/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int rn, in;
char t;
pair<ii, ii> reg[30];
ii icon[55], m, a, b;
bool firstMouse, obsIcon[55];

bool inside (pair<ii, ii> r, ii p) {
	return r.F.F <= p.F && p.F <= r.S.F && r.F.S <= p.S && p.S <= r.S.S;
}

int dist_point (ii a, ii b) {
	return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	firstMouse = true;
	memset(obsIcon, 0, sizeof obsIcon);
	while (cin>>t, t != '#') {
		if (t == 'R') {
			cin>>a.F>>a.S>>b.F>>b.S;
			reg[rn++] = MP(a, b);
		} else if (t == 'I') {
			cin>>a.F>>a.S;
			icon[in++] = a;
		} else {
			if (firstMouse) {
				firstMouse = false;
				for (j=0; j<in; j++) {
					for (i=rn-1; i>=0; i--) {
						if (inside(reg[i], icon[j])) {
							obsIcon[j] = true;
							break;
						}
					}
				}
			}
			cin>>a.F>>a.S;
			bool region = false;
			for (i=rn-1; i>=0; i--) {
				if (inside(reg[i], a)) {
					cout<<(char)('A'+i)<<endl;
					region = true;
					break;
				}
			}
			if (!region) {
				vector<int> ans;
				int dis = INT_MAX, aux;
				for (i=0; i<in; i++) if (!obsIcon[i]) {
					aux = dist_point(icon[i], a);
					if (aux < dis) {
						dis = aux;
						ans.clear();
						ans.push_back(i+1);
					} else if (aux == dis) {
						ans.push_back(i+1);
					}
				}
				for (i=0; i<ans.size(); i++) cout<<right<<setw(3)<<ans[i];
				cout<<endl;
			}
		}
	}
	
	return 0;
}
