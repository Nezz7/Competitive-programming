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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        s = s + "L";
        int n = s.size();
        int cur = 1;
        int ans = 0;
        int cond = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == 'L' ) cur++;
            else{
                cond = 1;
                ans = max(cur,ans);
                cur = 1;
            }
        }
        ans = max(cur-1,ans);
        cout << ans << endl;
    }
}