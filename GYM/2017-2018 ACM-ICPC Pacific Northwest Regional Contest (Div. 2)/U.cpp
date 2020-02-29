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
    LD a[6];
    LD ans = 0;
    for (int i = 0; i < 6; i++){
        cin >> a[i];
        ans +=(a[i] * (i + 1));
    }
    LD mn = 1e6;
    if (ans == 3.5) mn = 0;
    for (int i = 0; i < 6 ; i++){
        ans -= (a[i] * (i+1));
        LD cur = (3.50000000L - ans) / a[i];
        mn = min (abs(cur - i - 1L),mn);
        ans+= (a[i] * (i+1));

    }
    cout << fixed << setprecision(3);
    cout << mn;
}