/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=167
        Name: Testing the CATCHER
        Number: 231
        Date: 28/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n;
vector<int> vec;
set<int> LIS;
set<int>::iterator itr;

int lis () {
	LIS.clear();
	for (int i=(int)vec.size()-1; i>=0; i--) {
		itr = LIS.lower_bound(vec[i]);
		if (itr == LIS.end()) LIS.insert(vec[i]);
		else if (*itr != vec[i]) {
			LIS.erase(itr);
			LIS.insert(vec[i]);
		}
	}
	return LIS.size();
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	bool first = true;
	
	while (cin>>n, n != -1) {
		if (first) first = false;
		else cout<<endl;
		vec.clear();
		vec.push_back(n);
		while (cin>>n, n != -1)
			vec.push_back(n);
		cout<<"Test #"<<TC++<<":"<<endl;
		cout<<"  maximum possible interceptions: "<<lis()<<endl;
	}
	
	return 0;
}

