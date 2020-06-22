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
 int const MAXN = 2e5 + 9;
 vector<int> prime;
 int p[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
      for (int i = 2; i <=MAXN;i++){
        if (p[i] == 0){
        for (int j = 2*i; j <=MAXN; j+=i)
                p[j] =1;
        prime.push_back(i);
        }
        if (sz(prime) > 500 ) break;
    }
    cin >> n >> m;
      if (n == 1  && m == 1){
        cout << 0;
        return 0;
    }
    if (n == 1){
        int x = 2;
        for (int i = 0; i < m; i++) cout <<  x++ <<" ";
        return 0;
    }
    if (m == 1){
        int x = 2;
        for (int i = 0; i < n; i++) cout <<x++ << "\n";
        return 0;
    }

    int x = m+1;
    for (int i = 0; i < n; i ++){
        for (int j  = 0; j < m; j++){
            cout << x * (j+1) <<" ";
        }
        cout << endl;
        x++;
    }
 }
