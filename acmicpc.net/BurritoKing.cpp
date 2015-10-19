/*
        By: facug91
        From: https://www.acmicpc.net/problem/10590
        Name: Burrito King
        Date: 27/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll n, g[100005], a[100005], b[100005];
double ma, mb, acta, actb, mg, ans[100005];
vector<pair<double, int> > ratio;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(9); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	cin>>n>>ma>>mb;
	for (i=0; i<n; i++) {
		cin>>g[i]>>a[i]>>b[i];
		if (a[i] == 0) continue;
		ratio.push_back(make_pair((double)b[i]/(double)a[i], i));
	}
	sort(ratio.begin(), ratio.end());
	acta = actb = 0.0;
	memset(ans, 0, sizeof ans);
	for (i=0; i<ratio.size(); i++) {
		j = ratio[i].second;
		mg = (double)g[j];
		if ((b[j] != 0) && (b[j]*mg > mb-actb)) mg = (mb-actb)/(double)b[j];
		acta += a[j]*mg;
		actb += b[j]*mg;
		ans[j] = mg;
	}
	if (ma > acta) cout<<"-1 -1\n";
	else {
		cout<<acta<<" "<<actb<<"\n";
		cout<<ans[0];
		for (i=1; i<n; i++) cout<<" "<<ans[i];
		cout<<"\n";
	}
	
	return 0;
}
