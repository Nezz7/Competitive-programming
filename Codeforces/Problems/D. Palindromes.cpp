#include <bits/stdc++.h>
 using namespace std;
 string s;
 int k;
 int n;
 int pal[501][501];
 int dp [501][501];
 int ans;
 int solve (int i, int k){
    if (i == n){
            j--;
            i--;
            if (k >= 1) return pal[i-j + 1][j];
            return 1e9;
    }
    if (k < 0) return 1e9;
    int & ret = dp[i][k];
    if (ret != -1) return ret;
    for (int )
    et = min(solve (i+1,j+1,k),pal[i - j + 1][j] + solve(i+1,1,k-1));
 }
 void print (int i, int j, int k){
    if (i == n){
        j--;
        i--;
        int start = i - j +1;
        string str = s.substr(start,j);
        int m = str.size();
        for (int k = 0; k <m/2; k++){
            str[k]=str[m-1-k];
        }
        cout <<str;
        return;
    }
    if (ans == solve (i+1,j+1,k)){
        print(i+1,j+1,k);
        return ;
    }
    int start = i - j +1;
    string str = s.substr(start,j);
    int m = str.size();
    for (int k = 0; k <m/2; k++){
        str[k]=str[m-1-k];
    }
    cout <<str<< "+";
    ans-=pal[i - j + 1][j];
    print(i+1,1,k-1);
 }
 int main (){
    cin >> s >> k;
    n = s.size();
    memset(dp,-1,sizeof dp);
    // we can do it in o(n^2)
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= n - i ; j++){
            int cur = 0;
            string str = s.substr(i,j);
            int m = str.size();
            for (int k = 0; k <m/2; k++){
                cur += (str[k]!=str[m-1-k]);
            }
            pal[i][j]=cur;
        }
    }
    ans = solve (0,k);
    cout << ans  << "\n";
    print(0,1,k);
 }
