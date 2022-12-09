/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
        Name: I Can Guess the Data Structure!
        Date: 13/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-12
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, op, v;
stack<int> stk;
queue<int> q;
priority_queue<int> pq;
bool is_stack, is_queue, is_priority_queue;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	while (cin>>n) {
		while (stk.size()) stk.pop();
		while (q.size()) q.pop();
		while (pq.size()) pq.pop();
		is_stack = is_queue = is_priority_queue = true;
		for (int i=0; i<n; i++) {
			cin>>op>>v;
			if (op == 1) {
				stk.push(v);
				q.push(v);
				pq.push(v);
			} else {
				if (stk.size() == 0) is_stack = is_queue = is_priority_queue = false;
				else {
					if (stk.top() != v) is_stack = false;
					stk.pop();
					if (q.front() != v) is_queue = false;
					q.pop();
					if (pq.top() != v) is_priority_queue = false;
					pq.pop();
				}
			}
		}
		if (!is_stack && !is_queue && !is_priority_queue) cout<<"impossible\n";
		else if ((is_stack && is_queue) || (is_stack && is_priority_queue) || (is_queue && is_priority_queue)) cout<<"not sure\n";
		else if (is_stack) cout<<"stack\n";
		else if (is_queue) cout<<"queue\n";
		else cout<<"priority queue\n";
	}
	
	return 0;
}
