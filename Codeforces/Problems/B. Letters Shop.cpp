#include <bits/stdc++.h>
using namespace std;
int const MAXN=2e5+9;
int sum[26][MAXN];
int cur[26];
bool can (int x){
    for (int i=0;i<26;i++)
          if (sum[i][x]<cur[i]) return false;
  return true;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++){
        sum[s[i]-'a'][i]++;
    }
    for (int i=1;i<n;i++)
        for (int j=0;j<26;j++)
            sum[j][i]+=sum[j][i-1];

    int t;
    cin>>t;
    int ans;
    while (t--){
        for (int i=0;i<26;i++) cur[i]=0;
        cin>>s;
        for (int i=0;i<s.size();i++) cur[s[i]-'a']++;
        int l=0,r=n-1;
        while (l<=r){
             int mid=(l+r)/2;
             if (can (mid)){
                ans=mid+1;
                r=mid-1;
             }else l=mid+1;
        }
        cout<<ans<<"\n";
    }



}
