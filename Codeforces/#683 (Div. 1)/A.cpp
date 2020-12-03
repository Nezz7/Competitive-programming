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
    int t;
    cin >> t;
    while(t--){
        LL n, w;
        cin >> n >> w;
        LL sum = 0;
        int ans = -1;
        vector<pair<LL,int>> a;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if( x >= (w + 1)/2 && x <= w){
                ans = i + 1;
            }
            if(x < (w + 1)/2){
                sum += x;
                a.emplace_back(x, i + 1);
            }
        }
        if(ans != -1){
            cout <<  1  << endl;
            cout << ans << endl;
            continue;
        }
        sort(all(a));
        vector<int> out;
        LL cur = 0;
        for(int i = 0; i < sz(a); i++){
            cur += a[i].first;
            if(cur >= (w + 1)/ 2 && cur <= w){
                for(int j = 0; j <= i; j++){
                    out.push_back(a[j].second);
                }
                break;
            }
            if(sum - cur >= (w + 1) / 2 && sum - cur <= w){
                for(int j = i + 1; j < sz(a); j++){
                    out.push_back(a[j].second);
                }
                break;
            }
        }
   
        if(sz(out)) {
            cout << sz(out) << endl;
            for(auto cur : out) cout << cur << " ";
            cout << endl;
        }else cout << -1 << endl;
    }
}