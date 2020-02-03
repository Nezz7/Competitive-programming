#include<bits/stdc++.h>
using namespace std;
    int dp[1001][1001];
    string longestPalindrome(string s) {
        int n=s.size();
        if (n==0) return "";
        for (int i=0;i<n;i++)
            dp[i][1]=1;
        string ans=s.substr(0,1);
        cout<<ans<<endl;
        for (int i=0;i<n-1;i++){
            if (s[i]==s[i+1]) dp[i][2]=1;
            if (dp[i][2]) ans=s.substr(i,2);
        }
        for (int j=3;j<=n;j++)
            for (int i=0;i<=n-j;i++){
                if (s[i]==s[i+j-1] && dp[i+1][j-2]) dp[i][j]=1;
                if (j>ans.size() && dp[i][j]) ans=s.substr(i,j);
            }
        return ans;
    }

int main (){
    string s;
    int k;
    cin>>s;
    cout<<longestPalindrome(s);
}
