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
int const MAXN = (1 << 21) + 9;
class EllysCheckers{
    public:
        int n;
        int dp[MAXN];
        int solve(int msk){
            msk &= (~(1 << n));
            if(__builtin_popcount(msk) == 0) return 0;
            int & ret = dp[msk];
            if( ~ ret ) return ret;
            ret = 0;
            for(int i = 0; i <= n; i++){
                int bit = !!(msk & (1 << i));
                if(bit){
                    if(i + 1 <= n && (msk & (1 << (i + 1))) == 0){
                        int nxt = msk & (~(1 << i));
                        nxt |= (1 << (i + 1));
                        if(!solve(nxt)) return ret = 1;
                    }
                    if(i + 3 <= n){
                        int bit1 = !!(msk & (1 << i + 1));
                        int bit2 = !!(msk & (1 << i + 2));
                        int bit3 = !!(msk & (1 << i + 3));
                        if(bit1 && bit2 && !bit3){
                            int nxt = msk & (~(1 << i));
                            nxt |= (1 << (i + 3));
                            if(!solve(nxt)) return ret = 1;
                        }
                    }
                }
            }
            return ret;
        }

        string getWinner(string board){
            memset(dp, -1, sizeof(dp));
            n = sz(board) - 1;
            int msk = 0;
            for(int i = 0; i <= n; i++)
                if(board[i] == 'o') msk |= (1 << i);
            int ans = solve(msk);
            if(ans) return "YES";
            return "NO";
        }
};
