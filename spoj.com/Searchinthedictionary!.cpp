/*
        By: facug91
        From: http://www.spoj.com/problems/DICT/
        Name: Search in the dictionary!
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
	bool word;
	int next[30];
	node () {
		word = false;
		memset(next, -1, sizeof next);
	}
};

int n, k, size;
char s[50];
node trie[700005];

void insert (int idx, char s[], int f, int len) {
	if (f == len) {
		trie[idx].word = true;
	} else {
		if (trie[idx].next[s[f]-'a'] == -1) {
			trie[idx].next[s[f]-'a'] = size;
			trie[size++] = node();
		}
		insert(trie[idx].next[s[f]-'a'], s, f+1, len);
	}
}

void print (int idx, char s[], int len) {
	if (trie[idx].word == true) {
		s[len] = '\0';
		printf("\n%s\n", s);
	}
	for (char i='a'; i<='z'; i++) {
		if (trie[idx].next[i-'a'] != -1) {
			s[len] = i;
			print(trie[idx].next[i-'a'], s, len+1);
		}
	}
}

void find_prefix (int idx, char s[], int f, int len) {
	if (f == len) {
		for (char i='a'; i<='z'; i++) {
			if (trie[idx].next[i-'a'] != -1) {
				s[len] = i;
				print(trie[idx].next[i-'a'], s, len+1);
			}
		}
	} else {
		if (trie[idx].next[s[f]-'a'] == -1) printf("\nNo match.\n");
		else find_prefix(trie[idx].next[s[f]-'a'], s, f+1, len);
	}
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &n);
	trie[0] = node();
	size = 1;
	while (n--) {
		scanf("%s", s);
		insert(0, s, 0, strlen(s));
	}
	
	scanf("%d", &k);
	bool first = true;
	for (i=1; i<=k; i++) {
		if (first) first = false;
		else printf("\n");
		printf("Case #%d:\n", i);
		scanf("%s", s);
		find_prefix(0, s, 0, strlen(s));
	}
	
	return 0;
}
