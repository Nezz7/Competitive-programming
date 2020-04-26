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
int const MAXN = 3000 + 9;
string d[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[MAXN];
int n, k;
int dp[MAXN][MAXN];
int solve(int i, int k){
    if (i == n) return k == 0;
    int & ret = dp[i][k];
    if(ret != -1) return ret;
    ret = 0;
    for(int x = 9; x >= 0; x--){
        bool cond = true;
        int cur = 0;
        for(int j = 0; j < 7; j++){
            if(s[i][j] == '1' && d[x][j] =='0') cond = false;
            if(s[i][j] == '0' && d[x][j] =='1') cur++;
        }
        if (cond && cur <= k) ret = ret or solve(i+1, k - cur);
    }
    return ret;
}
void  print (int i, int k){
    if (i == n) return;
    for(int x = 9; x >= 0; x--){
        bool cond = true;
        int cur = 0;
        for(int j = 0; j < 7; j++){
            if(s[i][j] == '1' && d[x][j] =='0') cond = false;
            if(s[i][j] == '0' && d[x][j] =='1') cur++;
        }
        if (cond && cur <= k && solve(i+1, k - cur)){
            cout << x;
            print(i + 1, k - cur);
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof (dp));
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    if(solve(0,k)){
        print(0,k);
    }else cout << -1;
}

