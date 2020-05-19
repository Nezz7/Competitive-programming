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
    vector<int> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++) 
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) 
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) 
            bit[idx] += delta;
    }
};
int del (int x, int n, BIT & tree){
    int low = 0, hi = n;
    int to = 0;
    while(low <= hi){
        int mid = (low + hi+ 1) / 2;
        if(tree.sum(mid) >= x){
            to = mid;
            hi = mid - 1;
        }else low = mid + 1;
    }
    return to;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,t;
    cin >> n >> t;
    BIT tree (1e6 + 2);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.add(x, +1);
    }
    for(int i = 0; i < t; i++){
        int x;
        cin >> x ;
        if(x > 0) tree.add(x, +1);
        else tree.add(del(-x,n,tree),-1);
    }
    for(int i = 1; i <= n; i++){
        if(tree.sum(i,i)){
            cout << i << ' ';
            return 0;
        }
    }
    cout << del(1,n,tree) << endl;
}