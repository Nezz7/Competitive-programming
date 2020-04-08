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
int a[MAXN],occ[MAXN];
 struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        for(int i = 0; i < n + 1; i++){
            occ[i] = 0;
        }
        for(int i = 0; i < n; i++)
            cin >> a[i], occ[a[i]]++;
        bool cond = true;
        int mx = *max_element(a,a+n);
        int smx = -1;
        for(int i = 1; i <= mx; i++){
            if(occ[i] < 1 or occ[i] > 2) cond = false;

            if(occ[i] == 2) smx = i;
        }
        if(smx == -1) cond = false;
        for(int i = 1; i <= smx; i++){
            if(occ[i] != 2) cond = false;
        }
        vector<pair<int,int>> out; 
        if(cond){
            FenwickTree tree(mx + 9);
            tree.add(0,1);
            int cur = 0;
            for(int i = 0; i < n; i++){
                tree.add(a[i],1);
                cur = max(cur,a[i]);
                int l = tree.sum(0,cur);
                int r = tree.sum(cur+1,mx + 1);
                //cout << l << ' ' << r  << "cur " << cur <<  endl;
                if (l == (cur + 1) && r == 0 && ((n - i - 1) == smx  or (n - i - 1) == mx) ){
                    out.emplace_back(i+1,n - i - 1);
                }
            }
        }
        cout << sz(out) << endl;
        for(auto cur : out){
                cout << cur.first << " " << cur.second <<endl;
            }
        
    }
}