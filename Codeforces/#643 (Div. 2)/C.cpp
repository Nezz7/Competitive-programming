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
LL sum[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int x = a; x <= b; x++){
        sum[x + b] ++;
        sum[x + c + 1] --;
    }
    for(int i = 1; i < MAXN; i++) sum[i] += sum[i -1];
    for(int i = 1; i < MAXN; i++) sum[i] += sum[i -1];
    LL ans = 0;
    for(int z = c; z <= d; z++){
        if(z >= b + c) break;
        if(z < a + b) ans += (b - a + 1) * (c - b + 1);
        else {
            ans += sum[MAXN - 1] - sum[z];
        }
    }
    cout << ans << endl;
}