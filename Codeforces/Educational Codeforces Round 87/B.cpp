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
        set<char> st;
        for(auto c : s){
            st.insert(c);
        }
        if(sz(st) != 3){
            cout << 0 << endl;
            continue;
        }
        int n = s.size();
        int ans = n;
        int idx = 0;
        st.clear();
        st.insert(s[0]);
        int last1 = n,last2 = n,last3 = n;
        for(int i = 0; i < n; i++){
            st.insert(s[i]);
            if(s[i] == '1') last1 = i;
            if(s[i] == '2') last2 = i;
            if(s[i] == '3') last3 = i;
            idx = min(last1,min(last2,last3));
            if(sz(st) == 3)  ans = min(ans, i - idx + 1);
        }
        cout << ans << endl;
    }
}