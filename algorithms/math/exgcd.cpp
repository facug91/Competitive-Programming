#pragma once
#include <bits/stdc++.h>

template <typename T>
T exgcd (T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	T d = exgcd(b, a%b, x, y);
	T x1 = y;
	T y1 = x - (a / b) * y;
	x = x1;
	y = y1;
	return d;
}

template <typename T>
void makeXPositive(T a, T b, T& x, T& y, T gcd){
	if (x > 0) return;
	T m = (T)ceil((-x / double(b / gcd)));
	x += ((b / gcd) * m);
	y -= ((a / gcd) * m);
}

template <typename T>
void makeYPositive(T a, T b, T& x, T& y, T gcd){
	if (y > 0 ) return;
	T m = (T)ceil((-y / double(a/ gcd)));
	x -= ((b / gcd) * m);
	y += ((a / gcd) * m);
}

int main () {
	int x, y, a = 21, b = 35, c = 56, gcd;
	
	gcd = exgcd(a, b, x, y);
	
	std::cout << gcd << std::endl;
	
	x *= (c / gcd); y *= (c / gcd);
	std::cout << x << " " << y << std::endl;
	
	makeXPositive(a, b, x, y, gcd);
	std::cout << x << " " << y << std::endl;
	
	makeYPositive(a, b, x, y, gcd);
	std::cout << x << " " << y << std::endl;
	
	return 0;
}
