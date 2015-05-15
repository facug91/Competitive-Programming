/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3835
        Name: Guess the Numbers
        Date: 04/05/2015
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

int n, v[10], m;
string inorder, postorder;
char expresion[15];

void to_postorder () {
	stack<string> stk;
	string a, b, op;
	for (int i=0; i<inorder.length(); i++) {
		if (inorder[i] == '(') continue;
		if (inorder[i] != ')') stk.push(inorder.substr(i, 1));
		else {
			b = stk.top(); stk.pop();
			op = stk.top(); stk.pop();
			a = stk.top(); stk.pop();
			stk.push(a+b+op);
		}
	}
	postorder = stk.top();
}

int get_result () {
	int act = 0, a, b;
	stack<int> stk;
	for (int i=0; i<postorder.length(); i++) {
		if (postorder[i] == '+' || postorder[i] == '-' || postorder[i] == '*') {
			b = stk.top(); stk.pop();
			a = stk.top(); stk.pop();
			if (postorder[i] == '+') {
				stk.push(a+b);
			} else if (postorder[i] == '-') {
				stk.push(a-b);
			} else {
				stk.push(a*b);
			}
		} else {
			stk.push(v[act++]);
		}
	}
	return stk.top();
}

bool check () {
	sort(v, v+n);
	int it = 0;
	do {
		if (get_result() == m) return true;
	} while (next_permutation(v, v+n));
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); //cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) cin>>v[i];
		cin>>m;
		cin>>inorder;
		to_postorder();
		if (check()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
