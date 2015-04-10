/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=640&page=show_problem&problem=38
        Name: Ecological Bin Packing
        Date: 09/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int g[3][3], ans, aux;
map<int, char> l;
string ord, auxo;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' ');
	
	l[0] = 'B';
	l[1] = 'G';
	l[2] = 'C';
	while (cin>>g[0][0]>>g[0][1]>>g[0][2]) {
		for (int i=1; i<3; i++) for (int j=0; j<3; j++) cin>>g[i][j];
		ans = INT_MAX; ord = "ZZZ";
		for (int a=0; a<3; a++)	{
			for (int b=0; b<3; b++) if (a != b)	{
				for (int c=0; c<3; c++) if (c != a && c != b) {
					aux = 0;
					aux += g[1][a] + g[2][a];
					aux += g[0][b] + g[2][b];
					aux += g[0][c] + g[1][c];
					auxo = "";
					auxo += l[a];
					auxo += l[b];
					auxo += l[c];
					if (aux < ans || ((aux == ans) && (auxo.compare(ord) < 0))) {
						ans = aux;
						ord = auxo;
					}
				}
			}
		}
		cout<<ord<<" "<<ans<<"\n";		
	}
	
	return 0;
}
