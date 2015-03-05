/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2261
        Name: Good Arrays
        Date: 03/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define count dsakjfhbksadfasfasd3243
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000000ll
//#define MAXN 4000000000ll

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, seq[100], primes[] = {2, 3, 5, 7, 11}, count;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>n;
	for (i=0; i<n; i++) cin>>seq[i];
	bool ok = true;
	for (i=0; i<n; i++) {
		count = 0;
		for (j=0; j<5; j++)
			if (seq[i] % primes[j] == 0)
				count++;
		if (count < 3) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	
	return 0;
}
