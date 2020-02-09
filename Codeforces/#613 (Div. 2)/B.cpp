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
        int n;
        cin >> n;
        LL a[n];
        LL sum = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
           sum += a[i];
        }
        int start = 0;
        LL cur = 0;
        LL mx =0;
        if (a[0] == 0) start = 1;
        for (int i = 0; i < n; i++){
            if (i + 1 == n && start == 0) continue;
            if (a[i] >= 0){
                cur+=a[i];
            }else if (a[i] < 0){
                if(abs(a[i]) > cur){
                    cur = 0;
                    start = i;
                }else cur += a[i];
            }
            mx = max(mx,cur);
        }
        cur = 0;
        start = n-1;
        if (a[n-1] == 0) start = n-2;
        for (int i = n-1; i >= 0; i--){
            if (i == 0 && start == n-1) continue;
            if (a[i] >= 0){
                cur+=a[i];
            }else if (a[i] < 0){
                if(abs(a[i]) > cur){
                    cur = 0;
                    start = i;
                }else cur += a[i];
            }
            mx = max(mx,cur);
        }
        //debug(mx)
        if (sum > mx) cout << "YES\n";
        else cout << "NO\n";
    }
 }
