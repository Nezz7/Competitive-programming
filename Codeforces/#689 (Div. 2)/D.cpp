#include <bits/stdc++.h>
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
 struct BIT {
    #define T LL//define type
    vector<T> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) 
            ret += bit[r];
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
BIT tree(MAXN);
set<LL> vis, st;
vector<LL> a;
void solve(LL start, LL end){
    vis.insert(tree.sum(start,end));
    if(start == end){
        return;
    }
    LL mid = (start + end)/2;
    auto nxt = upper_bound(all(a), mid);
    solve(*nxt, end);
    nxt--;
    solve(start, *nxt);

}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vis.clear();
        st.clear();
        a.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            st.insert(x);
            tree.add(x, x);
        }
        for(auto x : st){
            a.push_back(x);
        }
        solve(*st.begin(), *st.rbegin());
        for(int i = 0; i < q; i++){
            int x;
            cin >> x;
            if(vis.count(x)) 
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }


        for(auto x : st){
            tree.add(x, -tree.sum(x,x));
        }
    }
}