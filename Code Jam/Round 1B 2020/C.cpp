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
    int A, B;
    cin >> T >> A >> B;
    int R = A;
    while (T--){
        int mx = 1e9;
        bool cond = false;
        LL x,y;
        for(int i = -5; i <= 5; i++){
             for(int j = -5; j <= 5; j++){
                    cout <<i << ' ' << j << endl;
                    cout << flush;
                    string s;
                    cin >> s;
                       if(s ==  "CENTER"){
                        cond = true;
                        break;
                    }
             }
             if (cond) break;
        }
    }
}
