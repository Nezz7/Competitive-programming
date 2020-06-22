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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    LL last = a[n - 1];
    LL ans = last;
    for(int i = n - 2; i >= 0; i--){
        ans += max(min(last - 1,(LL)a[i]),0LL);
        last = max(min(last - 1,(LL)a[i]),0LL);
    }
    cout << ans << endl;
}