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
int const MAXN = 1e7 + 9;
int u[MAXN],is_prime[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    is_prime[1] = 1;
    for(int i = 1; i < MAXN; i++)
        u[i] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!is_prime[i]){
            u[i] = -1;
            for(int j = 2 * i; j < MAXN; j += i)
                is_prime[j] = i, u[j] = (j % (i * 1LL * i)) ? - u[j] : 0; 
        }
    }
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    LL ans = (b - a + 1) * (d - c + 1);
    for(int i = 2; i < MAXN; i++){
        LL x = b / i - (a - 1) / i;
        LL y = d / i - (c - 1) / i;
        ans += u[i] * (x * y);
    }
    cout << ans << endl;
}