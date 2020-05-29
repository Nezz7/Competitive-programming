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
        LL n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> z;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') z.pb(i);
        }
        int j = 0;
        vector<int> out;
        for(int i = 0; i < n; i++){
            if (j == sz(z)){
                out.pb(1);
                continue;
            }
            if(abs(i - z[j]) <= k){
                k -= abs(i - z[j]);
                out.pb(0);
                j++;
            }else out.pb(1);
        }
        for(auto x : out) cout << x;
        cout << endl;
    }
}