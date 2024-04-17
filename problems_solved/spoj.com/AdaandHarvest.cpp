/*
        By: facug91
        From: https://www.spoj.com/problems/ADACROP/
        Name: ADACROP - Ada and Harvest
        Date: 29/12/2022
        Solution: implicit treap
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for an Implicit Treap.
 *        State: tested.
 *        Ref: https://cp-algorithms.com/data_structures/treap.html
 *             https://tanujkhattar.wordpress.com/2016/01/10/treaps-one-tree-to-rule-em-all-part-2/
 */
class ImplicitTreap {
private:
	using ValueType = long long;

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

	ValueType at(pItem t, int pos, int add = 0) {
		int currPos = add + size(t->l);
		if (currPos == pos) return t->val;
		if (currPos > pos) return at(t->l, pos, add);
		else /* if (currPos < pos) */ return at(t->r, pos, currPos + 1);
	}

	int findPos(pItem t, ValueType val, int add = 0) {
		if (!t) return -1;
		int currPos = add + size(t->l);
		if (t->val == val) return currPos;
		if (t->val > val) return findPos(t->l, val, add);
		else /* if (t->val < val) */ return findPos(t->r, val, currPos + 1);
	}

	int lowerBound(pItem t, ValueType val, int add = 0) {
		if (!t) return treeSize;
		int currPos = add + size(t->l);
		if (t->val == val) return currPos;
		if (t->val > val) return std::min(currPos, lowerBound(t->l, val, add));
		else /* if (t->val < val) */ return lowerBound(t->r, val, currPos + 1);
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

	void pushBack(ValueType val) {
		insert(val, treeSize);
	}

	ValueType at(int pos) {
		return at(root, pos);
	}

	void erase(int pos) {
		assert(pos >= 0 && pos < treeSize);
		pItem l, m, r;
		split(root, l, r, pos - 1);
		split(r, m, r, 0);
		merge(root, l, r);
		treeSize--;
	}

	/*
	 * Only works if the array was sorted.
	 * If not found, return -1;
	 */
	int findPos(ValueType val) {
		return findPos(root, val);
	}

	/*
	 * Only works if the array was sorted.
	 * If not found, return treeSize;
	 */
	int lowerBound(ValueType val) {
		return lowerBound(root, val);
	}

	int size() {
		return treeSize;
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

const int MAX_N = 2e5 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q, a[MAX_N], idx, val;
map<int, ImplicitTreap> mt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mt[a[i]].pushBack(i);
	}
	for (int i = 0; i < q; i++) {
		cin >> idx >> val;
		mt[a[idx]].erase(mt[a[idx]].findPos(idx));
		if (mt[val].size() == 0) {
			cout << 0 << endline;
			mt[val].pushBack(idx);
		} else {
			int pos = mt[val].lowerBound(idx);
			cout << pos << endline;
			mt[val].insert(idx, pos);
		}
		a[idx] = val;
	}

	return 0;
}
