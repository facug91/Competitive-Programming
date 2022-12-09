/*
        By: facug91
        From: https://www.spoj.com/problems/CITY2/
        Name: A Famous City
        Date: 21/11/2022
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;

int n, arr[MAX_N], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int it = 1;
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		stack<int> st;
		ans = 0;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && st.top() > arr[i])
				st.pop();
			if (st.empty() || st.top() < arr[i]) {
				if (arr[i] != 0) ans++;
				st.push(arr[i]);
			}
		}
		cout << "Case " << it++ << ": " << ans << endl;
	}

	return 0;
}
