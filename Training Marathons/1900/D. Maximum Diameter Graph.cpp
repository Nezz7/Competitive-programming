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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    vector<int> ones;
    vector<pair<int,int>> v;
    vector<pair<int,int>> edges;
    bool cond = true;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x == 1){
            ones.pb(i + 1);
        }else {
            v.emplace_back(x,i+1);
        }
    }
    sort(all(v));
    int m = sz(v);
    for(int i = m - 1; i > 1; i--){
        if (i == m - 1){
            v[i].first -= 2;
            v[i - 1].first --;
            v[0].first--;
            edges.emplace_back(v[i].second,v[i-1].second);
            edges.emplace_back(v[i].second,v[0].second); 
        }else {
            v[i].first --;
            v[i - 1].first --;
            edges.emplace_back(v[i].second,v[i-1].second); 
        }
    }
    if (sz(v) == 2){
        v[0].first--;
        v[1].first--;
        edges.emplace_back(v[0].second,v[1].second);
    }
    int d = max(m - 1,1);
    int i = 0;
    int j = 0;
    if(sz(ones) >= 1 && sz(v) >= 1){
        edges.emplace_back(v[0].second,ones[0]);
        v[0].first --;
        d++;
        j++;
        if(sz(ones) >= 2 && sz(v) >= 2){
            edges.emplace_back(v[1].second,ones[1]);
            v[1].first --;
            j ++;
            d++;
        }
    }
    for(;j < sz(ones); j++){
        if(i == m) break;
        if (v[i].first > 0){
            edges.emplace_back(v[i].second,ones[j]);
            v[i].first--;
        }else {
            i++;
            j--;
        }
    }
    cond = (j == sz(ones));
    if (cond){
        cout << "YES" << ' ' << d << endl;
        cout << sz(edges) << endl;
        for(auto cur : edges){
            cout << cur.first << ' ' << cur.second << endl;
        }
    }else cout << "NO";
}