/*
        By: facug91
        From:https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=399&page=show_problem&problem=2958
        Name:Fake scoreboard
        Date: 11/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000003ll
//#define MAXN 1000005
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;
 
int teams, problems, totalt, totalp, s, t, res[200][200], level[200], mf;
bool valid, inuse[200][200];
vi adj[200];
 
bool bfs () {
        memset(level, -1, sizeof level);
        queue<int> q; q.push(s);
        level[s] = 0;
        int u, v, i;
        while (q.size()) {
                u = q.front(); q.pop();
                for (i=0; i<adj[u].size(); i++) if (inuse[v=adj[u][i]]) {
                        if (level[v] == -1 && res[u][v] > 0) {
                                level[v] = level[u] +1;
                                q.push(v);
                                if (v == t) return true;
                        }
                }
        }
        return false;
}
 
int dfs (int u, int min_edge) {
        if (u == t) return min_edge;
        int v, i, faux, fsum = 0;
        for (i=0; i<adj[u].size(); i++) if (inuse[v=adj[u][i]]) {
                if (level[v] == level[u] + 1 && res[u][v] > 0) {
                        faux = dfs(v, min(min_edge, res[u][v]));
                        if (faux) {
                                fsum += faux;
                                res[u][v] -= faux;
                                res[v][u] += faux;
                                min_edge -= faux;
                                if (min_edge == 0) break;
                        }
                }
        }
        return fsum;
}
 
int max_flow () {
        while (bfs()) mf += dfs(s, INT_MAX);
        return mf;
}
 
int main () {
        ios_base::sync_with_stdio(0); cin.tie(0);
        //cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
        int i, j;
        bool first = true;
       
        while (cin>>teams>>problems, teams || problems) {
                if (first) first = false;
                else cout<<"\n";
                for (i=0; i<200; i++) adj[i].clear();
                memset(res, 0, sizeof res);
                memset(inuse, 0, sizeof inuse);
                totalt = totalp = 0;
                valid = true;
                s = teams+problems; t = s + 1;
                for (i=0; i<teams; i++) {
                        cin>>res[s][i];
                        adj[s].push_back(i);
                        adj[i].push_back(s);
                        inuse[s][i] = true;
                        inuse[i][s] = true;
                        totalt += res[s][i];
                        if (res[s][i] > problems) valid = false;
                }
                for (i=teams; i<problems+teams; i++) {
                        cin>>res[i][t];
                        adj[i].push_back(t);
                        adj[t].push_back(i);
                        inuse[i][t] = true;
                        inuse[t][i] = true;
                        totalp += res[i][t];
                        if (res[i][t] > teams) valid = false;
                }
                for (i=0; i<teams; i++) for (j=teams; j<problems+teams; j++) {
                        res[i][j] = 1;
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        inuse[i][j] = true;
                        inuse[j][i] = true;
                }
                mf = 0;
                if ((!valid) || (totalt != totalp) || (max_flow() != totalp)) cout<<"Impossible\n";
                else {
                        for (i=0; i<teams; i++) {
                                for (j=teams; j<problems+teams; j++) {
                                        if (res[j][i] > 0) {
                                                int mfaux = mf;
                                                mf--;
                                                res[j][i] = 0;
                                                inuse[i][j] = false;
                                                inuse[j][i] = false;
                                                res[t][j]--;
                                                res[j][t]++;
                                                res[i][s]--;
                                                res[s][i]++;
                                                max_flow();
                                                if (mf == mfaux) cout<<"N";
                                                else {
                                                        cout<<"Y";
                                                        res[j][t]--;
                                                        res[s][i]--;
                                                }
                                        } else {
                                                res[i][j] = 0;
                                                inuse[i][j] = false;
                                                inuse[j][i] = false;
                                                cout<<"N";
                                        }
                                }
                                cout<<"\n";
                        }
                }
        }
       
        return 0;
}
