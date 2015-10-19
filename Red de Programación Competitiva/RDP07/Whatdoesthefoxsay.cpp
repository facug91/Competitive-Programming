/*
        By: facug91
        From: https://acm.javeriana.edu.co/maratones/2015/07
        Name: What does the fox say
        Date: 08/08/2015
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	string an;
	string all[1005];
	while (t--){
		set<string> found;
		getline(cin, s);
		istringstream ss(s);
		int i = 0;
		while (ss>>s) {
			all[i] = s;
			i++;
		}
		bool first = true;
		while(true){
			getline(cin,s);
			if(s == "what does the fox say?") break;
			istringstream ss2(s);
			ss2 >> an;
			ss2 >> an;
			ss2 >> an; 
			found.insert(an);
		}
		for(int j=0;j<i;j++){
			if(found.find(all[j]) == found.end()){
				if (first) first = false;
				else cout<<" ";
				cout << all[j];
			}
		}
		cout << endl;
	}
	
}

