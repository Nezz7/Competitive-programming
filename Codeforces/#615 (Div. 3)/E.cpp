#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define por(i,a,b) for(ll i=a;i<b;i++)
#define fp(ch) freopen(ch,"r",stdin)
#define ll long long
#define pb(x) push_back(x)
#define S second
#define f first
#define N 100005
#define OO 1000000000000000000
#define mod 1000000007
#define pi acos(-1)
#define EPS 0.000000001
using namespace std;
ll n,m,h;
ll down[N],nb[N];
vector<ll> g[N], gr[N],ng[N];
vector<vector<ll> > comps;
bool used[N];
vector<ll> order, component;
ll scc[N];
void dfs1 (ll v) {
    used[v] = true;
    for (ll i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i]])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (ll v) {
    used[v] = true;
    component.push_back (v);
    for (ll i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i]])
            dfs2 (gr[v][i]);
}


int main(){
    fs;
    cin>>n>>m>>h;
    por(i,0,n) cin>>down[i];
    ll a, b;
    por(i,0,m) {
        cin>>a>>b;
        a--;b--;
        if(((down[a]+1)%h)==down[b]){
            g[a].push_back (b);
            gr[b].push_back (a);
        }
        if((((down[b]+1)%h)==down[a])){
            g[b].push_back (a);
            gr[a].push_back (b);
        }
    }
    ll id=0;
    memset(used,false,sizeof used);
    for (ll i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    memset(used,false,sizeof used);
    for (ll i=0; i<n; ++i) {
        ll v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            for(auto node:component) scc[node]=id;
            id++;
            comps.push_back(component);
            component.clear();
        }
    }
    memset(nb,0,sizeof nb);
    por(i,0,n){
        for(ll j=0;j<g[i].size();j++){
            if(scc[i]!=scc[g[i][j]]){
                ng[scc[i]].push_back(scc[ g[i][j] ]);
            }
        }
    }
    ll res=OO,ri=-1;
    por(i,0,id){
        if(ng[i].size()==0 && comps[i].size()<res) ri=i,res=comps[i].size();
    }
    cout<<res<<endl;
    por(i,0,comps[ri].size()){
        cout<<comps[ri][i]+1<<" ";
    }
}
