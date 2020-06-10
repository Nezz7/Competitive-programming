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
string a = "RBL";
string b = "SKH";
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(i + 2 < n){
            set<char> st;
            for(int j = 0; j < 3; j++){
                st.insert(s[i + j]);
            }
            if(sz(st) == 3){
                cout << "C";
                i = i + 2;
                continue;
            }
        }
        for(int j = 0; j < 3; j++){
            if(s[i] == a[j]) cout << b[j];
        }
    }
}