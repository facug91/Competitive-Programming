/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2683
        Name: XOR Sum
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

int n, x, size, pre, ans;
node trie[3500005];
string bin;

void to_binary (int n) {
	bin = "";
	while (n) {
		bin.push_back((n%2)+'0');
		n /= 2;
	}
	while (bin.length() < 32)
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

int query (int idx, string &s, int first) {
	if (first == 32) return 0;
	int ans = -1;
	if (s[first] == '0' && trie[idx].next[1] != -1)
		ans = max((1<<(31-first)) | query(trie[idx].next[1], s, first+1), ans);
	if (s[first] == '1' && trie[idx].next[0] != -1)
		ans = max((1<<(31-first)) | query(trie[idx].next[0], s, first+1), ans);
	if (ans == -1) {
		if (trie[idx].next[1] != -1)
			ans = max(query(trie[idx].next[1], s, first+1), ans);
		if (trie[idx].next[0] != -1)
			ans = max(query(trie[idx].next[0], s, first+1), ans);
	}
	return ans;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	string zero = "00000000000000000000000000000000"; //32 0s bits
	
	scanf("%d", &TC);
	while (TC--) {
		trie[0] = node();
		size = 1;
		insert(0, zero, 0);
		scanf("%d", &n);
		pre = 0; ans = -1;
		while (n--) {
			scanf("%d", &x);
			pre ^= x;
			to_binary(pre);
			ans = max(ans, query(0, bin, 0));
			insert(0, bin, 0);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
