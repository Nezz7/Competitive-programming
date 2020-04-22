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
int main(){
      int dp[100];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        for(int i = 4; i <= 99; i++){
            if(!dp[i - 1] or !dp[i - 2] or !dp[i - 3]) dp[i] = 1;
            else dp[i] = 0;
        }
        for (int i = 0; i < 50; i++) cout << dp[i] << " " << ((i % 4) != 0) << endl;
      }