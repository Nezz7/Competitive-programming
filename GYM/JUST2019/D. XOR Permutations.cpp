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
    while (n--){
        int  nbr [4];
        vector<int> v [4];
        memset(nbr,0,sizeof nbr);
        for (int i = 0; i <3; i++){
            string s;
            cin >> s;
            for (auto c : s) nbr[i] += (c == '1');
        }
        for (int i = 0; i <= 1024; i++){
             int x = __builtin_popcount(i);
             for (int j  = 0; j < 3; j++)
                if (x == nbr[j]) v[j] . pb(x);
        }
    }
 }
