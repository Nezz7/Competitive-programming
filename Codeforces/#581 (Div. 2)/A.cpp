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
    string s;
    cin >> s;
    reverse(all(s));
    int last = s[0] - '0';
    int n = s.size();
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            if(i % 2 == 0){
                if(last) ans = i/2 + 1;
                else ans = i/2;
            }else ans = i/2 + 1;
            last = i;
        }
    }
    cout << ans << endl;
}