/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4908
	Name: Eureka Theorem
	Date: 28/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n;
vector<int> tn;
bool isGauss[1005];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k;
	
	for (i=1; i*(i+1) <= 2000; i++) tn.push_back(i*(i+1)/2);
	memset(isGauss, 0, sizeof isGauss);
	for (i=0; i<tn.size(); i++)
		for (j=i; j<tn.size(); j++)
			if (tn[i]+tn[j] < 1005)
				for (k=j; k<tn.size(); k++)
					if (tn[i]+tn[j]+tn[k] < 1005)
						isGauss[tn[i]+tn[j]+tn[k]] = true;
	cin>>tc;
	while (tc--) {
		cin>>n;
		cout<<isGauss[n]<<endl;
	}
	
	return 0;
}
