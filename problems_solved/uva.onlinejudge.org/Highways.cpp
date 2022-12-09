/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1088
        Name: Highways
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

int n, m, x, y, u, v, p[755];
vector<pair<ll, ll> > coor;
vii ans;
vector<pair<ll, ii> > edges;

int find_set (int i) {
	return (i == p[i] ? i : (p[i] = find_set(p[i])));
}

void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[x] = y;
		ans.push_back(MP(i, j));
	}
}

ll dist (int i, int j) {
	return (coor[i].first-coor[j].first)*(coor[i].first-coor[j].first)+(coor[i].second-coor[j].second)*(coor[i].second-coor[j].second);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		coor.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			coor.push_back(MP(x, y));
		}
		edges.clear();
		for (i=0; i<n; i++) p[i] = i;
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) edges.push_back(MP(dist(i, j), MP(i, j)));
		sort(edges.begin(), edges.end());
		cin>>m;
		while (m--) {
			cin>>u>>v; u--; v--;
			union_set(u, v);
		}
		ans.clear();
		for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second);
		for (i=0; i<ans.size(); i++) cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
		if (ans.size() == 0) cout<<"No new highways need"<<endl;
		if (tc != 0) cout<<endl;
	}
	
	return 0;
}
