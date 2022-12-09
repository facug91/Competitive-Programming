/*
        By: facug91
        From: https://www.spoj.com/problems/DIFERENC/
        Name: DIFERENCIJA
        Date: 22/11/2022
*/

#include <bits/stdc++.h>

template<typename ValueType, int MaxSize, int MaxSizeLog>
class SparseTableRMinQ {
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

template<typename ValueType, int MaxSize, int MaxSizeLog>
class SparseTableRMaxQ {
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
		if (arr[i] > arr[j]) return i;
		if (arr[i] < arr[j]) return j;
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

#ifdef DEBUG
#define endline std::endl;
#define LOG(x) cerr << "#" << (#x) << ": " << (x) << endl
#else
#define endline "\n"
#define LOG(x)
#endif

#define EPS 1e-9
const double PI = 2.0*acos(0.0);
const int MAX_N = 3e5 + 5;
const int MAX_K = 18;

int n, k, arr[MAX_N], ans;
SparseTableRMinQ<int, MAX_N, MAX_K> stMin;
SparseTableRMaxQ<int, MAX_N, MAX_K> stMax;

template<typename sparse_table>
long long solve(long long l, long long r, sparse_table& st) {
	if (l > r) return 0;

	long long pivot = st.queryIndex(l, r);
	LOG((pivot - l + 1ll) * (r - pivot + 1ll) * (long long)arr[pivot]);
	return (pivot - l + 1ll) * (r - pivot + 1ll) * (long long)arr[pivot] + solve(l, pivot - 1, st) + solve(pivot + 1, r, st);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	k = floor(log2(n));
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	stMin.setNewArray(n, k, arr);
	stMax.setNewArray(n, k, arr);

	cout << solve(0, n - 1, stMax) - solve(0, n - 1, stMin) << endline;


	return 0;
}
