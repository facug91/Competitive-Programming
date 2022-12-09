/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4843
        Name: Knights of the Round Table
        Date: 26/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int k, d, a, b, assign[1000005];
bool occupied[1000005], standing[1000006], vis[1000005];
vector<int> act;

int main () {
	int TC, i, j, f;
	
	while (scanf("%d %d", &k, &d) != EOF) {
		for (i=1; i<=k; i++) {
			occupied[i] = false;
			standing[i] = true;
			assign[i] = 0;
		}
		for (i=0; i<d; i++) {
			scanf("%d %d", &a, &b);
			occupied[b] = true;
			standing[a] = false;
		}
		for (f=1; occupied[f]; f++);
		int dif = f - 1;
		for (i=1; i<=k; i++) {
			if (standing[i]) {
				if (dif < 0) {
					f = i;
					while (occupied[f]) {
						f = (f == k) ? 1 : (f + 1);
						dif++;
					}
				}
				assign[f]++;
			}
			dif--;
		}
		act.clear();
		for (i=1; i<=k; i++)
			if (!occupied[i])
				act.push_back(assign[i]);
		for (i=0; i<(int)act.size(); i++)
			vis[i] = false;
		int carry = 0; i = 0; k = (int)act.size();
		if (k != 0) {
			while ((!vis[i]) || (carry != 0)) {
				if (!vis[i]) {
					if (act[i] == 0) {
						act[i] = carry;
						carry = (carry == 0) ? 0 : (carry - 1);
					} else {
						int tmp = carry;
						act[i] += carry;
						carry = act[i] - 1;
					}
					vis[i] = true;
				} else {
					int tmp = carry;
					if (act[i] == 0)
						carry = (carry == 0) ? 0 : (carry - 1);
					act[i] += tmp;
				}
				i = (i + 1) % k;
			}
		}
		ll ans = 1ll;
		for (i=0; i<k; i++)
			ans = ((ll)act[i] * ans) % MOD;
		printf("%lld\n", ans);
	}
	
	return 0;
}
