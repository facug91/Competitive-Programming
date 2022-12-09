/*
        By: facug91
        From: https://www.acmicpc.net/problem/10594
        Name: Filter
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

int m, f, a[1005], n, q, u, b, aux, ans;
string s[1005];
bool bin[1005][1005], valid[1005], validu[1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j, k;
	
	cin>>m>>f;
	for (i=0; i<f; i++) cin>>a[i];
	cin>>n;
	for (i=0; i<n; i++) cin>>s[i];
	for (i=0; i<n; i++) {
		for (j=0; j<s[i].length(); j++) {
			char c = s[i][j];
			if ('0' <= c && c <= '9') aux = c - '0';
			else aux = c - 'a' + 10;
			for (k=0; k<4; k++) bin[i][j*4+k] = (aux & (1<<k));
		}
	}
	memset(valid, false, sizeof valid);
	cin>>q;
	while (q--) {
		cin>>u;
		memset(validu, true, sizeof validu);
		for (i=0; i<f; i++) {
			b = ((u%m)*(a[i]%m))%m;
			for (j=0; j<n; j++) if (!bin[j][b]) validu[j] = false;
		}
		for (i=0; i<n; i++) if (validu[i]) valid[i] = true;
	}
	ans = 0;
	for (i=0; i<n; i++) if (valid[i]) ans++;
	cout<<ans;
	for (i=0; i<n; i++) if (valid[i]) cout<<" "<<i;
	cout<<"\n";
	
	return 0;
}
