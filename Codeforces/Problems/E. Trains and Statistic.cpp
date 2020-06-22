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
int const MAXN = 1e5 + 9;
int const K = log2(MAXN)+1;
LL dp[MAXN];
int n;
int a[MAXN];
pair<int,int> st[MAXN][K];
pair<int,int> f(pair<int,int> a, pair<int,int> b){
    return max(a,b);
}
int lg[MAXN];
pair<int,int> get (int L, int R){
    int j = lg[R - L + 1];
    return f(st[L][j], st[R - (1 << j) + 1][j]);
}
void init (){
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++)
        lg[i] = lg[i/2] + 1;
    for (int i = 0; i < n; i++)
        st[i][0] = {a[i],i};
    for (int j = 1; j < K; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = f(st[i][j - 1],st[i + (1 << (j - 1)) ][j - 1]);
        }
    }
}
LL solve (int i){
    if (i == n - 1) return 0;
    LL &ret = dp[i];
    if (ret != -1) return ret;
    pair<int,int>  x = get(i,a[i]);
    ret = n - 1 - i + x.second - a[i]+ solve(x.second);
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> a[i],a[i]--;
    a[n-1] = n - 1;
    init();
    LL ans = 0;
    for (int i = 0; i < n - 1; i++){
        ans += solve(i);
    }
    cout << ans << endl;
}