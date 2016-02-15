/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541
        Name: ACM Contest and Blackout
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

int n, m, u, v, w, ans, sum, p[105], number_of_sets;
vector<pair<int, ii> > edges;
vi used;

int find_set (int i) {
	return ((i == p[i]) ? i : (p[i] = find_set(p[i])));
}

bool union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[y] = x;
		sum += w;
		number_of_sets--;
		return true;
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		edges.clear();
		while (m--) {
			cin>>u>>v>>w; u--; v--;
			edges.push_back(MP(w, MP(u, v)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i;
		sum = 0;
		used.clear();
		for (i=0; i<edges.size(); i++) if (union_set(edges[i].second.first, edges[i].second.second, edges[i].first)) used.push_back(i);
		cout<<sum;
		ans = INT_MAX;
		for (j=0; j<used.size(); j++) {
			for (i=0; i<n; i++) p[i] = i;
			sum = 0; number_of_sets = n;
			for (i=0; i<edges.size(); i++) if (i != used[j]) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
			if (number_of_sets == 1) ans = min(ans, sum);
		}
		cout<<" "<<ans<<endl;
	}
	
	return 0;
}
