/*
        By: facug91
        From: https://www.spoj.com/problems/POSTERIN/
        Name: Postering
        Date: 21/11/2022
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 250005;
const int MAX_K = 17;

int n, d, w[MAX_N], ans;
stack<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> d >> w[i];

	ans = 0;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() > w[i]) st.pop();
		if (st.empty() || st.top() < w[i]) {
			ans++;
			st.push(w[i]);
		}
	}

	cout << ans << endl;


	return 0;
}
}