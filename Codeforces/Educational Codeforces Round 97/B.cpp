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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> odd;
        for(int i = 0; i < n; i++){
            odd .push_back(i % 2 == (s[i] - '0'));
        }
        int last = 0;
        int cnt1 = 0, cnt2 = 0;
        for(auto x : odd){
            if(last == 0 && x == 1) cnt1++;
            last = x;
        }
        last = 1;
        for(auto x : odd){
            if(last == 1 && x == 0) cnt2++;
            last = x;
        }
        cout << min(cnt1, cnt2) << endl;
    }
}