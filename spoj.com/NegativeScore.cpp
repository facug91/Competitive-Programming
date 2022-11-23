/*
        By: facug91
        From: https://www.spoj.com/problems/RPLN/
        Name: Negative Score
        Date: 21/11/2022
*/

#include <bits/stdc++.h>

// MaxSizeLog = floor(log2(MaxSize))
// Modify function calcIndex for min/max table, and for leftmost/rightmost value when equals
template<typename ValueType, int MaxSize, int MaxSizeLog>
class SparseTableRMQ {
private:
	int n, k;
	ValueType st[MaxSizeLog + 1][MaxSize];
	ValueType arr[MaxSize];

#if __cplusplus >= 202002L
	int log2_floor(ValueType i) {
		return std::bit_width(i) - 1;
	}
#else

	int log2_floor(ValueType i) {
		return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
	}

#endif

	// Invert comparison operators if you need a range max query sparse table
	// Replace std::min with std::max if you need the rightmost index instead of the leftmost
	int calcIndex(int i, int j) {
		if (arr[i] < arr[j]) return i;
		if (arr[i] > arr[j]) return j;
		return std::min(i, j);
	}

	void calcSparseTable() {
		for (int i = 0; i < n; i++) st[0][i] = i;
		for (int i = 1; i <= k; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = calcIndex(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	}

public:

	void setNewArray(int n, int k, ValueType* begin, ValueType* end) {
		std::copy(begin, end, arr);
		this->n = n;
		this->k = k;
		calcSparseTable();
	}

	void setNewArray(int n, int k, typename std::vector<ValueType>::iterator begin, typename std::vector<ValueType>::iterator end) {
		std::copy(begin, end, arr);
		this->n = n;
		this->k = k;
		calcSparseTable();
	}

	void setNewArray(int n, int k, std::vector<ValueType>& newArray) {
		setNewArray(n, k, newArray.begin(), newArray.end());
	}

	void setNewArray(int n, int k, ValueType* newArray) {
		setNewArray(n, k, newArray, newArray + n);
	}

	int queryIndex(int l, int r) {
		auto i = log2_floor(r - l + 1);
		return calcIndex(st[i][l], st[i][r - (1 << i) + 1]);
	}

	ValueType queryValue(int l, int r) {
		return arr[queryIndex(l, r)];
	}
};

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_K = 16;

int t, n, q, arr[MAX_N], l, r;
SparseTableRMQ<int, MAX_N, MAX_K> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> n >> q;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		st.setNewArray(n, floor(log2(n)), arr);

		cout << "Scenario #" << it << ":" << "\n";
		while (q--) {
			cin >> l >> r;
			cout << st.queryValue(l - 1, r - 1) << "\n";
		}
	}


	return 0;
}