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
    freopen("collectingofficer.in","r",stdin);
    int t;
    cin >> t;
    string al ="";
    for(int i = 0; i < 26; i++){
        al.push_back('A' + i);
    }
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 52000;
        for(int i = 0; i < n; i++){
            int k = 0;
            for(int j = i; j < n; j++){
               if(s[j] == al[k]){
                   k++;
               }
               if(k == 26){
                   ans = min(ans, j - i + 1);
                   break;
               }
            }
        }
        cout << ans << endl;
    }

}