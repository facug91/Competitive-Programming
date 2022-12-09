/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3160&cid=1453
        Name: Pile of Cards
        Date: 06/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000007
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, cont[2];
string p1, p2, ans;
bool vis[1005][1005];

bool dfs (int i, int j) {
	//cerr<<"i "<<i<<" j "<<j<<" ans "<<ans<<" cont ["<<cont[0]<<", "<<cont[1]<<"]"<<endl;
	if (i == p1.length() && j == p2.length()) return true;
	if (!vis[i][j]) {
		vis[i][j] = true;
		if (i < p1.length()) {
			int act = p1[i]-'0';
			if (cont[act] <= cont[act^1]) {
				ans.push_back('1');
				cont[act]++;
				if (dfs(i+1, j)) return true;
				cont[act]--;
				ans.pop_back();
			}
		}
		if (j < p2.length()) {
			int act = p2[j]-'0';
			if (cont[act] <= cont[act^1]) {
				ans.push_back('2');
				cont[act]++;
				if (dfs(i, j+1)) return true;
				cont[act]--;
				ans.pop_back();
			}
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(9); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	cin>>n;
	cin>>p1;
	cin>>p2;
	dfs(0, 0);
	cout<<ans<<"\n";
	
	return 0;
}
