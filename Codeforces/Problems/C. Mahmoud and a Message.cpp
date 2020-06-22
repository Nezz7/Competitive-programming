#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e3+6;
int mod = 1e9+7;
LL dp[MAXN][MAXN];
int a[26];
int n;
string s;
int tree[MAXN][MAXN];
int L , N;
LL solve (int i,int j ){
    L = max(j,L);
    if (i == n) return 1;
    LL & ret = dp[i][j];
    if (ret != -1) return ret;
    if (tree[i-j ][i] <= j)
     return ret = solve (i+1,1);
    return ret = (solve(i+1,1) + solve(i+1,j+1))%mod;
}

int main (){
    memset(dp,-1,sizeof dp);
    cin >> n >> s;
    for (int i = 0; i < 26; i++)
        cin >> a[i];
    for (int i = 0; i <n;i++){
        tree[i][i] = a[s[i]-'a'];
        for (int j = i+1 ; j < n; j++)
            tree[i][j]= min(tree[i][j-1],a[s[j]-'a']);

    }
    int cur = 1;
    int N = 1;
    for (int i = 1; i < n;i++){
        if (tree[i-cur][i] > cur) cur++;
        else N++,cur=1;
    }
    cout << solve(1,1)<< endl;
    cout << L << endl;
    cout << N << endl;
}
