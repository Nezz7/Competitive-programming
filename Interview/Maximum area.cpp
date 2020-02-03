#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500];
bool check (double x){
    int g=k;
    for (int i=0;i<n;i++)
          g-=(int)(a[i]/x);
    return g<=0;
}
double bs (){
    double l=0,r=1e5;
    double ans=0;
    while(l<r){
       cout<<l<<" "<<r<<endl;
        if (abs(l-r)<1e-6) break;
        double mid=(l+r)/(2.0);
        if(check(mid)){
            ans=mid;
            l=mid;
        }else r=mid;
    }
    return ans;
}
int main (){
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i],a[i]*=a[i];
    double ans=bs();
    double pi=acos(-1);
    cout<<ans*pi;
}
