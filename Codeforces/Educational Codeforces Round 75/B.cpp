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
        int zero = 0, one = 0;
        int len[n];
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            len[i] = s.size();
            for(auto c : s){
                one += (c == '1');
                zero += (c == '0');
            }
        }
        sort(len,len + n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(len[i] & 1){
                if ((one & 1)){
                    if(one >= len[i]) ans++,one -= len[i];
                    else ans++, zero -= len[i] - one, one = 0;
                }else if ((zero & 1)){
                    if(zero >= len[i]) ans++,zero -= len[i];
                    else ans++, one -= len[i] - zero, zero = 0;
                }else if(one >= len[i]) ans++,one -= len[i];
                else ans++,zero -= len[i] - one,one = 0;
            }else {
                if(one >= len[i]) one -= len[i],ans++;
                else if(zero >= len[i]) zero -= len[i],ans++;
                else {
                    int x = one - (one & 1) + zero - (zero & 1);
                    if(x >= len[i]){
                        ans++;
                        zero -= len[i] - one + (one & 1);
                        one = (one & 1);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}