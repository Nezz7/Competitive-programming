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
int const MAXN = 100 + 9;
int pref[MAXN],suf[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        suf[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            suf[i] = suf[i + 1] + (s[i] == '>'); 
        }
        pref[0] = 0;
        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + (s[i] == '<');
        }
        int ans = n - 1;
        for(int i = 0; i < n; i++){
            if(s[i] == '<') ans = min(ans,suf[i]); 
            else ans = min(ans,pref[i + 1]);
        }
        cout << ans << endl;
    }
}