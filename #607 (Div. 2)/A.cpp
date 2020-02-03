#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.size();
        if (s[n-1] == 'o') cout << "FILIPINO\n";
        else if (s[n-1] == 'a') cout << "KOREAN\n";
        else cout << "JAPANESE\n";
    }
}
