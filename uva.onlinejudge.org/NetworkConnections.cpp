/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734
        Name: Network Connections
        Number: 793
        Date: 15/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, c1, c2, s, u;
char *op = new char[5], line[25];
vector<int> p, rank;

int find_set (int i) {
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}
void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		getchar();
		rank.clear();
		rank.assign(n+5, 0);
		p.clear();
		p.assign(n+5, 0);
		for (i=0; i<n+5; i++)
			p[i] = i;
		s = u = 0;
		
		while (gets(line)) {
			if (line[0] != 'q' && line[0] != 'c') break;
			op = strtok(line, " ");
			c1 = atoi(strtok(NULL, " "));
			c2 = atoi(strtok(NULL, " "));
			if (op[0] == 'c') {
				union_set(c1, c2);
			} else {
				if (find_set(c1) == find_set(c2)) s++;
				else u++;
			}
		}
		
		cout<<s<<","<<u<<endl;
		if (TC) cout<<endl;
	}
	
	return 0;
}
