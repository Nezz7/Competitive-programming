#include <bits/stdc++.h>
#define f first
#define s second
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
    int a,b,c;
    cin >> a >> b >> c;
    if (a == b && b == c){
        cout << '*';
    }
    if(a != b && a != c){
        cout << 'A';
    }
    if(a != b && b != c){
        cout << 'B';
    }
    if(c != b && a != c){
        cout << 'C';
    }
}