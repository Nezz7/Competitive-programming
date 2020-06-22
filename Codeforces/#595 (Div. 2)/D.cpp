#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int const MAXN = 1e5+99;
int MOD = 1e5;
ll a[MAXN],mn[MAXN],mx[MAXN];
ll pow (ll a,ll b){
    if (b==0) return 1;
    ll x = pow(a,b/2);
    if (x>MOD) return -1;
    if(b&1){
        return a*x*x;
    }
    return x*x;
}
ll bs (ll x,ll k){
    ll L = 2 , R = 1e5;
    ll ans = 2;
    while (L<R){
        ll mid = (L + R)/2;
        ll cur = pow (mid,k);
        if (cur==-1){
            R=mid-1;
            continue;
        }
        if (cur<=x){
            L=mid+1;
            ans=mid+1;
        }else {
            if (check(cur))
                R = mid-1;
            else
        }
    }
    return ans;

}
int main (){
    fast;
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i],cout<<bs(a[i],k)<<endl;;


}
