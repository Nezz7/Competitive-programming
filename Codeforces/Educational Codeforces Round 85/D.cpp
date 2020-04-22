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
LL n,l,r;
void go(int start,LL cnt){
    vector<int> v;
    if(start == n) v.pb(1);
    for(int i = start + 1; i <= n; i++){
        v.pb(start);
        v.pb(i);
    }
    if(cnt < l){
        for(int i = l - cnt; i < sz(v); i++){
            cout << v[i] << ' ';
            l++;
            if(l > r) return ;
        }
    }else {
        for(int i = 0 ; i < sz(v); i++){
            cout << v[i] << ' ';
            l++;
            if(l > r) return ;
        }
    }
    go(start + 1,l);
}
int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> l >> r;
        l--,r--;
        LL a[n];
        a[0] = 0;
        for(int i = 1; i < n; i++){
            a[i] = (n - i) * 2LL + a[i - 1];
        }
        int idx = upper_bound(a,a+n,l) - a - 1;
        go(idx + 1,a[idx]);
        cout << endl;
    }
}