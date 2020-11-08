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
        LL a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        vector<int> open, close;
        int last = '0';
        int id = 0;
        for(auto c : s){
            if(c == '1' && last == '0'){
                open.push_back(id);
            }
            if(c == '0' && last =='1'){
                close.push_back(id - 1);
            }
            last = c;
            id++;
        }
        if(a < b){
            cout << a * sz(open) << endl;
            continue;
        }
        LL ans = 0;
        int merge = 0;
        for(int i = 1; i < sz(open); i++){
            if((open[i] - close[i -1] - 1) * b < a){
                ans += (open[i] - close[i -1] - 1) * b;
                merge++;
            }
        }
        ans += (sz(open) - merge) * a;
        cout << ans << endl;
    }
}