/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2153
        Name: Editing a Book
        Date: 31/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, p, N;
vector<int> book, dest;

int solve () {
	queue<vector<int> > q1, q2;
	set<vector<int> > book1, book2;
	set<vector<int> >::iterator itr;
	pair<set<vector<int> >::iterator, bool> ret;
	
	if (book == dest) return 0;
	book1.insert(book);
	book2.insert(dest);
	q1.push(book);
	q2.push(dest);
	
	int l1 = 1, l2 = 1, i, j, k, l, m, size;
	vector<int> act, aux;
	while (true) {
		size = (int)q1.size();
		book1.clear();
		for (l=0; l<size; l++) {
			act = q1.front();
			q1.pop();
			for (i=1; i<n; i++) {
				for (j=0; j<(n+1-i); j++) {
					for (k=j+i+1; k<=n; k++) {
						aux.clear();
						for (m=0; m<j; m++)
							aux.push_back(act[m]);
						for (m=j+i; m<k; m++)
							aux.push_back(act[m]);
						for (m=j; m<j+i; m++)
							aux.push_back(act[m]);
						for (m=k; m<n; m++)
							aux.push_back(act[m]);
						ret = book1.insert(aux);
						if (ret.second) {
							itr = book2.find(aux);
							if (itr == book2.end()) {
								q1.push(aux);
							} else {
								return l1+l2-1;
							}
						}
					}
				}
			}
		}
		l1++;
		
		size = (int)q2.size();
		book2.clear();
		for (l=0; l<size; l++) {
			act = q2.front();
			q2.pop();
			for (i=1; i<n; i++) {
				for (j=0; j<(n+1-i); j++) {
					for (k=j+i+1; k<=n; k++) {
						aux.clear();
						for (m=0; m<j; m++)
							aux.push_back(act[m]);
						for (m=j+i; m<k; m++)
							aux.push_back(act[m]);
						for (m=j; m<j+i; m++)
							aux.push_back(act[m]);
						for (m=k; m<n; m++)
							aux.push_back(act[m]);
						ret = book2.insert(aux);
						if (ret.second) {
							itr = book1.find(aux);
							if (itr == book1.end()) {
								q2.push(aux);
							} else {
								return l2+l1-1;
							}
						}
					}
				}
			}
		}
		l2++;
	}
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (scanf("%d", &n), n) {
		book.clear();
		dest.clear();
		for (i=0; i<n; i++) {
			scanf("%d", &p);
			book.push_back(p-1);
			dest.push_back(i);
		}
		printf("Case %d: %d\n", TC++, solve());
	}
	
	return 0;
}
