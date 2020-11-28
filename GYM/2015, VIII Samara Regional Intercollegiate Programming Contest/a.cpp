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
int const MAXN = 1e4 + 9;
int n, m;
LL dp [MAXN][701][3];
vector<tuple<int,int, int>> arr;
LL solve(int i, int m, int l){
    if (m < 0) return -1e18;
    if (i == n){
        return 0;
    }
    LL & ret = dp[i][m][l];
    if(ret != -1) return ret;
    ret = 0;
    int d = get<0> (arr[i]);
    int w = get<1> (arr[i]);
    LL  p = get<2> (arr[i]);
    if(l){
        ret = p + solve(i + 1, m - w + d, l - 1);
    }else ret = p + solve(i + 1 , m - w, l);
    
    return ret = max(ret, solve(i + 1, m, l));
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        int p, w , d;
        cin >> p >> w >> d;
        arr.push_back(make_tuple(d, w, p));
    }
    sort(rall(arr));
    cout << solve(0, m, 2) << endl;
}