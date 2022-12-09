/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2474
        Name: Is this the easiest problem?
        Date: 29/01/2015
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
//#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll s[3];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>s[0]>>s[1]>>s[2];
		sort(s, s+3);
		cout<<"Case "<<it<<": ";
		if (s[0] + s[1] <= s[2]) cout<<"Invalid"<<endl;
		else if (s[0] == s[2]) cout<<"Equilateral"<<endl;
		else if (s[0] == s[1] || s[1] == s[2]) cout<<"Isosceles"<<endl;
		else cout<<"Scalene"<<endl;
	}
	
	return 0;
}
