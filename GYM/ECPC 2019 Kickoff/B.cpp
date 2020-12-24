#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
LD f(LD a, LD b, LD c){
    LD s = (a + b + c)/2;
    LD arr = s * (s - a) * (s - b) * (s - c);
    if(arr <= 0) return 0;
    return sqrt(arr);
}
double eps = 1e-6; 
bool check(LD a, LD b, LD c){
    return (a + b - c >= eps) && (a + c - b >= eps) && (b + c - a) >= eps;
}
int main(){
    freopen("sticks.in","r", stdin);
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        LD a, b, c, k;
        cin >> a >> b >> c >> k;
     // l + c > b - a
     // l + b > c - a
     // a + l < b + c
                    
        LD zer = 0;
        LD l = max(zer, min(k, max(b - c, c - b) - a)), r = max(zer, min(k, b + c - a));
        LD ans = check(a, b, c) * f(a, b, c);
        for(int i = 0; i < 200; i++){
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            double f1 = f(a + m1, b, c);      
            double f2 = f(a + m2, b, c);      
            if (f1 < f2)
                l = m1;
            else
                r = m2;
        }
        if(check(a + l, b, c))
        ans = max(ans, f(a + l, b, c));
        l = max(zer, min(k, max(a - c, c - a) - b)), r = max(zer, min(k, a + c - b));
        for(int i = 0; i < 200; i++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            double f1 = f(b + m1, a, c);      
            double f2 = f(b + m2, a, c);      
            if (f1 < f2)
                l = m1;
            else
                r = m2;
        }
        if(check(a, b + l, c))
        ans = max(ans, f(b + l, a, c));
        l = max(zer, min(k, max(a - b, b - a) - c)), r = max(zer, min(k, a + b - c));
        for(int i = 0; i < 200; i++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            double f1 = f(c + m1, a, b);      
            double f2 = f(c + m2, a, b);      
            if (f1 < f2)
                l = m1;
            else
                r = m2;
        }
        if(check(a, b, c + l))
        ans = max(ans, f(c + l, a, b));
        cout << setprecision(12);
        cout << ans << endl;
    
    }
}