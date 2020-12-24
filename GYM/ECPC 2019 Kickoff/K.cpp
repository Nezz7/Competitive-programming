#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 1e9;
const int N = 1e5;

int n;
int h[N+2];
int g[N+2];

int main(){ FAST
    freopen("plants.in", "r", stdin);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> h[i];
    }

    for(int i=1; i<=n; ++i){
        cin >> g[i];
    }

    vector<pii> vect;
    for(int i=1; i<=n-1; ++i){
        int l;
        if(h[i] > h[i+1]){
            if(g[i] >= g[i+1]){ cout << -1 << ln; return 0; }

            int num = h[i] - h[i+1];
            int denom = g[i+1] - g[i];
            l = (num + denom - 1)/denom;
        }
        else l = 0;


        int r;
        if(h[i] > h[i+1]){
            if(g[i] >= g[i+1]){ cout << -1 << ln; return 0; }

            r = INF;
        }
        else{
            if(g[i] <= g[i+1]) r = INF;
            else{
                int num = h[i+1] - h[i];
                int denom = g[i] - g[i+1];
                r = num/denom;
            }
        }

        vect.emplace_back(l, r);
    }

    int l = 0, r = INF;
    for(auto [ll, rr]: vect){
        l = max(l, ll);
        r = min(r, rr);
    }

    if(!(l <= r)) cout << -1 << ln;
    else cout << l << ln;
}