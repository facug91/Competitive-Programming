/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=526&page=show_problem&problem=3897
        Name: The Grille
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
 
int n;
string grille[1005], message[1005], aux[1005], ans;
 
void add () {
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (grille[i][j] == 'O') ans += message[i][j];
}
 
void rotate () {
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) aux[i][j] = grille[n-j-1][i];
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) grille[i][j] = aux[i][j];
}
 
int main () {
        ios_base::sync_with_stdio(0); cin.tie(0);
        //cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
        int i, j;
       
        for (i=0; i<1005; i++) for (aux[i] = "", j=0; j<1005; j++) aux[i] += " ";
        while (cin>>n, n) {
                for (i=0; i<n; i++) cin>>grille[i];
                for (i=0; i<n; i++) cin>>message[i];
                ans = "";
                for (i=0; i<4; i++) {
                        add();
                        if (i < 3) rotate();
                }
                cout<<ans<<"\n";
        }
       
        return 0;
}
