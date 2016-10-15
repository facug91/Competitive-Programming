/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2880
	Name: Old Fafhioned Typefetting
	Date: 27/06/2016
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int dt;
string s;

bool not_letter (char c) {
	return !(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>dt;
		getline(cin, s);
		cout<<dt;
		i = 0;
		while (i < s.length()) {
			if (s[i] == 'A') {
				if (i+1 < s.length() && (s[i+1] == 'E' || s[i+1] == 'e')) {
					cout<<"[AE]";
					i += 2;
				} else {
					cout<<"A";
					i++;
				}
			} else if (s[i] == 'a') {
				if (i+1 < s.length() && s[i+1] == 'e') {
					cout<<"[ae]";
					i += 2;
				} else {
					cout<<"a";
					i++;
				}
			} else if (s[i] == 'O') {
				if (i+1 < s.length() && (s[i+1] == 'E' || s[i+1] == 'e')) {
					cout<<"[OE]";
					i += 2;
				} else {
					cout<<"O";
					i++;
				}
			} else if (s[i] == 'o') {
				if (i+1 < s.length() && s[i+1] == 'e') {
					cout<<"[oe]";
					i += 2;
				} else {
					cout<<"o";
					i++;
				}
			} else if (s[i] == 'c') {
				if (i+1 < s.length() && s[i+1] == 't') {
					cout<<"[ct]";
					i += 2;
				} else {
					cout<<"c";
					i++;
				}
			} else if (s[i] == 'f') {
				if (i+1 < s.length() && s[i+1] == 'f') {
					if (i+2 < s.length() && s[i+2] == 'i') {
						cout<<"[ffi]";
						i += 3;
					} else if (i+2 < s.length() && s[i+2] == 'l') {
						cout<<"[ffl]";
						i += 3;
					} else {
						cout<<"[ff]";
						i += 2;
					}
				} else if (i+1 < s.length() && s[i+1] == 'i') {
					cout<<"[fi]";
					i += 2;
				} else if (i+1 < s.length() && s[i+1] == 'l') {
					cout<<"[fl]";
					i += 2;
				} else {
					cout<<"f";
					i++;
				}
			} else if (s[i] == 's') {
				if (i+1 < s.length() && s[i+1] == 's') {
					if (i+2 < s.length() && s[i+2] == 's') {
						cout<<"[longs]s";
						if (i+3 < s.length() && s[i+3] == 'i') {
							cout<<"[longsi]";
							i += 4;
						} else if (i+3 < s.length() && s[i+3] == 'h') {
							cout<<"[longsh]";
							i += 4;
						} else if (i+3 < s.length() && s[i+3] == 'l') {
							cout<<"[longsl]";
							i += 4;
						} else if (i+3 < s.length() && s[i+3] == 't') {
							cout<<"[longst]";
							i += 4;
						} else {
							cout<<"[longs]";
							i += 3;
						}
					} else if (i+2 < s.length() && s[i+2] == 'i') {
						cout<<"[longssi]";
						i += 3;
					} else if (i+2 == s.length() || not_letter(s[i+2]) || s[i+2] == 'f' || s[i+2] == 'b' || s[i+2] == 'k') {
						cout<<"[longs]s";
						i += 2;
					} else {
						cout<<"[longss]";
						i += 2;
					}
				} else if (i+1 < s.length() && s[i+1] == 'i') {
					cout<<"[longsi]";
					i += 2;
				} else if (i+1 < s.length() && s[i+1] == 'h') {
					cout<<"[longsh]";
					i += 2;
				} else if (i+1 < s.length() && s[i+1] == 'l') {
					cout<<"[longsl]";
					i += 2;
				} else if (i+1 < s.length() && s[i+1] == 't') {
					cout<<"[longst]";
					i += 2;
				} else if (i+1 == s.length() || not_letter(s[i+1]) || s[i+1] == 'f' || s[i+1] == 'b' || s[i+1] == 'k') {
					cout<<"s";
					i++;
				} else {
					cout<<"[longs]";
					i++;
				}
			} else {
				cout<<s[i];
				i++;
			}
		}
		cout<<endl;
	}
	
	return 0;
}
