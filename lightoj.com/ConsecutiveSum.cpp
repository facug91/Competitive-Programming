/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1269
        Name: Consecutive Sum
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
	int next[2];
	node () {
		next[0] = -1;
		next[1] = -1;
	}
};

int n, x, size, pre, mx, mn;
node trie[1600005];
string bin, ini;

void to_binary (int x) {
	bin = "";
	while (x) {
		bin.push_back((x%2) + '0');
		x /= 2;
	}
	while (bin.size() < 32)
		bin.push_back('0');
	reverse(bin.begin(), bin.end());
}

void insert (int idx, string &s, int first) {
	if (first == 32) return;
	if (trie[idx].next[s[first]-'0'] == -1) {
		trie[idx].next[s[first]-'0'] = size;
		trie[size++] = node();
	}
	insert(trie[idx].next[s[first]-'0'], s, first+1);
}

int query_max (int idx, string &s, int first) {
	if (first == 32) return 0;
	int ans = -1;
	if (s[first] == '1' && trie[idx].next[0] != -1)
		ans = max((1<<(31 - first)) | query_max(trie[idx].next[0], s, first+1), ans);
	if (s[first] == '0' && trie[idx].next[1] != -1)
		ans = max((1<<(31 - first)) | query_max(trie[idx].next[1], s, first+1), ans);
	if (ans == -1) {
		if (trie[idx].next[0] != -1)
			ans = max(query_max(trie[idx].next[0], s, first+1), ans);
		if (trie[idx].next[1] != -1)
			ans = max(query_max(trie[idx].next[1], s, first+1), ans);
	}
	return ans;
}

int query_min (int idx, string s, int first) {
	if (first == 32) return 0;
	int ans = MAX_INT;
	if (s[first] == '0' && trie[idx].next[0] != -1)
			ans = min(query_min(trie[idx].next[0], s, first+1), ans);
	if (s[first] == '1' && trie[idx].next[1] != -1)
		ans = min(query_min(trie[idx].next[1], s, first+1), ans);
	
	if (ans == MAX_INT) {
		if (trie[idx].next[0] != -1)
			ans = min((1<<(31 - first)) | query_min(trie[idx].next[0], s, first+1), ans);
		if (trie[idx].next[1] != -1)
			ans = min((1<<(31 - first)) | query_min(trie[idx].next[1], s, first+1), ans);
	}
	return ans;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	ini = "";
	for (i=0; i<32; i++)
		ini += "0";
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		trie[0] = node();
		size = 1;
		insert(0, ini, 0);
		trie[0] = node();
		size = 1;
		insert(0, ini, 0);
		scanf("%d", &n);
		pre = 0;
		mx = -1; mn = MAX_INT;
		for (i=0; i<n; i++) {
			scanf("%d", &x);
			pre = pre ^ x;
			to_binary(pre);
			mx = max(mx, query_max(0, bin, 0));
			mn = min(mn, query_min(0, bin, 0));
			insert(0, bin, 0);
		}
		printf("Case %d: %d %d\n", it, mx, mn);
	}
	
	return 0;
}
