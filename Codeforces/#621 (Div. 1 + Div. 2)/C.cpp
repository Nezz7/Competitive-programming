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
int const MAXN = 1e5 + 9;
LL pref[26][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++){
        int x = s[i] - 'a';
        for (int j = 0; j < 26; j++)
        pref[j][i+1] = pref[j][i] + (j == x);
    }
    LL ans  = 0;
    for (int i = 0; i < 26; i++){
        ans = max(ans,pref[i][n]);
    }
    for (int i = 0; i < 26; i++){
        for (int j  = 0; j < 26; j++){
            LL cur = 0;
            for (int k = 0; k < n; k++){
                if (s[k] - 'a' == i){
                    cur+= (pref[j][n] - pref[j][k+1]);
                }
            }
            ans = max(cur,ans);
        }
    }
    cout << ans << endl;

}