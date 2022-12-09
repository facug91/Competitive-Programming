/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1258
	Name: Making Huge Palindromes
	Date: 04/07/2016
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

int n;
string s;

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
	for (int it=1; it<=tc; it++) {
		cin>>s;
		n = s.length();
		string t = s;
		reverse(t.begin(), t.end());
		string aux = t + "$" + s;
		vector<int> z = calculate_z(aux);
		int ans = 0;
		for (i=n+1; i<n*2+1; i++) {
			if (z[i] == n*2+1-i) {
				ans = n*2+1-i;
				break;
			}
		}
		cout<<"Case "<<it<<": "<<n-ans+s.length()<<endl;
	}
	
	return 0;
}
