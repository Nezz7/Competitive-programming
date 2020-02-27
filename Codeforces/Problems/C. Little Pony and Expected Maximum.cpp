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
LD dp[MAXN];
LD solve (int i){

    dp[i] = ((1 + m) * m / 2) /(LD)m;
    for (int j = 1; j < i; i++)
        dp[i] += (1/(LD) m ) * solve(i - 1)
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> m >> n;
    cout << solve (n);
}