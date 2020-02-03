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
    while (T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1){
            cout << -1 << endl;
            continue;
        }
        bool cond = false;
        int sum = 0;
        string a ="";
        for (int i = n - 1; i >=0 ;i--){
            if ((s[i]-'0') % 2 && !cond){
                cond = true;
                a+=s[i];
                sum++;
            }else if (cond){
                a+=s[i];
                sum+=(s[i] -'0');
                if (sum%2 == 0) break;
            }
        }
        if (cond && sum%2 == 0){
            reverse(all(a));
            cout << a << endl;
        }else cout << -1 << endl;
    }
 }
