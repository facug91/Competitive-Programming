/*
        By: facug91
        From: http://poj.org/problem?id=3318
        Name: Matrix Multiplication
        Date: 07/05/2015
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;
 
int n, a[505][505], b[505][505], c[505][505], d[505], e[505], f[505];
 
int main () {
        //ios_base::sync_with_stdio(0); cin.tie(0);
        //cout<<fixed<<setprecision(10); //cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
        int i, j, k;
       
        scanf("%d", &n);
        for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d", &a[i][j]);
        for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d", &b[i][j]);
        for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d", &c[i][j]);
        for (int it=0; it<5; it++) {
                for (i=0; i<n; i++) d[i] = rand()%2;
                for (i=0; i<n; i++) for (e[i]=j=0; j<n; j++) e[i] += (b[i][j] * d[j]);
                for (i=0; i<n; i++) for (f[i]=j=0; j<n; j++) f[i] += (a[i][j] * e[j]);
                for (i=0; i<n; i++) for (e[i]=j=0; j<n; j++) e[i] += (c[i][j] * d[j]);
                for (i=0; i<n; i++) if (f[i] != e[i]) {
                        printf("NO\n");
                        return 0;
                }
        }
        printf("YES\n");
       
        return 0;
}
