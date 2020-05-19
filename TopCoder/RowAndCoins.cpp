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
int const MAXN = (1 << 14) + 9;
class RowAndCoins{
    public:
        string s;
        int n;
        int dp[MAXN][2];
        string p ="AB";
        int solve(int msk, int player){
            if(__builtin_popcount(msk) == n){
                for(int i = 0; i <= n; i++){
                    int bit = !!(msk & (1 << i));
                    if (!bit){
                        return s[i] == p[player];
                    }
                }
            }
            int & ret = dp[msk][player];
            if ( ~ ret ) return ret;
            ret = 0;
            for(int i = 0; i <= n; i++){
                int cur = 0;
                for(int j = i; j <= n; j++){
                    int bit = !!(msk & (1 << j));
                    if(bit) break;
                    cur |= (1 << j);
                    if(__builtin_popcount(msk | cur) == n + 1) break;
                    if(!solve(msk | cur,player ^ 1)) return ret = 1;
                }
            }
            return ret ;
        }

        string getWinner(string cells){
            s = cells;
            memset(dp, -1, sizeof(dp));
            n = sz(cells) - 1;
            int msk = 0;
            int ans = solve(msk,0);
            if(ans) return "Alice";
            return "Bob";
        }
};
