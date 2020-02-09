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
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n, time, a, b;
        cin >> n >> time >> a >> b;
        int v[n];
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<LL> easy;
        vector<LL> hard;
        for (int i = 0; i < n; i++){
            LL x;
            cin >> x;
            if (v[i] == 0) easy.pb(x);
            else hard.pb(x);
        }
        sort(all(easy));
        sort(all(hard));
        LL cur = 0;
        LL l = 0;
        LL r = 0;
        LL ans = 0;
        while (l + r < n){
            if (l < sz(easy) && r < sz(hard)){
                 l++, cur+=a;
            }else {
                if (l < sz(easy)){
                    cur+=a; l++;
                }else {
                    if (r < sz(hard)){
                        r++; cur+=b;
                    }
                }
            }

            while ((l < sz(easy) && easy[l] <= cur) or (r < sz(hard) && hard[r] <= cur)){
                while(l < sz(easy) && easy[l] <= cur) cur+=a,l++;
                while(r < sz(hard) && hard[r] <= cur) cur+=b,r++;
            }
            if (cur > time) break;
            ans = max(ans,r+l);
        }
        cout << ans << endl;
    }
 }
