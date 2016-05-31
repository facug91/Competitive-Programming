/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=617&problem=4477&mosmsg=Submission+received+with+ID+1961515
	Name: Von Neumann's Fly
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

int dt;
double d, a, b, f;
 
bool collision (double t) {
    return d - (a*t+b*t) < EPS;
}
 
double binary_search () {
    double lo = 0.0, hi = 10000.0, mid;
    for (int i=0; i<100; i++) {
        mid = (lo+hi)/2.0;
        if (collision(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	cin>>tc;
    while (tc--) {
        cin>>dt>>d>>a>>b>>f;
        cout<<dt<<" "<<fixed<<setprecision(2)<<binary_search()*f<<endl;
    }
	
	return 0;
}
