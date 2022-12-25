/*
        By: facug91
        From: http://www.spoj.com/problems/KQUERY/
        Name: K-query
        Date: 18/12/2022
        Solution: Merge Sort Segment Tree
*/

#include <bits/stdc++.h>

template<typename ValueType, int MaxSize, typename CalcResultFunc, typename CombineFunc, typename DefaultValueFunc>
class MergeSortSegmentTreeRangeQuery {
private:
	int n;
	std::vector<ValueType> st[MaxSize * 4];
	CalcResultFunc calcResultFunc;
	CombineFunc combine;
	DefaultValueFunc defaultValueFunc;

	void build(ValueType arr[], int v, int tl, int tr) {
		if (tl == tr) st[v] = std::vector<int>(1, arr[tl]);
		else {
			int tm = (tl + tr) / 2;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			std::merge(st[v * 2].begin(), st[v * 2].end(), st[v * 2 + 1].begin(), st[v * 2 + 1].end(), back_inserter(st[v]));
		}
	}

	ValueType query(int v, int tl, int tr, int l, int r, ValueType val) {
		if (l > r) return defaultValueFunc();
		if (l == tl && r == tr) return calcResultFunc(st[v], val);

		int tm = (tl + tr) / 2;
		return combine(query(v * 2, tl, tm, l, std::min(r, tm), val),
		               query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val));
	}

public:

	void build(int size, ValueType* arr) {
		n = size;
		build(arr, 1, 0, size - 1);
	}

	ValueType query(int l, int r, ValueType val) {
		return query(1, 0, n - 1, l, r, val);
	}
};

/** Merge sort segment tree with range query to get the number of elements greater than a specified number. */
template<typename ValueType> struct SumGreaterCombineMSRQ { ValueType operator()(ValueType val1, ValueType val2) { return val1 + val2; }};
template<typename ValueType> struct SumGreaterDefaultValueMSRQ { ValueType operator()() { return 0; }};
template<typename ValueType> struct SumGreaterCalcResultMSRQ {
	ValueType operator()(const std::vector<ValueType>& sortedSegment, ValueType val) {
		return std::distance(std::upper_bound(sortedSegment.begin(), sortedSegment.end(), val), sortedSegment.end());
	}
};
template<typename ValueType, int MaxSize>
using MergeSortSegmentTreeRangeQuerySumGreater =
		MergeSortSegmentTreeRangeQuery<ValueType, MaxSize,
				SumGreaterCalcResultMSRQ<ValueType>, SumGreaterCombineMSRQ<ValueType>, SumGreaterDefaultValueMSRQ<ValueType>>;

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
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, a[MAX_N], q, l, r, v;
MergeSortSegmentTreeRangeQuerySumGreater<int, MAX_N> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	st.build(n, a);

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r >> v;
		cout << st.query(l - 1, r - 1, v) << endline;
	}

	return 0;
}
