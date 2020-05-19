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
int const MAXN = 100 + 9;
class BagsOfGold{
    public:
    int dp[MAXN][MAXN][2];
    vector<int> a;
    int solve(int l, int r, int player){
        if(l > r) return 0;
        int & ret = dp[l][r][player];
        if(~ ret ) return ret;
        ret = 0;
        if(!player) ret = max(a[l] + solve(l + 1,r, 1),a[r] + solve(l,r - 1, 1));
        else ret = min(-a[l] + solve(l + 1,r, 0),- a[r] + solve(l,r - 1, 0));
        return ret;
    }
    int netGain(vector<int> bags){
        int n = sz(bags) - 1;
        a = bags;
        memset(dp,-1,sizeof(dp));
        return solve(0,n,0);
    }

};
