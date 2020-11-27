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
int const MAXN = 2e5 + 9;
LL bits[33];
int state[33];
int save[33][MAXN];
vector<LL> a;
int sz = 0;
void add_el(LL x){
    a.pb(x);
    sz++;
    for(int i = 0; i < 33; i++) bits[i] += !!(x & (1LL << i));
    for(int i = 0; i < 33; i++)
        save[i][sz(a) - 1] = state[i];
}
void del_el(LL x){
    LL cur = a[x - 1];
    for(int i = 0; i < 33; i++) bits[i] -= (!!(cur & (1LL << i)) ^ (save[i][x - 1] != state[i]));
    sz--;
    a[x - 1] = 0;
}
LL query(){
    LL ret = 0;
    for(int i = 0; i < 33; i++) ret += bits[i] * (1LL << i);
    return ret; 
}
void update(LL x){
    for(int i = 0; i < 33; i++) 
        if(x & (1LL << i)){
            bits[i] = sz - bits[i];
            state[i] ^= 1;
        }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        add_el(x);
    }
    while(q--){
        LL t, x;
        cin >> t >> x;
        if(t == 1){
            add_el(x);
        }
        if(t == 3){
            update(x);
        }
        if(t == 2){
            del_el(x);
        }
        cout << query() << endl;
    }
}