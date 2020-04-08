#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e5 + 9;
vector <int> inv[MAXN];
int r [MAXN], l[MAXN];
int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        inv[l[i]].pb(i);
        inv[r[i] + 1].pb(- i);
    }
    vector<int> out;
    set<pair<int,int>> seg;
    for(int i = 1; i < MAXN; i++){
        for(auto x : inv[i]){
            if (x < 0){
                int id = -x;
                seg.erase({r[id],id});
            }else seg.insert({r[x],x});
        }
        while (sz(seg) > k){
            auto it = seg.rbegin();
            out.pb(it-> second);
            seg.erase({it -> first,it->second});
        }
    }
    cout << sz(out) << endl;
    for(auto cur : out){
        cout << cur << ' ';
    }
}