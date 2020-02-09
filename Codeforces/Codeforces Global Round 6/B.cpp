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
    vector<int> v;
    cin >> n;
    while (n--){
        LL x;
        cin >> x;
        LL n = ((x - 7) + 13) / 14;
        //debug(n);
        bool cond = false;
        for (LL i = 1; i <7;i++){
            LL y = n*14 + 7 - i;
            if (y == x) cond = true;
        }
        if (x <= 20){
                cond = false;
              for (LL i = 1; i <7;i++){
                    LL y = 21 - i;
                if (y == x) cond = true;
        }
        }
        if (cond){

            v.push_back(x);
        }
    }
    for (auto cur : v) cout << cur << " ";
 }
