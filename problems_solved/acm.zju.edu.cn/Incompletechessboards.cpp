/*
        By: facug91
        From: http://acm.tju.edu.cn/toj/showp1709.html
        Name: Incomplete chess boards
        Date: 01/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll a, b;
set<ll> DP;

bool solve (ll bitmask) {
	if (DP.find(bitmask) != DP.end()) return false;
	if (bitmask == -1ll) return true;
	ll pos, act;
	for (pos=0ll; (bitmask & (1ll<<pos)) != 0ll; pos++);
	act = bitmask | (1ll << pos);
	//derecha
	if ((((pos + 1ll) % 8ll) != 0ll) && ((act & (1ll << (pos + 1ll))) == 0ll))
		if (solve(act | (1ll << (pos + 1ll))))
			return true;
	//abajo
	if ((pos < 56ll) && ((act & (1ll << (pos + 8ll))) == 0ll))
		if (solve(act | (1ll << (pos + 8ll))))
			return true;
	DP.insert(bitmask);
	return false;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		ll bitmask = 0ll;
		cin>>a>>b; a--; b--;
		bitmask |= (1ll << (8ll * a + b));
		cin>>a>>b; a--; b--;
		bitmask |= (1ll << (8ll * a + b));
		cout<<"Scenario #"<<it<<":"<<endl;
		if (solve(bitmask)) cout<<1<<endl<<endl;
		else cout<<0<<endl<<endl;
	}
	
	return 0;
}
