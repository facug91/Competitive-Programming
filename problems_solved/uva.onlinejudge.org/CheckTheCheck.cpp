/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1137
	Name: Check The Check
	Number: 10196
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int t;
int knight1[] = {-1, -2, -2, -1, 1, 2, 2, 1}, knight2[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int diagonal1[] = {-1, 1, 1, -1}, diagonal2[] = {1, 1, -1, -1};
int axis1[] = {0, 1, 0, -1}, axis2[] = {1, 0, -1, 0};
char board[10][10];
pair<int, int> white_king, black_king;

bool read_board () {
	bool ans = false;
	for (int i=0; i<8; i++) {
		gets(board[i]);
		for (int j=0; j<8; j++) {
			if (board[i][j] != '.') {
				ans = true;
				if (board[i][j] == 'K') {
					white_king.first = i;
					white_king.second = j;
				} else if (board[i][j] == 'k') {
					black_king.first = i;
					black_king.second = j;
				}
			}
		}
	}
	return ans;
}

bool check_pos(int x, int y) {
	return ((x >= 0) && (x < 8) && (y >= 0) && (y < 8));
}

bool check_white () {
	
	int x, y;
	
	//checkea los caballos
	for (int i=0; i<8; i++) {
		x = white_king.first+knight1[i];
		y = white_king.second+knight2[i];
		if (check_pos(x, y) && (board[x][y] == 'n')) return true;
	}
	
	//checkea las diagonales
	for (int i=0; i<4; i++) {
		x = white_king.first+diagonal1[i];
		y = white_king.second+diagonal2[i];
		while (check_pos(x, y) && (board[x][y] == '.')) {
			x += diagonal1[i];
			y += diagonal2[i];
		}
		if (check_pos(x, y)) {
			if (board[x][y] > 'a') {
				if ((board[x][y] == 'q') || (board[x][y] == 'b') || ((board[x][y] == 'p') && (x+1 == white_king.first))) return true;
			}
		}
	}
	
	//checkea los ejes
	for (int i=0; i<4; i++) {
		x = white_king.first+axis1[i];
		y = white_king.second+axis2[i];
		while (check_pos(x, y) && (board[x][y] == '.')) {
			x += axis1[i];
			y += axis2[i];
		}
		if (check_pos(x, y)) {
			if (board[x][y] > 'a') {
				if ((board[x][y] == 'q') || (board[x][y] == 'r')) return true;
			}
		}
	}
	
	return false;
	
}

bool check_black () {
	
	int x, y;
	
	//checkea los caballos
	for (int i=0; i<8; i++) {
		x = black_king.first+knight1[i];
		y = black_king.second+knight2[i];
		if (check_pos(x, y) && (board[x][y] == 'N')) return true;
	}
	
	//checkea las diagonales
	for (int i=0; i<4; i++) {
		x = black_king.first+diagonal1[i];
		y = black_king.second+diagonal2[i];
		while (check_pos(x, y) && (board[x][y] == '.')) {
			x += diagonal1[i];
			y += diagonal2[i];
		}
		if (check_pos(x, y)) {
			if (board[x][y] < 'a') {
				if ((board[x][y] == 'Q') || (board[x][y] == 'B') || ((board[x][y] == 'P') && (x-1 == black_king.first))) return true;
			}
		}
	}
	
	//checkea los ejes
	for (int i=0; i<4; i++) {
		x = black_king.first+axis1[i];
		y = black_king.second+axis2[i];
		while (check_pos(x, y) && (board[x][y] == '.')) {
			x += axis1[i];
			y += axis2[i];
		}
		if (check_pos(x, y)) {
			if (board[x][y] < 'a') {
				if ((board[x][y] == 'Q') || (board[x][y] == 'R')) return true;
			}
		}
	}
	
	return false;
	
}

int main() {
	
	t = 1;
	
	while (read_board()) {
		
		if (check_white()) printf("Game #%d: white king is in check.\n", t);
		else if (check_black()) printf("Game #%d: black king is in check.\n", t);
		else printf("Game #%d: no king is in check.\n", t);
		
		t++; gets(board[0]);
	}
	
	return 0;
} 
