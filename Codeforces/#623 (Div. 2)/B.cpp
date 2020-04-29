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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a,b,p;
        cin >> a >> b >> p;
        string s;
        cin >> s;
        s = "#" + s;
        int n  = s.size();
        int ans = n - 1;
        for(int i = n - 3; i >= 0; i--){
            if(s[i] != s[i + 1]){
                if(s[i + 1] == 'A'){
                    if(p >= a){
                        p -= a;
                        ans = i +1; 
                    }else break;
                }else {
                    if(p >= b){
                        p -= b;
                        ans = i + 1; 
                    }else break;
                }
            }
        }
        cout << ans << endl;
    }
}