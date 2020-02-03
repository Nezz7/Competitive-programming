#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e6 + 9;
map<int,int> id;
int last;
int p[MAXN],d[MAXN];
int get_id (int x){
    if (id[x] == 0) {
            id[x] = last;
            last ++;
            return id[x];
    }
    return id[x];
}
int find_set (int x){
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]);
}
int union_set (int u,int v){
    u = find_set (u);
    v = find_set (v);
    if (u < v) swap(u,v);
    if (u != v){
        p[v] = u;
    }
}
int main (){
freopen("out.txt","w",stdout);
LL  u,v;
for (int i = 0; i <MAXN; i++)
    p[i] = i;
 int c = 0;
 while (cin >> u >> v && u>=0 && v>=0){
    c++;
    if (u == v && v == 0){
         cout << "Case " << c << " ";
        cout << "is a tree.\n";
        continue;
    }
    int x = 1;
     last = 1;
    union_set(get_id(u),get_id(v));
    d[get_id(v)]++;
    while (cin >> u >> v && u && v){
         union_set(get_id(u),get_id(v));
        d[get_id(v)]++;
    }
    int root = 0;
    x = find_set(x);
    bool cond = true;
    for (auto y : id){
        int cur = y.second;
        if (find_set(cur) != x) cond = false;
        if (d[cur] == 0) root ++;
        if (d[cur]> 1) cond = false;
    }
    for (auto x : id){
        int cur = x.second;
        p[cur] = cur;
        d[cur] = 0;
    }
    cout << "Case " << c << " ";
    if (cond && root == 1) cout << "is a tree.\n";
    else cout << "is not a tree.\n";
    id.clear();
 }

}
