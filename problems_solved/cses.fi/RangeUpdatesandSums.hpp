/*
        By: facug91
        From: https://cses.fi/problemset/task/1735/
        Name: Range Updates and Sums
        Date: 22/12/2022
        Solution: Segment tree with lazy propagation
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Segment Tree.
 *        State: tested.
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
template<typename ValueType, int MaxSize, typename CombineFunc, typename DefaultValueFunc>
class SegmentTreeRangeUpdateRangeQuery {
private:
	int n;
	ValueType st[MaxSize * 4], lazyUpdate[MaxSize * 4], lazyAdd[MaxSize * 4];

	ValueType combine(ValueType a, ValueType b) { return a + b; }

	void build(ValueType arr[], int v, int tl, int tr) {
		lazyUpdate[v] = -1;
		lazyAdd[v] = 0;
		if (tl == tr) st[v] = arr[tl];
		else {
			int tm = (tl + tr) / 2;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

	void push(int v, int tl, int tr) {
		int tm = (tl + tr) / 2;
		if (lazyUpdate[v] != -1) {
			st[v * 2] = lazyUpdate[v] * (tm - tl + 1);
			lazyUpdate[v * 2] = lazyUpdate[v];
			lazyAdd[v * 2] = 0;
			st[v * 2 + 1] = lazyUpdate[v] * (tr - tm);
			lazyUpdate[v * 2 + 1] = lazyUpdate[v];
			lazyAdd[v * 2 + 1] = 0;
			lazyUpdate[v] = -1;
		}
		if (lazyAdd[v] != 0) {
			st[v * 2] += ((tm - tl + 1) * lazyAdd[v]);
			lazyAdd[v * 2] += lazyAdd[v];
			st[v * 2 + 1] += ((tr - tm) * lazyAdd[v]);
			lazyAdd[v * 2 + 1] += lazyAdd[v];
			lazyAdd[v] = 0;
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

	void update(int v, int tl, int tr, int l, int r, ValueType val) {
		if (l > r) return;
		if (l == tl && r == tr) {
			st[v] = (tr - tl + 1) * val;
			lazyUpdate[v] = val;
			lazyAdd[v] = 0;
		} else {
			push(v, tl, tr);

			int tm = (tl + tr) / 2;
			update(v * 2, tl, tm, l, std::min(r, tm), val);
			update(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

	void add(int v, int tl, int tr, int l, int r, ValueType val) {
		if (l > r) return;
		if (l == tl && r == tr) {
			st[v] += ((tr - tl + 1) *val);
			lazyAdd[v] += val;
		} else {
			push(v, tl, tr);

			int tm = (tl + tr) / 2;
			add(v * 2, tl, tm, l, std::min(r, tm), val);
			add(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

public:

	void build(int size) {
		n = size;
		std::fill(st, st + (n * 4), 0);
		std::fill(lazyUpdate, lazyUpdate + (n * 4), -1);
		std::fill(lazyAdd, lazyAdd + (n * 4), 0);
	}

	void build(int size, ValueType val) {
		build(size);
		update(1, val);
	}

	void build(int size, ValueType* arr) {
		n = size;
		build(arr, 1, 0, size - 1);
	}

	ValueType query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}

	void update(int l, int r, ValueType val) {
		update(1, 0, n - 1, l, r, val);
	}

	void add(int l, int r, ValueType val) {
		add(1, 0, n - 1, l, r, val);
	}
};

/** Segment tree with range update range query to get sum of values in the given interval */
template<typename ValueType> struct SumDefaultValueRURQ { ValueType operator()() { return 0; }};

template<typename ValueType> struct SumCombineRURQ { ValueType operator()(ValueType val1, ValueType val2) { return val1 + val2; }};

template<typename ValueType, int MaxSize>
using SegmentTreeRangeUpdateRangeQuerySum =
		SegmentTreeRangeUpdateRangeQuery<ValueType, MaxSize, SumCombineRURQ<ValueType>, SumDefaultValueRURQ<ValueType>>;

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

int n, q, type, a, b;
ll arr[MAX_N], x;

SegmentTreeRangeUpdateRangeQuerySum<ll, MAX_N> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];
	st.build(n, arr);
	while (q--) {
		cin >> type >> a >> b;
		if (type == 1) {
			cin >> x;
			st.add(a - 1, b - 1, x);
		} else if (type == 2) {
			cin >> x;
			st.update(a - 1, b - 1, x);
		} else {
			cout << st.query(a - 1, b - 1) << endline;
		}
	}

	return 0;
}
