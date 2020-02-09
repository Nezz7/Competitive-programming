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
    while ( T-- ){
        LL n, p , k;
        cin >> n >> p >>  k;
        LL a[n];
        for (int i = 0; i < n; i++ ) cin >> a[i];
        sort(a,a+n);
        LL can[n+1];
        LL ans = 0;

        LL psum = 0;
        LL sum = 0;
        for (LL j = k-1; j < n; j+=k){
                sum+=a[j];
                if (sum <= p) ans = max(ans,j+1);
            }
        for (int i = 0; i < k -1 ; i++){
             psum += a[i];
             LL sum = psum;
             LL cur = i+1;
             if (psum <= p ) ans = max(ans,cur);
            for (LL j = i+k; j < n; j+=k){
                sum+=a[j];
                if (sum <= p) ans = max(ans,j+1);
            }
        }
        //cout << endl;
        cout << ans << endl;
    }
 }
