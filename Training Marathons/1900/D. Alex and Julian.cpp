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
int const MAXN = 2e6 + 9;
vector<LL> p[100];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    int best = -1;
    for (int i = 0; i < n; i++){
        LL x;
        cin >> x;
        int id = __builtin_ctzll (x);
        p[id].push_back(x);
        if (sz(p[id]) > mx){
            best = id;
            mx = sz(p[id]);
        }
    }
    vector<LL> out;
    for(int i = 0; i < 100 ; i++){
        if(i == best) continue;
        for (auto x : p[i]){
            out.pb(x);
        }
    }
    cout << sz(out) << endl;
    for(auto cur : out){
        cout << cur << ' ';
    }

}