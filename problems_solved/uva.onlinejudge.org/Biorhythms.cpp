/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=697
        Name: Biorhythms
        Number: 756
        Date: 04/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int p, e, i, d, peak, ans;

int n[] = {23, 28, 33}, a[3], cant = 3;

ii extended_euclid (int a, int b) {
	int x = 0, lastx = 1;
	int y = 1, lasty = 0;
	int tmp;
	while (b != 0) {
		int quotient = a/b;
		tmp = a; a = b; b = tmp%b;
		tmp = x; x = lastx - quotient*x; lastx = tmp;
		tmp = y; y = lasty - quotient*y; lasty = tmp;
	}
	return ii(lastx ,lasty);
}

int inv (int a, int m) {
	ii res = extended_euclid(a, m);
	return ((res.first % m) + m) % m;
}

int crt () {
	int i, tmp, mod, res;
	mod = 1;
	for (i=0; i<cant; i++) {
		mod *= n[i];
	}
	res = 0;
	for (i=0; i<cant; i++) {
		tmp = mod/n[i];
		tmp *= inv(tmp, n[i]); //inv = extended_gcd
		res += ((tmp * a[i]) % mod);
	}
	return (res % mod + mod) % mod;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (cin>>a[0]>>a[1]>>a[2]>>d, (d != -1)) {
		peak = crt();
		if (peak == 0) ans = (n[0]*n[1]*n[2]) - d;
		else {
			if (peak <= d) ans = peak + (n[0]*n[1]*n[2]) - d;
			else ans = peak - d;
		}
		cout<<"Case "<<TC++<<": the next triple peak occurs in "<<ans<<" days."<<endl;
	}
	
	return 0;
}

