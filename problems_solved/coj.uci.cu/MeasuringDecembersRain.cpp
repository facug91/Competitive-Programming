/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2699
	Name: Measuring December´s Rain
	Number: 2699
	Date: 18/12/2013
*/

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring>
#include <string>

using namespace std; 

int main(){ 
    
	int d, sum = 0, i;
	
	for (i=0; i<30; i++) {
		scanf("%d", &d);
		sum += d;
	}
	
	printf("%.3lf\n", sum*1.0+sum/30.0);
	
	return 0;
}
