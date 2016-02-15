/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1310
        Name: Arctic Network
        Date: 17/10/2015
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
//#define MAXN 1100000000000000ll
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int s, n, number_of_sets, p[505];
vector<pair<double, double> > coor;
vector<pair<double, ii> > edges;
double x, y, ans;

double dist (int i, int j) {
	return hypot(coor[i].first-coor[j].first, coor[i].second-coor[j].second);
}

int find_set (int i) {
	return ((i == p[i]) ? i : (p[i] = find_set(p[i])));
}

void union_set (int i, int j, double w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[y] = x;
		ans = w;
		number_of_sets--;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>s>>n;
		coor.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			coor.push_back(MP(x, y));
		}
		number_of_sets = n;
		ans = 0.0;
		edges.clear();
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) {
			edges.push_back(MP(dist(i, j), MP(i, j)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i;
		i = 0;
		while (number_of_sets > s) {
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
			i++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
