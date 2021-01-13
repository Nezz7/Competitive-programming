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
int const MAXN = 2e6 + 9;
int Fs[100], Ft[100], nxt_s[100][26], nxt_t[100][26];
int dp[1005][55][55];
int vis[1005][55][55];
void build (string p, int F[], int nxt[][26]){
    int n = p.size();
    for (int i = 1,j = 0; i < n; i++){
        while ( j > 0 && p[i] != p[j]) j = F[j-1];
        if (p[i] == p[j]) F[i] = ++j;
        else F[i] = j;
    }
    for(int i = 0; i < n; i++){
        for(int k = 0; k < 26; k++){
            int cur = i;
            while(cur > 0 && p[cur] != (k + 'a'))
                cur = F[cur - 1];
            if(p[cur] == (k + 'a'))
                cur++;
            nxt[i][k] = cur;
        }
    }

}
string a, s, t;
int n;
int solve(int i, int ks, int kt){
    if(i == n) return 0;
    int & ret = dp[i][ks][kt];
    if(vis[i][ks][kt]) return ret;
    vis[i][ks][kt] = 1;
    ret = -1e9;
    for(int c = 0; c < 26; c++){
        if(a[i] == '*' or a[i] == ('a' + c)){
            int nks = nxt_s[ks][c];
            int nkt = nxt_t[kt][c];
            int add = 0;
            if(nks == s.size()){
                add++;
                nks = Fs[nks - 1];
            }
            if(nkt == t.size()){
                add--;
                nkt = Ft[nkt - 1];
            }
            //cout << " i = " << i << "  :" ;
            //cout << nks << " " << nkt << endl;
            ret = max(ret, add + solve(i + 1, nks, nkt));
        }
    }
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> a >> s >> t;
    n = a.size();
    build(s, Fs, nxt_s);
    build(t, Ft, nxt_t);
    memset(dp, -1, sizeof dp);
    memset(vis, 0, sizeof vis);
    cout << solve(0,0,0);
}

