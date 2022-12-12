/*
        By: facug91
        From: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3141&mosmsg=Submission+received+with+ID+28084926
        Name: Dynamic Inversion
        Date: 10/12/2022
        Solution: Fenwick Tree + sqrt decomposition
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 */
template<typename ValueType, int MaxSize>
class FenwickTreePointUpdateRangeQuery {
private:
	int n;
	ValueType bit[MaxSize + 1];

public:

	void init(int size) {
		n = size + 1;
		memset(bit, 0, sizeof(ValueType) * n);
	}

	void init(int size, ValueType val) {
		init(size);
		for (size_t i = 0; i < size; i++) add(i, val);
	}

	void init(int size, ValueType* arr) {
		init(size);
		for (size_t i = 0; i < size; i++) add(i, arr[i]);
	}

	void init(std::vector<ValueType>& arr) {
		init(arr.size(), &arr[0]);
	}

	void add(int idx, ValueType delta) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += delta;
	}

	ValueType sum(int r) {
		ValueType ret = 0;
		for (++r; r > 0; r -= r & -r)
			ret += bit[r];
		return ret;
	}

	ValueType sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

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

const int MAX_N = 2e5 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

struct query {
	int idx, val;
};

const int queryBlock = 2000;
int n, m, p, a[MAX_N], valueToIndex[MAX_N];
ll ans, pairL[MAX_N], pairR[MAX_N];
FenwickTreePointUpdateRangeQuery<ll, MAX_N> ftL, ftR;
vector<query> queries;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			valueToIndex[a[i]] = i;
		}

		while (m) {
			ans = 0;
			ftL.init(n + 1);
			ftR.init(n + 1);
			for (int i = 0; i < n; i++) {
				if (a[i] != -1) {
					pairL[i] = ftL.sum(n - a[i] - 1);
					ans += pairL[i];
					ftL.add(n - a[i], 1);
				}
				if (a[n - 1 - i] != -1) {
					pairR[n - 1 - i] = ftR.sum(a[n - 1 - i] - 1);
					ftR.add(a[n - 1 - i], 1);
				}
			}

			queries.clear();
			for (int iq = 0, end = min(queryBlock, m); iq < end; iq++, m--) {
				cin >> p;
				cout << ans << endline;
				ans -= (pairL[valueToIndex[p]] + pairR[valueToIndex[p]]);
				for (int i = 0; i < queries.size(); i++)
					if (queries[i].idx < valueToIndex[p] && queries[i].val > p) ans++;
					else if (queries[i].idx > valueToIndex[p] && queries[i].val < p) ans++;
				queries.push_back({ valueToIndex[p], p });
				a[valueToIndex[p]] = -1;
			}
		}
	}

	return 0;
}
