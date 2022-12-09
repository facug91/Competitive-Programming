/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2438
	Name: Ernesto
	Number: 2438
	Date: 29/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>

#define tint unsigned long long int
#define MAX_INT 2147483647

using namespace std;

struct cmp {
	bool operator () (const string &s1, const string &s2) {
		return (s1 > s2);
	}
};

int tolerancia[1001];
string nombres[1001];
map<string, int> hash;
vector<int> amistad[1001];
queue<int> cola;
bool visitado[1001];

string bfs (int n, int e) {
	int i, j, mx = 0;
	string s;
	cola.push(e);
	visitado[e] = true;
	
	int act;
	while (!cola.empty()) {
		act = cola.front();
		cola.pop();
		
		if (tolerancia[act] > mx) {
			mx = tolerancia[act];
			s = nombres[act];
		}
		
		for (i=0; i<amistad[act].size(); i++) {
			if (!visitado[amistad[act][i]]) {
				visitado[amistad[act][i]] = true;
				cola.push(amistad[act][i]);
			}
		}
	}
	
	return s;
}

int main () {
	int n, m, i, j;
	string s1, s2;
	priority_queue<string, vector<string>, cmp> res;
	
	cin>>n>>m;
	
	while (n || m) {
		
		for (i=0; i<n; i++) {
			cin>>s1>>tolerancia[i];
			hash.insert(make_pair(s1, i));
			nombres[i] = s1;
			visitado[i] = false;
		}
		
		for (i=0; i<m; i++) {
			cin>>s1>>s2;
			amistad[hash[s1]].push_back(hash[s2]);
			amistad[hash[s2]].push_back(hash[s1]);
		}
		
		for (i=0; i<n; i++) {
			if (!visitado[i]) {
				res.push(bfs(n, i));
			}
		}
		
		while (!res.empty()) {
			cout<<res.top()<<endl;
			res.pop();
		}
		
		cin>>n>>m;
		
		hash.clear();
		for (i=0; i<n; i++) {
			amistad[i].clear();
		}
	}
	
	return 0;
}
