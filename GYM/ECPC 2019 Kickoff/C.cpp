#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")

#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn];
bool vis[maxn];
set < int > av, zer;
int n;
vector < int > ans;
const int L = 32;

set < int > bit[L];

void solve(int p){
    assert(!vis[p]);
    vis[p] = true;
    for(int j = 0 ; j < L ; ++j)
            if(a[p] & (1 << j))
                bit[j].erase(p);
    if(!a[p]) bit[L - 1].erase(p);
    ans.push_back(a[p]);
    while(true){
        int ans = n + 1;
        for(int j = 0 ; j < L ; ++j)
            if(a[p] & (1 << j)){
                if((int)bit[j].size() > 0)
                    ans = min(ans, *bit[j].begin());
            }
        if(ans == n + 1) break;
        solve(ans);
    }

    while(true){
        int ans = n + 1;
        for(int j = 0 ; j < L ; ++j)
            if(!(a[p] & (1 << j))){
                if((int)bit[j].size() > 0)
                    ans = min(ans, *bit[j].begin());
            }
        if((int)bit[L - 1].size() > 0) ans = ans = min(ans, *bit[L - 1].begin());
        if(ans == n + 1) break;
        solve(ans);
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("sorting.in", "r", stdin);
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
         cin >> a[i];
         for(int j = 0 ; j < L ; ++j)
            if(a[i] & (1 << j))
                bit[j].insert(i);
        if(!a[i]) bit[L - 1].insert(i);
    }
    solve(0);
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}