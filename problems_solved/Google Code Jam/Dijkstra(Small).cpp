/*
        By: facug91
        From: Google Code Jam - Qualification Round 2015 - Problem C Small
        Name: Dijkstra
        Date: 11/04/2015
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
typedef unsigned long long ull;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int l, x;
string s, aux, memo(10000, 'b');
map<char, map<char, char> > op;

void init () {
	op['b']['b'] = 'b';
	op['b']['i'] = 'i';
	op['b']['j'] = 'j';
	op['b']['k'] = 'k';
	op['b']['a'] = 'a';
	op['b']['f'] = 'f';
	op['b']['g'] = 'g';
	op['b']['h'] = 'h';
	op['a']['b'] = 'a';
	op['a']['i'] = 'f';
	op['a']['j'] = 'g';
	op['a']['k'] = 'h';
	op['a']['a'] = 'b';
	op['a']['f'] = 'i';
	op['a']['g'] = 'j';
	op['a']['h'] = 'k';
	
	op['i']['b'] = 'i';
	op['i']['i'] = 'a';
	op['i']['j'] = 'k';
	op['i']['k'] = 'g';
	op['i']['a'] = 'f';
	op['i']['f'] = 'b';
	op['i']['g'] = 'h';
	op['i']['h'] = 'j';
	op['f']['b'] = 'f';
	op['f']['i'] = 'b';
	op['f']['j'] = 'h';
	op['f']['k'] = 'j';
	op['f']['a'] = 'i';
	op['f']['f'] = 'a';
	op['f']['g'] = 'k';
	op['f']['h'] = 'g';
	
	op['j']['b'] = 'j';
	op['j']['i'] = 'h';
	op['j']['j'] = 'a';
	op['j']['k'] = 'i';
	op['j']['a'] = 'g';
	op['j']['f'] = 'k';
	op['j']['g'] = 'b';
	op['j']['h'] = 'f';
	op['g']['b'] = 'g';
	op['g']['i'] = 'k';
	op['g']['j'] = 'b';
	op['g']['k'] = 'f';
	op['g']['a'] = 'j';
	op['g']['f'] = 'h';
	op['g']['g'] = 'a';
	op['g']['h'] = 'i';
	
	op['k']['b'] = 'k';
	op['k']['i'] = 'j';
	op['k']['j'] = 'f';
	op['k']['k'] = 'a';
	op['k']['a'] = 'h';
	op['k']['f'] = 'g';
	op['k']['g'] = 'i';
	op['k']['h'] = 'b';
	op['h']['b'] = 'h';
	op['h']['i'] = 'g';
	op['h']['j'] = 'i';
	op['h']['k'] = 'b';
	op['h']['a'] = 'k';
	op['h']['f'] = 'j';
	op['h']['g'] = 'f';
	op['h']['h'] = 'a';
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	init();
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>l>>x;
		cin>>aux;
		
		for (i=0, s=""; i<x; i++) s+= aux;
		
		char act = 'b';
		for (i=(int)s.length()-1; i>=0; i--) {
			act = op[s[i]][act];
			memo[i] = act;
		}
		
		bool find = false; char a = 'b', b;
		for (int i=0; i<(int)s.length()-2 && !find; i++) {
			a = op[a][s[i]];
			if (a == 'i') {
				b = 'b';
				for (int j=i+1; j<(int)s.length()-1 && !find; j++) {
					b = op[b][s[j]];
					if ((b == 'j') && (memo[j+1] == 'k')) find = true;
				}
			}
		}
		if (find) cout<<"Case #"<<it<<": YES\n";
		else cout<<"Case #"<<it<<": NO\n";
	}
	
	return 0;
}
