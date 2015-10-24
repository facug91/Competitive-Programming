/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1365
        Name: Love Calculator
        Date: 24/10/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int a, b, tmp;
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(6); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	//cout << std::right << std::setw(13)
	int i, j;
	
	while (getline(cin, s)) {
		getline(cin, t);
		a = 0;
		for (i=0; i<s.length(); i++) {
			s[i] = tolower(s[i]);
			if (s[i] >= 'a' && s[i] <= 'z') a += (s[i]-'a'+1);
		}
		while (a > 9) {
			tmp = a; a = 0;
			while (tmp) {
				a += (tmp%10);
				tmp /= 10;
			}
		}
		b = 0;
		for (i=0; i<t.length(); i++) {
			t[i] = tolower(t[i]);
			if (t[i] >= 'a' && t[i] <= 'z') b += (t[i]-'a'+1);
		}
		while (b > 9) {
			tmp = b; b = 0;
			while (tmp) {
				b += (tmp%10);
				tmp /= 10;
			}
		}
		if (a > b) swap(a, b);
		cout<<(double)a*100.0/(double)b<<" %"<<endl;
	}
	
	return 0;
}
