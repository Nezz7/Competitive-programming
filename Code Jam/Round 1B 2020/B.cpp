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
LL xx1,yy1;
LL xx2,yy2;
LL get1 (LL x, LL y){
    LL a = x - xx1;
    LL b = y - yy1;
    return a *a + b*b;
}
LL get2 (LL x, LL y){
    LL a = x - xx2;
    LL b = y - yy2;
    return a *a + b*b;
}
int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    int A, B;
    cin >> T >> A >> B;
    LL R = A;
    while (T--){
        int mx = 1e9;
        bool cond = false;
        LL x,y;
        for(int i = 0; i < 110; i++){
            cout << mx - i<< ' ' << 0<< endl;
            cout << flush;
           string s;
            cin >> s;
            if(s ==  "CENTER"){
                cond = true;
                x = mx - i, y = 0;
                break;
            }
            if (s == "HIT"){
                xx1 = mx - i;
                yy1 = 0;
                break;
            }
        }
        if(cond){
            continue;
        }
        for(int i = 0; i < 110; i++){
            string s;
            cout << 0 << ' ' << mx - i << endl;
            cout << flush;
            cin >> s;
            if(s ==  "CENTER"){
                cond = true;
                x = 0, y = mx - i;
                break;
            }
            if (s == "HIT"){
                xx2 = 0;
                yy2 = mx - i;
                break;
            }
        }
        if(cond){
            continue;
        }
        for(int x = -1000; x <= 1000; x++){
            for(int y = -1000; y <= 1000; y++){
                    if (get1(x,y)  == R*R && get2(x,y) == R*R){
                        cout << x << ' ' << y << endl;
                         cout << flush;
                        string s;
                        cin >> s;
                        if(s ==  "CENTER"){
                            cond = true;
                            break;
                         }
                    }
            }
            if (cond) break;
        }
        if (cond == false) assert(1 == 3);
    }
}
