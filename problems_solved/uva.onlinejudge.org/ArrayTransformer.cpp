/*
        By: facug91
        From: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3154&mosmsg=Submission+received+with+ID+28082126
        Name: 12003 - Array Transformer
        Date: 09/12/2022
        Solution: sqrt decomposition + sorting
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

const int MAX_N = 3e5 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

const int blockSize = 1000;
int n, m, u, a[MAX_N], blocks, sorted[MAX_N / blockSize + 5][blockSize];

void buildBlock(int blockId) {
	int l = blockId * blockSize;
	int r = min(l + blockSize - 1, n);

	copy(a + l, a + r + 1, sorted[blockId]);
	if (r - l + 1 != blockSize) fill(sorted[blockId] + r - l + 1, sorted[blockId] + blockSize, 1e9 + 5);
	sort(sorted[blockId], sorted[blockId] + r - l + 1);
}

void rebuildBlock(int blockId, int oldVal, int newVal) {
	int l = blockId * blockSize;
	int r = min(l + blockSize - 1, n);

	auto idx = distance(sorted[blockId], lower_bound(sorted[blockId], sorted[blockId] + blockSize, oldVal));
	sorted[blockId][idx] = newVal;

	while (idx + 1 < blockSize && sorted[blockId][idx] > sorted[blockId][idx + 1]) {
		std::swap(sorted[blockId][idx], sorted[blockId][idx + 1]);
		idx++;
	}
	while (idx > 0 && sorted[blockId][idx - 1] > sorted[blockId][idx]) {
		std::swap(sorted[blockId][idx - 1], sorted[blockId][idx]);
		idx--;
	}
}

int countLessThanV(int l, int r, int val) {
	int blockL = l / blockSize;
	int blockR = r / blockSize;
	int ans = 0;

	if (blockL == blockR) {
		if (r - l + 1 == blockSize) ans += distance(sorted[blockL], lower_bound(sorted[blockL], sorted[blockL] + blockSize, val));
		else for (int i = l; i <= r; i++) if (a[i] < val) ans++;
	} else {
		if (l % blockSize) {
			for (int i = l, end = (blockL + 1) * blockSize - 1; i <= end; i++) if (a[i] < val) ans++;
			blockL++;
		}
		for (int i = blockR * blockSize; i <= r; i++) if (a[i] < val) ans++;
		for (int blockId = blockL; blockId <= blockR - 1; blockId++) {
			ans += distance(sorted[blockId], lower_bound(sorted[blockId], sorted[blockId] + blockSize, val));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> u;
	for (int i = 0; i < n; i++) cin >> a[i];

	blocks = ceil(n / blockSize);
	for (int i = 0; i <= blocks; i++) buildBlock(i);

	int l, r, v, p;
	while (m--) {
		cin >> l >> r >> v >> p;
		l--;
		r--;
		p--;

		int k = countLessThanV(l, r, v);

		auto newVal = floor((k / (r - l + 1.0)) * u);
		rebuildBlock(p / blockSize, a[p], newVal);
		a[p] = newVal;
	}

	for (int i = 0; i < n; i++) cout << a[i] << endline;

	return 0;
}
