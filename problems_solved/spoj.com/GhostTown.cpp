/*
        By: facug91
        From: https://www.spoj.com/problems/COUNT1IT/
        Name: COUNT1IT - Ghost Town
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
class ImplicitTreap {
private:
	using ValueType = long long;

	struct item {
		ValueType val, sum, lazy;
		int priority;
		int size;
		item* l, * r;

		item() = default;

		item(ValueType val) : val(val), sum(val), lazy(0), priority(rand()), size(1), l(nullptr), r(nullptr) {}

		item(ValueType val, int prior) : val(val), sum(val), lazy(0), priority(prior), size(1), l(nullptr), r(nullptr) {}
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

	void lazy(pItem t) {
		if (!t || !t->lazy) return;
		t->val += t->lazy; //operation of lazy
		t->sum += t->lazy * size(t);
		if (t->l)t->l->lazy += t->lazy; //propagate lazy
		if (t->r)t->r->lazy += t->lazy;
		t->lazy = 0;
	}

	void reset(pItem t) {
		if (t)t->sum = t->val; // lazy already propagated
	}

	void combine(pItem& t, pItem l, pItem r) { //combine segment tree ranges
		if (!l || !r) return void(t = l ? l : r);
		t->sum = l->sum + r->sum;
	}

	void operation(pItem t) { //operation of segment tree
		if (!t) return;
		reset(t); // node represents single element of array
		lazy(t->l);
		lazy(t->r); // imp: propagate lazy before combining l,r
		combine(t, t->l, t);
		combine(t, t, t->r);
	}

	void split(pItem t, pItem& l, pItem& r, int pos, int add = 0) {
		if (!t) return void(l = r = nullptr);
		lazy(t);
		int currPos = add + size(t->l);
		if (currPos <= pos)//element at pos goes to "l"
			split(t->r, t->r, r, pos, currPos + 1), l = t;
		else split(t->l, l, t->l, pos, add), r = t;
		updateSize(t);
		operation(t);
	}

	void merge(pItem& t, pItem l, pItem r) { //result/left/right array
		lazy(l);
		lazy(r);
		if (!l || !r) t = l ? l : r;
		else if (l->priority > r->priority) merge(l->r, l->r, r), t = l;
		else merge(r->l, l, r->l), t = r;
		updateSize(t);
		operation(t);
	}

	pItem init(ValueType val) {
		pItem ret = new item(val, rand());
		return ret;
	}

	ValueType rangeQuery(pItem t, int l, int r) { //[l,r]
		pItem L, mid, R;
		split(t, L, mid, l - 1);
		split(mid, t, R, r - l);//note: r-l!!
		ValueType ans = t->sum;
		merge(mid, L, t);
		merge(t, mid, R);
		return ans;
	}

	void updateRange(pItem t, int l, int r, ValueType val) { // [l,r]
		pItem L, mid, R;
		split(t, L, mid, l - 1);
		split(mid, t, R, r - l); // note: r-l!!
		t->lazy += val; // lazy update
		merge(mid, L, t);
		merge(t, mid, R);
	}

	ValueType at(pItem t, int pos, int add = 0) {
		lazy(t);
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

	ValueType rangeQuery(int l, int r) {
		return rangeQuery(root, l, r);
	}

	void updateRange(int l, int r, ValueType val) {
		updateRange(root, l, r, val);
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

const int MAX_N = 1e5 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, q, a, type, v;
ImplicitTreap tp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a;
		int pos = tp.lowerBound(a);
		tp.insert(a, pos);
	}
	for (int iq = 0; iq < q; iq++) {
		cin >> type >> v;
		if (type == 1) {
			int pos = tp.lowerBound(v + 1);
			int pos2 = tp.lowerBound(v + pos);
			tp.insert(v + pos, pos2);
		} else if (type == 2) {
			cout << tp.lowerBound(v + 1) << endline;
		} else {
			if (v > tp.size()) cout << "invalid" << endline;
			else cout << tp.at(v - 1) << endline;
		}
	}

	return 0;
}
