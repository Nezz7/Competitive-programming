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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int cond = true;
        int mx = -9;
        for (int i = 0; i < n; i++){
            if (mx == -1) cond = false;
            if (mx!= -9){
                if (a[i] >= mx) mx--;
                else mx = a[i] -1;
            }
            if (mx == -9 && a[i] < i){
                if (a[i] == a[i-1] && a[i] == 0) cond =false;
                if (a[i] == a[i-1]) mx = a[i] - 2;
                else mx = a[i] - 1;
            }
        }
        if (cond == true){cout << "Yes\n";
        continue;
        }
        mx = a[0] - 1;
        cond = true;
        for (int i = 1; i < n; i++){
            //debug(mx)
            if (mx == -1) cond = false;
            if (a[i]>= mx) mx--;
            else mx = a[i]-1;
        }
        if (cond)
        cout << "Yes" << endl;
        else cout << "No" << endl;
    }
 }
