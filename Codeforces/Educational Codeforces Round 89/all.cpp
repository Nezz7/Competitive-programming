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
int p[MAXN];
bool go (int x){
        if(x % 2 == 0){
        LL  tot = x;
        while(tot % 2 == 0) tot /= 2;
        if(tot > 1) return true;
        }
        int nbr = x;
        vector<int> v;
        while(x > 1){
            int d = p[x];
            v.pb(d);
            while(x > 1 && x % d == 0){
                x /= d;
            }
        }
      
        bool cond = false;
        for(int j = 0; j < sz(v)&& !cond; j++){
            for(int k = j + 1; k < sz(v) && !cond; k++){
                if(__gcd(v[j] + v[k],nbr) == 1){

                    return true;
                }
            }
        }
        return false;
    
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
     for(int i = 2; i < MAXN; i++)
        if(!p[i]){
            for(int j = i; j < MAXN; j += i)
                p[j] = i;
        }
    for(int x = 2; x <= 10000; x++){
        vector<int> v;
        for(int i = 2; i *i <= x; i++)
            if(x % i == 0){
                v.pb(x/i);
                v.pb(i);
            }
         bool cond = false;
         int aa = 0, bb = 0;
        for(int j = 0; j < sz(v)&& !cond; j++){
            for(int k = j + 1; k < sz(v) && !cond; k++){
                if(__gcd(v[j] + v[k],x) == 1){
                    aa = v[j];
                    bb = v[k];
                    cond = true;
                }
            }
        }
        bool c = go(x);
        if(c != cond){
            cout << x << " " << aa << ' ' << bb << endl;
        }
    }
}