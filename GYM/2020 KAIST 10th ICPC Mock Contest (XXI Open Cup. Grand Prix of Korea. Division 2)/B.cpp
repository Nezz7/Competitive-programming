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
    int a, b, hp;
    cin >> a >> b >> hp;
    int dmg = b * 5;
    if(dmg < hp){
        cout << 1 << endl;
        return 0;
    }
    int mx = (hp + 4) / 5;
    int cards = a - b;
    LD ans = 0;
    for(int i = 0; i < mx; i++){
        int cur_b = b;
        int cur_a = a;
        LD p = 1;
        for(int j = 0; j < i; j++){
            p*= (cur_b / (LD)cur_a);
            cur_b--;
            cur_a--;
        }
        p*= (cards / (LD)(cur_a));
        ans += p;
    }
    cout << setprecision(10);
    cout << ans << endl;
}