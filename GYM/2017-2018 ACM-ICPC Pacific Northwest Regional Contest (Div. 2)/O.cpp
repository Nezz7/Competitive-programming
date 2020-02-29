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
int const MAXN = 50 + 9;
char a[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    while (cin >> n){;
    string s = "";
    for (int i = 0; i < n; i++){
        if (i <= 9){
            s+= (char) (i + '0');
        }else {
            s+= (char) (i - 10 + 'A');
        }
    }
    set<char> st;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            st.insert(a[i][j]);
        }
    bool latin = true;
    for (int k= 0; k < n; k ++){
        char c = s[k];
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                cnt += (a[i][j] == c);
            }
            if (cnt != 1) latin = false;
        }
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                cnt += (a[j][i] == c);
            }
            if (cnt != 1) latin = false;
        }
    }
    bool reduced = true;
    for (int i = 0; i < n; i++){
        if (s[i] != a[0][i]) reduced = false;
    }
     for (int i = 0; i < n; i++){
        if (s[i] != a[i][0]) reduced = false;
    }
    if (st.size() != n) latin = false;
    if (latin){
        if (reduced){
            cout << "Reduced";
        }else  cout << "Not Reduced";
    }else cout << "No";
    cout << endl;
    }
}