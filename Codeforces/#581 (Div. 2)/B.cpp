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
int const MAXN = 30 + 9;
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    a[0] = 1;
    for(int i = 1; i < r; i++){
        a[i] = 1 << i;
    }
    LL mn = 0;
    for(int i = 0; i < l; i++){
        mn += a[i];
    }
    mn += n - l;
    LL mx = 0;
    for(int i = 0; i < r; i++){
        mx += a[i];
    }
    mx += (n - r) * 1LL * a[r - 1];
    cout << mn << ' ' << mx << endl;

}