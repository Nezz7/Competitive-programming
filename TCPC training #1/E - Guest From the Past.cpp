#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define uid uniform_int_distribution
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const double PI = acos(-1);
template<class my>
using ind_set = tree<my,null_type,less<my>,rb_tree_tag,tree_order_statistics_node_update>;

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define all(vec) vec.begin(), vec.end()
#define fol(i,a,b) for(int i=a;i<b;i++)
#define loop(i,a,b) for(int i=a;i>=b;i--)
#define forr(x,arr) for(auto& x:arr)
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-7
#define sz(x) (int)(x).size()

using lli   = long long;
using lld   = long double;
using ulli  = unsigned long long int;
using pll   = pair<lli, lli>;
using ttt   = pair<lli, pll>;
using vttt  = vector<ttt>;
using vpll  = vector<pll>;
using vl    = vector<lli>;
using vvl   = vector<vector<lli>>;
using cd    = complex<long double>;

#ifdef tejasp
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.ff); __p(a.ss); cout << "} "; }
template<typename T, typename F, typename S>
void __p(pair<T,pair<F, S>> a) { cout << "{ "; __p(a.ff); __p(a.ss.ff); __p(a.ss.ss); cout << "} "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(; ;i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<"| ";
	__f(comma+1,args...);
}
template<typename Arg1, typename Arg2>
void __f(const char *names, Arg1 arg1[], Arg2 &&arg2){
    int i=0;
	for(; ;i++) if(names[i]==',') break;
	cout.write(names,i)<<" : { ";
	fol(i,0,arg2) __p(arg1[i]);
	cout << "} "<<endl;
}
#define trace(...) { cout<<"Line:"<<__LINE__<<" | "; __f(#__VA_ARGS__, __VA_ARGS__); }
#else
#define endl '\n'
#define trace(...)
#endif

inline lli mpow(lli a, lli b, lli m=mod) {
    int ans = 1;
    a=((a%m)+m)%m;
    while (b) {
        if (b & 1) ans = (ans*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return ans;
}

lli calc(lli l, lli r)
{
    r=(r-l-1)*(r-l)/2;
    r%=mod;
    return r;
}

void tejas_919(int kkkk)
{
    lli n, m, k, q, u, v, temp=0;
    cin>>n>>q;
    int arr[n+5]={};
    set<int> se [20];
    fol(j,0,20) se[j].insert(0),se[j].insert(n+1);
    fol(i,1,n+1)
    {
        cin>>arr[i];
        fol(j,0,20)
            if(!((arr[i]>>j)&1)) se[j].insert(i);
    }
    lli ans=0, power[20]={};
    power[0]=1;
    fol(i,1,20) power[i]=power[i-1]*2;
    fol(i,0,20)
    {
        fol(j,1,n+1)
        {
            u=*se[i].lower_bound(j)-j;
            temp=u*power[i];
            ans=ans+temp;
        }
    }
    while(q--)
    {
        lli l, r;
        cin>>u>>v;
        fol(i,0,20)
        {
            if(((arr[u]>>i)&1)==((v>>i)&1)) continue;
            se[i].erase(u);
            auto itr=se[i].upper_bound(u);
            r=*itr; itr--; l=*itr;
            temp=(u-l)*(r-u)*power[i];
            if((v>>i)&1)  ans+=temp;
            else    ans-=temp,se[i].insert(u);
        }
        cout<<ans<<endl;
        arr[u]=v;
    }

}

int main()
{
    #ifndef tejasp
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #endif
    cout << fixed << setprecision(10);
    int t=1;
    //cin>>t;
    fol(i,0,t) { tejas_919(i+1); }
}
