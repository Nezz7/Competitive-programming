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
    int T;
    cin >> T;
    int c = 0;
    while (T--){
        c++;
        string s;
        cin >> s;
        string a,b;
        for (int i = 0; i < sz(s) ; i++){
            if (s[i] == '0') a+='0',b+='0';
            else {
                a+= (s[i] - 1);
                b+='1';
            }
        }
        cout << "Case #" << c << ": " << a <<" " << b << endl;

    }

 }
