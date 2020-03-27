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
int const MAXN = 2e6 + 9;
int vis[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,r;
    cin >> n >> r;
    for(int i = 0; i < r; i++){
        int x;
        cin >> x;
        vis[x] = 1;
    }
    bool cond = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cond = true;
            cout << i <<  " ";
        }
    }
    if(!cond){
        cout <<"*";
    }
}