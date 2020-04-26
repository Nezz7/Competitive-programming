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
    int n;
    cin >> n;
    string s;
    cin >> s;
    LL ans = 0;
    LL nbrA = 0, nbrB = 0;
    LL fA = -1, fB = -1;
    LL ma = -1, mb = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            ans += nbrA;
            int d = i - fA - 1;
            if(d == 0) d++;
            if(nbrA)
            ans += max((nbrB - d),0LL);
            fA = i;
        }
         if(s[i] == 'B'){
            ans += nbrB;
            int d = i - fB - 1;
            if(d == 0) d++;
            if(nbrB)
            ans += max((nbrA - d),0LL);
            fB = i;
        }
        nbrA += (s[i] == 'A');
        nbrB += (s[i] == 'B');
    }
    cout << ans << endl;
}