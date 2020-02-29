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
    string s;
    cin >> s;
    n = s.size();
    int L = 0, R = 0, mx = 0;
    bool condR = true, condB = true;
    int cur = 0;
    int start = 0;
    for (int i = 0; i < n; i++){
        cur += (s[i] == 'R');
        cur -= (s[i] == 'B');
        if (cur  == 0){
            int j = i;
            while ( j >= 0 && s[j] == s[i]) j--;
            if (s[start] != s[i])
            start = j + 1,cur = i - j;       
            if (s[i] == 'B') cur *= -1;
        }
        if (abs(cur) > mx){
            L = start;
            R = i; 
            mx = abs(cur);
        }
         
    }
     cur = 0;
    for (int i = L - 1; i>=0; i--){
        cur += (s[i] == 'R');
        cur -= (s[i] == 'B');
        if (cur == 0) L = i;
    }
    L ++;
    R ++;
    cout << L << " " << R << endl;
}