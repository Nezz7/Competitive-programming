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
LL a[MAXN];
int p[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    p[1] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!p[i])
        for(int j = i; j < MAXN; j+= i){
            p[j] = i; 
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<vector<int>,int> cnt, cnt2;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cout << a[i] << " : ";
            if(a[i] == 1) {
                vector<int> v;
                cnt[r]++;
            }else{
                vector<int> r;
                while(a[i] > 1){
                    int d = p[a[i]];
                    int cur = 0;
                    while(a[i] > 1 && a[i] % d == 0){
                        cur ++;
                        a[i] /= d;
                    }
                    if(cur & 1){
                        r.push_back(d);
                    }
                }
                for(auto x : r) cout << x << " ";
                cout << endl;
                sort(all(r));
                cnt[r]++;
            }
        }
        int mx = 0;
        for(auto cur : cnt){
            mx = max(mx, cur.second);
            for(auto x : cur.first) cout << x << " ";
            cout << endl;
            cout << "cnt = " << cur.second << endl;
        }
        for(auto cur : cnt){
            if(cur.second & 1){
                cnt2[cur.first] = cur.second;
            }else {
                vector<int> r;
                cnt2[r] += cur.second;
            }
        }
        int mx2 = 0;
        for(auto cur : cnt2){
            mx2 = max(mx2, cur.second);
        }
        int q;
        cin >> q;
        for(int i = 0; i < 0; i++){
            LL x;
            cin >> x;
            if(x == 0) cout << mx << endl;
            else cout << mx2 << endl;
        }

    }
}