#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
map < pair < int, int >, int > m;

struct DSU{
    private:
        int parent[maxn];
        int sz[maxn];
    public:
    int find_set(int v) {
        assert(v < maxn);
        if (v == parent[v])  return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }
    void init(int n){
        assert(n < maxn);
        for(int i = 0 ; i < n ; ++i)
            make_set(i);
    }
    void union_sets(int a, int b) {
        assert(a < maxn);
        assert(b < maxn);
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
}dsu;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    int q;
    cin >> q;
    dsu.init(q);
    for(int i = 0 ; i < q ; ++i){
        int x, y;
        cin >> x >> y;
        if(m.find({x, y}) != m.end()){
            dsu.union_sets(m[{x, y}], i);
            m[{x, y}] = dsu.find_set(i);
        } 
        else m[{x, y}] = i;
    }
    int x = 0, y = 0, tx = 0, ty = 0;
    for(auto c : s){
        tx = x, ty = y;
        if(c == 'U') ++y;
        if(c == 'D') --y;
        if(c == 'L') --x;
        if(c == 'R') ++x;
        if(m.find({-x, -y}) != m.end()){
            int nx = -x + tx, ny = -y + ty;
            if(m.find({nx - x, ny - y}) != m.end()){
                dsu.union_sets(m[{-x, -y}], m[{nx - x, ny - y}]);
                m[{nx - x, ny - y}] = dsu.find_set(m[{nx - x, ny - y}]);
            }
            else m[{nx - x, ny - y}]= m[{-x, -y}];
            m.erase({-x, -y});
        }
    }
    map < int, pair < int, int > > ans;
    for(auto id : m)
            ans[id.second] = {id.first.first + x, id.first.second + y};
    for(int i = 0 ; i < q ; ++i){
        int par = dsu.find_set(i);
        cout << ans[par].first << ' ' << ans[par].second << '\n';
    }
    return 0;
}