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
const int N = 3e5;

int n;
int h[N+2];

int main(){ FAST
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> h[i];
    }


    int ans = 1;
    int lo = 1, hi = n;
    while(lo <= hi){
        LL mid = (lo + hi)/2;
        
        bool valid = false;
        int bad = 0;
        for(int i=1; i<=mid; ++i){
            if(h[i] < mid) ++bad;
        }
        if(bad == 0) valid = true;
        for(int i=mid+1; i<=n; ++i){
            if(h[i-mid] < mid) --bad;

            if(h[i] < mid) ++bad;

            if(bad == 0) valid = true;
        }

        if(valid) ans = mid, lo = mid+1;
        else hi = mid-1;
    }

    cout << ans << ln;
}