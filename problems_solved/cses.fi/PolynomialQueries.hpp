/*
        By: facug91
        From: https://cses.fi/problemset/result/5148324/
        Name: Polynomial Queries
        Date: 21/12/2022
        Solution: Segment tree with lazy propagation
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Segment Tree.
 *        State: untested.
 *        Ref: Competitive Programming 3, section 2.4.3
 *             https://cp-algorithms.com/data_structures/segment_tree.html
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 * \tparam ElementCompare Comparator function to combine intervals and partial answers
 *         (e.g. struct SumCombine { ValueType operator()(ValueType val1, ValueType val2) { return val1 + val2; }};).
 * \tparam DefaultValueFunc Function returning the default value, used when calling with an undefined interval (l > r)
 *         (e.g. struct SumDefaultValue { ValueType operator()() { return 0; }};).
 *         // TODO complete documentation of new parameters
 */
template<typename ValueType, int MaxSize>
class SegmentTreeRangeUpdateRangeQuery {
private:
	int n;
	ValueType st[MaxSize * 4], lazyAdd[MaxSize * 4], lazyMul[MaxSize * 4];

	ValueType getSum(ValueType n) {
		return n * (n + 1) / 2;
	}

	ValueType combine(ValueType a, ValueType b) { return a + b; }

	void build(ValueType arr[], int v, int tl, int tr) {
		lazyAdd[v] = 0;
		lazyMul[v] = 0;
		if (tl == tr) st[v] = arr[tl];
		else {
			int tm = (tl + tr) / 2;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

	void push(int v, int tl, int tr) {
		if (lazyAdd[v] != 0) {

			int tm = (tl + tr) / 2;

			int lenLeft = tm - tl + 1;
			st[v * 2] += (getSum(lenLeft - 1) * lazyMul[v] + lenLeft * (lazyAdd[v]));
			lazyAdd[v * 2] += lazyAdd[v];
			lazyMul[v * 2] += lazyMul[v];

			int lenRight = tr - tm;
			st[v * 2 + 1] += (getSum(lenRight - 1) * lazyMul[v] + lenRight * (lazyAdd[v] + lenLeft * lazyMul[v]));
			lazyAdd[v * 2 + 1] += lazyAdd[v] + lenLeft * lazyMul[v];
			lazyMul[v * 2 + 1] += lazyMul[v];

			lazyAdd[v] = 0;
			lazyMul[v] = 0;
		}
	}

	ValueType query(int v, int tl, int tr, int l, int r) {
		if (l > r) return 0;
		if (l == tl && r == tr) return st[v];
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		return combine(query(v * 2, tl, tm, l, std::min(r, tm)),
		               query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
	}

	void add(int v, int tl, int tr, int l, int r, ValueType val) {
		if (l > r) return;
		if (l == tl && r == tr) {
			st[v] += (getSum(tr - tl) + (tr - tl + 1) * val);
			lazyAdd[v] += val;
			lazyMul[v]++;
		} else {
			push(v, tl, tr);

			int tm = (tl + tr) / 2;
			add(v * 2, tl, tm, l, std::min(r, tm), val);
			add(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val + std::max(0, tm + 1 - l));
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

public:

	void build(int size, ValueType* arr) {
		n = size;
		build(arr, 1, 0, size - 1);
	}

	ValueType query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}

	void add(int l, int r) {
		add(1, 0, n - 1, l, r, 1);
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
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;
const int invalid = 1e9 + 5;

int n, q, type, a, b;
ll arr[MAX_N];
SegmentTreeRangeUpdateRangeQuery<ll, MAX_N> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];
	st.build(n, arr);
	for (int iq = 0; iq < q; iq++) {
		cin >> type >> a >> b;
		if (type == 1) st.add(a - 1, b - 1);
		else cout << st.query(a - 1, b - 1) << endline;
	}

	return 0;
}
