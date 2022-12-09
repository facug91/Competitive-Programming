/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=291
        Name: The Bases Are Loaded
        Number: 355
        Date: 07/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int from, to, to_number['G'];
string num, ans, to_char = "0123456789ABCDEF";
ll base10, power;

bool is_valid () {
	for (int i=0; i<(int)num.size(); i++) {
		if (num[i] > to_char[from-1]) {
			return false;
		}
	}
	return true;
}

void init () {
	to_number['0'] = 0;
	to_number['1'] = 1;
	to_number['2'] = 2;
	to_number['3'] = 3;
	to_number['4'] = 4;
	to_number['5'] = 5;
	to_number['6'] = 6;
	to_number['7'] = 7;
	to_number['8'] = 8;
	to_number['9'] = 9;
	to_number['A'] = 10;
	to_number['B'] = 11;
	to_number['C'] = 12;
	to_number['D'] = 13;
	to_number['E'] = 14;
	to_number['F'] = 15;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	while (cin>>from>>to>>num) {
		if (!is_valid()) {
			cout<<num<<" is an illegal base "<<from<<" number"<<endl;
		} else {
			base10 = 0;
			power = 1;
			for (i=(int)num.size()-1; i>=0; i--) {
				base10 += (to_number[num[i]]*power);
				power *= from;
			}
			if (to == 10) {
				cout<<num<<" base "<<from<<" = "<<base10<<" base "<<to<<endl;
			} else {
				i = 0; 
				while (base10) {
					ans[i++] = to_char[base10%to];
					base10 /= to;
				}
				if (i == 0) {
					cout<<num<<" base "<<from<<" = 0 base "<<to<<endl;
				} else {
					cout<<num<<" base "<<from<<" = ";
					for (--i; i>=0; i--) {
						cout<<ans[i];
					}
					cout<<" base "<<to<<endl;
				}
			}
		}
	}
	
	return 0;
}
