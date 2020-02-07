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
int const MAXN = 60;
int const MOD = 1e9 + 7;
string s;
LL dp[MAXN][MAXN][MAXN][MAXN][2];
LL vis[MAXN][MAXN][MAXN][MAXN][2];
int idx;
LL cnt (int pos, int cnt1, int cnt2, int cnt3, int cond){
    int lft = sz(s) - pos;
    if (3*max({cnt1,cnt2,cnt3}) - cnt1 - cnt2 - cnt3 > lft) return 0LL;
    if (pos == sz(s)) return (cnt1 == cnt2) && (cnt3 == cnt2) && (cnt1 > 0);
    LL & ret = dp[pos][cnt1][cnt2][cnt3][cond];
    if (vis[pos][cnt1][cnt2][cnt3][cond] == idx) return ret;
    vis[pos][cnt1][cnt2][cnt3][cond] = idx;
    ret = 0;
    int LMT;
    if (cond) LMT = 9;
    else LMT = s[pos] - '0';
    for (int i = 0; i <= LMT; i++){
        int f = cond;
        int c1 = cnt1, c2 = cnt2, c3 = cnt3;
        if (i < s[pos] - '0') f = 1;
        if (i == 3) c1++;
        if (i == 6) c2++;
        if (i == 9) c3++;
        ret = (ret + cnt (pos + 1,c1,c2,c3,f)) % MOD;
    }
    return ret;
}
LL solve (string x){
    s  = x;
    idx ++;
    return cnt (0,0,0,0,0);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        string a,b;
        cin >> a >> b;
        for (int i  = sz(a) - 1; i >= 0; i--)
            if (a[i] > '0') {a[i]--; break;}
        cout << (solve(b) - solve(a) + MOD) % MOD << endl;
    }
}