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
int n,k;
void solve(vector<int> v,int n){
    if(sz(v) == n) {
        int mn = 1e9;
        int mx = 0;
        for(auto x : v) {
            mn = min(mn,x);
            mx = max(mx,x);
        }
        if(mx - mn +1 != sz(v) or mn != 1) return;
        for(auto x : v){
            cout << x << ' ';
        }
        cout << endl;
        return;
    }
    int sz = sz(v);
    int last = 1;
    if(sz)
    last = v[sz - 1];
    for(int i = 1; i <= n ; i++){
        v.pb(i);
        solve(v,n);
        v.pop_back();
    }
}
int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    vector<int> a;
    solve(a,n);
}