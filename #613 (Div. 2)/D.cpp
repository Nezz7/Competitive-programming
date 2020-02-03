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
    int n;
    cin >> n;
    int a[n];
    int ad = (1 << 30) - 1;
    int mx = 0;
    for (int i = 0; i < n; i++) cin >> a[i], ad &= a[i],mx = max(a[i],mx);
    //debug(ad)
    int cur1 = 0;
    int cur2 = 0;
    vector<int> v;
    int mx2 = mx;
    bool cond = true;
    for (int j = 29; j>=0 ; j--){
        if (mx & (1 << j)){
            v.push_back(1<<j);
            if (cond){
                cond = false;
                mx2 ^=(1<<j);
            }
        }
    }
    int cur3 = 0;
    for (int i = 0; i < n; i++){
        cur1 = max(a[i]^ad,cur1);
        cur2 = max(a[i]^mx,cur2);
        cur3 = max(a[i]^mx2,cur3);
    }
    int ans =  (1 << 30) - 1;
    for (auto  x : v){
        int cur = 0;
        for (int  i = 0; i < n; i++){
            cur = max(cur , x ^ a[i]);
        }
        ans = min( ans ,cur);
    }
    ans = min(cur3,ans);
    cout << min({cur1,cur2,ans}) << endl;
 }
