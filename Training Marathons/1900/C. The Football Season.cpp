#include <bits/stdc++.h>
#define f first
#define s second
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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n,p,w,d;
    cin >> n >> p >> w >> d;
    for(LL y = 0; y < w ; y++){
        LL x = p - y * d;
        if (x % w or x < 0) continue;
        x /= w;
        if(x + y > n) continue;
        cout << x << " " << y << " " << n - x - y << endl;
        return 0;
    }
    cout << -1;
}