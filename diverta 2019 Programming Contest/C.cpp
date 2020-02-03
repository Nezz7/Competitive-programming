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
    cin >> n;
    int ans = 0;
    int AB = 0, A = 0, B = 0;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < sz(s) - 1; j++){
            if (s[j] == 'A' && s[j+1] == 'B') ans++;
        }
        if (s[0] == 'B' && s[sz(s) - 1]  == 'A') AB++;
        else if (s[0] == 'B') B++;
        else if (s[sz(s) - 1] == 'A') A++;
    }
    if(A == 0 && AB) A = 1, AB--;
    ans+= min(A,B)+ AB;
    cout << ans;
 }
