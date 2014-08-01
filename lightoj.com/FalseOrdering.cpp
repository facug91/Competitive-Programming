/*
	By: facug91
	From:http://lightoj.com/volume_showproblem.php?problem=1109
	Name: False Ordering
	Number: 1109
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
 
struct cmp {
    bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};
 
vector<pair<int, int> > DP;
 
void dp () {
    int i, j;
   
    //inicialización
    for (i=0; i<1000; i++)
        DP.push_back(make_pair(1, i+1));
   
    //carga de datos
    for (i=1; i<1000; i++)
        for (j=i+i-1; j<1000; j+=i)
            DP[j].first++;
           
    sort(DP.begin(), DP.end(), cmp());
}
 
int main() {
   
    int t, n, i, j;
   
    dp();
   
    cin>>t;
   
    for (i=1; i<=t; i++) {
       
        cin>>n;
       
        cout<<"Case "<<i<<": "<<DP[--n].second<<endl;
       
    }
   
    return 0;
}
