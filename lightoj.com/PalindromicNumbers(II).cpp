/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1225
	Name: Palindromic Numbers (II)
	Number: 1225
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
 
char s[15];
 
bool check () {
    int i, j;
   
    i = 0;
    j = strlen(s)-1;
   
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
   
    return true;
   
}
 
int main() {
   
    int t, i;
   
    scanf("%d", &t);
   
    for (i=1; i<=t; i++) {
       
        scanf("%14s", s);
       
        if (check()) printf("Case %d: Yes\n", i);
        else printf("Case %d: No\n", i);
       
    }
   
    return 0;
}
