/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=127
        Name: Intersection
        Number: 191
        Date: 09/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct Point_i {
	int x, y;
	Point_i() {x=y=0;}
	Point_i(int _x, int _y):x(_x), y(_y){};
};

Point_i start, end, left_top, right_bottom;
vector<Point_i> rectangle;

Point_i to_vec (const Point_i &a, const Point_i &b) {
	return Point_i(a.x-b.x, a.y-b.y);
}
int ccw (const Point_i &a, const Point_i &b) {
	int val = a.x*b.y - a.y*b.x;
	return (val == 0) ? 0 : (val > 0) ? 1 : -1;
}
bool on_segment (const Point_i &p, const Point_i &q, const Point_i &r) {
	return ((r.x <= max(p.x, q.x)) && (r.x >= min(p.x, q.x)) && (r.y <= max(p.y, q.y)) && (r.y >= min(p.y, q.y)));
}
bool intersect_segment (int idx_r) {
	Point_i vec1 = to_vec(start, end);
	Point_i vec2 = to_vec(rectangle[idx_r], rectangle[idx_r+1]);
	
	int orientation1 = ccw(vec1, to_vec(start, rectangle[idx_r]));
	int orientation2 = ccw(vec1, to_vec(start, rectangle[idx_r+1]));
	int orientation3 = ccw(vec2, to_vec(rectangle[idx_r], start));
	int orientation4 = ccw(vec2, to_vec(rectangle[idx_r], end));
	
	if ((orientation1 != orientation2) && (orientation3 != orientation4)) return true;
	
	if ((orientation1 == 0) && (on_segment(start, end, rectangle[idx_r]))) return true;
	if ((orientation2 == 0) && (on_segment(start, end, rectangle[idx_r+1]))) return true;
	if ((orientation3 == 0) && (on_segment(rectangle[idx_r], rectangle[idx_r+1], start))) return true;
	if ((orientation4 == 0) && (on_segment(rectangle[idx_r], rectangle[idx_r+1], end))) return true;
	
	return false;
}
bool segment_inside_rectangle () {
	for (int i=0; i<4; i++) {
		if (ccw(to_vec(rectangle[i], rectangle[i+1]), to_vec(rectangle[i], start)) < 0) return false;
	}
	return true;
}
bool intersect_rectangle () {
	for (int i=0; i<4; i++) {
		if (intersect_segment(i)) return true;
	}
	if (segment_inside_rectangle()) return true;
	return false;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>start.x>>start.y;
		cin>>end.x>>end.y;
		cin>>left_top.x>>left_top.y;
		cin>>right_bottom.x>>right_bottom.y;
		
		if (left_top.x > right_bottom.x) swap(left_top.x, right_bottom.x);
		if (left_top.y < right_bottom.y) swap(left_top.y, right_bottom.y);
		
		rectangle.push_back(Point_i(left_top.x, right_bottom.y));
		rectangle.push_back(right_bottom);
		rectangle.push_back(Point_i(right_bottom.x, left_top.y));
		rectangle.push_back(left_top);
		rectangle.push_back(Point_i(left_top.x, right_bottom.y));
		
		if (intersect_rectangle()) cout<<"T"<<endl;
		else cout<<"F"<<endl;
		
		rectangle.clear();
	}
	
	return 0;
}
