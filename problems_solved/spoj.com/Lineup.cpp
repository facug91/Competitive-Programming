/*
        By: facug91
        From: https://www.spoj.com/problems/KOILINE/
        Name: KOILINE - Line up
        Date: 30/12/2022
        Solution: implicit treap
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for an Implicit Treap.
 *        State: tested.
 *        Ref: https://cp-algorithms.com/data_structures/treap.html
 *             https://tanujkhattar.wordpress.com/2016/01/10/treaps-one-tree-to-rule-em-all-part-2/
 */
template <typename ValueType>
class ImplicitTreap {
private:

	struct item {
		ValueType val;
		int priority;
		int size;
		item* l, * r;

		item() = default;

		item(ValueType val) : val(val), priority(rand()), size(1), l(nullptr), r(nullptr) {}

		item(ValueType val, int prior) : val(val), priority(prior), size(1), l(nullptr), r(nullptr) {}
	};

	using pItem = item*;

	pItem root;
	int treeSize{ 0 };

	int size(pItem t) {
		return t ? t->size : 0;
	}

	void updateSize(pItem t) {
		if (t) t->size = 1 + size(t->l) + size(t->r);
	}

	void split(pItem t, pItem& l, pItem& r, int pos, int add = 0) {
		if (!t) return void(l = r = nullptr);
		int currPos = add + size(t->l);
		if (currPos <= pos)//element at pos goes to "l"
			split(t->r, t->r, r, pos, currPos + 1), l = t;
		else split(t->l, l, t->l, pos, add), r = t;
		updateSize(t);
	}

	void merge(pItem& t, pItem l, pItem r) { //result/left/right array
		if (!l || !r) t = l ? l : r;
		else if (l->priority > r->priority) merge(l->r, l->r, r), t = l;
		else merge(r->l, l, r->l), t = r;
		updateSize(t);
	}

	pItem init(ValueType val) {
		pItem ret = new item(val, rand());
		return ret;
	}

	void toArray(pItem t, ValueType* arr, int add = 0) {
		if (!t) return;
		int currPos = add + size(t->l);
		arr[currPos] = t->val;
		toArray(t->l, arr, add);
		toArray(t->r, arr, currPos + 1);
	}

public:

	void insert(ValueType val, int pos) {
		assert(pos >= 0 && pos <= treeSize);
		auto newItem = init(val);
		if (!root) root = newItem;
		else {
			pItem l, r;
			split(root, l, r, pos-1);
			merge(l, l, newItem);
			merge(root, l, r);
		}
		treeSize++;
	}

	void reverse(int l, int r) {
		pItem L, R, mid;

		split(root, L, R, l - 1);
		split(R, mid, R, r - l);

		mid->rev ^= true;
		merge(R, mid, R);
		merge(root, L, R);
	}

	void toArray(ValueType* arr) {
		toArray(root, arr);
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

const int MAX_N = 1e5 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, h[MAX_N], s[MAX_N], pos[MAX_N], ans[MAX_N];
ImplicitTreap<int> tp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	sort(h, h + n);
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) tp.insert(i, s[i]);
	tp.toArray(pos);
	for (int i = 0; i < n; i++) ans[pos[i]] = h[i];
	for (int i = 0; i < n; i++) cout << ans[i] << endline;

	return 0;
}
