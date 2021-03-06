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
int solve(vector<int>& a, int bit){
    if(!sz(a) or bit < 0) return 0;
    vector<int>l,r;
    for(auto x : a){
        int cur = !!(x & (1 << bit));
        if(cur) l.pb(x);
        else r.pb(x);
    }
    if(!sz(l)) return solve(r, bit - 1);
    if(!sz(r)) return solve(l, bit - 1);
    return min(solve(l, bit - 1),solve(r, bit - 1)) + (1 << bit);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(a,30);
}