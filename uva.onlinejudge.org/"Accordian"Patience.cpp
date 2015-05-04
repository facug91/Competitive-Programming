/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=63
        Name: "Accordian" Patience
        Date: 14/04/2015
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

int ans;
string c;
vector<stack<string> > stk;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k;
	
	while (cin>>c, c[0] != '#') {
		stk.clear();
		for (i=0; i<52; i++) stk.push_back(stack<string>());
		stk[0].push(c);
		for (i=1; i<52; i++) cin>>c, stk[i].push(c);
		i = 1;
		while (i < stk.size()) {
			if (i - 3 >= 0 && (stk[i-3].top()[0] == stk[i].top()[0] || stk[i-3].top()[1] == stk[i].top()[1])) {
				stk[i-3].push(stk[i].top());
				stk[i].pop();
				if (stk[i].size() == 0) stk.erase(stk.begin()+i);
				i = i - 3;
				continue;
			}
			if (i > 0 && stk[i-1].size() && (stk[i-1].top()[0] == stk[i].top()[0] || stk[i-1].top()[1] == stk[i].top()[1])) {
				stk[i-1].push(stk[i].top());
				stk[i].pop();
				if (stk[i].size() == 0) stk.erase(stk.begin()+i);
				i--;
				continue;
			}
			i++;
		}
		cout<<stk.size()<<" pile"<<((stk.size()==1)?"":"s")<<" remaining:";
		for (j=0; j<stk.size(); j++) cout<<" "<<stk[j].size();
		cout<<"\n";
	}
	
	return 0;
}
