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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, d = 0;
    for(auto c : s){
        a += (c == 'A');
        d += (c == 'D');
    }
    string out;
    if( a == d ) out = "Friendship";
    if ( a > d) out = "Anton";
    if ( d > a) out =  "Danik"; 
    cout << out;
}