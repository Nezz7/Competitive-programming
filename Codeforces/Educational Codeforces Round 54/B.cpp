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
LL solve (LL x){
    if (x % 2 == 0) return x/2;
    for(LL i = 2; i * i <= x; i++){
        if (x % i == 0) return 1 + solve (x - i);
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL x;
    cin >> x;
    cout << solve(x);
}