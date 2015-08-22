/*
        By: facug91
        From: https://www.acmicpc.net/problem/10589
        Name: Alter Board
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

int n, m;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>n>>m;
	cout<<n/2+m/2<<"\n";
	for (i=2; i<=n; i+=2) cout<<i<<" 1 "<<i<<" "<<m<<"\n";
	for (i=2; i<=m; i+=2) cout<<"1 "<<i<<" "<<n<<" "<<i<<"\n";
	
	return 0;
}
