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
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ch = s;
   for (int i = 0; i < n; i++)
         s[i] = s[i%k];
   if (s >= ch){
        cout << n << endl;
        cout << s;
        return 0;
   }
   for (int i = k-1; i >=0; i--){
    if (s[i] == '9') s[i] = '0';
    else {s[i]++; break;}
   }

 cout << n << endl;
 for (int i = 0; i < n;i++) cout << s[i%k];
 }
