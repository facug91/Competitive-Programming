/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1053
	Name: Higher Math
	Number: 1053
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
 
bool check (tint a, tint b, tint c) {
    if ((a + b == c) || (a + c == b) || (b + c == a)) return true;
    return false;
}
 
int main() {
   
    int t, i;
    int a, b, c;
   
    scanf("%d", &t);
   
    for (i=1; i<=t; i++) {
       
        scanf("%d %d %d", &a, &b, &c);
       
        a *= a;
        b *= b;
        c *= c;
       
        if (check(a, b, c)) printf("Case %d: yes\n", i);
        else printf("Case %d: no\n", i);
       
    }
   
    return 0;
}
