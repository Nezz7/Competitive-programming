#include <bits/stdc++.h>
using namespace std;
int const MAXN=1e5+8;
int F[MAXN],fq[MAXN];
vector<int> ans;
void pre (string p){
    int n=p.size();
    for (int i=1,j=0;i<n;i++){
        while (j>0 && p[i]!=p[j]) j=F[j-1];
        if (p[i]==p[j]) F[i]=++j;
        else F[i]=j;
    }
    int k=F[n-1];
    while (k>0){
        ans.push_back(k);
        k=F[k-1];
    }
    reverse(begin(ans),end(ans));
    ans.push_back(n);
    for (int i=0;i<n;i++)
        ++fq[F[i]];
    for (int i=n-1;i>0;--i)
        fq[F[i-1]]+=fq[i];
}
 
int main (){
  string s;
  cin>>s;
  pre(s);
  cout<<ans.size()<<"\n";
 for (auto c: ans)
    cout<<c<<" "<<fq[c]+1<<"\n";
}