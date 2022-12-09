/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2988
	Name: Abnormal 89's
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

string s, t;

vector<int> calculate_z (string& input) {
	vector<int> z(input.length(), 0);
	int left = 0;
	int right = 0;
	for (int k = 1; k < input.length(); k++) {
		if (k > right) {
			// it hasn't passed through a point like this
			left = right = k;
			while (right < input.length() && input[right] == input[right - left]) right++;
			z[k] = right - left;
			right--;
		} else {
			int k1 = k - left;
			if (z[k1] < right - k + 1) {
				// is the same answer as before
				z[k] = z[k1];
			} else {
				// it could be larger
				left = k;
				while (right < input.length() && input[right] == input[right - left]) right++;
				z[k] = right - left;
				right--;
			}
		}
	}
	return z;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>s;
		t = s;
		reverse(t.begin(), t.end());
		s = t + "$" + s + s;
		vector<int> z = calculate_z(s);
		bool alindrome = false;
		for (i=t.length()+2; i<t.length()+1+t.length(); i++) if (z[i] == t.length()) {
			alindrome = true;
			break;
		}
		if (alindrome) cout<<"alindrome"<<endl;
		else if (z[t.length()+1] == t.length()) cout<<"palindrome"<<endl;
		else cout<<"simple"<<endl;
	}
	
	return 0;
}
