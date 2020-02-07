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
vector<int> a;
LL dp[50][2];
int n;
LL cnt (int pos, int cond){
    if(pos == n) return 1;
    LL& ret = dp[pos][cond];
    if (ret != -1) return ret;
    ret = 0;
    int lim;
    if (cond) lim = 9;
    else lim = a[pos];
    for (int i = 1; i <= lim; i++){
        int f = cond;
        if (i < a[pos]) f = 1;
        if (!cond && a[pos] > a[sz(a) - 1 - pos] && i == lim) ret += cnt (pos+1,cond);
        ret += cnt(pos+1,f);
    }

    int lm2 = 9;
    if (pos + 1 != a.size()) 
        ret+= (lm2 + 1);
    return ret;
}
LL solve (LL x){
    a.clear();
    while (x > 0){
        a.push_back(x % 10);
        x /= 10;
    }
    reverse(all(a));
    memset(dp,-1,sizeof dp);
    n = (sz(a) + 1) /2;
    return cnt(0,0);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int c = 0;
    while (T--){
        c++;
        LL a, b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        cout << "Case "<< c << ": "<< solve (b) - solve(a - 1) << endl;
    }
}