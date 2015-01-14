/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1129
        Name: Consistency Checker
        Date: 28/12/2014
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

struct node {
	int prefixes;
	int words;
	int next[10];
	node () {
		prefixes = 0;
		words = 0;
		for (int i=0; i<10; i++)
			next[i] = -1;
	}
};

int n;
string s;
vector<node> trie;

void insert (int idx, string s) {
	if (s.length() == 0) {
		trie[idx].prefixes++;
		trie[idx].words++;
	} else {
		trie[idx].prefixes++;
		if (trie[idx].next[s[0]-'0'] == -1) {
			trie.push_back(node());
			trie[idx].next[s[0]-'0'] = trie.size()-1;
		}
		insert(trie[idx].next[s[0]-'0'], s.substr(1, s.length()-1));
	}
}

bool is_consistent (int idx) {
	if (trie[idx].words != 0) {
		for (int i=0; i<10; i++)
			if (trie[idx].next[i] != -1)
				return false;
		return true;
	} else {
		bool ans = true;
		for (int i=0; i<10; i++)
			if (trie[idx].next[i] != -1)
				ans = ans && is_consistent(trie[idx].next[i]);
		return ans;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		trie.clear();
		trie.push_back(node());
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>s;
			insert(0, s);
		}
		cout<<"Case "<<it<<": ";
		if (is_consistent(0)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
