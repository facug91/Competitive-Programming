/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1112
	Name: Curious Robin Hood
	Number: 1112
	Date: 19/07/2014
	Using: Segment Tree
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

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const long double PI = 2*acos(0);

#define INF 1000000000

using namespace std;
 
int n, q, sake[100005], st[400005], op, id, jd;
 
int left (int p) {return p*2;}
int right (int p) {return p*2+1;}
void build_seg_tree (int p, int L, int R) {
    if (L == R) st[p] = sake[L];
    else {
        build_seg_tree(left(p), L, (L+R)/2);
        build_seg_tree(right(p), (L+R)/2+1, R);
        st[p] = st[left(p)] + st[right(p)];
    }
}
int update_point (int p, int L, int R, int idx, int new_value) {
    if (idx > R || idx < L)
        return st[p];
    if (L == idx && R == idx) {
        sake[idx] = new_value;
        return st[p] = new_value;
    }
    return st[p] = (update_point(left(p), L, (L+R)/2, idx, new_value) +
                   update_point(right(p), (L+R)/2+1, R, idx, new_value));
}
int rsq (int p, int L, int R, int i, int j) {
    if (i > R || j < L) return 0;
    if (L >= i && R <= j) return st[p];
   
    return rsq(left(p), L, (L+R)/2, i, j) +
           rsq(right(p), (L+R)/2+1, R, i, j);
}
 
int main() {
    int t, i, j;
   
    scanf("%d", &t);
   
    for (int it=1; it<=t; it++) {
        scanf("%d %d", &n, &q);
        for (i=0; i<n; i++)
            scanf("%d", sake+i);
        build_seg_tree(1, 0, n-1);
       
        printf("Case %d:\n", it);
        for (i=0; i<q; i++) {
            scanf("%d %d", &op, &id);
            if (op == 1) {
                printf("%d\n", sake[id]);
                update_point(1, 0, n-1, id, 0);
            } else if (op == 2) {
                scanf("%d", &jd);
                update_point(1, 0, n-1, id, sake[id]+jd);
            } else if (op == 3) {
                scanf("%d", &jd);
                printf("%d\n", rsq(1, 0, n-1, id, jd));
            }
        }
    }
   
    return 0;
}
