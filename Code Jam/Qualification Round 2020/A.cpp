#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 500 + 9;
int a[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int ca =0;
    while(T--){
        int n;
        ca++;
        cin >> n;
        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
            cin >> a[i][j];
        }
        int tr = 0;
        int r = 0, c = 0;
        for (int i = 0; i < n; i++) tr += a[i][i];
        for (int i = 0; i < n; i++){
            set<int> st;
            for (int j = 0; j < n; j++){
                st.insert(a[i][j]);
            }
            if (sz(st) != n) r++;
        }
        for (int i = 0; i < n; i++){
            set<int> st;
            for (int j = 0; j < n; j++){
                st.insert(a[j][i]);
            }
            if (sz(st) != n) c++;
        }
        cout << "Case #"<< ca << ": " << tr << " " << r << " " << c << endl;

    }
}