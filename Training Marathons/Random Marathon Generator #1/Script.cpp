#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
string ret = "return ";
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    while(getline(cin , s)){
        reverse(all(s));
        string res ="";
        for(int j = 1 ; ; ++j){
            if(s[j] == ' ') break;
            res += toupper(s[j]);
        }
        reverse(all(res));
        cout << "%token " << res << '\n';
    }
 
    return 0;
}
 