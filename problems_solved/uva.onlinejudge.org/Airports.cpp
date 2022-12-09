/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=673&page=show_problem&problem=2833
        Name: Airports
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

int n, m, a, u, v, w, cost, number_ot_sets, p[10005];
vector<pair<int, ii> > edges;

int find_set (int i) {
	return ((i == p[i]) ? i : (p[i] = find_set(p[i])));
}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[y] = x;
		number_ot_sets--;
		cost += w;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m>>a;
		edges.clear();
		while (m--) {
			cin>>u>>v>>w; u--; v--;
			edges.push_back(MP(w, MP(u, v)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i;
		number_ot_sets = n;
		cost = 0;
		for (i=0; i<edges.size() && edges[i].first < a; i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		cout<<"Case #"<<it<<": "<<cost+number_ot_sets*a<<" "<<number_ot_sets<<endl;
	}
	
	return 0;
}
