/*
ID: facug911
LANG: C++
TASK: combo
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
ifstream fin ("combo.in"); //use fin to read
ofstream fout ("combo.out"); //use fout to write

int n, c[2][3], t[3];
set<pair<int, pair<int, int> > > ternas;

void dfs (int owner, int pos) {
	if (pos == 3) {
		ternas.insert(make_pair(t[0], make_pair(t[1], t[2])));
		return;
	}
	t[pos] = (c[owner][pos]+n-2)%n;
	dfs(owner,pos+1);
	t[pos] = (c[owner][pos]+n-1)%n;
	dfs(owner,pos+1);
	t[pos] = (c[owner][pos])%n;
	dfs(owner,pos+1);
	t[pos] = (c[owner][pos]+1)%n;
	dfs(owner,pos+1);
	t[pos] = (c[owner][pos]+2)%n;
	dfs(owner,pos+1);
}

int main () {
	int TC, i, j;
	
	fin>>n;
	fin>>c[0][0]>>c[0][1]>>c[0][2];
	fin>>c[1][0]>>c[1][1]>>c[1][2];
	
	dfs(0, 0);
	dfs(1, 0);
	
	fout<<ternas.size()<<endl;
	
	
	
	
	
	
	
	
	return 0;
}
