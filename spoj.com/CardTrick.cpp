/*
        By: facug91
        From: https://www.spoj.com/problems/CTRICK/
        Name: Card Trick
        Date: 01/12/2022
        Solution: brute force
*/

#include <bits/stdc++.h>

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

const int MAX_N = 2e5 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, n, cards[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>t;
	while (t--) {
		cin>>n;
		memset(cards, 0, sizeof(int) * n);
		cards[1] = 1;
		int last = 1;
		for (int i = 2; i < n; i++) {
			int j = 0;
			int move = (i + 1) % (n - i + 1);
			if (move == 0) move = n - i + 1;
			while (j < move) {
				last = (last + 1) % n;
				if (cards[last] == 0) j++;
			}
			cards[last] = i;
		}
		for (int i = 0; i < n; i++) {
			if (cards[i] == 0) {
				cards[i] = n;
				break;
			}
		}
		for (int j = 0; j < n; j++) {
			if (j != 0) cout << " ";
			cout << cards[j];
		}
		cout << endline;
	}
	return 0;
}
