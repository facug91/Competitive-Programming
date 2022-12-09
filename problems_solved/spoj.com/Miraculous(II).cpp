/*
        By: facug91
        From: https://www.spoj.com/problems/TNVFC1M/
        Name: Miraculous
        Date: 21/11/2022
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 5;
const int MAX_K = 13;

int n, h, b, e;
int c[MAX_N], ans[MAX_N];

struct compare
{
	bool operator()(const pair<int, int> & a, const pair<int, int> & b)
	{
		if (a.first > b.first) return true;
		if (a.first < b.first) return false;
		return a.second < b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h >> b >> e;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	fill(ans, ans + n, 0);
	ans[0] = 1;
	for (int i = 1; i < n; i++) {
		s.push(make_pair(c[i], i));
		while (s.top().second < i-h) s.pop();
		ans[s.top().second]++;
	}

	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}