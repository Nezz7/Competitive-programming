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
 int sum[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    int mn = 1e9;
    while (n--){
        int l, r;
        cin >> l >> r;
        sum[l]++;
        sum[r+1]--;
        mx = max(mx,r);
        mn = min(mn,l);

    }
    bool cond = true;
    for (int i =  mn; i <= mx; i++) sum[i] += sum[i-1];
    cout << mn << " " << mx<< endl;
    for (int i = mn; i <= mx; i++){
        cout << sum[i] << " ";
        if (sum[i] >= 3) cond = false;
    }
    cout << endl;
    if (cond) cout << "YES\n";
    else cout <<"NO";
 }
