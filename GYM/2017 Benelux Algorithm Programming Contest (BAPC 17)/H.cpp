#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
struct Point { 
    int x, y; 
};
pair < Point, Point > p[MAXN]; 
  
bool onSegment(Point p, Point q, Point r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
    return false; 
}
 
int orientation(Point p, Point q, Point r) { 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
} 
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) { 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
    if (o1 != o2 && o3 != o4) return true; 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
    return false;
}
 struct DSU {
    vector<int> root,sz;
    int cc ;
    DSU(int n){
        root.resize(n+1);
        sz.resize(n+1);
        for (int i = 0; i <= n; i++){
            root[i] = i;
            sz[i] = 1;
        }
        cc = n;
    }
    int find_set (int x){
        if (root[x] == x) return x;
        return root[x] = find_set(root[x]);
    }
    bool union_set(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if ( u == v ) return false;
        if(sz[u] < sz[v]) swap (u,v);
        root[v] = u;
        sz[u] += sz[v];
        cc--;
        return true;
    }
};
signed  main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i].first.x >> p[i].first.y >> p[i].second.x >> p[i].second.y;
    }
    DSU dsu(n*n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
        if (doIntersect(p[i].first,p[i].second,p[j].first,p[j].second)){
            ans += !dsu.union_set(i,j);
        }
    }
    cout << ans << endl;
}