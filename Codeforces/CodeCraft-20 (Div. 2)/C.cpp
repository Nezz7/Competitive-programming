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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,p,m;
    cin >> n >>  m >> p;
    int ans = -1;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x % p && ans == -1) ans = i;
    }
    int ans2 = -1;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        if (x % p && ans2 == -1) ans2 = i;
    }
    cout << ans + ans2; 
}