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
string card[60];
int vis[60];
int cur[60];
int dp[60][60];
int solve(int i, int last){
    if(i == n) return 0;
    int &ret = dp[i][last];
    if(ret != -1) return ret;
    ret = 0;
    if(cur[i] >= last) ret = 1 + solve(i+1,cur[i]);
    ret = max(ret,solve(i+1,last));
    return ret;
}
map<char,int> mp;
int p[6];
char d [] = {'T', 'J', 'Q', 'K', 'A'};
char typ []= {'s', 'h', 'd', 'c'};
int mini (int i, int j){
    if(i == -1) return -1;
    if(vis[j]) return i;
    if(card[i][1] == card[j][1]){
        if(isdigit(card[i][0]) && isdigit(card[j][0])){
            if(card[i][0] < card[j][0]) return i;
            return j;
        }
        if(isdigit(card[i][0])) return i;
        if(isdigit(card[j][0])) return j;
        int xi = -1;
        for(int k = 0; k < 5; k++){
            if(card[i][0] == d[k]) xi = k;
        }
        int xj = -1;
        for(int k = 0; k < 5; k++){
            if(card[j][0] == d[k]) xj = k;
        }
        if(xi < xj) return i;
        return j;
    }
    return i;
}
int get_id(int i){
        int id = -1;
        for(int k = 0; k < 4; k++) if(typ[k] == card[i][1]) id = k;   
    return id;
    }
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> card[i];
        mp[get_id(i)]++;
    }
    for(int i = 0; i < 4; i++) p[i] = i;
    LL ans = 1e9;
    do{

        for(int i = 0; i < (1<<4); i++){
            int last = 0;
            for(int j = 0; j < 4; j++){
                int inc = !!(i & (1 << j));
                int all = mp[p[j]];
                memset(vis,0,sizeof (vis));
                for(int pos = 0; pos < all; pos ++){
                        int mn = -1;
                        for(int k = 0; k < n; k++){
                            if(mn == -1 && get_id(k) == p[j] && !vis[k]) mn = k;
                            else mn = mini(mn,k);
                        }
                        vis[mn] = 1;
                        if(inc)
                            cur[last + pos] = mn;
                        else cur[all - pos - 1 + last]  = mn;
                }
                last += mp[p[j]];
            }
            memset(dp,-1,sizeof (dp));
            LL ret = solve(0,0);
            ans = min(ans,n - ret);
        }
        
    }while(next_permutation(p,p+4));
    cout << ans << endl;
}