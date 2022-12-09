/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=778
        Name: Light and Transparencies
        Date: 12/11/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
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

int n;
double x1, y1, x2, y2, r, act;
vector<pair<double, double> > endpoints;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	cin>>tc;
	while (tc--) {
		endpoints.clear();
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>x1>>y2>>x2>>y2>>r;
			if (x1 > x2) swap(x1, x2), swap(y1, y2);
			if (y1 < 0.0 && y2 < 0.0) continue;
			if (y1 < 0.0 || y2 < 0.0) {
				double a = -(y1-y2)/(x1-x2);
				double c = -(a * x1) - y1;
				if (y1 < 0.0) x1 = -c/a;
				else x2 = -c/a;
			}
			endpoints.push_back(MP(x1, r));
			endpoints.push_back(MP(x2, -r));
		}
		sort(endpoints.begin(), endpoints.end());
		act = 1.0;
		cout<<n*2+1<<endl;
		cout<<"-inf "<<endpoints[0].first<<" 1.000"<<endl;
		act *= endpoints[0].second;
		for (i=1; i<n*2; i++) {
			cout<<endpoints[i-1].first<<" "<<endpoints[i].first<<" "<<act<<endl;
			if (endpoints[i].second < 0.0) act /= -endpoints[i].second;
			else act *= endpoints[i].second;
		}
		cout<<endpoints.back().first<<" +inf 1.000"<<endl;
		if (tc) cout<<endl;
	}
	
	return 0;
}
