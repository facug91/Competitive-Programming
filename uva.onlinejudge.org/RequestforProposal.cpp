/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1082
	Name: Request for Proposal
	Date: 16/11/2015
*/

#include <bits/stdc++.h>
#define next asjkdbg1238dv8ydf38gy832gf8yd
#define prev asjkdbuiqdg783gdiu3dg79832dui
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << "#" << (#x) << ": " << (x) << " "
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi; typedef vector<ii> vii;		   typedef vector<iii> viii;

int n, p;
pair<int, pair<double, string> > rfp[1005];
string line;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n>>p, n || p) {
		getline(cin, line);
		if (tc != 1) cout<<endl;
		for (i=0; i<n; i++) getline(cin, line);
		for (i=0; i<p; i++) {
			getline(cin, rfp[i].S.S);
			getline(cin, line);
			stringstream ss(line);
			ss>>rfp[i].S.F>>rfp[i].F;
			for (j=0; j<rfp[i].F; j++) getline(cin, line);
		}
		stable_sort(rfp, rfp+p);
		string com;
		double pri = DBL_MAX;
		int req = 0;
		for (i=0; i<p; i++) {
			if (rfp[i].F > req) {
				req = rfp[i].F;
				pri = rfp[i].S.F;
				com = rfp[i].S.S;
			} else  if (rfp[i].F == req) { 
				if (rfp[i].S.F < pri) {
					req = rfp[i].F;
					pri = rfp[i].S.F;
					com = rfp[i].S.S;
				}
			}
		}
		cout<<"RFP #"<<tc++<<endl;
		cout<<com<<endl;
	}
	   
	return 0;
}
