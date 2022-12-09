/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2215
        Name: Electricity
        Date: 15/10/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, d[1003], m[1003], y[1003], c[1003], cnt, sum;
int days_of_month[13];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k, tc;
	
	days_of_month[0] = 31;
	days_of_month[1] = 28;
	days_of_month[2] = 31;
	days_of_month[3] = 30;
	days_of_month[4] = 31;
	days_of_month[5] = 30;
	days_of_month[6] = 31;
	days_of_month[7] = 31;
	days_of_month[8] = 30;
	days_of_month[9] = 31;
	days_of_month[10] = 30;
	days_of_month[11] = 31;
	
	while (cin>>n, n) {
		cnt = sum = 0;
		for (i=0; i<n; i++) cin>>d[i]>>m[i]>>y[i]>>c[i], m[i]--;
		for (i=1; i<n; i++) {
			j = i-1;
			if (y[j] == y[i]) {
				if (m[j] == m[i]) {
					if (d[j]+1 == d[i]) {
						cnt++;
						sum += c[i]-c[j];
					}
				} else if (m[j]+1 == m[i]) {
					if (d[i] == 1) {
						if (y[i] % 4 == 0 && y[i] != 1900 && y[i] != 2100) {
							if (m[j] == 1) {
								if (d[j] == 29) {
									cnt++;
									sum += c[i]-c[j];
								}
							} else if (days_of_month[m[j]] == d[j]) {
								cnt++;
								sum += c[i]-c[j];
							}
						} else if (days_of_month[m[j]] == d[j]) {
							cnt++;
							sum += c[i]-c[j];
						}
					}
				}
			} else if (y[j]+1 == y[i]) {
				if (m[j] == 11 && m[i] == 0 && d[i] == 1 && d[j] == 31) {
					cnt++;
					sum += c[i]-c[j];
				}
			}
		}
		cout<<cnt<<" "<<sum<<endl;
	}
	
	return 0;
}
