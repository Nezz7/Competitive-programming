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
int h, c, t;
LD f(LL x){
    x = 2 * x + 1;
    LL a = (x + 1)/ 2;
    LL b = x / 2;
    return abs((a * h + b * c ) / (LD) x - t) ;
}
void brute(){
        LL l = 0, r = 100;
        LD ans = abs(h - t);
        int out = 1;
       for(int i = 1; i < 10; i++){
           int x = (i + 1) / 2;
           int y = (i) / 2;
           LD cur = abs((x * h + y *c) /(LD) i - t);
           if(cur < ans){
               ans = cur;
               out = i;
           }
       }
        cout << out << " " ;
    }

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T -- ){
        int h, c, t;
        cin >> h >> c >> t;
        brute();
         LL l = 0, r = 1e9;
        LD ans = 1e18;
        LL out;
        if(ans > abs((h + c)/ 2.0L - t)){
            ans = abs((h + c)/ 2.0L - t);
            out = 2;
        }
        while((r - l) > 3){
            LL m1 = l + (r - l) / 3;
            LL m2 = r - (r - l) / 3;
            LL f1 = f(m1);
            LL f2 = f(m2);
            if(f1 > f2){
                l = m1;
            }else r = m2;
        }
        for(LL i = l; i <= r; i++){
            if(ans > f(i)){
                out =  i * 2 + 1;
                ans = f(i);
            }
        }
        cout << out << endl;
    }
}