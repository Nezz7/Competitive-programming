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
int const MAXN = 1e5 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
    while (T--){
        cc++;
        int x, y;
        cin >> x >> y;
        int ans = 1e9;
        string s;
        cin >> s;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'S') y--;
            if(s[i] == 'N') y++;
            if(s[i] =='E') x++;
            if(s[i] == 'W') x--;
            if(abs(x) + abs(y) <= i + 1){
                ans = i + 1;
                break;
            }
        }
        if(ans == 1e9)
            cout << "Case #"  << cc << ": " << "IMPOSSIBLE" << endl;
        else cout << "Case #"  << cc << ": " <<  ans << endl;
    }
}