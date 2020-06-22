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
        map<char,int> mp;
        for(auto c : s){
            mp[c]++;
        }
        if(mp.size() == 1){
            cout << -1 << endl;
            continue;
        }
        int n = s.size();
        bool cond = false;
        for(int i = 0; i < n/2; i++){
            for(int j = i + 1; j < n; j++){
                if(s[i] != s[n - 1 - i]) {cond = true;break;}
                if(s[i] != s[j]){
                    swap(s[i],s[j]);
                    cond = true;
                }
            }
            if(cond) break;
        }
        cout << s << endl;
    }
}