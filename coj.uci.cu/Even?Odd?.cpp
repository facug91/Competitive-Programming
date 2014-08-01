/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2196
	Name: Even? Odd?
	Number: 2196
	Date: 03/12/2013
*/

#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	int n; char s[150];
	scanf("%d",&n);
	for (;n--;) {
		scanf("%s",&s);
		(s[strlen(s)-1]&1)?printf("odd\n"):printf("even\n");
	}
    return 0;
}
