/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2626
	Name: 3403 is DEAD
	Number: 2626
	Date: 02/01/2014
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

int stringToInt(char* str) {
	int l = strlen(str);
	int aux = str[0]-'A';
	for (int i=1; i<l; i++) {
		aux *= 10;
		aux += (str[i]-'A');
	}
	return aux;
}

int main () {
	int n, p, i, l, num;
	char s[11];
	
	scanf("%d", &n);
	
	while (n--) {
		scanf("%s", s);
		p = 1;
		l = 10;
		for (i=1; i<strlen(s); i++) l *= 10;
		num = stringToInt(s);
		
		i = 0;
		while ((i<312530) && (p ^ num)) {
			p = (p << 1) % l;
			i++;
		}
		
		if (p ^ num) {
			printf("NONE\n");
		} else {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
