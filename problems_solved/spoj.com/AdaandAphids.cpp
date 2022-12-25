/*
        By: facug91
        From: https://www.spoj.com/problems/ADAAPHID/
        Name: ADAAPHID - Ada and Aphids
        Date: 24/12/2022
        Solution: Treap
*/

#include <bits/stdc++.h>

class Treap {
private:
	using ValueType = std::pair<long long, long long>;
	using CounterType = long long;

	struct item {
		ValueType key;
		int priority;
		CounterType cnt;
		item* l, * r;

		item() = default;

		item(ValueType key) : key(key), priority(rand()), l(nullptr), r(nullptr), cnt(0) {}

		item(ValueType key, int prior) : key(key), priority(prior), l(nullptr), r(nullptr) {}
	};

	using pItem = item*;

	pItem root;

	int count(pItem t) {
		return t ? t->cnt : 0;
	}

	void updateCounter(pItem t) {
		if (t) t->cnt = t->key.second + count(t->l) + count(t->r);
	}

	void heapify(pItem t) {
		if (!t) return;
		pItem max = t;
		if (t->l != nullptr && t->l->priority > max->priority) max = t->l;
		if (t->r != nullptr && t->r->priority > max->priority) max = t->r;
		if (max != t) {
			std::swap(t->priority, max->priority);
			heapify(max);
		}
	}

	void split(pItem t, ValueType key, pItem& l, pItem& r) {
		if (!t) l = r = nullptr;
		else if (t->key.first <= key.first) split(t->r, key, t->r, r), l = t;
		else split(t->l, key, l, t->l), r = t;
		updateCounter(t);
	}

	void insert(pItem& t, pItem it) {
		if (!t) t = it;
		else if (it->priority > t->priority) split(t, it->key, it->l, it->r), t = it;
		else insert(t->key.first <= it->key.first ? t->r : t->l, it);
		updateCounter(t);
	}

	void merge(pItem& t, pItem l, pItem r) {
		if (!l || !r) t = l ? l : r;
		else if (l->priority > r->priority) merge(l->r, l->r, r), t = l;
		else merge(r->l, l, r->l), t = r;
		updateCounter(t);
	}

	void erase(pItem& t, ValueType key) {
		if (t->key.first == key.first) {
			pItem th = t;
			merge(t, t->l, t->r);
			delete th;
		} else
			erase(key.first < t->key.first ? t->l : t->r, key);
		updateCounter(t);
	}

	pItem unite(pItem l, pItem r) {
		if (!l || !r) return l ? l : r;
		if (l->priority < r->priority) std::swap(l, r);
		pItem lt, rt;
		split(r, l->key, lt, rt);
		l->l = unite(l->l, lt);
		l->r = unite(l->r, rt);
		updateCounter(l);
		return l;
	}

	CounterType countLessEqual(const pItem& t, ValueType key) {
		if (!t) return 0;
		if (t->key.first > key.first) return countLessEqual(t->l, key);
		if (t->key.first <= key.first) return countLessEqual(t->r, key) + count(t->l) + t->key.second;
	}

public:

	pItem build(ValueType* a, int n) {
		// Construct a treap on values {a[0], a[1], ..., a[n - 1]}
		if (n == 0) return nullptr;
		int mid = n / 2;
		pItem t = new item(a[mid], rand());
		t->l = build(a, mid);
		t->r = build(a + mid + 1, n - mid - 1);
		heapify(t);
		updateCounter(t);
		return t;
	}

	void insert(ValueType newVal) {
		insert(root, new item(newVal));
	}

	void erase(ValueType val) {
		erase(root, val);
	}

	CounterType countLessEqual(ValueType key) {
		return countLessEqual(root, key);
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

ll q, l, a, v;
Treap t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	l = 0;
	cin >> q;
	for (int iq = 0; iq < q; iq++) {
		cin >> a >> v;
		a ^= l;
		v ^= l;
		t.insert(make_pair(a, v));
		l = t.countLessEqual(make_pair(a, v));
		cout << a << " " << l << endline;
	}

	return 0;
}
