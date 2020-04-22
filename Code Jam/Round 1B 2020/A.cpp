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
int const MAXN = 1e5 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
    while (T--){
        cc++;
        LL x, y;
        cin >> x >> y;
        LL sum = (abs(x) + abs(y));
        bool px  = (x > 0);
        bool py = (y > 0);
        x = abs(x);
        y = abs(y);
        string ans = "";
        LL msb = -1;
        for(int i = 0; i < 40 ; i++){
            int bit  = !!(sum & (1LL << i));
            if(bit) msb = i;
        }
        LL curx = 0;
        LL cury = 0;
        for(int i = msb; i >= 0; i--){
            LL bit = (1LL << i);
            if (abs(curx - x) > abs(cury - y)){
                    if(x > curx){
                        curx+= bit;
                        ans += "E";
                    }else {
                        curx -= bit;
                        ans += "W";
                    }
                
            }else {
                    if(y > cury){
                        cury+= bit;
                        ans += "N";
                    }else {
                        cury -= bit;
                        ans += "S";
                    }
                
            }
        }
        reverse(all(ans));
        if(abs(x - curx) != 0 or abs(y-cury) != 0){
            ans = "IMPOSSIBLE";
        }else {
            if(px == false){
                for(auto& c :ans){
                    if(c == 'E') c = 'W';
                    else if(c == 'W') c = 'E';
                }
            }
            if(py == false){
                for(auto& c :ans){
                    if(c == 'S') c = 'N';
                    else if(c == 'N') c = 'S';
                }
            }
        }
        cout << "Case #"  << cc << ": " << ans << endl;
    }
}