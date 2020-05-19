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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    cout << sz(s) << endl;
    /*int n;
    cin >> n;
    set<pair<int,int>> st;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        if(a){
            int g = __gcd(a,b);
            a /= g;
            b /= g;
            st.insert({-b,a});
        }
    }
    cout << sz(st) << endl;*/
}