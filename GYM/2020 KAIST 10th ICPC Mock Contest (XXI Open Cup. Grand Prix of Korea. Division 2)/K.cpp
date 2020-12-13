#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 1e9;
const int N = 1e3;

int n;
pair<pii,int> p[N+2];

int main(){ FAST
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    sort(p+1, p+n+1);

    cout << 2*n-1 << ln;
    for(int i=1; i<=n; ++i){
        cout << p[i].second << __;
    }
    for(int i=n-1; i>=1; --i){
        cout << p[i].second << __;
    }
    cout << ln;
}