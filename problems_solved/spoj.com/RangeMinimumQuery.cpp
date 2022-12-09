/*
        By: facug91
        From: https://www.spoj.com/problems/RMQSQ/
        Name: Range Minimum Query
        Date: 20/11/2022
*/

#include <bits/stdc++.h>

template<typename ValueType, int MaxSize, int MaxSizeLog>
class SparseTableRMQ {
private:
	int n, k;
	ValueType st[MaxSizeLog][MaxSize];
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

	int calcMinIndex(int i, int j) {
		if (arr[i] < arr[j]) return i;
		if (arr[i] > arr[j]) return j;
		return std::min(i, j);
	}

	void calcSparseTable() {
		for (int i = 0; i < n; i++) st[0][i] = i;
		for (int i = 1; i <= k; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = calcMinIndex(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
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

	int queryMinIndex(int l, int r) {
		auto i = log2_floor(r - l + 1);
		return calcMinIndex(st[i][l], st[i][r - (1 << i) + 1]);
	}

	ValueType queryMinValue(int l, int r) {
		return arr[queryMinIndex(l, r)];
	}
};

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_K = 17;

int n, q, l, r;
int a[MAX_N];
SparseTableRMQ<int, MAX_N, MAX_K> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	st.setNewArray(n, ceil(log2(n)), a);

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << st.queryMinValue(l, r) << endl;
	}

	return 0;
}