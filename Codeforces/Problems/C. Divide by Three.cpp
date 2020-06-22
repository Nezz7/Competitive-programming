#include <bits/stdc++.h>
using namespace std;
int const MAXN  = 1e5 + 9;
int n, cond;
string s;
int dp[MAXN][2][4];
int solve (int i, int l, int r){
    if (i == n){
        if (r % 3 == 0 && l ) return 0;
        return INT_MIN;
    }
    int & ret = dp[i][l][r];
    if (ret != -1) return ret;
    if (s[i]=='0' && l == 0)
       return ret = solve (i+1,l,r);
    return ret= max(solve (i+1,l,r),1 + solve (i+1,1,(r+s[i]-'0')%3));
}
void print (int i, int l, int r){
    if (i == n){
        return ;
    }
    if (s[i] == '0' && l == 0) {
        if (cond == 1 + solve(i+1,l,r)){
             cond --;
             print (i+1,l,r);
             return;
        }
        if (cond == 1){
            cond--;
            cout<<0;
            print (i+1,l,r);
            return ;
        }
    }
    if (cond == 1 + solve (i+1,1,(r+s[i]-'0')%3)){
        cond --;
        cout<<s[i];
        print(i+1,1,(r+s[i]-'0')%3);
        return;
    }
     print (i+1,l,r);
}
int main (){
    memset(dp,-1,sizeof dp);
    ios_base::sync_with_stdio(0);
    cin . tie(0), cout.tie(0);
    cin >> s;
    n = s.size();
    cond = solve (0,0,0);
    if (cond <= 0){
        for (int i = 0 ;i < n ;i++)
        if (s[i] == '0' ) { return cout << 0 , 0;}
        cout << "-1";
    }
    else  print(0,0,0);
}
