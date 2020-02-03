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
 int m[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    pair<int,int> a[n];
    for (int i = 0; i < n ; i++){
        cin >> a[i].f >> a[i].s;
    }
    sort(a,a+n);
    for (int i = n - 1; i >= 0; i--){
        m[i] = max(m[i+1],a[i].s);
    }
    int ans = 0;
    for (int i = 0; i < n ; i++){
       auto it = lower_bound(a,a+n,make_pair(a[i].f+1,a[i].s+1)) - a;
       ans +=(m[it] > a[i].s);
    }
    cout << n - ans;
 }
