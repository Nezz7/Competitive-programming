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
int block = 0;
int n,q;
set<pair<int,int>> st;
bool valid (int x,int y){
    return x >= 1 && x <= 2 && y >= 1 && y <= n;
}
void add(int x, int y){
    if(x == 1 && y == 1) block++;
    if(x == 2 && y == n) block++;
    st.insert({x,y});
    for(int i = - 1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if (i == 0) continue;
            if(st.count({x+i,y+j})) block++;
        }
    }
}
void del(int x, int y){
    if(x == 1 && y == 1) block--;
    if(x == 2 && y == n) block--;
    st.erase({x,y});
    for(int i = - 1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if (i == 0) continue;
            if(st.count({x+i,y+j})) block--;
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        if(st.count({x,y})) del(x,y);
        else add(x,y);
        if(!block) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}