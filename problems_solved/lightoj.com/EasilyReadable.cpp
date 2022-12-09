/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1114
        Name: Easily Readable
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

int index_of (char c) {
	if (islower(c))	return c - 'a';
	else return c - 'A' + 26;
}

struct node {
	int words;
	int next[55];
	node () {
		words = 0;
		memset(next, -1, sizeof next);
	}
};

int n, m, size;
char s[100005];
node trie[100005];

void insert (int idx, string s) {
	if (s.length() == 0) {
		trie[idx].words++;
	} else {
		if (trie[idx].next[index_of(s[0])] == -1) {
			trie[idx].next[index_of(s[0])] = size;
			trie[size++] = node();
		}
		insert(trie[idx].next[index_of(s[0])], s.substr(1, s.length()-1));
	}
}

int find (int idx, string s) {
	if (s.length() == 0) return trie[idx].words;
	if (trie[idx].next[index_of(s[0])] == -1) return 0;
	return find(trie[idx].next[index_of(s[0])], s.substr(1, s.length()-1));
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		trie[0] = node();
		size = 1;
		scanf("%d", &n);
		for (i=0; i<n; i++) {
			scanf("%s", s);
			string str(s);
			if (str.length() > 2)
				sort(++str.begin(), --str.end());
			insert(0, str);
		}
		scanf("%d", &m);
		gets(s);
		printf("Case %d:\n", it);
		for (i=0; i<m; i++) {
			gets(s);
			string str(s);
			istringstream ss(str);
			int ans = 1;
			while (ss>>str) {
				if (str.length() < 101) {
					if (str.length() > 2)
						sort(++str.begin(), --str.end());
					ans *= find(0, str);
				}
			}
		printf("%d\n", ans);
		}
	}
	
	return 0;
}
