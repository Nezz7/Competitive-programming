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
bool divide (string &s, string &t){
    int j = 0;
    int n = t.size();
    for(int i = 0; i < s.size() ; i++){
        if(s[i] != t[j]) return false;
        j++;
        j%= n;
    }
    return j == 0;
}
string find (string s){
    for(int i = 0; i < s.size(); i++){
        string str = s.substr(0, i + 1);
        if(divide(s, str)) return str;
    }
    string ret = "";
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        if(s.size() < t.size()){
            swap(s,t);
        }
        string ss = find(s);
        string tt = find(t);
        if(ss != tt){
            cout << -1 << endl;
            continue;
        }
        int n = s.size() / ss.size();
        int m = t.size() / tt.size();
        int lcm = n * m / __gcd(n,m);
        for(int i = 0; i < lcm; i++) cout << ss;
        cout << endl;
    }
}