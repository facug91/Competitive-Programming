/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2890
        Name: Murcia's Skyline
        Number: 11790
        Date: 29/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, a, mlis, mlds;
vector<int> height, width, LLIS, LLDS;

int lis () {
	int i, j, ans = 0;
	LLIS.clear();
	LLIS.assign(n, 0);
	for (i=0; i<n; i++) {
		for (j=0; j<i; j++)
			if (height[j] < height[i])
				if (LLIS[j] > LLIS[i])
					LLIS[i] = LLIS[j];
		LLIS[i] += width[i];
		ans = max(LLIS[i], ans);
	}
	return ans;
}
int lds () {
	int i, j, ans = 0;
	LLDS.clear();
	LLDS.assign(n, 0);
	for (i=n-1; i>=0; i--) {
		for (j=n-1; j>i; j--)
			if (height[j] < height[i])
				if (LLDS[j] > LLDS[i])
					LLDS[i] = LLDS[j];
		LLDS[i] += width[i];
		ans = max(LLDS[i], ans);
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		height.clear();
		for (i=0; i<n; i++) {
			cin>>a;
			height.push_back(a);
		}
		width.clear();
		for (i=0; i<n; i++) {
			cin>>a;
			width.push_back(a);
		}
		mlis = lis();
		mlds = lds();
		if (mlis >= mlds) cout<<"Case "<<it<<". Increasing ("<<mlis<<"). Decreasing ("<<mlds<<")."<<endl;
		else cout<<"Case "<<it<<". Decreasing ("<<mlds<<"). Increasing ("<<mlis<<")."<<endl;
	}
	
	return 0;
}

