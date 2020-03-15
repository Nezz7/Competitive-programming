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
int const MAXN = 509;
int n;
int a[MAXN], mem[MAXN][MAXN],dp[MAXN];
int get (int l, int r){
    if (l == r) return a[l];
    int & ret = mem[l][r];
    if (ret != -1) return ret;
    for (int i = l; i < r; i++){
        int x = get(l,i);
        int y = get(i+1,r);
        if (x == y && x) return ret = x + 1;
    }
    return ret = 0;
}
int solve(int p){
    if (p == n) return 0;
    int & ret = dp[p];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int j = p; j < n; j++){
        if(get(p,j)){
            ret = min(ret, 1 + solve(j+1));
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    memset(dp, -1 , sizeof dp);
    memset(mem, -1 , sizeof mem);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(0);
}