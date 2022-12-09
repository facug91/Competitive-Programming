/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3899
        Name: Stack Machine Executor
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
#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

vector<pair<string, int> > op;
stack<int> stk;
string s;
int n, val, val2;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>s, s != "QUIT") {
		op.clear();
		while (s != "END") {
			if (s == "NUM") cin>>val;
			else val = 0;
			op.push_back(make_pair(s, val));
			cin>>s;
		}
		cin>>n;
		while (n--) {
			cin>>val;
			bool error = false;
			while (stk.size()) stk.pop();
			stk.push(val);
			for (i=0; i<op.size(); i++) {
				if (op[i].first == "NUM") stk.push(op[i].second);
				else if (op[i].first == "POP") {
					if (stk.size() == 0) {
						error = true;
						break;
					} else {
						stk.pop();
					}
				} else if (op[i].first == "INV") {
					if (stk.size() == 0) {
						error = true;
						break;
					} else {
						val = stk.top();
						stk.pop();
						stk.push(-val);
					}
				} else if (op[i].first == "DUP") {
					if (stk.size() == 0) {
						error = true;
						break;
					} else {
						val = stk.top();
						stk.push(val);
					}
				} else if (op[i].first == "SWP") {
					if (stk.size() <= 1) {
						error = true;
						break;
					} else {
						val = stk.top(); stk.pop();
						val2 = stk.top(); stk.pop();
						stk.push(val); stk.push(val2);
					}
				} else if (op[i].first == "ADD") {
					if (stk.size() <= 1) {
						error = true;
						break;
					} else {
						val = stk.top(); stk.pop();
						val2 = stk.top(); stk.pop();
						val += val2;
						if (abs(val) > 1000000000) {
							error = true;
							break;
						} else {
							stk.push(val);
						}
					}
				} else if (op[i].first == "SUB") {
					if (stk.size() <= 1) {
						error = true;
						break;
					} else {
						val = stk.top(); stk.pop();
						val2 = stk.top(); stk.pop();
						val = val2 - val;
						if (abs(val) > 1000000000) {
							error = true;
							break;
						} else {
							stk.push(val);
						}
					}
				} else if (op[i].first == "MUL") {
					if (stk.size() <= 1) {
						error = true;
						break;
					} else {
						val = stk.top(); stk.pop();
						val2 = stk.top(); stk.pop();
						if (abs((ll)val2 * (ll)val) > 1000000000ll) {
							error = true;
							break;
						} else {
							stk.push(val2 * val);
						}
					}
				} else if (op[i].first == "DIV") {
					if (stk.size() <= 1) {
						error = true;
						break;
					} else {
						val = stk.top(); stk.pop();
						val2 = stk.top(); stk.pop();
						if (val == 0) {
							error = true;
							break;
						} else {
							stk.push(val2/val);
						}
					}
				} else if (op[i].first == "MOD") {
					if (stk.size() <= 1) {
						error = true;
						break;
					} else {
						val = stk.top(); stk.pop();
						val2 = stk.top(); stk.pop();
						if (val == 0) {
							error = true;
							break;
						} else {
							stk.push(val2%val);
						}
					}
				}
			}
			if (error || stk.size() != 1) cout<<"ERROR\n";
			else cout<<stk.top()<<"\n";
		}
		cout<<"\n";
	}
	
	return 0;
}
