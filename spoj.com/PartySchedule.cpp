/*
        By: facug91
        From: http://www.spoj.com/problems/PARTY/
        Name: Party Schedule
        Date: 14/09/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, k, party[105][2];
ii DP[105][505];

ii dp (int idx, int cap) {
	if (idx == n || cap == 0) return ii(0, 0);
	if (DP[idx][cap].first != -1) return DP[idx][cap];
	DP[idx][cap] = dp(idx+1, cap);
	if (cap >= party[idx][0]) {
		ii aux = dp(idx+1, cap-party[idx][0]);
		aux.first += party[idx][0];
		aux.second += party[idx][1];
		if (aux.second > DP[idx][cap].second) DP[idx][cap] = aux;
		else if (aux.second == DP[idx][cap].second) DP[idx][cap].first = min(DP[idx][cap].first, aux.first);
	}
	return DP[idx][cap];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>k>>n, n || k) {
		for (i=0; i<n; i++) cin>>party[i][0]>>party[i][1];
		for (i=0; i<n; i++) for (j=0; j<=k; j++) DP[i][j] = ii(-1, -1);
		ii ans = dp(0, k);
		cout << ans.first << " " << ans.second << endl;
	}
	
	return 0;
}
