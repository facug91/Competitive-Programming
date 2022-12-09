/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622&page=show_problem&problem=4529
        Name: Generations of Tribbles
        Date: 18/08/2015
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;

unsigned long long t, n, DP[100];

int main(){
	DP[0] = 1ull;
	DP[1] = 1ull;
	DP[2] = 2ull;
	DP[3] = 4ull;
	for (int i=4; i<100; i++) DP[i] = DP[i-1] + DP[i-2] + DP[i-3] + DP[i-4];
	cin >> t;
	while (t--) {
		cin>>n;
		cout<<DP[n]<<endl;
	}
	
}

