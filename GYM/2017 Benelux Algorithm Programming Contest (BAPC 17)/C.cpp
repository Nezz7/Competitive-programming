#include "bits/stdc++.h"
using namespace std;
void __dump(long long x){cerr << x;}
void __dump(long double x){cerr << fixed << setprecision(3) << x;}
void __dump(char x){cerr << '\'' << x << '\'';}
void __dump(const string &x){cerr << '"' << x << '"';}
void __dump(const char *x){cerr << '"' << x << '"';}
void __dump(bool x){cerr << (x ? "true" : "false");}
void _dump(){cerr << "\n";}
template <typename T, typename U> void __dump(const pair<T, U> &x){cerr << '{'; __dump(x.first); cerr << ','; __dump(x.second); cerr << '}';}
template <typename T, typename U, typename V> void __dump(const tuple<T, U, V> &x){cerr << '{'; __dump(get<0>(x)); cerr << ',';  __dump(get<1>(x)); cerr << ',';  __dump(get<2>(x)); cerr << '}';}
template <typename T> void __dump(const T& x){int f=0; cerr << '{'; for(auto&i:x) cerr << (f++ ? "," : ""), __dump(i); cerr << "}";}
template <typename T, typename ... U> void _dump(T t, U ... u){__dump(t); if(sizeof...(u)) cerr << ", "; _dump(u...);}
#define dump(x ...) cerr  <<  "|| "  <<  # x  <<  " = ", _dump(x) 
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 2e9;
const int NN = 5e5;
int n;
LL a[NN+3];
set<LL> ans;
set<LL> ansi[NN+3];
long long gcd(long long aa, long long bb) { return (bb == 0 ? aa : gcd(bb, aa % bb));}
 
int32_t main(){ FAST;
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
 
	for(int i=1; i<=n; ++i){
		ans.insert(a[i]);
		ansi[i].insert(a[i]);
		for(LL prv: ansi[i-1]){
			ans.insert(gcd(prv,a[i]));
			ansi[i].insert(gcd(prv,a[i]));
		}
		ansi[i-1].clear();
	}
 
	cout << size(ans) << ln;
 
}