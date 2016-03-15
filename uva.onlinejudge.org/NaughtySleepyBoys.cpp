/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1368
        Name: Naughty Sleepy Boys
        Date: 03/03/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, aux;
vi arr;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n) {
		int p10 = 1, cnt = 1;
		for (; 9*p10*cnt<n; p10 *= 10, cnt++) n -= 9*p10*cnt;
		aux = p10 + n / cnt;
		if (n % cnt == 0) {
			aux--;
			n = cnt;
		} else n %= cnt;
		arr.clear();
		while (aux) {
			arr.push_back(aux%10);
			aux /= 10;
		}
		cout<<arr[arr.size()-n]<<endl;
	}
	
	return 0;
}
