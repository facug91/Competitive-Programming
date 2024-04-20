/*
        By: facug91
        From: https://acm.timus.ru/problem.aspx?space=1&num=1521
        Name: 1521. War Games 2
        Date: 18/04/2024
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define endl std::endl
#define LOG(x) std::cerr << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
typedef long long ll;

const int MAX_N = (2 << 16) + 5;
const int MAX_K = 16;
const int INF = 1e9;

/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *             https://codeforces.com/blog/entry/61364
 *
 * \tparam ValueType Type of the elements.
 */
template<typename ValueType>
class FenwickTreePointUpdateRangeQuery {
private:
	int n;
	vector<ValueType> bit;

	int log2_floor(ValueType i) {
		return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
	}

public:

	void init(int size) {
		n = size + 1;
		bit.assign(n, 0);
	}

	void init(int size, ValueType val) {
		n = size + 1;
		bit.assign(n, val);
		bit[0] = 0;
		for (size_t i = 0; i < size; i++) {
			size_t j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}

	void init(const std::vector<ValueType>& arr) {
		n = arr.size();
		bit.resize(n);
		bit[0] = 0;
		std::copy(arr.begin(), arr.end(), bit.begin() + 1);
		for (size_t i = 0; i < n; i++) {
			size_t j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
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

	ValueType searchPos(ValueType v) {
		ValueType sum = 0;
		int pos = 0;
		for (int i = log2_floor(n); i >= 0; i--) {
			if (pos + (1 << i) < n and sum + bit[pos + (1 << i)] < v) {
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin>>n>>k;
	int curr = k - 1;

	FenwickTreePointUpdateRangeQuery<int> bit;
	bit.init(n, 1);
	int ans = 0;
	while (n--) {
		int aux = bit.searchPos(curr + 1);
		cout << aux + 1 << " ";
		bit.add(aux, -1);
		if (n > 0)
			curr = (curr + k - 1) % n;
	}
	cout << endl;

	return 0;
}
