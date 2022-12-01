/*
        By: facug91
        From: https://www.spoj.com/problems/CTRICK/
        Name: Card Trick
        Date: 01/12/2022
        Solution: Fenwick Tree + binary search
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

	void init(int size, ValueType* arr) {
		init(size);
		for (size_t i = 0; i < size; i++)
			add(i, arr[i]);
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

const int MAX_N = 2e4 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, n, cards[MAX_N];
FenwickTreePointUpdateRangeQuery<int, MAX_N> ft;

int binary_search(int low, int high, int val) {
	while (high - low > 1) {
		int mid = low + (high - low) / 2;
		int aux = ft.sum(low, mid);
		if (aux < val) {
			low = mid + 1;
			val -= aux;
		} else {
			high = mid;
		}
	}
	int aux = ft.sum(low, low);
	if (aux == val) return low;
	else return high;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> n;

		if (n == 1) {
			cout << 1 << endline;
			continue;
		}

		memset(cards, 0, sizeof cards);
		ft.init(n);
		for (int i = 0; i < n; i++) ft.add(i, 1);

		cards[1] = 1;
		ft.add(1, -1);
		int last = 1;

		for (int i = 2; i <= n; i++) {
			int move = (i + 1) % (n - i + 1);
			if (move == 0) move = n - i + 1;
			int emptyPlacesRight = last + 1 < n ? ft.sum(last + 1, n - 1) : 0;
			if (emptyPlacesRight >= move) {
				last = binary_search(last + 1, n - 1, move);
			} else {
				last = binary_search(0, last - 1, move - emptyPlacesRight);
			}
			cards[last] = i;
			ft.add(last, -1);
		}

		for (int j = 0; j < n; j++) {
			if (j != 0) cout << " ";
			cout << cards[j];
		}
		cout << endline;
	}

	return 0;
}
