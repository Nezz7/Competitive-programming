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
    while(T--){
        int n;
        cin >> n;
        pair<int,int> a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i].first  >> a[i].second;
        }
        bool cond = true;
        sort(a,a+n);
        for (int i = 1; i < n; i++){
            if (a[i].second < a[i-1].second) cond = false;
        }
        if (!cond){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int x = 0 , y = 0;
        for (int i = 0; i < n; i++){
            for (int j = x; j < a[i].first ; j++) cout << "R";
            for (int j = y; j < a[i].second ; j++) cout << "U";
            x = a[i].first;
            y = a[i].second;
        }
        cout << endl;
    }
 }
