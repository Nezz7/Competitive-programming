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
        string s;
        cin >> s;
        int n = s.size();
        vector<char> ans;
        for(char c = 'a'; c <= 'z'; c++){
            int cur = 0;
            for(auto x : s){
                if(x == c) cur++;
                else {
                    if(cur & 1) break;
                    cur = 0;
                }
            }
            if(cur & 1)  ans .pb(c);
        }
        for(auto c : ans) cout << c;
        cout << endl;
    }
}