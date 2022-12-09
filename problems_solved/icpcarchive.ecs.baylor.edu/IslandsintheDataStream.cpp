/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4476
	Name: Islands in the Data Stream
	Date: 23/05/2016
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
#define MOD 100000007
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int dt, a[20], ans;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	cin>>tc;
    while (tc--) {
        cin>>dt;
        for (i=0; i<15; i++) cin>>a[i];
        ans = 0;
        for (i=1; i<14; i++) for (j=i; j<14; j++) {
            bool isl = true;
            for (k=i; k<=j; k++) if (a[k] <= a[i-1] || a[k] <= a[j+1]) isl = false;
            if (isl) ans++;
        }
        cout<<dt<<" "<<ans<<endl;
    }
	
	return 0;
}
