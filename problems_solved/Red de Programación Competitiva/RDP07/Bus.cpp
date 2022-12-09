/*
        By: facug91
        From: https://acm.javeriana.edu.co/maratones/2015/07
        Name: Bus
        Date: 08/08/2015
*/

#include <bits/stdc++.h>

using namespace std;

int k;

int main() {
	int i, j, tc;
	
	cin>>tc;
	while (tc--) {
		cin>>k;
		int ans = 1;
		while (--k) ans = ans * 2 + 1;
		cout<<ans<<endl;
	}
	
}

