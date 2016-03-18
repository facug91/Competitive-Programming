/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4534
        Name: Languages
        Date: 17/03/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

struct node {
	int word_idx;
	unordered_map<char, int> next;
	node () {word_idx = -1;}
};

int n, size, ans;
string lang[105], line, word;
node trie[25605];
stringstream ss;

inline void trie_insert (string& word, int word_idx) {
	int idx = 0;
	for (int i=0; i<word.length(); i++) {
		if (trie[idx].next.find(word[i]) == trie[idx].next.end()) trie[idx].next[word[i]] = size++;
		idx = trie[idx].next[word[i]];
	}
	trie[idx].word_idx = word_idx;
}

inline int find (string& word) {
	int idx = 0;
	for (int i=0; i<word.length(); i++) {
		if (trie[idx].next.find(word[i]) == trie[idx].next.end()) return -1;
		idx = trie[idx].next[word[i]];
	}
	return trie[idx].word_idx;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>n;
	size = 1;
	for (i=0; i<n; i++) {
		cin>>lang[i];
		getline(cin, line);
		for (j=0; j<line.length(); j++) line[j] = tolower(line[j]);
		ss.clear();
		ss.str(line);
		while (ss>>word) trie_insert(word, i);
	}
	getline(cin, line);
	while (getline(cin, line)) {
		for (i=0; i<line.length(); i++) 
			if (line[i] == '.' || line[i] == ',' || line[i] == '!' || line[i] == '?' || line[i] == ';' ||
				line[i] =='(' || line[i] == ')') line[i] = ' ';
			else line[i] = tolower(line[i]);
		ss.clear();
		ss.str(line);
		while (ss>>word) {
			ans = find(word);
			if (ans != -1) {
				cout<<lang[ans]<<endl;
				break;
			}
		}
	}
	
	return 0;
}
