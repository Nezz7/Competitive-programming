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
int occ[MAXN];
int cnt[50][50];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for
    for(int i = 0; i < 100000; i++){
        occ[__builtin_popcount(i)]++;
        if(occ[__builtin_popcount(i)] == 1){
            for(int j = 0; j <= __builtin_popcount(i); j++){
                cout << occ[j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
    for(int i = 0; i < 6; i++) occ[i] = 0;
    for(int i = 0; i <= 25; i++){
         occ[__builtin_popcount(i)]++;
    }
    for(int i = 0; i < 6; i++) cout << occ[i] << ' ';
    cout << endl;
}