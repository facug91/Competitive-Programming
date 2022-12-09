/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2678
	Name: My Brother's Diary
	Number: 2678
	Date: 18/12/2013
*/

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring>
#include <string>

using namespace std; 

int cant['Z'+1];

int main(){ 
    int c, i, max, cmax, add;
	char e;
	string s, res;
	
	cin>>c;
	getline(cin, s);
	while (c--) {
		getline(cin, s);
		memset(cant, 0, sizeof(cant));
		for (i=0; i<s.length(); i++) {
			cant[s[i]]++;
		}
		max = cmax = 0;
		for (i='A'; i<='Z'; i++) {
			if (cant[i] > max) {
				max = cant[i];
				e = i;
				cmax = 1;
			} else if (cant[i] == max) {
				cmax++;
			}
		}
		
		if (cmax == 1) {
			add = (e-'A') - ('E'-'A');
			if (add < 0) {
				add += 26;
			}
			add = 26 - add;
			
			res = "";
			for (i=0; i<s.length(); i++) {
				if (s[i] == ' ') {
					res += " ";
				} else {
					
					res += (char) ((s[i]-'A'+add)%26+'A');
				}
			}
			
			cout<<26-add<<" "<<res<<endl;
		} else {
			cout<<"NOT POSSIBLE"<<endl;
		}
	}
	
	return 0;
}
