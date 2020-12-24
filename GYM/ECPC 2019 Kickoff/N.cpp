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
const int N = -1;

int main(){ FAST
    freopen("equal.in", "r", stdin);
    int _T; cin >> _T;
    for(int _t=1; _t<=_T; ++_t){
        //cout << "Case #" << _t << ": ";
        int x,y,z; cin >> x >> y >> z;
        if(x == y || y == z || x == z) cout << "YES" << ln;
        else cout << "NO" << ln;
    }
}