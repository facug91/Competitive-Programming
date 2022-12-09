/*
        By: facug91
        From: https://www.spoj.com/problems/NKTEAM/
        Name: Team Selection
        Date: 01/12/2022
        Solution: Fenwick Tree Min
*/

#include <bits/stdc++.h>

template<typename ValueType, int MaxSize, typename ElementCompare = std::less<ValueType>, ValueType LimitValue = std::numeric_limits<ValueType>::max()>
class FenwickTreeMinMax {
private:
	int n;
	ValueType bit[MaxSize + 1];
	ElementCompare elementCompare;

public:

	ValueType Limit = LimitValue;

	void init(int size) {
		n = size + 1;
		std::fill(bit, bit + n, LimitValue);
	}

	void init(int size, ValueType* arr) {
		init(size);
		for (size_t i = 0; i < size; i++)
			update(i, arr[i]);
	}

	void init(std::vector<ValueType>& arr) {
		init(arr.size(), &arr[0]);
	}

	void update(int idx, ValueType val) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] = elementCompare(bit[idx], val) ? bit[idx] : val;
	}

	ValueType getValue(int r) {
		ValueType ret = LimitValue;
		for (++r; r > 0; r -= r & -r)
			ret = elementCompare(bit[r], ret) ? bit[r] : ret;
		return ret;
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

const int MAX_N = 5e5 + 5;
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, c, ans;
pair<int, ii> arr[MAX_N];
FenwickTreeMinMax<int, MAX_N> ft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> c, arr[c-1].first = i;
	for (int i = 0; i < n; i++) cin >> c, arr[c-1].second.first = i;
	for (int i = 0; i < n; i++) cin >> c, arr[c-1].second.second = i;

	sort(arr, arr + n);

	ans = 0;
	ft.init(n + 1);

	for (int i = 0; i < n; i++) {
		if (arr[i].second.second < ft.getValue(arr[i].second.first)) ans++;
		ft.update(arr[i].second.first, arr[i].second.second);
	}

	cout << ans << endline;


	return 0;
}
