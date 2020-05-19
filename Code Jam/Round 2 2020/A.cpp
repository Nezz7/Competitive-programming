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
LL even (LL s, LL e){
    if((e & 1)) e--;
    return (e + s) * (e - s + 2) / 4;
}
void solve(int t){
    cout << even(4,5) << endl;

    cout << "Case #"<< t <<": " << 1<< endl; 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
   for(int t = 1; t <= T; t++){
       solve(t);
   }
}