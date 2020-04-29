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
        int z = 0, o = 0;
        for(auto c : s){
            z+= (c == '0');
            o+= (c == '1');
        }
        if (!z or !o){
            cout << s << endl;
            continue;
        }
        int n = s.size();
        cout << s[0];
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]){
                int x = s[i] - '0';
                x ^= 1;
                cout << x << s[i];
            }else cout << s[i];
        }
        cout << endl;
    }
}