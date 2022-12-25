/*
        By: facug91
        From: https://oj.uz/problem/view/COCI17_deda
        Name: DEDA (COCI17_DEDA)
        Date: 20/12/2022
        Solution: Segment tree
*/

#pragma GCC optimize("fast-math")
// begin "cp-lib/prelude.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define cp_lib_4th(_1, _2, _3, x, ...)  x
#define cp_lib_rep(i, l, r)             for (int i = (l); (i) < (r); ++(i))
#define cp_lib_rep0(i, r)               cp_lib_rep(i, 0, r)
#define rep(...)                        cp_lib_4th(__VA_ARGS__, cp_lib_rep, cp_lib_rep0, _)(__VA_ARGS__)
#define cp_lib_repr(i, r, l, ...)       for (int i = (r); (i) >= (l); --(i))
#define repr(...)                       cp_lib_repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : (b))

using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/prelude.hpp"
// begin "cp-lib/io.hpp"
// begin "_assert.hpp"
#ifdef CP_LIB_DEBUG
#define cp_lib_assert(expr) \
    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << #expr << " (" << __FILE__ << ':' << __LINE__ << ")\n"; \
        ::abort(); \
    } } while (0)
#else
#define cp_lib_assert(expr)
#endif
// end "_assert.hpp"
// begin "_type-meta.hpp"
#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif

namespace cp_lib_type_meta {
	struct NoOp { template <class... Args> void operator()(Args&&...) const noexcept {} };
	template <class T, class = void> constexpr bool is_tuple_like = false;
	template <class T> constexpr bool is_tuple_like<T, void_t<tuple_element_t<0, T>>> = true;
}
// end "_type-meta.hpp"
// begin "modint/_detect.hpp"
namespace cp_lib_modint { struct ModIntTag {}; }
// end "modint/_detect.hpp"
#include <unistd.h>

namespace cp_lib_io {
	constexpr int BUF_SIZE = 1 << 20;
	array<char, BUF_SIZE> ibuf, obuf;
	char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

	template <class T> constexpr bool is_std_array = false;
	template <class T, size_t I> constexpr bool is_std_array<array<T, I>> = true;

	void flush() {
		auto* p = begin(obuf);
		while (p != optr)
			p += write(STDOUT_FILENO, p, optr - p);
		optr = begin(obuf);
	}
	void ensure_write(int l) { if (end(obuf) - optr < l) flush(); }
	int _flush_atexit = []{ atexit(flush); return 0; }();
	void refill() {
		memmove(begin(ibuf), iptr, iend - iptr);
		iend -= iptr - begin(ibuf);
		iptr = begin(ibuf);
		iend += read(STDIN_FILENO, iend, end(ibuf) - iend);
	}
	void skip_ensure_read(int l) {
		do {
			while (iptr != iend && *iptr <= ' ') ++iptr;
			if (iend - iptr < l) refill();
		} while (*iptr <= ' ');
	}

