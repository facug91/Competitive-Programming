/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1182
	Name: Parity
	Number: 1182
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
 
 
 
int main() {
   
    unsigned int t, n, i, j, cont;
   
    cin>>t;
   
    for (i=1; i<=t; i++) {
       
        cin>>n;
       
        cont = 0;
       
        for (j=0; j<32; j++) {
            if (n & 1) cont++;
            n >>= 1;
        }
       
        if (cont & 1)
            cout<<"Case "<<i<<": odd"<<endl;
        else
            cout<<"Case "<<i<<": even"<<endl;
    }
   
    return 0;
}
