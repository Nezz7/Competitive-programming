 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define LD long dobule
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);

    LL n, l, v1, v2, k;
    cin >> n >> l >>  v1 >> v2 >> k;
    long double tim = 0;
    bool cond = false;
    while (n){
        n-= k;
        n = max(n,0LL);
        long double d = l - (v1 * tim);
        debug(n)
        debug(d)
        long double d2 = d;
        if (cond){
        long double xt = d / (v1 + v2) + tim;
         d2 = l - (v1 * xt);
        if (d <= 0 or d2 <= 0) break;
        tim = xt;
        }
                if (d <= 0 or d2 <= 0) break;
        debug(d2)
        tim += d2 / v2;
        debug(tim)
        cond = true;
    }
    cout << tim << endl;
 }
