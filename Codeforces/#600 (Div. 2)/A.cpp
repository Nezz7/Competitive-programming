#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e5+9;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int i = 0; i<n; i++)
            cin >> a[i];
        for (int i = 0; i<n; i++)
            cin >> b[i];
        vector<int> v;
        set<int> st;
        bool cond = true;
        for (int i = 0; i< n ;i++){
            if (a[i]> b[i]) cond = false;
            else if (a[i] != b[i]) st.insert(b[i] - a[i]),v.push_back(i);
        }
        for (int i = 0; i < (int) v.size()-1 ;i++){
            if (v[i] +1 != v[i+1]) cond = false;
        }
        if (cond == false or st.size() > 1 ) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
}
