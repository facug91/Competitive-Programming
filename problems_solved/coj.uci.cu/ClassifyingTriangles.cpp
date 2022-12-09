/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2799
        Name: Classifying Triangles
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int a, b, c;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>a>>b>>c;
	if (a+b+c != 180 || a <= 0 || b <= 0 || c <= 0) cout<<"Error"<<endl;
	else if (a == b && a == c && b == c) cout<<"Equilateral"<<endl;
	else if (a == b || a == c || b == c) cout<<"Isosceles"<<endl;
	else cout<<"Scalene"<<endl;
	
	return 0;
}
