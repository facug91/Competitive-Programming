/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1072
	Name: Calm Down
	Number: 1072
	Date: 03/04/2014
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
//#include <bitset>
 
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;
 
#define INF 1000000000
#define maximo 16666670
 
using namespace std;
 
const long double PI = 2.0*acos(0.0);
 
int main() {
   
    int t, i;
    long double R, n, r, a, b, c;
   
    scanf("%d", &t);
   
    for (i=1; i<=t; i++) {
       
        scanf("%Lf %Lf", &R, &n);
       
        if (n > 2.0) {
            a = R;
            b = 2.0 * ((a / sin(PI-(PI/n)-(PI/2.0))) * sin(PI/n));
            c = (a / sin(PI-(PI/n)-(PI/2.0))) * sin(PI/2.0);
           
            r = b*a/(b+c+c);
           
            printf("Case %d: %.9Lf\n", i, r);
           
        } else {
            printf("Case %d: %.9Lf\n", i, R/2.0);
        }
       
    }
   
    return 0;
}
