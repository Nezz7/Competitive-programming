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
 unordered_map<string,int> mp;
 char dif (char a, char b){
    string s = "SET";
    for (int i = 0; i < 3; i++)
        if (s[i]!= a && s[i]!= b ) return s[i];
    return s[0];
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
        mp[s[i]]++;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n ; j ++){
        string ch  = "";
            for (int k = 0; k < m; k++){
                    if (s[i][k] == s[j][k]) ch+= s[i][k];
                    else ch += dif(s[i][k],s[j][k]);
            }
        ans += mp[ch];
        }
    }
    cout << ans /3<< endl;
 }
