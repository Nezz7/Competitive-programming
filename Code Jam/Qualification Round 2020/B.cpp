#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 500 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int ca = 0;
    while(T--){
        ca++;
        string s;
        cin >> s;
        string ans = "";
        int cur = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int d = s[i] - '0';
            if (cur < d){
                for (int x = 0; x < d - cur; x++) ans+="(";
            }
            if (cur > d){
                for (int x = 0; x < cur - d; x++) ans+=")";
            }
            ans +=  s.substr(i,1);
            cur = d;
        }
        for (int x = 0; x < cur ; x++) ans+=")";
        cout << "Case #"<< ca << ": " << ans << endl;

    }
}