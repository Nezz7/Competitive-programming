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
    int n,m;
    cin >> n >> m;
    string s[n],t[m];
    for (int i = 0; i < n ; i++) cin >> s[i];
    for (int i = 0; i < m ; i++) cin >> t[i];
    int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        x--;
        cout << s[x%n] << t[x%m] << endl;
    }
 }
