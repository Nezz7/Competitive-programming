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
        int n;
        cin >> n;
        vector<int> ans;
        ans.push_back(4*n);
        for(int i = 4*n - 1; i >= 2 && sz(ans) < n; i--){
            bool cond = true;
            for(auto x : ans){
                if(x % i == 0 or __gcd(x,i) == 1){
                    cond = false;
                    break;
                }
            }
            if(cond) ans.push_back(i);
        }
        for(auto x : ans) cout << x << " ";
        cout << endl;
    }
}