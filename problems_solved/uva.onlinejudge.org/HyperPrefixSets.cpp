/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2483
        Name: Hyper Prefix Sets
        Date: 31/12/2014
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
	int next[2];
	node () {
		prefixes = 0;
		next[0] = -1;
		next[1] = -1;
	}
};

int n, size;
node trie[10000005];
char s[250];

void insert (int idx, char s[], int f, int len) {
	trie[idx].prefixes++;
	if (f == len) return;
	if (trie[idx].next[s[f]-'0'] == -1) {
		trie[idx].next[s[f]-'0'] = size;
		trie[size++] = node();
	}
	insert(trie[idx].next[s[f]-'0'], s, f+1, len);
}

int solve (int idx, int d) {
	int ans = d * trie[idx].prefixes;
	if (trie[idx].next[0] != -1)
		ans = max(ans, solve(trie[idx].next[0], d+1));
	if (trie[idx].next[1] != -1)
		ans = max(ans, solve(trie[idx].next[1], d+1));
	return ans;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		trie[0] = node();
		size = 1;
		scanf("%d", &n);
		while (n--) {
			scanf("%s", s);
			insert(0, s, 0, strlen(s));
		}
		printf("%d\n", solve(0, 0));
	}
	
	return 0;
}
