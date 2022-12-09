/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3950
        Name: Shortest Names
        Date: 01/01/2015
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

struct node {
	int prefixes;
	int next[30];
	node () {
		prefixes = 0;
		memset(next, -1, sizeof next);
	}
};

int n, size;
node trie[1000005];
string s;

void insert (int idx, string &s, int f) {
	trie[idx].prefixes++;
	if (f == s.length()) return;
	if (trie[idx].next[s[f]-'a'] == -1) {
		trie[idx].next[s[f]-'a'] = size;
		trie[size++] = node();
	}
	insert(trie[idx].next[s[f]-'a'], s, f+1);
}

int solve (int idx) {
	if (trie[idx].prefixes == 1) return 1;
	int ans = (idx == 0) ? 0 : trie[idx].prefixes;
	for (int i='a'; i<='z'; i++)
		if (trie[idx].next[i-'a'] != -1)
			ans += solve(trie[idx].next[i-'a']);
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		trie[0] = node();
		size = 1;
		cin>>n;
		while (n--) {
			cin>>s;
			insert(0, s, 0);
		}
		cout<<solve(0)<<endl;
	}
	
	return 0;
}
