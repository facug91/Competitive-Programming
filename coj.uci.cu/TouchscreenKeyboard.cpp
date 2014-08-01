/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2601
	Name: Touchscreen Keyboard
	Number: 2601
	Date: 06/11/2013
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

//Accepted

int distancias[30][30];

void precalcular() {
	string s1 = "qwertyuiop";
	string s2 = "asdfghjkl{";
	string s3 = "zxcvbnm}|~";
	
	int distanciaAct;
	int i, j;
	
	for (i=0; i<10; i++) {
		distanciaAct = 0;
		for (j=i; j<10; j++) {
			distancias[s1[i]-'a'][s1[j]-'a'] = distanciaAct;
			distancias[s1[i]-'a'][s2[j]-'a'] = distanciaAct+1; 
			distancias[s1[i]-'a'][s3[j]-'a'] = distanciaAct+2; 
			distancias[s2[i]-'a'][s1[j]-'a'] = distanciaAct+1;
			distancias[s2[i]-'a'][s2[j]-'a'] = distanciaAct;
			distancias[s2[i]-'a'][s3[j]-'a'] = distanciaAct+1;
			distancias[s3[i]-'a'][s1[j]-'a'] = distanciaAct+2;
			distancias[s3[i]-'a'][s2[j]-'a'] = distanciaAct+1;
			distancias[s3[i]-'a'][s3[j]-'a'] = distanciaAct; 
			
			distancias[s1[j]-'a'][s1[i]-'a'] = distanciaAct;
			distancias[s1[j]-'a'][s2[i]-'a'] = distanciaAct+1; 
			distancias[s1[j]-'a'][s3[i]-'a'] = distanciaAct+2; 
			distancias[s2[j]-'a'][s1[i]-'a'] = distanciaAct+1;
			distancias[s2[j]-'a'][s2[i]-'a'] = distanciaAct;
			distancias[s2[j]-'a'][s3[i]-'a'] = distanciaAct+1;
			distancias[s3[j]-'a'][s1[i]-'a'] = distanciaAct+2;
			distancias[s3[j]-'a'][s2[i]-'a'] = distanciaAct+1;
			distancias[s3[j]-'a'][s3[i]-'a'] = distanciaAct;
			
			distanciaAct++;
		}
	}
	
}

string act, aux;

int calcularDistancia() {
	int total = 0;
	//cout<<act<<endl;
	for (int i=0; i<act.size(); i++) {
		total += distancias[act[i]-'a'][aux[i]-'a'];
	}
	return total;
}

struct cmp { //comparador de pairs por segundo dato de menor a mayor
    bool operator() (const pair<string, int> &a, const pair<string, int> &b) {
        if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
    }
};

int main () {
	
	precalcular();
	
	int t, n, i;
	priority_queue<pair<string,int>, vector<pair<string, int> >, cmp> cola;
	
	cin>>t;
	
	while (t--) {
		
		cin>>act>>n;
		
		for (i=0; i<n; i++) {
			cin>>aux;
			cola.push(make_pair(aux, calcularDistancia()));
		}
		
		for (i=0; i<n; i++) {
			cout<<cola.top().first<< " " <<cola.top().second<<endl;
			cola.pop();
		}
	}
	return 0;
}
