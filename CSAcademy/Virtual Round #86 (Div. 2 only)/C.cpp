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
string s;
 bool is_pal(int start, int end){
    bool ret = true;
    if (start == end) return false;
    while (start < end){
        if (s[start] == '1' or s[end] == '1') return false;
        if( s[start] != s[end]) return false;
        start++;
        end--;
    }
    return ret;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> s;
    int ans = 0;
    int n = sz(s);
    for (int  i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (is_pal(j,i)) s[i] = '1',ans++;
        }
    }
    cout << ans;
 }
