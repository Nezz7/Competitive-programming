 #include <bits/stdc++.h>
 using namespace std;
 int dp[1001][1001];
 int main (){
        string s;
        cin>>s;
        int n=s.size();
        int mx=1;
        int start=0;
        for (int i=0;i<n;i++)
            dp[i][i]=1;
        for (int i=0;i<n-1;i++)
            if (s[i]==s[i+1]) {
                dp[i][i+1]=1;
                mx=2;
                start=i;
            }
       for (int j=2;j<n;j++)
            for (int i=0;i<n-j;i++)
                if (s[i]==s[i+j] && dp[i+1][i+j-1]){
                      dp[i][i+j]=1;
                      if (j+1>mx){
                          mx=j+1;
                          start=i;
                      }
                }
                for (int i=0;i<n;i++){
                    for (int j=0;j<n;j++)
                        cout<<dp[i][j]<<" ";
                cout<<endl;
                }
                cout<<s.substr(start,mx);
    }
