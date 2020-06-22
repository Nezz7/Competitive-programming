#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
LL a[MAXN],b[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <n;i++){
        int x;
        cin >> x;
        a[x%m]++;
        b[i] = x;
    }
    for (int i = 0; i < m; i++)
        if (a[i]>=2){
            cout << 0 << endl;
            return 0;
        }
    LL ans = 1;
    for (LL i = 0; i < n;i++){
        for (LL j = i+1; j < n; j++){
            if (i == j) continue;
                ans *= 1LL*abs(b[i]-b[j]);
                ans%= m;
        }
    }
    cout << ans << endl;
}