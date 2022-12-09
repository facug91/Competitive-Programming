/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4844
	Name: Bit String Reordering
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

int n, m, order[20], cnt[2], bit_cnt[2], ans;
string bits, bits2, aux;
char c;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	while (cin>>n>>m) {
		bits = "";
		for (i=0; i<n; i++) {
			cin>>c;
			bits += c;
		}
		for (i=0; i<m; i++) cin>>order[i];
		cnt[0] = cnt[1] = 0;
		bit_cnt[0] = bit_cnt[1] = 0;
		for (i=0; i<m; i++) cnt[i%2] += order[i];
		for (i=0; i<n; i++) bit_cnt[bits[i]-'0']++;
		
		ans = INF;
		
		//using 0 then 1
		bits2 = bits;
		if (bit_cnt[0] == cnt[0]) {
			int ans2 = 0;
			aux = "";
			for (i=0; i<m; i++) for (j=0; j<order[i]; j++) aux += (char)((i%2)+'0');
			bool done = false;
			while (!done) {
				done = true;
				for (i=0; i<n; i++) if (bits[i] != aux[i]) {
					done = false;
					j = i + 1;
					while (bits[j] != aux[i]) j++;
					ans2 += j-i;
					bits = aux.substr(0, i+1) + bits.substr(i, j-i) + bits.substr(j+1, (int)bits.length()-j+1);
				}
			}
			ans = min(ans, ans2);
		}
		bits = bits2;
		
		//using 1 then 0
		bits2 = bits;
		if (bit_cnt[1] == cnt[0]) {
			int ans2 = 0;
			aux = "";
			for (i=0; i<m; i++) for (j=0; j<order[i]; j++) aux += (char)(((i+1)%2)+'0');
			bool done = false;
			while (!done) {
				done = true;
				for (i=0; i<n; i++) if (bits[i] != aux[i]) {
					done = false;
					j = i + 1;
					while (bits[j] != aux[i]) j++;
					ans2 += j-i;
					bits = aux.substr(0, i+1) + bits.substr(i, j-i) + bits.substr(j+1, (int)bits.length()-j+1);
				}
			}
			ans = min(ans, ans2);
		}
		bits = bits2;
		
		cout<<ans<<endl;
	}
	
	return 0;
}
