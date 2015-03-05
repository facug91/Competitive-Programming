/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2443
        Name: An Unidentified Object Cup
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

int n, k, ans, idx, aux, count;
bool sieve[105], tie;

void init () {
	int i, j;
	memset(sieve, ~0, sizeof sieve);
	sieve[0] = sieve[1] = false;
	for (i=4; i<105; i+=2) sieve[i] = false;
	for (i=3; i<15; i+=2)
		if (sieve[i])
			for (j=i*i; j<105; j+=i+i)
				sieve[j] = false;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	init();
	cin>>n>>k;
	ans = -1;
	for (i=0; i<n; i++) {
		count = 0;
		for (j=0; j<k; j++) {
			cin>>aux;
			if (sieve[aux]) count++;
		}
		if (count > ans) {
			ans = count;
			idx = i+1;
			tie = false;
		} else if (count == ans) tie = true;
	}
	if (tie) cout<<"No winner"<<endl;
	else cout<<"Object "<<idx<<" wins with "<<ans<<" rare characteristics"<<endl;
	
	return 0;
}
