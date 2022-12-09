/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=120
        Name: Laser Lines
        Date: 12/02/2016
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

struct point {
	int x, y;
	point() {x = y = 0;}
	point(int x, int y) : x(x), y(y) {}
};

int n, x, y, num, den;
point p[305];
bool match[305][305];
vector<vector<ii> > ans;
map<ii, vector<int> > lines;

int gcd (int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>x>>y, x || y) {
		n = 1;
		p[0] = point(x, y);
		while (cin>>x>>y, x || y) p[n++] = point(x, y);
		for (i=0; i<n; i++) for (j=0; j<n; j++) match[i][j] = false;
		ans.clear();
		for (i=0; i<n; i++) {
			lines.clear();
			for (j=i+1; j<n; j++) if (!match[i][j]) {
				num = p[i].y-p[j].y;
				den = p[i].x-p[j].x;
				if (den == 0) {
					num = INT_MAX;
				} else if (num == 0) {
					den = 1;
				} else {
					int aux = gcd(abs(num), abs(den));
					num /= aux;
					den /= aux;
					if (den < 0) {
						num *= -1;
						den *= -1;
					}
				}
				lines[ii(num, den)].push_back(j);
			}
			for (pair<ii, vector<int> > line : lines) {
				if (line.S.size() > 1) {
					ans.push_back(vector<ii>());
					ans.back().push_back(ii(p[i].x, p[i].y));
					for (int po : line.S) {
						match[po][i] = match[i][po] = true;
						for (int pp : line.S) match[po][pp] = match[pp][po] = true;
						ans.back().push_back(ii(p[po].x, p[po].y));
					}
				}
			}
		}
		for (vector<ii>& line : ans) sort(line.begin(), line.end());
		sort(ans.begin(), ans.end());
		if (ans.size() > 0) {
			cout<<"The following lines were found:"<<endl;
			for (vector<ii> line : ans) {
				for (ii po : line) {
					cout<<"("<<right<<setw(4)<<po.F<<","<<right<<setw(4)<<po.S<<")";
				}
				cout<<endl;
			}
		} else cout<<"No lines were found"<<endl;
	}
	
	return 0;
}
