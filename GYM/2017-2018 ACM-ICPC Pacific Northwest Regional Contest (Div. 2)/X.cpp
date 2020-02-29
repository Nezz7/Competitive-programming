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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n ;
    cout << n <<':'<<endl;
    for (int i = 2; i <= (n+1)/2; i++){
        if (n % (i + i -1) == 0 or n % (i + i -1) == i ){
            cout << i << ',' << i-1 << endl;
        }
        if (n % (i + i) ==0 or (n % (2*i) == i)) 
            cout << i << ',' << i << endl;
    }
}