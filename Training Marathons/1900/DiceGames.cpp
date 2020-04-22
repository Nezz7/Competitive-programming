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
int const MAXN = 50 + 9;
LL dp[MAXN][MAXN];
int a[MAXN];
int n;
LL solve(int i, int p,vector<int>&sides, int n){
    if (i == n) return 1;
    LL & ret = dp[i][p];
    if (ret != -1) return ret;
    ret = 0;
    for(int x = p; x <= sides[i]; x++){
        ret += solve(i+1,x,sides,n);
    }
    return ret;
}
class DiceGames {
public:
	long  countFormations(vector<int> sides){
        int n = sz(sides);
        sort(all(sides));
        memset(dp,-1,sizeof (dp));
       return solve(0,1,sides,n);
	}
};