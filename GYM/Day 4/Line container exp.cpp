#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
struct Line {
	mutable LL k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(LL x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	const LL inf = LLONG_MAX;
	LL div(LL a, LL b) { 
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(LL k, LL m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	LL query(LL x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
vector< tuple<LL, LL, LL> > a;

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n ;
    for(int i = 0; i < n; i++){
        LL x, y, s;
        cin >> x >> y >> s;
        a.push_back(make_tuple(x,y,s));
    }
    sort(all(a));
    LineContainer lc;
    lc.add(0,0);
    LL ans = 0;
    for(int i = 0; i < n; i++){
        LL x = get<0>(a[i]);
        LL y = get<1>(a[i]);
        LL s = get<2>(a[i]);
        LL dp = x * y - s + lc.query(y);
        lc.add(-x, dp);
        ans = max(dp, ans);
    }
    cout << ans << endl;
}