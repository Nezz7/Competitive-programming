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
 int a[20],b[20];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,c,s;
    cin >> n >> c >> s;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int MX = (1 << n);
    int ans = 1e9;
    for (int bit = 0; bit < MX; bit++){
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (bit & (1 << i)){
                v.pb(i);
            }
        sort(all(v));
        do{
            int cookie = 0;
            int temp = 0;
            int bb = s;
            for (auto cur : v){
                int i = cur;
                if (cookie >= a[i]){
                    cookie -= a[i];
                    bb += b[i];
                }else {
                    int x = (a[i] + bb - 1 - cookie)/ bb;
                    debug(x)
                    temp += x;
                    cookie =   cookie + x * bb - a[i];
                    bb+=b[i];
                }
            }
            if (cookie >= c) ans = min(ans,temp);
            else {
                int x = (c + bb - 1 - cookie) / bb;
                temp+=x;
                ans = min(ans,temp);
            }
        }while(next_permutation(all(v)));
    }
    cout << ans << endl;
 }
