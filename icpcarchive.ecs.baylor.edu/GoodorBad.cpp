/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3900
        Name: Good or Bad?
        Date: 18/03/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int b, g;
string line;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	cin.ignore();
	while (tc--) {
		b = g = 0;
		getline(cin, line);
		for (i=0; i<line.length(); i++) {
			if (tolower(line[i]) == 'b') b++; 
			else if (tolower(line[i]) == 'g') g++;
		}
		if (b == g) cout<<line<<" is NEUTRAL"<<endl;
		else if (b > g) cout<<line<<" is A BADDY"<<endl;
		else cout<<line<<" is GOOD"<<endl;
	}
	
	return 0;
}
