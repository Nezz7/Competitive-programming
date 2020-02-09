#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > in,de;
int a[2000];
int main(){
    int n,m;
    cin>>n>>m;
    while (m--){
       int t,l,r;
       cin>>t>>l>>r;
       if (t==1){
          in.emplace_back(l,r);
       }else de.emplace_back(l,r);
    }
    sort(in.begin(),in.end());
    sort(de.rbegin(),de.rend());
    for (auto cur : in){
        for (int i=cur.first;i<cur.second+1;i++)
                      a[i]=5000;
    }
    for (auto cur: de){
            for (auto c: in){
                if (c.first<=cur.first && cur.second<=c.second){
                    cout<<"NO";
                    return 0;
                }
            }
            if (a[cur.first+1]==0) a[cur.first+1]=1;
            a[cur.first]=a[cur.first+1]+1;
    }

         cout<<"YES\n";
         for (int i=1;i<=n;i++)
            if (!a[i]) cout<<1<<" ";
            else cout<<a[i]<<" ";

    }



