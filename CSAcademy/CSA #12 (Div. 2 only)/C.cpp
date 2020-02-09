#include<bits/stdc++.h>
#define In_the_name_of_allah_the_merciful ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Alhamdulillah return 0;
#define pb push_back
#define ins(x) insert(x)
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(v) (v.begin(),v.end())
#define sz(v) ((ll)((v).size()))
#define reset(v,val) memset(v,val,sizeof(v))
#define erep(i, x, n) for ( i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for( i = x; i<(ll)(n); i++)
using namespace std;
typedef   long long  int ll;
const long long int mod=1e9+7;
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,-1};
ll m,k,n,dp[500005];
string s1="one",s2="zero",ch="",s;
set< ll > st;
vector< pair<ll,ll> >vv,vv2,vm;
vector< pair< pair <ll,ll>,ll> > vvv1,vvv2;
vector< ll > vz;

vector<ll> z_function(string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    z[0]=0;
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

ll pow(ll a,ll b,ll mod)
{
  if(b==0) return 1;
  else if(b%2==0) return pow(a*a%mod,b/2,mod);
  else return pow(a,b-1,mod)*a%mod;
}



int main(){
In_the_name_of_allah_the_merciful

    ll i=0,x,y,j=0,z,q,nb0=0,nbp=0,nbn=0,nbmax=0,nbinf=0,nb2=0,mm=5e8,idx=0,ok=0,l,r,negatif=0,positif=0,l1,r1,t;
    set<ll> ::iterator it,it2;
    char c;
  // freopen("a.txt","r",stdin);
   cin>>s>>s1;
   n=s.size();
   k=s1.size();
   s2=s1;
   vz=z_function(s1);
   if(k>n)return cout<<"0",0;
   if(k==n)return cout<<(s==s1),0;
   ll res=0;
   for(ll lg=2*k;lg<n;lg++){
        ll rest=lg-2*k;
        res+=pow(10,rest,mod);
        res+=mod;
        res%=mod;
   }
   ll flag=0;
   for(i=0;i<k;i++){
    if(s[i]>s1[i]){
        flag=1;break;
    }
    if(s[i]<s1[i]){
         flag=-1;break;
    }
   }
   if(flag==1){
      ll rest=n-2*k;
      if(rest>0)res+=pow(10,rest,mod)%mod;
      res+=mod;
      res%=mod;
   }
   else if(!flag){
     for(i=k;i<n-k;i++){
            x=(s[i]-'0');
            ll rest=(n-k-i-1);
            ll ans=x*pow(10,rest,mod)%mod;
            res+=ans%mod;
            res%=mod;
            s1+=s[i];
      }
   }
   else if(flag==-1){
      //return cout<<"0",0;
   }
   s1+=s2;
   if((s1<=s )&&(s1.size()==s.size())){
     res++;
     res+=mod;
     res%=mod;
   }
   vz[0]=k;
   for(i=0;i<k;i++){
     if(vz[i]+i==k){
        if((k+i)==n){
            for(j=0;j<i;j++)s2+=s1[j];
            if(s2<=s)res++;
            //cout<<s2<<"   ***\n";
        }
        else if((k+i)<n)res++;
     }
     res+=mod;
     res%=mod;
   }
   cout<<res<<endl;

Alhamdulillah
 }
