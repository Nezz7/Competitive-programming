#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
struct FenwickTree {
    vector<LL> bit;  // binary indexed tree
    LL n;
 
    FenwickTree(LL n) {
        this->n = n;
        bit.assign(n, 0);
    }
 
    FenwickTree(vector<LL> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    LL sum(LL r) {
        LL ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    LL sum(LL l, LL r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(LL idx, LL delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    pair<LL,LL> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    sort(a,a+n);
    FenwickTree ones(n);
    FenwickTree sums(n);
    priority_queue <pair <LL,LL> , vector <pair <LL,LL> >, greater <pair <LL,LL> > >pq;
    for (int i = 0; i < n; i++){
        sums.add(i,a[i].first);
        pq.push({a[i].second,i});
    }
 
    LL ans = 0;
    while(!pq.empty()){
        int i = pq.top().second;
        pq.pop();
        LL x = n - (i + 1) - ones.sum(i+1,n-1);
        LL sum = sums.sum(i+1,n-1);
        LL cur = sum - x * a[i].first;
        ones.add(i,1);
        sums.add(i,-a[i].first);
        ans += cur;
    }
    cout << ans << endl;
}