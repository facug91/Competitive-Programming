/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1224
        Name: DNA Prefix
        Date: 30/12/2014
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

int index_of (char c) {
	switch (c) {
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
	}
}

struct node {
	int prefixes;
	int next[4];
	node () {
		prefixes = 0;
		for (int i=0; i<4; i++)
			next[i] = -1;
	}
};

int n;
string s;
vector<node> trie;

void insert (int idx, string s) {
	trie[idx].prefixes++;
	if (s.length() == 0) return;
	if (trie[idx].next[index_of(s[0])] == -1) {
		trie.push_back(node());
		trie[idx].next[index_of(s[0])] = trie.size() - 1;
	}
	insert(trie[idx].next[index_of(s[0])], s.substr(1, s.length()-1));
}

int solve (int idx, int h) {
	int ans = h * trie[idx].prefixes;
	for (int i=0; i<4; i++)
		if (trie[idx].next[i] != -1)
			ans = max(ans, solve(trie[idx].next[i], h+1));
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		trie.clear();
		trie.push_back(node());
		for (i=0; i<n; i++) {
			cin>>s;
			insert(0, s);
		}
		cout<<"Case "<<it<<": "<<solve(0, 0)<<endl;
	}
	
	return 0;
}
