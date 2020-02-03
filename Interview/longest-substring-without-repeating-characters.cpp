  #include <bits/stdc++.h>
  using namespace std;

  int main (){
      string s="";
      map<char,int>a;
        int ans=0;
        int cur=0,start=0;
        for (int i=0;i<s.size();i++){
            if (a.count(s[i])==0 or a[s[i]]<start ){
                cur++;
                a[s[i]]=i;
            }else {
                ans=max(ans,cur);
                start=a[s[i]]+1;
                cur=i-a[s[i]];
                a[s[i]]=i;
            }

    }
        ans=max(ans,cur);
        cout<<ans;
  }
