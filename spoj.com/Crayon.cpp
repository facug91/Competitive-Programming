/*
        By: facug91
        From: https://www.spoj.com/problems/CRAYON/
        Name: Crayon
        Date: 05/12/2022
        Solution: Fenwick Tree
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

const int MAX_N = 2e6 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

int q, n, idx, arr[MAX_N], segmentsCounter;
vector<pair<char, ii>> queries;
vector<ii> addedSegment;
FenwickTreePointUpdateRangeQuery<int, MAX_N> ftL, ftR;
map<int, int> compressValue;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> q;
	n = 0;
	queries.resize(q);
	for (int iq = 0; iq < q; iq++) {
		cin >> queries[iq].first;
		if (queries[iq].first == 'C') cin >> queries[iq].second.first;
		else {
			cin >> queries[iq].second.first >> queries[iq].second.second;
			arr[n++] = queries[iq].second.first;
			arr[n++] = queries[iq].second.second;
		}
	}

	sort(arr, arr + n);
	idx = 0;
	compressValue[arr[0]] = idx++;
	for (int i = 1; i < n; i++)
		if (arr[i] != arr[i - 1])
			compressValue[arr[i]] = idx++;

	ftL.init(n);
	ftR.init(n);
	segmentsCounter = 0;
	for (int iq = 0; iq < q; iq++) {
		if (queries[iq].first == 'C') {
			ftL.add(compressValue[addedSegment[queries[iq].second.first - 1].first], -1);
			ftR.add(compressValue[addedSegment[queries[iq].second.first - 1].second], -1);
			segmentsCounter--;
		} else if (queries[iq].first == 'D') {
			ftL.add(compressValue[queries[iq].second.first], 1);
			ftR.add(compressValue[queries[iq].second.second], 1);
			addedSegment.push_back(queries[iq].second);
			segmentsCounter++;
		} else if (queries[iq].first == 'Q') {
			cout << segmentsCounter
			        - ftL.sum(compressValue[queries[iq].second.second] + 1, idx)
			        - ftR.sum(compressValue[queries[iq].second.first] - 1)
			     << endline;
		}
	}

	return 0;
}
