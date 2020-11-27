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
    string a, b;
    cin >> a >> b;
    reverse(all(a));
    reverse(all(b));
    string x = a;
    int d = 1;
    if(a == b){
         int m = 0;
        for(int i  = 0; i < sz(a); i++) m += (a[i] -'0');
        if(m > 10) m %= 9;
        cout << m ;
        return 0;
    }
    while(x != b){
        if( d >= 9) break;
        bool cond = false;
        for(int i = 0; i < sz(x); i++){
            if(x[i] != '9'){
                x[i]++;
                cond = true;
                break;
            }else x[i] = '0';
        }
        if(!cond) x += "1";
        d++;
    }
    if(d >= 9) cout << 0;
    else {
        int m = 0;
        for(int i  = 0; i < sz(a); i++) m += (a[i] -'0');
        m %= 9;
        int x = m;
        int j = 1;
        for(int i = 1; i < d;i++){
            m *= (x + j);
            m %= 9;
            j++;
        }
        cout << m << endl;
    }

}