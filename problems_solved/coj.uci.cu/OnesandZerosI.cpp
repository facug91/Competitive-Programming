/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1398
	Name: Ones and Zeros I
	Number: 1398
	Date: 30/05/2014
*/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <queue>
#include <utility>

using namespace std;

int k, n, parent[20005], size, q[20005], r, w;
bool visited[20005];
char value[20005];
char ans[1000];

void bfs () {
	
	if (n == 1) {
		ans[0] = '1';
		size = 1;
		return;
	}
	
	r = 0, w = 0;
	
	for (int i=0; i<=n; i++) visited[i] = false;
	
	q[w++] = 10;
	visited[10] = true;
	value[10] = '0';
	parent[10] = 1;
	
	q[w++] = 11;
	visited[11] = true;
	value[11] = '1';
	parent[11] = 1;
	
	int act, res;
	while (true) {
		
		act = q[r++];
		
		if (act % n == 0) {
			break;
			
		} else {
			res = (act*10)%n;
			if (!visited[res]) {
				visited[res] = true;
				value[res] = '0';
				parent[res] = act;
				q[w++] = res;
			}
			
			res = ((act*10)+1)%n;
			if (!visited[res]) {
				visited[res] = true;
				value[res] = '1';
				parent[res] = act;
				q[w++] = res;
			}
			
		}
		
	}
	
	size = 0;
	while (act != 1) {
		ans[size] = value[act];
		act = parent[act];
		size++;
	}
	ans[size++] = '1';
	
}
 
int main() {
	
	scanf("%d", &k);
	
	while (k--) {
		
		scanf("%d", &n);
		
		bfs();
		
		for (int i=size-1; i>=0; i--) {
			putchar(ans[i]);
		}
		putchar('\n');
		
	}
	
	
	return 0;
} 
