/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=
	Name: Points in Rectangles
	Number: 1415
	Date: 05/12/2014
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#define sqr(x) ((x) * (x))

using namespace std;

struct figura {
	double first;
	double second;
	double third;
	double fourth;
};

bool isInCircle (figura f, double x, double y) {
	return sqr(x-f.first)+sqr(y-f.second) < sqr(f.third);
}
bool isInRectangle (figura f, double x, double y) {
	return (x > f.first) && (x < f.third) && (y < f.second) && (y > f.fourth);
}

char c;
queue< pair<char, figura> > figuras;
double x, y;
int i, j;
bool contenido;

int main () {
	
	cin>>c;
	while (c != '*') {
		figura f;
		cin>>f.first>>f.second>>f.third;
		if (c == 'r') {
			cin>>f.fourth;
		}
		figuras.push(make_pair(c, f));
		cin>>c;
	}
	
	i = 1;
	cin>>x>>y;
	while ((x != 9999.9) || (y != 9999.9)) {
		contenido = false;
		
		for (j=1; j<=figuras.size(); j++) {
		
			if (figuras.front().first == 'c') {
				if (isInCircle(figuras.front().second, x, y)) {
					printf("Point %d is contained in figure %d\n", i, j);
					contenido = true;
				}
			} else {
				if (isInRectangle(figuras.front().second, x, y)) {
					printf("Point %d is contained in figure %d\n", i, j);
					contenido = true;
				}
			}
			
			figuras.push(figuras.front());
			figuras.pop();
		}
		
		if (!contenido) {
			printf("Point %d is not contained in any figure\n", i);
		}
		
		i++;
		
		cin>>x>>y;
	}
	
	return 0;
}
