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
 vector<pair<int,pair<int,int>>> v;
 int tree[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, m, q;
        cin >> n >> m >> q;
        int a[m+2];
        v.clear();
        memset(a,0,sizeof (a));
        for (int i = 0; i <= m; i++){
            tree[i] = 0;
        }
        while (n--){
            int l,r;
            cin >> l >> r;
            a[l]++;
            a[r+1]--;
        }
        for (int i = 1; i <= m; i++){
             a[i]+= a[i-1];
        }
        int start = 1;
        for (int i = 1; i <= m; i++){
            if (a[i] == 1){
                if (start != i){
                    int r = i - 1;
                    v.push_back({r - start + 1,{r,start}});
                }
                    start = i + 1;
            }
        }
        if (a[m] == 0){
            v.push_back({m - start + 1,{m,start}});
        }
        int sv = sz(v) -1;
        if (sv >= 0){
            sort(all(v));
        }
        for(int i = sv; i >= 0; i--){
            tree[i]= max(tree[i+1],v[i].second.first);
        }
        while (q--){
            int len;
            cin >> len;
            if (sv < 0){
                cout << -1 << " " << -1 << endl;
                continue;
            }
            int idx  = lower_bound(all(v),make_pair(len,make_pair(-1,-1))) - v.begin();
            if (idx == sv +1)
                cout << -1 << " " << -1 << endl;
            else {
                    int ans = tree[idx];
                    cout << ans - len + 1<< " " << ans << endl;
            }
        }

    }
 }
