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
    vector<LL> bit;  // binary indexed tree
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++) 
            add(i, a[i]);
    }
    LL sum(int r) {
        LL ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) 
            ret += bit[r];
        return ret;
    }
    LL sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) 
            bit[idx] += delta;
    }
};
void solve(int t){
    int n, q;
    cin >> n >> q;
    BIT tree1(n),tree2(n),tree3(n),tree4(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(i % 2 == 0){
            tree1.add(i,x);
            tree2.add(i,x * i);
            tree3.add(i,-x);
            tree4.add(i,-x * i);
        }else {
            tree1.add(i,-x);
            tree2.add(i,-x * i);
            tree3.add(i,x);
            tree4.add(i,x * i);
        }
    }
    LL ans = 0;
    while(q--){
        char c;
        cin >> c;
        if(c == 'Q'){
            int l,r;
            cin >> l >> r;
            l--,r--;
            if(l % 2 == 0){
                ans += tree2.sum(l,r) - (l - 1) * tree1.sum(l,r);
            }else {
                ans += tree4.sum(l,r) - (l - 1) * tree3.sum(l,r);
            }
        }else {
            int i, x;
            cin >> i >> x;
            i--;
            tree1.add(i,-tree1.sum(i,i));
            tree2.add(i,-tree2.sum(i,i));
            tree3.add(i,-tree3.sum(i,i));
            tree4.add(i,-tree4.sum(i,i));
            if(i % 2 == 0){
                tree1.add(i,x);
                tree2.add(i,x * i);
                tree3.add(i,-x);
                tree4.add(i,-x * i);
            }else {
                tree1.add(i,-x);
                tree2.add(i,-x * i);
                tree3.add(i,x);
                tree4.add(i,x * i);
            }
        }
    }
    cout << "Case #"<< t <<": " << ans << endl;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
       solve(t);
   }
}