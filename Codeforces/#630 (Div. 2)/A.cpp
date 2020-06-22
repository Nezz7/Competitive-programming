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
int x1,x2,y1,y2;
bool isvalid(int x,int y){
    return x1 <= x && x <= x2 &&  y1 <= y && y <= y2;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int x,y;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        bool cond = true;
        if ( a == b && a){
            if(!isvalid(x - 1, y) && !isvalid(x + 1, y)) cond = false;
        }
        if(c == d && c){
            if(!isvalid(x , y - 1) && !isvalid(x , y + 1)) cond = false;
        }
        int dx = b - a;
        if(!isvalid(x + dx, y)) cond = false;

        int dy = d - c;
        if(!isvalid(x, y  + dy)) cond = false;
        cout << ((cond) ?"YES" : "NO") << endl;
        
    }
}