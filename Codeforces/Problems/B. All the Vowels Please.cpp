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
 char c [] = {'a','e','i','o','u'};
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int cond = false;
    int x = 0;
    for (int i = 5; i <= n; i++){
        x = n/i;
        if (n % i == 0 && x >= 5){
            cond = true; break;
        }
    }
    if (cond == false){
        cout << -1;
        return 0;
    }
    int a[x];
    for (int  i = 0; i < x;i++) a[i] = i%5;
    for (int i = 0; i < n/x; i++){
        for (int j = 0; j < x; j++){
             cout << c[a[j]];
        }
        for (int j = 0; j < x; j++) a[j]++,a[j]%=5;
    }
 }
