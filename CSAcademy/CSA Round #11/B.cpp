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
    string a,b;
    cin >> a >> b;
    int j = 0;
    bool cond = true;
    for (int i = 0; i < b.size(); i++){
        if (a[j] == b[i]){
            j++;
        }else if (j == 0 or b[i] != a[j - 1]) cond = false;
    }
    if (j != a.size()) cond =false;
    cout << cond ;
 }
