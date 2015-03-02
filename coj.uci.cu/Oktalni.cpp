/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3125
        Name: Oktalni
        Date: 02/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int ans;
string s, aux;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>s;
	while (s.length() % 3 != 0) s = "0" + s;
	for (i=0; i<s.length(); i+=3) {
		aux = s.substr(i, 3);
		if (aux == "000") cout<<"0";
		if (aux == "001") cout<<"1";
		if (aux == "010") cout<<"2";
		if (aux == "011") cout<<"3";
		if (aux == "100") cout<<"4";
		if (aux == "101") cout<<"5";
		if (aux == "110") cout<<"6";
		if (aux == "111") cout<<"7";
	}
	cout<<endl;
	
	return 0;
}