	template <class T, class T2 = remove_reference_t<remove_cv_t<T>>>
	void print(T&& val) {
		if constexpr (is_same_v<T2, char>)
			ensure_write(2), *optr++ = val;
		else if constexpr (is_integral_v<T2> && !is_same_v<T2, bool>) {
			ensure_write(numeric_limits<T>::digits10 + 1 + is_signed_v<T2>);
			if (val < 0) { *optr++ = '-'; print(make_unsigned_t<T2>(-make_unsigned_t<T2>(val))); return; }
			array<char, 128> tmp;
			char* tptr = end(tmp);
			remove_const_t<T2> val_copy = val;
			do { *--tptr = char('0' + val_copy % 10), val_copy /= 10; } while (val_copy);
			memcpy(optr, tptr, end(tmp) - tptr);
			optr += end(tmp) - tptr;
#if __cpp_lib_to_chars >= 201611
			} else if constexpr (is_floating_point_v<T2>) {
            ensure_write(64);
            auto res = to_chars(optr, end(obuf), val, chars_format::fixed, 30);
            cp_lib_assert(res.ec == errc());
            optr = res.ptr;
#endif
		} else if constexpr (is_convertible_v<T, string_view>) {
			string_view sv(val);
			if (sz(sv) + 1 <= end(obuf) - optr)
				memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
			else {
				flush();
				for (auto *p = data(sv), *pe = p + sz(sv); p != end(sv); )
					p += write(STDOUT_FILENO, p, pe - p);
			}
		} else {
			if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
				print(int(val));
			else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T2>)
				print(decltype(T2::mod())(val));
			else if constexpr (cp_lib_type_meta::is_tuple_like<T2> && !is_std_array<T2>)
				apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
			else
				trav(item, val) print(item);
			return;
		}
		*optr++ = ' ';
	}

	template <class T>
	void read(T& val) {
		if constexpr (is_same_v<T, char>)
			skip_ensure_read(1), val = *iptr++;
		else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
			uint8_t ival; read(ival), val = bool(ival);
		} else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>) {
			ll ival; read(ival); val = T(ival);
		} else if constexpr (is_integral_v<T>) {
			skip_ensure_read(numeric_limits<T>::digits10 + 1 + is_signed_v<T>);
			if (is_signed_v<T> && *iptr == '-') {
				++iptr;
				make_unsigned_t<T> uval;
				read(uval);
				val = T(-uval);
			} else {
				val = 0;
				while (iptr != iend && *iptr > ' ') val = T(10 * val + (*iptr++ - '0'));
			}
#if __cpp_lib_to_chars >= 201611
			} else if constexpr (is_floating_point_v<T>) {
            skip_ensure_read(128);
            auto res = from_chars(iptr, iend, val);
            assert(res.ec == errc());
            iptr = const_cast<char*>(res.ptr);
#endif
		} else if constexpr (is_same_v<T, string>) {
			val = string();
			skip_ensure_read(1);
			do {
				auto* after = iptr;
				while (after != iend && *after > ' ') ++after;
				copy(iptr, after, back_inserter(val));
				if ((iptr = after) == iend)
					refill();
				else
					break;
			} while (iptr != iend);
		} else if constexpr (cp_lib_type_meta::is_tuple_like<T> && !is_std_array<T>)
			apply([](auto&... items) { (read(items), ...); }, val);
		else
			trav(item, val) read(item);
	}
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
	if (sizeof...(Args) > 0)
		(cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
	else
		cp_lib_io::ensure_write(1), *cp_lib_io::optr++ = '\n';
}

template <class... Args>
void printlns(Args&&... args) {
	((cp_lib_io::print(forward<Args>(args)), *(cp_lib_io::optr - 1) = '\n'), ...);
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }
// end "cp-lib/io.hpp"

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
const int invalid = 1e9 + 5;


/**
 * \brief Defines a class for a Segment Tree.
 *        State: untested.
 *        Ref: Competitive Programming 3, section 2.4.3
 *             https://cp-algorithms.com/data_structures/segment_tree.html
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 */
class SegmentTreePointUpdateRangeQuery {
private:
	int n;
	int st[MAX_N * 4];


	int combine(int a, int b) {
		return min(a, b);
	}

	int query(int v, int tl, int tr, int l, int r, int val) {
		if (l > r || st[v] > val) return -2;
		if (tl == tr) return tl;

		int tm = (tl + tr) / 2;
		int left = query(v * 2, tl, tm, l, std::min(r, tm), val);
		if (left != -2) return left;
		return query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val);
	}

	void update(int v, int tl, int tr, int pos, int val) {
		if (tl == tr) st[v] = val;
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) update(v * 2, tl, tm, pos, val);
			else update(v * 2 + 1, tm + 1, tr, pos, val);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

public:

	void build(int size, int val) {
		n = size;
		fill(st+1, st+n*4+1, invalid);
	}

	int query(int l, int r, int val) {
		return query(1, 0, n - 1, l, r, val);
	}

	void update(int idx, int val) {
		update(1, 0, n - 1, idx, val);
	}
};

int n, q, x, a, y, b;
char type;
SegmentTreePointUpdateRangeQuery st;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	read(n, q);
	st.build(n, invalid);
	while (q--) {
		read(type);
		if (type == 'M') {
			read(x, a);
			st.update(a - 1, x);
		} else if (type == 'D') {
			read(y, b);
			println(st.query(b - 1, n - 1, y) + 1);
		}
	}

	return 0;
}
