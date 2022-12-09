/*
        By: facug91
        From: https://www.spoj.com/problems/YODANESS/
        Name: Yodaness Level
        Date: 02/12/2022
        Solution: Fenwick Tree
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *        State: tested.
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

const int MAX_N = 3e4 + 5;
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int t, n, ans;
string s1[MAX_N], s2[MAX_N];
FenwickTreePointUpdateRangeQuery<int, MAX_N> ft;
map<string, int> s1ToIndex;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s1[i];
			s1ToIndex[s1[i]] = i;
		}
		for (int i = 0; i < n; i++) cin >> s2[i];

		ans = 0;
		ft.init(n, 1);
		int i1 = 0;
		int i2 = 0;
		while (i2 < n) {
			if (s1[i1] == s2[i2]) i1++;
			else {
				ans += ft.sum(i1, s1ToIndex[s2[i2]])-1;
				ft.add(s1ToIndex[s2[i2]], -1);
			}
			i2++;
		}

		cout << ans << endline;
	}

	return 0;
}
