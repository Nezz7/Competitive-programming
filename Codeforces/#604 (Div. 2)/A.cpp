#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.size();
        bool cond = true;
        for (int i  = 0; i < n-1;i++){
            if (s[i] == s[i+1] && s[i]!='?') cond = false;
        }
        if (s[0] == '?' && n > 1){
            s[0] = (((s[1]- 'a') + 1)%3) + 'a';
        }else if (s[0] == '?'){
            s[0] = 'a';
        }
        for (int i = 1; i < n - 1; i++){
            if (s[i] == '?'){
                if (s[i + 1] != '?'){
                    for (char c = 'a'; c <= 'c';c++){
                        if (s[i+1]!=c && s[i-1]!= c) s[i] = c;
                    }
                }else   s[i] = (((s[i-1]- 'a') + 1)%3) + 'a';
            }
        }
        if (s[n-1]=='?' && n> 1){
            s[n-1] = (((s[n-2]- 'a') + 1)%3) + 'a';
        }
        if (cond) cout << s << "\n";
        else cout << -1 << "\n";
    }
}
