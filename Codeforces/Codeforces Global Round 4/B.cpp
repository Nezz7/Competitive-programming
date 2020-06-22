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
LL p[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for ( int i = 1; i < s.size(); i++){
        p[i] += p[i - 1];
        if(s[i - 1] == 'v' && s[i] == 'v'){
            p[i]++;
        }
    }
    LL ans = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'o'){
            ans+= p[i] * (p[n-1] - p[i]);
        }
    }
    cout << ans << endl;
}