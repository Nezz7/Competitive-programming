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
LD dp[MAXN][MAXN][2];
LD solve(int w, int b, int player){
    if(w == 0) return 0;
    if(b == 0){
        return 1 - player;
    }
    LD & ret = dp[w][b][player];
    if(ret == ret) return ret;
    ret = 0;
    int all = w + b;
    if(!player){
        return ret = w/(LD)all + b/(LD)all * solve(w, b - 1, 1);
    }
    if(all == 1) return ret = b/(LD)all;
    if(b >= 2)
    ret += b/(LD)all * (b - 1) /(LD)(all - 1) * solve(w, b - 2,0);
    if(b >= 1 && w >= 1)
    ret += b/(LD)all * (w)/(LD)(all - 1 ) * solve(w - 1 , b - 1,0);
    return ret;
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int w,b;
    cin >> w >> b;
    memset(dp,-1,sizeof(dp));
    cout << setprecision(20);
    cout << solve(w,b,0) << endl;
}