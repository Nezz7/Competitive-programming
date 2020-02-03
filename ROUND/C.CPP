#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
int const MAXN = 1e5;
ll p[MAXN];
ll a,b,x,y,k;
bool check (int n){
    ll g =(a*b)/ __gcd(a,b);
    ll sum=0;
    for (int i=0;i<n/g;i++)
        sum+=(p[i]/100)*x+(p[i]/100)*y;
    ll sum1=sum;
    ll sum2=sum;
    ll c=n/a;
    int start=n/g;
    for (int i=start;i<n/a;i++){
        sum1+=(p[i]/100)*x;
    }
    for (int i=0;i<n/b;i++){
        sum1+=(p[i+n/a]/100)*y;
    }
    for (int i=start;i<n/b;i++){
        sum2+=(p[i]/100)*y;
    }
    for (int i=0;i<n/a;i++){
        sum2+=(p[i+n/b]/100)*x;
    }
    return sum1>=k or sum2>=k;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while (q--){
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>p[i];
        sort(p,p+n);
        reverse(p,p+n);
        cin>>x>>a;
        cin>>y>>b;
        cin>>k;
        int L=1,R=n;
        int ans=-1;
        while(L<=R){
            int mid = (L+R)/2;
            if (check(mid)){
                R=mid-1;
                ans=mid;
            }else L=mid+1;
        }
        cout<<ans<<"\n";
    }



}
