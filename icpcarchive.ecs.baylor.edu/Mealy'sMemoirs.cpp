/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4421
        Name: Mealy's Memoirs
        Date: 13/02/2015
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
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int ans;
string s;
vector<int> ats, dots;

int main () {
	ios_base::sync_with_stdio(0);
	cout << fixed << setprecision(2);
	int TC, i, j, k;
	
	cin>>TC;
	getline(cin, s);
	while (TC--) {
		getline(cin, s);
		istringstream ss(s);
		ans = 0;
		while (ss>>s) {
			ats.clear(); dots.clear();
			for (i=3; i<(int)s.length()-5; i++) {
				if (s[i] == 'd' && s[i+1] == 'o' && s[i+2] == 't') {
					dots.push_back(i);
					i += 2;
					continue;
				}
				if (s[i] == 'a' && s[i+1] == 't') {
					ats.push_back(i);
					i++;
				}
			}
			i = j = k = 0; 
			while (j < ats.size() && k < dots.size()) {
				while (j < ats.size() && ats[j] - i < 3) j++;
				if (j < ats.size()) while (k < dots.size() && dots[k] - ats[j] < 5) k++;
				if (k < dots.size()) while (j < ats.size() && dots[k] - ats[j] > 18) j++;
				if (j < ats.size() && k < dots.size() && dots[k] - ats[j] >= 5) {
					ans++;
					i = dots[k] + 6;
					j++; k++;
				}
			}
		}
		cout<<"$"<<ans*1.28<<endl;
	}
	
	return 0;
}
