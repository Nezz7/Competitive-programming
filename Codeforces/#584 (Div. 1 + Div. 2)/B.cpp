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
int const MAXN = 150 + 9;
int a[MAXN],b[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(auto & c : s){
        c -='0';
    }
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for(int i = 0; i <= 1e4; i++){
        int cur = 0;
        for(int j = 0; j < n; j++){
            if(i >= b[j]){
                if((i - b[j]) % a[j] == 0){
                    s[j] ^= 1;
                }
            }
            cur += s[j];
        }
        ans = max(ans,cur);
    }
    cout << ans << endl;
}