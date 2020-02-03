#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int const MANX = 1e6;
int mx (ll x){
    int ret =0;
    for (ll i=0;i<33;i++){
            int bit = (x & ((1LL)<<i))>>i;
            if (i==0){
                ret+=bit;
                continue;
            }
            if (bit) ret+=(i+1);
    }
    return ret;
}
int main (){
    ll n,p;
    cin>>n>>p;
    int ans=0;
    for (int i=1;i<50;i++){
        int x=p*i;
        ll cur = n-x;
        if(cur > 0 && mx(cur)>=i && __builtin_popcount(cur)<=i ){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;


}
