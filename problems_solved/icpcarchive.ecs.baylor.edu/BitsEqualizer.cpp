/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4163
        Name: Bits Equalizer
        Date: 16/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n;
string s, t;

int main () {
	int TC, i, j, k;
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>s>>t;
		cout<<"Case "<<it<<": ";
		if (s.length() != t.length()) cout<<"-1\n";
		else {
			int z[2];
			z[0] = z[1] = 0;
			for (i=0; i<s.length(); i++) {
				if (s[i] == '0' || s[i] == '?') z[0]++;
				if (t[i] == '0') z[1]++;
			}
			if (z[0] < z[1]) {
				cout<<"-1\n";
				continue;
			}
			int ans = 0;
			for (i=0; i<s.length(); i++) {
				if (s[i] == '1' && t[i] == '0') {
					for (j=0; j<s.length(); j++) if (i != j) {
						if (s[j] == '0' && t[j] == '1') {
							s[i] = '0';
							s[j] = '1';
							break;
						}
					}
					ans++;
				}
			}
			for (i=0; i<s.length(); i++) {
				if (s[i] == '0' && t[i] == '1') ans++;
			}
			for (i=0; i<s.length(); i++) {
				if (s[i] == '?') ans++;
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
