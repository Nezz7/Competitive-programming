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
    LL  mx = 0;
    for (LL i = 0; i < 2001; i++){
        for (LL j = 0; j <= i; j++)
            mx = max(mx,i * i * j - j * j * j + j);
    }
    cout << log10(mx) << endl;
}