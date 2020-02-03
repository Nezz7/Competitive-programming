#include <bits/stdc++.h>
using namespace std;
string s;
bool cond;
int const MAXN = 5e4+9;
int mod = 1e9+7;
int p[MAXN];
long long int pr[MAXN];
int find_set(int u){
    if (p[u] == u) return u;
    return p[u] = find_set(p[u]);
}
void union_set(int u,int v){
    u = find_set(u);
    v = find_set(v);

    if (u != v){
        if (s[u] == '?'){
            p[u] = v;
            s[u] = s[v];
        }else if (s[v] == '?') p[v] = u,s[v]=s[u];
        else if (s[u] != s[v]) cond = false;
        else p[u] = v;
    }

}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie(0); cout.tie(0);
    pr[0] = 1;
    for (int i = 1; i < MAXN ;i++)
        pr [i] = (26 * pr[i-1])%mod;
    int T;
    cin >> T;
    while (T--){
        cond = true;
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < n;i++)
            p[i]= i;
        cin >> s;
        while (m--){
            int u, v;
            cin >> u >> v;
            u--,v--;
            union_set(u,v);
        }
        for (int i = 0 ; i <n/2;i++)
            union_set(i,n-1-i);
        set<int> st;
        for (int i = 0; i < n; i++){

            if (s[find_set(i)] == '?'){
                st.insert(p[find_set(i)]);
            }
        }
        int id = st.size();

        if (cond){
            cout << pr[id] << "\n";
        }else cout << 0 << "\n";
    }

}
