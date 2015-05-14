/*
        By: facug91
        From: Lawn mower
        Name: Lawn mower
        Date: 29/04/2015
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
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n[2];
double w, pos[2][1005];
 
bool check (int idx) {
        int i, j;
        double act = 0.0;
        for (i=0; i<n[idx]; i++) {
                if (pos[idx][i]-w/2.0 <= act) {
                        act = pos[idx][i] + w/2.0;
                } else {
                        return false;
                }
        }
        if (idx == 1) return act >= 100.0;
        else return act >= 75.0;
}
 
int main () {
        ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0);
        int i, j;
       
        while (cin>>n[0]>>n[1]>>w, n[0] || n[1] || w) {
                for (i=0; i<n[0]; i++) cin>>pos[0][i];
                for (i=0; i<n[1]; i++) cin>>pos[1][i];
                sort(pos[0], pos[0]+n[0]);
                sort(pos[1], pos[1]+n[1]);
                if (check(0) && check(1)) cout<<"YES\n";
                else cout<<"NO\n";
        }
 
        return 0;
}
