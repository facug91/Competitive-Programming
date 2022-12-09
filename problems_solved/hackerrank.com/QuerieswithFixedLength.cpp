/*
        By: facug91
        From: https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
        Name:Queries with Fixed Length
        Date: 24/11/2022
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define endline std::endl;
#define LOG(x) std::cerr << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
typedef long long ll;

const int MAX_N = 1e5 + 5;
const int MAX_K = 18;

template<typename ValueType, typename Compare = std::less<ValueType>>
class MinMaxQueue {
private:
	Compare comp;
	std::vector<std::pair<ValueType, ValueType>> st1, st2;

public:

	void reset() {
		while (!st1.empty()) st1.pop();
		while (!st2.empty()) st2.pop();
	}

	void print() {
		std::cout << "Stack 1:";
		for (int i = 0; i < st1.size(); i++)
			std::cout << " (" << st1[i].first << ", " << st1[i].second << ")";
		std::cout << std::endl;
		std::cout << "Stack 2:";
		for (int i = 0; i < st2.size(); i++)
			std::cout << " (" << st2[i].first << ", " << st2[i].second << ")";
		std::cout << std::endl;
	}

	ValueType front() {
		if (st1.empty() || st2.empty())
			return st1.empty() ? st2.back().second : st1.back().second;
		else
			return comp(st1.back().second, st2.back().second) ? st1.back().second : st2.back().second;
	}

	void push(ValueType newElem) {
		int bestValue = (st1.empty() || comp(newElem, st1.back().second)) ? newElem : st1.back().second;
		st1.push_back({ newElem, bestValue });
	}

	void pop() {
		if (st2.empty()) {
			while (!st1.empty()) {
				int element = st1.back().first;
				st1.pop_back();
				int bestValue = (st2.empty() || comp(element, st2.back().second)) ? element : st2.back().second;
				st2.push_back({ element, bestValue });
			}
		}
		st2.pop_back();
	}
};

int solve2(const vector<int>& arr, int d) {
	int ans = 2e6;

	MinMaxQueue<int, std::greater<int>> mq;

	for (int i = 0; i < d; i++)
		mq.push(arr[i]);

	for (int i = d; i <= arr.size(); i++) {
		ans = min(ans, mq.front());
		if (i < arr.size()) {
			mq.pop();
			mq.push(arr[i]);
		}
	}

	return ans;
}

vector<int> solve(vector<int> arr, vector<int> queries) {
	vector<int> ans;
	for (int query : queries) {
		ans.push_back(solve2(arr, query));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, d;
	vector<int> arr, queries;

	cin >> n >> q;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	queries.resize(n);
	for (int i = 0; i < q; i++)
		cin >> queries[i];
	auto ans = solve(arr, queries);
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << endline;

	return 0;
}
