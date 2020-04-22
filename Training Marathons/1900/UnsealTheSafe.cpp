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
int const MAXN = 30 + 9;
LL dp[MAXN][5][5];
int n;
int a[4][3];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool valid(int x, int y){
    if (x == 3) return y == 0;
    return x >= 0 && x < 3 && y >= 0 &&  y < 3;
}
LL solve (int i, int x,int y){
    if ( i == n - 1 ) return 1;
    LL & ret = dp[i][x][y];
    if (ret != -1) return ret;
    ret = 0;
    for (int k = 0; k < 4; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];
       
        if(valid(xx,yy)) ret += solve(i+1,xx,yy);
    }
    return ret;
}
class UnsealTheSafe {
public:
	long long countPasswords(int N){
        n = N;
        memset(dp,-1,sizeof (dp));
        LL ans = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                ans += solve(0,i,j);
        ans += solve(0,3,0);
       return ans;
	}
};