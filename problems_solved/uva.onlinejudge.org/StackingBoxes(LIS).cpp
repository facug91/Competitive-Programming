/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=39
        Name: Stacking Boxes
        Number: 103
        Date: 20/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int k, n, b;
pair<vector<int>, int> box[50];
ii LIS[50]; //first value, second predecessor
stack<int> print;


bool compare_boxes (int i, int j) {
	for (int s=0; s<n; s++)
		if (box[i].first[s] <= box[j].first[s])
			return false;
	return true;
}
ii lis () {
	int i, j, c;
	ii ans(0, 0);
	for (i=0; i<k; i++) {
		LIS[i].first = 1;
		LIS[i].second = i;
		for (j=0; j<i; j++) {
			if (compare_boxes(i, j)) {
				if (LIS[j].first+1 > LIS[i].first) {
					LIS[i].first = LIS[j].first+1;
					LIS[i].second = j;
				}
			}
		}
		if (LIS[i].first > ans.first) {
			ans.first = LIS[i].first;
			ans.second = i;
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (scanf("%d %d", &k, &n) != EOF) {
		for (i=0; i<k; i++) {
			box[i].first.clear();
			box[i].second = i+1;
			for (j=0; j<n; j++) {
				scanf("%d", &b);
				box[i].first.push_back(b);
			}
			sort(box[i].first.begin(), box[i].first.end()); //sort all the dimensions in the box
		}
		sort(box, box+k); //sort the boxies
		
		ii last = lis();
		
		//print the length of de lis
		printf("%d\n", last.first);
		
		//reconstruct the lis with a stack
		print.push(box[last.second].second);
		int act = last.second;
		while (LIS[act].second != act) {
			act = LIS[act].second;
			print.push(box[act].second);
		}
		
		//print the lis
		printf("%d", print.top());
		print.pop();
		while (!print.empty()) {
			printf(" %d", print.top());
			print.pop();
		}
		printf("\n");
	}
	
	return 0;
}
