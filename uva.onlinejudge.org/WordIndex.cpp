/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=358
        Name: Word Index
        Date: 13/04/2015
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

int cont;
string s;
map<string, int> mp;
map<string, int>::iterator itr;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	cont = 1;
	for (char a='a'; a<='z'; a++) {
		s = a;
		mp[s] = cont++;
	}
	for (char a='a'; a<='z'; a++) {
		for (char b=a+1; b<='z'; b++) {
			s = a;
			s += b;
			mp[s] = cont++;
		}
	}
	for (char a='a'; a<='z'; a++) {
		for (char b=a+1; b<='z'; b++) {
			for (char c=b+1; c<='z'; c++) {
				s = a;
				s += b;
				s += c;
				mp[s] = cont++;
			}
		}
	}
	for (char a='a'; a<='z'; a++) {
		for (char b=a+1; b<='z'; b++) {
			for (char c=b+1; c<='z'; c++) {
				for (char d=c+1; d<='z'; d++) {
					s = a;
					s += b;
					s += c;
					s += d;
					mp[s] = cont++;
				}
			}
		}
	}
	for (char a='a'; a<='z'; a++) {
		for (char b=a+1; b<='z'; b++) {
			for (char c=b+1; c<='z'; c++) {
				for (char d=c+1; d<='z'; d++) {
					for (char e=d+1; e<='z'; e++) {
						s = a;
						s += b;
						s += c;
						s += d;
						s += e;
						mp[s] = cont++;
					}
				}
			}
		}
	}
	while (cin>>s) {
		itr = mp.find(s);
		if (itr == mp.end()) cout<<"0\n";
		else cout<<(*itr).second<<"\n";
	}
	
	return 0;
}
