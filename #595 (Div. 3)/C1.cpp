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
 LL p[50];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    p[0] = 1;
    for (int i = 1; i < 39; i++){
        LL x = p[i-1] * 3;
        p[i] = x;
    }
    int T;
    cin >> T;
    while (T--){
        LL n;
        cin >> n;
        LL x = 0;
        int i = 0;
        while (x < n){
            x += p[i];
            i++;
        }
        i--;
        for (int k  = i; k>= 0 ; k--){
            if (x - p[k] >= n) x-= p[k];
        }
        cout << x << endl;
    }

 }
