/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4246
        Name: Tongues
        Date: 06/08/2015
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

string s;
int pos;
char nv = 6, vowels[] = {'a', 'i', 'y', 'e', 'o', 'u'};
char nc = 20, consonants[] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

bool isVowel (char c) {
	for (int i=0; i<nv; i++) if (vowels[i] == tolower(c)) return true;
	return false;
}

bool isConsonant (char c) {
	for (int i=0; i<nc; i++) if (consonants[i] == tolower(c)) return true;
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, k;
	
	while (getline(cin, s)) {
		for (i=0; i<s.length(); i++) {
			if (isVowel(s[i])) {
				for (pos=0; tolower(s[i])!=vowels[pos]; pos++);
				if (s[i] == tolower(s[i])) cout<<vowels[(pos+3)%nv];
				else cout<<(char)toupper(vowels[(pos+3)%nv]);
			} else if (isConsonant(s[i])) {
				for (pos=0; tolower(s[i])!=consonants[pos]; pos++);
				if (s[i] == tolower(s[i])) cout<<consonants[(pos+10)%nc];
				else cout<<(char)toupper(consonants[(pos+10)%nc]);
			} else cout<<s[i];
		}
		cout<<"\n";
	}
	
	return 0;
}
