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
int a[MAXN];
int p1[MAXN], p2[MAXN];
int query1(int x){
    if(p1[x] == x) return x;
    return p1[x] = query1(p1[x]);
}
int query2(int x){
    if(p2[x] == x) return x;
    return p2[x] = query2(p2[x]);
}
int main(){
    freopen("orxor.in", "r", stdin);
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, q;
    cin >> n >> q;
    LL sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < MAXN; i++)
        p1[i] = p2[i] = i;
    while(q--){
        int l, r;
        int t;
        cin >> t;
        cin >> l >> r;
        l--, r--;
        if(t == 1){
            for(int i = query1(l); i <= r; i = query1(i + 1)){
                sum -= a[i];
                a[i] |= (a[i] - 1);
                if(a[i] & 1) p1[i] = query1(i + 1);
                sum += a[i];
            }
        }else {
            for(int i = query2(l); i <= r; i = query2(i + 1)){
                sum -= a[i];
                a[i] ^= (a[i] - 1);
                if(a[i] == 1) p2[i] = query2(i + 1);
                sum += a[i];
            }
        }
        cout << sum << endl;
    }
}