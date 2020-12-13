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
LL a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a, a + m);
    LL mn = 0;
    for(int i = 0; i < n - 1; i++){
        mn += a[i];
    }
    LL mx = 0;
    int idx = m - 1;
    for(int i = n - 1; i > 0; i--){
        idx = idx - i + 1;
        mx += a[idx];
        idx--;
    }
    cout << mn << "  " << mx << endl;
}