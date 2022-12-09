/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1354
	Name: IP Checking
	Number: 1354
	Date: 08/02/2014
*/

#include <iostream>
#include <cstdio>
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
 
#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;
 
using namespace std;
 
unsigned int d[4], b[4];
 
bool check () {
 
    int i, j;
   
    for (i=0; i<4; i++) {
        for (j=0; j<8; j++) {
            if ((((d[i] & 1) == 1) && ((b[i] % 10) == 0)) || (((d[i] & 1) == 0) && ((b[i] % 10) == 1))) return false;
            d[i] >>= 1;
            b[i] /= 10;
        }
    }
   
    return true;
   
}
 
int main() {
   
    int t, i;
   
    scanf("%d", &t);
   
    for (i=1; i<=t; i++) {
       
        scanf("%d.%d.%d.%d", &d[0], &d[1], &d[2], &d[3]);
        scanf("%d.%d.%d.%d", &b[0], &b[1], &b[2], &b[3]);
       
        if (check()) printf("Case %d: Yes\n", i);
        else printf("Case %d: No\n", i);
       
    }
   
    return 0;
}
