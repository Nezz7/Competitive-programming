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
pair<int,int> a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    FenwickTree bit(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
        bit.add(i,1);
    }
    sort(a,a + n);
    int j = 0;
    LL ans = 0;
    for(int i = 0; i < n; i++){
        while (j < n && a[j].first == a[i].first ){
            int idx = a[j].second;
            bit.add(idx,-1);
            j++;
        }
        int idx = a[i].second;
        int l = bit.sum(0,idx);
        int r = bit.sum(idx,n - 1);
        ans += min(l,r);
    }
    cout << ans << endl;
}