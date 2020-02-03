#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e5+9;
int p [MAXN];
int find_set (int x){
    if (p[x]  == x) return x;
    return p[x] = find_set(p[x]);
}
bool union_set (int u, int v){
     u = find_set(u);
     v = find_set(v);
     if (u != v){
        if (u < v)
            swap(u,v);
        p[v] = u;
        return true;
     }
     return false;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie(0);
    int n, m;

    cin >> n >> m;
       for (int i = 0; i < n +3 ; i++)
        p[i] = i;
    for (int i = 0; i < m; i++){
        int u , v;
        cin >> u >> v;
        union_set(u,v);
    }

    int ans = 0;
    for (int i = 1 ; i <= n ; ){
        if (find_set(i)== i) i++;
        else {
            int nxt = find_set(i);
            for (int j = i; j <= nxt ; j++){
                ans += union_set(i,j);
            }
            i = nxt;
        }
    }
    cout << ans;
}
