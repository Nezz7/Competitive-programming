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
int const MAXN = 1000 + 9;
const LL mod = 123456789;
LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
LL sub(LL x, LL y){
    x -= y;
    if(x < 0) x += mod;
    return x;
}
LL dp[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        
    }
}