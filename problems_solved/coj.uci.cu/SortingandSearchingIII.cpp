/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3069
        Name: Sorting and Searching III
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define count akjdhasjkldasl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

struct node {
	int hash, age;
	char sex, code[10];
};

int n, q1, q2, a, h;
node seq[100005];
char c[10];
map<int, int> count;


int hash_function (char s[]) {
	int ans = 0, len = strlen(s);
	for (int i=0; i<6; i++) ans = ans*27 + ((len>i)?(s[i]-'A'+1):0);
	//printf("%s %d\n", s, ans);
	return ans;
}

struct cmp {
	bool operator () (const node &n1, const node &n2) {
		return n1.hash < n2.hash;
	}
};

int main () {
	//ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%s : %d : %c : ", seq[i].code, &seq[i].age, &seq[i].sex);
		seq[i].hash = hash_function(seq[i].code);
		if (count.find(seq[i].hash) != count.end()) count[seq[i].hash]++;
		else count[seq[i].hash] = 1;
	}
	scanf("%d %d", &q1, &q2);
	for (i=0; i<q1; i++) {
		scanf("%s", c);
		h = hash_function(c);
		if (count.find(h) != count.end()) printf("%d\n", count[h]);
		else printf("0\n");
	}
	stable_sort(seq, seq+n, cmp());
	for (i=0; i<q2; i++) {
		scanf("%d", &a);
		printf("%s : %d : %c\n", seq[a-1].code, seq[a-1].age, seq[a-1].sex);
	}
	
	return 0;
}
