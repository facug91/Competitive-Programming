/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5215
        Name: At most twice
        Date: 16/11/2015
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

ll u;
int n[20], len, m[20], ans[20], used[10];

bool check () {
	for (int i=0; i<10; i++) if (used[i] > 2) return false;
	return true;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k, l;
	
	while (cin>>u) {
		memset(n, 0, sizeof n);
		len = 0;
		memset(used, 0, sizeof used);
		while (u) {
			n[len++] = u%10;
			used[u%10]++;
			u /= 10;
		}
		if (check()) {
			for (i=len-1; i>=0; i--) cout<<n[i];
			cout<<endl;
		} else {
			for (i=0; i<len; i++) if (n[i]) {
				bool keep = true;
				for (l=1; l<=n[i]; l++) {
					memset(used, 0, sizeof used);
					for (j=i+1; j<len; j++) {
						m[j] = n[j];
						used[m[j]]++;
					}
					m[i] = n[i]-l;
					used[m[i]]++;
					for (j=i-1; j>=0; j--) {
						for (k=9; k>=0; k--) {
							if (used[k] < 2) {
								m[j] = k;
								used[k]++;
								break;
							}
						}
						if (k == -1) used[0]++;
					}
					if (check()) {
						for (j=0; j<len; j++) ans[j] = m[j];
						keep = false;
						break;
					}
				}
				if (!keep) break;
			}
			if (ans[len-1] == 0) len--;
			for (i=len-1; i>=0; i--) cout<<ans[i];
			cout<<endl;
		}
	}
	
	return 0;
}
