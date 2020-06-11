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
string s;
int n;
bool is_pal(int l, int r){
    int sz = (r - l + 1);
    for(int i = 0; i < sz/2; i++){
        if(s[l + i] != s[r - i]) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> s;
    n = s.size();
    bool out = true;
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            bool cond = is_pal(l,r);
            if(cond){
                if((r - l + 1) % 2 == 0) out = false;
            }
        }
    }
    if(out) cout << "Odd." << endl;
    else cout << "Or not." << endl;

}