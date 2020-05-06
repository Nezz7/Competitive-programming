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
int x[MAXN];
char c[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int w = 0, b = 0;
        for(int i = 0; i < n; i++){
            cin >> x[i] >> c[i];
            if(c[i] == 'W') w += x[i];
            else b += x[i];
        }
        int g = __gcd(w,b);
        if(!b or !w){
            cout << w + b << endl;
            continue; 
        }
        w /= g;
        b /= g;
        int cur_b = 0;
        int cur_w = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(c[i] == 'W'){
                cur_w += x[i];
            }else cur_b += x[i];
            if(cur_w && cur_b){
                if(c[i] == 'W'){
                    int d = cur_b / b;
                    if(cur_b % b == 0 && cur_w >= d * w && cur_w - x[i] < d * w ){
                        ans ++;
                        cur_w -= d * w;
                        cur_b = 0;
                    }
                }else{
                    int d = cur_w / w;
                    if(cur_w % w == 0 && cur_b >= d * b && cur_b - x[i] < d * b ){
                        ans ++;
                        cur_b -= d * b;
                        cur_w = 0;
                    }
                }
            }
        }
        assert(!cur_b or !cur_w);
        cout << ans << endl;
    }
}