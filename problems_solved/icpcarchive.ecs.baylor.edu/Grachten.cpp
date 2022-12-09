/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4639
        Name: Grachten
        Date: 01/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define clock asoudh219udhjdgausdhs9udy
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int ab, ac, bd, num, den, g;

int gcd (int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (cin>>ab>>ac>>bd) {
		num = ac * ab;
		den = bd - ac;
		g = gcd(num, den);
		num /= g;
		den /= g;
		cout<<num<<"/"<<den<<"\n";
	}
	
	return 0;
}
