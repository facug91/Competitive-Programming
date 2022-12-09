/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2844
        Name: Word Searching
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int b[25], n, m;
string p, t, aux;

void kmp_preprocess () {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[i] != p[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

int kmp_search () {
	int i = 0, j = 0, ans = 0;
	while (i < n) {
		while (j >= 0 && t[i] != p[j]) j = b[j];
		i++; j++;
		if (j == m) {
			ans++;
			j = b[j];
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>p;
	t = "";
	while (getline(cin, aux)) t += aux;
	n = t.length(); m = p.length();
	kmp_preprocess();
	cout<<kmp_search()<<endl;
	
	return 0;
}
