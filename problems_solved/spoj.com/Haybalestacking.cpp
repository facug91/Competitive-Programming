/*
        By: facug91
        From: http://www.spoj.com/problems/HAYBALE/
        Name: Haybale stacking
        Date: 3/09/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, k, l, r, arr[1000005], counting[25005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	memset(arr, 0, sizeof arr);
	cin>>n>>k;
	for (i=0; i<k; i++) {
		cin>>l>>r; l--; r--;
		arr[l]++; arr[r+1]--;
	}
	for (i=1; i<n; i++) arr[i] += arr[i-1];
	memset(counting, 0, sizeof counting);
	for (i=0; i<n; i++) counting[arr[i]]++;
	i = j = 0;
	while (true) {
		if (counting[j] != 0) {
			i += counting[j];
			if (i >= n/2+1) {
				cout<<j<<endl;
				break;
			}
		}
		j++;
	}
	
	return 0;
}
