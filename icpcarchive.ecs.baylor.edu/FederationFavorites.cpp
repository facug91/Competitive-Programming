/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622&page=show_problem&problem=4528
        Name: Federation Favorites
        Date: 18/08/2015
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;

int n, sum;
vector<int> divs, div1, div2;

void calc_div () {
	div1.clear();
	div2.clear();
	div1.push_back(1);
	div2.push_back(n);
	int i = 2;
	while (i*i <= n) {
		if (n % i == 0) {
			div1.push_back(i);
			div2.push_back(n/i);
		}
		i++;
	}
	if (div1.back() == div2.back()) div2.pop_back();
	divs.clear();
	for (int i=0; i<div1.size(); i++) divs.push_back(div1[i]);
	for (int i=(int)div2.size()-1; i>0; i--) divs.push_back(div2[i]);
}

int main(){
	int i, j;
	
	while (cin>>n, n != -1) {
		calc_div();
		sum = 0;
		for (i=0; i<divs.size(); i++) sum += divs[i];
		if (sum != n) cout<<n<<" is NOT perfect.\n";
		else {
			cout<<n<<" = "<<divs[0];
			for (i=1; i<divs.size(); i++) cout<<" + "<<divs[i];
			cout<<"\n";
		}
	}
	
	
}

