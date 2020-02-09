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
 vector<int> prime;
 int p[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for (int i = 2; i <=MAXN;i++){
        if (p[i] == 0){
        for (int j = 2*i; j <=MAXN; j+=i)
                p[j] =1;
        prime.push_back(i);
        }
    }
    int n, m;
    cin >> n >> m;
    if (n == 1  && m == 1){
        cout << 0;
        return 0;
    }
    int a[n][m];
    cout << endl << endl;
    int x = m+1;

    for (int i = 0; i < n; i ++){
        for (int j  = 0; j < m; j++){
           a[i][j] =  x * (j+1) ;
        }
        x++;
    }

    cout << endl;
    for (int i = 0; i < n; i++){
        for (int j =0; j < m;j++) cout << a[i][j] <<" ";
        cout << endl;
    }
    for (int j = 0; j < m; j++){
        int g = 0;
        for (int i = 0; i < n;i++)
        g = __gcd(a[i][j],g);
    cout << g << " ";
    }
            for (int i = 0; i < n;i++){
            int g = 0;
        for (int j = 0; j < m; j++)
            g = __gcd(a[i][j],g);
            cout << g << endl;
        }
 }
