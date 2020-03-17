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
int const MAXN = 1e7+ 9;
int occ[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n,m;
    cin >> n >> m;
    LL x = 0;
    for ( int i = 0; i < min(4* n,m); i++){
        x+= i;
        x %= n;
        occ[x] ++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans+= (occ[i] != 0);
    cout << ans;
}