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
int n;
LL ans;
LL dp[MAXN][5], team[MAXN];
pair<LL,int> a[MAXN];
LL solve(int i, int nbr){
    if (i == n) {
        if(nbr == 0) return 0;
        return 1e18;
    }
    LL & ret = dp[i][nbr];
    if( ~ ret ) return ret;
    ret = 1e18;
    if(nbr == 2) ret = min(a[i].first + solve(i + 1, 0),solve(i + 1, 2));
    else if(nbr == 0) ret = min(ret,-a[i].first + solve(i + 1, 1));
    else ret = min(ret,solve(i + 1, nbr + 1));
    return ret;
}
int k = 1;
void gen (int i, int nbr){
    if (i == n) {
        return;
    }
    if(nbr == 2) {
        if(ans == a[i].first + solve(i + 1, 0)){
            ans -= a[i].first;
            team[a[i].second] = k;
            k++;
            gen(i + 1, 0);
            return ;
        }else {
            team[a[i].second] = k;
            gen(i + 1, 2);
            return ;
        }
        
    }else if(nbr == 0) {
        ans += a[i].first;
        team[a[i].second] = k;
        gen(i + 1, 1);
        return ;
    }else {
        team[a[i].second] = k;
        gen(i + 1, nbr + 1);
        return ;
    }
}


int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    ans = solve(0,0);
    LL ANS = ans;
    gen(0,0);
    cout << ANS << ' ' << k - 1 << endl;
    for(int i = 0; i < n; i++) cout << team[i] << ' ';
}