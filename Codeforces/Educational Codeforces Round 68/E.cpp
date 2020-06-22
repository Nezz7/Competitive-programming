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
int const d = 5000;
int const MAXN = d*2 + 9;
struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    BIT(vector<int> a) : BIT(a.size()) {
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
vector<int> add[MAXN];
vector<pair<int,int>> x[MAXN];
vector<pair<int,int>> y[MAXN];

int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+= d, x2+= d, y1+= d, y2+= d;
        if (x1 == x2){
            x[x1].push_back(minmax(y1,y2));
        }else y[y1].push_back(minmax(x1,x2));
    }
    LL ans  = 0;
    for (int i = 0; i < MAXN; i++){
        for(auto cury : y[i]){
            for(int j = 0; j < MAXN; j++) add[j].clear();
            BIT bit (MAXN);
            // add one to good one
            for(int idx = cury.first; idx <= cury.second; idx++){
                for(auto curx : x[idx]){
                    if(curx.first <= i &&  i < curx.second){
                            bit.add(idx,1);
                            add[curx.second].pb(idx);
                    }
                }
            }
            // looking for another horizental line
            for(int j = i + 1; j < MAXN; j++){
                for(auto line : y[j]){
                    LL sum = bit.sum(line.first,line.second);
                    ans += (sum - 1) * sum /2;
                }
                for(auto x : add[j]) bit.add(x,-1);
            }
        }
    }
    cout << ans << endl;
}