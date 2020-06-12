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
int const MAXN = 1e7 + 9;
int p [MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 2; i < MAXN; i++)
        if(!p[i]){
            for(int j = i; j < MAXN; j += i)
                p[j] = i;
        }
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
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
                    a[i] = v[j];
                    b[i] = v[k];
                    cond = true;
                }
            }
        }
        if(!cond && nbr % 2 == 0){
            LL  tot = nbr;
            while(tot % 2 == 0) tot /= 2;
            if(tot > 1){
                 a[i] = 2, b[i] = tot;
                cond = true;
            }
        }
        
        if(!cond) a[i]= b[i] = -1;
    }
    for(int i  = 0; i < n; i++) cout << a[i] << ' ' ;
    cout << endl;
    for(int i  = 0; i < n; i++) cout << b[i] << ' ';
}