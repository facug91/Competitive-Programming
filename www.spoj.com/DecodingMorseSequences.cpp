/*
        By: facug91
        From: http://www.spoj.com/problems/MORSE/
        Name: Decoding Morse Sequences
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
	int words;
	map<char, int> next;
	node () {
		prefixes = 0;
		words = 0;
		next['-'] = -1;
		next['.'] = -1;
	}
};

int n, size, DP[10005];
string morse, s;
node trie[1000005];
map<char, string> morse_code;

void init () {
	morse_code['A'] = ".-";
	morse_code['B'] = "-...";
	morse_code['C'] = "-.-.";
	morse_code['D'] = "-..";
	morse_code['E'] = ".";
	morse_code['F'] = "..-.";
	morse_code['G'] = "--.";
	morse_code['H'] = "....";
	morse_code['I'] = "..";
	morse_code['J'] = ".---";
	morse_code['K'] = "-.-";
	morse_code['L'] = ".-..";
	morse_code['M'] = "--";
	morse_code['N'] = "-.";
	morse_code['O'] = "---";
	morse_code['P'] = ".--.";
	morse_code['Q'] = "--.-";
	morse_code['R'] = ".-.";
	morse_code['S'] = "...";
	morse_code['T'] = "-";
	morse_code['U'] = "..-";
	morse_code['V'] = "...-";
	morse_code['W'] = ".--";
	morse_code['X'] = "-..-";
	morse_code['Y'] = "-.--";
	morse_code['Z'] = "--..";
}

string to_morse (string s) {
	string ans = "";
	for (int i=0; i<s.length(); i++)
		ans += morse_code[s[i]];
	return ans;
}

void insert (int idx, const string &s, int first) {
	trie[idx].prefixes++;
	if (first == s.length()) {
		trie[idx].words++;
		return;
	}
	if (trie[idx].next[s[first]] == -1) {
		trie[idx].next[s[first]] = size;
		trie[size++] = node();
	}
	insert(trie[idx].next[s[first]], s, first+1);
}

int dp (int idx);

int query (int idx, int first) {
	if (first == morse.length()) {
		if (trie[idx].words > 0) return trie[idx].words;
		else return 0;
	}
	int ans = 0;
	if (trie[idx].words > 0) ans += (dp(first) * trie[idx].words);
	if (trie[idx].next[morse[first]] == -1) return ans;
	else return ans + query(trie[idx].next[morse[first]], first+1);
}

int dp (int idx) {
	if (DP[idx] != -1) return DP[idx];
	return DP[idx] = query(0, idx);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	
	cin>>TC;
	while (TC--) {
		trie[0] = node();
		size = 1;
		cin>>morse;
		cin>>n;
		while (n--) {
			cin>>s;
			insert(0, to_morse(s), 0);
		}
		memset(DP, -1, sizeof DP);
		cout<<dp(0)<<endl;
	}
	
	return 0;
}
