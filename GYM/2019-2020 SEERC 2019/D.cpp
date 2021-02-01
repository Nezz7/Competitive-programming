#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.length() / 2;
    sort(all(s));
    int cnt[26] = {0};
    for(auto c : s) cnt[c - 'a']++;
    int len = 0;
    for(int i = 0 ; i < 26 ; ++i){
        len += cnt[i] >= n;
        if(cnt[i] == 2 * n) return cout << "NO", 0;
    }

    if(len == 1){
        int dif = 0;
        char x = '*';
        for(int i = 0 ; i < 26; ++i){
            if(cnt[i] > n) x = 'a' + i;
            else dif += (cnt[i] > 0);
        }
        if(x == '*'){
            cout << "YES\n";
            cout << s << '\n';
            return 0;
        }
        if(dif == 1){
            if(cnt[x - 'a'] >= 2 * n - 2) return cout << "NO", 0;
        }
        cout << "YES\n";
        for(int i = 0 ; i < n; ++i) cout << x;
        for(int i = 0 ; i < 26 ; ++i)
            if(cnt[i] && (i + 'a') != x){
                cout << (char)('a' + i);
                cnt[i]--;
                break;
            }
        for(int i = 0 ; i < cnt[x - 'a'] - n; ++i) cout << x;
        cnt[x - 'a'] = 0;
        for(int i = 0 ; i < 26 ; ++i)
        for(int j = 0 ; j < cnt[i] ; ++j) cout << (char)('a' + i);
        cout << '\n';
        return 0;
    }
    cout << "YES\n";
    if(len == 2){
        char x = '*',y;
        for(int i = 0 ; i < 26 ; ++i)
            if(cnt[i] == n){
                if(x != '*') y = i + 'a';
                else x = i + 'a';
            }
        cout << x;
        for(int i = 0 ; i < n ; ++i) cout << y;
        for(int i = 0 ; i < n - 1 ; ++i) cout << x;
        cout << '\n';
    }else{
        cout << s;
    }
    return 0;
}