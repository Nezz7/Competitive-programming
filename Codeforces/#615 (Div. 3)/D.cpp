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
 int tree[4*MAXN];
 int in[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int x, q;
    cin >> q >> x;
    int id = 0;
    int ans  = 0;
    if (x == 1){
        for (int i = 0; i < q;i++)
            cout << i +1 << endl;
        return 0;
    }
    while (q--){
        int n;
        cin >> n;
        n %= x;
        in[n]++;
        int  cur = (in[id] - 1) * x + id + 1;
        if (in[id] == 0) cur = -1;
        while (cur >= ans){
            id++;
            id%=x;
            cur = (in[id] - 1) * x + id + 1;
            if (in[id] == 0) cur = -1;
            ans++;
        }
        cout << ans << endl;
    }
 }
