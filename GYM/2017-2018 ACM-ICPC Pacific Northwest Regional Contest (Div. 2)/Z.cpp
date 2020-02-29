#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
bool cond (int x){
    while (x > 0){
        int d = x % 10;
        if (d == 0) return false;
        x/=10;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    n++;
    while (!cond(n)){
        n++;
    }
    cout << n ;
}