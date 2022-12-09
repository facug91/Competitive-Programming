/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4849
	Name: There is No Alternative
	Date: 27/06/2016
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int n, m, u, v, w, p[505], mst_sum, sum_aux, cnt_aux, cnt, sum;
vector<pair<int, ii>> edges;
vi mst;

int find_set (int i) {
	return ((i == p[i]) ? i : (p[i] = find_set(p[i])));
}

void union_set (int i, int j, int w, int idx) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[x] = y;
		mst.push_back(idx);
		mst_sum += w;
	}
}

void union_set2 (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[x] = y;
		sum_aux += w;
		cnt_aux++;
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	while (cin>>n>>m) {
		edges.clear();
		for (i=1; i<=n; i++) p[i] = i;
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			edges.push_back(MP(w, ii(u, v)));
		}
		mst_sum = 0;
		mst.clear();
		sort(edges.begin(), edges.end());
		for (i=0; i<m; i++) union_set(edges[i].S.F, edges[i].S.S, edges[i].F, i);
		//cerr<<"mst_sum "<<mst_sum<<endl;
		cnt = sum = 0;
		for (i=0; i<n-1; i++) {
			for (j=1; j<=n; j++) p[j] = j;
			sum_aux = cnt_aux = 0;
			for (j=0; j<m; j++) if (j != mst[i]) union_set2(edges[j].S.F, edges[j].S.S, edges[j].F);
			//cerr<<"sum_aux "<<sum_aux<<endl;
			if (sum_aux > mst_sum || cnt_aux != n-1) {
				cnt++;
				sum += edges[mst[i]].F;
			}
		}
		cout<<cnt<<" "<<sum<<endl;
	}
	
	return 0;
}
