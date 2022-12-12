/*
        By: facug91
        From: https://www.spoj.com/problems/DQUERY/
        Name: DQUERY - D-query
        Date: 12/12/2022
        Solution: Mo's algorithm
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define endline std::endl
#define LOG(x) std::cout << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

#define y0 dbnw9uddu0132dnd03dnqwuidg1o
#define y1 nd03dnqwuidg1odbnw9uddu0132d
const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

const int MAX_N = 3e4 + 5;
const int MAX_Q = 2e5 + 5;
const int MAX_VALUE = 1e6 + 7;
const int BlockSize = 200;

struct query {
	int l, r, idx;

	bool operator<(const query& other) {
		if (l / BlockSize != other.l / BlockSize)
			return l < other.l;
		return (l / BlockSize & 1) ? (r < other.r) : (r > other.r);
	}
};

int n, a[MAX_N], q, ans[MAX_Q], currL = 0, currR = -1, currCounter[MAX_VALUE], currAns = 0;
query queries[MAX_Q];

int count(int l, int r) {
	while (currL > l) {
		currL--;
		currCounter[a[currL]]++;
		if (currCounter[a[currL]] == 1) currAns++;
	}
	while (currR < r) {
		currR++;
		currCounter[a[currR]]++;
		if (currCounter[a[currR]] == 1) currAns++;
	}
	while (currL < l) {
		currCounter[a[currL]]--;
		if (currCounter[a[currL]] == 0) currAns--;
		currL++;
	}
	while (currR > r) {
		currCounter[a[currR]]--;
		if (currCounter[a[currR]] == 0) currAns--;
		currR--;
	}
	return currAns;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].idx = i;
	}

	sort(queries, queries + q);
	memset(currCounter, 0, sizeof currCounter);
	for (int i = 0; i < q; i++)
		ans[queries[i].idx] = count(queries[i].l, queries[i].r);

	for (int i = 0; i < q; i++) cout << ans[i] << endline;

	return 0;
}
