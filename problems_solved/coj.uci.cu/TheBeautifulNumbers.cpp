/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3106
        Name: The Beautiful Numbers
        Date: 18/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define find asjkldhakjsdbsakjdb
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

string a, b;

bool check () {
	int i = 0, j = a.length()-1;
	while (i < j) {
		if (a[i] != a[j]) return false;
		i++; j--;
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
    
    cin>>a>>b;
    a += b;
    if (check()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
	return 0;
}
