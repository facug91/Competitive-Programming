/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=292
        Name: Square Pegs And Round Holes
        Date: 11/02/2016
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
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, parcially, completed, corners, r2;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	bool first = true;
	while (cin>>n) {
		if (first) first = false;
		else cout<<endl;
		parcially = completed = 0;
		r2 = (2*n-1)*(2*n-1);
		for (i=0; i<n; i++) for (j=0; j<n; j++) {
			corners = (((i-n)*(i-n)+(j-n)*(j-n))*4 <= r2) 
					+ (((i+1-n)*(i+1-n)+(j-n)*(j-n))*4 <= r2)
					+ (((i-n)*(i-n)+(j+1-n)*(j+1-n))*4 <= r2)
					+ (((i+1-n)*(i+1-n)+(j+1-n)*(j+1-n))*4 <= r2);
			if (corners == 4) completed++;
			else if (corners > 0) parcially++;
		}
		cout<<"In the case n = "<<n<<", "<<parcially*4<<" cells contain segments of the circle."<<endl;
		cout<<"There are "<<completed*4<<" cells completely contained in the circle."<<endl;
	}
	
	return 0;
}
