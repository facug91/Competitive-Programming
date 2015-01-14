/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2524
        Name: Folding Machine
        Date: 27/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000ll
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, x;
vector<int> w;
set<vector<int> > DP;

bool is_equal(vector<int> &v) {
	
	if (v.size() != w.size()) return false;
	
	bool equal = true; int i;
	for (i=0; i<(int)v.size(); i++)
		equal = equal && (v[i] == w[i]);
	if (equal) return true;
	
	equal = true;
	for (i=0; i<(int)v.size(); i++)
		equal = equal && (v[(int)v.size()-i-1] == w[i]);
	return equal;
}

bool dp (vector<int> v) {
	if (DP.find(v) != DP.end()) return false;
	if (is_equal(v)) return true;
	if (v.size() > w.size()) {
		vector<int> aux;
		int i, j, k;
		for (i=1; i<(int)v.size(); i++) {
			aux.clear();
			for (j=i; j<(int)v.size(); j++)
				aux.push_back(v[j]);
			for (j=i-1, k=0; j>=0; j--, k++) {
				if (aux.size() == k) aux.push_back(0);
				aux[k] += v[j];
			}
			if (dp(aux)) return true;
		}
	}
	DP.insert(v);
	return false;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n) {
		
		vector<int> v;
		for (i=0; i<n; i++) {
			cin>>x;
			v.push_back(x);
		}
		
		cin>>m;
		w.clear();
		for (i=0; i<m; i++) {
			cin>>x;
			w.push_back(x);
		}
		
		DP.clear();
		if (dp(v)) cout<<"S"<<endl;
		else cout<<"N"<<endl;
	}
	
	return 0;
}
