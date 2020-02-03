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
 bool can[5];
 int n,m;
 int a[100][100];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m;
        can[0] = true;
        can[4] = true;
        bool cond = false;
        for (int i = 1; i < 4; i++) can[i] = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                char c ;
                cin >> c;
                if(c == 'A'){
                    cond = true;
                    a[i][j] = 1;
                }else {
                    a[i][j] = 0;
                    can[0] = false;
                }
            }
        if (!cond){
            cout << "MORTAL" << endl;
            continue;
        }
        // one move
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 0; j < m ; j ++)
                sum +=a[i][j];
            if (sum == m) can[2] = true;
        }
        for (int j = 0; j < m ; j ++){
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum +=a[i][j];
            if (sum == n) can[2] = true;
        }
        bool up = true, down = true, l = true, r = true;
        for (int j = 0; j < m; j++){
            if (!a[0][j]) up = false;
            else can[3] = true;
            if (!a[n-1][j]) down = false;
            else can[3] = true;
        }
        for (int j = 0; j < n; j++){
            if (!a[j][0]) l = false;
           else can[3] = true;
            if (!a[j][m-1]) r = false;
            else can[3] = true;
        }
        can[1] =  up or down or l or r;
        if (a[0][0] or a[n-1][0] or a[0][m-1] or a[n-1][m-1]) can[2] = true;

        for (int i = 0; i <= 4; i++)
            if (can[i]){
                cout  << i << endl;
                break;
            }
    }
 }
