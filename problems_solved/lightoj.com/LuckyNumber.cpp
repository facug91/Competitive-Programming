/*
	By: facug91
	From: http://www.lightoj.com/volume_showproblem.php?problem=1097
	Name: Lucky Number
	Date: 20/06/2016
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int n, ft[1500005];
bool lucky[1500005];
vi ans;

int rsq (int b) {
	int sum = 0;
	for (; b; b -= (b & (-b))) sum += ft[b];
	return sum;
}

void update (int p, int v) {
	for (; p<1500005; p += (p & (-p))) ft[p] += v;
}

int binary_search (int v) {
	int lo = 0, hi = 1500005, mid;
	while (lo+1 < hi) {
		mid = (lo + hi) / 2;
		if (rsq(mid) >= v) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main () {
	//#ifdef ONLINE_JUDGE
		//ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	memset(ft, 0, sizeof ft);
	for (i=1; i<1500005; i+=2) {
		update(i, 1);
		lucky[i] = true;
	}
	//for (i=1; i<10; i++) cerr<<"i = "<<i<<" "<<rsq(i)<<" bs "<<binary_search(i)<<endl;
	for (i=3; i<750000; i+=2) if (lucky[i]) {
		int curr = rsq(1500000);
		curr = (curr / i) * i;
		while (curr) {
			//if (i == 3 && curr < 30) cerr<<"curr "<<curr<<endl;
			int to_erase = binary_search(curr);
			//if (i == 3 && curr < 30) cerr<<"to_erase "<<to_erase<<endl;
			lucky[to_erase] = false;
			update(to_erase, -1);
			curr -= i;
		}
	}
	for (i=1; i<1500005; i++) if (lucky[i]) ans.push_back(i);
	scanf("%d", &tc);
	for (int it=1; it<=tc; it++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", it, ans[n-1]);
	}
	
	return 0;
}
