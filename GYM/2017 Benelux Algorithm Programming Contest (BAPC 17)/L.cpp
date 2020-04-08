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
map<string,LD> m;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    m["pink"] = 0;
    for(int i = 0; i < n; i++){
        string u,v;
        LD x;
        cin >> u >> v >> x;
        x = logl(x);
        if (m.count(v)){
            x += m[v];
            if (!m.count(u))
                m[u] = x;
            else m[u] = max(m[u], x);
        }
    }
    cout << setprecision(20);
    if (m.count("blue")){
        m["blue"] = min(10.L,m["blue"]);
        cout << min((LD) expl(m["blue"]),10.L);
    }else cout << 0;

}