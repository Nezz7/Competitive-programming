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
bool cmp(string s, string s1){
    int i = 0;
    int j = 0;
    int n = s.size();
    int m = s1.size();
    while (i < n && j < m){
        bool digit = false;
        bool digit1 = false;
        LL x = 0;
        LL x1 = 0;
        if(isdigit(s[i])){
            digit = true;
            int k;
            for( k = i; k < n && isdigit(s[k]); k++){
                x = x * 10 + s[k] - '0';
            }
            i = k;

        }
        if(isdigit(s1[j])){
            digit1 = true;
            int k ;
            for( k = j; k < m && isdigit(s1[k]); k++){
                x1 = x1 * 10 + s1[k] - '0';
            }
            j = k;
        }
        if(digit1 && digit){
            if (x == x1) continue;
            return x > x1;
        }
        if (digit) return false;
        if (digit1) return true;
        if(s[i] == s1[j]){
            i++;
            j++;
            continue;
        }
        return s[i] > s1[j];
    }
    if (i == n && j == m) return false;
    if (i < n) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        string s1;
        cin >> s1;
        if (cmp(s,s1)) cout << "-" << endl;
        else cout << '+' <<endl;
    }
}