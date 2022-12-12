
/**
 * Mo's algorithm template
 * Ref: https://cp-algorithms.com/data_structures/sqrt_decomposition.html#mos-algorithm
 *      https://codeforces.com/blog/entry/61203
 */

static_assert(false, "You shouldn't include this file, it's only a helper template.");

const int BlockSize = 200;

struct Query {
	int l, r, idx;

	bool operator<(const Query& other) {
		if (l / BlockSize != other.l / BlockSize) return l < other.l;
		return (l / BlockSize & 1) ? (r < other.r) : (r > other.r);
	}
};

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) return 0;
	int hpow = 1 << (pow - 1);
	int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = { 3, 0, 0, 1 };
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct OptimizeQuery {
	int l, r, idx;
	int64_t ord;

	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0); // To optimize even further, replace 21 with ceil(sqrt(N))
	}

	inline bool operator<(const OptimizeQuery& other) {
		return ord < other.ord;
	}
};