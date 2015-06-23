/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=526&page=show_problem&problem=3892
        Name: Unique Encryption Keys
        Date: 23/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;              typedef vector<iii> viii;
 
int m, q, k[1000005], ans[1000005], b, e;
deque<int> dq;
set<int> prev;
 
int main () {
        ios_base::sync_with_stdio(0); cin.tie(0);
        //cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
       
        while (cin>>m>>q, m || q) {
                memset(ans, -1, sizeof ans);
                prev.clear();
                dq.clear();
                for (int i=0; i<m; i++) cin>>k[i];
                for (int i=0; i<m; i++) {
                        if (prev.find(k[i]) != prev.end()) {
                                while (k[dq.front()] != k[i]) {
                                        ans[dq.front()] = i;
                                        prev.erase(k[dq.front()]);
                                        dq.pop_front();
                                }
                                ans[dq.front()] = i;
                                dq.pop_front();
                                dq.push_back(i);
                        } else {
                                prev.insert(k[i]);
                                dq.push_back(i);
                        }
                }
                while (q--) {
                        cin>>b>>e; b--; e--;
                        if (ans[b] != -1 && ans[b] <= e) cout<<k[ans[b]]<<"\n";
                        else cout<<"OK\n";
                }
                cout<<"\n";                
        }
       
        return 0;
}
