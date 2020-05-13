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
        for(auto & c : s) c -= '0';
        int n = s.size();
        vector<pair<int,int>> odd,even;
        for(int i = 0; i < n; i++){
            if(s[i] & 1){
                odd.pb({s[i],i});
            }else even.pb({s[i],i});
        }
        int idx;
        int od = 0;
        int ev = 0;
        for(int i = 0; i < n ;i++){
            if (od < sz(odd) && ev < sz(even)){
                if(odd[od].second < even[ev].second) idx = 1;
                else idx = 0;
            }else if(od == sz(odd)) idx = 0;
            else idx = 1;
            if (idx == 0){
                if(od < sz(odd) && even[ev].first > odd[od].first) cout << odd[od].first,od++;
                else cout << even[ev].first, ev++;
            }else {
                if(ev < sz(even) && even[ev].first < odd[od].first) cout << even[ev].first,ev++;
                else cout << odd[od].first,od++;
            }
        }
        cout  << endl;
    }
}